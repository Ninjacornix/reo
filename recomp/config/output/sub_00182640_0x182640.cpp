#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182640
// Address: 0x182640 - 0x182688
void sub_00182640_0x182640(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182640_0x182640");
#endif

    switch (ctx->pc) {
        case 0x182658u: goto label_182658;
        default: break;
    }

    ctx->pc = 0x182640u;

    // 0x182640: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x182640u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182644: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x182644u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182648: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x182648u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x18264c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x18264Cu;
    {
        const bool branch_taken_0x18264c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18264Cu;
            // 0x182650: 0x90a30000  lbu         $v1, 0x0($a1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18264c) {
            ctx->pc = 0x18267Cu;
            goto label_18267c;
        }
    }
    ctx->pc = 0x182654u;
    // 0x182654: 0x2407002f  addiu       $a3, $zero, 0x2F
    ctx->pc = 0x182654u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
label_182658:
    // 0x182658: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x182658u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x18265c: 0x24c30001  addiu       $v1, $a2, 0x1
    ctx->pc = 0x18265cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x182660: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x182660u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x182664: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x182664u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x182668: 0x80a40000  lb          $a0, 0x0($a1)
    ctx->pc = 0x182668u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x18266c: 0x471026  xor         $v0, $v0, $a3
    ctx->pc = 0x18266cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 7));
    // 0x182670: 0x62300a  movz        $a2, $v1, $v0
    ctx->pc = 0x182670u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x182674: 0x1480fff8  bnez        $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x182674u;
    {
        const bool branch_taken_0x182674 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x182678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182674u;
            // 0x182678: 0x90a30000  lbu         $v1, 0x0($a1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182674) {
            ctx->pc = 0x182658u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182658;
        }
    }
    ctx->pc = 0x18267Cu;
label_18267c:
    // 0x18267c: 0x3e00008  jr          $ra
    ctx->pc = 0x18267Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18267Cu;
            // 0x182680: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182658u: goto label_182658;
            case 0x18267Cu: goto label_18267c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182684u;
    // 0x182684: 0x0  nop
    ctx->pc = 0x182684u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
