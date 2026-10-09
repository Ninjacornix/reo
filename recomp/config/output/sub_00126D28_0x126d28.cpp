#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126D28
// Address: 0x126d28 - 0x126f20
void sub_00126D28_0x126d28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126D28_0x126d28");
#endif

    switch (ctx->pc) {
        case 0x126d70u: goto label_126d70;
        default: break;
    }

    ctx->pc = 0x126d28u;

    // 0x126d28: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x126d28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x126d2c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x126d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x126d30: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x126d30u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126d34: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x126d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x126d38: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x126d38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126d3c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x126d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x126d40: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x126d40u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126d44: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x126d44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x126d48: 0x120982d  daddu       $s3, $t1, $zero
    ctx->pc = 0x126d48u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126d4c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x126d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x126d50: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x126d50u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126d54: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x126d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x126d58: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x126d58u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126d5c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x126d5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x126d60: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x126d60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126d64: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x126d64u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x126d68: 0xc049a46  jal         func_126918
    ctx->pc = 0x126D68u;
    SET_GPR_U32(ctx, 31, 0x126D70u);
    ctx->pc = 0x126D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126D68u;
            // 0x126d6c: 0x27a70001  addiu       $a3, $sp, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126918u;
    if (runtime->hasFunction(0x126918u)) {
        auto targetFn = runtime->lookupFunction(0x126918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126D70u; }
        if (ctx->pc != 0x126D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126918_0x126918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126D70u; }
        if (ctx->pc != 0x126D70u) { return; }
    }
    ctx->pc = 0x126D70u;
label_126d70:
    // 0x126d70: 0x54400062  bnel        $v0, $zero, . + 4 + (0x62 << 2)
    ctx->pc = 0x126D70u;
    {
        const bool branch_taken_0x126d70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x126d70) {
            ctx->pc = 0x126D74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126D70u;
            // 0x126d74: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126EFCu;
            goto label_126efc;
        }
    }
    ctx->pc = 0x126D78u;
    // 0x126d78: 0x93a30000  lbu         $v1, 0x0($sp)
    ctx->pc = 0x126d78u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x126d7c: 0x2406003c  addiu       $a2, $zero, 0x3C
    ctx->pc = 0x126d7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x126d80: 0x24040048  addiu       $a0, $zero, 0x48
    ctx->pc = 0x126d80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x126d84: 0x38670004  xori        $a3, $v1, 0x4
    ctx->pc = 0x126d84u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)4);
    // 0x126d88: 0x87300a  movz        $a2, $a0, $a3
    ctx->pc = 0x126d88u;
    if (GPR_U64(ctx, 7) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 4));
    // 0x126d8c: 0x226182a  slt         $v1, $s1, $a2
    ctx->pc = 0x126d8cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x126d90: 0x54600059  bnel        $v1, $zero, . + 4 + (0x59 << 2)
    ctx->pc = 0x126D90u;
    {
        const bool branch_taken_0x126d90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x126d90) {
            ctx->pc = 0x126D94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126D90u;
            // 0x126d94: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126EF8u;
            goto label_126ef8;
        }
    }
    ctx->pc = 0x126D98u;
    // 0x126d98: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x126d98u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x126d9c: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x126d9cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x126da0: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x126da0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126da4: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x126da4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x126da8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126da8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126dac: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x126dacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x126db0: 0x14650021  bne         $v1, $a1, . + 4 + (0x21 << 2)
    ctx->pc = 0x126DB0u;
    {
        const bool branch_taken_0x126db0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x126DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126DB0u;
            // 0x126db4: 0x240aff00  addiu       $t2, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126db0) {
            ctx->pc = 0x126E38u;
            goto label_126e38;
        }
    }
    ctx->pc = 0x126DB8u;
    // 0x126db8: 0x96030002  lhu         $v1, 0x2($s0)
    ctx->pc = 0x126db8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x126dbc: 0x24c5fffc  addiu       $a1, $a2, -0x4
    ctx->pc = 0x126dbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967292));
    // 0x126dc0: 0x92040003  lbu         $a0, 0x3($s0)
    ctx->pc = 0x126dc0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x126dc4: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126dc8: 0x6a1824  and         $v1, $v1, $t2
    ctx->pc = 0x126dc8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 10));
    // 0x126dcc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x126dccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x126dd0: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x126dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x126dd4: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x126dd4u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x126dd8: 0x85202a  slt         $a0, $a0, $a1
    ctx->pc = 0x126dd8u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x126ddc: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x126DDCu;
    {
        const bool branch_taken_0x126ddc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x126DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126DDCu;
            // 0x126de0: 0x24030020  addiu       $v1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126ddc) {
            ctx->pc = 0x126DF0u;
            goto label_126df0;
        }
    }
    ctx->pc = 0x126DE4u;
    // 0x126de4: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x126DE4u;
    {
        const bool branch_taken_0x126de4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126DE4u;
            // 0x126de8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126de4) {
            ctx->pc = 0x126EF8u;
            goto label_126ef8;
        }
    }
    ctx->pc = 0x126DECu;
    // 0x126dec: 0x0  nop
    ctx->pc = 0x126decu;
    // NOP
