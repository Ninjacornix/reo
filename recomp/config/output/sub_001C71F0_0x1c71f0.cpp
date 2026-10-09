#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C71F0
// Address: 0x1c71f0 - 0x1c7250
void sub_001C71F0_0x1c71f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C71F0_0x1c71f0");
#endif

    switch (ctx->pc) {
        case 0x1c7208u: goto label_1c7208;
        default: break;
    }

    ctx->pc = 0x1c71f0u;

    // 0x1c71f0: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c71f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c71f4: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c71f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c71f8: 0x90255055  lbu         $a1, 0x5055($at)
    ctx->pc = 0x1c71f8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20565)));
    // 0x1c71fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c71fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7200: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C7200u;
    {
        const bool branch_taken_0x1c7200 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7200u;
            // 0x1c7204: 0x24845050  addiu       $a0, $a0, 0x5050 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20560));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7200) {
            ctx->pc = 0x1C722Cu;
            goto label_1c722c;
        }
    }
    ctx->pc = 0x1C7208u;
label_1c7208:
    // 0x1c7208: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1c7208u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c720c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c720cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c7210: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1c7210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1c7214: 0x9063004c  lbu         $v1, 0x4C($v1)
    ctx->pc = 0x1c7214u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 76)));
    // 0x1c7218: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7218u;
    {
        const bool branch_taken_0x1c7218 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7218) {
            ctx->pc = 0x1C7228u;
            goto label_1c7228;
        }
    }
    ctx->pc = 0x1C7220u;
    // 0x1c7220: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C7220u;
    {
        const bool branch_taken_0x1c7220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7220) {
            ctx->pc = 0x1C723Cu;
            goto label_1c723c;
        }
    }
    ctx->pc = 0x1C7228u;
label_1c7228:
    // 0x1c7228: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c7228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1c722c:
    // 0x1c722c: 0x45182a  slt         $v1, $v0, $a1
    ctx->pc = 0x1c722cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1c7230: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x1C7230u;
    {
        const bool branch_taken_0x1c7230 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7230u;
            // 0x1c7234: 0x21900  sll         $v1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7230) {
            ctx->pc = 0x1C7208u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c7208;
        }
    }
    ctx->pc = 0x1C7238u;
    // 0x1c7238: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c7238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1c723c:
    // 0x1c723c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C723Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7208u: goto label_1c7208;
            case 0x1C7228u: goto label_1c7228;
            case 0x1C722Cu: goto label_1c722c;
            case 0x1C723Cu: goto label_1c723c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7244u;
    // 0x1c7244: 0x0  nop
    ctx->pc = 0x1c7244u;
    // NOP
    // 0x1c7248: 0x0  nop
    ctx->pc = 0x1c7248u;
    // NOP
    // 0x1c724c: 0x0  nop
    ctx->pc = 0x1c724cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
