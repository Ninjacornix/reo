#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174760
// Address: 0x174760 - 0x1747bc
void sub_00174760_0x174760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174760_0x174760");
#endif

    switch (ctx->pc) {
        case 0x174774u: goto label_174774;
        case 0x1747a8u: goto label_1747a8;
        default: break;
    }

    ctx->pc = 0x174760u;

    // 0x174760: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x174760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x174764: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174768: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x174768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17476c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x17476Cu;
    SET_GPR_U32(ctx, 31, 0x174774u);
    ctx->pc = 0x174770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17476Cu;
            // 0x174770: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174774u; }
        if (ctx->pc != 0x174774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174774u; }
        if (ctx->pc != 0x174774u) { return; }
    }
    ctx->pc = 0x174774u;
label_174774:
    // 0x174774: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x174774u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174778: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x174778u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17477c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x17477cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x174780: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174780u;
    {
        const bool branch_taken_0x174780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174780u;
            // 0x174784: 0x34a50153  ori         $a1, $a1, 0x153 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)339);
        ctx->in_delay_slot = false;
        if (branch_taken_0x174780) {
            ctx->pc = 0x1747A0u;
            goto label_1747a0;
        }
    }
    ctx->pc = 0x174788u;
    // 0x174788: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174788u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17478c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17478cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174790: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x174790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174794: 0x805a704  j           func_169C10
    ctx->pc = 0x174794u;
    ctx->pc = 0x174798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174794u;
            // 0x174798: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17479Cu;
    // 0x17479c: 0x0  nop
    ctx->pc = 0x17479cu;
    // NOP
label_1747a0:
    // 0x1747a0: 0xc05d518  jal         func_175460
    ctx->pc = 0x1747A0u;
    SET_GPR_U32(ctx, 31, 0x1747A8u);
    ctx->pc = 0x1747A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1747A0u;
            // 0x1747a4: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1747A8u; }
        if (ctx->pc != 0x1747A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1747A8u; }
        if (ctx->pc != 0x1747A8u) { return; }
    }
    ctx->pc = 0x1747A8u;
label_1747a8:
    // 0x1747a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1747a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1747ac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1747acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1747b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1747b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1747b4: 0x805c8b0  j           func_1722C0
    ctx->pc = 0x1747B4u;
    ctx->pc = 0x1747B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1747B4u;
            // 0x1747b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1722C0u;
    if (runtime->hasFunction(0x1722C0u)) {
        auto targetFn = runtime->lookupFunction(0x1722C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001722C0_0x1722c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1747BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
