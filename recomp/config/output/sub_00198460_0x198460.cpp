#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198460
// Address: 0x198460 - 0x1984d0
void sub_00198460_0x198460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198460_0x198460");
#endif

    switch (ctx->pc) {
        case 0x1984a4u: goto label_1984a4;
        case 0x1984bcu: goto label_1984bc;
        default: break;
    }

    ctx->pc = 0x198460u;

    // 0x198460: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x198460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x198464: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x198464u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x198468: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x198468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19846c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19846cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198470: 0x8c2bfe68  lw          $t3, -0x198($at)
    ctx->pc = 0x198470u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x198474: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x198474u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x198478: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x198478u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x19847c: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x19847cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x198480: 0x3c090023  lui         $t1, 0x23
    ctx->pc = 0x198480u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)35 << 16));
    // 0x198484: 0x3c0a0023  lui         $t2, 0x23
    ctx->pc = 0x198484u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)35 << 16));
    // 0x198488: 0x24a50190  addiu       $a1, $a1, 0x190
    ctx->pc = 0x198488u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 400));
    // 0x19848c: 0x24c601a0  addiu       $a2, $a2, 0x1A0
    ctx->pc = 0x19848cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 416));
    // 0x198490: 0x24e701b0  addiu       $a3, $a3, 0x1B0
    ctx->pc = 0x198490u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 432));
    // 0x198494: 0x250801c0  addiu       $t0, $t0, 0x1C0
    ctx->pc = 0x198494u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 448));
    // 0x198498: 0x252901d0  addiu       $t1, $t1, 0x1D0
    ctx->pc = 0x198498u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 464));
    // 0x19849c: 0xc066134  jal         func_1984D0
    ctx->pc = 0x19849Cu;
    SET_GPR_U32(ctx, 31, 0x1984A4u);
    ctx->pc = 0x1984A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19849Cu;
            // 0x1984a0: 0x254a01e0  addiu       $t2, $t2, 0x1E0 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1984D0u;
    if (runtime->hasFunction(0x1984D0u)) {
        auto targetFn = runtime->lookupFunction(0x1984D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1984A4u; }
        if (ctx->pc != 0x1984A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001984D0_0x1984d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1984A4u; }
        if (ctx->pc != 0x1984A4u) { return; }
    }
    ctx->pc = 0x1984A4u;
label_1984a4:
    // 0x1984a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1984A4u;
    {
        const bool branch_taken_0x1984a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1984A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1984A4u;
            // 0x1984a8: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1984a4) {
            ctx->pc = 0x1984B4u;
            goto label_1984b4;
        }
    }
    ctx->pc = 0x1984ACu;
    // 0x1984ac: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1984ACu;
    {
        const bool branch_taken_0x1984ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1984B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1984ACu;
            // 0x1984b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1984ac) {
            ctx->pc = 0x1984C0u;
            goto label_1984c0;
        }
    }
    ctx->pc = 0x1984B4u;
label_1984b4:
    // 0x1984b4: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1984B4u;
    SET_GPR_U32(ctx, 31, 0x1984BCu);
    ctx->pc = 0x1984B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1984B4u;
            // 0x1984b8: 0x24840170  addiu       $a0, $a0, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1984BCu; }
        if (ctx->pc != 0x1984BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1984BCu; }
        if (ctx->pc != 0x1984BCu) { return; }
    }
    ctx->pc = 0x1984BCu;
label_1984bc:
    // 0x1984bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1984bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1984c0:
    // 0x1984c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1984c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1984c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1984C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1984C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1984C4u;
            // 0x1984c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1984A4u: goto label_1984a4;
            case 0x1984B4u: goto label_1984b4;
            case 0x1984BCu: goto label_1984bc;
            case 0x1984C0u: goto label_1984c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1984CCu;
    // 0x1984cc: 0x0  nop
    ctx->pc = 0x1984ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
