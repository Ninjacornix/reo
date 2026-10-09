#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C138
// Address: 0x12c138 - 0x12c19c
void sub_0012C138_0x12c138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C138_0x12c138");
#endif

    switch (ctx->pc) {
        case 0x12c14cu: goto label_12c14c;
        case 0x12c16cu: goto label_12c16c;
        case 0x12c174u: goto label_12c174;
        case 0x12c17cu: goto label_12c17c;
        default: break;
    }

    ctx->pc = 0x12c138u;

    // 0x12c138: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c13c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12c13cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12c140: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12c140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12c144: 0xc04af5e  jal         func_12BD78
    ctx->pc = 0x12C144u;
    SET_GPR_U32(ctx, 31, 0x12C14Cu);
    ctx->pc = 0x12BD78u;
    if (runtime->hasFunction(0x12BD78u)) {
        auto targetFn = runtime->lookupFunction(0x12BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C14Cu; }
        if (ctx->pc != 0x12C14Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD78_0x12bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C14Cu; }
        if (ctx->pc != 0x12C14Cu) { return; }
    }
    ctx->pc = 0x12C14Cu;
label_12c14c:
    // 0x12c14c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12c14cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12c150: 0x24500558  addiu       $s0, $v0, 0x558
    ctx->pc = 0x12c150u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 1368));
    // 0x12c154: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12c154u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c158: 0x5460000d  bnel        $v1, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x12C158u;
    {
        const bool branch_taken_0x12c158 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12c158) {
            ctx->pc = 0x12C15Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12C158u;
            // 0x12c15c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12C190u;
            goto label_12c190;
        }
    }
    ctx->pc = 0x12C160u;
    // 0x12c160: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12c160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c164: 0xc04af64  jal         func_12BD90
    ctx->pc = 0x12C164u;
    SET_GPR_U32(ctx, 31, 0x12C16Cu);
    ctx->pc = 0x12C168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C164u;
            // 0x12c168: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12BD90u;
    if (runtime->hasFunction(0x12BD90u)) {
        auto targetFn = runtime->lookupFunction(0x12BD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C16Cu; }
        if (ctx->pc != 0x12C16Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD90_0x12bd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C16Cu; }
        if (ctx->pc != 0x12C16Cu) { return; }
    }
    ctx->pc = 0x12C16Cu;
label_12c16c:
    // 0x12c16c: 0xc04cb02  jal         func_132C08
    ctx->pc = 0x12C16Cu;
    SET_GPR_U32(ctx, 31, 0x12C174u);
    ctx->pc = 0x132C08u;
    if (runtime->hasFunction(0x132C08u)) {
        auto targetFn = runtime->lookupFunction(0x132C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C174u; }
        if (ctx->pc != 0x12C174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132C08_0x132c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C174u; }
        if (ctx->pc != 0x12C174u) { return; }
    }
    ctx->pc = 0x12C174u;
label_12c174:
    // 0x12c174: 0xc04a808  jal         func_12A020
    ctx->pc = 0x12C174u;
    SET_GPR_U32(ctx, 31, 0x12C17Cu);
    ctx->pc = 0x12A020u;
    if (runtime->hasFunction(0x12A020u)) {
        auto targetFn = runtime->lookupFunction(0x12A020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C17Cu; }
        if (ctx->pc != 0x12C17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C17Cu; }
        if (ctx->pc != 0x12C17Cu) { return; }
    }
    ctx->pc = 0x12C17Cu;
label_12c17c:
    // 0x12c17c: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x12c17cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x12c180: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12c180u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c184: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12c184u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c188: 0x3e00008  jr          $ra
    ctx->pc = 0x12C188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C18Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C188u;
            // 0x12c18c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C14Cu: goto label_12c14c;
            case 0x12C16Cu: goto label_12c16c;
            case 0x12C174u: goto label_12c174;
            case 0x12C17Cu: goto label_12c17c;
            case 0x12C190u: goto label_12c190;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C190u;
label_12c190:
    // 0x12c190: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12c190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c194: 0x804af64  j           func_12BD90
    ctx->pc = 0x12C194u;
    ctx->pc = 0x12C198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C194u;
            // 0x12c198: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12BD90u;
    if (runtime->hasFunction(0x12BD90u)) {
        auto targetFn = runtime->lookupFunction(0x12BD90u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012BD90_0x12bd90(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C19Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
