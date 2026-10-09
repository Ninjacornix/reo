#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BFF0
// Address: 0x16bff0 - 0x16c040
void sub_0016BFF0_0x16bff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BFF0_0x16bff0");
#endif

    switch (ctx->pc) {
        case 0x16c004u: goto label_16c004;
        case 0x16c01cu: goto label_16c01c;
        default: break;
    }

    ctx->pc = 0x16bff0u;

    // 0x16bff0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16bff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16bff4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16bff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16bff8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16bff8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16bffc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x16BFFCu;
    SET_GPR_U32(ctx, 31, 0x16C004u);
    ctx->pc = 0x16C000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BFFCu;
            // 0x16c000: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C004u; }
        if (ctx->pc != 0x16C004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C004u; }
        if (ctx->pc != 0x16C004u) { return; }
    }
    ctx->pc = 0x16C004u;
label_16c004:
    // 0x16c004: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16c004u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16c008: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16c008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c00c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16C00Cu;
    {
        const bool branch_taken_0x16c00c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C00Cu;
            // 0x16c010: 0x34a50183  ori         $a1, $a1, 0x183 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)387);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c00c) {
            ctx->pc = 0x16C030u;
            goto label_16c030;
        }
    }
    ctx->pc = 0x16C014u;
    // 0x16c014: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16C014u;
    SET_GPR_U32(ctx, 31, 0x16C01Cu);
    ctx->pc = 0x16C018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C014u;
            // 0x16c018: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C01Cu; }
        if (ctx->pc != 0x16C01Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C01Cu; }
        if (ctx->pc != 0x16C01Cu) { return; }
    }
    ctx->pc = 0x16C01Cu;
label_16c01c:
    // 0x16c01c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16c01cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c020: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c020u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c024: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16c024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c028: 0x3e00008  jr          $ra
    ctx->pc = 0x16C028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C028u;
            // 0x16c02c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C004u: goto label_16c004;
            case 0x16C01Cu: goto label_16c01c;
            case 0x16C030u: goto label_16c030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C030u;
label_16c030:
    // 0x16c030: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c030u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c034: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16c034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c038: 0x805c212  j           func_170848
    ctx->pc = 0x16C038u;
    ctx->pc = 0x16C03Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C038u;
            // 0x16c03c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170848u;
    if (runtime->hasFunction(0x170848u)) {
        auto targetFn = runtime->lookupFunction(0x170848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00170848_0x170848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
