#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CEDF0
// Address: 0x1cedf0 - 0x1cee40
void sub_001CEDF0_0x1cedf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CEDF0_0x1cedf0");
#endif

    switch (ctx->pc) {
        case 0x1cee00u: goto label_1cee00;
        default: break;
    }

    ctx->pc = 0x1cedf0u;

    // 0x1cedf0: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cedf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cedf4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cedf4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cedf8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1CEDF8u;
    {
        const bool branch_taken_0x1cedf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEDFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEDF8u;
            // 0x1cedfc: 0x24421430  addiu       $v0, $v0, 0x1430 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5168));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cedf8) {
            ctx->pc = 0x1CEE1Cu;
            goto label_1cee1c;
        }
    }
    ctx->pc = 0x1CEE00u;
label_1cee00:
    // 0x1cee00: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1cee00u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cee04: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CEE04u;
    {
        const bool branch_taken_0x1cee04 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cee04) {
            ctx->pc = 0x1CEE14u;
            goto label_1cee14;
        }
    }
    ctx->pc = 0x1CEE0Cu;
    // 0x1cee0c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CEE0Cu;
    {
        const bool branch_taken_0x1cee0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cee0c) {
            ctx->pc = 0x1CEE2Cu;
            goto label_1cee2c;
        }
    }
    ctx->pc = 0x1CEE14u;
label_1cee14:
    // 0x1cee14: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1cee14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1cee18: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1cee18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_1cee1c:
    // 0x1cee1c: 0x28830010  slti        $v1, $a0, 0x10
    ctx->pc = 0x1cee1cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1cee20: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1CEE20u;
    {
        const bool branch_taken_0x1cee20 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cee20) {
            ctx->pc = 0x1CEE00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cee00;
        }
    }
    ctx->pc = 0x1CEE28u;
    // 0x1cee28: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cee28u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cee2c:
    // 0x1cee2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CEE2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CEE00u: goto label_1cee00;
            case 0x1CEE14u: goto label_1cee14;
            case 0x1CEE1Cu: goto label_1cee1c;
            case 0x1CEE2Cu: goto label_1cee2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CEE34u;
    // 0x1cee34: 0x0  nop
    ctx->pc = 0x1cee34u;
    // NOP
    // 0x1cee38: 0x0  nop
    ctx->pc = 0x1cee38u;
    // NOP
    // 0x1cee3c: 0x0  nop
    ctx->pc = 0x1cee3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
