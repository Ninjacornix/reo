#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171E68
// Address: 0x171e68 - 0x172000
void sub_00171E68_0x171e68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171E68_0x171e68");
#endif

    switch (ctx->pc) {
        case 0x171ee8u: goto label_171ee8;
        case 0x171fa8u: goto label_171fa8;
        case 0x171fdcu: goto label_171fdc;
        default: break;
    }

    ctx->pc = 0x171e68u;

    // 0x171e68: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x171e68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x171e6c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x171e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x171e70: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x171e70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x171e74: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x171e74u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171e78: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x171e78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x171e7c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x171e7cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171e80: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x171e80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x171e84: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x171e84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171e88: 0x8c831b30  lw          $v1, 0x1B30($a0)
    ctx->pc = 0x171e88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x171e8c: 0x247009d8  addiu       $s0, $v1, 0x9D8
    ctx->pc = 0x171e8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 2520));
    // 0x171e90: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x171e90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x171e94: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x171e94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x171e98: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x171e98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x171e9c: 0x92050010  lbu         $a1, 0x10($s0)
    ctx->pc = 0x171e9cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x171ea0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x171ea0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x171ea4: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x171ea4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x171ea8: 0xae040004  sw          $a0, 0x4($s0)
    ctx->pc = 0x171ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 4));
    // 0x171eac: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x171eacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x171eb0: 0xa3a50000  sb          $a1, 0x0($sp)
    ctx->pc = 0x171eb0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x171eb4: 0x92020011  lbu         $v0, 0x11($s0)
    ctx->pc = 0x171eb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 17)));
    // 0x171eb8: 0xa3a20001  sb          $v0, 0x1($sp)
    ctx->pc = 0x171eb8u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x171ebc: 0x92030012  lbu         $v1, 0x12($s0)
    ctx->pc = 0x171ebcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 18)));
    // 0x171ec0: 0xa3a30002  sb          $v1, 0x2($sp)
    ctx->pc = 0x171ec0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x171ec4: 0x92420000  lbu         $v0, 0x0($s2)
    ctx->pc = 0x171ec4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x171ec8: 0xa3a20003  sb          $v0, 0x3($sp)
    ctx->pc = 0x171ec8u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 3), (uint8_t)GPR_U32(ctx, 2));
    // 0x171ecc: 0x92430001  lbu         $v1, 0x1($s2)
    ctx->pc = 0x171eccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0x171ed0: 0xa3a30004  sb          $v1, 0x4($sp)
    ctx->pc = 0x171ed0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x171ed4: 0x92420002  lbu         $v0, 0x2($s2)
    ctx->pc = 0x171ed4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x171ed8: 0xa3a20005  sb          $v0, 0x5($sp)
    ctx->pc = 0x171ed8u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x171edc: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x171EDCu;
    {
        const bool branch_taken_0x171edc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171EE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171EDCu;
            // 0x171ee0: 0x2a270004  slti        $a3, $s1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x171edc) {
            ctx->pc = 0x171F3Cu;
            goto label_171f3c;
        }
    }
    ctx->pc = 0x171EE4u;
    // 0x171ee4: 0x0  nop
    ctx->pc = 0x171ee4u;
    // NOP
