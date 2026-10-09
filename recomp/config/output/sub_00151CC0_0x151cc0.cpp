#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00151CC0
// Address: 0x151cc0 - 0x154c78
void sub_00151CC0_0x151cc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00151CC0_0x151cc0");
#endif

    switch (ctx->pc) {
        case 0x152488u: goto label_152488;
        case 0x152490u: goto label_152490;
        case 0x1524e0u: goto label_1524e0;
        case 0x1524f8u: goto label_1524f8;
        case 0x152504u: goto label_152504;
        case 0x152518u: goto label_152518;
        case 0x152530u: goto label_152530;
        case 0x15253cu: goto label_15253c;
        case 0x152960u: goto label_152960;
        case 0x152a08u: goto label_152a08;
        case 0x152b00u: goto label_152b00;
        case 0x152bf8u: goto label_152bf8;
        case 0x152cb0u: goto label_152cb0;
        case 0x152cdcu: goto label_152cdc;
        case 0x1538b8u: goto label_1538b8;
        case 0x1538d8u: goto label_1538d8;
        case 0x154618u: goto label_154618;
        case 0x154620u: goto label_154620;
        default: break;
    }

    ctx->pc = 0x151cc0u;

    // 0x151cc0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x151cc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x151cc4: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x151cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x151cc8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x151cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x151ccc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x151cccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x151cd0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x151cd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x151cd4: 0x24940128  addiu       $s4, $a0, 0x128
    ctx->pc = 0x151cd4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x151cd8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x151cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x151cdc: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x151cdcu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151ce0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x151ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x151ce4: 0x2a28824  and         $s1, $s5, $v0
    ctx->pc = 0x151ce4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
    // 0x151ce8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x151ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x151cec: 0x2b11023  subu        $v0, $s5, $s1
    ctx->pc = 0x151cecu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 17)));
    // 0x151cf0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x151cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x151cf4: 0x298c0  sll         $s3, $v0, 3
    ctx->pc = 0x151cf4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x151cf8: 0x8e8304f0  lw          $v1, 0x4F0($s4)
    ctx->pc = 0x151cf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 1264)));
    // 0x151cfc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x151cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x151d00: 0xae8304f0  sw          $v1, 0x4F0($s4)
    ctx->pc = 0x151d00u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 1264), GPR_U32(ctx, 3));
    // 0x151d04: 0x82320000  lb          $s2, 0x0($s1)
    ctx->pc = 0x151d04u;
    SET_GPR_S32(ctx, 18, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d08: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d08u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d0c: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x151d0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d10: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d14: 0x92240000  lbu         $a0, 0x0($s1)
    ctx->pc = 0x151d14u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d18: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d1c: 0x92250000  lbu         $a1, 0x0($s1)
    ctx->pc = 0x151d1cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d20: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d24: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x151d24u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d28: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d2c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151d2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d30: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d34: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x151d34u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x151d38: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151d38u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151d3c: 0x2439025  or          $s2, $s2, $v1
    ctx->pc = 0x151d3cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x151d40: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x151d40u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d44: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x151d44u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x151d48: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x151d48u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x151d4c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d4cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d50: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151d50u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151d54: 0x2449025  or          $s2, $s2, $a0
    ctx->pc = 0x151d54u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 4));
    // 0x151d58: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151d58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151d5c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x151d5cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x151d60: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x151d60u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x151d64: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151d64u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151d68: 0x2459025  or          $s2, $s2, $a1
    ctx->pc = 0x151d68u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 5));
    // 0x151d6c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151d6cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151d70: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x151d70u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x151d74: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x151D74u;
    {
        const bool branch_taken_0x151d74 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x151D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151D74u;
            // 0x151d78: 0x2729004  sllv        $s2, $s2, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), GPR_U32(ctx, 19) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151d74) {
            ctx->pc = 0x151D98u;
            goto label_151d98;
        }
    }
    ctx->pc = 0x151D7Cu;
    // 0x151d7c: 0x131023  negu        $v0, $s3
    ctx->pc = 0x151d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
    // 0x151d80: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x151d80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x151d84: 0x2421025  or          $v0, $s2, $v0
    ctx->pc = 0x151d84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x151d88: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x151d88u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x151d8c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151D8Cu;
    {
        const bool branch_taken_0x151d8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151D8Cu;
            // 0x151d90: 0xae820034  sw          $v0, 0x34($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151d8c) {
            ctx->pc = 0x151DA0u;
            goto label_151da0;
        }
    }
    ctx->pc = 0x151D94u;
    // 0x151d94: 0x0  nop
    ctx->pc = 0x151d94u;
    // NOP
label_151d98:
    // 0x151d98: 0xae920034  sw          $s2, 0x34($s4)
    ctx->pc = 0x151d98u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 52), GPR_U32(ctx, 18));
    // 0x151d9c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x151d9cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_151da0:
    // 0x151da0: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x151da0u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151da4: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151da4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151da8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151da8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151dac: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151dacu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151db0: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151db0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151db4: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x151db4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151db8: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x151db8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x151dbc: 0x2a62001c  slti        $v0, $s3, 0x1C
    ctx->pc = 0x151dbcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x151dc0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151dc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151dc4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151dc4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151dc8: 0x92240000  lbu         $a0, 0x0($s1)
    ctx->pc = 0x151dc8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151dcc: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151dccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151dd0: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x151dd0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x151dd4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151dd4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151dd8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151DD8u;
    {
        const bool branch_taken_0x151dd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151DD8u;
            // 0x151ddc: 0x2048025  or          $s0, $s0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151dd8) {
            ctx->pc = 0x151E50u;
            goto label_151e50;
        }
    }
    ctx->pc = 0x151DE0u;
    // 0x151de0: 0x2673ffe4  addiu       $s3, $s3, -0x1C
    ctx->pc = 0x151de0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967268));
    // 0x151de4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x151DE4u;
    {
        const bool branch_taken_0x151de4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x151DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151DE4u;
            // 0x151de8: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151de4) {
            ctx->pc = 0x151E08u;
            goto label_151e08;
        }
    }
    ctx->pc = 0x151DECu;
    // 0x151dec: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x151decu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x151df0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x151df0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x151df4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x151df4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x151df8: 0x121f02  srl         $v1, $s2, 28
    ctx->pc = 0x151df8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x151dfc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x151dfcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x151e00: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151E00u;
    {
        const bool branch_taken_0x151e00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151E00u;
            // 0x151e04: 0xae830040  sw          $v1, 0x40($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 64), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151e00) {
            ctx->pc = 0x151E14u;
            goto label_151e14;
        }
    }
    ctx->pc = 0x151E08u;
label_151e08:
    // 0x151e08: 0x121702  srl         $v0, $s2, 28
    ctx->pc = 0x151e08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x151e0c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x151e0cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151e10: 0xae820040  sw          $v0, 0x40($s4)
    ctx->pc = 0x151e10u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 64), GPR_U32(ctx, 2));
label_151e14:
    // 0x151e14: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x151e14u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151e18: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151e18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151e1c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151e1cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151e20: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151e20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151e24: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151e24u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151e28: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x151e28u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151e2c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x151e2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x151e30: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151e30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151e34: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151e34u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151e38: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151e38u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151e3c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x151e3cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x151e40: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151e40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151e44: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151e44u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151e48: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x151E48u;
    {
        const bool branch_taken_0x151e48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151E48u;
            // 0x151e4c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151e48) {
            ctx->pc = 0x151E60u;
            goto label_151e60;
        }
    }
    ctx->pc = 0x151E50u;
label_151e50:
    // 0x151e50: 0x121702  srl         $v0, $s2, 28
    ctx->pc = 0x151e50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x151e54: 0x129100  sll         $s2, $s2, 4
    ctx->pc = 0x151e54u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x151e58: 0xae820040  sw          $v0, 0x40($s4)
    ctx->pc = 0x151e58u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 64), GPR_U32(ctx, 2));
    // 0x151e5c: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x151e5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
label_151e60:
    // 0x151e60: 0x8e8404dc  lw          $a0, 0x4DC($s4)
    ctx->pc = 0x151e60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 1244)));
    // 0x151e64: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x151e64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x151e68: 0x1082000b  beq         $a0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x151E68u;
    {
        const bool branch_taken_0x151e68 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x151E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151E68u;
            // 0x151e6c: 0x8e830040  lw          $v1, 0x40($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151e68) {
            ctx->pc = 0x151E98u;
            goto label_151e98;
        }
    }
    ctx->pc = 0x151E70u;
    // 0x151e70: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x151e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x151e74: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x151e74u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x151e78: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x151E78u;
    {
        const bool branch_taken_0x151e78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x151e78) {
            ctx->pc = 0x151E7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151E78u;
            // 0x151e7c: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x151EA0u;
            goto label_151ea0;
        }
    }
    ctx->pc = 0x151E80u;
    // 0x151e80: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x151e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x151e84: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x151E84u;
    {
        const bool branch_taken_0x151e84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x151E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151E84u;
            // 0x151e88: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151e84) {
            ctx->pc = 0x151E9Cu;
            goto label_151e9c;
        }
    }
    ctx->pc = 0x151E8Cu;
    // 0x151e8c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151E8Cu;
    {
        const bool branch_taken_0x151e8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151E8Cu;
            // 0x151e90: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151e8c) {
            ctx->pc = 0x151EA0u;
            goto label_151ea0;
        }
    }
    ctx->pc = 0x151E94u;
    // 0x151e94: 0x0  nop
    ctx->pc = 0x151e94u;
    // NOP
label_151e98:
    // 0x151e98: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x151e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_151e9c:
    // 0x151e9c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x151e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_151ea0:
    // 0x151ea0: 0x2c62000a  sltiu       $v0, $v1, 0xA
    ctx->pc = 0x151ea0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x151ea4: 0x50400b61  beql        $v0, $zero, . + 4 + (0xB61 << 2)
    ctx->pc = 0x151EA4u;
    {
        const bool branch_taken_0x151ea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x151ea4) {
            ctx->pc = 0x151EA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151EA4u;
            // 0x151ea8: 0x2351823  subu        $v1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x154C2Cu;
            goto label_154c2c;
        }
    }
    ctx->pc = 0x151EACu;
    // 0x151eac: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x151eacu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x151eb0: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x151eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x151eb4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x151eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x151eb8: 0x8c63e480  lw          $v1, -0x1B80($v1)
    ctx->pc = 0x151eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294960256)));
    // 0x151ebc: 0x600008  jr          $v1
    ctx->pc = 0x151EBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151EC8u: goto label_151ec8;
            case 0x152548u: goto label_152548;
            case 0x152968u: goto label_152968;
            case 0x152CE8u: goto label_152ce8;
            case 0x153208u: goto label_153208;
            case 0x1538B0u: goto label_1538b0;
            case 0x153B18u: goto label_153b18;
            case 0x154628u: goto label_154628;
            case 0x154A40u: goto label_154a40;
            case 0x154C28u: goto label_154c28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x151EC4u;
    // 0x151ec4: 0x0  nop
    ctx->pc = 0x151ec4u;
    // NOP
label_151ec8:
    // 0x151ec8: 0x2a620018  slti        $v0, $s3, 0x18
    ctx->pc = 0x151ec8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x151ecc: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x151ECCu;
    {
        const bool branch_taken_0x151ecc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151ECCu;
            // 0x151ed0: 0x121602  srl         $v0, $s2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151ecc) {
            ctx->pc = 0x151F48u;
            goto label_151f48;
        }
    }
    ctx->pc = 0x151ED4u;
    // 0x151ed4: 0x2673ffe8  addiu       $s3, $s3, -0x18
    ctx->pc = 0x151ed4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967272));
    // 0x151ed8: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x151ED8u;
    {
        const bool branch_taken_0x151ed8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x151EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151ED8u;
            // 0x151edc: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151ed8) {
            ctx->pc = 0x151F00u;
            goto label_151f00;
        }
    }
    ctx->pc = 0x151EE0u;
    // 0x151ee0: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x151ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x151ee4: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x151ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x151ee8: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x151ee8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x151eec: 0x121e02  srl         $v1, $s2, 24
    ctx->pc = 0x151eecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x151ef0: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x151ef0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x151ef4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x151EF4u;
    {
        const bool branch_taken_0x151ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151EF4u;
            // 0x151ef8: 0xae830044  sw          $v1, 0x44($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 68), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151ef4) {
            ctx->pc = 0x151F0Cu;
            goto label_151f0c;
        }
    }
    ctx->pc = 0x151EFCu;
    // 0x151efc: 0x0  nop
    ctx->pc = 0x151efcu;
    // NOP
label_151f00:
    // 0x151f00: 0x121602  srl         $v0, $s2, 24
    ctx->pc = 0x151f00u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x151f04: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x151f04u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151f08: 0xae820044  sw          $v0, 0x44($s4)
    ctx->pc = 0x151f08u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 68), GPR_U32(ctx, 2));
label_151f0c:
    // 0x151f0c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x151f0cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151f10: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151f10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151f14: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151f14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151f18: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151f18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151f1c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151f1cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151f20: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x151f20u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151f24: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x151f24u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x151f28: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151f28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151f2c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151f2cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151f30: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151f30u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151f34: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x151f34u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x151f38: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151f38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151f3c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151f3cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151f40: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151F40u;
    {
        const bool branch_taken_0x151f40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151F40u;
            // 0x151f44: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151f40) {
            ctx->pc = 0x151F54u;
            goto label_151f54;
        }
    }
    ctx->pc = 0x151F48u;
label_151f48:
    // 0x151f48: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x151f48u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x151f4c: 0xae820044  sw          $v0, 0x44($s4)
    ctx->pc = 0x151f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 68), GPR_U32(ctx, 2));
    // 0x151f50: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x151f50u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_151f54:
    // 0x151f54: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x151f54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x151f58: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151F58u;
    {
        const bool branch_taken_0x151f58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151F58u;
            // 0x151f5c: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151f58) {
            ctx->pc = 0x151FD0u;
            goto label_151fd0;
        }
    }
    ctx->pc = 0x151F60u;
    // 0x151f60: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x151f60u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x151f64: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x151F64u;
    {
        const bool branch_taken_0x151f64 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x151F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151F64u;
            // 0x151f68: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151f64) {
            ctx->pc = 0x151F88u;
            goto label_151f88;
        }
    }
    ctx->pc = 0x151F6Cu;
    // 0x151f6c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x151f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x151f70: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x151f70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x151f74: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x151f74u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x151f78: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x151f78u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x151f7c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x151f7cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x151f80: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151F80u;
    {
        const bool branch_taken_0x151f80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151F80u;
            // 0x151f84: 0xae830048  sw          $v1, 0x48($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 72), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151f80) {
            ctx->pc = 0x151F94u;
            goto label_151f94;
        }
    }
    ctx->pc = 0x151F88u;
label_151f88:
    // 0x151f88: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x151f88u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x151f8c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x151f8cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151f90: 0xae820048  sw          $v0, 0x48($s4)
    ctx->pc = 0x151f90u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 72), GPR_U32(ctx, 2));
label_151f94:
    // 0x151f94: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x151f94u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151f98: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151f98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151f9c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151f9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151fa0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151fa0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151fa4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151fa4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151fa8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x151fa8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151fac: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x151facu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x151fb0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151fb0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151fb4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151fb4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151fb8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x151fb8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x151fbc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x151fbcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x151fc0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151fc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x151fc4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x151fc4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x151fc8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151FC8u;
    {
        const bool branch_taken_0x151fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151FC8u;
            // 0x151fcc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151fc8) {
            ctx->pc = 0x151FDCu;
            goto label_151fdc;
        }
    }
    ctx->pc = 0x151FD0u;
label_151fd0:
    // 0x151fd0: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x151fd0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x151fd4: 0xae820048  sw          $v0, 0x48($s4)
    ctx->pc = 0x151fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 72), GPR_U32(ctx, 2));
    // 0x151fd8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x151fd8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_151fdc:
    // 0x151fdc: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x151fdcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x151fe0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151FE0u;
    {
        const bool branch_taken_0x151fe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151FE0u;
            // 0x151fe4: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151fe0) {
            ctx->pc = 0x152058u;
            goto label_152058;
        }
    }
    ctx->pc = 0x151FE8u;
    // 0x151fe8: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x151fe8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x151fec: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x151FECu;
    {
        const bool branch_taken_0x151fec = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x151FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151FECu;
            // 0x151ff0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151fec) {
            ctx->pc = 0x152010u;
            goto label_152010;
        }
    }
    ctx->pc = 0x151FF4u;
    // 0x151ff4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x151ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x151ff8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x151ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x151ffc: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x151ffcu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152000: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x152000u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x152004: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152004u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152008: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152008u;
    {
        const bool branch_taken_0x152008 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15200Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152008u;
            // 0x15200c: 0xae83004c  sw          $v1, 0x4C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152008) {
            ctx->pc = 0x15201Cu;
            goto label_15201c;
        }
    }
    ctx->pc = 0x152010u;
label_152010:
    // 0x152010: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x152010u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x152014: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152014u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152018: 0xae82004c  sw          $v0, 0x4C($s4)
    ctx->pc = 0x152018u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 76), GPR_U32(ctx, 2));
label_15201c:
    // 0x15201c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15201cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152020: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152020u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152024: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152024u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152028: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152028u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15202c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15202cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152030: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152030u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152034: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152034u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152038: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152038u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15203c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15203cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152040: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152040u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152044: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152044u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152048: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152048u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15204c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15204cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152050: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152050u;
    {
        const bool branch_taken_0x152050 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152050u;
            // 0x152054: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152050) {
            ctx->pc = 0x152064u;
            goto label_152064;
        }
    }
    ctx->pc = 0x152058u;
label_152058:
    // 0x152058: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x152058u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x15205c: 0xae82004c  sw          $v0, 0x4C($s4)
    ctx->pc = 0x15205cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 76), GPR_U32(ctx, 2));
    // 0x152060: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x152060u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_152064:
    // 0x152064: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x152064u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x152068: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152068u;
    {
        const bool branch_taken_0x152068 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15206Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152068u;
            // 0x15206c: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152068) {
            ctx->pc = 0x1520E0u;
            goto label_1520e0;
        }
    }
    ctx->pc = 0x152070u;
    // 0x152070: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x152070u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x152074: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152074u;
    {
        const bool branch_taken_0x152074 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152074u;
            // 0x152078: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152074) {
            ctx->pc = 0x152098u;
            goto label_152098;
        }
    }
    ctx->pc = 0x15207Cu;
    // 0x15207c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15207cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152080: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152080u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152084: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152084u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152088: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x152088u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x15208c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15208cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152090: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152090u;
    {
        const bool branch_taken_0x152090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152090u;
            // 0x152094: 0xae830050  sw          $v1, 0x50($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 80), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152090) {
            ctx->pc = 0x1520A4u;
            goto label_1520a4;
        }
    }
    ctx->pc = 0x152098u;
label_152098:
    // 0x152098: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x152098u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x15209c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15209cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1520a0: 0xae820050  sw          $v0, 0x50($s4)
    ctx->pc = 0x1520a0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 80), GPR_U32(ctx, 2));
label_1520a4:
    // 0x1520a4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1520a4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1520a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1520a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1520ac: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1520acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1520b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1520b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1520b4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1520b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1520b8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1520b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1520bc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1520bcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1520c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1520c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1520c4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1520c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1520c8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1520c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1520cc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1520ccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1520d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1520d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1520d4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1520d4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1520d8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1520D8u;
    {
        const bool branch_taken_0x1520d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1520DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1520D8u;
            // 0x1520dc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1520d8) {
            ctx->pc = 0x1520ECu;
            goto label_1520ec;
        }
    }
    ctx->pc = 0x1520E0u;
label_1520e0:
    // 0x1520e0: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x1520e0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1520e4: 0xae820050  sw          $v0, 0x50($s4)
    ctx->pc = 0x1520e4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 80), GPR_U32(ctx, 2));
    // 0x1520e8: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x1520e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_1520ec:
    // 0x1520ec: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x1520ecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x1520f0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1520F0u;
    {
        const bool branch_taken_0x1520f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1520F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1520F0u;
            // 0x1520f4: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1520f0) {
            ctx->pc = 0x152168u;
            goto label_152168;
        }
    }
    ctx->pc = 0x1520F8u;
    // 0x1520f8: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x1520f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x1520fc: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1520FCu;
    {
        const bool branch_taken_0x1520fc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1520FCu;
            // 0x152100: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1520fc) {
            ctx->pc = 0x152120u;
            goto label_152120;
        }
    }
    ctx->pc = 0x152104u;
    // 0x152104: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152104u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152108: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152108u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15210c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15210cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152110: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x152110u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x152114: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152114u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152118: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152118u;
    {
        const bool branch_taken_0x152118 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15211Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152118u;
            // 0x15211c: 0xae830054  sw          $v1, 0x54($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 84), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152118) {
            ctx->pc = 0x15212Cu;
            goto label_15212c;
        }
    }
    ctx->pc = 0x152120u;
label_152120:
    // 0x152120: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x152120u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x152124: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152124u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152128: 0xae820054  sw          $v0, 0x54($s4)
    ctx->pc = 0x152128u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 84), GPR_U32(ctx, 2));
label_15212c:
    // 0x15212c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15212cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152130: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152130u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152134: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152134u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152138: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152138u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15213c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15213cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152140: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152140u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152144: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152144u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152148: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152148u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15214c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15214cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152150: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152150u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152154: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152154u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152158: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152158u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15215c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15215cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152160: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152160u;
    {
        const bool branch_taken_0x152160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152160u;
            // 0x152164: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152160) {
            ctx->pc = 0x152174u;
            goto label_152174;
        }
    }
    ctx->pc = 0x152168u;
label_152168:
    // 0x152168: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x152168u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x15216c: 0xae820054  sw          $v0, 0x54($s4)
    ctx->pc = 0x15216cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 84), GPR_U32(ctx, 2));
    // 0x152170: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x152170u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_152174:
    // 0x152174: 0x2a620014  slti        $v0, $s3, 0x14
    ctx->pc = 0x152174u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x152178: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152178u;
    {
        const bool branch_taken_0x152178 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15217Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152178u;
            // 0x15217c: 0x121502  srl         $v0, $s2, 20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152178) {
            ctx->pc = 0x1521F0u;
            goto label_1521f0;
        }
    }
    ctx->pc = 0x152180u;
    // 0x152180: 0x2673ffec  addiu       $s3, $s3, -0x14
    ctx->pc = 0x152180u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967276));
    // 0x152184: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152184u;
    {
        const bool branch_taken_0x152184 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152184u;
            // 0x152188: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152184) {
            ctx->pc = 0x1521A8u;
            goto label_1521a8;
        }
    }
    ctx->pc = 0x15218Cu;
    // 0x15218c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15218cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152190: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152190u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152194: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152194u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152198: 0x121d02  srl         $v1, $s2, 20
    ctx->pc = 0x152198u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 20));
    // 0x15219c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15219cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1521a0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1521A0u;
    {
        const bool branch_taken_0x1521a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1521A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1521A0u;
            // 0x1521a4: 0xae830058  sw          $v1, 0x58($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 88), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1521a0) {
            ctx->pc = 0x1521B4u;
            goto label_1521b4;
        }
    }
    ctx->pc = 0x1521A8u;
label_1521a8:
    // 0x1521a8: 0x121502  srl         $v0, $s2, 20
    ctx->pc = 0x1521a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 20));
    // 0x1521ac: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1521acu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1521b0: 0xae820058  sw          $v0, 0x58($s4)
    ctx->pc = 0x1521b0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 88), GPR_U32(ctx, 2));
label_1521b4:
    // 0x1521b4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1521b4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1521b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1521b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1521bc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1521bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1521c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1521c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1521c4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1521c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1521c8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1521c8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1521cc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1521ccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1521d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1521d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1521d4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1521d4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1521d8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1521d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1521dc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1521dcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1521e0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1521e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1521e4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1521e4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1521e8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1521E8u;
    {
        const bool branch_taken_0x1521e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1521ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1521E8u;
            // 0x1521ec: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1521e8) {
            ctx->pc = 0x1521FCu;
            goto label_1521fc;
        }
    }
    ctx->pc = 0x1521F0u;
label_1521f0:
    // 0x1521f0: 0x129300  sll         $s2, $s2, 12
    ctx->pc = 0x1521f0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 12));
    // 0x1521f4: 0xae820058  sw          $v0, 0x58($s4)
    ctx->pc = 0x1521f4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 88), GPR_U32(ctx, 2));
    // 0x1521f8: 0x2673000c  addiu       $s3, $s3, 0xC
    ctx->pc = 0x1521f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 12));
label_1521fc:
    // 0x1521fc: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1521fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x152200: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152200u;
    {
        const bool branch_taken_0x152200 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152200u;
            // 0x152204: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152200) {
            ctx->pc = 0x152278u;
            goto label_152278;
        }
    }
    ctx->pc = 0x152208u;
    // 0x152208: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152208u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15220c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15220Cu;
    {
        const bool branch_taken_0x15220c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15220Cu;
            // 0x152210: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15220c) {
            ctx->pc = 0x152230u;
            goto label_152230;
        }
    }
    ctx->pc = 0x152214u;
    // 0x152214: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152214u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152218: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152218u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15221c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15221cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152220: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152220u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152224: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152224u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152228: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152228u;
    {
        const bool branch_taken_0x152228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15222Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152228u;
            // 0x15222c: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152228) {
            ctx->pc = 0x15223Cu;
            goto label_15223c;
        }
    }
    ctx->pc = 0x152230u;
label_152230:
    // 0x152230: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152230u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152234: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152234u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152238: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x152238u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_15223c:
    // 0x15223c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15223cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152240: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152240u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152244: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152244u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152248: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152248u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15224c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15224cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152250: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152250u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152254: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152254u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152258: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152258u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15225c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15225cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152260: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152260u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152264: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152264u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152268: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152268u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15226c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15226cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152270: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152270u;
    {
        const bool branch_taken_0x152270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152270u;
            // 0x152274: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152270) {
            ctx->pc = 0x152284u;
            goto label_152284;
        }
    }
    ctx->pc = 0x152278u;
label_152278:
    // 0x152278: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152278u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15227c: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x15227cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x152280: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152280u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_152284:
    // 0x152284: 0x2a620018  slti        $v0, $s3, 0x18
    ctx->pc = 0x152284u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x152288: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152288u;
    {
        const bool branch_taken_0x152288 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15228Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152288u;
            // 0x15228c: 0x121602  srl         $v0, $s2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152288) {
            ctx->pc = 0x152300u;
            goto label_152300;
        }
    }
    ctx->pc = 0x152290u;
    // 0x152290: 0x2673ffe8  addiu       $s3, $s3, -0x18
    ctx->pc = 0x152290u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967272));
    // 0x152294: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152294u;
    {
        const bool branch_taken_0x152294 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152294u;
            // 0x152298: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152294) {
            ctx->pc = 0x1522B8u;
            goto label_1522b8;
        }
    }
    ctx->pc = 0x15229Cu;
    // 0x15229c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15229cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1522a0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1522a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1522a4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1522a4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1522a8: 0x121e02  srl         $v1, $s2, 24
    ctx->pc = 0x1522a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x1522ac: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1522acu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1522b0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1522B0u;
    {
        const bool branch_taken_0x1522b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1522B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1522B0u;
            // 0x1522b4: 0xae83005c  sw          $v1, 0x5C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 92), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1522b0) {
            ctx->pc = 0x1522C4u;
            goto label_1522c4;
        }
    }
    ctx->pc = 0x1522B8u;
label_1522b8:
    // 0x1522b8: 0x121602  srl         $v0, $s2, 24
    ctx->pc = 0x1522b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x1522bc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1522bcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1522c0: 0xae82005c  sw          $v0, 0x5C($s4)
    ctx->pc = 0x1522c0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 92), GPR_U32(ctx, 2));
label_1522c4:
    // 0x1522c4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1522c4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1522c8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1522c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1522cc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1522ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1522d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1522d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1522d4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1522d4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1522d8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1522d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1522dc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1522dcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1522e0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1522e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1522e4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1522e4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1522e8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1522e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1522ec: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1522ecu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1522f0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1522f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1522f4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1522f4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1522f8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1522F8u;
    {
        const bool branch_taken_0x1522f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1522FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1522F8u;
            // 0x1522fc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1522f8) {
            ctx->pc = 0x15230Cu;
            goto label_15230c;
        }
    }
    ctx->pc = 0x152300u;
label_152300:
    // 0x152300: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x152300u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x152304: 0xae82005c  sw          $v0, 0x5C($s4)
    ctx->pc = 0x152304u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 92), GPR_U32(ctx, 2));
    // 0x152308: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x152308u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_15230c:
    // 0x15230c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x15230cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x152310: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152310u;
    {
        const bool branch_taken_0x152310 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152310u;
            // 0x152314: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152310) {
            ctx->pc = 0x152388u;
            goto label_152388;
        }
    }
    ctx->pc = 0x152318u;
    // 0x152318: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152318u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15231c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15231Cu;
    {
        const bool branch_taken_0x15231c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15231Cu;
            // 0x152320: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15231c) {
            ctx->pc = 0x152340u;
            goto label_152340;
        }
    }
    ctx->pc = 0x152324u;
    // 0x152324: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152324u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152328: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152328u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15232c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15232cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152330: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152330u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152334: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152334u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152338: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152338u;
    {
        const bool branch_taken_0x152338 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15233Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152338u;
            // 0x15233c: 0xae830060  sw          $v1, 0x60($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 96), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152338) {
            ctx->pc = 0x15234Cu;
            goto label_15234c;
        }
    }
    ctx->pc = 0x152340u;
label_152340:
    // 0x152340: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152340u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152344: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152344u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152348: 0xae820060  sw          $v0, 0x60($s4)
    ctx->pc = 0x152348u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 96), GPR_U32(ctx, 2));
label_15234c:
    // 0x15234c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15234cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152350: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152350u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152354: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152354u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152358: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152358u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15235c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15235cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152360: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152360u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152364: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152364u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152368: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152368u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15236c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15236cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152370: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152370u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152374: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152374u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152378: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152378u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15237c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15237cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152380: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152380u;
    {
        const bool branch_taken_0x152380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152380u;
            // 0x152384: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152380) {
            ctx->pc = 0x152394u;
            goto label_152394;
        }
    }
    ctx->pc = 0x152388u;
