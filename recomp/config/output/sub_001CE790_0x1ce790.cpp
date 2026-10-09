#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CE790
// Address: 0x1ce790 - 0x1ce800
void sub_001CE790_0x1ce790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CE790_0x1ce790");
#endif

    switch (ctx->pc) {
        case 0x1ce7a8u: goto label_1ce7a8;
        default: break;
    }

    ctx->pc = 0x1ce790u;

    // 0x1ce790: 0x308600ff  andi        $a2, $a0, 0xFF
    ctx->pc = 0x1ce790u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1ce794: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1ce794u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1ce798: 0x30a4ffff  andi        $a0, $a1, 0xFFFF
    ctx->pc = 0x1ce798u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1ce79c: 0x24421500  addiu       $v0, $v0, 0x1500
    ctx->pc = 0x1ce79cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5376));
    // 0x1ce7a0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1CE7A0u;
    {
        const bool branch_taken_0x1ce7a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE7A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE7A0u;
            // 0x1ce7a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce7a0) {
            ctx->pc = 0x1CE7DCu;
            goto label_1ce7dc;
        }
    }
    ctx->pc = 0x1CE7A8u;
label_1ce7a8:
    // 0x1ce7a8: 0x90430010  lbu         $v1, 0x10($v0)
    ctx->pc = 0x1ce7a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ce7ac: 0x14660009  bne         $v1, $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CE7ACu;
    {
        const bool branch_taken_0x1ce7ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        if (branch_taken_0x1ce7ac) {
            ctx->pc = 0x1CE7D4u;
            goto label_1ce7d4;
        }
    }
    ctx->pc = 0x1CE7B4u;
    // 0x1ce7b4: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1ce7b4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ce7b8: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CE7B8u;
    {
        const bool branch_taken_0x1ce7b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce7b8) {
            ctx->pc = 0x1CE7D4u;
            goto label_1ce7d4;
        }
    }
    ctx->pc = 0x1CE7C0u;
    // 0x1ce7c0: 0x94430012  lhu         $v1, 0x12($v0)
    ctx->pc = 0x1ce7c0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 18)));
    // 0x1ce7c4: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CE7C4u;
    {
        const bool branch_taken_0x1ce7c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1ce7c4) {
            ctx->pc = 0x1CE7D4u;
            goto label_1ce7d4;
        }
    }
    ctx->pc = 0x1CE7CCu;
    // 0x1ce7cc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CE7CCu;
    {
        const bool branch_taken_0x1ce7cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ce7cc) {
            ctx->pc = 0x1CE7ECu;
            goto label_1ce7ec;
        }
    }
    ctx->pc = 0x1CE7D4u;
label_1ce7d4:
    // 0x1ce7d4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1ce7d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1ce7d8: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1ce7d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
label_1ce7dc:
    // 0x1ce7dc: 0x28a30010  slti        $v1, $a1, 0x10
    ctx->pc = 0x1ce7dcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1ce7e0: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1CE7E0u;
    {
        const bool branch_taken_0x1ce7e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ce7e0) {
            ctx->pc = 0x1CE7A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ce7a8;
        }
    }
    ctx->pc = 0x1CE7E8u;
    // 0x1ce7e8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ce7e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ce7ec:
    // 0x1ce7ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1CE7ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CE7A8u: goto label_1ce7a8;
            case 0x1CE7D4u: goto label_1ce7d4;
            case 0x1CE7DCu: goto label_1ce7dc;
            case 0x1CE7ECu: goto label_1ce7ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CE7F4u;
    // 0x1ce7f4: 0x0  nop
    ctx->pc = 0x1ce7f4u;
    // NOP
    // 0x1ce7f8: 0x0  nop
    ctx->pc = 0x1ce7f8u;
    // NOP
    // 0x1ce7fc: 0x0  nop
    ctx->pc = 0x1ce7fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
