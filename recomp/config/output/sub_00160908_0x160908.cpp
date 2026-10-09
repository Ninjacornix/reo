#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160908
// Address: 0x160908 - 0x160938
void sub_00160908_0x160908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160908_0x160908");
#endif

    switch (ctx->pc) {
        case 0x160928u: goto label_160928;
        default: break;
    }

    ctx->pc = 0x160908u;

    // 0x160908: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16090c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16090cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160910: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x160910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x160914: 0x8c830044  lw          $v1, 0x44($a0)
    ctx->pc = 0x160914u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x160918: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x160918u;
    {
        const bool branch_taken_0x160918 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16091Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160918u;
            // 0x16091c: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160918) {
            ctx->pc = 0x16092Cu;
            goto label_16092c;
        }
    }
    ctx->pc = 0x160920u;
    // 0x160920: 0xc059160  jal         func_164580
    ctx->pc = 0x160920u;
    SET_GPR_U32(ctx, 31, 0x160928u);
    ctx->pc = 0x160924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160920u;
            // 0x160924: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164580u;
    if (runtime->hasFunction(0x164580u)) {
        auto targetFn = runtime->lookupFunction(0x164580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160928u; }
        if (ctx->pc != 0x160928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164580_0x164580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160928u; }
        if (ctx->pc != 0x160928u) { return; }
    }
    ctx->pc = 0x160928u;
label_160928:
    // 0x160928: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x160928u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_16092c:
    // 0x16092c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16092cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160930: 0x3e00008  jr          $ra
    ctx->pc = 0x160930u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160930u;
            // 0x160934: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160928u: goto label_160928;
            case 0x16092Cu: goto label_16092c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160938u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