label_152388:
    // 0x152388: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152388u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15238c: 0xae820060  sw          $v0, 0x60($s4)
    ctx->pc = 0x15238cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 96), GPR_U32(ctx, 2));
    // 0x152390: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152390u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_152394:
    // 0x152394: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x152394u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x152398: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152398u;
    {
        const bool branch_taken_0x152398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15239Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152398u;
            // 0x15239c: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152398) {
            ctx->pc = 0x152410u;
            goto label_152410;
        }
    }
    ctx->pc = 0x1523A0u;
    // 0x1523a0: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x1523a0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x1523a4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1523A4u;
    {
        const bool branch_taken_0x1523a4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1523A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1523A4u;
            // 0x1523a8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1523a4) {
            ctx->pc = 0x1523C8u;
            goto label_1523c8;
        }
    }
    ctx->pc = 0x1523ACu;
    // 0x1523ac: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1523acu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1523b0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1523b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1523b4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1523b4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1523b8: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x1523b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x1523bc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1523bcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1523c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1523C0u;
    {
        const bool branch_taken_0x1523c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1523C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1523C0u;
            // 0x1523c4: 0xae830064  sw          $v1, 0x64($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 100), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1523c0) {
            ctx->pc = 0x1523D4u;
            goto label_1523d4;
        }
    }
    ctx->pc = 0x1523C8u;
label_1523c8:
    // 0x1523c8: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x1523c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x1523cc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1523ccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1523d0: 0xae820064  sw          $v0, 0x64($s4)
    ctx->pc = 0x1523d0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 100), GPR_U32(ctx, 2));
label_1523d4:
    // 0x1523d4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1523d4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1523d8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1523d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1523dc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1523dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1523e0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1523e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1523e4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1523e4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1523e8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1523e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1523ec: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1523ecu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1523f0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1523f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1523f4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1523f4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1523f8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1523f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1523fc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1523fcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152400: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152400u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152404: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152404u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152408: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152408u;
    {
        const bool branch_taken_0x152408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15240Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152408u;
            // 0x15240c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152408) {
            ctx->pc = 0x15241Cu;
            goto label_15241c;
        }
    }
    ctx->pc = 0x152410u;
label_152410:
    // 0x152410: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x152410u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x152414: 0xae820064  sw          $v0, 0x64($s4)
    ctx->pc = 0x152414u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 100), GPR_U32(ctx, 2));
    // 0x152418: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x152418u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_15241c:
    // 0x15241c: 0x2a62001b  slti        $v0, $s3, 0x1B
    ctx->pc = 0x15241cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x152420: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x152420u;
    {
        const bool branch_taken_0x152420 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152420u;
            // 0x152424: 0x1216c2  srl         $v0, $s2, 27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152420) {
            ctx->pc = 0x152460u;
            goto label_152460;
        }
    }
    ctx->pc = 0x152428u;
    // 0x152428: 0x2673ffe5  addiu       $s3, $s3, -0x1B
    ctx->pc = 0x152428u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967269));
    // 0x15242c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15242Cu;
    {
        const bool branch_taken_0x15242c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15242Cu;
            // 0x152430: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15242c) {
            ctx->pc = 0x152450u;
            goto label_152450;
        }
    }
    ctx->pc = 0x152434u;
    // 0x152434: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152434u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152438: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152438u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15243c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15243cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152440: 0x121ec2  srl         $v1, $s2, 27
    ctx->pc = 0x152440u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x152444: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152444u;
    {
        const bool branch_taken_0x152444 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152444u;
            // 0x152448: 0xae830068  sw          $v1, 0x68($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 104), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152444) {
            ctx->pc = 0x152458u;
            goto label_152458;
        }
    }
    ctx->pc = 0x15244Cu;
    // 0x15244c: 0x0  nop
    ctx->pc = 0x15244cu;
    // NOP
label_152450:
    // 0x152450: 0x1216c2  srl         $v0, $s2, 27
    ctx->pc = 0x152450u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x152454: 0xae820068  sw          $v0, 0x68($s4)
    ctx->pc = 0x152454u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 104), GPR_U32(ctx, 2));
label_152458:
    // 0x152458: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x152458u;
    {
        const bool branch_taken_0x152458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15245Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152458u;
            // 0x15245c: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152458) {
            ctx->pc = 0x152468u;
            goto label_152468;
        }
    }
    ctx->pc = 0x152460u;
label_152460:
    // 0x152460: 0x26730005  addiu       $s3, $s3, 0x5
    ctx->pc = 0x152460u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 5));
    // 0x152464: 0xae820068  sw          $v0, 0x68($s4)
    ctx->pc = 0x152464u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 104), GPR_U32(ctx, 2));
label_152468:
    // 0x152468: 0x8e82004c  lw          $v0, 0x4C($s4)
    ctx->pc = 0x152468u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 76)));
    // 0x15246c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x15246cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152470: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x152470u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x152474: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x152474u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x152478: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x152478u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x15247c: 0x8c63e3d0  lw          $v1, -0x1C30($v1)
    ctx->pc = 0x15247cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294960080)));
    // 0x152480: 0xc054382  jal         func_150E08
    ctx->pc = 0x152480u;
    SET_GPR_U32(ctx, 31, 0x152488u);
    ctx->pc = 0x152484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x152480u;
            // 0x152484: 0xae830338  sw          $v1, 0x338($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 824), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150E08u;
    if (runtime->hasFunction(0x150E08u)) {
        auto targetFn = runtime->lookupFunction(0x150E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152488u; }
        if (ctx->pc != 0x152488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150E08_0x150e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152488u; }
        if (ctx->pc != 0x152488u) { return; }
    }
    ctx->pc = 0x152488u;
label_152488:
    // 0x152488: 0xc0543b4  jal         func_150ED0
    ctx->pc = 0x152488u;
    SET_GPR_U32(ctx, 31, 0x152490u);
    ctx->pc = 0x15248Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x152488u;
            // 0x15248c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150ED0u;
    if (runtime->hasFunction(0x150ED0u)) {
        auto targetFn = runtime->lookupFunction(0x150ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152490u; }
        if (ctx->pc != 0x152490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150ED0_0x150ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152490u; }
        if (ctx->pc != 0x152490u) { return; }
    }
    ctx->pc = 0x152490u;
label_152490:
    // 0x152490: 0x8e840058  lw          $a0, 0x58($s4)
    ctx->pc = 0x152490u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 88)));
    // 0x152494: 0x8e820010  lw          $v0, 0x10($s4)
    ctx->pc = 0x152494u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 16)));
    // 0x152498: 0x8e83005c  lw          $v1, 0x5C($s4)
    ctx->pc = 0x152498u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 92)));
    // 0x15249c: 0x42480  sll         $a0, $a0, 18
    ctx->pc = 0x15249cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 18));
    // 0x1524a0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1524a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1524a4: 0x8e850014  lw          $a1, 0x14($s4)
    ctx->pc = 0x1524a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 20)));
    // 0x1524a8: 0x8e86001c  lw          $a2, 0x1C($s4)
    ctx->pc = 0x1524a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 28)));
    // 0x1524ac: 0x31a80  sll         $v1, $v1, 10
    ctx->pc = 0x1524acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
    // 0x1524b0: 0x3c120024  lui         $s2, 0x24
    ctx->pc = 0x1524b0u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)36 << 16));
    // 0x1524b4: 0x2429021  addu        $s2, $s2, $v0
    ctx->pc = 0x1524b4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1524b8: 0xde52e350  ld          $s2, -0x1CB0($s2)
    ctx->pc = 0x1524b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 18), 4294959952)));
    // 0x1524bc: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1524bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1524c0: 0x8e900064  lw          $s0, 0x64($s4)
    ctx->pc = 0x1524c0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 100)));
    // 0x1524c4: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x1524c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x1524c8: 0xae8402f8  sw          $a0, 0x2F8($s4)
    ctx->pc = 0x1524c8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 760), GPR_U32(ctx, 4));
    // 0x1524cc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1524ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1524d0: 0xae8302fc  sw          $v1, 0x2FC($s4)
    ctx->pc = 0x1524d0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 764), GPR_U32(ctx, 3));
    // 0x1524d4: 0xfe9202e8  sd          $s2, 0x2E8($s4)
    ctx->pc = 0x1524d4u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 744), GPR_U64(ctx, 18));
    // 0x1524d8: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x1524D8u;
    SET_GPR_U32(ctx, 31, 0x1524E0u);
    ctx->pc = 0x1524DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1524D8u;
            // 0x1524dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1524E0u; }
        if (ctx->pc != 0x1524E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1524E0u; }
        if (ctx->pc != 0x1524E0u) { return; }
    }
    ctx->pc = 0x1524E0u;
label_1524e0:
    // 0x1524e0: 0x6010005  bgez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1524E0u;
    {
        const bool branch_taken_0x1524e0 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x1524e0) {
            ctx->pc = 0x1524F8u;
            goto label_1524f8;
        }
    }
    ctx->pc = 0x1524E8u;
    // 0x1524e8: 0x340583e0  ori         $a1, $zero, 0x83E0
    ctx->pc = 0x1524e8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33760);
    // 0x1524ec: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x1524ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x1524f0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x1524F0u;
    SET_GPR_U32(ctx, 31, 0x1524F8u);
    ctx->pc = 0x1524F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1524F0u;
            // 0x1524f4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1524F8u; }
        if (ctx->pc != 0x1524F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1524F8u; }
        if (ctx->pc != 0x1524F8u) { return; }
    }
    ctx->pc = 0x1524F8u;
label_1524f8:
    // 0x1524f8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1524f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1524fc: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1524FCu;
    SET_GPR_U32(ctx, 31, 0x152504u);
    ctx->pc = 0x152500u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1524FCu;
            // 0x152500: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152504u; }
        if (ctx->pc != 0x152504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152504u; }
        if (ctx->pc != 0x152504u) { return; }
    }
    ctx->pc = 0x152504u;
label_152504:
    // 0x152504: 0x8e900068  lw          $s0, 0x68($s4)
    ctx->pc = 0x152504u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 104)));
    // 0x152508: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x152508u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15250c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x15250cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x152510: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x152510u;
    SET_GPR_U32(ctx, 31, 0x152518u);
    ctx->pc = 0x152514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x152510u;
            // 0x152514: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152518u; }
        if (ctx->pc != 0x152518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152518u; }
        if (ctx->pc != 0x152518u) { return; }
    }
    ctx->pc = 0x152518u;
label_152518:
    // 0x152518: 0x6010005  bgez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x152518u;
    {
        const bool branch_taken_0x152518 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x152518) {
            ctx->pc = 0x152530u;
            goto label_152530;
        }
    }
    ctx->pc = 0x152520u;
    // 0x152520: 0x340583e0  ori         $a1, $zero, 0x83E0
    ctx->pc = 0x152520u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33760);
    // 0x152524: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x152524u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x152528: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x152528u;
    SET_GPR_U32(ctx, 31, 0x152530u);
    ctx->pc = 0x15252Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x152528u;
            // 0x15252c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152530u; }
        if (ctx->pc != 0x152530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152530u; }
        if (ctx->pc != 0x152530u) { return; }
    }
    ctx->pc = 0x152530u;
label_152530:
    // 0x152530: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x152530u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152534: 0xc04480e  jal         func_112038
    ctx->pc = 0x152534u;
    SET_GPR_U32(ctx, 31, 0x15253Cu);
    ctx->pc = 0x152538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x152534u;
            // 0x152538: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15253Cu; }
        if (ctx->pc != 0x15253Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15253Cu; }
        if (ctx->pc != 0x15253Cu) { return; }
    }
    ctx->pc = 0x15253Cu;
label_15253c:
    // 0x15253c: 0xfe8202f0  sd          $v0, 0x2F0($s4)
    ctx->pc = 0x15253cu;
    WRITE64(ADD32(GPR_U32(ctx, 20), 752), GPR_U64(ctx, 2));
    // 0x152540: 0x100009ba  b           . + 4 + (0x9BA << 2)
    ctx->pc = 0x152540u;
    {
        const bool branch_taken_0x152540 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152540u;
            // 0x152544: 0x2351823  subu        $v1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152540) {
            ctx->pc = 0x154C2Cu;
            goto label_154c2c;
        }
    }
    ctx->pc = 0x152548u;
label_152548:
    // 0x152548: 0x2a62001d  slti        $v0, $s3, 0x1D
    ctx->pc = 0x152548u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x15254c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x15254Cu;
    {
        const bool branch_taken_0x15254c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15254Cu;
            // 0x152550: 0x121742  srl         $v0, $s2, 29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15254c) {
            ctx->pc = 0x1525C8u;
            goto label_1525c8;
        }
    }
    ctx->pc = 0x152554u;
    // 0x152554: 0x2673ffe3  addiu       $s3, $s3, -0x1D
    ctx->pc = 0x152554u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967267));
    // 0x152558: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x152558u;
    {
        const bool branch_taken_0x152558 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x15255Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152558u;
            // 0x15255c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152558) {
            ctx->pc = 0x152580u;
            goto label_152580;
        }
    }
    ctx->pc = 0x152560u;
    // 0x152560: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152560u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152564: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152564u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152568: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152568u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x15256c: 0x121f42  srl         $v1, $s2, 29
    ctx->pc = 0x15256cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x152570: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152570u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152574: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x152574u;
    {
        const bool branch_taken_0x152574 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152574u;
            // 0x152578: 0xae83006c  sw          $v1, 0x6C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 108), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152574) {
            ctx->pc = 0x15258Cu;
            goto label_15258c;
        }
    }
    ctx->pc = 0x15257Cu;
    // 0x15257c: 0x0  nop
    ctx->pc = 0x15257cu;
    // NOP
label_152580:
    // 0x152580: 0x121742  srl         $v0, $s2, 29
    ctx->pc = 0x152580u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x152584: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152584u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152588: 0xae82006c  sw          $v0, 0x6C($s4)
    ctx->pc = 0x152588u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 108), GPR_U32(ctx, 2));
label_15258c:
    // 0x15258c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15258cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152590: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152590u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152594: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152594u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152598: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152598u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15259c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15259cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1525a0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1525a0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1525a4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1525a4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1525a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1525a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1525ac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1525acu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1525b0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1525b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1525b4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1525b4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1525b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1525b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1525bc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1525bcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1525c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1525C0u;
    {
        const bool branch_taken_0x1525c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1525C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1525C0u;
            // 0x1525c4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1525c0) {
            ctx->pc = 0x1525D4u;
            goto label_1525d4;
        }
    }
    ctx->pc = 0x1525C8u;
label_1525c8:
    // 0x1525c8: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x1525c8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x1525cc: 0xae82006c  sw          $v0, 0x6C($s4)
    ctx->pc = 0x1525ccu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 108), GPR_U32(ctx, 2));
    // 0x1525d0: 0x26730003  addiu       $s3, $s3, 0x3
    ctx->pc = 0x1525d0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
label_1525d4:
    // 0x1525d4: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1525d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1525d8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1525D8u;
    {
        const bool branch_taken_0x1525d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1525DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1525D8u;
            // 0x1525dc: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1525d8) {
            ctx->pc = 0x152650u;
            goto label_152650;
        }
    }
    ctx->pc = 0x1525E0u;
    // 0x1525e0: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1525e0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1525e4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1525E4u;
    {
        const bool branch_taken_0x1525e4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1525E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1525E4u;
            // 0x1525e8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1525e4) {
            ctx->pc = 0x152608u;
            goto label_152608;
        }
    }
    ctx->pc = 0x1525ECu;
    // 0x1525ec: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1525ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1525f0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1525f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1525f4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1525f4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1525f8: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1525f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1525fc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1525fcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152600: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152600u;
    {
        const bool branch_taken_0x152600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152600u;
            // 0x152604: 0xae830070  sw          $v1, 0x70($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152600) {
            ctx->pc = 0x152614u;
            goto label_152614;
        }
    }
    ctx->pc = 0x152608u;
label_152608:
    // 0x152608: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152608u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15260c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15260cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152610: 0xae820070  sw          $v0, 0x70($s4)
    ctx->pc = 0x152610u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
label_152614:
    // 0x152614: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152614u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152618: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152618u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15261c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15261cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152620: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152620u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152624: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152624u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152628: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152628u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15262c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15262cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152630: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152630u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152634: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152634u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152638: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152638u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15263c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15263cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152640: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152640u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152644: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152644u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152648: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152648u;
    {
        const bool branch_taken_0x152648 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15264Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152648u;
            // 0x15264c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152648) {
            ctx->pc = 0x15265Cu;
            goto label_15265c;
        }
    }
    ctx->pc = 0x152650u;
label_152650:
    // 0x152650: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152650u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x152654: 0xae820070  sw          $v0, 0x70($s4)
    ctx->pc = 0x152654u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
    // 0x152658: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152658u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15265c:
    // 0x15265c: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x15265cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x152660: 0x10400066  beqz        $v0, . + 4 + (0x66 << 2)
    ctx->pc = 0x152660u;
    {
        const bool branch_taken_0x152660 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x152664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152660u;
            // 0x152664: 0x2a620018  slti        $v0, $s3, 0x18 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)24) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x152660) {
            ctx->pc = 0x1527FCu;
            goto label_1527fc;
        }
    }
    ctx->pc = 0x152668u;
    // 0x152668: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152668u;
    {
        const bool branch_taken_0x152668 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15266Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152668u;
            // 0x15266c: 0x121602  srl         $v0, $s2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152668) {
            ctx->pc = 0x1526E0u;
            goto label_1526e0;
        }
    }
    ctx->pc = 0x152670u;
    // 0x152670: 0x2673ffe8  addiu       $s3, $s3, -0x18
    ctx->pc = 0x152670u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967272));
    // 0x152674: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152674u;
    {
        const bool branch_taken_0x152674 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152674u;
            // 0x152678: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152674) {
            ctx->pc = 0x152698u;
            goto label_152698;
        }
    }
    ctx->pc = 0x15267Cu;
    // 0x15267c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15267cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152680: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152680u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152684: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152684u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152688: 0x121e02  srl         $v1, $s2, 24
    ctx->pc = 0x152688u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x15268c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15268cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152690: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152690u;
    {
        const bool branch_taken_0x152690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152690u;
            // 0x152694: 0xae830074  sw          $v1, 0x74($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152690) {
            ctx->pc = 0x1526A4u;
            goto label_1526a4;
        }
    }
    ctx->pc = 0x152698u;
label_152698:
    // 0x152698: 0x121602  srl         $v0, $s2, 24
    ctx->pc = 0x152698u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x15269c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15269cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1526a0: 0xae820074  sw          $v0, 0x74($s4)
    ctx->pc = 0x1526a0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
label_1526a4:
    // 0x1526a4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1526a4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1526a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1526a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1526ac: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1526acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1526b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1526b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1526b4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1526b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1526b8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1526b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1526bc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1526bcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1526c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1526c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1526c4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1526c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1526c8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1526c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1526cc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1526ccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1526d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1526d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1526d4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1526d4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1526d8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1526D8u;
    {
        const bool branch_taken_0x1526d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1526DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1526D8u;
            // 0x1526dc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1526d8) {
            ctx->pc = 0x1526ECu;
            goto label_1526ec;
        }
    }
    ctx->pc = 0x1526E0u;
label_1526e0:
    // 0x1526e0: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x1526e0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x1526e4: 0xae820074  sw          $v0, 0x74($s4)
    ctx->pc = 0x1526e4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
    // 0x1526e8: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x1526e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_1526ec:
    // 0x1526ec: 0x2a620018  slti        $v0, $s3, 0x18
    ctx->pc = 0x1526ecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x1526f0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1526F0u;
    {
        const bool branch_taken_0x1526f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1526F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1526F0u;
            // 0x1526f4: 0x121602  srl         $v0, $s2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1526f0) {
            ctx->pc = 0x152768u;
            goto label_152768;
        }
    }
    ctx->pc = 0x1526F8u;
    // 0x1526f8: 0x2673ffe8  addiu       $s3, $s3, -0x18
    ctx->pc = 0x1526f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967272));
    // 0x1526fc: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1526FCu;
    {
        const bool branch_taken_0x1526fc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1526FCu;
            // 0x152700: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1526fc) {
            ctx->pc = 0x152720u;
            goto label_152720;
        }
    }
    ctx->pc = 0x152704u;
    // 0x152704: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152704u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152708: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152708u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15270c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15270cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152710: 0x121e02  srl         $v1, $s2, 24
    ctx->pc = 0x152710u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x152714: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152714u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152718: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152718u;
    {
        const bool branch_taken_0x152718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15271Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152718u;
            // 0x15271c: 0xae830078  sw          $v1, 0x78($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 120), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152718) {
            ctx->pc = 0x15272Cu;
            goto label_15272c;
        }
    }
    ctx->pc = 0x152720u;
label_152720:
    // 0x152720: 0x121602  srl         $v0, $s2, 24
    ctx->pc = 0x152720u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x152724: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152724u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152728: 0xae820078  sw          $v0, 0x78($s4)
    ctx->pc = 0x152728u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 120), GPR_U32(ctx, 2));
label_15272c:
    // 0x15272c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15272cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152730: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152730u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152734: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152734u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152738: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152738u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15273c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15273cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152740: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152740u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152744: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152744u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152748: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152748u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15274c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15274cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152750: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152750u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152754: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152754u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152758: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152758u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15275c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15275cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152760: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152760u;
    {
        const bool branch_taken_0x152760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152760u;
            // 0x152764: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152760) {
            ctx->pc = 0x152774u;
            goto label_152774;
        }
    }
    ctx->pc = 0x152768u;
label_152768:
    // 0x152768: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x152768u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x15276c: 0xae820078  sw          $v0, 0x78($s4)
    ctx->pc = 0x15276cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 120), GPR_U32(ctx, 2));
    // 0x152770: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x152770u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_152774:
    // 0x152774: 0x2a620018  slti        $v0, $s3, 0x18
    ctx->pc = 0x152774u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x152778: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152778u;
    {
        const bool branch_taken_0x152778 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15277Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152778u;
            // 0x15277c: 0x121602  srl         $v0, $s2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152778) {
            ctx->pc = 0x1527F0u;
            goto label_1527f0;
        }
    }
    ctx->pc = 0x152780u;
    // 0x152780: 0x2673ffe8  addiu       $s3, $s3, -0x18
    ctx->pc = 0x152780u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967272));
    // 0x152784: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152784u;
    {
        const bool branch_taken_0x152784 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152784u;
            // 0x152788: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152784) {
            ctx->pc = 0x1527A8u;
            goto label_1527a8;
        }
    }
    ctx->pc = 0x15278Cu;
    // 0x15278c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15278cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152790: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152790u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152794: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152794u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152798: 0x121e02  srl         $v1, $s2, 24
    ctx->pc = 0x152798u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x15279c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15279cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1527a0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1527A0u;
    {
        const bool branch_taken_0x1527a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1527A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1527A0u;
            // 0x1527a4: 0xae83007c  sw          $v1, 0x7C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 124), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1527a0) {
            ctx->pc = 0x1527B4u;
            goto label_1527b4;
        }
    }
    ctx->pc = 0x1527A8u;
label_1527a8:
    // 0x1527a8: 0x121602  srl         $v0, $s2, 24
    ctx->pc = 0x1527a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x1527ac: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1527acu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1527b0: 0xae82007c  sw          $v0, 0x7C($s4)
    ctx->pc = 0x1527b0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 124), GPR_U32(ctx, 2));
label_1527b4:
    // 0x1527b4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1527b4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1527b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1527b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1527bc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1527bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1527c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1527c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1527c4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1527c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1527c8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1527c8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1527cc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1527ccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1527d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1527d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1527d4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1527d4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1527d8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1527d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1527dc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1527dcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1527e0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1527e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1527e4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1527e4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1527e8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1527E8u;
    {
        const bool branch_taken_0x1527e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1527ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1527E8u;
            // 0x1527ec: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1527e8) {
            ctx->pc = 0x1527FCu;
            goto label_1527fc;
        }
    }
    ctx->pc = 0x1527F0u;
label_1527f0:
    // 0x1527f0: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x1527f0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x1527f4: 0xae82007c  sw          $v0, 0x7C($s4)
    ctx->pc = 0x1527f4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 124), GPR_U32(ctx, 2));
    // 0x1527f8: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x1527f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_1527fc:
    // 0x1527fc: 0x2a620012  slti        $v0, $s3, 0x12
    ctx->pc = 0x1527fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x152800: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152800u;
    {
        const bool branch_taken_0x152800 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152800u;
            // 0x152804: 0x121482  srl         $v0, $s2, 18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152800) {
            ctx->pc = 0x152878u;
            goto label_152878;
        }
    }
    ctx->pc = 0x152808u;
    // 0x152808: 0x2673ffee  addiu       $s3, $s3, -0x12
    ctx->pc = 0x152808u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967278));
    // 0x15280c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15280Cu;
    {
        const bool branch_taken_0x15280c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15280Cu;
            // 0x152810: 0x2402000e  addiu       $v0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15280c) {
            ctx->pc = 0x152830u;
            goto label_152830;
        }
    }
    ctx->pc = 0x152814u;
    // 0x152814: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152814u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152818: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152818u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15281c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15281cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152820: 0x121c82  srl         $v1, $s2, 18
    ctx->pc = 0x152820u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x152824: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152824u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152828: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152828u;
    {
        const bool branch_taken_0x152828 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15282Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152828u;
            // 0x15282c: 0xae830080  sw          $v1, 0x80($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 128), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152828) {
            ctx->pc = 0x15283Cu;
            goto label_15283c;
        }
    }
    ctx->pc = 0x152830u;
label_152830:
    // 0x152830: 0x121482  srl         $v0, $s2, 18
    ctx->pc = 0x152830u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x152834: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152834u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152838: 0xae820080  sw          $v0, 0x80($s4)
    ctx->pc = 0x152838u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 128), GPR_U32(ctx, 2));
label_15283c:
    // 0x15283c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15283cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152840: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152840u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152844: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152844u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152848: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152848u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15284c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15284cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152850: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152850u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152854: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152854u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152858: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152858u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15285c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15285cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152860: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152860u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152864: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152864u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152868: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152868u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15286c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15286cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152870: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152870u;
    {
        const bool branch_taken_0x152870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152870u;
            // 0x152874: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152870) {
            ctx->pc = 0x152884u;
            goto label_152884;
        }
    }
    ctx->pc = 0x152878u;
label_152878:
    // 0x152878: 0x129380  sll         $s2, $s2, 14
    ctx->pc = 0x152878u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 14));
    // 0x15287c: 0xae820080  sw          $v0, 0x80($s4)
    ctx->pc = 0x15287cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 128), GPR_U32(ctx, 2));
    // 0x152880: 0x2673000e  addiu       $s3, $s3, 0xE
    ctx->pc = 0x152880u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 14));
label_152884:
    // 0x152884: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152884u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x152888: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152888u;
    {
        const bool branch_taken_0x152888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15288Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152888u;
            // 0x15288c: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152888) {
            ctx->pc = 0x152900u;
            goto label_152900;
        }
    }
    ctx->pc = 0x152890u;
    // 0x152890: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152890u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152894: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152894u;
    {
        const bool branch_taken_0x152894 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152894u;
            // 0x152898: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152894) {
            ctx->pc = 0x1528B8u;
            goto label_1528b8;
        }
    }
    ctx->pc = 0x15289Cu;
    // 0x15289c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15289cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1528a0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1528a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1528a4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1528a4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1528a8: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1528a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1528ac: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1528acu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1528b0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1528B0u;
    {
        const bool branch_taken_0x1528b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1528B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1528B0u;
            // 0x1528b4: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1528b0) {
            ctx->pc = 0x1528C4u;
            goto label_1528c4;
        }
    }
    ctx->pc = 0x1528B8u;
label_1528b8:
    // 0x1528b8: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1528b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1528bc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1528bcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1528c0: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x1528c0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_1528c4:
    // 0x1528c4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1528c4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1528c8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1528c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1528cc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1528ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1528d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1528d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1528d4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1528d4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1528d8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1528d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1528dc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1528dcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1528e0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1528e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1528e4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1528e4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1528e8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1528e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1528ec: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1528ecu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1528f0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1528f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1528f4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1528f4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1528f8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1528F8u;
    {
        const bool branch_taken_0x1528f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1528FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1528F8u;
            // 0x1528fc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1528f8) {
            ctx->pc = 0x15290Cu;
            goto label_15290c;
        }
    }
    ctx->pc = 0x152900u;
label_152900:
    // 0x152900: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152900u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x152904: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x152904u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x152908: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152908u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15290c:
    // 0x15290c: 0x2a620012  slti        $v0, $s3, 0x12
    ctx->pc = 0x15290cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x152910: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x152910u;
    {
        const bool branch_taken_0x152910 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152910u;
            // 0x152914: 0x121482  srl         $v0, $s2, 18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152910) {
            ctx->pc = 0x152950u;
            goto label_152950;
        }
    }
    ctx->pc = 0x152918u;
    // 0x152918: 0x2673ffee  addiu       $s3, $s3, -0x12
    ctx->pc = 0x152918u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967278));
    // 0x15291c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15291Cu;
    {
        const bool branch_taken_0x15291c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15291Cu;
            // 0x152920: 0x2402000e  addiu       $v0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15291c) {
            ctx->pc = 0x152940u;
            goto label_152940;
        }
    }
    ctx->pc = 0x152924u;
    // 0x152924: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152924u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152928: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152928u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15292c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15292cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152930: 0x121c82  srl         $v1, $s2, 18
    ctx->pc = 0x152930u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x152934: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152934u;
    {
        const bool branch_taken_0x152934 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152934u;
            // 0x152938: 0xae830084  sw          $v1, 0x84($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 132), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152934) {
            ctx->pc = 0x152948u;
            goto label_152948;
        }
    }
    ctx->pc = 0x15293Cu;
    // 0x15293c: 0x0  nop
    ctx->pc = 0x15293cu;
    // NOP
label_152940:
    // 0x152940: 0x121482  srl         $v0, $s2, 18
    ctx->pc = 0x152940u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x152944: 0xae820084  sw          $v0, 0x84($s4)
    ctx->pc = 0x152944u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 132), GPR_U32(ctx, 2));
label_152948:
    // 0x152948: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x152948u;
    {
        const bool branch_taken_0x152948 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15294Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152948u;
            // 0x15294c: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152948) {
            ctx->pc = 0x152958u;
            goto label_152958;
        }
    }
    ctx->pc = 0x152950u;
