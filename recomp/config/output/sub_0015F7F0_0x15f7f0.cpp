#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F7F0
// Address: 0x15f7f0 - 0x15f86c
void sub_0015F7F0_0x15f7f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F7F0_0x15f7f0");
#endif

    switch (ctx->pc) {
        case 0x15f81cu: goto label_15f81c;
        case 0x15f830u: goto label_15f830;
        case 0x15f838u: goto label_15f838;
        case 0x15f84cu: goto label_15f84c;
        case 0x15f854u: goto label_15f854;
        default: break;
    }

    ctx->pc = 0x15f7f0u;

    // 0x15f7f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f7f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f7f4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15f7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15f7f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f7f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f7fc: 0x2470ef48  addiu       $s0, $v1, -0x10B8
    ctx->pc = 0x15f7fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963016));
    // 0x15f800: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x15f800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15f804: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f808: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x15f808u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f80c: 0x10510012  beq         $v0, $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0x15F80Cu;
    {
        const bool branch_taken_0x15f80c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x15F810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F80Cu;
            // 0x15f810: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f80c) {
            ctx->pc = 0x15F858u;
            goto label_15f858;
        }
    }
    ctx->pc = 0x15F814u;
    // 0x15f814: 0xc057e38  jal         func_15F8E0
    ctx->pc = 0x15F814u;
    SET_GPR_U32(ctx, 31, 0x15F81Cu);
    ctx->pc = 0x15F8E0u;
    if (runtime->hasFunction(0x15F8E0u)) {
        auto targetFn = runtime->lookupFunction(0x15F8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F81Cu; }
        if (ctx->pc != 0x15F81Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F8E0_0x15f8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F81Cu; }
        if (ctx->pc != 0x15F81Cu) { return; }
    }
    ctx->pc = 0x15F81Cu;
label_15f81c:
    // 0x15f81c: 0x3c060027  lui         $a2, 0x27
    ctx->pc = 0x15f81cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)39 << 16));
    // 0x15f820: 0x24c68640  addiu       $a2, $a2, -0x79C0
    ctx->pc = 0x15f820u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294936128));
    // 0x15f824: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f824u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f828: 0xc057e40  jal         func_15F900
    ctx->pc = 0x15F828u;
    SET_GPR_U32(ctx, 31, 0x15F830u);
    ctx->pc = 0x15F82Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F828u;
            // 0x15f82c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F900u;
    if (runtime->hasFunction(0x15F900u)) {
        auto targetFn = runtime->lookupFunction(0x15F900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F830u; }
        if (ctx->pc != 0x15F830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F900_0x15f900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F830u; }
        if (ctx->pc != 0x15F830u) { return; }
    }
    ctx->pc = 0x15F830u;
label_15f830:
    // 0x15f830: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F830u;
    SET_GPR_U32(ctx, 31, 0x15F838u);
    ctx->pc = 0x15F834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F830u;
            // 0x15f834: 0x24040008  addiu       $a0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F838u; }
        if (ctx->pc != 0x15F838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F838u; }
        if (ctx->pc != 0x15F838u) { return; }
    }
    ctx->pc = 0x15F838u;
label_15f838:
    // 0x15f838: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x15f838u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x15f83c: 0x2484c640  addiu       $a0, $a0, -0x39C0
    ctx->pc = 0x15f83cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952512));
    // 0x15f840: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f840u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f844: 0xc057e5a  jal         func_15F968
    ctx->pc = 0x15F844u;
    SET_GPR_U32(ctx, 31, 0x15F84Cu);
    ctx->pc = 0x15F848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F844u;
            // 0x15f848: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F968u;
    if (runtime->hasFunction(0x15F968u)) {
        auto targetFn = runtime->lookupFunction(0x15F968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F84Cu; }
        if (ctx->pc != 0x15F84Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F968_0x15f968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F84Cu; }
        if (ctx->pc != 0x15F84Cu) { return; }
    }
    ctx->pc = 0x15F84Cu;
label_15f84c:
    // 0x15f84c: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F84Cu;
    SET_GPR_U32(ctx, 31, 0x15F854u);
    ctx->pc = 0x15F850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F84Cu;
            // 0x15f850: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F854u; }
        if (ctx->pc != 0x15F854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F854u; }
        if (ctx->pc != 0x15F854u) { return; }
    }
    ctx->pc = 0x15F854u;
label_15f854:
    // 0x15f854: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x15f854u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
label_15f858:
    // 0x15f858: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f858u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f85c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f85cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f860: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f860u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f864: 0x3e00008  jr          $ra
    ctx->pc = 0x15F864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F864u;
            // 0x15f868: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F81Cu: goto label_15f81c;
            case 0x15F830u: goto label_15f830;
            case 0x15F838u: goto label_15f838;
            case 0x15F84Cu: goto label_15f84c;
            case 0x15F854u: goto label_15f854;
            case 0x15F858u: goto label_15f858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F86Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
