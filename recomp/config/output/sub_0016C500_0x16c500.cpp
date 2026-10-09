#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C500
// Address: 0x16c500 - 0x16c560
void sub_0016C500_0x16c500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C500_0x16c500");
#endif

    switch (ctx->pc) {
        case 0x16c514u: goto label_16c514;
        case 0x16c524u: goto label_16c524;
        case 0x16c534u: goto label_16c534;
        default: break;
    }

    ctx->pc = 0x16c500u;

    // 0x16c500: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16c500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c504: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16c504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c508: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16c508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16c50c: 0xc05c15c  jal         func_170570
    ctx->pc = 0x16C50Cu;
    SET_GPR_U32(ctx, 31, 0x16C514u);
    ctx->pc = 0x16C510u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C50Cu;
            // 0x16c510: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170570u;
    if (runtime->hasFunction(0x170570u)) {
        auto targetFn = runtime->lookupFunction(0x170570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C514u; }
        if (ctx->pc != 0x16C514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170570_0x170570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C514u; }
        if (ctx->pc != 0x16C514u) { return; }
    }
    ctx->pc = 0x16C514u;
label_16c514:
    // 0x16c514: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16C514u;
    {
        const bool branch_taken_0x16c514 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16C518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C514u;
            // 0x16c518: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c514) {
            ctx->pc = 0x16C53Cu;
            goto label_16c53c;
        }
    }
    ctx->pc = 0x16C51Cu;
    // 0x16c51c: 0xc05b158  jal         func_16C560
    ctx->pc = 0x16C51Cu;
    SET_GPR_U32(ctx, 31, 0x16C524u);
    ctx->pc = 0x16C560u;
    if (runtime->hasFunction(0x16C560u)) {
        auto targetFn = runtime->lookupFunction(0x16C560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C524u; }
        if (ctx->pc != 0x16C524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C560_0x16c560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C524u; }
        if (ctx->pc != 0x16C524u) { return; }
    }
    ctx->pc = 0x16C524u;
label_16c524:
    // 0x16c524: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16C524u;
    {
        const bool branch_taken_0x16c524 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C524u;
            // 0x16c528: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c524) {
            ctx->pc = 0x16C548u;
            goto label_16c548;
        }
    }
    ctx->pc = 0x16C52Cu;
    // 0x16c52c: 0xc05b16a  jal         func_16C5A8
    ctx->pc = 0x16C52Cu;
    SET_GPR_U32(ctx, 31, 0x16C534u);
    ctx->pc = 0x16C5A8u;
    if (runtime->hasFunction(0x16C5A8u)) {
        auto targetFn = runtime->lookupFunction(0x16C5A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C534u; }
        if (ctx->pc != 0x16C534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C5A8_0x16c5a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C534u; }
        if (ctx->pc != 0x16C534u) { return; }
    }
    ctx->pc = 0x16C534u;
label_16c534:
    // 0x16c534: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x16C534u;
    {
        const bool branch_taken_0x16c534 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16c534) {
            ctx->pc = 0x16C538u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16C534u;
            // 0x16c538: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16C54Cu;
            goto label_16c54c;
        }
    }
    ctx->pc = 0x16C53Cu;
label_16c53c:
    // 0x16c53c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16C53Cu;
    {
        const bool branch_taken_0x16c53c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C53Cu;
            // 0x16c540: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c53c) {
            ctx->pc = 0x16C54Cu;
            goto label_16c54c;
        }
    }
    ctx->pc = 0x16C544u;
    // 0x16c544: 0x0  nop
    ctx->pc = 0x16c544u;
    // NOP
label_16c548:
    // 0x16c548: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16c548u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16c54c:
    // 0x16c54c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c54cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c550: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16c550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c554: 0x3e00008  jr          $ra
    ctx->pc = 0x16C554u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C554u;
            // 0x16c558: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C514u: goto label_16c514;
            case 0x16C524u: goto label_16c524;
            case 0x16C534u: goto label_16c534;
            case 0x16C53Cu: goto label_16c53c;
            case 0x16C548u: goto label_16c548;
            case 0x16C54Cu: goto label_16c54c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C55Cu;
    // 0x16c55c: 0x0  nop
    ctx->pc = 0x16c55cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
