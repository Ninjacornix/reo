#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EDF8
// Address: 0x11edf8 - 0x11ee44
void sub_0011EDF8_0x11edf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EDF8_0x11edf8");
#endif

    switch (ctx->pc) {
        case 0x11ee10u: goto label_11ee10;
        case 0x11ee1cu: goto label_11ee1c;
        case 0x11ee2cu: goto label_11ee2c;
        default: break;
    }

    ctx->pc = 0x11edf8u;

    // 0x11edf8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11edf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11edfc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11edfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ee00: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ee00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ee04: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ee04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11ee08: 0xc047598  jal         func_11D660
    ctx->pc = 0x11EE08u;
    SET_GPR_U32(ctx, 31, 0x11EE10u);
    ctx->pc = 0x11EE0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE08u;
            // 0x11ee0c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE10u; }
        if (ctx->pc != 0x11EE10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE10u; }
        if (ctx->pc != 0x11EE10u) { return; }
    }
    ctx->pc = 0x11EE10u;
label_11ee10:
    // 0x11ee10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11ee10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ee14: 0xc047b6c  jal         func_11EDB0
    ctx->pc = 0x11EE14u;
    SET_GPR_U32(ctx, 31, 0x11EE1Cu);
    ctx->pc = 0x11EE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE14u;
            // 0x11ee18: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EDB0u;
    if (runtime->hasFunction(0x11EDB0u)) {
        auto targetFn = runtime->lookupFunction(0x11EDB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE1Cu; }
        if (ctx->pc != 0x11EE1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EDB0_0x11edb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE1Cu; }
        if (ctx->pc != 0x11EE1Cu) { return; }
    }
    ctx->pc = 0x11EE1Cu;
label_11ee1c:
    // 0x11ee1c: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EE1Cu;
    {
        const bool branch_taken_0x11ee1c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE1Cu;
            // 0x11ee20: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ee1c) {
            ctx->pc = 0x11EE2Cu;
            goto label_11ee2c;
        }
    }
    ctx->pc = 0x11EE24u;
    // 0x11ee24: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11EE24u;
    SET_GPR_U32(ctx, 31, 0x11EE2Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE2Cu; }
        if (ctx->pc != 0x11EE2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE2Cu; }
        if (ctx->pc != 0x11EE2Cu) { return; }
    }
    ctx->pc = 0x11EE2Cu;
label_11ee2c:
    // 0x11ee2c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ee2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ee30: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ee30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ee34: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ee34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ee38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ee38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ee3c: 0x3e00008  jr          $ra
    ctx->pc = 0x11EE3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EE40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE3Cu;
            // 0x11ee40: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EE10u: goto label_11ee10;
            case 0x11EE1Cu: goto label_11ee1c;
            case 0x11EE2Cu: goto label_11ee2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EE44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
