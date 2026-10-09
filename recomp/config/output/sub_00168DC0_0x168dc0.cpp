#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168DC0
// Address: 0x168dc0 - 0x168f60
void sub_00168DC0_0x168dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168DC0_0x168dc0");
#endif

    switch (ctx->pc) {
        case 0x168e00u: goto label_168e00;
        case 0x168e0cu: goto label_168e0c;
        default: break;
    }

    ctx->pc = 0x168dc0u;

    // 0x168dc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x168dc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x168dc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x168dc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x168dc8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x168dc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168dcc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x168dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x168dd0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x168dd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168dd4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x168dd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x168dd8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x168dd8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168ddc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x168ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x168de0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x168de0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x168de4: 0x1a000046  blez        $s0, . + 4 + (0x46 << 2)
    ctx->pc = 0x168DE4u;
    {
        const bool branch_taken_0x168de4 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x168DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168DE4u;
            // 0x168de8: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168de4) {
            ctx->pc = 0x168F00u;
            goto label_168f00;
        }
    }
    ctx->pc = 0x168DECu;
    // 0x168dec: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x168decu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x168df0: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x168df0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x168df4: 0x24530638  addiu       $s3, $v0, 0x638
    ctx->pc = 0x168df4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 1592));
    // 0x168df8: 0x24740860  addiu       $s4, $v1, 0x860
    ctx->pc = 0x168df8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), 2144));
    // 0x168dfc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168dfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_168e00:
    // 0x168e00: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x168e00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168e04: 0xc0561d4  jal         func_158750
    ctx->pc = 0x168E04u;
    SET_GPR_U32(ctx, 31, 0x168E0Cu);
    ctx->pc = 0x168E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168E04u;
            // 0x168e08: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168E0Cu; }
        if (ctx->pc != 0x168E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168E0Cu; }
        if (ctx->pc != 0x168E0Cu) { return; }
    }
    ctx->pc = 0x168E0Cu;
label_168e0c:
    // 0x168e0c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x168e0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168e10: 0x10a0003c  beqz        $a1, . + 4 + (0x3C << 2)
    ctx->pc = 0x168E10u;
    {
        const bool branch_taken_0x168e10 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x168E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168E10u;
            // 0x168e14: 0xb12023  subu        $a0, $a1, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168e10) {
            ctx->pc = 0x168F04u;
            goto label_168f04;
        }
    }
    ctx->pc = 0x168E18u;
    // 0x168e18: 0x90a60007  lbu         $a2, 0x7($a1)
    ctx->pc = 0x168e18u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x168e1c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x168e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x168e20: 0x2048023  subu        $s0, $s0, $a0
    ctx->pc = 0x168e20u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x168e24: 0x2248821  addu        $s1, $s1, $a0
    ctx->pc = 0x168e24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x168e28: 0x61902  srl         $v1, $a2, 4
    ctx->pc = 0x168e28u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x168e2c: 0x30c6000f  andi        $a2, $a2, 0xF
    ctx->pc = 0x168e2cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x168e30: 0x24c200ff  addiu       $v0, $a2, 0xFF
    ctx->pc = 0x168e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 255));
    // 0x168e34: 0x90ac000b  lbu         $t4, 0xB($a1)
    ctx->pc = 0x168e34u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 11)));
    // 0x168e38: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x168e38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x168e3c: 0x90a7000a  lbu         $a3, 0xA($a1)
    ctx->pc = 0x168e3cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 10)));
    // 0x168e40: 0x2c420008  sltiu       $v0, $v0, 0x8
    ctx->pc = 0x168e40u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x168e44: 0x90a80004  lbu         $t0, 0x4($a1)
    ctx->pc = 0x168e44u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x168e48: 0x90a40005  lbu         $a0, 0x5($a1)
    ctx->pc = 0x168e48u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x168e4c: 0x90a90006  lbu         $t1, 0x6($a1)
    ctx->pc = 0x168e4cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x168e50: 0x90aa0008  lbu         $t2, 0x8($a1)
    ctx->pc = 0x168e50u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x168e54: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x168E54u;
    {
        const bool branch_taken_0x168e54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x168E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168E54u;
            // 0x168e58: 0x90ab0009  lbu         $t3, 0x9($a1) (Delay Slot)
        SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168e54) {
            ctx->pc = 0x168EF8u;
            goto label_168ef8;
        }
    }
    ctx->pc = 0x168E5Cu;
    // 0x168e5c: 0x10400026  beqz        $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x168E5Cu;
    {
        const bool branch_taken_0x168e5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168E5Cu;
            // 0x168e60: 0x71142  srl         $v0, $a3, 5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168e5c) {
            ctx->pc = 0x168EF8u;
            goto label_168ef8;
        }
    }
    ctx->pc = 0x168E64u;
    // 0x168e64: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x168e64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x168e68: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x168e68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x168e6c: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x168E6Cu;
    {
        const bool branch_taken_0x168e6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168E6Cu;
            // 0x168e70: 0x3082000f  andi        $v0, $a0, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x168e6c) {
            ctx->pc = 0x168EF8u;
            goto label_168ef8;
        }
    }
    ctx->pc = 0x168E74u;
    // 0x168e74: 0x42102  srl         $a0, $a0, 4
    ctx->pc = 0x168e74u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 4));
    // 0x168e78: 0x81900  sll         $v1, $t0, 4
    ctx->pc = 0x168e78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x168e7c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x168e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x168e80: 0x8e45001c  lw          $a1, 0x1C($s2)
    ctx->pc = 0x168e80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x168e84: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x168e84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x168e88: 0x491025  or          $v0, $v0, $t1
    ctx->pc = 0x168e88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 9));
    // 0x168e8c: 0xae430014  sw          $v1, 0x14($s2)
    ctx->pc = 0x168e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 3));
    // 0x168e90: 0x14a0000c  bnez        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x168E90u;
    {
        const bool branch_taken_0x168e90 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x168E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168E90u;
            // 0x168e94: 0xae420018  sw          $v0, 0x18($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168e90) {
            ctx->pc = 0x168EC4u;
            goto label_168ec4;
        }
    }
    ctx->pc = 0x168E98u;
    // 0x168e98: 0xb1080  sll         $v0, $t3, 2
    ctx->pc = 0x168e98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 11), 2));
    // 0x168e9c: 0xa1a80  sll         $v1, $t2, 10
    ctx->pc = 0x168e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), 10));
    // 0x168ea0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x168ea0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x168ea4: 0x72182  srl         $a0, $a3, 6
    ctx->pc = 0x168ea4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 6));
    // 0x168ea8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x168ea8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x168eac: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x168eacu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x168eb0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x168eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x168eb4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x168eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x168eb8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x168eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x168ebc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x168ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x168ec0: 0xae42001c  sw          $v0, 0x1C($s2)
    ctx->pc = 0x168ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 2));