label_152950:
    // 0x152950: 0x2673000e  addiu       $s3, $s3, 0xE
    ctx->pc = 0x152950u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 14));
    // 0x152954: 0xae820084  sw          $v0, 0x84($s4)
    ctx->pc = 0x152954u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 132), GPR_U32(ctx, 2));
label_152958:
    // 0x152958: 0xc0543b4  jal         func_150ED0
    ctx->pc = 0x152958u;
    SET_GPR_U32(ctx, 31, 0x152960u);
    ctx->pc = 0x15295Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x152958u;
            // 0x15295c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150ED0u;
    if (runtime->hasFunction(0x150ED0u)) {
        auto targetFn = runtime->lookupFunction(0x150ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152960u; }
        if (ctx->pc != 0x152960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150ED0_0x150ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152960u; }
        if (ctx->pc != 0x152960u) { return; }
    }
    ctx->pc = 0x152960u;
label_152960:
    // 0x152960: 0x100008b2  b           . + 4 + (0x8B2 << 2)
    ctx->pc = 0x152960u;
    {
        const bool branch_taken_0x152960 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152960u;
            // 0x152964: 0x2351823  subu        $v1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152960) {
            ctx->pc = 0x154C2Cu;
            goto label_154c2c;
        }
    }
    ctx->pc = 0x152968u;
label_152968:
    // 0x152968: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152968u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x15296c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x15296Cu;
    {
        const bool branch_taken_0x15296c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15296Cu;
            // 0x152970: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15296c) {
            ctx->pc = 0x1529E8u;
            goto label_1529e8;
        }
    }
    ctx->pc = 0x152974u;
    // 0x152974: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152974u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152978: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x152978u;
    {
        const bool branch_taken_0x152978 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x15297Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152978u;
            // 0x15297c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152978) {
            ctx->pc = 0x1529A0u;
            goto label_1529a0;
        }
    }
    ctx->pc = 0x152980u;
    // 0x152980: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152980u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152984: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152984u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152988: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152988u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x15298c: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x15298cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152990: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152990u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152994: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x152994u;
    {
        const bool branch_taken_0x152994 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152994u;
            // 0x152998: 0xae830024  sw          $v1, 0x24($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 36), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152994) {
            ctx->pc = 0x1529ACu;
            goto label_1529ac;
        }
    }
    ctx->pc = 0x15299Cu;
    // 0x15299c: 0x0  nop
    ctx->pc = 0x15299cu;
    // NOP
label_1529a0:
    // 0x1529a0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1529a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1529a4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1529a4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1529a8: 0xae820024  sw          $v0, 0x24($s4)
    ctx->pc = 0x1529a8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 36), GPR_U32(ctx, 2));
label_1529ac:
    // 0x1529ac: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1529acu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1529b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1529b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1529b4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1529b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1529b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1529b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1529bc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1529bcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1529c0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1529c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1529c4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1529c4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1529c8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1529c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1529cc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1529ccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1529d0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1529d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1529d4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1529d4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1529d8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1529d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1529dc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1529dcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1529e0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1529E0u;
    {
        const bool branch_taken_0x1529e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1529E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1529E0u;
            // 0x1529e4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1529e0) {
            ctx->pc = 0x1529F4u;
            goto label_1529f4;
        }
    }
    ctx->pc = 0x1529E8u;
label_1529e8:
    // 0x1529e8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x1529e8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1529ec: 0xae820024  sw          $v0, 0x24($s4)
    ctx->pc = 0x1529ecu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 36), GPR_U32(ctx, 2));
    // 0x1529f0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1529f0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1529f4:
    // 0x1529f4: 0x8e820024  lw          $v0, 0x24($s4)
    ctx->pc = 0x1529f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 36)));
    // 0x1529f8: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1529F8u;
    {
        const bool branch_taken_0x1529f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1529FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1529F8u;
            // 0x1529fc: 0x2a62001f  slti        $v0, $s3, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1529f8) {
            ctx->pc = 0x152A64u;
            goto label_152a64;
        }
    }
    ctx->pc = 0x152A00u;
    // 0x152a00: 0x2404003f  addiu       $a0, $zero, 0x3F
    ctx->pc = 0x152a00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x152a04: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x152a04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_152a08:
    // 0x152a08: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x152a08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x152a0c: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x152A0Cu;
    {
        const bool branch_taken_0x152a0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x152a0c) {
            ctx->pc = 0x152A10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x152A0Cu;
            // 0x152a10: 0x129200  sll         $s2, $s2, 8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x152A54u;
            goto label_152a54;
        }
    }
    ctx->pc = 0x152A14u;
    // 0x152a14: 0x2673ffe0  addiu       $s3, $s3, -0x20
    ctx->pc = 0x152a14u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967264));
    // 0x152a18: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152a18u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152a1c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152a1cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152a20: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152a20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152a24: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152a24u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152a28: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152a28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152a2c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152a2cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152a30: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152a30u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152a34: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152a34u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152a38: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152a38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152a3c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152a3cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152a40: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152a40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152a44: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152a44u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152a48: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152a48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152a4c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152a4cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152a50: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152a50u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
label_152a54:
    // 0x152a54: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x152a54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x152a58: 0x483ffeb  bgezl       $a0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x152A58u;
    {
        const bool branch_taken_0x152a58 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x152a58) {
            ctx->pc = 0x152A5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x152A58u;
            // 0x152a5c: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x152A08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_152a08;
        }
    }
    ctx->pc = 0x152A60u;
    // 0x152a60: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152a60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
label_152a64:
    // 0x152a64: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x152A64u;
    {
        const bool branch_taken_0x152a64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152A64u;
            // 0x152a68: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152a64) {
            ctx->pc = 0x152AE0u;
            goto label_152ae0;
        }
    }
    ctx->pc = 0x152A6Cu;
    // 0x152a6c: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152a6cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152a70: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x152A70u;
    {
        const bool branch_taken_0x152a70 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152A70u;
            // 0x152a74: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152a70) {
            ctx->pc = 0x152A98u;
            goto label_152a98;
        }
    }
    ctx->pc = 0x152A78u;
    // 0x152a78: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152a78u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152a7c: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152a80: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152a80u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152a84: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152a84u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152a88: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152a88u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152a8c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x152A8Cu;
    {
        const bool branch_taken_0x152a8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152A8Cu;
            // 0x152a90: 0xae830028  sw          $v1, 0x28($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 40), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152a8c) {
            ctx->pc = 0x152AA4u;
            goto label_152aa4;
        }
    }
    ctx->pc = 0x152A94u;
    // 0x152a94: 0x0  nop
    ctx->pc = 0x152a94u;
    // NOP
label_152a98:
    // 0x152a98: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152a98u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152a9c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152a9cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152aa0: 0xae820028  sw          $v0, 0x28($s4)
    ctx->pc = 0x152aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 40), GPR_U32(ctx, 2));
label_152aa4:
    // 0x152aa4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152aa4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152aa8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152aa8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152aac: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152aacu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152ab0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ab0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ab4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152ab4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152ab8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152ab8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152abc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152abcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152ac0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ac0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ac4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152ac4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152ac8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152ac8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152acc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152accu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152ad0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ad0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ad4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152ad4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152ad8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152AD8u;
    {
        const bool branch_taken_0x152ad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152AD8u;
            // 0x152adc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152ad8) {
            ctx->pc = 0x152AECu;
            goto label_152aec;
        }
    }
    ctx->pc = 0x152AE0u;
label_152ae0:
    // 0x152ae0: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152ae0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x152ae4: 0xae820028  sw          $v0, 0x28($s4)
    ctx->pc = 0x152ae4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 40), GPR_U32(ctx, 2));
    // 0x152ae8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152ae8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_152aec:
    // 0x152aec: 0x8e820028  lw          $v0, 0x28($s4)
    ctx->pc = 0x152aecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 40)));
    // 0x152af0: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x152AF0u;
    {
        const bool branch_taken_0x152af0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x152AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152AF0u;
            // 0x152af4: 0x2a62001f  slti        $v0, $s3, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x152af0) {
            ctx->pc = 0x152B5Cu;
            goto label_152b5c;
        }
    }
    ctx->pc = 0x152AF8u;
    // 0x152af8: 0x2404003f  addiu       $a0, $zero, 0x3F
    ctx->pc = 0x152af8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x152afc: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x152afcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_152b00:
    // 0x152b00: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x152b00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x152b04: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x152B04u;
    {
        const bool branch_taken_0x152b04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x152b04) {
            ctx->pc = 0x152B08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x152B04u;
            // 0x152b08: 0x129200  sll         $s2, $s2, 8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x152B4Cu;
            goto label_152b4c;
        }
    }
    ctx->pc = 0x152B0Cu;
    // 0x152b0c: 0x2673ffe0  addiu       $s3, $s3, -0x20
    ctx->pc = 0x152b0cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967264));
    // 0x152b10: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152b10u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152b14: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152b14u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152b18: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152b18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152b1c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152b1cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152b20: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152b20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152b24: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152b24u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152b28: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152b28u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152b2c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152b2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152b30: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152b30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152b34: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152b34u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152b38: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152b38u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152b3c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152b3cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152b40: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152b40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152b44: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152b44u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152b48: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152b48u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
label_152b4c:
    // 0x152b4c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x152b4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x152b50: 0x483ffeb  bgezl       $a0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x152B50u;
    {
        const bool branch_taken_0x152b50 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x152b50) {
            ctx->pc = 0x152B54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x152B50u;
            // 0x152b54: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x152B00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_152b00;
        }
    }
    ctx->pc = 0x152B58u;
    // 0x152b58: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152b58u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
label_152b5c:
    // 0x152b5c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x152B5Cu;
    {
        const bool branch_taken_0x152b5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152B5Cu;
            // 0x152b60: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152b5c) {
            ctx->pc = 0x152BD8u;
            goto label_152bd8;
        }
    }
    ctx->pc = 0x152B64u;
    // 0x152b64: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152b64u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152b68: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x152B68u;
    {
        const bool branch_taken_0x152b68 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152B6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152B68u;
            // 0x152b6c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152b68) {
            ctx->pc = 0x152B90u;
            goto label_152b90;
        }
    }
    ctx->pc = 0x152B70u;
    // 0x152b70: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152b70u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152b74: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152b74u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152b78: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152b78u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152b7c: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152b7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152b80: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152b80u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152b84: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x152B84u;
    {
        const bool branch_taken_0x152b84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152B84u;
            // 0x152b88: 0xae830158  sw          $v1, 0x158($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 344), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152b84) {
            ctx->pc = 0x152B9Cu;
            goto label_152b9c;
        }
    }
    ctx->pc = 0x152B8Cu;
    // 0x152b8c: 0x0  nop
    ctx->pc = 0x152b8cu;
    // NOP
label_152b90:
    // 0x152b90: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152b90u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152b94: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152b94u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152b98: 0xae820158  sw          $v0, 0x158($s4)
    ctx->pc = 0x152b98u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 344), GPR_U32(ctx, 2));
label_152b9c:
    // 0x152b9c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152b9cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152ba0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ba0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ba4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152ba4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152ba8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ba8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152bac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152bacu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152bb0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152bb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152bb4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152bb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152bb8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152bb8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152bbc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152bbcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152bc0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152bc0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152bc4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152bc4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152bc8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152bc8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152bcc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152bccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152bd0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152BD0u;
    {
        const bool branch_taken_0x152bd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152BD0u;
            // 0x152bd4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152bd0) {
            ctx->pc = 0x152BE4u;
            goto label_152be4;
        }
    }
    ctx->pc = 0x152BD8u;
label_152bd8:
    // 0x152bd8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152bd8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x152bdc: 0xae820158  sw          $v0, 0x158($s4)
    ctx->pc = 0x152bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 344), GPR_U32(ctx, 2));
    // 0x152be0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152be0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_152be4:
    // 0x152be4: 0x8e820158  lw          $v0, 0x158($s4)
    ctx->pc = 0x152be4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 344)));
    // 0x152be8: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x152BE8u;
    {
        const bool branch_taken_0x152be8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x152BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152BE8u;
            // 0x152bec: 0x2a62001f  slti        $v0, $s3, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x152be8) {
            ctx->pc = 0x152C54u;
            goto label_152c54;
        }
    }
    ctx->pc = 0x152BF0u;
    // 0x152bf0: 0x2404003f  addiu       $a0, $zero, 0x3F
    ctx->pc = 0x152bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x152bf4: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x152bf4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_152bf8:
    // 0x152bf8: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x152bf8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x152bfc: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x152BFCu;
    {
        const bool branch_taken_0x152bfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x152bfc) {
            ctx->pc = 0x152C00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x152BFCu;
            // 0x152c00: 0x129200  sll         $s2, $s2, 8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x152C44u;
            goto label_152c44;
        }
    }
    ctx->pc = 0x152C04u;
    // 0x152c04: 0x2673ffe0  addiu       $s3, $s3, -0x20
    ctx->pc = 0x152c04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967264));
    // 0x152c08: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152c08u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152c0c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152c0cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152c10: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152c10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152c14: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152c14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152c18: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152c18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152c1c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152c1cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152c20: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152c20u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152c24: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152c24u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152c28: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152c28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152c2c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152c2cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152c30: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152c30u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152c34: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152c34u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152c38: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152c38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152c3c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152c3cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152c40: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152c40u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
label_152c44:
    // 0x152c44: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x152c44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x152c48: 0x483ffeb  bgezl       $a0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x152C48u;
    {
        const bool branch_taken_0x152c48 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x152c48) {
            ctx->pc = 0x152C4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x152C48u;
            // 0x152c4c: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x152BF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_152bf8;
        }
    }
    ctx->pc = 0x152C50u;
    // 0x152c50: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152c50u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
label_152c54:
    // 0x152c54: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x152C54u;
    {
        const bool branch_taken_0x152c54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152C54u;
            // 0x152c58: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152c54) {
            ctx->pc = 0x152C90u;
            goto label_152c90;
        }
    }
    ctx->pc = 0x152C5Cu;
    // 0x152c5c: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152c5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152c60: 0x12600007  beqz        $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x152C60u;
    {
        const bool branch_taken_0x152c60 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152C60u;
            // 0x152c64: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152c60) {
            ctx->pc = 0x152C80u;
            goto label_152c80;
        }
    }
    ctx->pc = 0x152C68u;
    // 0x152c68: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152c68u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152c6c: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152c70: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152c70u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152c74: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152c74u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152c78: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x152C78u;
    {
        const bool branch_taken_0x152c78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152C78u;
            // 0x152c7c: 0xae83015c  sw          $v1, 0x15C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 348), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152c78) {
            ctx->pc = 0x152C88u;
            goto label_152c88;
        }
    }
    ctx->pc = 0x152C80u;
label_152c80:
    // 0x152c80: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152c80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152c84: 0xae82015c  sw          $v0, 0x15C($s4)
    ctx->pc = 0x152c84u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 348), GPR_U32(ctx, 2));
label_152c88:
    // 0x152c88: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x152C88u;
    {
        const bool branch_taken_0x152c88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152C88u;
            // 0x152c8c: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152c88) {
            ctx->pc = 0x152C98u;
            goto label_152c98;
        }
    }
    ctx->pc = 0x152C90u;
label_152c90:
    // 0x152c90: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152c90u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x152c94: 0xae82015c  sw          $v0, 0x15C($s4)
    ctx->pc = 0x152c94u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 348), GPR_U32(ctx, 2));
label_152c98:
    // 0x152c98: 0x8e82015c  lw          $v0, 0x15C($s4)
    ctx->pc = 0x152c98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 348)));
    // 0x152c9c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x152C9Cu;
    {
        const bool branch_taken_0x152c9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x152c9c) {
            ctx->pc = 0x152CD4u;
            goto label_152cd4;
        }
    }
    ctx->pc = 0x152CA4u;
    // 0x152ca4: 0x2403003f  addiu       $v1, $zero, 0x3F
    ctx->pc = 0x152ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x152ca8: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x152ca8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x152cac: 0x0  nop
    ctx->pc = 0x152cacu;
    // NOP
label_152cb0:
    // 0x152cb0: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x152cb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x152cb4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x152CB4u;
    {
        const bool branch_taken_0x152cb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152CB4u;
            // 0x152cb8: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152cb4) {
            ctx->pc = 0x152CC4u;
            goto label_152cc4;
        }
    }
    ctx->pc = 0x152CBCu;
    // 0x152cbc: 0x2673ffe0  addiu       $s3, $s3, -0x20
    ctx->pc = 0x152cbcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967264));
    // 0x152cc0: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x152cc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_152cc4:
    // 0x152cc4: 0x0  nop
    ctx->pc = 0x152cc4u;
    // NOP
    // 0x152cc8: 0x0  nop
    ctx->pc = 0x152cc8u;
    // NOP
    // 0x152ccc: 0x463fff8  bgezl       $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x152CCCu;
    {
        const bool branch_taken_0x152ccc = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x152ccc) {
            ctx->pc = 0x152CD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x152CCCu;
            // 0x152cd0: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x152CB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_152cb0;
        }
    }
    ctx->pc = 0x152CD4u;
label_152cd4:
    // 0x152cd4: 0xc05444c  jal         func_151130
    ctx->pc = 0x152CD4u;
    SET_GPR_U32(ctx, 31, 0x152CDCu);
    ctx->pc = 0x152CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x152CD4u;
            // 0x152cd8: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151130u;
    if (runtime->hasFunction(0x151130u)) {
        auto targetFn = runtime->lookupFunction(0x151130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152CDCu; }
        if (ctx->pc != 0x152CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151130_0x151130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x152CDCu; }
        if (ctx->pc != 0x152CDCu) { return; }
    }
    ctx->pc = 0x152CDCu;
label_152cdc:
    // 0x152cdc: 0x100007d3  b           . + 4 + (0x7D3 << 2)
    ctx->pc = 0x152CDCu;
    {
        const bool branch_taken_0x152cdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152CDCu;
            // 0x152ce0: 0x2351823  subu        $v1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152cdc) {
            ctx->pc = 0x154C2Cu;
            goto label_154c2c;
        }
    }
    ctx->pc = 0x152CE4u;
    // 0x152ce4: 0x0  nop
    ctx->pc = 0x152ce4u;
    // NOP
label_152ce8:
    // 0x152ce8: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152ce8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x152cec: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x152CECu;
    {
        const bool branch_taken_0x152cec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152CECu;
            // 0x152cf0: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152cec) {
            ctx->pc = 0x152D68u;
            goto label_152d68;
        }
    }
    ctx->pc = 0x152CF4u;
    // 0x152cf4: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152cf4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152cf8: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x152CF8u;
    {
        const bool branch_taken_0x152cf8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152CF8u;
            // 0x152cfc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152cf8) {
            ctx->pc = 0x152D20u;
            goto label_152d20;
        }
    }
    ctx->pc = 0x152D00u;
    // 0x152d00: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152d00u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152d04: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152d04u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152d08: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152d08u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152d0c: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152d10: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152d10u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152d14: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x152D14u;
    {
        const bool branch_taken_0x152d14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152D14u;
            // 0x152d18: 0xae83019c  sw          $v1, 0x19C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 412), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152d14) {
            ctx->pc = 0x152D2Cu;
            goto label_152d2c;
        }
    }
    ctx->pc = 0x152D1Cu;
    // 0x152d1c: 0x0  nop
    ctx->pc = 0x152d1cu;
    // NOP
label_152d20:
    // 0x152d20: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152d20u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152d24: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152d24u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152d28: 0xae82019c  sw          $v0, 0x19C($s4)
    ctx->pc = 0x152d28u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 412), GPR_U32(ctx, 2));
label_152d2c:
    // 0x152d2c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152d2cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152d30: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152d30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152d34: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152d34u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152d38: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152d38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152d3c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152d3cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152d40: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152d40u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152d44: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152d44u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152d48: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152d48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152d4c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152d4cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152d50: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152d50u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152d54: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152d54u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152d58: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152d58u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152d5c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152d5cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152d60: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152D60u;
    {
        const bool branch_taken_0x152d60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152D60u;
            // 0x152d64: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152d60) {
            ctx->pc = 0x152D74u;
            goto label_152d74;
        }
    }
    ctx->pc = 0x152D68u;
label_152d68:
    // 0x152d68: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152d68u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x152d6c: 0xae82019c  sw          $v0, 0x19C($s4)
    ctx->pc = 0x152d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 412), GPR_U32(ctx, 2));
    // 0x152d70: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152d70u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_152d74:
    // 0x152d74: 0x2a620018  slti        $v0, $s3, 0x18
    ctx->pc = 0x152d74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x152d78: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152D78u;
    {
        const bool branch_taken_0x152d78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152D78u;
            // 0x152d7c: 0x121602  srl         $v0, $s2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152d78) {
            ctx->pc = 0x152DF0u;
            goto label_152df0;
        }
    }
    ctx->pc = 0x152D80u;
    // 0x152d80: 0x2673ffe8  addiu       $s3, $s3, -0x18
    ctx->pc = 0x152d80u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967272));
    // 0x152d84: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152D84u;
    {
        const bool branch_taken_0x152d84 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152D84u;
            // 0x152d88: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152d84) {
            ctx->pc = 0x152DA8u;
            goto label_152da8;
        }
    }
    ctx->pc = 0x152D8Cu;
    // 0x152d8c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152d90: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152d90u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152d94: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152d94u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152d98: 0x121e02  srl         $v1, $s2, 24
    ctx->pc = 0x152d98u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x152d9c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152d9cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152da0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152DA0u;
    {
        const bool branch_taken_0x152da0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152DA0u;
            // 0x152da4: 0xae8301a0  sw          $v1, 0x1A0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 416), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152da0) {
            ctx->pc = 0x152DB4u;
            goto label_152db4;
        }
    }
    ctx->pc = 0x152DA8u;
label_152da8:
    // 0x152da8: 0x121602  srl         $v0, $s2, 24
    ctx->pc = 0x152da8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x152dac: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152dacu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152db0: 0xae8201a0  sw          $v0, 0x1A0($s4)
    ctx->pc = 0x152db0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 416), GPR_U32(ctx, 2));
label_152db4:
    // 0x152db4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152db4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152db8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152db8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152dbc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152dbcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152dc0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152dc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152dc4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152dc4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152dc8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152dc8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152dcc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152dccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152dd0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152dd0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152dd4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152dd4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152dd8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152dd8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152ddc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152ddcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152de0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152de0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152de4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152de4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152de8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152DE8u;
    {
        const bool branch_taken_0x152de8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152DE8u;
            // 0x152dec: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152de8) {
            ctx->pc = 0x152DFCu;
            goto label_152dfc;
        }
    }
    ctx->pc = 0x152DF0u;
label_152df0:
    // 0x152df0: 0x129200  sll         $s2, $s2, 8
    ctx->pc = 0x152df0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x152df4: 0xae8201a0  sw          $v0, 0x1A0($s4)
    ctx->pc = 0x152df4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 416), GPR_U32(ctx, 2));
    // 0x152df8: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x152df8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_152dfc:
    // 0x152dfc: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152dfcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x152e00: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152E00u;
    {
        const bool branch_taken_0x152e00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152E00u;
            // 0x152e04: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152e00) {
            ctx->pc = 0x152E78u;
            goto label_152e78;
        }
    }
    ctx->pc = 0x152E08u;
    // 0x152e08: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152e08u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152e0c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152E0Cu;
    {
        const bool branch_taken_0x152e0c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152E0Cu;
            // 0x152e10: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152e0c) {
            ctx->pc = 0x152E30u;
            goto label_152e30;
        }
    }
    ctx->pc = 0x152E14u;
    // 0x152e14: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152e14u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152e18: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152e18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152e1c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152e1cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152e20: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152e20u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152e24: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152e24u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152e28: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152E28u;
    {
        const bool branch_taken_0x152e28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152E28u;
            // 0x152e2c: 0xae8301a4  sw          $v1, 0x1A4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 420), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152e28) {
            ctx->pc = 0x152E3Cu;
            goto label_152e3c;
        }
    }
    ctx->pc = 0x152E30u;
label_152e30:
    // 0x152e30: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152e30u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152e34: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152e34u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152e38: 0xae8201a4  sw          $v0, 0x1A4($s4)
    ctx->pc = 0x152e38u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 420), GPR_U32(ctx, 2));
label_152e3c:
    // 0x152e3c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152e3cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152e40: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152e40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152e44: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152e44u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152e48: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152e48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152e4c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152e4cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152e50: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152e50u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152e54: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152e54u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152e58: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152e58u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152e5c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152e5cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152e60: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152e60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152e64: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152e64u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152e68: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152e68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152e6c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152e6cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152e70: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152E70u;
    {
        const bool branch_taken_0x152e70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152E70u;
            // 0x152e74: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152e70) {
            ctx->pc = 0x152E84u;
            goto label_152e84;
        }
    }
    ctx->pc = 0x152E78u;
label_152e78:
    // 0x152e78: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152e78u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x152e7c: 0xae8201a4  sw          $v0, 0x1A4($s4)
    ctx->pc = 0x152e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 420), GPR_U32(ctx, 2));
    // 0x152e80: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152e80u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_152e84:
    // 0x152e84: 0x2a620019  slti        $v0, $s3, 0x19
    ctx->pc = 0x152e84u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)25) ? 1 : 0);
    // 0x152e88: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152E88u;
    {
        const bool branch_taken_0x152e88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152E88u;
            // 0x152e8c: 0x121642  srl         $v0, $s2, 25 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 25));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152e88) {
            ctx->pc = 0x152F00u;
            goto label_152f00;
        }
    }
    ctx->pc = 0x152E90u;
    // 0x152e90: 0x2673ffe7  addiu       $s3, $s3, -0x19
    ctx->pc = 0x152e90u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967271));
    // 0x152e94: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152E94u;
    {
        const bool branch_taken_0x152e94 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152E94u;
            // 0x152e98: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152e94) {
            ctx->pc = 0x152EB8u;
            goto label_152eb8;
        }
    }
    ctx->pc = 0x152E9Cu;
    // 0x152e9c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152ea0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152ea0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152ea4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152ea4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152ea8: 0x121e42  srl         $v1, $s2, 25
    ctx->pc = 0x152ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 25));
    // 0x152eac: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152eacu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152eb0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152EB0u;
    {
        const bool branch_taken_0x152eb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152EB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152EB0u;
            // 0x152eb4: 0xae8301a8  sw          $v1, 0x1A8($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 424), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152eb0) {
            ctx->pc = 0x152EC4u;
            goto label_152ec4;
        }
    }
    ctx->pc = 0x152EB8u;
label_152eb8:
    // 0x152eb8: 0x121642  srl         $v0, $s2, 25
    ctx->pc = 0x152eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 25));
    // 0x152ebc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152ebcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152ec0: 0xae8201a8  sw          $v0, 0x1A8($s4)
    ctx->pc = 0x152ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 424), GPR_U32(ctx, 2));
label_152ec4:
    // 0x152ec4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152ec4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152ec8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ec8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ecc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152eccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152ed0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ed0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ed4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152ed4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152ed8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152ed8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152edc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152edcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152ee0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ee0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ee4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152ee4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152ee8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152ee8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152eec: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152eecu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152ef0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ef0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ef4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152ef4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152ef8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152EF8u;
    {
        const bool branch_taken_0x152ef8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152EF8u;
            // 0x152efc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152ef8) {
            ctx->pc = 0x152F0Cu;
            goto label_152f0c;
        }
    }
    ctx->pc = 0x152F00u;
label_152f00:
    // 0x152f00: 0x1291c0  sll         $s2, $s2, 7
    ctx->pc = 0x152f00u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 7));
    // 0x152f04: 0xae8201a8  sw          $v0, 0x1A8($s4)
    ctx->pc = 0x152f04u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 424), GPR_U32(ctx, 2));
    // 0x152f08: 0x26730007  addiu       $s3, $s3, 0x7
    ctx->pc = 0x152f08u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 7));
label_152f0c:
    // 0x152f0c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x152f0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x152f10: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152F10u;
    {
        const bool branch_taken_0x152f10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152F10u;
            // 0x152f14: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152f10) {
            ctx->pc = 0x152F88u;
            goto label_152f88;
        }
    }
    ctx->pc = 0x152F18u;
    // 0x152f18: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x152f18u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x152f1c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152F1Cu;
    {
        const bool branch_taken_0x152f1c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152F1Cu;
            // 0x152f20: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152f1c) {
            ctx->pc = 0x152F40u;
            goto label_152f40;
        }
    }
    ctx->pc = 0x152F24u;
    // 0x152f24: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152f24u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152f28: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152f28u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152f2c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152f2cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152f30: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x152f30u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152f34: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152f34u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152f38: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152F38u;
    {
        const bool branch_taken_0x152f38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152F38u;
            // 0x152f3c: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152f38) {
            ctx->pc = 0x152F4Cu;
            goto label_152f4c;
        }
    }
    ctx->pc = 0x152F40u;
label_152f40:
    // 0x152f40: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x152f40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x152f44: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152f44u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152f48: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x152f48u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_152f4c:
    // 0x152f4c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152f4cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152f50: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152f50u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152f54: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152f54u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152f58: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152f58u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152f5c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152f5cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152f60: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152f60u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152f64: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152f64u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152f68: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152f68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152f6c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152f6cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152f70: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152f70u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152f74: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152f74u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x152f78: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152f78u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152f7c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152f7cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152f80: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152F80u;
    {
        const bool branch_taken_0x152f80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152F80u;
            // 0x152f84: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152f80) {
            ctx->pc = 0x152F94u;
            goto label_152f94;
        }
    }
    ctx->pc = 0x152F88u;
label_152f88:
    // 0x152f88: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x152f88u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x152f8c: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x152f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x152f90: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x152f90u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_152f94:
    // 0x152f94: 0x2a62000c  slti        $v0, $s3, 0xC
    ctx->pc = 0x152f94u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)12) ? 1 : 0);
    // 0x152f98: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x152F98u;
    {
        const bool branch_taken_0x152f98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x152F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152F98u;
            // 0x152f9c: 0x121302  srl         $v0, $s2, 12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152f98) {
            ctx->pc = 0x153010u;
            goto label_153010;
        }
    }
    ctx->pc = 0x152FA0u;
    // 0x152fa0: 0x2673fff4  addiu       $s3, $s3, -0xC
    ctx->pc = 0x152fa0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967284));
    // 0x152fa4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x152FA4u;
    {
        const bool branch_taken_0x152fa4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x152FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152FA4u;
            // 0x152fa8: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152fa4) {
            ctx->pc = 0x152FC8u;
            goto label_152fc8;
        }
    }
    ctx->pc = 0x152FACu;
    // 0x152fac: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x152facu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x152fb0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x152fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x152fb4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x152fb4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x152fb8: 0x121b02  srl         $v1, $s2, 12
    ctx->pc = 0x152fb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 12));
    // 0x152fbc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x152fbcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x152fc0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x152FC0u;
    {
        const bool branch_taken_0x152fc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x152FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x152FC0u;
            // 0x152fc4: 0xae8301ac  sw          $v1, 0x1AC($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 428), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x152fc0) {
            ctx->pc = 0x152FD4u;
            goto label_152fd4;
        }
    }
    ctx->pc = 0x152FC8u;
