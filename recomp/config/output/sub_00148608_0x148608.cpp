#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148608
// Address: 0x148608 - 0x148670
void sub_00148608_0x148608(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148608_0x148608");
#endif

    switch (ctx->pc) {
        case 0x148640u: goto label_148640;
        default: break;
    }

    ctx->pc = 0x148608u;

    // 0x148608: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x148608u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x14860c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x14860cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148610: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x148610u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x148614: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x148614u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148618: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14861c: 0x8e300040  lw          $s0, 0x40($s1)
    ctx->pc = 0x14861cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x148620: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x148620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x148624: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x148624u;
    {
        const bool branch_taken_0x148624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x148628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148624u;
            // 0x148628: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148624) {
            ctx->pc = 0x148658u;
            goto label_148658;
        }
    }
    ctx->pc = 0x14862Cu;
    // 0x14862c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x14862cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x148630: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x148630u;
    {
        const bool branch_taken_0x148630 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x148634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148630u;
            // 0x148634: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148630) {
            ctx->pc = 0x14865Cu;
            goto label_14865c;
        }
    }
    ctx->pc = 0x148638u;
    // 0x148638: 0xc0521a0  jal         func_148680
    ctx->pc = 0x148638u;
    SET_GPR_U32(ctx, 31, 0x148640u);
    ctx->pc = 0x14863Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148638u;
            // 0x14863c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148680u;
    if (runtime->hasFunction(0x148680u)) {
        auto targetFn = runtime->lookupFunction(0x148680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148640u; }
        if (ctx->pc != 0x148640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148680_0x148680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148640u; }
        if (ctx->pc != 0x148640u) { return; }
    }
    ctx->pc = 0x148640u;
label_148640:
    // 0x148640: 0x8e020130  lw          $v0, 0x130($s0)
    ctx->pc = 0x148640u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x148644: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x148644u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148648: 0x8e0300c4  lw          $v1, 0xC4($s0)
    ctx->pc = 0x148648u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 196)));
    // 0x14864c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x14864cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x148650: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x148650u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x148654: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x148654u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_148658:
    // 0x148658: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x148658u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_14865c:
    // 0x14865c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x14865cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148660: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x148660u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x148664: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x148664u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x148668: 0x3e00008  jr          $ra
    ctx->pc = 0x148668u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14866Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148668u;
            // 0x14866c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148640u: goto label_148640;
            case 0x148658u: goto label_148658;
            case 0x14865Cu: goto label_14865c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148670u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
