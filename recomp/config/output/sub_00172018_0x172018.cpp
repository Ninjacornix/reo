#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172018
// Address: 0x172018 - 0x172078
void sub_00172018_0x172018(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172018_0x172018");
#endif

    switch (ctx->pc) {
        case 0x17202cu: goto label_17202c;
        default: break;
    }

    ctx->pc = 0x172018u;

    // 0x172018: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17201c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17201cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172020: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x172020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x172024: 0xc05c54c  jal         func_171530
    ctx->pc = 0x172024u;
    SET_GPR_U32(ctx, 31, 0x17202Cu);
    ctx->pc = 0x172028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172024u;
            // 0x172028: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171530u;
    if (runtime->hasFunction(0x171530u)) {
        auto targetFn = runtime->lookupFunction(0x171530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17202Cu; }
        if (ctx->pc != 0x17202Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171530_0x171530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17202Cu; }
        if (ctx->pc != 0x17202Cu) { return; }
    }
    ctx->pc = 0x17202Cu;
label_17202c:
    // 0x17202c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17202Cu;
    {
        const bool branch_taken_0x17202c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17202Cu;
            // 0x172030: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17202c) {
            ctx->pc = 0x172040u;
            goto label_172040;
        }
    }
    ctx->pc = 0x172034u;
    // 0x172034: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x172034u;
    {
        const bool branch_taken_0x172034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172034u;
            // 0x172038: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172034) {
            ctx->pc = 0x172060u;
            goto label_172060;
        }
    }
    ctx->pc = 0x17203Cu;
    // 0x17203c: 0x0  nop
    ctx->pc = 0x17203cu;
    // NOP
label_172040:
    // 0x172040: 0x8e041b30  lw          $a0, 0x1B30($s0)
    ctx->pc = 0x172040u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
    // 0x172044: 0x248409d8  addiu       $a0, $a0, 0x9D8
    ctx->pc = 0x172044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2520));
    // 0x172048: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x172048u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x17204c: 0x10650004  beq         $v1, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17204Cu;
    {
        const bool branch_taken_0x17204c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x172050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17204Cu;
            // 0x172050: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17204c) {
            ctx->pc = 0x172060u;
            goto label_172060;
        }
    }
    ctx->pc = 0x172054u;
    // 0x172054: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x172054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x172058: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x172058u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x17205c: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x17205cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_172060:
    // 0x172060: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172060u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172064: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x172064u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172068: 0x3e00008  jr          $ra
    ctx->pc = 0x172068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17206Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172068u;
            // 0x17206c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17202Cu: goto label_17202c;
            case 0x172040u: goto label_172040;
            case 0x172060u: goto label_172060;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172070u;
    // 0x172070: 0x3e00008  jr          $ra
    ctx->pc = 0x172070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172070u;
            // 0x172074: 0x24020048  addiu       $v0, $zero, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17202Cu: goto label_17202c;
            case 0x172040u: goto label_172040;
            case 0x172060u: goto label_172060;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172078u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