label_152fc8:
    // 0x152fc8: 0x121302  srl         $v0, $s2, 12
    ctx->pc = 0x152fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 12));
    // 0x152fcc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x152fccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x152fd0: 0xae8201ac  sw          $v0, 0x1AC($s4)
    ctx->pc = 0x152fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 428), GPR_U32(ctx, 2));
label_152fd4:
    // 0x152fd4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x152fd4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152fd8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152fd8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152fdc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152fdcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152fe0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152fe0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152fe4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152fe4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152fe8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x152fe8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152fec: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x152fecu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x152ff0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x152ff0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x152ff4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x152ff4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x152ff8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x152ff8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x152ffc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x152ffcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153000: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153000u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153004: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153004u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153008: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153008u;
    {
        const bool branch_taken_0x153008 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15300Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153008u;
            // 0x15300c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153008) {
            ctx->pc = 0x15301Cu;
            goto label_15301c;
        }
    }
    ctx->pc = 0x153010u;
label_153010:
    // 0x153010: 0x129500  sll         $s2, $s2, 20
    ctx->pc = 0x153010u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 20));
    // 0x153014: 0xae8201ac  sw          $v0, 0x1AC($s4)
    ctx->pc = 0x153014u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 428), GPR_U32(ctx, 2));
    // 0x153018: 0x26730014  addiu       $s3, $s3, 0x14
    ctx->pc = 0x153018u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 20));
label_15301c:
    // 0x15301c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x15301cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153020: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153020u;
    {
        const bool branch_taken_0x153020 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153020u;
            // 0x153024: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153020) {
            ctx->pc = 0x153098u;
            goto label_153098;
        }
    }
    ctx->pc = 0x153028u;
    // 0x153028: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153028u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15302c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15302Cu;
    {
        const bool branch_taken_0x15302c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15302Cu;
            // 0x153030: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15302c) {
            ctx->pc = 0x153050u;
            goto label_153050;
        }
    }
    ctx->pc = 0x153034u;
    // 0x153034: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153034u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153038: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153038u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15303c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15303cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153040: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x153040u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153044: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153044u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153048: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153048u;
    {
        const bool branch_taken_0x153048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15304Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153048u;
            // 0x15304c: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153048) {
            ctx->pc = 0x15305Cu;
            goto label_15305c;
        }
    }
    ctx->pc = 0x153050u;
label_153050:
    // 0x153050: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153050u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153054: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153054u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153058: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x153058u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_15305c:
    // 0x15305c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15305cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153060: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153060u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153064: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153064u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153068: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153068u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15306c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15306cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153070: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153070u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153074: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153074u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153078: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153078u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15307c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15307cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153080: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153080u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153084: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153084u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153088: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153088u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15308c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15308cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153090: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153090u;
    {
        const bool branch_taken_0x153090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153090u;
            // 0x153094: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153090) {
            ctx->pc = 0x1530A4u;
            goto label_1530a4;
        }
    }
    ctx->pc = 0x153098u;
label_153098:
    // 0x153098: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x153098u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15309c: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x15309cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x1530a0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1530a0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1530a4:
    // 0x1530a4: 0x2a62000a  slti        $v0, $s3, 0xA
    ctx->pc = 0x1530a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1530a8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1530A8u;
    {
        const bool branch_taken_0x1530a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1530ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1530A8u;
            // 0x1530ac: 0x121282  srl         $v0, $s2, 10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1530a8) {
            ctx->pc = 0x153120u;
            goto label_153120;
        }
    }
    ctx->pc = 0x1530B0u;
    // 0x1530b0: 0x2673fff6  addiu       $s3, $s3, -0xA
    ctx->pc = 0x1530b0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967286));
    // 0x1530b4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1530B4u;
    {
        const bool branch_taken_0x1530b4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1530B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1530B4u;
            // 0x1530b8: 0x24020016  addiu       $v0, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1530b4) {
            ctx->pc = 0x1530D8u;
            goto label_1530d8;
        }
    }
    ctx->pc = 0x1530BCu;
    // 0x1530bc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1530bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1530c0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1530c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1530c4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1530c4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1530c8: 0x121a82  srl         $v1, $s2, 10
    ctx->pc = 0x1530c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 10));
    // 0x1530cc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1530ccu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1530d0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1530D0u;
    {
        const bool branch_taken_0x1530d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1530D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1530D0u;
            // 0x1530d4: 0xae8301b0  sw          $v1, 0x1B0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 432), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1530d0) {
            ctx->pc = 0x1530E4u;
            goto label_1530e4;
        }
    }
    ctx->pc = 0x1530D8u;
label_1530d8:
    // 0x1530d8: 0x121282  srl         $v0, $s2, 10
    ctx->pc = 0x1530d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 10));
    // 0x1530dc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1530dcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1530e0: 0xae8201b0  sw          $v0, 0x1B0($s4)
    ctx->pc = 0x1530e0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 432), GPR_U32(ctx, 2));
label_1530e4:
    // 0x1530e4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1530e4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1530e8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1530e8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1530ec: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1530ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1530f0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1530f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1530f4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1530f4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1530f8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1530f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1530fc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1530fcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153100: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153100u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153104: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153104u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153108: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153108u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15310c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15310cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153110: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153110u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153114: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153114u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153118: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153118u;
    {
        const bool branch_taken_0x153118 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15311Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153118u;
            // 0x15311c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153118) {
            ctx->pc = 0x15312Cu;
            goto label_15312c;
        }
    }
    ctx->pc = 0x153120u;
label_153120:
    // 0x153120: 0x129580  sll         $s2, $s2, 22
    ctx->pc = 0x153120u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 22));
    // 0x153124: 0xae8201b0  sw          $v0, 0x1B0($s4)
    ctx->pc = 0x153124u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 432), GPR_U32(ctx, 2));
    // 0x153128: 0x26730016  addiu       $s3, $s3, 0x16
    ctx->pc = 0x153128u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 22));
label_15312c:
    // 0x15312c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x15312cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153130: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153130u;
    {
        const bool branch_taken_0x153130 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153130u;
            // 0x153134: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153130) {
            ctx->pc = 0x1531A8u;
            goto label_1531a8;
        }
    }
    ctx->pc = 0x153138u;
    // 0x153138: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153138u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15313c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15313Cu;
    {
        const bool branch_taken_0x15313c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15313Cu;
            // 0x153140: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15313c) {
            ctx->pc = 0x153160u;
            goto label_153160;
        }
    }
    ctx->pc = 0x153144u;
    // 0x153144: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153144u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153148: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153148u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15314c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15314cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153150: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x153150u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153154: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153154u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153158: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153158u;
    {
        const bool branch_taken_0x153158 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15315Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153158u;
            // 0x15315c: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153158) {
            ctx->pc = 0x15316Cu;
            goto label_15316c;
        }
    }
    ctx->pc = 0x153160u;
label_153160:
    // 0x153160: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153160u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153164: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153164u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153168: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x153168u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_15316c:
    // 0x15316c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15316cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153170: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153170u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153174: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153174u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153178: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153178u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15317c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15317cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153180: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153180u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153184: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153184u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153188: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153188u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15318c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15318cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153190: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153190u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153194: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153194u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153198: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153198u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15319c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15319cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1531a0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1531A0u;
    {
        const bool branch_taken_0x1531a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1531A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1531A0u;
            // 0x1531a4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1531a0) {
            ctx->pc = 0x1531B4u;
            goto label_1531b4;
        }
    }
    ctx->pc = 0x1531A8u;
label_1531a8:
    // 0x1531a8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x1531a8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1531ac: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x1531acu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x1531b0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1531b0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1531b4:
    // 0x1531b4: 0x2a62000a  slti        $v0, $s3, 0xA
    ctx->pc = 0x1531b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1531b8: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1531B8u;
    {
        const bool branch_taken_0x1531b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1531BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1531B8u;
            // 0x1531bc: 0x121282  srl         $v0, $s2, 10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1531b8) {
            ctx->pc = 0x1531F8u;
            goto label_1531f8;
        }
    }
    ctx->pc = 0x1531C0u;
    // 0x1531c0: 0x2673fff6  addiu       $s3, $s3, -0xA
    ctx->pc = 0x1531c0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967286));
    // 0x1531c4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1531C4u;
    {
        const bool branch_taken_0x1531c4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1531C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1531C4u;
            // 0x1531c8: 0x24020016  addiu       $v0, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1531c4) {
            ctx->pc = 0x1531E8u;
            goto label_1531e8;
        }
    }
    ctx->pc = 0x1531CCu;
    // 0x1531cc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1531ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1531d0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1531d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1531d4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1531d4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1531d8: 0x121a82  srl         $v1, $s2, 10
    ctx->pc = 0x1531d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 10));
    // 0x1531dc: 0x1000068e  b           . + 4 + (0x68E << 2)
    ctx->pc = 0x1531DCu;
    {
        const bool branch_taken_0x1531dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1531E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1531DCu;
            // 0x1531e0: 0xae8301b4  sw          $v1, 0x1B4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 436), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1531dc) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x1531E4u;
    // 0x1531e4: 0x0  nop
    ctx->pc = 0x1531e4u;
    // NOP
label_1531e8:
    // 0x1531e8: 0x121282  srl         $v0, $s2, 10
    ctx->pc = 0x1531e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 10));
    // 0x1531ec: 0x1000068a  b           . + 4 + (0x68A << 2)
    ctx->pc = 0x1531ECu;
    {
        const bool branch_taken_0x1531ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1531F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1531ECu;
            // 0x1531f0: 0xae8201b4  sw          $v0, 0x1B4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 436), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1531ec) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x1531F4u;
    // 0x1531f4: 0x0  nop
    ctx->pc = 0x1531f4u;
    // NOP
label_1531f8:
    // 0x1531f8: 0x26730016  addiu       $s3, $s3, 0x16
    ctx->pc = 0x1531f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 22));
    // 0x1531fc: 0x1000068a  b           . + 4 + (0x68A << 2)
    ctx->pc = 0x1531FCu;
    {
        const bool branch_taken_0x1531fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1531FCu;
            // 0x153200: 0xae8201b4  sw          $v0, 0x1B4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 436), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1531fc) {
            ctx->pc = 0x154C28u;
            goto label_154c28;
        }
    }
    ctx->pc = 0x153204u;
    // 0x153204: 0x0  nop
    ctx->pc = 0x153204u;
    // NOP
label_153208:
    // 0x153208: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x153208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15320c: 0x2a63001e  slti        $v1, $s3, 0x1E
    ctx->pc = 0x15320cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x153210: 0x1460001d  bnez        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x153210u;
    {
        const bool branch_taken_0x153210 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x153214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153210u;
            // 0x153214: 0xae820330  sw          $v0, 0x330($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 816), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153210) {
            ctx->pc = 0x153288u;
            goto label_153288;
        }
    }
    ctx->pc = 0x153218u;
    // 0x153218: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x153218u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x15321c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15321Cu;
    {
        const bool branch_taken_0x15321c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15321Cu;
            // 0x153220: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15321c) {
            ctx->pc = 0x153240u;
            goto label_153240;
        }
    }
    ctx->pc = 0x153224u;
    // 0x153224: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153224u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153228: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153228u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15322c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15322cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153230: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x153230u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x153234: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153234u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153238: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153238u;
    {
        const bool branch_taken_0x153238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15323Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153238u;
            // 0x15323c: 0xae830088  sw          $v1, 0x88($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 136), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153238) {
            ctx->pc = 0x15324Cu;
            goto label_15324c;
        }
    }
    ctx->pc = 0x153240u;
label_153240:
    // 0x153240: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x153240u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x153244: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153244u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153248: 0xae820088  sw          $v0, 0x88($s4)
    ctx->pc = 0x153248u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 136), GPR_U32(ctx, 2));
label_15324c:
    // 0x15324c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15324cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153250: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153250u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153254: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153254u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153258: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153258u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15325c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15325cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153260: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153260u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153264: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153264u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153268: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153268u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15326c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15326cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153270: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153270u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153274: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153274u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153278: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153278u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15327c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15327cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153280: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x153280u;
    {
        const bool branch_taken_0x153280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153280u;
            // 0x153284: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153280) {
            ctx->pc = 0x153298u;
            goto label_153298;
        }
    }
    ctx->pc = 0x153288u;
label_153288:
    // 0x153288: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x153288u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x15328c: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x15328cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x153290: 0xae820088  sw          $v0, 0x88($s4)
    ctx->pc = 0x153290u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 136), GPR_U32(ctx, 2));
    // 0x153294: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x153294u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_153298:
    // 0x153298: 0x2a62001c  slti        $v0, $s3, 0x1C
    ctx->pc = 0x153298u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x15329c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x15329Cu;
    {
        const bool branch_taken_0x15329c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1532A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15329Cu;
            // 0x1532a0: 0x121702  srl         $v0, $s2, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15329c) {
            ctx->pc = 0x153318u;
            goto label_153318;
        }
    }
    ctx->pc = 0x1532A4u;
    // 0x1532a4: 0x2673ffe4  addiu       $s3, $s3, -0x1C
    ctx->pc = 0x1532a4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967268));
    // 0x1532a8: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x1532A8u;
    {
        const bool branch_taken_0x1532a8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1532ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1532A8u;
            // 0x1532ac: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1532a8) {
            ctx->pc = 0x1532D0u;
            goto label_1532d0;
        }
    }
    ctx->pc = 0x1532B0u;
    // 0x1532b0: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1532b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1532b4: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1532b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1532b8: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1532b8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1532bc: 0x121f02  srl         $v1, $s2, 28
    ctx->pc = 0x1532bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x1532c0: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1532c0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1532c4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1532C4u;
    {
        const bool branch_taken_0x1532c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1532C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1532C4u;
            // 0x1532c8: 0xae83008c  sw          $v1, 0x8C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 140), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1532c4) {
            ctx->pc = 0x1532DCu;
            goto label_1532dc;
        }
    }
    ctx->pc = 0x1532CCu;
    // 0x1532cc: 0x0  nop
    ctx->pc = 0x1532ccu;
    // NOP
label_1532d0:
    // 0x1532d0: 0x121702  srl         $v0, $s2, 28
    ctx->pc = 0x1532d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x1532d4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1532d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1532d8: 0xae82008c  sw          $v0, 0x8C($s4)
    ctx->pc = 0x1532d8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 140), GPR_U32(ctx, 2));
label_1532dc:
    // 0x1532dc: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1532dcu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1532e0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1532e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1532e4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1532e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1532e8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1532e8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1532ec: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1532ecu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1532f0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1532f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1532f4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1532f4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1532f8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1532f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1532fc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1532fcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153300: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153300u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153304: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153304u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153308: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153308u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15330c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15330cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153310: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153310u;
    {
        const bool branch_taken_0x153310 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153310u;
            // 0x153314: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153310) {
            ctx->pc = 0x153324u;
            goto label_153324;
        }
    }
    ctx->pc = 0x153318u;
label_153318:
    // 0x153318: 0x129100  sll         $s2, $s2, 4
    ctx->pc = 0x153318u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x15331c: 0xae82008c  sw          $v0, 0x8C($s4)
    ctx->pc = 0x15331cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 140), GPR_U32(ctx, 2));
    // 0x153320: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x153320u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
label_153324:
    // 0x153324: 0x8e830088  lw          $v1, 0x88($s4)
    ctx->pc = 0x153324u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 136)));
    // 0x153328: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x153328u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15332c: 0x146400e2  bne         $v1, $a0, . + 4 + (0xE2 << 2)
    ctx->pc = 0x15332Cu;
    {
        const bool branch_taken_0x15332c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x153330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15332Cu;
            // 0x153330: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15332c) {
            ctx->pc = 0x1536B8u;
            goto label_1536b8;
        }
    }
    ctx->pc = 0x153334u;
    // 0x153334: 0x2a620012  slti        $v0, $s3, 0x12
    ctx->pc = 0x153334u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x153338: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153338u;
    {
        const bool branch_taken_0x153338 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15333Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153338u;
            // 0x15333c: 0x121482  srl         $v0, $s2, 18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153338) {
            ctx->pc = 0x1533B0u;
            goto label_1533b0;
        }
    }
    ctx->pc = 0x153340u;
    // 0x153340: 0x2673ffee  addiu       $s3, $s3, -0x12
    ctx->pc = 0x153340u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967278));
    // 0x153344: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153344u;
    {
        const bool branch_taken_0x153344 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153344u;
            // 0x153348: 0x2402000e  addiu       $v0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153344) {
            ctx->pc = 0x153368u;
            goto label_153368;
        }
    }
    ctx->pc = 0x15334Cu;
    // 0x15334c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15334cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153350: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153350u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153354: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153354u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153358: 0x121c82  srl         $v1, $s2, 18
    ctx->pc = 0x153358u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x15335c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15335cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153360: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153360u;
    {
        const bool branch_taken_0x153360 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153360u;
            // 0x153364: 0xae830090  sw          $v1, 0x90($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153360) {
            ctx->pc = 0x153374u;
            goto label_153374;
        }
    }
    ctx->pc = 0x153368u;
label_153368:
    // 0x153368: 0x121482  srl         $v0, $s2, 18
    ctx->pc = 0x153368u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x15336c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15336cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153370: 0xae820090  sw          $v0, 0x90($s4)
    ctx->pc = 0x153370u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 144), GPR_U32(ctx, 2));
label_153374:
    // 0x153374: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153374u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153378: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153378u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15337c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15337cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153380: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153380u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153384: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153384u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153388: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153388u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15338c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15338cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153390: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153390u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153394: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153394u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153398: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153398u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15339c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15339cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1533a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1533a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1533a4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1533a4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1533a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1533A8u;
    {
        const bool branch_taken_0x1533a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1533ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1533A8u;
            // 0x1533ac: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1533a8) {
            ctx->pc = 0x1533BCu;
            goto label_1533bc;
        }
    }
    ctx->pc = 0x1533B0u;
label_1533b0:
    // 0x1533b0: 0x129380  sll         $s2, $s2, 14
    ctx->pc = 0x1533b0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 14));
    // 0x1533b4: 0xae820090  sw          $v0, 0x90($s4)
    ctx->pc = 0x1533b4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 144), GPR_U32(ctx, 2));
    // 0x1533b8: 0x2673000e  addiu       $s3, $s3, 0xE
    ctx->pc = 0x1533b8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 14));
label_1533bc:
    // 0x1533bc: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1533bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1533c0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1533C0u;
    {
        const bool branch_taken_0x1533c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1533C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1533C0u;
            // 0x1533c4: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1533c0) {
            ctx->pc = 0x153438u;
            goto label_153438;
        }
    }
    ctx->pc = 0x1533C8u;
    // 0x1533c8: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1533c8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1533cc: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1533CCu;
    {
        const bool branch_taken_0x1533cc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1533D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1533CCu;
            // 0x1533d0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1533cc) {
            ctx->pc = 0x1533F0u;
            goto label_1533f0;
        }
    }
    ctx->pc = 0x1533D4u;
    // 0x1533d4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1533d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1533d8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1533d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1533dc: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1533dcu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1533e0: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1533e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1533e4: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1533e4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1533e8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1533E8u;
    {
        const bool branch_taken_0x1533e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1533ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1533E8u;
            // 0x1533ec: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1533e8) {
            ctx->pc = 0x1533FCu;
            goto label_1533fc;
        }
    }
    ctx->pc = 0x1533F0u;
label_1533f0:
    // 0x1533f0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1533f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1533f4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1533f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1533f8: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x1533f8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_1533fc:
    // 0x1533fc: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1533fcu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153400: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153400u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153404: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153404u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153408: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153408u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15340c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15340cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153410: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153410u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153414: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153414u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153418: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153418u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15341c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15341cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153420: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153420u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153424: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153424u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153428: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153428u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15342c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15342cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153430: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153430u;
    {
        const bool branch_taken_0x153430 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153430u;
            // 0x153434: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153430) {
            ctx->pc = 0x153444u;
            goto label_153444;
        }
    }
    ctx->pc = 0x153438u;
label_153438:
    // 0x153438: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x153438u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15343c: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x15343cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x153440: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x153440u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_153444:
    // 0x153444: 0x2a620012  slti        $v0, $s3, 0x12
    ctx->pc = 0x153444u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x153448: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153448u;
    {
        const bool branch_taken_0x153448 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15344Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153448u;
            // 0x15344c: 0x121482  srl         $v0, $s2, 18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153448) {
            ctx->pc = 0x1534C0u;
            goto label_1534c0;
        }
    }
    ctx->pc = 0x153450u;
    // 0x153450: 0x2673ffee  addiu       $s3, $s3, -0x12
    ctx->pc = 0x153450u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967278));
    // 0x153454: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153454u;
    {
        const bool branch_taken_0x153454 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153454u;
            // 0x153458: 0x2402000e  addiu       $v0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153454) {
            ctx->pc = 0x153478u;
            goto label_153478;
        }
    }
    ctx->pc = 0x15345Cu;
    // 0x15345c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15345cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153460: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153460u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153464: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153464u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153468: 0x121c82  srl         $v1, $s2, 18
    ctx->pc = 0x153468u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x15346c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15346cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153470: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153470u;
    {
        const bool branch_taken_0x153470 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153470u;
            // 0x153474: 0xae830094  sw          $v1, 0x94($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 148), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153470) {
            ctx->pc = 0x153484u;
            goto label_153484;
        }
    }
    ctx->pc = 0x153478u;
label_153478:
    // 0x153478: 0x121482  srl         $v0, $s2, 18
    ctx->pc = 0x153478u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 18));
    // 0x15347c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15347cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153480: 0xae820094  sw          $v0, 0x94($s4)
    ctx->pc = 0x153480u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 148), GPR_U32(ctx, 2));
label_153484:
    // 0x153484: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153484u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153488: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153488u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15348c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15348cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153490: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153490u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153494: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153494u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153498: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153498u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15349c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15349cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1534a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1534a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1534a4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1534a4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1534a8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1534a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1534ac: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1534acu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1534b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1534b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1534b4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1534b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1534b8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1534B8u;
    {
        const bool branch_taken_0x1534b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1534BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1534B8u;
            // 0x1534bc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1534b8) {
            ctx->pc = 0x1534CCu;
            goto label_1534cc;
        }
    }
    ctx->pc = 0x1534C0u;
label_1534c0:
    // 0x1534c0: 0x129380  sll         $s2, $s2, 14
    ctx->pc = 0x1534c0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 14));
    // 0x1534c4: 0xae820094  sw          $v0, 0x94($s4)
    ctx->pc = 0x1534c4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 148), GPR_U32(ctx, 2));
    // 0x1534c8: 0x2673000e  addiu       $s3, $s3, 0xE
    ctx->pc = 0x1534c8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 14));
label_1534cc:
    // 0x1534cc: 0x2a62001b  slti        $v0, $s3, 0x1B
    ctx->pc = 0x1534ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x1534d0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1534D0u;
    {
        const bool branch_taken_0x1534d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1534D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1534D0u;
            // 0x1534d4: 0x1216c2  srl         $v0, $s2, 27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1534d0) {
            ctx->pc = 0x153548u;
            goto label_153548;
        }
    }
    ctx->pc = 0x1534D8u;
    // 0x1534d8: 0x2673ffe5  addiu       $s3, $s3, -0x1B
    ctx->pc = 0x1534d8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967269));
    // 0x1534dc: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1534DCu;
    {
        const bool branch_taken_0x1534dc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1534E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1534DCu;
            // 0x1534e0: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1534dc) {
            ctx->pc = 0x153500u;
            goto label_153500;
        }
    }
    ctx->pc = 0x1534E4u;
    // 0x1534e4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1534e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1534e8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1534e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1534ec: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1534ecu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1534f0: 0x121ec2  srl         $v1, $s2, 27
    ctx->pc = 0x1534f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x1534f4: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1534f4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1534f8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1534F8u;
    {
        const bool branch_taken_0x1534f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1534FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1534F8u;
            // 0x1534fc: 0xae830098  sw          $v1, 0x98($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 152), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1534f8) {
            ctx->pc = 0x15350Cu;
            goto label_15350c;
        }
    }
    ctx->pc = 0x153500u;
label_153500:
    // 0x153500: 0x1216c2  srl         $v0, $s2, 27
    ctx->pc = 0x153500u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x153504: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153504u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153508: 0xae820098  sw          $v0, 0x98($s4)
    ctx->pc = 0x153508u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 152), GPR_U32(ctx, 2));
label_15350c:
    // 0x15350c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15350cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153510: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153510u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153514: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153514u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153518: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153518u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15351c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15351cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153520: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153520u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153524: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153524u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153528: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153528u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15352c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15352cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153530: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153530u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153534: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153534u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153538: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153538u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15353c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15353cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153540: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153540u;
    {
        const bool branch_taken_0x153540 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153540u;
            // 0x153544: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153540) {
            ctx->pc = 0x153554u;
            goto label_153554;
        }
    }
    ctx->pc = 0x153548u;
label_153548:
    // 0x153548: 0x129140  sll         $s2, $s2, 5
    ctx->pc = 0x153548u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 5));
    // 0x15354c: 0xae820098  sw          $v0, 0x98($s4)
    ctx->pc = 0x15354cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 152), GPR_U32(ctx, 2));
    // 0x153550: 0x26730005  addiu       $s3, $s3, 0x5
    ctx->pc = 0x153550u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 5));
label_153554:
    // 0x153554: 0x2a62001b  slti        $v0, $s3, 0x1B
    ctx->pc = 0x153554u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x153558: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153558u;
    {
        const bool branch_taken_0x153558 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15355Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153558u;
            // 0x15355c: 0x1216c2  srl         $v0, $s2, 27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153558) {
            ctx->pc = 0x1535D0u;
            goto label_1535d0;
        }
    }
    ctx->pc = 0x153560u;
    // 0x153560: 0x2673ffe5  addiu       $s3, $s3, -0x1B
    ctx->pc = 0x153560u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967269));
    // 0x153564: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153564u;
    {
        const bool branch_taken_0x153564 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153564u;
            // 0x153568: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153564) {
            ctx->pc = 0x153588u;
            goto label_153588;
        }
    }
    ctx->pc = 0x15356Cu;
    // 0x15356c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15356cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153570: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153570u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153574: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153574u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153578: 0x121ec2  srl         $v1, $s2, 27
    ctx->pc = 0x153578u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x15357c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15357cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153580: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153580u;
    {
        const bool branch_taken_0x153580 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153580u;
            // 0x153584: 0xae83009c  sw          $v1, 0x9C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 156), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153580) {
            ctx->pc = 0x153594u;
            goto label_153594;
        }
    }
    ctx->pc = 0x153588u;
label_153588:
    // 0x153588: 0x1216c2  srl         $v0, $s2, 27
    ctx->pc = 0x153588u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x15358c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15358cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153590: 0xae82009c  sw          $v0, 0x9C($s4)
    ctx->pc = 0x153590u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 156), GPR_U32(ctx, 2));
label_153594:
    // 0x153594: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153594u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153598: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153598u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15359c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15359cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1535a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1535a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1535a4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1535a4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1535a8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1535a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1535ac: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1535acu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1535b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1535b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1535b4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1535b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1535b8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1535b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1535bc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1535bcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1535c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1535c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1535c4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1535c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1535c8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1535C8u;
    {
        const bool branch_taken_0x1535c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1535CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1535C8u;
            // 0x1535cc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1535c8) {
            ctx->pc = 0x1535DCu;
            goto label_1535dc;
        }
    }
    ctx->pc = 0x1535D0u;
label_1535d0:
    // 0x1535d0: 0x129140  sll         $s2, $s2, 5
    ctx->pc = 0x1535d0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 5));
    // 0x1535d4: 0xae82009c  sw          $v0, 0x9C($s4)
    ctx->pc = 0x1535d4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 156), GPR_U32(ctx, 2));
    // 0x1535d8: 0x26730005  addiu       $s3, $s3, 0x5
    ctx->pc = 0x1535d8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 5));
label_1535dc:
    // 0x1535dc: 0x2a62001b  slti        $v0, $s3, 0x1B
    ctx->pc = 0x1535dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x1535e0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1535E0u;
    {
        const bool branch_taken_0x1535e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1535E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1535E0u;
            // 0x1535e4: 0x1216c2  srl         $v0, $s2, 27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1535e0) {
            ctx->pc = 0x153658u;
            goto label_153658;
        }
    }
    ctx->pc = 0x1535E8u;
    // 0x1535e8: 0x2673ffe5  addiu       $s3, $s3, -0x1B
    ctx->pc = 0x1535e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967269));
    // 0x1535ec: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1535ECu;
    {
        const bool branch_taken_0x1535ec = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1535F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1535ECu;
            // 0x1535f0: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1535ec) {
            ctx->pc = 0x153610u;
            goto label_153610;
        }
    }
    ctx->pc = 0x1535F4u;
    // 0x1535f4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1535f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1535f8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1535f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1535fc: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1535fcu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153600: 0x121ec2  srl         $v1, $s2, 27
    ctx->pc = 0x153600u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x153604: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153604u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153608: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153608u;
    {
        const bool branch_taken_0x153608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15360Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153608u;
            // 0x15360c: 0xae8300a0  sw          $v1, 0xA0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 160), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153608) {
            ctx->pc = 0x15361Cu;
            goto label_15361c;
        }
    }
    ctx->pc = 0x153610u;
label_153610:
    // 0x153610: 0x1216c2  srl         $v0, $s2, 27
    ctx->pc = 0x153610u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x153614: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153614u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153618: 0xae8200a0  sw          $v0, 0xA0($s4)
    ctx->pc = 0x153618u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 160), GPR_U32(ctx, 2));
