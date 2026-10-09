#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001801F0
// Address: 0x1801f0 - 0x180250
void sub_001801F0_0x1801f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001801F0_0x1801f0");
#endif

    switch (ctx->pc) {
        case 0x180210u: goto label_180210;
        case 0x18021cu: goto label_18021c;
        default: break;
    }

    ctx->pc = 0x1801f0u;

    // 0x1801f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1801f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1801f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1801f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1801f8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1801f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1801fc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1801fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180200: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x180200u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x180204: 0x91082b  sltu        $at, $a0, $s1
    ctx->pc = 0x180204u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x180208: 0x10200009  beqz        $at, . + 4 + (0x9 << 2)
    ctx->pc = 0x180208u;
    {
        const bool branch_taken_0x180208 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18020Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180208u;
            // 0x18020c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180208) {
            ctx->pc = 0x180230u;
            goto label_180230;
        }
    }
    ctx->pc = 0x180210u;
label_180210:
    // 0x180210: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x180210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x180214: 0x40f809  jalr        $v0
    ctx->pc = 0x180214u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x18021Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x18021Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180210u: goto label_180210;
            case 0x18021Cu: goto label_18021c;
            case 0x180230u: goto label_180230;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x18021Cu; }
            if (ctx->pc != 0x18021Cu) { return; }
        }
        }
    }
    ctx->pc = 0x18021Cu;
label_18021c:
    // 0x18021c: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x18021cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x180220: 0x211182b  sltu        $v1, $s0, $s1
    ctx->pc = 0x180220u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x180224: 0x0  nop
    ctx->pc = 0x180224u;
    // NOP
    // 0x180228: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x180228u;
    {
        const bool branch_taken_0x180228 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x180228) {
            ctx->pc = 0x180210u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_180210;
        }
    }
    ctx->pc = 0x180230u;
label_180230:
    // 0x180230: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x180230u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x180234: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x180234u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180238: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x180238u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18023c: 0x3e00008  jr          $ra
    ctx->pc = 0x18023Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18023Cu;
            // 0x180240: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180210u: goto label_180210;
            case 0x18021Cu: goto label_18021c;
            case 0x180230u: goto label_180230;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180244u;
    // 0x180244: 0x0  nop
    ctx->pc = 0x180244u;
    // NOP
    // 0x180248: 0x0  nop
    ctx->pc = 0x180248u;
    // NOP
    // 0x18024c: 0x0  nop
    ctx->pc = 0x18024cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
