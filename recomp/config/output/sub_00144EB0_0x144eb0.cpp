#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00144EB0
// Address: 0x144eb0 - 0x144f38
void sub_00144EB0_0x144eb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00144EB0_0x144eb0");
#endif

    ctx->pc = 0x144eb0u;

    // 0x144eb0: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x144eb0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144eb4: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x144eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x144eb8: 0x8d440000  lw          $a0, 0x0($t2)
    ctx->pc = 0x144eb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x144ebc: 0xa24804  sllv        $t1, $v0, $a1
    ctx->pc = 0x144ebcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x144ec0: 0x41843  sra         $v1, $a0, 1
    ctx->pc = 0x144ec0u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 1));
    // 0x144ec4: 0x18c0000c  blez        $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x144EC4u;
    {
        const bool branch_taken_0x144ec4 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x144EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144EC4u;
            // 0x144ec8: 0x68200b  movn        $a0, $v1, $t0 (Delay Slot)
        if (GPR_U64(ctx, 8) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ec4) {
            ctx->pc = 0x144EF8u;
            goto label_144ef8;
        }
    }
    ctx->pc = 0x144ECCu;
    // 0x144ecc: 0x24c2ffff  addiu       $v0, $a2, -0x1
    ctx->pc = 0x144eccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x144ed0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x144ed0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x144ed4: 0xa21004  sllv        $v0, $v0, $a1
    ctx->pc = 0x144ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x144ed8: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x144ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x144edc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x144edcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x144ee0: 0x89182a  slt         $v1, $a0, $t1
    ctx->pc = 0x144ee0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x144ee4: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x144EE4u;
    {
        const bool branch_taken_0x144ee4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x144EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144EE4u;
            // 0x144ee8: 0x41040  sll         $v0, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ee4) {
            ctx->pc = 0x144F2Cu;
            goto label_144f2c;
        }
    }
    ctx->pc = 0x144EECu;
    // 0x144eec: 0x91040  sll         $v0, $t1, 1
    ctx->pc = 0x144eecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x144ef0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x144EF0u;
    {
        const bool branch_taken_0x144ef0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144EF0u;
            // 0x144ef4: 0x822023  subu        $a0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ef0) {
            ctx->pc = 0x144F28u;
            goto label_144f28;
        }
    }
    ctx->pc = 0x144EF8u;
label_144ef8:
    // 0x144ef8: 0x4c1000c  bgez        $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x144EF8u;
    {
        const bool branch_taken_0x144ef8 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x144EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144EF8u;
            // 0x144efc: 0x41040  sll         $v0, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ef8) {
            ctx->pc = 0x144F2Cu;
            goto label_144f2c;
        }
    }
    ctx->pc = 0x144F00u;
    // 0x144f00: 0x61027  nor         $v0, $zero, $a2
    ctx->pc = 0x144f00u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 6)));
    // 0x144f04: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x144f04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x144f08: 0xa21004  sllv        $v0, $v0, $a1
    ctx->pc = 0x144f08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x144f0c: 0x91823  negu        $v1, $t1
    ctx->pc = 0x144f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 9)));
    // 0x144f10: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x144f10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x144f14: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x144f14u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x144f18: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x144f18u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x144f1c: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x144F1Cu;
    {
        const bool branch_taken_0x144f1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x144F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144F1Cu;
            // 0x144f20: 0x91040  sll         $v0, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144f1c) {
            ctx->pc = 0x144F28u;
            goto label_144f28;
        }
    }
    ctx->pc = 0x144F24u;
    // 0x144f24: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x144f24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_144f28:
    // 0x144f28: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x144f28u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
label_144f2c:
    // 0x144f2c: 0x88100a  movz        $v0, $a0, $t0
    ctx->pc = 0x144f2cu;
    if (GPR_U64(ctx, 8) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x144f30: 0x3e00008  jr          $ra
    ctx->pc = 0x144F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x144F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144F30u;
            // 0x144f34: 0xad420000  sw          $v0, 0x0($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144EF8u: goto label_144ef8;
            case 0x144F28u: goto label_144f28;
            case 0x144F2Cu: goto label_144f2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144F38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
