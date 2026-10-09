#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126AC8
// Address: 0x126ac8 - 0x126d28
void sub_00126AC8_0x126ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126AC8_0x126ac8");
#endif

    switch (ctx->pc) {
        case 0x126b20u: goto label_126b20;
        default: break;
    }

    ctx->pc = 0x126ac8u;

    // 0x126ac8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x126ac8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x126acc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x126accu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x126ad0: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x126ad0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126ad4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x126ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x126ad8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x126ad8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126adc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x126adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x126ae0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x126ae0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126ae4: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x126ae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x126ae8: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x126ae8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126aec: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x126aecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x126af0: 0x120a02d  daddu       $s4, $t1, $zero
    ctx->pc = 0x126af0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126af4: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x126af4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x126af8: 0x140a82d  daddu       $s5, $t2, $zero
    ctx->pc = 0x126af8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126afc: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x126afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x126b00: 0x100b02d  daddu       $s6, $t0, $zero
    ctx->pc = 0x126b00u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126b04: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x126b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x126b08: 0x160b82d  daddu       $s7, $t3, $zero
    ctx->pc = 0x126b08u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126b0c: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x126b0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x126b10: 0x27a70001  addiu       $a3, $sp, 0x1
    ctx->pc = 0x126b10u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 1));
    // 0x126b14: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x126b14u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x126b18: 0xc049a46  jal         func_126918
    ctx->pc = 0x126B18u;
    SET_GPR_U32(ctx, 31, 0x126B20u);
    ctx->pc = 0x126B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126B18u;
            // 0x126b1c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126918u;
    if (runtime->hasFunction(0x126918u)) {
        auto targetFn = runtime->lookupFunction(0x126918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126B20u; }
        if (ctx->pc != 0x126B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126918_0x126918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126B20u; }
        if (ctx->pc != 0x126B20u) { return; }
    }
    ctx->pc = 0x126B20u;
label_126b20:
    // 0x126b20: 0x54400077  bnel        $v0, $zero, . + 4 + (0x77 << 2)
    ctx->pc = 0x126B20u;
    {
        const bool branch_taken_0x126b20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x126b20) {
            ctx->pc = 0x126B24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126B20u;
            // 0x126b24: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126D00u;
            goto label_126d00;
        }
    }
    ctx->pc = 0x126B28u;
    // 0x126b28: 0x93a30000  lbu         $v1, 0x0($sp)
    ctx->pc = 0x126b28u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x126b2c: 0x24060030  addiu       $a2, $zero, 0x30
    ctx->pc = 0x126b2cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x126b30: 0x2404003c  addiu       $a0, $zero, 0x3C
    ctx->pc = 0x126b30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x126b34: 0x38670004  xori        $a3, $v1, 0x4
    ctx->pc = 0x126b34u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)4);
    // 0x126b38: 0x87300a  movz        $a2, $a0, $a3
    ctx->pc = 0x126b38u;
    if (GPR_U64(ctx, 7) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 4));
    // 0x126b3c: 0x226182a  slt         $v1, $s1, $a2
    ctx->pc = 0x126b3cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x126b40: 0x5460006e  bnel        $v1, $zero, . + 4 + (0x6E << 2)
    ctx->pc = 0x126B40u;
    {
        const bool branch_taken_0x126b40 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x126b40) {
            ctx->pc = 0x126B44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126B40u;
            // 0x126b44: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126CFCu;
            goto label_126cfc;
        }
    }
    ctx->pc = 0x126B48u;
    // 0x126b48: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x126b48u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x126b4c: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x126b4cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x126b50: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x126b50u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126b54: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x126b54u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x126b58: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126b58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126b5c: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x126b5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x126b60: 0x14650027  bne         $v1, $a1, . + 4 + (0x27 << 2)
    ctx->pc = 0x126B60u;
    {
        const bool branch_taken_0x126b60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x126B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126B60u;
            // 0x126b64: 0x240eff00  addiu       $t6, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126b60) {
            ctx->pc = 0x126C00u;
            goto label_126c00;
        }
    }
    ctx->pc = 0x126B68u;
    // 0x126b68: 0x96030002  lhu         $v1, 0x2($s0)
    ctx->pc = 0x126b68u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x126b6c: 0x24c5fffc  addiu       $a1, $a2, -0x4
    ctx->pc = 0x126b6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967292));
    // 0x126b70: 0x92040003  lbu         $a0, 0x3($s0)
    ctx->pc = 0x126b70u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x126b74: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126b74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126b78: 0x6e1824  and         $v1, $v1, $t6
    ctx->pc = 0x126b78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 14));
    // 0x126b7c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x126b7cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x126b80: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x126b80u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x126b84: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x126b84u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x126b88: 0x85202a  slt         $a0, $a0, $a1
    ctx->pc = 0x126b88u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x126b8c: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x126B8Cu;
    {
        const bool branch_taken_0x126b8c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x126B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126B8Cu;
            // 0x126b90: 0x24030020  addiu       $v1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126b8c) {
            ctx->pc = 0x126BA0u;
            goto label_126ba0;
        }
    }
    ctx->pc = 0x126B94u;
    // 0x126b94: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x126B94u;
    {
        const bool branch_taken_0x126b94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126B94u;
            // 0x126b98: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126b94) {
            ctx->pc = 0x126CFCu;
            goto label_126cfc;
        }
    }
    ctx->pc = 0x126B9Cu;
    // 0x126b9c: 0x0  nop
    ctx->pc = 0x126b9cu;
    // NOP
