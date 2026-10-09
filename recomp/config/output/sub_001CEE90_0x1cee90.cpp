#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CEE90
// Address: 0x1cee90 - 0x1cef00
void sub_001CEE90_0x1cee90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CEE90_0x1cee90");
#endif

    switch (ctx->pc) {
        case 0x1ceea8u: goto label_1ceea8;
        default: break;
    }

    ctx->pc = 0x1cee90u;

    // 0x1cee90: 0x308600ff  andi        $a2, $a0, 0xFF
    ctx->pc = 0x1cee90u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1cee94: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cee94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cee98: 0x30a4ffff  andi        $a0, $a1, 0xFFFF
    ctx->pc = 0x1cee98u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1cee9c: 0x24421430  addiu       $v0, $v0, 0x1430
    ctx->pc = 0x1cee9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5168));
    // 0x1ceea0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1CEEA0u;
    {
        const bool branch_taken_0x1ceea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEEA0u;
            // 0x1ceea4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceea0) {
            ctx->pc = 0x1CEEDCu;
            goto label_1ceedc;
        }
    }
    ctx->pc = 0x1CEEA8u;
label_1ceea8:
    // 0x1ceea8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1ceea8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ceeac: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CEEACu;
    {
        const bool branch_taken_0x1ceeac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ceeac) {
            ctx->pc = 0x1CEED4u;
            goto label_1ceed4;
        }
    }
    ctx->pc = 0x1CEEB4u;
    // 0x1ceeb4: 0x90430008  lbu         $v1, 0x8($v0)
    ctx->pc = 0x1ceeb4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1ceeb8: 0x14660006  bne         $v1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CEEB8u;
    {
        const bool branch_taken_0x1ceeb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        if (branch_taken_0x1ceeb8) {
            ctx->pc = 0x1CEED4u;
            goto label_1ceed4;
        }
    }
    ctx->pc = 0x1CEEC0u;
    // 0x1ceec0: 0x9443000a  lhu         $v1, 0xA($v0)
    ctx->pc = 0x1ceec0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 10)));
    // 0x1ceec4: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CEEC4u;
    {
        const bool branch_taken_0x1ceec4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1ceec4) {
            ctx->pc = 0x1CEED4u;
            goto label_1ceed4;
        }
    }
    ctx->pc = 0x1CEECCu;
    // 0x1ceecc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CEECCu;
    {
        const bool branch_taken_0x1ceecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ceecc) {
            ctx->pc = 0x1CEEECu;
            goto label_1ceeec;
        }
    }
    ctx->pc = 0x1CEED4u;
label_1ceed4:
    // 0x1ceed4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1ceed4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1ceed8: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1ceed8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_1ceedc:
    // 0x1ceedc: 0x28a30010  slti        $v1, $a1, 0x10
    ctx->pc = 0x1ceedcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1ceee0: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1CEEE0u;
    {
        const bool branch_taken_0x1ceee0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ceee0) {
            ctx->pc = 0x1CEEA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ceea8;
        }
    }
    ctx->pc = 0x1CEEE8u;
    // 0x1ceee8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ceee8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ceeec:
    // 0x1ceeec: 0x3e00008  jr          $ra
    ctx->pc = 0x1CEEECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CEEA8u: goto label_1ceea8;
            case 0x1CEED4u: goto label_1ceed4;
            case 0x1CEEDCu: goto label_1ceedc;
            case 0x1CEEECu: goto label_1ceeec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CEEF4u;
    // 0x1ceef4: 0x0  nop
    ctx->pc = 0x1ceef4u;
    // NOP
    // 0x1ceef8: 0x0  nop
    ctx->pc = 0x1ceef8u;
    // NOP
    // 0x1ceefc: 0x0  nop
    ctx->pc = 0x1ceefcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
