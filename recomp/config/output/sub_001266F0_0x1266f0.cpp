#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001266F0
// Address: 0x1266f0 - 0x126794
void sub_001266F0_0x1266f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001266F0_0x1266f0");
#endif

    switch (ctx->pc) {
        case 0x12676cu: goto label_12676c;
        default: break;
    }

    ctx->pc = 0x1266f0u;

    // 0x1266f0: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1266f0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1266f4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1266f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1266f8: 0x29030010  slti        $v1, $t0, 0x10
    ctx->pc = 0x1266f8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1266fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1266fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x126700: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x126700u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x126704: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x126704u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126708: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x126708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12670c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x12670cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126710: 0x1460001b  bnez        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x126710u;
    {
        const bool branch_taken_0x126710 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x126714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126710u;
            // 0x126714: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126710) {
            ctx->pc = 0x126780u;
            goto label_126780;
        }
    }
    ctx->pc = 0x126718u;
    // 0x126718: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x126718u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12671c: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x12671cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x126720: 0x90e40001  lbu         $a0, 0x1($a3)
    ctx->pc = 0x126720u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x126724: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126724u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126728: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x126728u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x12672c: 0x14850015  bne         $a0, $a1, . + 4 + (0x15 << 2)
    ctx->pc = 0x12672Cu;
    {
        const bool branch_taken_0x12672c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 5));
        ctx->pc = 0x126730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12672Cu;
            // 0x126730: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12672c) {
            ctx->pc = 0x126784u;
            goto label_126784;
        }
    }
    ctx->pc = 0x126734u;
    // 0x126734: 0x90e30002  lbu         $v1, 0x2($a3)
    ctx->pc = 0x126734u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x126738: 0x24057fff  addiu       $a1, $zero, 0x7FFF
    ctx->pc = 0x126738u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x12673c: 0x90e40003  lbu         $a0, 0x3($a3)
    ctx->pc = 0x12673cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x126740: 0xa8282a  slt         $a1, $a1, $t0
    ctx->pc = 0x126740u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x126744: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126744u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126748: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126748u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x12674c: 0x2464fffe  addiu       $a0, $v1, -0x2
    ctx->pc = 0x12674cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967294));
    // 0x126750: 0x24700004  addiu       $s0, $v1, 0x4
    ctx->pc = 0x126750u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x126754: 0x10a0000a  beqz        $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x126754u;
    {
        const bool branch_taken_0x126754 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x126758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126754u;
            // 0x126758: 0xe42021  addu        $a0, $a3, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126754) {
            ctx->pc = 0x126780u;
            goto label_126780;
        }
    }
    ctx->pc = 0x12675Cu;
    // 0x12675c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x12675cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x126760: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x126760u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x126764: 0xc041e86  jal         func_107A18
    ctx->pc = 0x126764u;
    SET_GPR_U32(ctx, 31, 0x12676Cu);
    ctx->pc = 0x126768u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126764u;
            // 0x126768: 0x24a59be0  addiu       $a1, $a1, -0x6420 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12676Cu; }
        if (ctx->pc != 0x12676Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12676Cu; }
        if (ctx->pc != 0x12676Cu) { return; }
    }
    ctx->pc = 0x12676Cu;
label_12676c:
    // 0x12676c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12676Cu;
    {
        const bool branch_taken_0x12676c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x126770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12676Cu;
            // 0x126770: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12676c) {
            ctx->pc = 0x126780u;
            goto label_126780;
        }
    }
    ctx->pc = 0x126774u;
    // 0x126774: 0x56200001  bnel        $s1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x126774u;
    {
        const bool branch_taken_0x126774 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x126774) {
            ctx->pc = 0x126778u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126774u;
            // 0x126778: 0xa6300000  sh          $s0, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12677Cu;
            goto label_12677c;
        }
    }
    ctx->pc = 0x12677Cu;
label_12677c:
    // 0x12677c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12677cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_126780:
    // 0x126780: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x126780u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_126784:
    // 0x126784: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x126784u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x126788: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x126788u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12678c: 0x3e00008  jr          $ra
    ctx->pc = 0x12678Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12678Cu;
            // 0x126790: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12676Cu: goto label_12676c;
            case 0x12677Cu: goto label_12677c;
            case 0x126780u: goto label_126780;
            case 0x126784u: goto label_126784;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126794u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
