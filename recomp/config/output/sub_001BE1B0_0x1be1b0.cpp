#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE1B0
// Address: 0x1be1b0 - 0x1be21c
void sub_001BE1B0_0x1be1b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE1B0_0x1be1b0");
#endif

    switch (ctx->pc) {
        case 0x1be1e8u: goto label_1be1e8;
        case 0x1be1fcu: goto label_1be1fc;
        case 0x1be204u: goto label_1be204;
        case 0x1be20cu: goto label_1be20c;
        default: break;
    }

    ctx->pc = 0x1be1b0u;

    // 0x1be1b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1be1b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1be1b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be1b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be1b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1be1b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1be1bc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1be1bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1be1c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1be1c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1be1c4: 0x8c3044f0  lw          $s0, 0x44F0($at)
    ctx->pc = 0x1be1c4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17648)));
    // 0x1be1c8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be1c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be1cc: 0x1200000f  beqz        $s0, . + 4 + (0xF << 2)
    ctx->pc = 0x1BE1CCu;
    {
        const bool branch_taken_0x1be1cc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE1CCu;
            // 0x1be1d0: 0xac2344e0  sw          $v1, 0x44E0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17632), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be1cc) {
            ctx->pc = 0x1BE20Cu;
            goto label_1be20c;
        }
    }
    ctx->pc = 0x1BE1D4u;
    // 0x1be1d4: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x1be1d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1be1d8: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE1D8u;
    {
        const bool branch_taken_0x1be1d8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1be1d8) {
            ctx->pc = 0x1BE1E8u;
            goto label_1be1e8;
        }
    }
    ctx->pc = 0x1BE1E0u;
    // 0x1be1e0: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BE1E0u;
    SET_GPR_U32(ctx, 31, 0x1BE1E8u);
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE1E8u; }
        if (ctx->pc != 0x1BE1E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE1E8u; }
        if (ctx->pc != 0x1BE1E8u) { return; }
    }
    ctx->pc = 0x1BE1E8u;
label_1be1e8:
    // 0x1be1e8: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x1be1e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1be1ec: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE1ECu;
    {
        const bool branch_taken_0x1be1ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1be1ec) {
            ctx->pc = 0x1BE1FCu;
            goto label_1be1fc;
        }
    }
    ctx->pc = 0x1BE1F4u;
    // 0x1be1f4: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BE1F4u;
    SET_GPR_U32(ctx, 31, 0x1BE1FCu);
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE1FCu; }
        if (ctx->pc != 0x1BE1FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE1FCu; }
        if (ctx->pc != 0x1BE1FCu) { return; }
    }
    ctx->pc = 0x1BE1FCu;
label_1be1fc:
    // 0x1be1fc: 0xc06f900  jal         func_1BE400
    ctx->pc = 0x1BE1FCu;
    SET_GPR_U32(ctx, 31, 0x1BE204u);
    ctx->pc = 0x1BE400u;
    if (runtime->hasFunction(0x1BE400u)) {
        auto targetFn = runtime->lookupFunction(0x1BE400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE204u; }
        if (ctx->pc != 0x1BE204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE400_0x1be400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE204u; }
        if (ctx->pc != 0x1BE204u) { return; }
    }
    ctx->pc = 0x1BE204u;
label_1be204:
    // 0x1be204: 0xc06f888  jal         func_1BE220
    ctx->pc = 0x1BE204u;
    SET_GPR_U32(ctx, 31, 0x1BE20Cu);
    ctx->pc = 0x1BE220u;
    if (runtime->hasFunction(0x1BE220u)) {
        auto targetFn = runtime->lookupFunction(0x1BE220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE20Cu; }
        if (ctx->pc != 0x1BE20Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE220_0x1be220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE20Cu; }
        if (ctx->pc != 0x1BE20Cu) { return; }
    }
    ctx->pc = 0x1BE20Cu;
label_1be20c:
    // 0x1be20c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1be20cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1be210: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1be210u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1be214: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE214u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE214u;
            // 0x1be218: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE1E8u: goto label_1be1e8;
            case 0x1BE1FCu: goto label_1be1fc;
            case 0x1BE204u: goto label_1be204;
            case 0x1BE20Cu: goto label_1be20c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE21Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