label_171ee8:
    // 0x171ee8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x171ee8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x171eec: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x171EECu;
    {
        const bool branch_taken_0x171eec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x171EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171EECu;
            // 0x171ef0: 0x24c50001  addiu       $a1, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171eec) {
            ctx->pc = 0x171F38u;
            goto label_171f38;
        }
    }
    ctx->pc = 0x171EF4u;
    // 0x171ef4: 0x3a51021  addu        $v0, $sp, $a1
    ctx->pc = 0x171ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 5)));
    // 0x171ef8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x171ef8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x171efc: 0x5460000f  bnel        $v1, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x171EFCu;
    {
        const bool branch_taken_0x171efc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x171efc) {
            ctx->pc = 0x171F00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171EFCu;
            // 0x171f00: 0xa0302d  daddu       $a2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171F3Cu;
            goto label_171f3c;
        }
    }
    ctx->pc = 0x171F04u;
    // 0x171f04: 0xdd1021  addu        $v0, $a2, $sp
    ctx->pc = 0x171f04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 29)));
    // 0x171f08: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x171f08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171f0c: 0x90430002  lbu         $v1, 0x2($v0)
    ctx->pc = 0x171f0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x171f10: 0x5464000a  bnel        $v1, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x171F10u;
    {
        const bool branch_taken_0x171f10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x171f10) {
            ctx->pc = 0x171F14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171F10u;
            // 0x171f14: 0xa0302d  daddu       $a2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171F3Cu;
            goto label_171f3c;
        }
    }
    ctx->pc = 0x171F18u;
    // 0x171f18: 0x90430003  lbu         $v1, 0x3($v0)
    ctx->pc = 0x171f18u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 3)));
    // 0x171f1c: 0x54600007  bnel        $v1, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x171F1Cu;
    {
        const bool branch_taken_0x171f1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x171f1c) {
            ctx->pc = 0x171F20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171F1Cu;
            // 0x171f20: 0xa0302d  daddu       $a2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171F3Cu;
            goto label_171f3c;
        }
    }
    ctx->pc = 0x171F24u;
    // 0x171f24: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x171f24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x171f28: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x171f28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x171f2c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x171F2Cu;
    {
        const bool branch_taken_0x171f2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171F2Cu;
            // 0x171f30: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171f2c) {
            ctx->pc = 0x171F50u;
            goto label_171f50;
        }
    }
    ctx->pc = 0x171F34u;
    // 0x171f34: 0x0  nop
    ctx->pc = 0x171f34u;
    // NOP
label_171f38:
    // 0x171f38: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x171f38u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_171f3c:
    // 0x171f3c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x171f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x171f40: 0x227100b  movn        $v0, $s1, $a3
    ctx->pc = 0x171f40u;
    if (GPR_U64(ctx, 7) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 17));
    // 0x171f44: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x171f44u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x171f48: 0x1440ffe7  bnez        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x171F48u;
    {
        const bool branch_taken_0x171f48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x171F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171F48u;
            // 0x171f4c: 0x3a61021  addu        $v0, $sp, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171f48) {
            ctx->pc = 0x171EE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_171ee8;
        }
    }
    ctx->pc = 0x171F50u;
label_171f50:
    // 0x171f50: 0x2a220003  slti        $v0, $s1, 0x3
    ctx->pc = 0x171f50u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x171f54: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x171F54u;
    {
        const bool branch_taken_0x171f54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x171F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171F54u;
            // 0x171f58: 0x2512021  addu        $a0, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171f54) {
            ctx->pc = 0x171F88u;
            goto label_171f88;
        }
    }
    ctx->pc = 0x171F5Cu;
    // 0x171f5c: 0x3b11021  addu        $v0, $sp, $s1
    ctx->pc = 0x171f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 17)));
    // 0x171f60: 0x23d2021  addu        $a0, $s1, $sp
    ctx->pc = 0x171f60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 29)));
    // 0x171f64: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x171f64u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x171f68: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x171f68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171f6c: 0xa2030010  sb          $v1, 0x10($s0)
    ctx->pc = 0x171f6cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 16), (uint8_t)GPR_U32(ctx, 3));
    // 0x171f70: 0x90820001  lbu         $v0, 0x1($a0)
    ctx->pc = 0x171f70u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x171f74: 0xa2020011  sb          $v0, 0x11($s0)
    ctx->pc = 0x171f74u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 17), (uint8_t)GPR_U32(ctx, 2));
    // 0x171f78: 0x90a30002  lbu         $v1, 0x2($a1)
    ctx->pc = 0x171f78u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x171f7c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x171F7Cu;
    {
        const bool branch_taken_0x171f7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171F7Cu;
            // 0x171f80: 0xa2030012  sb          $v1, 0x12($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 18), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171f7c) {
            ctx->pc = 0x171FC4u;
            goto label_171fc4;
        }
    }
    ctx->pc = 0x171F84u;
    // 0x171f84: 0x0  nop
    ctx->pc = 0x171f84u;
    // NOP
