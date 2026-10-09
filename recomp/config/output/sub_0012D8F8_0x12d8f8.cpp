#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D8F8
// Address: 0x12d8f8 - 0x12d950
void sub_0012D8F8_0x12d8f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D8F8_0x12d8f8");
#endif

    switch (ctx->pc) {
        case 0x12d910u: goto label_12d910;
        case 0x12d934u: goto label_12d934;
        default: break;
    }

    ctx->pc = 0x12d8f8u;

    // 0x12d8f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d8f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d8fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12d8fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12d900: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12d900u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d904: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12d904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12d908: 0xc0493d2  jal         func_124F48
    ctx->pc = 0x12D908u;
    SET_GPR_U32(ctx, 31, 0x12D910u);
    ctx->pc = 0x12D90Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D908u;
            // 0x12d90c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F48u;
    if (runtime->hasFunction(0x124F48u)) {
        auto targetFn = runtime->lookupFunction(0x124F48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D910u; }
        if (ctx->pc != 0x12D910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124F48_0x124f48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D910u; }
        if (ctx->pc != 0x12D910u) { return; }
    }
    ctx->pc = 0x12D910u;
label_12d910:
    // 0x12d910: 0x1840000b  blez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x12D910u;
    {
        const bool branch_taken_0x12d910 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x12D914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D910u;
            // 0x12d914: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d910) {
            ctx->pc = 0x12D940u;
            goto label_12d940;
        }
    }
    ctx->pc = 0x12D918u;
    // 0x12d918: 0x92020001  lbu         $v0, 0x1($s0)
    ctx->pc = 0x12d918u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x12d91c: 0x2442fffe  addiu       $v0, $v0, -0x2
    ctx->pc = 0x12d91cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
    // 0x12d920: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x12d920u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x12d924: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x12D924u;
    {
        const bool branch_taken_0x12d924 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d924) {
            ctx->pc = 0x12D928u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D924u;
            // 0x12d928: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D940u;
            goto label_12d940;
        }
    }
    ctx->pc = 0x12D92Cu;
    // 0x12d92c: 0xc0493d4  jal         func_124F50
    ctx->pc = 0x12D92Cu;
    SET_GPR_U32(ctx, 31, 0x12D934u);
    ctx->pc = 0x12D930u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D92Cu;
            // 0x12d930: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F50u;
    if (runtime->hasFunction(0x124F50u)) {
        auto targetFn = runtime->lookupFunction(0x124F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D934u; }
        if (ctx->pc != 0x12D934u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124F50_0x124f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D934u; }
        if (ctx->pc != 0x12D934u) { return; }
    }
    ctx->pc = 0x12D934u;
label_12d934:
    // 0x12d934: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12D934u;
    {
        const bool branch_taken_0x12d934 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D934u;
            // 0x12d938: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d934) {
            ctx->pc = 0x12D944u;
            goto label_12d944;
        }
    }
    ctx->pc = 0x12D93Cu;
    // 0x12d93c: 0x0  nop
    ctx->pc = 0x12d93cu;
    // NOP
label_12d940:
    // 0x12d940: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12d940u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12d944:
    // 0x12d944: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12d944u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d948: 0x3e00008  jr          $ra
    ctx->pc = 0x12D948u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D94Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D948u;
            // 0x12d94c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D910u: goto label_12d910;
            case 0x12D934u: goto label_12d934;
            case 0x12D940u: goto label_12d940;
            case 0x12D944u: goto label_12d944;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D950u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