label_126ba0:
    // 0x126ba0: 0x240d0014  addiu       $t5, $zero, 0x14
    ctx->pc = 0x126ba0u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x126ba4: 0x67680a  movz        $t5, $v1, $a3
    ctx->pc = 0x126ba4u;
    if (GPR_U64(ctx, 7) == 0) SET_GPR_VEC(ctx, 13, GPR_VEC(ctx, 3));
    // 0x126ba8: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x126ba8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x126bac: 0x20d3021  addu        $a2, $s0, $t5
    ctx->pc = 0x126bacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 13)));
    // 0x126bb0: 0x25ad0002  addiu       $t5, $t5, 0x2
    ctx->pc = 0x126bb0u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 2));
    // 0x126bb4: 0x20d3821  addu        $a3, $s0, $t5
    ctx->pc = 0x126bb4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 13)));
    // 0x126bb8: 0x25ad0002  addiu       $t5, $t5, 0x2
    ctx->pc = 0x126bb8u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 2));
    // 0x126bbc: 0x94c50000  lhu         $a1, 0x0($a2)
    ctx->pc = 0x126bbcu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x126bc0: 0x94e40000  lhu         $a0, 0x0($a3)
    ctx->pc = 0x126bc0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x126bc4: 0x90c30001  lbu         $v1, 0x1($a2)
    ctx->pc = 0x126bc4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x126bc8: 0x52a00  sll         $a1, $a1, 8
    ctx->pc = 0x126bc8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x126bcc: 0x90e60001  lbu         $a2, 0x1($a3)
    ctx->pc = 0x126bccu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x126bd0: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x126bd0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x126bd4: 0x8e2024  and         $a0, $a0, $t6
    ctx->pc = 0x126bd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 14));
    // 0x126bd8: 0xae2824  and         $a1, $a1, $t6
    ctx->pc = 0x126bd8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 14));
    // 0x126bdc: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x126bdcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x126be0: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x126be0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x126be4: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x126be4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x126be8: 0x62400  sll         $a0, $a2, 16
    ctx->pc = 0x126be8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x126bec: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x126becu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x126bf0: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x126bf0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x126bf4: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x126bf4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x126bf8: 0x10880003  beq         $a0, $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x126BF8u;
    {
        const bool branch_taken_0x126bf8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 8));
        ctx->pc = 0x126BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126BF8u;
            // 0x126bfc: 0xa6460000  sh          $a2, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126bf8) {
            ctx->pc = 0x126C08u;
            goto label_126c08;
        }
    }
    ctx->pc = 0x126C00u;
label_126c00:
    // 0x126c00: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x126C00u;
    {
        const bool branch_taken_0x126c00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126C00u;
            // 0x126c04: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126c00) {
            ctx->pc = 0x126CFCu;
            goto label_126cfc;
        }
    }
    ctx->pc = 0x126C08u;