label_168ec4:
    // 0x168ec4: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x168ec4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x168ec8: 0x30e2001f  andi        $v0, $a3, 0x1F
    ctx->pc = 0x168ec8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)31);
    // 0x168ecc: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x168eccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x168ed0: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x168ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x168ed4: 0xc20c2  srl         $a0, $t4, 3
    ctx->pc = 0x168ed4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 12), 3));
    // 0x168ed8: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x168ed8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x168edc: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x168edcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x168ee0: 0xae540008  sw          $s4, 0x8($s2)
    ctx->pc = 0x168ee0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 20));
    // 0x168ee4: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x168ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x168ee8: 0xae450020  sw          $a1, 0x20($s2)
    ctx->pc = 0x168ee8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 5));
    // 0x168eec: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x168EECu;
    {
        const bool branch_taken_0x168eec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x168EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168EECu;
            // 0x168ef0: 0xae420024  sw          $v0, 0x24($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168eec) {
            ctx->pc = 0x168F00u;
            goto label_168f00;
        }
    }
    ctx->pc = 0x168EF4u;
    // 0x168ef4: 0x0  nop
    ctx->pc = 0x168ef4u;
    // NOP
label_168ef8:
    // 0x168ef8: 0x1e00ffc1  bgtz        $s0, . + 4 + (-0x3F << 2)
    ctx->pc = 0x168EF8u;
    {
        const bool branch_taken_0x168ef8 = (GPR_S64(ctx, 16) > 0);
        ctx->pc = 0x168EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168EF8u;
            // 0x168efc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168ef8) {
            ctx->pc = 0x168E00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_168e00;
        }
    }
    ctx->pc = 0x168F00u;
label_168f00:
    // 0x168f00: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x168f00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_168f04:
    // 0x168f04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x168f04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168f08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x168f08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x168f0c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x168f0cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x168f10: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x168f10u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168f14: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x168f14u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x168f18: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x168f18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x168f1c: 0x3e00008  jr          $ra
    ctx->pc = 0x168F1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168F1Cu;
            // 0x168f20: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168E00u: goto label_168e00;
            case 0x168E0Cu: goto label_168e0c;
            case 0x168EC4u: goto label_168ec4;
            case 0x168EF8u: goto label_168ef8;
            case 0x168F00u: goto label_168f00;
            case 0x168F04u: goto label_168f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168F24u;
    // 0x168f24: 0x0  nop
    ctx->pc = 0x168f24u;
    // NOP
    // 0x168f28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x168f28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x168f2c: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x168f2cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x168f30: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x168f30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x168f34: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x168f34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x168f38: 0x24a51808  addiu       $a1, $a1, 0x1808
    ctx->pc = 0x168f38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6152));
    // 0x168f3c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x168f3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168f40: 0x805e406  j           func_179018
    ctx->pc = 0x168F40u;
    ctx->pc = 0x168F44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168F40u;
            // 0x168f44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179018u;
    if (runtime->hasFunction(0x179018u)) {
        auto targetFn = runtime->lookupFunction(0x179018u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00179018_0x179018(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x168F48u;
    // 0x168f48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x168f48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x168f4c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x168f4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x168f50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x168f50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168f54: 0x805e42a  j           func_1790A8
    ctx->pc = 0x168F54u;
    ctx->pc = 0x168F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168F54u;
            // 0x168f58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1790A8u;
    if (runtime->hasFunction(0x1790A8u)) {
        auto targetFn = runtime->lookupFunction(0x1790A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001790A8_0x1790a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x168F5Cu;
    // 0x168f5c: 0x0  nop
    ctx->pc = 0x168f5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
