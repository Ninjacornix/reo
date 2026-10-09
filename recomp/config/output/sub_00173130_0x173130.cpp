#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173130
// Address: 0x173130 - 0x1731a0
void sub_00173130_0x173130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173130_0x173130");
#endif

    switch (ctx->pc) {
        case 0x173144u: goto label_173144;
        case 0x173154u: goto label_173154;
        case 0x173164u: goto label_173164;
        case 0x173174u: goto label_173174;
        default: break;
    }

    ctx->pc = 0x173130u;

    // 0x173130: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173134: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173138: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x173138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17313c: 0xc05cc68  jal         func_1731A0
    ctx->pc = 0x17313Cu;
    SET_GPR_U32(ctx, 31, 0x173144u);
    ctx->pc = 0x173140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17313Cu;
            // 0x173140: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1731A0u;
    if (runtime->hasFunction(0x1731A0u)) {
        auto targetFn = runtime->lookupFunction(0x1731A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173144u; }
        if (ctx->pc != 0x173144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001731A0_0x1731a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173144u; }
        if (ctx->pc != 0x173144u) { return; }
    }
    ctx->pc = 0x173144u;
label_173144:
    // 0x173144: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x173144u;
    {
        const bool branch_taken_0x173144 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x173148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173144u;
            // 0x173148: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173144) {
            ctx->pc = 0x17317Cu;
            goto label_17317c;
        }
    }
    ctx->pc = 0x17314Cu;
    // 0x17314c: 0xc05cc84  jal         func_173210
    ctx->pc = 0x17314Cu;
    SET_GPR_U32(ctx, 31, 0x173154u);
    ctx->pc = 0x173210u;
    if (runtime->hasFunction(0x173210u)) {
        auto targetFn = runtime->lookupFunction(0x173210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173154u; }
        if (ctx->pc != 0x173154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173210_0x173210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173154u; }
        if (ctx->pc != 0x173154u) { return; }
    }
    ctx->pc = 0x173154u;
label_173154:
    // 0x173154: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x173154u;
    {
        const bool branch_taken_0x173154 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x173158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173154u;
            // 0x173158: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173154) {
            ctx->pc = 0x17317Cu;
            goto label_17317c;
        }
    }
    ctx->pc = 0x17315Cu;
    // 0x17315c: 0xc05ccb6  jal         func_1732D8
    ctx->pc = 0x17315Cu;
    SET_GPR_U32(ctx, 31, 0x173164u);
    ctx->pc = 0x1732D8u;
    if (runtime->hasFunction(0x1732D8u)) {
        auto targetFn = runtime->lookupFunction(0x1732D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173164u; }
        if (ctx->pc != 0x173164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001732D8_0x1732d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173164u; }
        if (ctx->pc != 0x173164u) { return; }
    }
    ctx->pc = 0x173164u;
label_173164:
    // 0x173164: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x173164u;
    {
        const bool branch_taken_0x173164 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x173168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173164u;
            // 0x173168: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173164) {
            ctx->pc = 0x17317Cu;
            goto label_17317c;
        }
    }
    ctx->pc = 0x17316Cu;
    // 0x17316c: 0xc05cccc  jal         func_173330
    ctx->pc = 0x17316Cu;
    SET_GPR_U32(ctx, 31, 0x173174u);
    ctx->pc = 0x173330u;
    if (runtime->hasFunction(0x173330u)) {
        auto targetFn = runtime->lookupFunction(0x173330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173174u; }
        if (ctx->pc != 0x173174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173330_0x173330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173174u; }
        if (ctx->pc != 0x173174u) { return; }
    }
    ctx->pc = 0x173174u;
label_173174:
    // 0x173174: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x173174u;
    {
        const bool branch_taken_0x173174 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x173174) {
            ctx->pc = 0x173178u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173174u;
            // 0x173178: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173190u;
            goto label_173190;
        }
    }
    ctx->pc = 0x17317Cu;
label_17317c:
    // 0x17317c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17317cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173180: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173180u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173184: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173184u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173188: 0x805ccf0  j           func_1733C0
    ctx->pc = 0x173188u;
    ctx->pc = 0x17318Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173188u;
            // 0x17318c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1733C0u;
    if (runtime->hasFunction(0x1733C0u)) {
        auto targetFn = runtime->lookupFunction(0x1733C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001733C0_0x1733c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173190u;
label_173190:
    // 0x173190: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173194: 0x3e00008  jr          $ra
    ctx->pc = 0x173194u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173194u;
            // 0x173198: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173144u: goto label_173144;
            case 0x173154u: goto label_173154;
            case 0x173164u: goto label_173164;
            case 0x173174u: goto label_173174;
            case 0x17317Cu: goto label_17317c;
            case 0x173190u: goto label_173190;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17319Cu;
    // 0x17319c: 0x0  nop
    ctx->pc = 0x17319cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
