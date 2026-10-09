#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2CF0
// Address: 0x1a2cf0 - 0x1a2d70
void sub_001A2CF0_0x1a2cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2CF0_0x1a2cf0");
#endif

    switch (ctx->pc) {
        case 0x1a2d00u: goto label_1a2d00;
        case 0x1a2d1cu: goto label_1a2d1c;
        default: break;
    }

    ctx->pc = 0x1a2cf0u;

    // 0x1a2cf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a2cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a2cf4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a2cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a2cf8: 0xc068b20  jal         func_1A2C80
    ctx->pc = 0x1A2CF8u;
    SET_GPR_U32(ctx, 31, 0x1A2D00u);
    ctx->pc = 0x1A2CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2CF8u;
            // 0x1a2cfc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2C80u;
    if (runtime->hasFunction(0x1A2C80u)) {
        auto targetFn = runtime->lookupFunction(0x1A2C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2D00u; }
        if (ctx->pc != 0x1A2D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2C80_0x1a2c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2D00u; }
        if (ctx->pc != 0x1A2D00u) { return; }
    }
    ctx->pc = 0x1A2D00u;
label_1a2d00:
    // 0x1a2d00: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a2d00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a2d04: 0xa3082b  sltu        $at, $a1, $v1
    ctx->pc = 0x1a2d04u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a2d08: 0x10200012  beqz        $at, . + 4 + (0x12 << 2)
    ctx->pc = 0x1A2D08u;
    {
        const bool branch_taken_0x1a2d08 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2d08) {
            ctx->pc = 0x1A2D54u;
            goto label_1a2d54;
        }
    }
    ctx->pc = 0x1A2D10u;
    // 0x1a2d10: 0x2484000c  addiu       $a0, $a0, 0xC
    ctx->pc = 0x1a2d10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1a2d14: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A2D14u;
    {
        const bool branch_taken_0x1a2d14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2D14u;
            // 0x1a2d18: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2d14) {
            ctx->pc = 0x1A2D48u;
            goto label_1a2d48;
        }
    }
    ctx->pc = 0x1A2D1Cu;
label_1a2d1c:
    // 0x1a2d1c: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x1a2d1cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a2d20: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A2D20u;
    {
        const bool branch_taken_0x1a2d20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2d20) {
            ctx->pc = 0x1A2D3Cu;
            goto label_1a2d3c;
        }
    }
    ctx->pc = 0x1A2D28u;
    // 0x1a2d28: 0x14e50003  bne         $a3, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2D28u;
    {
        const bool branch_taken_0x1a2d28 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A2D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2D28u;
            // 0x1a2d2c: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2d28) {
            ctx->pc = 0x1A2D38u;
            goto label_1a2d38;
        }
    }
    ctx->pc = 0x1A2D30u;
    // 0x1a2d30: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A2D30u;
    {
        const bool branch_taken_0x1a2d30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2D30u;
            // 0x1a2d34: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2d30) {
            ctx->pc = 0x1A2D5Cu;
            goto label_1a2d5c;
        }
    }
    ctx->pc = 0x1A2D38u;
label_1a2d38:
    // 0x1a2d38: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1a2d38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1a2d3c:
    // 0x1a2d3c: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a2d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a2d40: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a2d40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a2d44: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a2d44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a2d48:
    // 0x1a2d48: 0xc3102b  sltu        $v0, $a2, $v1
    ctx->pc = 0x1a2d48u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a2d4c: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A2D4Cu;
    {
        const bool branch_taken_0x1a2d4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a2d4c) {
            ctx->pc = 0x1A2D1Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2d1c;
        }
    }
    ctx->pc = 0x1A2D54u;
label_1a2d54:
    // 0x1a2d54: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a2d54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2d58: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a2d58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a2d5c:
    // 0x1a2d5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2D5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2D5Cu;
            // 0x1a2d60: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2D00u: goto label_1a2d00;
            case 0x1A2D1Cu: goto label_1a2d1c;
            case 0x1A2D38u: goto label_1a2d38;
            case 0x1A2D3Cu: goto label_1a2d3c;
            case 0x1A2D48u: goto label_1a2d48;
            case 0x1A2D54u: goto label_1a2d54;
            case 0x1A2D5Cu: goto label_1a2d5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2D64u;
    // 0x1a2d64: 0x0  nop
    ctx->pc = 0x1a2d64u;
    // NOP
    // 0x1a2d68: 0x0  nop
    ctx->pc = 0x1a2d68u;
    // NOP
    // 0x1a2d6c: 0x0  nop
    ctx->pc = 0x1a2d6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