label_15361c:
    // 0x15361c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15361cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153620: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153620u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153624: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153624u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153628: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153628u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15362c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15362cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153630: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153630u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153634: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153634u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153638: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153638u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15363c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15363cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153640: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153640u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153644: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153644u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153648: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153648u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15364c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15364cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153650: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153650u;
    {
        const bool branch_taken_0x153650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153650u;
            // 0x153654: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153650) {
            ctx->pc = 0x153664u;
            goto label_153664;
        }
    }
    ctx->pc = 0x153658u;
label_153658:
    // 0x153658: 0x129140  sll         $s2, $s2, 5
    ctx->pc = 0x153658u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 5));
    // 0x15365c: 0xae8200a0  sw          $v0, 0xA0($s4)
    ctx->pc = 0x15365cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 160), GPR_U32(ctx, 2));
    // 0x153660: 0x26730005  addiu       $s3, $s3, 0x5
    ctx->pc = 0x153660u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 5));
label_153664:
    // 0x153664: 0x2a62001b  slti        $v0, $s3, 0x1B
    ctx->pc = 0x153664u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x153668: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x153668u;
    {
        const bool branch_taken_0x153668 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15366Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153668u;
            // 0x15366c: 0x1216c2  srl         $v0, $s2, 27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153668) {
            ctx->pc = 0x1536A8u;
            goto label_1536a8;
        }
    }
    ctx->pc = 0x153670u;
    // 0x153670: 0x2673ffe5  addiu       $s3, $s3, -0x1B
    ctx->pc = 0x153670u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967269));
    // 0x153674: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153674u;
    {
        const bool branch_taken_0x153674 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153674u;
            // 0x153678: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153674) {
            ctx->pc = 0x153698u;
            goto label_153698;
        }
    }
    ctx->pc = 0x15367Cu;
    // 0x15367c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15367cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153680: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153680u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153684: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153684u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153688: 0x121ec2  srl         $v1, $s2, 27
    ctx->pc = 0x153688u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x15368c: 0x10000562  b           . + 4 + (0x562 << 2)
    ctx->pc = 0x15368Cu;
    {
        const bool branch_taken_0x15368c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15368Cu;
            // 0x153690: 0xae8300a4  sw          $v1, 0xA4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 164), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15368c) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x153694u;
    // 0x153694: 0x0  nop
    ctx->pc = 0x153694u;
    // NOP
label_153698:
    // 0x153698: 0x1216c2  srl         $v0, $s2, 27
    ctx->pc = 0x153698u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 27));
    // 0x15369c: 0x1000055e  b           . + 4 + (0x55E << 2)
    ctx->pc = 0x15369Cu;
    {
        const bool branch_taken_0x15369c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1536A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15369Cu;
            // 0x1536a0: 0xae8200a4  sw          $v0, 0xA4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 164), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15369c) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x1536A4u;
    // 0x1536a4: 0x0  nop
    ctx->pc = 0x1536a4u;
    // NOP
label_1536a8:
    // 0x1536a8: 0x26730005  addiu       $s3, $s3, 0x5
    ctx->pc = 0x1536a8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 5));
    // 0x1536ac: 0x1000055e  b           . + 4 + (0x55E << 2)
    ctx->pc = 0x1536ACu;
    {
        const bool branch_taken_0x1536ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1536B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1536ACu;
            // 0x1536b0: 0xae8200a4  sw          $v0, 0xA4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 164), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1536ac) {
            ctx->pc = 0x154C28u;
            goto label_154c28;
        }
    }
    ctx->pc = 0x1536B4u;
    // 0x1536b4: 0x0  nop
    ctx->pc = 0x1536b4u;
    // NOP
label_1536b8:
    // 0x1536b8: 0x5462055c  bnel        $v1, $v0, . + 4 + (0x55C << 2)
    ctx->pc = 0x1536B8u;
    {
        const bool branch_taken_0x1536b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1536b8) {
            ctx->pc = 0x1536BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1536B8u;
            // 0x1536bc: 0x2351823  subu        $v1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x154C2Cu;
            goto label_154c2c;
        }
    }
    ctx->pc = 0x1536C0u;
    // 0x1536c0: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1536c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1536c4: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1536C4u;
    {
        const bool branch_taken_0x1536c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1536C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1536C4u;
            // 0x1536c8: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1536c4) {
            ctx->pc = 0x153738u;
            goto label_153738;
        }
    }
    ctx->pc = 0x1536CCu;
    // 0x1536cc: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1536ccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1536d0: 0x12600007  beqz        $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x1536D0u;
    {
        const bool branch_taken_0x1536d0 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1536D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1536D0u;
            // 0x1536d4: 0x931023  subu        $v0, $a0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1536d0) {
            ctx->pc = 0x1536F0u;
            goto label_1536f0;
        }
    }
    ctx->pc = 0x1536D8u;
    // 0x1536d8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1536d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1536dc: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1536dcu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1536e0: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1536e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1536e4: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1536e4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1536e8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1536E8u;
    {
        const bool branch_taken_0x1536e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1536ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1536E8u;
            // 0x1536ec: 0xae8300a8  sw          $v1, 0xA8($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 168), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1536e8) {
            ctx->pc = 0x1536FCu;
            goto label_1536fc;
        }
    }
    ctx->pc = 0x1536F0u;
label_1536f0:
    // 0x1536f0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1536f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1536f4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1536f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1536f8: 0xae8200a8  sw          $v0, 0xA8($s4)
    ctx->pc = 0x1536f8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 168), GPR_U32(ctx, 2));
label_1536fc:
    // 0x1536fc: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1536fcu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153700: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153700u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153704: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153704u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153708: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153708u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15370c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15370cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153710: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153710u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153714: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153714u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153718: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153718u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15371c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15371cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153720: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153720u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153724: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153724u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153728: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153728u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15372c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15372cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153730: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153730u;
    {
        const bool branch_taken_0x153730 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153730u;
            // 0x153734: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153730) {
            ctx->pc = 0x153744u;
            goto label_153744;
        }
    }
    ctx->pc = 0x153738u;
label_153738:
    // 0x153738: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x153738u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15373c: 0xae8200a8  sw          $v0, 0xA8($s4)
    ctx->pc = 0x15373cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 168), GPR_U32(ctx, 2));
    // 0x153740: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x153740u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_153744:
    // 0x153744: 0x8e8200a8  lw          $v0, 0xA8($s4)
    ctx->pc = 0x153744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 168)));
    // 0x153748: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x153748u;
    {
        const bool branch_taken_0x153748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15374Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153748u;
            // 0x15374c: 0x2a62001f  slti        $v0, $s3, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x153748) {
            ctx->pc = 0x1537D4u;
            goto label_1537d4;
        }
    }
    ctx->pc = 0x153750u;
    // 0x153750: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153750u;
    {
        const bool branch_taken_0x153750 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153750u;
            // 0x153754: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153750) {
            ctx->pc = 0x1537C8u;
            goto label_1537c8;
        }
    }
    ctx->pc = 0x153758u;
    // 0x153758: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153758u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15375c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15375Cu;
    {
        const bool branch_taken_0x15375c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15375Cu;
            // 0x153760: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15375c) {
            ctx->pc = 0x153780u;
            goto label_153780;
        }
    }
    ctx->pc = 0x153764u;
    // 0x153764: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153764u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153768: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153768u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15376c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15376cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153770: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x153770u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153774: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153774u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153778: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153778u;
    {
        const bool branch_taken_0x153778 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15377Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153778u;
            // 0x15377c: 0xae8300ac  sw          $v1, 0xAC($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 172), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153778) {
            ctx->pc = 0x15378Cu;
            goto label_15378c;
        }
    }
    ctx->pc = 0x153780u;
label_153780:
    // 0x153780: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153780u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153784: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153784u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153788: 0xae8200ac  sw          $v0, 0xAC($s4)
    ctx->pc = 0x153788u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 172), GPR_U32(ctx, 2));
label_15378c:
    // 0x15378c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15378cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153790: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153790u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153794: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153794u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153798: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153798u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15379c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15379cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1537a0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1537a0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1537a4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1537a4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1537a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1537a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1537ac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1537acu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1537b0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1537b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1537b4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1537b4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1537b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1537b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1537bc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1537bcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1537c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1537C0u;
    {
        const bool branch_taken_0x1537c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1537C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1537C0u;
            // 0x1537c4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1537c0) {
            ctx->pc = 0x1537D4u;
            goto label_1537d4;
        }
    }
    ctx->pc = 0x1537C8u;
label_1537c8:
    // 0x1537c8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x1537c8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1537cc: 0xae8200ac  sw          $v0, 0xAC($s4)
    ctx->pc = 0x1537ccu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 172), GPR_U32(ctx, 2));
    // 0x1537d0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1537d0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1537d4:
    // 0x1537d4: 0x2a62001d  slti        $v0, $s3, 0x1D
    ctx->pc = 0x1537d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x1537d8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1537D8u;
    {
        const bool branch_taken_0x1537d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1537DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1537D8u;
            // 0x1537dc: 0x121742  srl         $v0, $s2, 29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1537d8) {
            ctx->pc = 0x153850u;
            goto label_153850;
        }
    }
    ctx->pc = 0x1537E0u;
    // 0x1537e0: 0x2673ffe3  addiu       $s3, $s3, -0x1D
    ctx->pc = 0x1537e0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967267));
    // 0x1537e4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1537E4u;
    {
        const bool branch_taken_0x1537e4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1537E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1537E4u;
            // 0x1537e8: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1537e4) {
            ctx->pc = 0x153808u;
            goto label_153808;
        }
    }
    ctx->pc = 0x1537ECu;
    // 0x1537ec: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1537ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1537f0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1537f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1537f4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1537f4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1537f8: 0x121f42  srl         $v1, $s2, 29
    ctx->pc = 0x1537f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x1537fc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1537fcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153800: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153800u;
    {
        const bool branch_taken_0x153800 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153800u;
            // 0x153804: 0xae8300b0  sw          $v1, 0xB0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 176), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153800) {
            ctx->pc = 0x153814u;
            goto label_153814;
        }
    }
    ctx->pc = 0x153808u;
label_153808:
    // 0x153808: 0x121742  srl         $v0, $s2, 29
    ctx->pc = 0x153808u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x15380c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15380cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153810: 0xae8200b0  sw          $v0, 0xB0($s4)
    ctx->pc = 0x153810u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 176), GPR_U32(ctx, 2));
label_153814:
    // 0x153814: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153814u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153818: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153818u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15381c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15381cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153820: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153820u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153824: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153824u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153828: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153828u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15382c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15382cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153830: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153830u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153834: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153834u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153838: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153838u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15383c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15383cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153840: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153840u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153844: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153844u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153848: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153848u;
    {
        const bool branch_taken_0x153848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15384Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153848u;
            // 0x15384c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153848) {
            ctx->pc = 0x15385Cu;
            goto label_15385c;
        }
    }
    ctx->pc = 0x153850u;
label_153850:
    // 0x153850: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x153850u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x153854: 0xae8200b0  sw          $v0, 0xB0($s4)
    ctx->pc = 0x153854u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 176), GPR_U32(ctx, 2));
    // 0x153858: 0x26730003  addiu       $s3, $s3, 0x3
    ctx->pc = 0x153858u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
label_15385c:
    // 0x15385c: 0x2a62001d  slti        $v0, $s3, 0x1D
    ctx->pc = 0x15385cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x153860: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x153860u;
    {
        const bool branch_taken_0x153860 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153860u;
            // 0x153864: 0x121742  srl         $v0, $s2, 29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153860) {
            ctx->pc = 0x1538A0u;
            goto label_1538a0;
        }
    }
    ctx->pc = 0x153868u;
    // 0x153868: 0x2673ffe3  addiu       $s3, $s3, -0x1D
    ctx->pc = 0x153868u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967267));
    // 0x15386c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15386Cu;
    {
        const bool branch_taken_0x15386c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15386Cu;
            // 0x153870: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15386c) {
            ctx->pc = 0x153890u;
            goto label_153890;
        }
    }
    ctx->pc = 0x153874u;
    // 0x153874: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153874u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153878: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153878u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15387c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15387cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153880: 0x121f42  srl         $v1, $s2, 29
    ctx->pc = 0x153880u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x153884: 0x100004e4  b           . + 4 + (0x4E4 << 2)
    ctx->pc = 0x153884u;
    {
        const bool branch_taken_0x153884 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153884u;
            // 0x153888: 0xae8300b4  sw          $v1, 0xB4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 180), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153884) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x15388Cu;
    // 0x15388c: 0x0  nop
    ctx->pc = 0x15388cu;
    // NOP
label_153890:
    // 0x153890: 0x121742  srl         $v0, $s2, 29
    ctx->pc = 0x153890u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x153894: 0x100004e0  b           . + 4 + (0x4E0 << 2)
    ctx->pc = 0x153894u;
    {
        const bool branch_taken_0x153894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153894u;
            // 0x153898: 0xae8200b4  sw          $v0, 0xB4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 180), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153894) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x15389Cu;
    // 0x15389c: 0x0  nop
    ctx->pc = 0x15389cu;
    // NOP
label_1538a0:
    // 0x1538a0: 0x26730003  addiu       $s3, $s3, 0x3
    ctx->pc = 0x1538a0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
    // 0x1538a4: 0x100004e0  b           . + 4 + (0x4E0 << 2)
    ctx->pc = 0x1538A4u;
    {
        const bool branch_taken_0x1538a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1538A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1538A4u;
            // 0x1538a8: 0xae8200b4  sw          $v0, 0xB4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 180), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1538a4) {
            ctx->pc = 0x154C28u;
            goto label_154c28;
        }
    }
    ctx->pc = 0x1538ACu;
    // 0x1538ac: 0x0  nop
    ctx->pc = 0x1538acu;
    // NOP
label_1538b0:
    // 0x1538b0: 0xc05441c  jal         func_151070
    ctx->pc = 0x1538B0u;
    SET_GPR_U32(ctx, 31, 0x1538B8u);
    ctx->pc = 0x1538B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1538B0u;
            // 0x1538b4: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151070u;
    if (runtime->hasFunction(0x151070u)) {
        auto targetFn = runtime->lookupFunction(0x151070u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1538B8u; }
        if (ctx->pc != 0x1538B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151070_0x151070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1538B8u; }
        if (ctx->pc != 0x1538B8u) { return; }
    }
    ctx->pc = 0x1538B8u;
label_1538b8:
    // 0x1538b8: 0x8e820038  lw          $v0, 0x38($s4)
    ctx->pc = 0x1538b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 56)));
    // 0x1538bc: 0x184004da  blez        $v0, . + 4 + (0x4DA << 2)
    ctx->pc = 0x1538BCu;
    {
        const bool branch_taken_0x1538bc = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1538C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1538BCu;
            // 0x1538c0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1538bc) {
            ctx->pc = 0x154C28u;
            goto label_154c28;
        }
    }
    ctx->pc = 0x1538C4u;
    // 0x1538c4: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1538c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1538c8: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1538c8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1538cc: 0x2685016c  addiu       $a1, $s4, 0x16C
    ctx->pc = 0x1538ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 364));
    // 0x1538d0: 0x26840160  addiu       $a0, $s4, 0x160
    ctx->pc = 0x1538d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 352));
    // 0x1538d4: 0x0  nop
    ctx->pc = 0x1538d4u;
    // NOP
label_1538d8:
    // 0x1538d8: 0x2a620010  slti        $v0, $s3, 0x10
    ctx->pc = 0x1538d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1538dc: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1538DCu;
    {
        const bool branch_taken_0x1538dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1538E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1538DCu;
            // 0x1538e0: 0x121402  srl         $v0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1538dc) {
            ctx->pc = 0x153950u;
            goto label_153950;
        }
    }
    ctx->pc = 0x1538E4u;
    // 0x1538e4: 0x2673fff0  addiu       $s3, $s3, -0x10
    ctx->pc = 0x1538e4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967280));
    // 0x1538e8: 0x12600007  beqz        $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x1538E8u;
    {
        const bool branch_taken_0x1538e8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1538ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1538E8u;
            // 0x1538ec: 0x1131023  subu        $v0, $t0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1538e8) {
            ctx->pc = 0x153908u;
            goto label_153908;
        }
    }
    ctx->pc = 0x1538F0u;
    // 0x1538f0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1538f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1538f4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1538f4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1538f8: 0x121c02  srl         $v1, $s2, 16
    ctx->pc = 0x1538f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 16));
    // 0x1538fc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1538fcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153900: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153900u;
    {
        const bool branch_taken_0x153900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153900u;
            // 0x153904: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153900) {
            ctx->pc = 0x153914u;
            goto label_153914;
        }
    }
    ctx->pc = 0x153908u;
label_153908:
    // 0x153908: 0x121402  srl         $v0, $s2, 16
    ctx->pc = 0x153908u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 16));
    // 0x15390c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15390cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153910: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x153910u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_153914:
    // 0x153914: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153914u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153918: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153918u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15391c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15391cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153920: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153920u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153924: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153924u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153928: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153928u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15392c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15392cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153930: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153930u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153934: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153934u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153938: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153938u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15393c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15393cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153940: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153940u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153944: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153944u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153948: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153948u;
    {
        const bool branch_taken_0x153948 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15394Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153948u;
            // 0x15394c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153948) {
            ctx->pc = 0x15395Cu;
            goto label_15395c;
        }
    }
    ctx->pc = 0x153950u;
label_153950:
    // 0x153950: 0x129400  sll         $s2, $s2, 16
    ctx->pc = 0x153950u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
    // 0x153954: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x153954u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x153958: 0x26730010  addiu       $s3, $s3, 0x10
    ctx->pc = 0x153958u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
label_15395c:
    // 0x15395c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x15395cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153960: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153960u;
    {
        const bool branch_taken_0x153960 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153960u;
            // 0x153964: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153960) {
            ctx->pc = 0x1539D8u;
            goto label_1539d8;
        }
    }
    ctx->pc = 0x153968u;
    // 0x153968: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153968u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15396c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15396Cu;
    {
        const bool branch_taken_0x15396c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15396Cu;
            // 0x153970: 0xf31023  subu        $v0, $a3, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15396c) {
            ctx->pc = 0x153990u;
            goto label_153990;
        }
    }
    ctx->pc = 0x153974u;
    // 0x153974: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153974u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153978: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153978u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x15397c: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x15397cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153980: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153980u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153984: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x153984u;
    {
        const bool branch_taken_0x153984 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153984u;
            // 0x153988: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153984) {
            ctx->pc = 0x15399Cu;
            goto label_15399c;
        }
    }
    ctx->pc = 0x15398Cu;
    // 0x15398c: 0x0  nop
    ctx->pc = 0x15398cu;
    // NOP
label_153990:
    // 0x153990: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153990u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153994: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153994u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153998: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x153998u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_15399c:
    // 0x15399c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15399cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1539a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1539a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1539a4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1539a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1539a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1539a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1539ac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1539acu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1539b0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1539b0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1539b4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1539b4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1539b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1539b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1539bc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1539bcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1539c0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1539c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1539c4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1539c4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1539c8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1539c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1539cc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1539ccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1539d0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1539D0u;
    {
        const bool branch_taken_0x1539d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1539D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1539D0u;
            // 0x1539d4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1539d0) {
            ctx->pc = 0x1539E4u;
            goto label_1539e4;
        }
    }
    ctx->pc = 0x1539D8u;
label_1539d8:
    // 0x1539d8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x1539d8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1539dc: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x1539dcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x1539e0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1539e0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1539e4:
    // 0x1539e4: 0x2a620010  slti        $v0, $s3, 0x10
    ctx->pc = 0x1539e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1539e8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1539E8u;
    {
        const bool branch_taken_0x1539e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1539ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1539E8u;
            // 0x1539ec: 0x121402  srl         $v0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1539e8) {
            ctx->pc = 0x153A60u;
            goto label_153a60;
        }
    }
    ctx->pc = 0x1539F0u;
    // 0x1539f0: 0x2673fff0  addiu       $s3, $s3, -0x10
    ctx->pc = 0x1539f0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967280));
    // 0x1539f4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1539F4u;
    {
        const bool branch_taken_0x1539f4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1539F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1539F4u;
            // 0x1539f8: 0x1131023  subu        $v0, $t0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1539f4) {
            ctx->pc = 0x153A18u;
            goto label_153a18;
        }
    }
    ctx->pc = 0x1539FCu;
    // 0x1539fc: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1539fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153a00: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153a00u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153a04: 0x121c02  srl         $v1, $s2, 16
    ctx->pc = 0x153a04u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 16));
    // 0x153a08: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153a08u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153a0c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x153A0Cu;
    {
        const bool branch_taken_0x153a0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153A0Cu;
            // 0x153a10: 0xaca30000  sw          $v1, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153a0c) {
            ctx->pc = 0x153A24u;
            goto label_153a24;
        }
    }
    ctx->pc = 0x153A14u;
    // 0x153a14: 0x0  nop
    ctx->pc = 0x153a14u;
    // NOP
label_153a18:
    // 0x153a18: 0x121402  srl         $v0, $s2, 16
    ctx->pc = 0x153a18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 16));
    // 0x153a1c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153a1cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153a20: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x153a20u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_153a24:
    // 0x153a24: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153a24u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153a28: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153a28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153a2c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153a2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153a30: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153a30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153a34: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153a34u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153a38: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153a38u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153a3c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153a3cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153a40: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153a40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153a44: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153a44u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153a48: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153a48u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153a4c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153a4cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153a50: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153a50u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153a54: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153a54u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153a58: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153A58u;
    {
        const bool branch_taken_0x153a58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153A58u;
            // 0x153a5c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153a58) {
            ctx->pc = 0x153A6Cu;
            goto label_153a6c;
        }
    }
    ctx->pc = 0x153A60u;
label_153a60:
    // 0x153a60: 0x129400  sll         $s2, $s2, 16
    ctx->pc = 0x153a60u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
    // 0x153a64: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x153a64u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x153a68: 0x26730010  addiu       $s3, $s3, 0x10
    ctx->pc = 0x153a68u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
label_153a6c:
    // 0x153a6c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x153a6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153a70: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153A70u;
    {
        const bool branch_taken_0x153a70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153A70u;
            // 0x153a74: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153a70) {
            ctx->pc = 0x153AE8u;
            goto label_153ae8;
        }
    }
    ctx->pc = 0x153A78u;
    // 0x153a78: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153a78u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x153a7c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153A7Cu;
    {
        const bool branch_taken_0x153a7c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153A7Cu;
            // 0x153a80: 0xf31023  subu        $v0, $a3, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153a7c) {
            ctx->pc = 0x153AA0u;
            goto label_153aa0;
        }
    }
    ctx->pc = 0x153A84u;
    // 0x153a84: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153a84u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153a88: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153a88u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153a8c: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x153a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153a90: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153a90u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153a94: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x153A94u;
    {
        const bool branch_taken_0x153a94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153A94u;
            // 0x153a98: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153a94) {
            ctx->pc = 0x153AACu;
            goto label_153aac;
        }
    }
    ctx->pc = 0x153A9Cu;
    // 0x153a9c: 0x0  nop
    ctx->pc = 0x153a9cu;
    // NOP
label_153aa0:
    // 0x153aa0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153aa4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153aa4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153aa8: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x153aa8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_153aac:
    // 0x153aac: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153aacu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153ab0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153ab0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153ab4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153ab4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153ab8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153ab8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153abc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153abcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153ac0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153ac0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153ac4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153ac4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153ac8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153ac8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153acc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153accu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153ad0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153ad0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153ad4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153ad4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153ad8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153ad8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153adc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153adcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153ae0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153AE0u;
    {
        const bool branch_taken_0x153ae0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153AE0u;
            // 0x153ae4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ae0) {
            ctx->pc = 0x153AF4u;
            goto label_153af4;
        }
    }
    ctx->pc = 0x153AE8u;
label_153ae8:
    // 0x153ae8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x153ae8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x153aec: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x153aecu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x153af0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x153af0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_153af4:
    // 0x153af4: 0x8e820038  lw          $v0, 0x38($s4)
    ctx->pc = 0x153af4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 56)));
    // 0x153af8: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x153af8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x153afc: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x153afcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x153b00: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x153b00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x153b04: 0x1440ff74  bnez        $v0, . + 4 + (-0x8C << 2)
    ctx->pc = 0x153B04u;
    {
        const bool branch_taken_0x153b04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153B04u;
            // 0x153b08: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153b04) {
            ctx->pc = 0x1538D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1538d8;
        }
    }
    ctx->pc = 0x153B0Cu;
    // 0x153b0c: 0x10000447  b           . + 4 + (0x447 << 2)
    ctx->pc = 0x153B0Cu;
    {
        const bool branch_taken_0x153b0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153B0Cu;
            // 0x153b10: 0x2351823  subu        $v1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153b0c) {
            ctx->pc = 0x154C2Cu;
            goto label_154c2c;
        }
    }
    ctx->pc = 0x153B14u;
    // 0x153b14: 0x0  nop
    ctx->pc = 0x153b14u;
    // NOP
label_153b18:
    // 0x153b18: 0x2a62001c  slti        $v0, $s3, 0x1C
    ctx->pc = 0x153b18u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x153b1c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x153B1Cu;
    {
        const bool branch_taken_0x153b1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153B1Cu;
            // 0x153b20: 0x121702  srl         $v0, $s2, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153b1c) {
            ctx->pc = 0x153B98u;
            goto label_153b98;
        }
    }
    ctx->pc = 0x153B24u;
    // 0x153b24: 0x2673ffe4  addiu       $s3, $s3, -0x1C
    ctx->pc = 0x153b24u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967268));
    // 0x153b28: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x153B28u;
    {
        const bool branch_taken_0x153b28 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153B28u;
            // 0x153b2c: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153b28) {
            ctx->pc = 0x153B50u;
            goto label_153b50;
        }
    }
    ctx->pc = 0x153B30u;
    // 0x153b30: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153b30u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153b34: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153b34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153b38: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153b38u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153b3c: 0x121f02  srl         $v1, $s2, 28
    ctx->pc = 0x153b3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153b40: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153b40u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153b44: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x153B44u;
    {
        const bool branch_taken_0x153b44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153B44u;
            // 0x153b48: 0xae830104  sw          $v1, 0x104($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 260), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153b44) {
            ctx->pc = 0x153B5Cu;
            goto label_153b5c;
        }
    }
    ctx->pc = 0x153B4Cu;
    // 0x153b4c: 0x0  nop
    ctx->pc = 0x153b4cu;
    // NOP
label_153b50:
    // 0x153b50: 0x121702  srl         $v0, $s2, 28
    ctx->pc = 0x153b50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153b54: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153b54u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153b58: 0xae820104  sw          $v0, 0x104($s4)
    ctx->pc = 0x153b58u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 260), GPR_U32(ctx, 2));
label_153b5c:
    // 0x153b5c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153b5cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153b60: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153b60u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153b64: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153b64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153b68: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153b68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153b6c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153b6cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153b70: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153b70u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153b74: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153b74u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153b78: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153b78u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153b7c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153b7cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153b80: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153b80u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153b84: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153b84u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153b88: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153b88u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153b8c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153b8cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153b90: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153B90u;
    {
        const bool branch_taken_0x153b90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153B94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153B90u;
            // 0x153b94: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153b90) {
            ctx->pc = 0x153BA4u;
            goto label_153ba4;
        }
    }
    ctx->pc = 0x153B98u;
label_153b98:
    // 0x153b98: 0x129100  sll         $s2, $s2, 4
    ctx->pc = 0x153b98u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x153b9c: 0xae820104  sw          $v0, 0x104($s4)
    ctx->pc = 0x153b9cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 260), GPR_U32(ctx, 2));
    // 0x153ba0: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x153ba0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
label_153ba4:
    // 0x153ba4: 0x2a62001c  slti        $v0, $s3, 0x1C
    ctx->pc = 0x153ba4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x153ba8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153BA8u;
    {
        const bool branch_taken_0x153ba8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153BA8u;
            // 0x153bac: 0x121702  srl         $v0, $s2, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ba8) {
            ctx->pc = 0x153C20u;
            goto label_153c20;
        }
    }
    ctx->pc = 0x153BB0u;
    // 0x153bb0: 0x2673ffe4  addiu       $s3, $s3, -0x1C
    ctx->pc = 0x153bb0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967268));
    // 0x153bb4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153BB4u;
    {
        const bool branch_taken_0x153bb4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153BB4u;
            // 0x153bb8: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153bb4) {
            ctx->pc = 0x153BD8u;
            goto label_153bd8;
        }
    }
    ctx->pc = 0x153BBCu;
    // 0x153bbc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153bc0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153bc4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153bc4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153bc8: 0x121f02  srl         $v1, $s2, 28
    ctx->pc = 0x153bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153bcc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153bccu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153bd0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153BD0u;
    {
        const bool branch_taken_0x153bd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153BD0u;
            // 0x153bd4: 0xae830108  sw          $v1, 0x108($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 264), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153bd0) {
            ctx->pc = 0x153BE4u;
            goto label_153be4;
        }
    }
    ctx->pc = 0x153BD8u;
label_153bd8:
    // 0x153bd8: 0x121702  srl         $v0, $s2, 28
    ctx->pc = 0x153bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153bdc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153bdcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153be0: 0xae820108  sw          $v0, 0x108($s4)
    ctx->pc = 0x153be0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 264), GPR_U32(ctx, 2));
label_153be4:
    // 0x153be4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153be4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153be8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153be8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153bec: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153becu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153bf0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153bf0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153bf4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153bf4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153bf8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153bf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153bfc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153bfcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153c00: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153c00u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153c04: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153c04u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153c08: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153c08u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153c0c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153c0cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153c10: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153c10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153c14: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153c14u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153c18: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153C18u;
    {
        const bool branch_taken_0x153c18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153C18u;
            // 0x153c1c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153c18) {
            ctx->pc = 0x153C2Cu;
            goto label_153c2c;
        }
    }
    ctx->pc = 0x153C20u;
label_153c20:
    // 0x153c20: 0x129100  sll         $s2, $s2, 4
    ctx->pc = 0x153c20u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x153c24: 0xae820108  sw          $v0, 0x108($s4)
    ctx->pc = 0x153c24u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 264), GPR_U32(ctx, 2));
    // 0x153c28: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x153c28u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
