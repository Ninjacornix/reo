#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174518
// Address: 0x174518 - 0x174580
void sub_00174518_0x174518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174518_0x174518");
#endif

    switch (ctx->pc) {
        case 0x174558u: goto label_174558;
        case 0x174564u: goto label_174564;
        default: break;
    }

    ctx->pc = 0x174518u;

    // 0x174518: 0x24830004  addiu       $v1, $a0, 0x4
    ctx->pc = 0x174518u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x17451c: 0x2405fffd  addiu       $a1, $zero, -0x3
    ctx->pc = 0x17451cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x174520: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x174520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x174524: 0xac650004  sw          $a1, 0x4($v1)
    ctx->pc = 0x174524u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 5));
    // 0x174528: 0xac620008  sw          $v0, 0x8($v1)
    ctx->pc = 0x174528u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x17452c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x17452cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x174530: 0x3e00008  jr          $ra
    ctx->pc = 0x174530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174530u;
            // 0x174534: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174558u: goto label_174558;
            case 0x174564u: goto label_174564;
            case 0x17456Cu: goto label_17456c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174538u;
    // 0x174538: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174538u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17453c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17453cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174540: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x174540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174544: 0x18a00009  blez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x174544u;
    {
        const bool branch_taken_0x174544 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x174548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174544u;
            // 0x174548: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174544) {
            ctx->pc = 0x17456Cu;
            goto label_17456c;
        }
    }
    ctx->pc = 0x17454Cu;
    // 0x17454c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17454cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174550: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x174550u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174554: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x174554u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_174558:
    // 0x174558: 0x26310dc4  addiu       $s1, $s1, 0xDC4
    ctx->pc = 0x174558u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 3524));
    // 0x17455c: 0xc05d160  jal         func_174580
    ctx->pc = 0x17455Cu;
    SET_GPR_U32(ctx, 31, 0x174564u);
    ctx->pc = 0x174560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17455Cu;
            // 0x174560: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174580u;
    if (runtime->hasFunction(0x174580u)) {
        auto targetFn = runtime->lookupFunction(0x174580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174564u; }
        if (ctx->pc != 0x174564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174580_0x174580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174564u; }
        if (ctx->pc != 0x174564u) { return; }
    }
    ctx->pc = 0x174564u;
label_174564:
    // 0x174564: 0x1600fffc  bnez        $s0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x174564u;
    {
        const bool branch_taken_0x174564 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x174568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174564u;
            // 0x174568: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174564) {
            ctx->pc = 0x174558u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_174558;
        }
    }
    ctx->pc = 0x17456Cu;
label_17456c:
    // 0x17456c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17456cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174570: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174570u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174574: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174574u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174578: 0x3e00008  jr          $ra
    ctx->pc = 0x174578u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17457Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174578u;
            // 0x17457c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174558u: goto label_174558;
            case 0x174564u: goto label_174564;
            case 0x17456Cu: goto label_17456c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174580u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