label_126df0:
    // 0x126df0: 0x24090014  addiu       $t1, $zero, 0x14
    ctx->pc = 0x126df0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x126df4: 0x67480a  movz        $t1, $v1, $a3
    ctx->pc = 0x126df4u;
    if (GPR_U64(ctx, 7) == 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x126df8: 0x3c084149  lui         $t0, 0x4149
    ctx->pc = 0x126df8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)16713 << 16));
    // 0x126dfc: 0x25290004  addiu       $t1, $t1, 0x4
    ctx->pc = 0x126dfcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
    // 0x126e00: 0x35084e46  ori         $t0, $t0, 0x4E46
    ctx->pc = 0x126e00u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)20038);
    // 0x126e04: 0x2092821  addu        $a1, $s0, $t1
    ctx->pc = 0x126e04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 9)));
    // 0x126e08: 0x90a60001  lbu         $a2, 0x1($a1)
    ctx->pc = 0x126e08u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x126e0c: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x126e0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x126e10: 0x90a40002  lbu         $a0, 0x2($a1)
    ctx->pc = 0x126e10u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x126e14: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x126e14u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x126e18: 0x90a70003  lbu         $a3, 0x3($a1)
    ctx->pc = 0x126e18u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 3)));
    // 0x126e1c: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x126e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x126e20: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x126e20u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x126e24: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x126e24u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x126e28: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x126e28u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x126e2c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126e2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126e30: 0x10680003  beq         $v1, $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x126E30u;
    {
        const bool branch_taken_0x126e30 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        ctx->pc = 0x126E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126E30u;
            // 0x126e34: 0x25290004  addiu       $t1, $t1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126e30) {
            ctx->pc = 0x126E40u;
            goto label_126e40;
        }
    }
    ctx->pc = 0x126E38u;
label_126e38:
    // 0x126e38: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x126E38u;
    {
        const bool branch_taken_0x126e38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126E38u;
            // 0x126e3c: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126e38) {
            ctx->pc = 0x126EF8u;
            goto label_126ef8;
        }
    }
    ctx->pc = 0x126E40u;
