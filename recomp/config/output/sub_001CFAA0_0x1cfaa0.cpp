#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CFAA0
// Address: 0x1cfaa0 - 0x1cfb20
void sub_001CFAA0_0x1cfaa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CFAA0_0x1cfaa0");
#endif

    switch (ctx->pc) {
        case 0x1cfab4u: goto label_1cfab4;
        case 0x1cfad4u: goto label_1cfad4;
        default: break;
    }

    ctx->pc = 0x1cfaa0u;

    // 0x1cfaa0: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1cfaa0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1cfaa4: 0x3083ffff  andi        $v1, $a0, 0xFFFF
    ctx->pc = 0x1cfaa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1cfaa8: 0x24e713f0  addiu       $a3, $a3, 0x13F0
    ctx->pc = 0x1cfaa8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 5104));
    // 0x1cfaac: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1CFAACu;
    {
        const bool branch_taken_0x1cfaac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFAB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFAACu;
            // 0x1cfab0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfaac) {
            ctx->pc = 0x1CFB0Cu;
            goto label_1cfb0c;
        }
    }
    ctx->pc = 0x1CFAB4u;
label_1cfab4:
    // 0x1cfab4: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x1cfab4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1cfab8: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CFAB8u;
    {
        const bool branch_taken_0x1cfab8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cfab8) {
            ctx->pc = 0x1CFB04u;
            goto label_1cfb04;
        }
    }
    ctx->pc = 0x1CFAC0u;
    // 0x1cfac0: 0x8ce60004  lw          $a2, 0x4($a3)
    ctx->pc = 0x1cfac0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1cfac4: 0x10c0000f  beqz        $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x1CFAC4u;
    {
        const bool branch_taken_0x1cfac4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFAC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFAC4u;
            // 0x1cfac8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfac4) {
            ctx->pc = 0x1CFB04u;
            goto label_1cfb04;
        }
    }
    ctx->pc = 0x1CFACCu;
    // 0x1cfacc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CFACCu;
    {
        const bool branch_taken_0x1cfacc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFACCu;
            // 0x1cfad0: 0x28820640  slti        $v0, $a0, 0x640 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)1600) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfacc) {
            ctx->pc = 0x1CFAFCu;
            goto label_1cfafc;
        }
    }
    ctx->pc = 0x1CFAD4u;
label_1cfad4:
    // 0x1cfad4: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1cfad4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1cfad8: 0x94420004  lhu         $v0, 0x4($v0)
    ctx->pc = 0x1cfad8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1cfadc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CFADCu;
    {
        const bool branch_taken_0x1cfadc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cfadc) {
            ctx->pc = 0x1CFAF4u;
            goto label_1cfaf4;
        }
    }
    ctx->pc = 0x1CFAE4u;
    // 0x1cfae4: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CFAE4u;
    {
        const bool branch_taken_0x1cfae4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1cfae4) {
            ctx->pc = 0x1CFAF4u;
            goto label_1cfaf4;
        }
    }
    ctx->pc = 0x1CFAECu;
    // 0x1cfaec: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1CFAECu;
    {
        const bool branch_taken_0x1cfaec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CFAF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFAECu;
            // 0x1cfaf0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfaec) {
            ctx->pc = 0x1CFB18u;
            goto label_1cfb18;
        }
    }
    ctx->pc = 0x1CFAF4u;
label_1cfaf4:
    // 0x1cfaf4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1cfaf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1cfaf8: 0x28820640  slti        $v0, $a0, 0x640
    ctx->pc = 0x1cfaf8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)1600) ? 1 : 0);
label_1cfafc:
    // 0x1cfafc: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1CFAFCu;
    {
        const bool branch_taken_0x1cfafc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFB00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFAFCu;
            // 0x1cfb00: 0x41040  sll         $v0, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfafc) {
            ctx->pc = 0x1CFAD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfad4;
        }
    }
    ctx->pc = 0x1CFB04u;
label_1cfb04:
    // 0x1cfb04: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cfb04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cfb08: 0x24e70010  addiu       $a3, $a3, 0x10
    ctx->pc = 0x1cfb08u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
label_1cfb0c:
    // 0x1cfb0c: 0x28a20004  slti        $v0, $a1, 0x4
    ctx->pc = 0x1cfb0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1cfb10: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1CFB10u;
    {
        const bool branch_taken_0x1cfb10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CFB14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CFB10u;
            // 0x1cfb14: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cfb10) {
            ctx->pc = 0x1CFAB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cfab4;
        }
    }
    ctx->pc = 0x1CFB18u;
label_1cfb18:
    // 0x1cfb18: 0x3e00008  jr          $ra
    ctx->pc = 0x1CFB18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CFAB4u: goto label_1cfab4;
            case 0x1CFAD4u: goto label_1cfad4;
            case 0x1CFAF4u: goto label_1cfaf4;
            case 0x1CFAFCu: goto label_1cfafc;
            case 0x1CFB04u: goto label_1cfb04;
            case 0x1CFB0Cu: goto label_1cfb0c;
            case 0x1CFB18u: goto label_1cfb18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CFB20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