label_153c2c:
    // 0x153c2c: 0x2a62001c  slti        $v0, $s3, 0x1C
    ctx->pc = 0x153c2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x153c30: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153C30u;
    {
        const bool branch_taken_0x153c30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153C30u;
            // 0x153c34: 0x121702  srl         $v0, $s2, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153c30) {
            ctx->pc = 0x153CA8u;
            goto label_153ca8;
        }
    }
    ctx->pc = 0x153C38u;
    // 0x153c38: 0x2673ffe4  addiu       $s3, $s3, -0x1C
    ctx->pc = 0x153c38u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967268));
    // 0x153c3c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153C3Cu;
    {
        const bool branch_taken_0x153c3c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153C3Cu;
            // 0x153c40: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153c3c) {
            ctx->pc = 0x153C60u;
            goto label_153c60;
        }
    }
    ctx->pc = 0x153C44u;
    // 0x153c44: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153c44u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153c48: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153c48u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153c4c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153c4cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153c50: 0x121f02  srl         $v1, $s2, 28
    ctx->pc = 0x153c50u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153c54: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153c54u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153c58: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153C58u;
    {
        const bool branch_taken_0x153c58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153C58u;
            // 0x153c5c: 0xae83010c  sw          $v1, 0x10C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 268), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153c58) {
            ctx->pc = 0x153C6Cu;
            goto label_153c6c;
        }
    }
    ctx->pc = 0x153C60u;
label_153c60:
    // 0x153c60: 0x121702  srl         $v0, $s2, 28
    ctx->pc = 0x153c60u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153c64: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153c64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153c68: 0xae82010c  sw          $v0, 0x10C($s4)
    ctx->pc = 0x153c68u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 268), GPR_U32(ctx, 2));
label_153c6c:
    // 0x153c6c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153c6cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153c70: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153c70u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153c74: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153c74u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153c78: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153c78u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153c7c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153c7cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153c80: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153c80u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153c84: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153c84u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153c88: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153c88u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153c8c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153c8cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153c90: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153c90u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153c94: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153c94u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153c98: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153c98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153c9c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153c9cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153ca0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153CA0u;
    {
        const bool branch_taken_0x153ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153CA0u;
            // 0x153ca4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ca0) {
            ctx->pc = 0x153CB4u;
            goto label_153cb4;
        }
    }
    ctx->pc = 0x153CA8u;
label_153ca8:
    // 0x153ca8: 0x129100  sll         $s2, $s2, 4
    ctx->pc = 0x153ca8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x153cac: 0xae82010c  sw          $v0, 0x10C($s4)
    ctx->pc = 0x153cacu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 268), GPR_U32(ctx, 2));
    // 0x153cb0: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x153cb0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
label_153cb4:
    // 0x153cb4: 0x2a62001c  slti        $v0, $s3, 0x1C
    ctx->pc = 0x153cb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x153cb8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153CB8u;
    {
        const bool branch_taken_0x153cb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153CB8u;
            // 0x153cbc: 0x121702  srl         $v0, $s2, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153cb8) {
            ctx->pc = 0x153D30u;
            goto label_153d30;
        }
    }
    ctx->pc = 0x153CC0u;
    // 0x153cc0: 0x2673ffe4  addiu       $s3, $s3, -0x1C
    ctx->pc = 0x153cc0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967268));
    // 0x153cc4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153CC4u;
    {
        const bool branch_taken_0x153cc4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153CC4u;
            // 0x153cc8: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153cc4) {
            ctx->pc = 0x153CE8u;
            goto label_153ce8;
        }
    }
    ctx->pc = 0x153CCCu;
    // 0x153ccc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153cccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153cd0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153cd4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153cd4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153cd8: 0x121f02  srl         $v1, $s2, 28
    ctx->pc = 0x153cd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153cdc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153cdcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153ce0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153CE0u;
    {
        const bool branch_taken_0x153ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153CE0u;
            // 0x153ce4: 0xae830110  sw          $v1, 0x110($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 272), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ce0) {
            ctx->pc = 0x153CF4u;
            goto label_153cf4;
        }
    }
    ctx->pc = 0x153CE8u;
label_153ce8:
    // 0x153ce8: 0x121702  srl         $v0, $s2, 28
    ctx->pc = 0x153ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 28));
    // 0x153cec: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153cecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153cf0: 0xae820110  sw          $v0, 0x110($s4)
    ctx->pc = 0x153cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 272), GPR_U32(ctx, 2));
label_153cf4:
    // 0x153cf4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153cf4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153cf8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153cf8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153cfc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153cfcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153d00: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153d00u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153d04: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153d04u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153d08: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153d08u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153d0c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153d0cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153d10: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153d10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153d14: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153d14u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153d18: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153d18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153d1c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153d1cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153d20: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153d20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153d24: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153d24u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153d28: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153D28u;
    {
        const bool branch_taken_0x153d28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153D28u;
            // 0x153d2c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153d28) {
            ctx->pc = 0x153D3Cu;
            goto label_153d3c;
        }
    }
    ctx->pc = 0x153D30u;
label_153d30:
    // 0x153d30: 0x129100  sll         $s2, $s2, 4
    ctx->pc = 0x153d30u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x153d34: 0xae820110  sw          $v0, 0x110($s4)
    ctx->pc = 0x153d34u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 272), GPR_U32(ctx, 2));
    // 0x153d38: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x153d38u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
label_153d3c:
    // 0x153d3c: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x153d3cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x153d40: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153D40u;
    {
        const bool branch_taken_0x153d40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153D40u;
            // 0x153d44: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153d40) {
            ctx->pc = 0x153DB8u;
            goto label_153db8;
        }
    }
    ctx->pc = 0x153D48u;
    // 0x153d48: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x153d48u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x153d4c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153D4Cu;
    {
        const bool branch_taken_0x153d4c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153D4Cu;
            // 0x153d50: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153d4c) {
            ctx->pc = 0x153D70u;
            goto label_153d70;
        }
    }
    ctx->pc = 0x153D54u;
    // 0x153d54: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153d54u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153d58: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153d58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153d5c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153d5cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153d60: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x153d60u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x153d64: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153d64u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153d68: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153D68u;
    {
        const bool branch_taken_0x153d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153D68u;
            // 0x153d6c: 0xae830114  sw          $v1, 0x114($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 276), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153d68) {
            ctx->pc = 0x153D7Cu;
            goto label_153d7c;
        }
    }
    ctx->pc = 0x153D70u;
label_153d70:
    // 0x153d70: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x153d70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x153d74: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153d74u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153d78: 0xae820114  sw          $v0, 0x114($s4)
    ctx->pc = 0x153d78u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 276), GPR_U32(ctx, 2));
label_153d7c:
    // 0x153d7c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153d7cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153d80: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153d80u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153d84: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153d84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153d88: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153d88u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153d8c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153d8cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153d90: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153d90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153d94: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153d94u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153d98: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153d98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153d9c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153d9cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153da0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153da0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153da4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153da4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153da8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153da8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153dac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153dacu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153db0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153DB0u;
    {
        const bool branch_taken_0x153db0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153DB0u;
            // 0x153db4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153db0) {
            ctx->pc = 0x153DC4u;
            goto label_153dc4;
        }
    }
    ctx->pc = 0x153DB8u;
label_153db8:
    // 0x153db8: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x153db8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x153dbc: 0xae820114  sw          $v0, 0x114($s4)
    ctx->pc = 0x153dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 276), GPR_U32(ctx, 2));
    // 0x153dc0: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x153dc0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_153dc4:
    // 0x153dc4: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x153dc4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x153dc8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153DC8u;
    {
        const bool branch_taken_0x153dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153DC8u;
            // 0x153dcc: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153dc8) {
            ctx->pc = 0x153E40u;
            goto label_153e40;
        }
    }
    ctx->pc = 0x153DD0u;
    // 0x153dd0: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x153dd0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x153dd4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153DD4u;
    {
        const bool branch_taken_0x153dd4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153DD4u;
            // 0x153dd8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153dd4) {
            ctx->pc = 0x153DF8u;
            goto label_153df8;
        }
    }
    ctx->pc = 0x153DDCu;
    // 0x153ddc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153de0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153de0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153de4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153de4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153de8: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x153de8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x153dec: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153decu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153df0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153DF0u;
    {
        const bool branch_taken_0x153df0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153DF0u;
            // 0x153df4: 0xae830118  sw          $v1, 0x118($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 280), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153df0) {
            ctx->pc = 0x153E04u;
            goto label_153e04;
        }
    }
    ctx->pc = 0x153DF8u;
label_153df8:
    // 0x153df8: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x153df8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x153dfc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153dfcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153e00: 0xae820118  sw          $v0, 0x118($s4)
    ctx->pc = 0x153e00u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 280), GPR_U32(ctx, 2));
label_153e04:
    // 0x153e04: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153e04u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153e08: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153e08u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153e0c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153e0cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153e10: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153e10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153e14: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153e14u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153e18: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153e18u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153e1c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153e1cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153e20: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153e20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153e24: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153e24u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153e28: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153e28u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153e2c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153e2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153e30: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153e30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153e34: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153e34u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153e38: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153E38u;
    {
        const bool branch_taken_0x153e38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153E38u;
            // 0x153e3c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153e38) {
            ctx->pc = 0x153E4Cu;
            goto label_153e4c;
        }
    }
    ctx->pc = 0x153E40u;
label_153e40:
    // 0x153e40: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x153e40u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x153e44: 0xae820118  sw          $v0, 0x118($s4)
    ctx->pc = 0x153e44u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 280), GPR_U32(ctx, 2));
    // 0x153e48: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x153e48u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_153e4c:
    // 0x153e4c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x153e4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153e50: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153E50u;
    {
        const bool branch_taken_0x153e50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153E50u;
            // 0x153e54: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153e50) {
            ctx->pc = 0x153EC8u;
            goto label_153ec8;
        }
    }
    ctx->pc = 0x153E58u;
    // 0x153e58: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153e58u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x153e5c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153E5Cu;
    {
        const bool branch_taken_0x153e5c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153E5Cu;
            // 0x153e60: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153e5c) {
            ctx->pc = 0x153E80u;
            goto label_153e80;
        }
    }
    ctx->pc = 0x153E64u;
    // 0x153e64: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153e64u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153e68: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153e68u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153e6c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153e6cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153e70: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x153e70u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153e74: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153e74u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153e78: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153E78u;
    {
        const bool branch_taken_0x153e78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153E78u;
            // 0x153e7c: 0xae83011c  sw          $v1, 0x11C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 284), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153e78) {
            ctx->pc = 0x153E8Cu;
            goto label_153e8c;
        }
    }
    ctx->pc = 0x153E80u;
label_153e80:
    // 0x153e80: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153e80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153e84: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153e84u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153e88: 0xae82011c  sw          $v0, 0x11C($s4)
    ctx->pc = 0x153e88u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 284), GPR_U32(ctx, 2));
label_153e8c:
    // 0x153e8c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153e8cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153e90: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153e90u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153e94: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153e94u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153e98: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153e98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153e9c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153e9cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153ea0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153ea0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153ea4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153ea4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153ea8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153ea8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153eac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153eacu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153eb0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153eb0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153eb4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153eb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153eb8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153eb8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153ebc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153ebcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153ec0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153EC0u;
    {
        const bool branch_taken_0x153ec0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153EC0u;
            // 0x153ec4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ec0) {
            ctx->pc = 0x153ED4u;
            goto label_153ed4;
        }
    }
    ctx->pc = 0x153EC8u;
label_153ec8:
    // 0x153ec8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x153ec8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x153ecc: 0xae82011c  sw          $v0, 0x11C($s4)
    ctx->pc = 0x153eccu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 284), GPR_U32(ctx, 2));
    // 0x153ed0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x153ed0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_153ed4:
    // 0x153ed4: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x153ed4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153ed8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153ED8u;
    {
        const bool branch_taken_0x153ed8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153ED8u;
            // 0x153edc: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ed8) {
            ctx->pc = 0x153F50u;
            goto label_153f50;
        }
    }
    ctx->pc = 0x153EE0u;
    // 0x153ee0: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153ee0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x153ee4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153EE4u;
    {
        const bool branch_taken_0x153ee4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153EE4u;
            // 0x153ee8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ee4) {
            ctx->pc = 0x153F08u;
            goto label_153f08;
        }
    }
    ctx->pc = 0x153EECu;
    // 0x153eec: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153eecu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153ef0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153ef4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153ef4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153ef8: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x153ef8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153efc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153efcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153f00: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153F00u;
    {
        const bool branch_taken_0x153f00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153F00u;
            // 0x153f04: 0xae830120  sw          $v1, 0x120($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 288), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153f00) {
            ctx->pc = 0x153F14u;
            goto label_153f14;
        }
    }
    ctx->pc = 0x153F08u;
label_153f08:
    // 0x153f08: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153f08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153f0c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153f0cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153f10: 0xae820120  sw          $v0, 0x120($s4)
    ctx->pc = 0x153f10u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 288), GPR_U32(ctx, 2));
label_153f14:
    // 0x153f14: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153f14u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153f18: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153f18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153f1c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153f1cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153f20: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153f20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153f24: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153f24u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153f28: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153f28u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153f2c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153f2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153f30: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153f30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153f34: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153f34u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153f38: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153f38u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153f3c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153f3cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153f40: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153f40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153f44: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153f44u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153f48: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153F48u;
    {
        const bool branch_taken_0x153f48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153F48u;
            // 0x153f4c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153f48) {
            ctx->pc = 0x153F5Cu;
            goto label_153f5c;
        }
    }
    ctx->pc = 0x153F50u;
label_153f50:
    // 0x153f50: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x153f50u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x153f54: 0xae820120  sw          $v0, 0x120($s4)
    ctx->pc = 0x153f54u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 288), GPR_U32(ctx, 2));
    // 0x153f58: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x153f58u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_153f5c:
    // 0x153f5c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x153f5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153f60: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153F60u;
    {
        const bool branch_taken_0x153f60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153F60u;
            // 0x153f64: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153f60) {
            ctx->pc = 0x153FD8u;
            goto label_153fd8;
        }
    }
    ctx->pc = 0x153F68u;
    // 0x153f68: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153f68u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x153f6c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153F6Cu;
    {
        const bool branch_taken_0x153f6c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153F6Cu;
            // 0x153f70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153f6c) {
            ctx->pc = 0x153F90u;
            goto label_153f90;
        }
    }
    ctx->pc = 0x153F74u;
    // 0x153f74: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153f74u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x153f78: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x153f78u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x153f7c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x153f7cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x153f80: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x153f80u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153f84: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x153f84u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x153f88: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153F88u;
    {
        const bool branch_taken_0x153f88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153F88u;
            // 0x153f8c: 0xae830124  sw          $v1, 0x124($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 292), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153f88) {
            ctx->pc = 0x153F9Cu;
            goto label_153f9c;
        }
    }
    ctx->pc = 0x153F90u;
label_153f90:
    // 0x153f90: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x153f90u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x153f94: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x153f94u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x153f98: 0xae820124  sw          $v0, 0x124($s4)
    ctx->pc = 0x153f98u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 292), GPR_U32(ctx, 2));
label_153f9c:
    // 0x153f9c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x153f9cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153fa0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153fa0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153fa4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153fa4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153fa8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153fa8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153fac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153facu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153fb0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x153fb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153fb4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x153fb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x153fb8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153fb8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153fbc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153fbcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153fc0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x153fc0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x153fc4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x153fc4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x153fc8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x153fc8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x153fcc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x153fccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x153fd0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x153FD0u;
    {
        const bool branch_taken_0x153fd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x153FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153FD0u;
            // 0x153fd4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153fd0) {
            ctx->pc = 0x153FE4u;
            goto label_153fe4;
        }
    }
    ctx->pc = 0x153FD8u;
label_153fd8:
    // 0x153fd8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x153fd8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x153fdc: 0xae820124  sw          $v0, 0x124($s4)
    ctx->pc = 0x153fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 292), GPR_U32(ctx, 2));
    // 0x153fe0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x153fe0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_153fe4:
    // 0x153fe4: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x153fe4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x153fe8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x153FE8u;
    {
        const bool branch_taken_0x153fe8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x153FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153FE8u;
            // 0x153fec: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153fe8) {
            ctx->pc = 0x154060u;
            goto label_154060;
        }
    }
    ctx->pc = 0x153FF0u;
    // 0x153ff0: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x153ff0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x153ff4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x153FF4u;
    {
        const bool branch_taken_0x153ff4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x153FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x153FF4u;
            // 0x153ff8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x153ff4) {
            ctx->pc = 0x154018u;
            goto label_154018;
        }
    }
    ctx->pc = 0x153FFCu;
    // 0x153ffc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x153ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154000: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154000u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154004: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154004u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154008: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154008u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15400c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15400cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154010: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154010u;
    {
        const bool branch_taken_0x154010 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154010u;
            // 0x154014: 0xae830128  sw          $v1, 0x128($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 296), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154010) {
            ctx->pc = 0x154024u;
            goto label_154024;
        }
    }
    ctx->pc = 0x154018u;
label_154018:
    // 0x154018: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154018u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15401c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15401cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154020: 0xae820128  sw          $v0, 0x128($s4)
    ctx->pc = 0x154020u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 296), GPR_U32(ctx, 2));
label_154024:
    // 0x154024: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154024u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154028: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154028u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15402c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15402cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154030: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154030u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154034: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154034u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154038: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154038u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15403c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15403cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154040: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154040u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154044: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154044u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154048: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154048u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15404c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15404cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154050: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154050u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154054: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154054u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154058: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154058u;
    {
        const bool branch_taken_0x154058 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15405Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154058u;
            // 0x15405c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154058) {
            ctx->pc = 0x15406Cu;
            goto label_15406c;
        }
    }
    ctx->pc = 0x154060u;
label_154060:
    // 0x154060: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154060u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x154064: 0xae820128  sw          $v0, 0x128($s4)
    ctx->pc = 0x154064u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 296), GPR_U32(ctx, 2));
    // 0x154068: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154068u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15406c:
    // 0x15406c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x15406cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x154070: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154070u;
    {
        const bool branch_taken_0x154070 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154070u;
            // 0x154074: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154070) {
            ctx->pc = 0x1540E8u;
            goto label_1540e8;
        }
    }
    ctx->pc = 0x154078u;
    // 0x154078: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154078u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15407c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15407Cu;
    {
        const bool branch_taken_0x15407c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15407Cu;
            // 0x154080: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15407c) {
            ctx->pc = 0x1540A0u;
            goto label_1540a0;
        }
    }
    ctx->pc = 0x154084u;
    // 0x154084: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154084u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154088: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154088u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15408c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15408cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154090: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154090u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x154094: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154094u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154098: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154098u;
    {
        const bool branch_taken_0x154098 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15409Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154098u;
            // 0x15409c: 0xae83012c  sw          $v1, 0x12C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 300), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154098) {
            ctx->pc = 0x1540ACu;
            goto label_1540ac;
        }
    }
    ctx->pc = 0x1540A0u;
label_1540a0:
    // 0x1540a0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1540a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1540a4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1540a4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1540a8: 0xae82012c  sw          $v0, 0x12C($s4)
    ctx->pc = 0x1540a8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 300), GPR_U32(ctx, 2));
label_1540ac:
    // 0x1540ac: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1540acu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1540b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1540b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1540b4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1540b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1540b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1540b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1540bc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1540bcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1540c0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1540c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1540c4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1540c4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1540c8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1540c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1540cc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1540ccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1540d0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1540d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1540d4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1540d4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1540d8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1540d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1540dc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1540dcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1540e0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1540E0u;
    {
        const bool branch_taken_0x1540e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1540E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1540E0u;
            // 0x1540e4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1540e0) {
            ctx->pc = 0x1540F4u;
            goto label_1540f4;
        }
    }
    ctx->pc = 0x1540E8u;
label_1540e8:
    // 0x1540e8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x1540e8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1540ec: 0xae82012c  sw          $v0, 0x12C($s4)
    ctx->pc = 0x1540ecu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 300), GPR_U32(ctx, 2));
    // 0x1540f0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1540f0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1540f4:
    // 0x1540f4: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1540f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1540f8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1540F8u;
    {
        const bool branch_taken_0x1540f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1540FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1540F8u;
            // 0x1540fc: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1540f8) {
            ctx->pc = 0x154170u;
            goto label_154170;
        }
    }
    ctx->pc = 0x154100u;
    // 0x154100: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154100u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x154104: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154104u;
    {
        const bool branch_taken_0x154104 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154104u;
            // 0x154108: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154104) {
            ctx->pc = 0x154128u;
            goto label_154128;
        }
    }
    ctx->pc = 0x15410Cu;
    // 0x15410c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15410cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154110: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154110u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154114: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154114u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154118: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154118u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15411c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15411cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154120: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154120u;
    {
        const bool branch_taken_0x154120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154120u;
            // 0x154124: 0xae830130  sw          $v1, 0x130($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 304), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154120) {
            ctx->pc = 0x154134u;
            goto label_154134;
        }
    }
    ctx->pc = 0x154128u;
label_154128:
    // 0x154128: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154128u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15412c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15412cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154130: 0xae820130  sw          $v0, 0x130($s4)
    ctx->pc = 0x154130u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 304), GPR_U32(ctx, 2));
label_154134:
    // 0x154134: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154134u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154138: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154138u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15413c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15413cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154140: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154140u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154144: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154144u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154148: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154148u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15414c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15414cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154150: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154150u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154154: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154154u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154158: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154158u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15415c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15415cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154160: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154160u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154164: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154164u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154168: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154168u;
    {
        const bool branch_taken_0x154168 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15416Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154168u;
            // 0x15416c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154168) {
            ctx->pc = 0x15417Cu;
            goto label_15417c;
        }
    }
    ctx->pc = 0x154170u;
label_154170:
    // 0x154170: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154170u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x154174: 0xae820130  sw          $v0, 0x130($s4)
    ctx->pc = 0x154174u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 304), GPR_U32(ctx, 2));
    // 0x154178: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154178u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15417c:
    // 0x15417c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x15417cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x154180: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154180u;
    {
        const bool branch_taken_0x154180 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154180u;
            // 0x154184: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154180) {
            ctx->pc = 0x1541F8u;
            goto label_1541f8;
        }
    }
    ctx->pc = 0x154188u;
    // 0x154188: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154188u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15418c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15418Cu;
    {
        const bool branch_taken_0x15418c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15418Cu;
            // 0x154190: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15418c) {
            ctx->pc = 0x1541B0u;
            goto label_1541b0;
        }
    }
    ctx->pc = 0x154194u;
    // 0x154194: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154194u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154198: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154198u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15419c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15419cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1541a0: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1541a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1541a4: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1541a4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1541a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1541A8u;
    {
        const bool branch_taken_0x1541a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1541ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1541A8u;
            // 0x1541ac: 0xae830134  sw          $v1, 0x134($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 308), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1541a8) {
            ctx->pc = 0x1541BCu;
            goto label_1541bc;
        }
    }
    ctx->pc = 0x1541B0u;
label_1541b0:
    // 0x1541b0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1541b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1541b4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1541b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1541b8: 0xae820134  sw          $v0, 0x134($s4)
    ctx->pc = 0x1541b8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 308), GPR_U32(ctx, 2));
label_1541bc:
    // 0x1541bc: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1541bcu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1541c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1541c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1541c4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1541c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1541c8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1541c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1541cc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1541ccu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1541d0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1541d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1541d4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1541d4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1541d8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1541d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1541dc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1541dcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1541e0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1541e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1541e4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1541e4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1541e8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1541e8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1541ec: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1541ecu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1541f0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1541F0u;
    {
        const bool branch_taken_0x1541f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1541F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1541F0u;
            // 0x1541f4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1541f0) {
            ctx->pc = 0x154204u;
            goto label_154204;
        }
    }
    ctx->pc = 0x1541F8u;
label_1541f8:
    // 0x1541f8: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x1541f8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1541fc: 0xae820134  sw          $v0, 0x134($s4)
    ctx->pc = 0x1541fcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 308), GPR_U32(ctx, 2));
    // 0x154200: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154200u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_154204:
    // 0x154204: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x154204u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x154208: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154208u;
    {
        const bool branch_taken_0x154208 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15420Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154208u;
            // 0x15420c: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154208) {
            ctx->pc = 0x154280u;
            goto label_154280;
        }
    }
    ctx->pc = 0x154210u;
    // 0x154210: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154210u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x154214: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154214u;
    {
        const bool branch_taken_0x154214 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154214u;
            // 0x154218: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154214) {
            ctx->pc = 0x154238u;
            goto label_154238;
        }
    }
    ctx->pc = 0x15421Cu;
    // 0x15421c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15421cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154220: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154220u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154224: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154224u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154228: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154228u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15422c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15422cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154230: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154230u;
    {
        const bool branch_taken_0x154230 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154230u;
            // 0x154234: 0xae830138  sw          $v1, 0x138($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 312), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154230) {
            ctx->pc = 0x154244u;
            goto label_154244;
        }
    }
    ctx->pc = 0x154238u;
label_154238:
    // 0x154238: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154238u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15423c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15423cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154240: 0xae820138  sw          $v0, 0x138($s4)
    ctx->pc = 0x154240u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 312), GPR_U32(ctx, 2));
label_154244:
    // 0x154244: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154244u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154248: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154248u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15424c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15424cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154250: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154250u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154254: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154254u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154258: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154258u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15425c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15425cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154260: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154260u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154264: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154264u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154268: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154268u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15426c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15426cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154270: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154270u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154274: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154274u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154278: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154278u;
    {
        const bool branch_taken_0x154278 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15427Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154278u;
            // 0x15427c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154278) {
            ctx->pc = 0x15428Cu;
            goto label_15428c;
        }
    }
    ctx->pc = 0x154280u;
label_154280:
    // 0x154280: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154280u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x154284: 0xae820138  sw          $v0, 0x138($s4)
    ctx->pc = 0x154284u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 312), GPR_U32(ctx, 2));
    // 0x154288: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154288u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15428c:
    // 0x15428c: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x15428cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x154290: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154290u;
    {
        const bool branch_taken_0x154290 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154290u;
            // 0x154294: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154290) {
            ctx->pc = 0x154308u;
            goto label_154308;
        }
    }
    ctx->pc = 0x154298u;
    // 0x154298: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154298u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x15429c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15429Cu;
    {
        const bool branch_taken_0x15429c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1542A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15429Cu;
            // 0x1542a0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15429c) {
            ctx->pc = 0x1542C0u;
            goto label_1542c0;
        }
    }
    ctx->pc = 0x1542A4u;
    // 0x1542a4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1542a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1542a8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1542a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1542ac: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1542acu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1542b0: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1542b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1542b4: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1542b4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1542b8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1542B8u;
    {
        const bool branch_taken_0x1542b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1542BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1542B8u;
            // 0x1542bc: 0xae83013c  sw          $v1, 0x13C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 316), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1542b8) {
            ctx->pc = 0x1542CCu;
            goto label_1542cc;
        }
    }
    ctx->pc = 0x1542C0u;
label_1542c0:
    // 0x1542c0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1542c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1542c4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1542c4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1542c8: 0xae82013c  sw          $v0, 0x13C($s4)
    ctx->pc = 0x1542c8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 316), GPR_U32(ctx, 2));
label_1542cc:
    // 0x1542cc: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1542ccu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1542d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1542d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1542d4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1542d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1542d8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1542d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1542dc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1542dcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1542e0: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1542e0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1542e4: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1542e4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1542e8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1542e8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1542ec: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1542ecu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1542f0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1542f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1542f4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1542f4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1542f8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1542f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1542fc: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1542fcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154300: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154300u;
    {
        const bool branch_taken_0x154300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154300u;
            // 0x154304: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154300) {
            ctx->pc = 0x154314u;
            goto label_154314;
        }
    }
    ctx->pc = 0x154308u;
label_154308:
    // 0x154308: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154308u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15430c: 0xae82013c  sw          $v0, 0x13C($s4)
    ctx->pc = 0x15430cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 316), GPR_U32(ctx, 2));
    // 0x154310: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154310u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_154314:
    // 0x154314: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x154314u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x154318: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154318u;
    {
        const bool branch_taken_0x154318 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15431Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154318u;
            // 0x15431c: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154318) {
            ctx->pc = 0x154390u;
            goto label_154390;
        }
    }
    ctx->pc = 0x154320u;
    // 0x154320: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154320u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x154324: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154324u;
    {
        const bool branch_taken_0x154324 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154324u;
            // 0x154328: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154324) {
            ctx->pc = 0x154348u;
            goto label_154348;
        }
    }
    ctx->pc = 0x15432Cu;
    // 0x15432c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15432cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154330: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154330u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154334: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154334u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154338: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154338u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15433c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15433cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154340: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154340u;
    {
        const bool branch_taken_0x154340 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154340u;
            // 0x154344: 0xae830140  sw          $v1, 0x140($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 320), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154340) {
            ctx->pc = 0x154354u;
            goto label_154354;
        }
    }
    ctx->pc = 0x154348u;
label_154348:
    // 0x154348: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154348u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15434c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15434cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154350: 0xae820140  sw          $v0, 0x140($s4)
    ctx->pc = 0x154350u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 320), GPR_U32(ctx, 2));
label_154354:
    // 0x154354: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154354u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154358: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154358u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15435c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15435cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154360: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154360u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154364: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154364u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154368: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154368u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15436c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15436cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154370: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154370u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154374: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154374u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154378: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154378u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15437c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15437cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154380: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154380u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154384: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154384u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154388: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154388u;
    {
        const bool branch_taken_0x154388 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15438Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154388u;
            // 0x15438c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154388) {
            ctx->pc = 0x15439Cu;
            goto label_15439c;
        }
    }
    ctx->pc = 0x154390u;