label_126e40:
    // 0x126e40: 0x2091821  addu        $v1, $s0, $t1
    ctx->pc = 0x126e40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 9)));
    // 0x126e44: 0x25290004  addiu       $t1, $t1, 0x4
    ctx->pc = 0x126e44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
    // 0x126e48: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x126e48u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x126e4c: 0x3c0700ff  lui         $a3, 0xFF
    ctx->pc = 0x126e4cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)255 << 16));
    // 0x126e50: 0x2094021  addu        $t0, $s0, $t1
    ctx->pc = 0x126e50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 9)));
    // 0x126e54: 0x25290010  addiu       $t1, $t1, 0x10
    ctx->pc = 0x126e54u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 16));
    // 0x126e58: 0x53203  sra         $a2, $a1, 8
    ctx->pc = 0x126e58u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 5), 8));
    // 0x126e5c: 0x52200  sll         $a0, $a1, 8
    ctx->pc = 0x126e5cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x126e60: 0x872024  and         $a0, $a0, $a3
    ctx->pc = 0x126e60u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 7));
    // 0x126e64: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x126e64u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x126e68: 0x51e02  srl         $v1, $a1, 24
    ctx->pc = 0x126e68u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x126e6c: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x126e6cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x126e70: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x126e70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x126e74: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x126e74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x126e78: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126e78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126e7c: 0x2092821  addu        $a1, $s0, $t1
    ctx->pc = 0x126e7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 9)));
    // 0x126e80: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x126e80u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x126e84: 0x25290004  addiu       $t1, $t1, 0x4
    ctx->pc = 0x126e84u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
    // 0x126e88: 0x2093021  addu        $a2, $s0, $t1
    ctx->pc = 0x126e88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 9)));
    // 0x126e8c: 0x1303821  addu        $a3, $t1, $s0
    ctx->pc = 0x126e8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 16)));
    // 0x126e90: 0x69030007  ldl         $v1, 0x7($t0)
    ctx->pc = 0x126e90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x126e94: 0x6d030000  ldr         $v1, 0x0($t0)
    ctx->pc = 0x126e94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x126e98: 0x6904000f  ldl         $a0, 0xF($t0)
    ctx->pc = 0x126e98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x126e9c: 0x6d040008  ldr         $a0, 0x8($t0)
    ctx->pc = 0x126e9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x126ea0: 0xb2830007  sdl         $v1, 0x7($s4)
    ctx->pc = 0x126ea0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 20), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x126ea4: 0xb6830000  sdr         $v1, 0x0($s4)
    ctx->pc = 0x126ea4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 20), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x126ea8: 0xb284000f  sdl         $a0, 0xF($s4)
    ctx->pc = 0x126ea8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 20), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x126eac: 0xb6840008  sdr         $a0, 0x8($s4)
    ctx->pc = 0x126eacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 20), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x126eb0: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x126eb0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x126eb4: 0x90a40001  lbu         $a0, 0x1($a1)
    ctx->pc = 0x126eb4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x126eb8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126ebc: 0x6a1824  and         $v1, $v1, $t2
    ctx->pc = 0x126ebcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 10));
    // 0x126ec0: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x126ec0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x126ec4: 0xa6a40000  sh          $a0, 0x0($s5)
    ctx->pc = 0x126ec4u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x126ec8: 0x94c30000  lhu         $v1, 0x0($a2)
    ctx->pc = 0x126ec8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x126ecc: 0x90c40001  lbu         $a0, 0x1($a2)
    ctx->pc = 0x126eccu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x126ed0: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126ed0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126ed4: 0x6a1824  and         $v1, $v1, $t2
    ctx->pc = 0x126ed4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 10));
    // 0x126ed8: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x126ed8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x126edc: 0xa6640000  sh          $a0, 0x0($s3)
    ctx->pc = 0x126edcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x126ee0: 0x94e30002  lhu         $v1, 0x2($a3)
    ctx->pc = 0x126ee0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x126ee4: 0x90e40003  lbu         $a0, 0x3($a3)
    ctx->pc = 0x126ee4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x126ee8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126eec: 0x6a1824  and         $v1, $v1, $t2
    ctx->pc = 0x126eecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 10));
    // 0x126ef0: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x126ef0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x126ef4: 0xa6640002  sh          $a0, 0x2($s3)
    ctx->pc = 0x126ef4u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 2), (uint16_t)GPR_U32(ctx, 4));
label_126ef8:
    // 0x126ef8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x126ef8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_126efc:
    // 0x126efc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x126efcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x126f00: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x126f00u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x126f04: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x126f04u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x126f08: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x126f08u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x126f0c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x126f0cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x126f10: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x126f10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x126f14: 0x3e00008  jr          $ra
    ctx->pc = 0x126F14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126F14u;
            // 0x126f18: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126D70u: goto label_126d70;
            case 0x126DF0u: goto label_126df0;
            case 0x126E38u: goto label_126e38;
            case 0x126E40u: goto label_126e40;
            case 0x126EF8u: goto label_126ef8;
            case 0x126EFCu: goto label_126efc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126F1Cu;
    // 0x126f1c: 0x0  nop
    ctx->pc = 0x126f1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
