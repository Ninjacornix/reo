#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F608
// Address: 0x15f608 - 0x15f660
void sub_0015F608_0x15f608(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F608_0x15f608");
#endif

    switch (ctx->pc) {
        case 0x15f62cu: goto label_15f62c;
        default: break;
    }

    ctx->pc = 0x15f608u;

    // 0x15f608: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f608u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f60c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f60cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f610: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15f610u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15f614: 0x8c820044  lw          $v0, 0x44($a0)
    ctx->pc = 0x15f614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15f618: 0x8c900040  lw          $s0, 0x40($a0)
    ctx->pc = 0x15f618u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f61c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x15F61Cu;
    {
        const bool branch_taken_0x15f61c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F61Cu;
            // 0x15f620: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f61c) {
            ctx->pc = 0x15F650u;
            goto label_15f650;
        }
    }
    ctx->pc = 0x15F624u;
    // 0x15f624: 0xc0591ca  jal         func_164728
    ctx->pc = 0x15F624u;
    SET_GPR_U32(ctx, 31, 0x15F62Cu);
    ctx->pc = 0x164728u;
    if (runtime->hasFunction(0x164728u)) {
        auto targetFn = runtime->lookupFunction(0x164728u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F62Cu; }
        if (ctx->pc != 0x15F62Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164728_0x164728(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F62Cu; }
        if (ctx->pc != 0x15F62Cu) { return; }
    }
    ctx->pc = 0x15F62Cu;
label_15f62c:
    // 0x15f62c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x15f62cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15f630: 0x54430008  bnel        $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15F630u;
    {
        const bool branch_taken_0x15f630 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x15f630) {
            ctx->pc = 0x15F634u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15F630u;
            // 0x15f634: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15F654u;
            goto label_15f654;
        }
    }
    ctx->pc = 0x15F638u;
    // 0x15f638: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f638u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f63c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f63cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f640: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f640u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f644: 0x805cfca  j           func_173F28
    ctx->pc = 0x15F644u;
    ctx->pc = 0x15F648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F644u;
            // 0x15f648: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173F28u;
    if (runtime->hasFunction(0x173F28u)) {
        auto targetFn = runtime->lookupFunction(0x173F28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00173F28_0x173f28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F64Cu;
    // 0x15f64c: 0x0  nop
    ctx->pc = 0x15f64cu;
    // NOP
label_15f650:
    // 0x15f650: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f650u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15f654:
    // 0x15f654: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f654u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f658: 0x3e00008  jr          $ra
    ctx->pc = 0x15F658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F658u;
            // 0x15f65c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F62Cu: goto label_15f62c;
            case 0x15F650u: goto label_15f650;
            case 0x15F654u: goto label_15f654;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F660u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