label_126c08:
    // 0x126c08: 0x25ad0002  addiu       $t5, $t5, 0x2
    ctx->pc = 0x126c08u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 2));
    // 0x126c0c: 0x3c0900ff  lui         $t1, 0xFF
    ctx->pc = 0x126c0cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)255 << 16));
    // 0x126c10: 0x20d5021  addu        $t2, $s0, $t5
    ctx->pc = 0x126c10u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 13)));
    // 0x126c14: 0x25ad0002  addiu       $t5, $t5, 0x2
    ctx->pc = 0x126c14u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 2));
    // 0x126c18: 0x20d1821  addu        $v1, $s0, $t5
    ctx->pc = 0x126c18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 13)));
    // 0x126c1c: 0x25ad0004  addiu       $t5, $t5, 0x4
    ctx->pc = 0x126c1cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 4));
    // 0x126c20: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x126c20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x126c24: 0x20d5821  addu        $t3, $s0, $t5
    ctx->pc = 0x126c24u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 13)));
    // 0x126c28: 0x25ad0004  addiu       $t5, $t5, 0x4
    ctx->pc = 0x126c28u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 4));
    // 0x126c2c: 0x95470000  lhu         $a3, 0x0($t2)
    ctx->pc = 0x126c2cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x126c30: 0x53203  sra         $a2, $a1, 8
    ctx->pc = 0x126c30u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 5), 8));
    // 0x126c34: 0x52200  sll         $a0, $a1, 8
    ctx->pc = 0x126c34u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x126c38: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x126c38u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x126c3c: 0x51e02  srl         $v1, $a1, 24
    ctx->pc = 0x126c3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x126c40: 0x892024  and         $a0, $a0, $t1
    ctx->pc = 0x126c40u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 9));
    // 0x126c44: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x126c44u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x126c48: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x126c48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x126c4c: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x126c4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x126c50: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126c50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126c54: 0x20d6021  addu        $t4, $s0, $t5
    ctx->pc = 0x126c54u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 13)));
    // 0x126c58: 0xae830000  sw          $v1, 0x0($s4)
    ctx->pc = 0x126c58u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 3));
    // 0x126c5c: 0x1b06821  addu        $t5, $t5, $s0
    ctx->pc = 0x126c5cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 16)));
    // 0x126c60: 0x91480001  lbu         $t0, 0x1($t2)
    ctx->pc = 0x126c60u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 1)));
    // 0x126c64: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x126c64u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x126c68: 0x8d650000  lw          $a1, 0x0($t3)
    ctx->pc = 0x126c68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x126c6c: 0xee3824  and         $a3, $a3, $t6
    ctx->pc = 0x126c6cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 14));
    // 0x126c70: 0x1074025  or          $t0, $t0, $a3
    ctx->pc = 0x126c70u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 7));
    // 0x126c74: 0x53203  sra         $a2, $a1, 8
    ctx->pc = 0x126c74u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 5), 8));
    // 0x126c78: 0x52200  sll         $a0, $a1, 8
    ctx->pc = 0x126c78u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x126c7c: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x126c7cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x126c80: 0x51e02  srl         $v1, $a1, 24
    ctx->pc = 0x126c80u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x126c84: 0x892024  and         $a0, $a0, $t1
    ctx->pc = 0x126c84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 9));
    // 0x126c88: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x126c88u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x126c8c: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x126c8cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x126c90: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x126c90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x126c94: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126c94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126c98: 0xa6c80000  sh          $t0, 0x0($s6)
    ctx->pc = 0x126c98u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 0), (uint16_t)GPR_U32(ctx, 8));
    // 0x126c9c: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x126c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x126ca0: 0x8d840000  lw          $a0, 0x0($t4)
    ctx->pc = 0x126ca0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x126ca4: 0x43203  sra         $a2, $a0, 8
    ctx->pc = 0x126ca4u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 4), 8));
    // 0x126ca8: 0x42a00  sll         $a1, $a0, 8
    ctx->pc = 0x126ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x126cac: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x126cacu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x126cb0: 0x41e02  srl         $v1, $a0, 24
    ctx->pc = 0x126cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x126cb4: 0xa92824  and         $a1, $a1, $t1
    ctx->pc = 0x126cb4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 9));
    // 0x126cb8: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x126cb8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x126cbc: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x126cbcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x126cc0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126cc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126cc4: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x126cc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x126cc8: 0xaee30000  sw          $v1, 0x0($s7)
    ctx->pc = 0x126cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 3));
    // 0x126ccc: 0x8da40004  lw          $a0, 0x4($t5)
    ctx->pc = 0x126cccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4)));
    // 0x126cd0: 0x43203  sra         $a2, $a0, 8
    ctx->pc = 0x126cd0u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 4), 8));
    // 0x126cd4: 0x42a00  sll         $a1, $a0, 8
    ctx->pc = 0x126cd4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x126cd8: 0x41e02  srl         $v1, $a0, 24
    ctx->pc = 0x126cd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x126cdc: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x126cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x126ce0: 0xa92824  and         $a1, $a1, $t1
    ctx->pc = 0x126ce0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 9));
    // 0x126ce4: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x126ce4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x126ce8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126ce8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126cec: 0x8fa40060  lw          $a0, 0x60($sp)
    ctx->pc = 0x126cecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x126cf0: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x126cf0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x126cf4: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x126cf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x126cf8: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x126cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
label_126cfc:
    // 0x126cfc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x126cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_126d00:
    // 0x126d00: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x126d00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x126d04: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x126d04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x126d08: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x126d08u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x126d0c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x126d0cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x126d10: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x126d10u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x126d14: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x126d14u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x126d18: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x126d18u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x126d1c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x126d1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x126d20: 0x3e00008  jr          $ra
    ctx->pc = 0x126D20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126D20u;
            // 0x126d24: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126B20u: goto label_126b20;
            case 0x126BA0u: goto label_126ba0;
            case 0x126C00u: goto label_126c00;
            case 0x126C08u: goto label_126c08;
            case 0x126CFCu: goto label_126cfc;
            case 0x126D00u: goto label_126d00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126D28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
