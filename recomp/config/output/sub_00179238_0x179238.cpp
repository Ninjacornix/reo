#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179238
// Address: 0x179238 - 0x179288
void sub_00179238_0x179238(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179238_0x179238");
#endif

    switch (ctx->pc) {
        case 0x179260u: goto label_179260;
        case 0x17926cu: goto label_17926c;
        default: break;
    }

    ctx->pc = 0x179238u;

    // 0x179238: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179238u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17923c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x17923cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179240: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179244: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x179244u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179248: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17924c: 0x18400009  blez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17924Cu;
    {
        const bool branch_taken_0x17924c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x179250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17924Cu;
            // 0x179250: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17924c) {
            ctx->pc = 0x179274u;
            goto label_179274;
        }
    }
    ctx->pc = 0x179254u;
    // 0x179254: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x179254u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179258: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x179258u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17925c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17925cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_179260:
    // 0x179260: 0x26310010  addiu       $s1, $s1, 0x10
    ctx->pc = 0x179260u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x179264: 0xc05e482  jal         func_179208
    ctx->pc = 0x179264u;
    SET_GPR_U32(ctx, 31, 0x17926Cu);
    ctx->pc = 0x179268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179264u;
            // 0x179268: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179208u;
    if (runtime->hasFunction(0x179208u)) {
        auto targetFn = runtime->lookupFunction(0x179208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17926Cu; }
        if (ctx->pc != 0x17926Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179208_0x179208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17926Cu; }
        if (ctx->pc != 0x17926Cu) { return; }
    }
    ctx->pc = 0x17926Cu;
label_17926c:
    // 0x17926c: 0x1600fffc  bnez        $s0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x17926Cu;
    {
        const bool branch_taken_0x17926c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x179270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17926Cu;
            // 0x179270: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17926c) {
            ctx->pc = 0x179260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_179260;
        }
    }
    ctx->pc = 0x179274u;
label_179274:
    // 0x179274: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179274u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179278: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179278u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17927c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17927cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179280: 0x3e00008  jr          $ra
    ctx->pc = 0x179280u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179280u;
            // 0x179284: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179260u: goto label_179260;
            case 0x17926Cu: goto label_17926c;
            case 0x179274u: goto label_179274;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179288u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