label_154390:
    // 0x154390: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154390u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x154394: 0xae820140  sw          $v0, 0x140($s4)
    ctx->pc = 0x154394u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 320), GPR_U32(ctx, 2));
    // 0x154398: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154398u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15439c:
    // 0x15439c: 0x8e820140  lw          $v0, 0x140($s4)
    ctx->pc = 0x15439cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 320)));
    // 0x1543a0: 0x1040009b  beqz        $v0, . + 4 + (0x9B << 2)
    ctx->pc = 0x1543A0u;
    {
        const bool branch_taken_0x1543a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1543A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1543A0u;
            // 0x1543a4: 0x2a62001f  slti        $v0, $s3, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1543a0) {
            ctx->pc = 0x154610u;
            goto label_154610;
        }
    }
    ctx->pc = 0x1543A8u;
    // 0x1543a8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1543A8u;
    {
        const bool branch_taken_0x1543a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1543ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1543A8u;
            // 0x1543ac: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1543a8) {
            ctx->pc = 0x154420u;
            goto label_154420;
        }
    }
    ctx->pc = 0x1543B0u;
    // 0x1543b0: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1543b0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1543b4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1543B4u;
    {
        const bool branch_taken_0x1543b4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1543B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1543B4u;
            // 0x1543b8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1543b4) {
            ctx->pc = 0x1543D8u;
            goto label_1543d8;
        }
    }
    ctx->pc = 0x1543BCu;
    // 0x1543bc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1543bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1543c0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1543c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1543c4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1543c4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1543c8: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1543c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1543cc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1543ccu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1543d0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1543D0u;
    {
        const bool branch_taken_0x1543d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1543D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1543D0u;
            // 0x1543d4: 0xae830144  sw          $v1, 0x144($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 324), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1543d0) {
            ctx->pc = 0x1543E4u;
            goto label_1543e4;
        }
    }
    ctx->pc = 0x1543D8u;
label_1543d8:
    // 0x1543d8: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1543d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1543dc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1543dcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1543e0: 0xae820144  sw          $v0, 0x144($s4)
    ctx->pc = 0x1543e0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 324), GPR_U32(ctx, 2));
label_1543e4:
    // 0x1543e4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1543e4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1543e8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1543e8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1543ec: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1543ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1543f0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1543f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1543f4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1543f4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1543f8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1543f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1543fc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1543fcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154400: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154400u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154404: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154404u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154408: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154408u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15440c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15440cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154410: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154410u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154414: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154414u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154418: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154418u;
    {
        const bool branch_taken_0x154418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15441Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154418u;
            // 0x15441c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154418) {
            ctx->pc = 0x15442Cu;
            goto label_15442c;
        }
    }
    ctx->pc = 0x154420u;
label_154420:
    // 0x154420: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154420u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x154424: 0xae820144  sw          $v0, 0x144($s4)
    ctx->pc = 0x154424u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 324), GPR_U32(ctx, 2));
    // 0x154428: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154428u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15442c:
    // 0x15442c: 0x2a62001d  slti        $v0, $s3, 0x1D
    ctx->pc = 0x15442cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x154430: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154430u;
    {
        const bool branch_taken_0x154430 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154430u;
            // 0x154434: 0x121742  srl         $v0, $s2, 29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154430) {
            ctx->pc = 0x1544A8u;
            goto label_1544a8;
        }
    }
    ctx->pc = 0x154438u;
    // 0x154438: 0x2673ffe3  addiu       $s3, $s3, -0x1D
    ctx->pc = 0x154438u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967267));
    // 0x15443c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15443Cu;
    {
        const bool branch_taken_0x15443c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15443Cu;
            // 0x154440: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15443c) {
            ctx->pc = 0x154460u;
            goto label_154460;
        }
    }
    ctx->pc = 0x154444u;
    // 0x154444: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154444u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154448: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154448u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15444c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15444cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154450: 0x121f42  srl         $v1, $s2, 29
    ctx->pc = 0x154450u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x154454: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154454u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154458: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154458u;
    {
        const bool branch_taken_0x154458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15445Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154458u;
            // 0x15445c: 0xae830148  sw          $v1, 0x148($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 328), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154458) {
            ctx->pc = 0x15446Cu;
            goto label_15446c;
        }
    }
    ctx->pc = 0x154460u;
label_154460:
    // 0x154460: 0x121742  srl         $v0, $s2, 29
    ctx->pc = 0x154460u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 29));
    // 0x154464: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154464u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154468: 0xae820148  sw          $v0, 0x148($s4)
    ctx->pc = 0x154468u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 328), GPR_U32(ctx, 2));
label_15446c:
    // 0x15446c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15446cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154470: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154470u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154474: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154474u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154478: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154478u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15447c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15447cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154480: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154480u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154484: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154484u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154488: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154488u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15448c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15448cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154490: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154490u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154494: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154494u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154498: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154498u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15449c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15449cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1544a0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1544A0u;
    {
        const bool branch_taken_0x1544a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1544A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1544A0u;
            // 0x1544a4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1544a0) {
            ctx->pc = 0x1544B4u;
            goto label_1544b4;
        }
    }
    ctx->pc = 0x1544A8u;
label_1544a8:
    // 0x1544a8: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x1544a8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x1544ac: 0xae820148  sw          $v0, 0x148($s4)
    ctx->pc = 0x1544acu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 328), GPR_U32(ctx, 2));
    // 0x1544b0: 0x26730003  addiu       $s3, $s3, 0x3
    ctx->pc = 0x1544b0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
label_1544b4:
    // 0x1544b4: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1544b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1544b8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1544B8u;
    {
        const bool branch_taken_0x1544b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1544BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1544B8u;
            // 0x1544bc: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1544b8) {
            ctx->pc = 0x154530u;
            goto label_154530;
        }
    }
    ctx->pc = 0x1544C0u;
    // 0x1544c0: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1544c0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1544c4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1544C4u;
    {
        const bool branch_taken_0x1544c4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1544C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1544C4u;
            // 0x1544c8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1544c4) {
            ctx->pc = 0x1544E8u;
            goto label_1544e8;
        }
    }
    ctx->pc = 0x1544CCu;
    // 0x1544cc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1544ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1544d0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1544d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1544d4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1544d4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1544d8: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1544d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1544dc: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1544dcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1544e0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1544E0u;
    {
        const bool branch_taken_0x1544e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1544E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1544E0u;
            // 0x1544e4: 0xae83014c  sw          $v1, 0x14C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 332), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1544e0) {
            ctx->pc = 0x1544F4u;
            goto label_1544f4;
        }
    }
    ctx->pc = 0x1544E8u;
label_1544e8:
    // 0x1544e8: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1544e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1544ec: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1544ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1544f0: 0xae82014c  sw          $v0, 0x14C($s4)
    ctx->pc = 0x1544f0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 332), GPR_U32(ctx, 2));
label_1544f4:
    // 0x1544f4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1544f4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1544f8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1544f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1544fc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1544fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154500: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154500u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154504: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154504u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154508: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154508u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15450c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15450cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154510: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154510u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154514: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154514u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154518: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154518u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15451c: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x15451cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154520: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154520u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154524: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154524u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154528: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154528u;
    {
        const bool branch_taken_0x154528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15452Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154528u;
            // 0x15452c: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154528) {
            ctx->pc = 0x15453Cu;
            goto label_15453c;
        }
    }
    ctx->pc = 0x154530u;
label_154530:
    // 0x154530: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154530u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x154534: 0xae82014c  sw          $v0, 0x14C($s4)
    ctx->pc = 0x154534u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 332), GPR_U32(ctx, 2));
    // 0x154538: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154538u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_15453c:
    // 0x15453c: 0x2a620019  slti        $v0, $s3, 0x19
    ctx->pc = 0x15453cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)25) ? 1 : 0);
    // 0x154540: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154540u;
    {
        const bool branch_taken_0x154540 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154540u;
            // 0x154544: 0x121642  srl         $v0, $s2, 25 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 25));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154540) {
            ctx->pc = 0x1545B8u;
            goto label_1545b8;
        }
    }
    ctx->pc = 0x154548u;
    // 0x154548: 0x2673ffe7  addiu       $s3, $s3, -0x19
    ctx->pc = 0x154548u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967271));
    // 0x15454c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15454Cu;
    {
        const bool branch_taken_0x15454c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15454Cu;
            // 0x154550: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15454c) {
            ctx->pc = 0x154570u;
            goto label_154570;
        }
    }
    ctx->pc = 0x154554u;
    // 0x154554: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154554u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154558: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154558u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15455c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15455cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154560: 0x121e42  srl         $v1, $s2, 25
    ctx->pc = 0x154560u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 25));
    // 0x154564: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154564u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154568: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154568u;
    {
        const bool branch_taken_0x154568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15456Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154568u;
            // 0x15456c: 0xae830150  sw          $v1, 0x150($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 336), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154568) {
            ctx->pc = 0x15457Cu;
            goto label_15457c;
        }
    }
    ctx->pc = 0x154570u;
label_154570:
    // 0x154570: 0x121642  srl         $v0, $s2, 25
    ctx->pc = 0x154570u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 25));
    // 0x154574: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154574u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154578: 0xae820150  sw          $v0, 0x150($s4)
    ctx->pc = 0x154578u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 336), GPR_U32(ctx, 2));
label_15457c:
    // 0x15457c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15457cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154580: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154580u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154584: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154584u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154588: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154588u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15458c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15458cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154590: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154590u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154594: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154594u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154598: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154598u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15459c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15459cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1545a0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1545a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1545a4: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1545a4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1545a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1545a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1545ac: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1545acu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1545b0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1545B0u;
    {
        const bool branch_taken_0x1545b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1545B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1545B0u;
            // 0x1545b4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1545b0) {
            ctx->pc = 0x1545C4u;
            goto label_1545c4;
        }
    }
    ctx->pc = 0x1545B8u;
label_1545b8:
    // 0x1545b8: 0x1291c0  sll         $s2, $s2, 7
    ctx->pc = 0x1545b8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 7));
    // 0x1545bc: 0xae820150  sw          $v0, 0x150($s4)
    ctx->pc = 0x1545bcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 336), GPR_U32(ctx, 2));
    // 0x1545c0: 0x26730007  addiu       $s3, $s3, 0x7
    ctx->pc = 0x1545c0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 7));
label_1545c4:
    // 0x1545c4: 0x2a620018  slti        $v0, $s3, 0x18
    ctx->pc = 0x1545c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x1545c8: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1545C8u;
    {
        const bool branch_taken_0x1545c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1545CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1545C8u;
            // 0x1545cc: 0x121602  srl         $v0, $s2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1545c8) {
            ctx->pc = 0x154608u;
            goto label_154608;
        }
    }
    ctx->pc = 0x1545D0u;
    // 0x1545d0: 0x2673ffe8  addiu       $s3, $s3, -0x18
    ctx->pc = 0x1545d0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967272));
    // 0x1545d4: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1545D4u;
    {
        const bool branch_taken_0x1545d4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1545D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1545D4u;
            // 0x1545d8: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1545d4) {
            ctx->pc = 0x1545F8u;
            goto label_1545f8;
        }
    }
    ctx->pc = 0x1545DCu;
    // 0x1545dc: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1545dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1545e0: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1545e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1545e4: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1545e4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1545e8: 0x121e02  srl         $v1, $s2, 24
    ctx->pc = 0x1545e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x1545ec: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1545ECu;
    {
        const bool branch_taken_0x1545ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1545F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1545ECu;
            // 0x1545f0: 0xae830154  sw          $v1, 0x154($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 340), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1545ec) {
            ctx->pc = 0x154600u;
            goto label_154600;
        }
    }
    ctx->pc = 0x1545F4u;
    // 0x1545f4: 0x0  nop
    ctx->pc = 0x1545f4u;
    // NOP
label_1545f8:
    // 0x1545f8: 0x121602  srl         $v0, $s2, 24
    ctx->pc = 0x1545f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 24));
    // 0x1545fc: 0xae820154  sw          $v0, 0x154($s4)
    ctx->pc = 0x1545fcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 340), GPR_U32(ctx, 2));
label_154600:
    // 0x154600: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x154600u;
    {
        const bool branch_taken_0x154600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154600u;
            // 0x154604: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154600) {
            ctx->pc = 0x154610u;
            goto label_154610;
        }
    }
    ctx->pc = 0x154608u;
label_154608:
    // 0x154608: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x154608u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x15460c: 0xae820154  sw          $v0, 0x154($s4)
    ctx->pc = 0x15460cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 340), GPR_U32(ctx, 2));
label_154610:
    // 0x154610: 0xc054382  jal         func_150E08
    ctx->pc = 0x154610u;
    SET_GPR_U32(ctx, 31, 0x154618u);
    ctx->pc = 0x154614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x154610u;
            // 0x154614: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150E08u;
    if (runtime->hasFunction(0x150E08u)) {
        auto targetFn = runtime->lookupFunction(0x150E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x154618u; }
        if (ctx->pc != 0x154618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150E08_0x150e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x154618u; }
        if (ctx->pc != 0x154618u) { return; }
    }
    ctx->pc = 0x154618u;
label_154618:
    // 0x154618: 0xc054430  jal         func_1510C0
    ctx->pc = 0x154618u;
    SET_GPR_U32(ctx, 31, 0x154620u);
    ctx->pc = 0x15461Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x154618u;
            // 0x15461c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1510C0u;
    if (runtime->hasFunction(0x1510C0u)) {
        auto targetFn = runtime->lookupFunction(0x1510C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x154620u; }
        if (ctx->pc != 0x154620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001510C0_0x1510c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x154620u; }
        if (ctx->pc != 0x154620u) { return; }
    }
    ctx->pc = 0x154620u;
label_154620:
    // 0x154620: 0x10000182  b           . + 4 + (0x182 << 2)
    ctx->pc = 0x154620u;
    {
        const bool branch_taken_0x154620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154620u;
            // 0x154624: 0x2351823  subu        $v1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154620) {
            ctx->pc = 0x154C2Cu;
            goto label_154c2c;
        }
    }
    ctx->pc = 0x154628u;
label_154628:
    // 0x154628: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x154628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15462c: 0x2a630016  slti        $v1, $s3, 0x16
    ctx->pc = 0x15462cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)22) ? 1 : 0);
    // 0x154630: 0x1460001d  bnez        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x154630u;
    {
        const bool branch_taken_0x154630 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x154634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154630u;
            // 0x154634: 0xae820334  sw          $v0, 0x334($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 820), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154630) {
            ctx->pc = 0x1546A8u;
            goto label_1546a8;
        }
    }
    ctx->pc = 0x154638u;
    // 0x154638: 0x2673ffea  addiu       $s3, $s3, -0x16
    ctx->pc = 0x154638u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967274));
    // 0x15463c: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15463Cu;
    {
        const bool branch_taken_0x15463c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15463Cu;
            // 0x154640: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15463c) {
            ctx->pc = 0x154660u;
            goto label_154660;
        }
    }
    ctx->pc = 0x154644u;
    // 0x154644: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154644u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154648: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154648u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x15464c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x15464cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154650: 0x121d82  srl         $v1, $s2, 22
    ctx->pc = 0x154650u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
    // 0x154654: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154654u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154658: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154658u;
    {
        const bool branch_taken_0x154658 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15465Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154658u;
            // 0x15465c: 0xae830184  sw          $v1, 0x184($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 388), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154658) {
            ctx->pc = 0x15466Cu;
            goto label_15466c;
        }
    }
    ctx->pc = 0x154660u;
label_154660:
    // 0x154660: 0x121582  srl         $v0, $s2, 22
    ctx->pc = 0x154660u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
    // 0x154664: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154664u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154668: 0xae820184  sw          $v0, 0x184($s4)
    ctx->pc = 0x154668u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 388), GPR_U32(ctx, 2));
label_15466c:
    // 0x15466c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15466cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154670: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154670u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154674: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154674u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154678: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154678u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15467c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15467cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154680: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154680u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154684: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154684u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154688: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154688u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15468c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15468cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154690: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154690u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154694: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154694u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154698: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154698u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15469c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15469cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1546a0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1546A0u;
    {
        const bool branch_taken_0x1546a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1546A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1546A0u;
            // 0x1546a4: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1546a0) {
            ctx->pc = 0x1546B8u;
            goto label_1546b8;
        }
    }
    ctx->pc = 0x1546A8u;
label_1546a8:
    // 0x1546a8: 0x121582  srl         $v0, $s2, 22
    ctx->pc = 0x1546a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
    // 0x1546ac: 0x129280  sll         $s2, $s2, 10
    ctx->pc = 0x1546acu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 10));
    // 0x1546b0: 0xae820184  sw          $v0, 0x184($s4)
    ctx->pc = 0x1546b0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 388), GPR_U32(ctx, 2));
    // 0x1546b4: 0x2673000a  addiu       $s3, $s3, 0xA
    ctx->pc = 0x1546b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 10));
label_1546b8:
    // 0x1546b8: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1546b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1546bc: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1546BCu;
    {
        const bool branch_taken_0x1546bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1546C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1546BCu;
            // 0x1546c0: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1546bc) {
            ctx->pc = 0x154738u;
            goto label_154738;
        }
    }
    ctx->pc = 0x1546C4u;
    // 0x1546c4: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1546c4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1546c8: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x1546C8u;
    {
        const bool branch_taken_0x1546c8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1546CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1546C8u;
            // 0x1546cc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1546c8) {
            ctx->pc = 0x1546F0u;
            goto label_1546f0;
        }
    }
    ctx->pc = 0x1546D0u;
    // 0x1546d0: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1546d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1546d4: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1546d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1546d8: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1546d8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1546dc: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1546dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1546e0: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1546e0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1546e4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1546E4u;
    {
        const bool branch_taken_0x1546e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1546E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1546E4u;
            // 0x1546e8: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1546e4) {
            ctx->pc = 0x1546FCu;
            goto label_1546fc;
        }
    }
    ctx->pc = 0x1546ECu;
    // 0x1546ec: 0x0  nop
    ctx->pc = 0x1546ecu;
    // NOP
label_1546f0:
    // 0x1546f0: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x1546f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1546f4: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1546f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1546f8: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x1546f8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_1546fc:
    // 0x1546fc: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1546fcu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154700: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154700u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154704: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154704u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154708: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154708u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15470c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15470cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154710: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154710u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154714: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154714u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154718: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154718u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15471c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15471cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154720: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154720u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154724: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154724u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154728: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154728u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15472c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15472cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154730: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154730u;
    {
        const bool branch_taken_0x154730 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154730u;
            // 0x154734: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154730) {
            ctx->pc = 0x154744u;
            goto label_154744;
        }
    }
    ctx->pc = 0x154738u;
label_154738:
    // 0x154738: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154738u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15473c: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x15473cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x154740: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154740u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_154744:
    // 0x154744: 0x2a620011  slti        $v0, $s3, 0x11
    ctx->pc = 0x154744u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x154748: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154748u;
    {
        const bool branch_taken_0x154748 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15474Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154748u;
            // 0x15474c: 0x121442  srl         $v0, $s2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154748) {
            ctx->pc = 0x1547C0u;
            goto label_1547c0;
        }
    }
    ctx->pc = 0x154750u;
    // 0x154750: 0x2673ffef  addiu       $s3, $s3, -0x11
    ctx->pc = 0x154750u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967279));
    // 0x154754: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154754u;
    {
        const bool branch_taken_0x154754 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154754u;
            // 0x154758: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154754) {
            ctx->pc = 0x154778u;
            goto label_154778;
        }
    }
    ctx->pc = 0x15475Cu;
    // 0x15475c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15475cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154760: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154760u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154764: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154764u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154768: 0x121c42  srl         $v1, $s2, 17
    ctx->pc = 0x154768u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
    // 0x15476c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15476cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154770: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154770u;
    {
        const bool branch_taken_0x154770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154770u;
            // 0x154774: 0xae830188  sw          $v1, 0x188($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 392), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154770) {
            ctx->pc = 0x154784u;
            goto label_154784;
        }
    }
    ctx->pc = 0x154778u;
label_154778:
    // 0x154778: 0x121442  srl         $v0, $s2, 17
    ctx->pc = 0x154778u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
    // 0x15477c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15477cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154780: 0xae820188  sw          $v0, 0x188($s4)
    ctx->pc = 0x154780u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 392), GPR_U32(ctx, 2));
label_154784:
    // 0x154784: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154784u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154788: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154788u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15478c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15478cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154790: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154790u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154794: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154794u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154798: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154798u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15479c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x15479cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1547a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1547a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1547a4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1547a4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1547a8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1547a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1547ac: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1547acu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1547b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1547b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1547b4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1547b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1547b8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1547B8u;
    {
        const bool branch_taken_0x1547b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1547BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1547B8u;
            // 0x1547bc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1547b8) {
            ctx->pc = 0x1547CCu;
            goto label_1547cc;
        }
    }
    ctx->pc = 0x1547C0u;
label_1547c0:
    // 0x1547c0: 0x1293c0  sll         $s2, $s2, 15
    ctx->pc = 0x1547c0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 15));
    // 0x1547c4: 0xae820188  sw          $v0, 0x188($s4)
    ctx->pc = 0x1547c4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 392), GPR_U32(ctx, 2));
    // 0x1547c8: 0x2673000f  addiu       $s3, $s3, 0xF
    ctx->pc = 0x1547c8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 15));
label_1547cc:
    // 0x1547cc: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1547ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1547d0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1547D0u;
    {
        const bool branch_taken_0x1547d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1547D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1547D0u;
            // 0x1547d4: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1547d0) {
            ctx->pc = 0x154848u;
            goto label_154848;
        }
    }
    ctx->pc = 0x1547D8u;
    // 0x1547d8: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1547d8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1547dc: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1547DCu;
    {
        const bool branch_taken_0x1547dc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1547E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1547DCu;
            // 0x1547e0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1547dc) {
            ctx->pc = 0x154800u;
            goto label_154800;
        }
    }
    ctx->pc = 0x1547E4u;
    // 0x1547e4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1547e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1547e8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1547e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1547ec: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1547ecu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x1547f0: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x1547f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x1547f4: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x1547f4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x1547f8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1547F8u;
    {
        const bool branch_taken_0x1547f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1547FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1547F8u;
            // 0x1547fc: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1547f8) {
            ctx->pc = 0x15480Cu;
            goto label_15480c;
        }
    }
    ctx->pc = 0x154800u;
label_154800:
    // 0x154800: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154800u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x154804: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154804u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154808: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x154808u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_15480c:
    // 0x15480c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15480cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154810: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154810u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154814: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154814u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154818: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154818u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15481c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15481cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154820: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154820u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154824: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154824u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154828: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154828u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15482c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15482cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154830: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154830u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154834: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154834u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154838: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154838u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15483c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15483cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154840: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154840u;
    {
        const bool branch_taken_0x154840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154840u;
            // 0x154844: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154840) {
            ctx->pc = 0x154854u;
            goto label_154854;
        }
    }
    ctx->pc = 0x154848u;
label_154848:
    // 0x154848: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154848u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x15484c: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x15484cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x154850: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154850u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_154854:
    // 0x154854: 0x2a620011  slti        $v0, $s3, 0x11
    ctx->pc = 0x154854u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x154858: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154858u;
    {
        const bool branch_taken_0x154858 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15485Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154858u;
            // 0x15485c: 0x121442  srl         $v0, $s2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154858) {
            ctx->pc = 0x1548D0u;
            goto label_1548d0;
        }
    }
    ctx->pc = 0x154860u;
    // 0x154860: 0x2673ffef  addiu       $s3, $s3, -0x11
    ctx->pc = 0x154860u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967279));
    // 0x154864: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154864u;
    {
        const bool branch_taken_0x154864 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154864u;
            // 0x154868: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154864) {
            ctx->pc = 0x154888u;
            goto label_154888;
        }
    }
    ctx->pc = 0x15486Cu;
    // 0x15486c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15486cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154870: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154870u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154874: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154874u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154878: 0x121c42  srl         $v1, $s2, 17
    ctx->pc = 0x154878u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
    // 0x15487c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15487cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154880: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154880u;
    {
        const bool branch_taken_0x154880 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154880u;
            // 0x154884: 0xae83018c  sw          $v1, 0x18C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 396), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154880) {
            ctx->pc = 0x154894u;
            goto label_154894;
        }
    }
    ctx->pc = 0x154888u;
label_154888:
    // 0x154888: 0x121442  srl         $v0, $s2, 17
    ctx->pc = 0x154888u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
    // 0x15488c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15488cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154890: 0xae82018c  sw          $v0, 0x18C($s4)
    ctx->pc = 0x154890u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 396), GPR_U32(ctx, 2));
label_154894:
    // 0x154894: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154894u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154898: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154898u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15489c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x15489cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1548a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1548a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1548a4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1548a4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1548a8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1548a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1548ac: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1548acu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1548b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1548b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1548b4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1548b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1548b8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1548b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1548bc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1548bcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1548c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1548c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1548c4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1548c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1548c8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1548C8u;
    {
        const bool branch_taken_0x1548c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1548CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1548C8u;
            // 0x1548cc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1548c8) {
            ctx->pc = 0x1548DCu;
            goto label_1548dc;
        }
    }
    ctx->pc = 0x1548D0u;
label_1548d0:
    // 0x1548d0: 0x1293c0  sll         $s2, $s2, 15
    ctx->pc = 0x1548d0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 15));
    // 0x1548d4: 0xae82018c  sw          $v0, 0x18C($s4)
    ctx->pc = 0x1548d4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 396), GPR_U32(ctx, 2));
    // 0x1548d8: 0x2673000f  addiu       $s3, $s3, 0xF
    ctx->pc = 0x1548d8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 15));
label_1548dc:
    // 0x1548dc: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x1548dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x1548e0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1548E0u;
    {
        const bool branch_taken_0x1548e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1548E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1548E0u;
            // 0x1548e4: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1548e0) {
            ctx->pc = 0x154958u;
            goto label_154958;
        }
    }
    ctx->pc = 0x1548E8u;
    // 0x1548e8: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x1548e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x1548ec: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1548ECu;
    {
        const bool branch_taken_0x1548ec = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1548F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1548ECu;
            // 0x1548f0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1548ec) {
            ctx->pc = 0x154910u;
            goto label_154910;
        }
    }
    ctx->pc = 0x1548F4u;
    // 0x1548f4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x1548f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1548f8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x1548f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x1548fc: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x1548fcu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154900: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x154900u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x154904: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154904u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154908: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154908u;
    {
        const bool branch_taken_0x154908 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15490Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154908u;
            // 0x15490c: 0xae830190  sw          $v1, 0x190($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 400), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154908) {
            ctx->pc = 0x15491Cu;
            goto label_15491c;
        }
    }
    ctx->pc = 0x154910u;
label_154910:
    // 0x154910: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x154910u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x154914: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154914u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154918: 0xae820190  sw          $v0, 0x190($s4)
    ctx->pc = 0x154918u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 400), GPR_U32(ctx, 2));
label_15491c:
    // 0x15491c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x15491cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154920: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154920u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154924: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154924u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154928: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154928u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15492c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15492cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154930: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154930u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154934: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154934u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154938: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154938u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15493c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15493cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154940: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154940u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154944: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154944u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154948: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154948u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x15494c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x15494cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154950: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154950u;
    {
        const bool branch_taken_0x154950 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154950u;
            // 0x154954: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154950) {
            ctx->pc = 0x154964u;
            goto label_154964;
        }
    }
    ctx->pc = 0x154958u;
label_154958:
    // 0x154958: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x154958u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x15495c: 0xae820190  sw          $v0, 0x190($s4)
    ctx->pc = 0x15495cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 400), GPR_U32(ctx, 2));
    // 0x154960: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x154960u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_154964:
    // 0x154964: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x154964u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x154968: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154968u;
    {
        const bool branch_taken_0x154968 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15496Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154968u;
            // 0x15496c: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154968) {
            ctx->pc = 0x1549E0u;
            goto label_1549e0;
        }
    }
    ctx->pc = 0x154970u;
    // 0x154970: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154970u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x154974: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154974u;
    {
        const bool branch_taken_0x154974 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154974u;
            // 0x154978: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154974) {
            ctx->pc = 0x154998u;
            goto label_154998;
        }
    }
    ctx->pc = 0x15497Cu;
    // 0x15497c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x15497cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154980: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154980u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154984: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154984u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154988: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154988u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15498c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x15498cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154990: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154990u;
    {
        const bool branch_taken_0x154990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154990u;
            // 0x154994: 0xae830194  sw          $v1, 0x194($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 404), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154990) {
            ctx->pc = 0x1549A4u;
            goto label_1549a4;
        }
    }
    ctx->pc = 0x154998u;
label_154998:
    // 0x154998: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154998u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x15499c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x15499cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1549a0: 0xae820194  sw          $v0, 0x194($s4)
    ctx->pc = 0x1549a0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 404), GPR_U32(ctx, 2));
label_1549a4:
    // 0x1549a4: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x1549a4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1549a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1549a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1549ac: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1549acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1549b0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1549b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1549b4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1549b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1549b8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1549b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1549bc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1549bcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1549c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1549c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1549c4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1549c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1549c8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1549c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1549cc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x1549ccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1549d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1549d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1549d4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x1549d4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x1549d8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1549D8u;
    {
        const bool branch_taken_0x1549d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1549DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1549D8u;
            // 0x1549dc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1549d8) {
            ctx->pc = 0x1549ECu;
            goto label_1549ec;
        }
    }
    ctx->pc = 0x1549E0u;
