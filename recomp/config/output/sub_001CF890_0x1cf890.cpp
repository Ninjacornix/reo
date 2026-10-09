#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF890
// Address: 0x1cf890 - 0x1cf900
void sub_001CF890_0x1cf890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF890_0x1cf890");
#endif

    switch (ctx->pc) {
        case 0x1cf8a8u: goto label_1cf8a8;
        default: break;
    }

    ctx->pc = 0x1cf890u;

    // 0x1cf890: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cf890u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cf894: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x1cf894u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1cf898: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1cf898u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1cf89c: 0x244213f0  addiu       $v0, $v0, 0x13F0
    ctx->pc = 0x1cf89cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5104));
    // 0x1cf8a0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1CF8A0u;
    {
        const bool branch_taken_0x1cf8a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF8A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF8A0u;
            // 0x1cf8a4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf8a0) {
            ctx->pc = 0x1CF8DCu;
            goto label_1cf8dc;
        }
    }
    ctx->pc = 0x1CF8A8u;
label_1cf8a8:
    // 0x1cf8a8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1cf8a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cf8ac: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CF8ACu;
    {
        const bool branch_taken_0x1cf8ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf8ac) {
            ctx->pc = 0x1CF8D4u;
            goto label_1cf8d4;
        }
    }
    ctx->pc = 0x1CF8B4u;
    // 0x1cf8b4: 0x9443000c  lhu         $v1, 0xC($v0)
    ctx->pc = 0x1cf8b4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1cf8b8: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CF8B8u;
    {
        const bool branch_taken_0x1cf8b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1cf8b8) {
            ctx->pc = 0x1CF8D4u;
            goto label_1cf8d4;
        }
    }
    ctx->pc = 0x1CF8C0u;
    // 0x1cf8c0: 0x94430008  lhu         $v1, 0x8($v0)
    ctx->pc = 0x1cf8c0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1cf8c4: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF8C4u;
    {
        const bool branch_taken_0x1cf8c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cf8c4) {
            ctx->pc = 0x1CF8D4u;
            goto label_1cf8d4;
        }
    }
    ctx->pc = 0x1CF8CCu;
    // 0x1cf8cc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CF8CCu;
    {
        const bool branch_taken_0x1cf8cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf8cc) {
            ctx->pc = 0x1CF8ECu;
            goto label_1cf8ec;
        }
    }
    ctx->pc = 0x1CF8D4u;
label_1cf8d4:
    // 0x1cf8d4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1cf8d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1cf8d8: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1cf8d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
label_1cf8dc:
    // 0x1cf8dc: 0x28c30004  slti        $v1, $a2, 0x4
    ctx->pc = 0x1cf8dcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1cf8e0: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1CF8E0u;
    {
        const bool branch_taken_0x1cf8e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf8e0) {
            ctx->pc = 0x1CF8A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf8a8;
        }
    }
    ctx->pc = 0x1CF8E8u;
    // 0x1cf8e8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cf8e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cf8ec:
    // 0x1cf8ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF8ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF8A8u: goto label_1cf8a8;
            case 0x1CF8D4u: goto label_1cf8d4;
            case 0x1CF8DCu: goto label_1cf8dc;
            case 0x1CF8ECu: goto label_1cf8ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF8F4u;
    // 0x1cf8f4: 0x0  nop
    ctx->pc = 0x1cf8f4u;
    // NOP
    // 0x1cf8f8: 0x0  nop
    ctx->pc = 0x1cf8f8u;
    // NOP
    // 0x1cf8fc: 0x0  nop
    ctx->pc = 0x1cf8fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
