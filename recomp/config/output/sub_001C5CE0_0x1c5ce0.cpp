#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5CE0
// Address: 0x1c5ce0 - 0x1c5d70
void sub_001C5CE0_0x1c5ce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5CE0_0x1c5ce0");
#endif

    switch (ctx->pc) {
        case 0x1c5d04u: goto label_1c5d04;
        default: break;
    }

    ctx->pc = 0x1c5ce0u;

    // 0x1c5ce0: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1c5ce0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c5ce4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1c5ce4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5ce8: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x1c5ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x1c5cec: 0x90830008  lbu         $v1, 0x8($a0)
    ctx->pc = 0x1c5cecu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1c5cf0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c5cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c5cf4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1c5cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1c5cf8: 0x8c63fffc  lw          $v1, -0x4($v1)
    ctx->pc = 0x1c5cf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294967292)));
    // 0x1c5cfc: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1C5CFCu;
    {
        const bool branch_taken_0x1c5cfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5CFCu;
            // 0x1c5d00: 0xac830004  sw          $v1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5cfc) {
            ctx->pc = 0x1C5D4Cu;
            goto label_1c5d4c;
        }
    }
    ctx->pc = 0x1C5D04u;
label_1c5d04:
    // 0x1c5d04: 0x2523ffff  addiu       $v1, $t1, -0x1
    ctx->pc = 0x1c5d04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x1c5d08: 0xa63821  addu        $a3, $a1, $a2
    ctx->pc = 0x1c5d08u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1c5d0c: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5D0Cu;
    {
        const bool branch_taken_0x1c5d0c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1C5D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5D0Cu;
            // 0x1c5d10: 0x8ce80000  lw          $t0, 0x0($a3) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5d0c) {
            ctx->pc = 0x1C5D1Cu;
            goto label_1c5d1c;
        }
    }
    ctx->pc = 0x1C5D14u;
    // 0x1c5d14: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5D14u;
    {
        const bool branch_taken_0x1c5d14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5D14u;
            // 0x1c5d18: 0xad000000  sw          $zero, 0x0($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5d14) {
            ctx->pc = 0x1C5D24u;
            goto label_1c5d24;
        }
    }
    ctx->pc = 0x1C5D1Cu;
label_1c5d1c:
    // 0x1c5d1c: 0x8ce3fffc  lw          $v1, -0x4($a3)
    ctx->pc = 0x1c5d1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4294967292)));
    // 0x1c5d20: 0xad030000  sw          $v1, 0x0($t0)
    ctx->pc = 0x1c5d20u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 3));
label_1c5d24:
    // 0x1c5d24: 0x90830008  lbu         $v1, 0x8($a0)
    ctx->pc = 0x1c5d24u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1c5d28: 0x25260001  addiu       $a2, $t1, 0x1
    ctx->pc = 0x1c5d28u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1c5d2c: 0xc3082a  slt         $at, $a2, $v1
    ctx->pc = 0x1c5d2cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c5d30: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5D30u;
    {
        const bool branch_taken_0x1c5d30 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5d30) {
            ctx->pc = 0x1C5D44u;
            goto label_1c5d44;
        }
    }
    ctx->pc = 0x1C5D38u;
    // 0x1c5d38: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x1c5d38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1c5d3c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C5D3Cu;
    {
        const bool branch_taken_0x1c5d3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5D3Cu;
            // 0x1c5d40: 0xad030004  sw          $v1, 0x4($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5d3c) {
            ctx->pc = 0x1C5D48u;
            goto label_1c5d48;
        }
    }
    ctx->pc = 0x1C5D44u;
label_1c5d44:
    // 0x1c5d44: 0xad000004  sw          $zero, 0x4($t0)
    ctx->pc = 0x1c5d44u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 0));
label_1c5d48:
    // 0x1c5d48: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1c5d48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
label_1c5d4c:
    // 0x1c5d4c: 0x90830008  lbu         $v1, 0x8($a0)
    ctx->pc = 0x1c5d4cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1c5d50: 0x123182a  slt         $v1, $t1, $v1
    ctx->pc = 0x1c5d50u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c5d54: 0x1460ffeb  bnez        $v1, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1C5D54u;
    {
        const bool branch_taken_0x1c5d54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5D54u;
            // 0x1c5d58: 0x93080  sll         $a2, $t1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5d54) {
            ctx->pc = 0x1C5D04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5d04;
        }
    }
    ctx->pc = 0x1C5D5Cu;
    // 0x1c5d5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5D5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5D04u: goto label_1c5d04;
            case 0x1C5D1Cu: goto label_1c5d1c;
            case 0x1C5D24u: goto label_1c5d24;
            case 0x1C5D44u: goto label_1c5d44;
            case 0x1C5D48u: goto label_1c5d48;
            case 0x1C5D4Cu: goto label_1c5d4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5D64u;
    // 0x1c5d64: 0x0  nop
    ctx->pc = 0x1c5d64u;
    // NOP
    // 0x1c5d68: 0x0  nop
    ctx->pc = 0x1c5d68u;
    // NOP
    // 0x1c5d6c: 0x0  nop
    ctx->pc = 0x1c5d6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
