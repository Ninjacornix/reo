#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF7E0
// Address: 0x1cf7e0 - 0x1cf840
void sub_001CF7E0_0x1cf7e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF7E0_0x1cf7e0");
#endif

    switch (ctx->pc) {
        case 0x1cf7fcu: goto label_1cf7fc;
        case 0x1cf814u: goto label_1cf814;
        default: break;
    }

    ctx->pc = 0x1cf7e0u;

    // 0x1cf7e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cf7e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cf7e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cf7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cf7e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cf7e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cf7ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cf7ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cf7f0: 0x3c110034  lui         $s1, 0x34
    ctx->pc = 0x1cf7f0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)52 << 16));
    // 0x1cf7f4: 0x263113f0  addiu       $s1, $s1, 0x13F0
    ctx->pc = 0x1cf7f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 5104));
    // 0x1cf7f8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1cf7f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cf7fc:
    // 0x1cf7fc: 0x92230000  lbu         $v1, 0x0($s1)
    ctx->pc = 0x1cf7fcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cf800: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CF800u;
    {
        const bool branch_taken_0x1cf800 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf800) {
            ctx->pc = 0x1CF814u;
            goto label_1cf814;
        }
    }
    ctx->pc = 0x1CF808u;
    // 0x1cf808: 0x9625000c  lhu         $a1, 0xC($s1)
    ctx->pc = 0x1cf808u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1cf80c: 0xc073dd0  jal         func_1CF740
    ctx->pc = 0x1CF80Cu;
    SET_GPR_U32(ctx, 31, 0x1CF814u);
    ctx->pc = 0x1CF810u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF80Cu;
            // 0x1cf810: 0x96240008  lhu         $a0, 0x8($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF740u;
    if (runtime->hasFunction(0x1CF740u)) {
        auto targetFn = runtime->lookupFunction(0x1CF740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF814u; }
        if (ctx->pc != 0x1CF814u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF740_0x1cf740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF814u; }
        if (ctx->pc != 0x1CF814u) { return; }
    }
    ctx->pc = 0x1CF814u;
label_1cf814:
    // 0x1cf814: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cf814u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cf818: 0x2a030004  slti        $v1, $s0, 0x4
    ctx->pc = 0x1cf818u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1cf81c: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1CF81Cu;
    {
        const bool branch_taken_0x1cf81c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF81Cu;
            // 0x1cf820: 0x26310010  addiu       $s1, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf81c) {
            ctx->pc = 0x1CF7FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf7fc;
        }
    }
    ctx->pc = 0x1CF824u;
    // 0x1cf824: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cf824u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cf828: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cf828u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cf82c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cf82cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf830: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF830u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF830u;
            // 0x1cf834: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF7FCu: goto label_1cf7fc;
            case 0x1CF814u: goto label_1cf814;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF838u;
    // 0x1cf838: 0x0  nop
    ctx->pc = 0x1cf838u;
    // NOP
    // 0x1cf83c: 0x0  nop
    ctx->pc = 0x1cf83cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