label_1549e0:
    // 0x1549e0: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x1549e0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1549e4: 0xae820194  sw          $v0, 0x194($s4)
    ctx->pc = 0x1549e4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 404), GPR_U32(ctx, 2));
    // 0x1549e8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1549e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1549ec:
    // 0x1549ec: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x1549ecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1549f0: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1549F0u;
    {
        const bool branch_taken_0x1549f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1549F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1549F0u;
            // 0x1549f4: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1549f0) {
            ctx->pc = 0x154A30u;
            goto label_154a30;
        }
    }
    ctx->pc = 0x1549F8u;
    // 0x1549f8: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x1549f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x1549fc: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1549FCu;
    {
        const bool branch_taken_0x1549fc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1549FCu;
            // 0x154a00: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1549fc) {
            ctx->pc = 0x154A20u;
            goto label_154a20;
        }
    }
    ctx->pc = 0x154A04u;
    // 0x154a04: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154a04u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154a08: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154a08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154a0c: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154a0cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154a10: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154a10u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x154a14: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x154A14u;
    {
        const bool branch_taken_0x154a14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154A14u;
            // 0x154a18: 0xae830198  sw          $v1, 0x198($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 408), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154a14) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x154A1Cu;
    // 0x154a1c: 0x0  nop
    ctx->pc = 0x154a1cu;
    // NOP
label_154a20:
    // 0x154a20: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154a20u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x154a24: 0x1000007c  b           . + 4 + (0x7C << 2)
    ctx->pc = 0x154A24u;
    {
        const bool branch_taken_0x154a24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154A24u;
            // 0x154a28: 0xae820198  sw          $v0, 0x198($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 408), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154a24) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x154A2Cu;
    // 0x154a2c: 0x0  nop
    ctx->pc = 0x154a2cu;
    // NOP
label_154a30:
    // 0x154a30: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154a30u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x154a34: 0x1000007c  b           . + 4 + (0x7C << 2)
    ctx->pc = 0x154A34u;
    {
        const bool branch_taken_0x154a34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154A34u;
            // 0x154a38: 0xae820198  sw          $v0, 0x198($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 408), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154a34) {
            ctx->pc = 0x154C28u;
            goto label_154c28;
        }
    }
    ctx->pc = 0x154A3Cu;
    // 0x154a3c: 0x0  nop
    ctx->pc = 0x154a3cu;
    // NOP
label_154a40:
    // 0x154a40: 0x2a62001e  slti        $v0, $s3, 0x1E
    ctx->pc = 0x154a40u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)30) ? 1 : 0);
    // 0x154a44: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x154A44u;
    {
        const bool branch_taken_0x154a44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154A44u;
            // 0x154a48: 0x121782  srl         $v0, $s2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154a44) {
            ctx->pc = 0x154AC0u;
            goto label_154ac0;
        }
    }
    ctx->pc = 0x154A4Cu;
    // 0x154a4c: 0x2673ffe2  addiu       $s3, $s3, -0x1E
    ctx->pc = 0x154a4cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967266));
    // 0x154a50: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x154A50u;
    {
        const bool branch_taken_0x154a50 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154A50u;
            // 0x154a54: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154a50) {
            ctx->pc = 0x154A78u;
            goto label_154a78;
        }
    }
    ctx->pc = 0x154A58u;
    // 0x154a58: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154a58u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154a5c: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154a60: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154a60u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154a64: 0x121f82  srl         $v1, $s2, 30
    ctx->pc = 0x154a64u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x154a68: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154a68u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154a6c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x154A6Cu;
    {
        const bool branch_taken_0x154a6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154A6Cu;
            // 0x154a70: 0xae830178  sw          $v1, 0x178($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 376), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154a6c) {
            ctx->pc = 0x154A84u;
            goto label_154a84;
        }
    }
    ctx->pc = 0x154A74u;
    // 0x154a74: 0x0  nop
    ctx->pc = 0x154a74u;
    // NOP
label_154a78:
    // 0x154a78: 0x121782  srl         $v0, $s2, 30
    ctx->pc = 0x154a78u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 30));
    // 0x154a7c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154a7cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154a80: 0xae820178  sw          $v0, 0x178($s4)
    ctx->pc = 0x154a80u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 376), GPR_U32(ctx, 2));
label_154a84:
    // 0x154a84: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154a84u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154a88: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154a88u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154a8c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154a8cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154a90: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154a90u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154a94: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154a94u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154a98: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154a98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154a9c: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154a9cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154aa0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154aa0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154aa4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154aa4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154aa8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154aa8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154aac: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154aacu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154ab0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154ab0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154ab4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154ab4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154ab8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154AB8u;
    {
        const bool branch_taken_0x154ab8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154AB8u;
            // 0x154abc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154ab8) {
            ctx->pc = 0x154ACCu;
            goto label_154acc;
        }
    }
    ctx->pc = 0x154AC0u;
label_154ac0:
    // 0x154ac0: 0x129080  sll         $s2, $s2, 2
    ctx->pc = 0x154ac0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x154ac4: 0xae820178  sw          $v0, 0x178($s4)
    ctx->pc = 0x154ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 376), GPR_U32(ctx, 2));
    // 0x154ac8: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x154ac8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_154acc:
    // 0x154acc: 0x2a620016  slti        $v0, $s3, 0x16
    ctx->pc = 0x154accu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)22) ? 1 : 0);
    // 0x154ad0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154AD0u;
    {
        const bool branch_taken_0x154ad0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154AD0u;
            // 0x154ad4: 0x121582  srl         $v0, $s2, 22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154ad0) {
            ctx->pc = 0x154B48u;
            goto label_154b48;
        }
    }
    ctx->pc = 0x154AD8u;
    // 0x154ad8: 0x2673ffea  addiu       $s3, $s3, -0x16
    ctx->pc = 0x154ad8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967274));
    // 0x154adc: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154ADCu;
    {
        const bool branch_taken_0x154adc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154ADCu;
            // 0x154ae0: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154adc) {
            ctx->pc = 0x154B00u;
            goto label_154b00;
        }
    }
    ctx->pc = 0x154AE4u;
    // 0x154ae4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154ae8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154aec: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154aecu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154af0: 0x121d82  srl         $v1, $s2, 22
    ctx->pc = 0x154af0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
    // 0x154af4: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154af4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154af8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154AF8u;
    {
        const bool branch_taken_0x154af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154AF8u;
            // 0x154afc: 0xae83017c  sw          $v1, 0x17C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 380), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154af8) {
            ctx->pc = 0x154B0Cu;
            goto label_154b0c;
        }
    }
    ctx->pc = 0x154B00u;
label_154b00:
    // 0x154b00: 0x121582  srl         $v0, $s2, 22
    ctx->pc = 0x154b00u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
    // 0x154b04: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154b04u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154b08: 0xae82017c  sw          $v0, 0x17C($s4)
    ctx->pc = 0x154b08u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 380), GPR_U32(ctx, 2));
label_154b0c:
    // 0x154b0c: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154b0cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154b10: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154b10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154b14: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154b14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154b18: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154b18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154b1c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154b1cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154b20: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154b20u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154b24: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154b24u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154b28: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154b28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154b2c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154b2cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154b30: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154b30u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154b34: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154b34u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154b38: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154b38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154b3c: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154b3cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154b40: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154B40u;
    {
        const bool branch_taken_0x154b40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154B40u;
            // 0x154b44: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154b40) {
            ctx->pc = 0x154B54u;
            goto label_154b54;
        }
    }
    ctx->pc = 0x154B48u;
label_154b48:
    // 0x154b48: 0x129280  sll         $s2, $s2, 10
    ctx->pc = 0x154b48u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 10));
    // 0x154b4c: 0xae82017c  sw          $v0, 0x17C($s4)
    ctx->pc = 0x154b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 380), GPR_U32(ctx, 2));
    // 0x154b50: 0x2673000a  addiu       $s3, $s3, 0xA
    ctx->pc = 0x154b50u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 10));
label_154b54:
    // 0x154b54: 0x2a62001f  slti        $v0, $s3, 0x1F
    ctx->pc = 0x154b54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x154b58: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x154B58u;
    {
        const bool branch_taken_0x154b58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154B58u;
            // 0x154b5c: 0x1217c2  srl         $v0, $s2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154b58) {
            ctx->pc = 0x154BD0u;
            goto label_154bd0;
        }
    }
    ctx->pc = 0x154B60u;
    // 0x154b60: 0x2673ffe1  addiu       $s3, $s3, -0x1F
    ctx->pc = 0x154b60u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967265));
    // 0x154b64: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154B64u;
    {
        const bool branch_taken_0x154b64 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154B64u;
            // 0x154b68: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154b64) {
            ctx->pc = 0x154B88u;
            goto label_154b88;
        }
    }
    ctx->pc = 0x154B6Cu;
    // 0x154b6c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154b70: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154b70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154b74: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154b74u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154b78: 0x121fc2  srl         $v1, $s2, 31
    ctx->pc = 0x154b78u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x154b7c: 0x2709004  sllv        $s2, $s0, $s3
    ctx->pc = 0x154b7cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 19) & 0x1F));
    // 0x154b80: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154B80u;
    {
        const bool branch_taken_0x154b80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154B80u;
            // 0x154b84: 0xae830018  sw          $v1, 0x18($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154b80) {
            ctx->pc = 0x154B94u;
            goto label_154b94;
        }
    }
    ctx->pc = 0x154B88u;
label_154b88:
    // 0x154b88: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x154b88u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x154b8c: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x154b8cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x154b90: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x154b90u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
label_154b94:
    // 0x154b94: 0x82300000  lb          $s0, 0x0($s1)
    ctx->pc = 0x154b94u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154b98: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154b98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154b9c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154b9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154ba0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154ba0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154ba4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154ba4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154ba8: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x154ba8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154bac: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x154bacu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x154bb0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154bb0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154bb4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154bb4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154bb8: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x154bb8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x154bbc: 0x2038025  or          $s0, $s0, $v1
    ctx->pc = 0x154bbcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x154bc0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x154bc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x154bc4: 0x108200  sll         $s0, $s0, 8
    ctx->pc = 0x154bc4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 8));
    // 0x154bc8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154BC8u;
    {
        const bool branch_taken_0x154bc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154BC8u;
            // 0x154bcc: 0x2028025  or          $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154bc8) {
            ctx->pc = 0x154BDCu;
            goto label_154bdc;
        }
    }
    ctx->pc = 0x154BD0u;
label_154bd0:
    // 0x154bd0: 0x129040  sll         $s2, $s2, 1
    ctx->pc = 0x154bd0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x154bd4: 0xae820018  sw          $v0, 0x18($s4)
    ctx->pc = 0x154bd4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 2));
    // 0x154bd8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x154bd8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_154bdc:
    // 0x154bdc: 0x2a620016  slti        $v0, $s3, 0x16
    ctx->pc = 0x154bdcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)22) ? 1 : 0);
    // 0x154be0: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x154BE0u;
    {
        const bool branch_taken_0x154be0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x154BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154BE0u;
            // 0x154be4: 0x121582  srl         $v0, $s2, 22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154be0) {
            ctx->pc = 0x154C20u;
            goto label_154c20;
        }
    }
    ctx->pc = 0x154BE8u;
    // 0x154be8: 0x2673ffea  addiu       $s3, $s3, -0x16
    ctx->pc = 0x154be8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967274));
    // 0x154bec: 0x12600008  beqz        $s3, . + 4 + (0x8 << 2)
    ctx->pc = 0x154BECu;
    {
        const bool branch_taken_0x154bec = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x154BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154BECu;
            // 0x154bf0: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154bec) {
            ctx->pc = 0x154C10u;
            goto label_154c10;
        }
    }
    ctx->pc = 0x154BF4u;
    // 0x154bf4: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x154bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x154bf8: 0x501006  srlv        $v0, $s0, $v0
    ctx->pc = 0x154bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 2) & 0x1F));
    // 0x154bfc: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x154bfcu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x154c00: 0x121d82  srl         $v1, $s2, 22
    ctx->pc = 0x154c00u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
    // 0x154c04: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x154C04u;
    {
        const bool branch_taken_0x154c04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154C04u;
            // 0x154c08: 0xae830180  sw          $v1, 0x180($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 384), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154c04) {
            ctx->pc = 0x154C18u;
            goto label_154c18;
        }
    }
    ctx->pc = 0x154C0Cu;
    // 0x154c0c: 0x0  nop
    ctx->pc = 0x154c0cu;
    // NOP
label_154c10:
    // 0x154c10: 0x121582  srl         $v0, $s2, 22
    ctx->pc = 0x154c10u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 22));
    // 0x154c14: 0xae820180  sw          $v0, 0x180($s4)
    ctx->pc = 0x154c14u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 384), GPR_U32(ctx, 2));
label_154c18:
    // 0x154c18: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x154C18u;
    {
        const bool branch_taken_0x154c18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x154C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154C18u;
            // 0x154c1c: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x154c18) {
            ctx->pc = 0x154C28u;
            goto label_154c28;
        }
    }
    ctx->pc = 0x154C20u;
label_154c20:
    // 0x154c20: 0x2673000a  addiu       $s3, $s3, 0xA
    ctx->pc = 0x154c20u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 10));
    // 0x154c24: 0xae820180  sw          $v0, 0x180($s4)
    ctx->pc = 0x154c24u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 384), GPR_U32(ctx, 2));
label_154c28:
    // 0x154c28: 0x2351823  subu        $v1, $s1, $s5
    ctx->pc = 0x154c28u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
label_154c2c:
    // 0x154c2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x154c2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x154c30: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x154c30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x154c34: 0xae80032c  sw          $zero, 0x32C($s4)
    ctx->pc = 0x154c34u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 812), GPR_U32(ctx, 0));
    // 0x154c38: 0x2631821  addu        $v1, $s3, $v1
    ctx->pc = 0x154c38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x154c3c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x154c3cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x154c40: 0x2462ffc7  addiu       $v0, $v1, -0x39
    ctx->pc = 0x154c40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967239));
    // 0x154c44: 0x2463ffce  addiu       $v1, $v1, -0x32
    ctx->pc = 0x154c44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967246));
    // 0x154c48: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x154c48u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x154c4c: 0xae800328  sw          $zero, 0x328($s4)
    ctx->pc = 0x154c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 808), GPR_U32(ctx, 0));
    // 0x154c50: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x154c50u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x154c54: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x154c54u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x154c58: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x154c58u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x154c5c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x154c5cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x154c60: 0x2a21021  addu        $v0, $s5, $v0
    ctx->pc = 0x154c60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x154c64: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x154c64u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x154c68: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x154c68u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x154c6c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x154c6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x154c70: 0x3e00008  jr          $ra
    ctx->pc = 0x154C70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x154C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x154C70u;
            // 0x154c74: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151D98u: goto label_151d98;
            case 0x151DA0u: goto label_151da0;
            case 0x151E08u: goto label_151e08;
            case 0x151E14u: goto label_151e14;
            case 0x151E50u: goto label_151e50;
            case 0x151E60u: goto label_151e60;
            case 0x151E98u: goto label_151e98;
            case 0x151E9Cu: goto label_151e9c;
            case 0x151EA0u: goto label_151ea0;
            case 0x151EC8u: goto label_151ec8;
            case 0x151F00u: goto label_151f00;
            case 0x151F0Cu: goto label_151f0c;
            case 0x151F48u: goto label_151f48;
            case 0x151F54u: goto label_151f54;
            case 0x151F88u: goto label_151f88;
            case 0x151F94u: goto label_151f94;
            case 0x151FD0u: goto label_151fd0;
            case 0x151FDCu: goto label_151fdc;
            case 0x152010u: goto label_152010;
            case 0x15201Cu: goto label_15201c;
            case 0x152058u: goto label_152058;
            case 0x152064u: goto label_152064;
            case 0x152098u: goto label_152098;
            case 0x1520A4u: goto label_1520a4;
            case 0x1520E0u: goto label_1520e0;
            case 0x1520ECu: goto label_1520ec;
            case 0x152120u: goto label_152120;
            case 0x15212Cu: goto label_15212c;
            case 0x152168u: goto label_152168;
            case 0x152174u: goto label_152174;
            case 0x1521A8u: goto label_1521a8;
            case 0x1521B4u: goto label_1521b4;
            case 0x1521F0u: goto label_1521f0;
            case 0x1521FCu: goto label_1521fc;
            case 0x152230u: goto label_152230;
            case 0x15223Cu: goto label_15223c;
            case 0x152278u: goto label_152278;
            case 0x152284u: goto label_152284;
            case 0x1522B8u: goto label_1522b8;
            case 0x1522C4u: goto label_1522c4;
            case 0x152300u: goto label_152300;
            case 0x15230Cu: goto label_15230c;
            case 0x152340u: goto label_152340;
            case 0x15234Cu: goto label_15234c;
            case 0x152388u: goto label_152388;
            case 0x152394u: goto label_152394;
            case 0x1523C8u: goto label_1523c8;
            case 0x1523D4u: goto label_1523d4;
            case 0x152410u: goto label_152410;
            case 0x15241Cu: goto label_15241c;
            case 0x152450u: goto label_152450;
            case 0x152458u: goto label_152458;
            case 0x152460u: goto label_152460;
            case 0x152468u: goto label_152468;
            case 0x152488u: goto label_152488;
            case 0x152490u: goto label_152490;
            case 0x1524E0u: goto label_1524e0;
            case 0x1524F8u: goto label_1524f8;
            case 0x152504u: goto label_152504;
            case 0x152518u: goto label_152518;
            case 0x152530u: goto label_152530;
            case 0x15253Cu: goto label_15253c;
            case 0x152548u: goto label_152548;
            case 0x152580u: goto label_152580;
            case 0x15258Cu: goto label_15258c;
            case 0x1525C8u: goto label_1525c8;
            case 0x1525D4u: goto label_1525d4;
            case 0x152608u: goto label_152608;
            case 0x152614u: goto label_152614;
            case 0x152650u: goto label_152650;
            case 0x15265Cu: goto label_15265c;
            case 0x152698u: goto label_152698;
            case 0x1526A4u: goto label_1526a4;
            case 0x1526E0u: goto label_1526e0;
            case 0x1526ECu: goto label_1526ec;
            case 0x152720u: goto label_152720;
            case 0x15272Cu: goto label_15272c;
            case 0x152768u: goto label_152768;
            case 0x152774u: goto label_152774;
            case 0x1527A8u: goto label_1527a8;
            case 0x1527B4u: goto label_1527b4;
            case 0x1527F0u: goto label_1527f0;
            case 0x1527FCu: goto label_1527fc;
            case 0x152830u: goto label_152830;
            case 0x15283Cu: goto label_15283c;
            case 0x152878u: goto label_152878;
            case 0x152884u: goto label_152884;
            case 0x1528B8u: goto label_1528b8;
            case 0x1528C4u: goto label_1528c4;
            case 0x152900u: goto label_152900;
            case 0x15290Cu: goto label_15290c;
            case 0x152940u: goto label_152940;
            case 0x152948u: goto label_152948;
            case 0x152950u: goto label_152950;
            case 0x152958u: goto label_152958;
            case 0x152960u: goto label_152960;
            case 0x152968u: goto label_152968;
            case 0x1529A0u: goto label_1529a0;
            case 0x1529ACu: goto label_1529ac;
            case 0x1529E8u: goto label_1529e8;
            case 0x1529F4u: goto label_1529f4;
            case 0x152A08u: goto label_152a08;
            case 0x152A54u: goto label_152a54;
            case 0x152A64u: goto label_152a64;
            case 0x152A98u: goto label_152a98;
            case 0x152AA4u: goto label_152aa4;
            case 0x152AE0u: goto label_152ae0;
            case 0x152AECu: goto label_152aec;
            case 0x152B00u: goto label_152b00;
            case 0x152B4Cu: goto label_152b4c;
            case 0x152B5Cu: goto label_152b5c;
            case 0x152B90u: goto label_152b90;
            case 0x152B9Cu: goto label_152b9c;
            case 0x152BD8u: goto label_152bd8;
            case 0x152BE4u: goto label_152be4;
            case 0x152BF8u: goto label_152bf8;
            case 0x152C44u: goto label_152c44;
            case 0x152C54u: goto label_152c54;
            case 0x152C80u: goto label_152c80;
            case 0x152C88u: goto label_152c88;
            case 0x152C90u: goto label_152c90;
            case 0x152C98u: goto label_152c98;
            case 0x152CB0u: goto label_152cb0;
            case 0x152CC4u: goto label_152cc4;
            case 0x152CD4u: goto label_152cd4;
            case 0x152CDCu: goto label_152cdc;
            case 0x152CE8u: goto label_152ce8;
            case 0x152D20u: goto label_152d20;
            case 0x152D2Cu: goto label_152d2c;
            case 0x152D68u: goto label_152d68;
            case 0x152D74u: goto label_152d74;
            case 0x152DA8u: goto label_152da8;
            case 0x152DB4u: goto label_152db4;
            case 0x152DF0u: goto label_152df0;
            case 0x152DFCu: goto label_152dfc;
            case 0x152E30u: goto label_152e30;
            case 0x152E3Cu: goto label_152e3c;
            case 0x152E78u: goto label_152e78;
            case 0x152E84u: goto label_152e84;
            case 0x152EB8u: goto label_152eb8;
            case 0x152EC4u: goto label_152ec4;
            case 0x152F00u: goto label_152f00;
            case 0x152F0Cu: goto label_152f0c;
            case 0x152F40u: goto label_152f40;
            case 0x152F4Cu: goto label_152f4c;
            case 0x152F88u: goto label_152f88;
            case 0x152F94u: goto label_152f94;
            case 0x152FC8u: goto label_152fc8;
            case 0x152FD4u: goto label_152fd4;
            case 0x153010u: goto label_153010;
            case 0x15301Cu: goto label_15301c;
            case 0x153050u: goto label_153050;
            case 0x15305Cu: goto label_15305c;
            case 0x153098u: goto label_153098;
            case 0x1530A4u: goto label_1530a4;
            case 0x1530D8u: goto label_1530d8;
            case 0x1530E4u: goto label_1530e4;
            case 0x153120u: goto label_153120;
            case 0x15312Cu: goto label_15312c;
            case 0x153160u: goto label_153160;
            case 0x15316Cu: goto label_15316c;
            case 0x1531A8u: goto label_1531a8;
            case 0x1531B4u: goto label_1531b4;
            case 0x1531E8u: goto label_1531e8;
            case 0x1531F8u: goto label_1531f8;
            case 0x153208u: goto label_153208;
            case 0x153240u: goto label_153240;
            case 0x15324Cu: goto label_15324c;
            case 0x153288u: goto label_153288;
            case 0x153298u: goto label_153298;
            case 0x1532D0u: goto label_1532d0;
            case 0x1532DCu: goto label_1532dc;
            case 0x153318u: goto label_153318;
            case 0x153324u: goto label_153324;
            case 0x153368u: goto label_153368;
            case 0x153374u: goto label_153374;
            case 0x1533B0u: goto label_1533b0;
            case 0x1533BCu: goto label_1533bc;
            case 0x1533F0u: goto label_1533f0;
            case 0x1533FCu: goto label_1533fc;
            case 0x153438u: goto label_153438;
            case 0x153444u: goto label_153444;
            case 0x153478u: goto label_153478;
            case 0x153484u: goto label_153484;
            case 0x1534C0u: goto label_1534c0;
            case 0x1534CCu: goto label_1534cc;
            case 0x153500u: goto label_153500;
            case 0x15350Cu: goto label_15350c;
            case 0x153548u: goto label_153548;
            case 0x153554u: goto label_153554;
            case 0x153588u: goto label_153588;
            case 0x153594u: goto label_153594;
            case 0x1535D0u: goto label_1535d0;
            case 0x1535DCu: goto label_1535dc;
            case 0x153610u: goto label_153610;
            case 0x15361Cu: goto label_15361c;
            case 0x153658u: goto label_153658;
            case 0x153664u: goto label_153664;
            case 0x153698u: goto label_153698;
            case 0x1536A8u: goto label_1536a8;
            case 0x1536B8u: goto label_1536b8;
            case 0x1536F0u: goto label_1536f0;
            case 0x1536FCu: goto label_1536fc;
            case 0x153738u: goto label_153738;
            case 0x153744u: goto label_153744;
            case 0x153780u: goto label_153780;
            case 0x15378Cu: goto label_15378c;
            case 0x1537C8u: goto label_1537c8;
            case 0x1537D4u: goto label_1537d4;
            case 0x153808u: goto label_153808;
            case 0x153814u: goto label_153814;
            case 0x153850u: goto label_153850;
            case 0x15385Cu: goto label_15385c;
            case 0x153890u: goto label_153890;
            case 0x1538A0u: goto label_1538a0;
            case 0x1538B0u: goto label_1538b0;
            case 0x1538B8u: goto label_1538b8;
            case 0x1538D8u: goto label_1538d8;
            case 0x153908u: goto label_153908;
            case 0x153914u: goto label_153914;
            case 0x153950u: goto label_153950;
            case 0x15395Cu: goto label_15395c;
            case 0x153990u: goto label_153990;
            case 0x15399Cu: goto label_15399c;
            case 0x1539D8u: goto label_1539d8;
            case 0x1539E4u: goto label_1539e4;
            case 0x153A18u: goto label_153a18;
            case 0x153A24u: goto label_153a24;
            case 0x153A60u: goto label_153a60;
            case 0x153A6Cu: goto label_153a6c;
            case 0x153AA0u: goto label_153aa0;
            case 0x153AACu: goto label_153aac;
            case 0x153AE8u: goto label_153ae8;
            case 0x153AF4u: goto label_153af4;
            case 0x153B18u: goto label_153b18;
            case 0x153B50u: goto label_153b50;
            case 0x153B5Cu: goto label_153b5c;
            case 0x153B98u: goto label_153b98;
            case 0x153BA4u: goto label_153ba4;
            case 0x153BD8u: goto label_153bd8;
            case 0x153BE4u: goto label_153be4;
            case 0x153C20u: goto label_153c20;
            case 0x153C2Cu: goto label_153c2c;
            case 0x153C60u: goto label_153c60;
            case 0x153C6Cu: goto label_153c6c;
            case 0x153CA8u: goto label_153ca8;
            case 0x153CB4u: goto label_153cb4;
            case 0x153CE8u: goto label_153ce8;
            case 0x153CF4u: goto label_153cf4;
            case 0x153D30u: goto label_153d30;
            case 0x153D3Cu: goto label_153d3c;
            case 0x153D70u: goto label_153d70;
            case 0x153D7Cu: goto label_153d7c;
            case 0x153DB8u: goto label_153db8;
            case 0x153DC4u: goto label_153dc4;
            case 0x153DF8u: goto label_153df8;
            case 0x153E04u: goto label_153e04;
            case 0x153E40u: goto label_153e40;
            case 0x153E4Cu: goto label_153e4c;
            case 0x153E80u: goto label_153e80;
            case 0x153E8Cu: goto label_153e8c;
            case 0x153EC8u: goto label_153ec8;
            case 0x153ED4u: goto label_153ed4;
            case 0x153F08u: goto label_153f08;
            case 0x153F14u: goto label_153f14;
            case 0x153F50u: goto label_153f50;
            case 0x153F5Cu: goto label_153f5c;
            case 0x153F90u: goto label_153f90;
            case 0x153F9Cu: goto label_153f9c;
            case 0x153FD8u: goto label_153fd8;
            case 0x153FE4u: goto label_153fe4;
            case 0x154018u: goto label_154018;
            case 0x154024u: goto label_154024;
            case 0x154060u: goto label_154060;
            case 0x15406Cu: goto label_15406c;
            case 0x1540A0u: goto label_1540a0;
            case 0x1540ACu: goto label_1540ac;
            case 0x1540E8u: goto label_1540e8;
            case 0x1540F4u: goto label_1540f4;
            case 0x154128u: goto label_154128;
            case 0x154134u: goto label_154134;
            case 0x154170u: goto label_154170;
            case 0x15417Cu: goto label_15417c;
            case 0x1541B0u: goto label_1541b0;
            case 0x1541BCu: goto label_1541bc;
            case 0x1541F8u: goto label_1541f8;
            case 0x154204u: goto label_154204;
            case 0x154238u: goto label_154238;
            case 0x154244u: goto label_154244;
            case 0x154280u: goto label_154280;
            case 0x15428Cu: goto label_15428c;
            case 0x1542C0u: goto label_1542c0;
            case 0x1542CCu: goto label_1542cc;
            case 0x154308u: goto label_154308;
            case 0x154314u: goto label_154314;
            case 0x154348u: goto label_154348;
            case 0x154354u: goto label_154354;
            case 0x154390u: goto label_154390;
            case 0x15439Cu: goto label_15439c;
            case 0x1543D8u: goto label_1543d8;
            case 0x1543E4u: goto label_1543e4;
            case 0x154420u: goto label_154420;
            case 0x15442Cu: goto label_15442c;
            case 0x154460u: goto label_154460;
            case 0x15446Cu: goto label_15446c;
            case 0x1544A8u: goto label_1544a8;
            case 0x1544B4u: goto label_1544b4;
            case 0x1544E8u: goto label_1544e8;
            case 0x1544F4u: goto label_1544f4;
            case 0x154530u: goto label_154530;
            case 0x15453Cu: goto label_15453c;
            case 0x154570u: goto label_154570;
            case 0x15457Cu: goto label_15457c;
            case 0x1545B8u: goto label_1545b8;
            case 0x1545C4u: goto label_1545c4;
            case 0x1545F8u: goto label_1545f8;
            case 0x154600u: goto label_154600;
            case 0x154608u: goto label_154608;
            case 0x154610u: goto label_154610;
            case 0x154618u: goto label_154618;
            case 0x154620u: goto label_154620;
            case 0x154628u: goto label_154628;
            case 0x154660u: goto label_154660;
            case 0x15466Cu: goto label_15466c;
            case 0x1546A8u: goto label_1546a8;
            case 0x1546B8u: goto label_1546b8;
            case 0x1546F0u: goto label_1546f0;
            case 0x1546FCu: goto label_1546fc;
            case 0x154738u: goto label_154738;
            case 0x154744u: goto label_154744;
            case 0x154778u: goto label_154778;
            case 0x154784u: goto label_154784;
            case 0x1547C0u: goto label_1547c0;
            case 0x1547CCu: goto label_1547cc;
            case 0x154800u: goto label_154800;
            case 0x15480Cu: goto label_15480c;
            case 0x154848u: goto label_154848;
            case 0x154854u: goto label_154854;
            case 0x154888u: goto label_154888;
            case 0x154894u: goto label_154894;
            case 0x1548D0u: goto label_1548d0;
            case 0x1548DCu: goto label_1548dc;
            case 0x154910u: goto label_154910;
            case 0x15491Cu: goto label_15491c;
            case 0x154958u: goto label_154958;
            case 0x154964u: goto label_154964;
            case 0x154998u: goto label_154998;
            case 0x1549A4u: goto label_1549a4;
            case 0x1549E0u: goto label_1549e0;
            case 0x1549ECu: goto label_1549ec;
            case 0x154A20u: goto label_154a20;
            case 0x154A30u: goto label_154a30;
            case 0x154A40u: goto label_154a40;
            case 0x154A78u: goto label_154a78;
            case 0x154A84u: goto label_154a84;
            case 0x154AC0u: goto label_154ac0;
            case 0x154ACCu: goto label_154acc;
            case 0x154B00u: goto label_154b00;
            case 0x154B0Cu: goto label_154b0c;
            case 0x154B48u: goto label_154b48;
            case 0x154B54u: goto label_154b54;
            case 0x154B88u: goto label_154b88;
            case 0x154B94u: goto label_154b94;
            case 0x154BD0u: goto label_154bd0;
            case 0x154BDCu: goto label_154bdc;
            case 0x154C10u: goto label_154c10;
            case 0x154C18u: goto label_154c18;
            case 0x154C20u: goto label_154c20;
            case 0x154C28u: goto label_154c28;
            case 0x154C2Cu: goto label_154c2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x154C78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
