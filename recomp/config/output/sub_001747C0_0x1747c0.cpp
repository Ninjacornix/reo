#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001747C0
// Address: 0x1747c0 - 0x17482c
void sub_001747C0_0x1747c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001747C0_0x1747c0");
#endif

    switch (ctx->pc) {
        case 0x1747e0u: goto label_1747e0;
        case 0x174814u: goto label_174814;
        default: break;
    }

    ctx->pc = 0x1747c0u;

    // 0x1747c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1747c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1747c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1747c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1747c8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1747c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1747cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1747ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1747d0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1747d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1747d4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1747d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1747d8: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1747D8u;
    SET_GPR_U32(ctx, 31, 0x1747E0u);
    ctx->pc = 0x1747DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1747D8u;
            // 0x1747dc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1747E0u; }
        if (ctx->pc != 0x1747E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1747E0u; }
        if (ctx->pc != 0x1747E0u) { return; }
    }
    ctx->pc = 0x1747E0u;
label_1747e0:
    // 0x1747e0: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1747e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1747e4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1747E4u;
    {
        const bool branch_taken_0x1747e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1747E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1747E4u;
            // 0x1747e8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1747e4) {
            ctx->pc = 0x174808u;
            goto label_174808;
        }
    }
    ctx->pc = 0x1747ECu;
    // 0x1747ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1747ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1747f0: 0x34a50154  ori         $a1, $a1, 0x154
    ctx->pc = 0x1747f0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)340);
    // 0x1747f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1747f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1747f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1747f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1747fc: 0x805a704  j           func_169C10
    ctx->pc = 0x1747FCu;
    ctx->pc = 0x174800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1747FCu;
            // 0x174800: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174804u;
    // 0x174804: 0x0  nop
    ctx->pc = 0x174804u;
    // NOP
label_174808:
    // 0x174808: 0x8e242ab0  lw          $a0, 0x2AB0($s1)
    ctx->pc = 0x174808u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 10928)));
    // 0x17480c: 0xc05d20c  jal         func_174830
    ctx->pc = 0x17480Cu;
    SET_GPR_U32(ctx, 31, 0x174814u);
    ctx->pc = 0x174810u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17480Cu;
            // 0x174810: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174830u;
    if (runtime->hasFunction(0x174830u)) {
        auto targetFn = runtime->lookupFunction(0x174830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174814u; }
        if (ctx->pc != 0x174814u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174830_0x174830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174814u; }
        if (ctx->pc != 0x174814u) { return; }
    }
    ctx->pc = 0x174814u;
label_174814:
    // 0x174814: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174814u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174818: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174818u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17481c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17481cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174820: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174820u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174824: 0x3e00008  jr          $ra
    ctx->pc = 0x174824u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174824u;
            // 0x174828: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1747E0u: goto label_1747e0;
            case 0x174808u: goto label_174808;
            case 0x174814u: goto label_174814;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17482Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
