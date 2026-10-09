#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176000
// Address: 0x176000 - 0x176040
void sub_00176000_0x176000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176000_0x176000");
#endif

    switch (ctx->pc) {
        case 0x176014u: goto label_176014;
        case 0x176028u: goto label_176028;
        default: break;
    }

    ctx->pc = 0x176000u;

    // 0x176000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x176000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x176004: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176008: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x176008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17600c: 0xc05d810  jal         func_176040
    ctx->pc = 0x17600Cu;
    SET_GPR_U32(ctx, 31, 0x176014u);
    ctx->pc = 0x176010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17600Cu;
            // 0x176010: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176040u;
    if (runtime->hasFunction(0x176040u)) {
        auto targetFn = runtime->lookupFunction(0x176040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176014u; }
        if (ctx->pc != 0x176014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176040_0x176040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176014u; }
        if (ctx->pc != 0x176014u) { return; }
    }
    ctx->pc = 0x176014u;
label_176014:
    // 0x176014: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x176014u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x176018: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x176018u;
    {
        const bool branch_taken_0x176018 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17601Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176018u;
            // 0x17601c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176018) {
            ctx->pc = 0x17602Cu;
            goto label_17602c;
        }
    }
    ctx->pc = 0x176020u;
    // 0x176020: 0xc05a704  jal         func_169C10
    ctx->pc = 0x176020u;
    SET_GPR_U32(ctx, 31, 0x176028u);
    ctx->pc = 0x176024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176020u;
            // 0x176024: 0x34a50222  ori         $a1, $a1, 0x222 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)546);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176028u; }
        if (ctx->pc != 0x176028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176028u; }
        if (ctx->pc != 0x176028u) { return; }
    }
    ctx->pc = 0x176028u;
label_176028:
    // 0x176028: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x176028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17602c:
    // 0x17602c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17602cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176030: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x176030u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176034: 0x3e00008  jr          $ra
    ctx->pc = 0x176034u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176034u;
            // 0x176038: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176014u: goto label_176014;
            case 0x176028u: goto label_176028;
            case 0x17602Cu: goto label_17602c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17603Cu;
    // 0x17603c: 0x0  nop
    ctx->pc = 0x17603cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