label_171f88:
    // 0x171f88: 0x9082fffd  lbu         $v0, -0x3($a0)
    ctx->pc = 0x171f88u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4294967293)));
    // 0x171f8c: 0xa2020010  sb          $v0, 0x10($s0)
    ctx->pc = 0x171f8cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x171f90: 0x9083fffe  lbu         $v1, -0x2($a0)
    ctx->pc = 0x171f90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4294967294)));
    // 0x171f94: 0xa2030011  sb          $v1, 0x11($s0)
    ctx->pc = 0x171f94u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 17), (uint8_t)GPR_U32(ctx, 3));
    // 0x171f98: 0x9082ffff  lbu         $v0, -0x1($a0)
    ctx->pc = 0x171f98u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4294967295)));
    // 0x171f9c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x171F9Cu;
    {
        const bool branch_taken_0x171f9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171F9Cu;
            // 0x171fa0: 0xa2020012  sb          $v0, 0x12($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 18), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171f9c) {
            ctx->pc = 0x171FC4u;
            goto label_171fc4;
        }
    }
    ctx->pc = 0x171FA4u;
    // 0x171fa4: 0x0  nop
    ctx->pc = 0x171fa4u;
    // NOP
label_171fa8:
    // 0x171fa8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x171fa8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x171fac: 0x921823  subu        $v1, $a0, $s2
    ctx->pc = 0x171facu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x171fb0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x171fb0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171fb4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x171fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x171fb8: 0x2238823  subu        $s1, $s1, $v1
    ctx->pc = 0x171fb8u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x171fbc: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x171fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x171fc0: 0x2a270004  slti        $a3, $s1, 0x4
    ctx->pc = 0x171fc0u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
label_171fc4:
    // 0x171fc4: 0x54e00009  bnel        $a3, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x171FC4u;
    {
        const bool branch_taken_0x171fc4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x171fc4) {
            ctx->pc = 0x171FC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171FC4u;
            // 0x171fc8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171FECu;
            goto label_171fec;
        }
    }
    ctx->pc = 0x171FCCu;
    // 0x171fcc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x171fccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171fd0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x171fd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171fd4: 0xc0561d4  jal         func_158750
    ctx->pc = 0x171FD4u;
    SET_GPR_U32(ctx, 31, 0x171FDCu);
    ctx->pc = 0x171FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171FD4u;
            // 0x171fd8: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171FDCu; }
        if (ctx->pc != 0x171FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171FDCu; }
        if (ctx->pc != 0x171FDCu) { return; }
    }
    ctx->pc = 0x171FDCu;
label_171fdc:
    // 0x171fdc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x171fdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171fe0: 0x5480fff1  bnel        $a0, $zero, . + 4 + (-0xF << 2)
    ctx->pc = 0x171FE0u;
    {
        const bool branch_taken_0x171fe0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x171fe0) {
            ctx->pc = 0x171FE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171FE0u;
            // 0x171fe4: 0x8e020008  lw          $v0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171FA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_171fa8;
        }
    }
    ctx->pc = 0x171FE8u;
    // 0x171fe8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x171fe8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_171fec:
    // 0x171fec: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x171fecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x171ff0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x171ff0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171ff4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x171ff4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171ff8: 0x3e00008  jr          $ra
    ctx->pc = 0x171FF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171FF8u;
            // 0x171ffc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171EE8u: goto label_171ee8;
            case 0x171F38u: goto label_171f38;
            case 0x171F3Cu: goto label_171f3c;
            case 0x171F50u: goto label_171f50;
            case 0x171F88u: goto label_171f88;
            case 0x171FA8u: goto label_171fa8;
            case 0x171FC4u: goto label_171fc4;
            case 0x171FDCu: goto label_171fdc;
            case 0x171FECu: goto label_171fec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172000u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
