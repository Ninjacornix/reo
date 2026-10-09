#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001662E0
// Address: 0x1662e0 - 0x16634c
void sub_001662E0_0x1662e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001662E0_0x1662e0");
#endif

    switch (ctx->pc) {
        case 0x1662f4u: goto label_1662f4;
        case 0x16630cu: goto label_16630c;
        case 0x166324u: goto label_166324;
        case 0x16633cu: goto label_16633c;
        default: break;
    }

    ctx->pc = 0x1662e0u;

    // 0x1662e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1662e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1662e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1662e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1662e8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1662e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1662ec: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1662ECu;
    SET_GPR_U32(ctx, 31, 0x1662F4u);
    ctx->pc = 0x1662F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1662ECu;
            // 0x1662f0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662F4u; }
        if (ctx->pc != 0x1662F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662F4u; }
        if (ctx->pc != 0x1662F4u) { return; }
    }
    ctx->pc = 0x1662F4u;
label_1662f4:
    // 0x1662f4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1662f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1662f8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1662f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1662fc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1662FCu;
    {
        const bool branch_taken_0x1662fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1662FCu;
            // 0x166300: 0x34a501a4  ori         $a1, $a1, 0x1A4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)420);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1662fc) {
            ctx->pc = 0x166318u;
            goto label_166318;
        }
    }
    ctx->pc = 0x166304u;
    // 0x166304: 0xc05a704  jal         func_169C10
    ctx->pc = 0x166304u;
    SET_GPR_U32(ctx, 31, 0x16630Cu);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16630Cu; }
        if (ctx->pc != 0x16630Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16630Cu; }
        if (ctx->pc != 0x16630Cu) { return; }
    }
    ctx->pc = 0x16630Cu;
label_16630c:
    // 0x16630c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x16630Cu;
    {
        const bool branch_taken_0x16630c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x166310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16630Cu;
            // 0x166310: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16630c) {
            ctx->pc = 0x16633Cu;
            goto label_16633c;
        }
    }
    ctx->pc = 0x166314u;
    // 0x166314: 0x0  nop
    ctx->pc = 0x166314u;
    // NOP
label_166318:
    // 0x166318: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16631c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16631Cu;
    SET_GPR_U32(ctx, 31, 0x166324u);
    ctx->pc = 0x166320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16631Cu;
            // 0x166320: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166324u; }
        if (ctx->pc != 0x166324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166324u; }
        if (ctx->pc != 0x166324u) { return; }
    }
    ctx->pc = 0x166324u;
label_166324:
    // 0x166324: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x166324u;
    {
        const bool branch_taken_0x166324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166324u;
            // 0x166328: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166324) {
            ctx->pc = 0x16633Cu;
            goto label_16633c;
        }
    }
    ctx->pc = 0x16632Cu;
    // 0x16632c: 0x8e031c84  lw          $v1, 0x1C84($s0)
    ctx->pc = 0x16632cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x166330: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x166330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x166334: 0x40f809  jalr        $v0
    ctx->pc = 0x166334u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16633Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x16633Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16633Cu; }
            if (ctx->pc != 0x16633Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16633Cu;
label_16633c:
    // 0x16633c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16633cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166340: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166340u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166344: 0x3e00008  jr          $ra
    ctx->pc = 0x166344u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166344u;
            // 0x166348: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16634Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
