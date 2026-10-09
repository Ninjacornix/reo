#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF840
// Address: 0x1cf840 - 0x1cf890
void sub_001CF840_0x1cf840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF840_0x1cf840");
#endif

    switch (ctx->pc) {
        case 0x1cf850u: goto label_1cf850;
        default: break;
    }

    ctx->pc = 0x1cf840u;

    // 0x1cf840: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cf840u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cf844: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cf844u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf848: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1CF848u;
    {
        const bool branch_taken_0x1cf848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF84Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF848u;
            // 0x1cf84c: 0x244213f0  addiu       $v0, $v0, 0x13F0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf848) {
            ctx->pc = 0x1CF86Cu;
            goto label_1cf86c;
        }
    }
    ctx->pc = 0x1CF850u;
label_1cf850:
    // 0x1cf850: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1cf850u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cf854: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF854u;
    {
        const bool branch_taken_0x1cf854 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf854) {
            ctx->pc = 0x1CF864u;
            goto label_1cf864;
        }
    }
    ctx->pc = 0x1CF85Cu;
    // 0x1cf85c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CF85Cu;
    {
        const bool branch_taken_0x1cf85c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf85c) {
            ctx->pc = 0x1CF87Cu;
            goto label_1cf87c;
        }
    }
    ctx->pc = 0x1CF864u;
label_1cf864:
    // 0x1cf864: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1cf864u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1cf868: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1cf868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
label_1cf86c:
    // 0x1cf86c: 0x28830004  slti        $v1, $a0, 0x4
    ctx->pc = 0x1cf86cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1cf870: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1CF870u;
    {
        const bool branch_taken_0x1cf870 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf870) {
            ctx->pc = 0x1CF850u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf850;
        }
    }
    ctx->pc = 0x1CF878u;
    // 0x1cf878: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cf878u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cf87c:
    // 0x1cf87c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF87Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF850u: goto label_1cf850;
            case 0x1CF864u: goto label_1cf864;
            case 0x1CF86Cu: goto label_1cf86c;
            case 0x1CF87Cu: goto label_1cf87c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF884u;
    // 0x1cf884: 0x0  nop
    ctx->pc = 0x1cf884u;
    // NOP
    // 0x1cf888: 0x0  nop
    ctx->pc = 0x1cf888u;
    // NOP
    // 0x1cf88c: 0x0  nop
    ctx->pc = 0x1cf88cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
