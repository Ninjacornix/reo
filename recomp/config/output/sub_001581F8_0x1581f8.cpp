#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001581F8
// Address: 0x1581f8 - 0x158248
void sub_001581F8_0x1581f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001581F8_0x1581f8");
#endif

    switch (ctx->pc) {
        case 0x158220u: goto label_158220;
        case 0x158230u: goto label_158230;
        default: break;
    }

    ctx->pc = 0x1581f8u;

    // 0x1581f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1581f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1581fc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1581fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158200: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158204: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x158204u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158208: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x158208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15820c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15820Cu;
    {
        const bool branch_taken_0x15820c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15820Cu;
            // 0x158210: 0x24440004  addiu       $a0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15820c) {
            ctx->pc = 0x158228u;
            goto label_158228;
        }
    }
    ctx->pc = 0x158214u;
    // 0x158214: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x158214u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x158218: 0xc056092  jal         func_158248
    ctx->pc = 0x158218u;
    SET_GPR_U32(ctx, 31, 0x158220u);
    ctx->pc = 0x15821Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158218u;
            // 0x15821c: 0x8c44d870  lw          $a0, -0x2790($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957168)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158248u;
    if (runtime->hasFunction(0x158248u)) {
        auto targetFn = runtime->lookupFunction(0x158248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158220u; }
        if (ctx->pc != 0x158220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158248_0x158248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158220u; }
        if (ctx->pc != 0x158220u) { return; }
    }
    ctx->pc = 0x158220u;
label_158220:
    // 0x158220: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x158220u;
    {
        const bool branch_taken_0x158220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158220u;
            // 0x158224: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158220) {
            ctx->pc = 0x158234u;
            goto label_158234;
        }
    }
    ctx->pc = 0x158228u;
label_158228:
    // 0x158228: 0xc056092  jal         func_158248
    ctx->pc = 0x158228u;
    SET_GPR_U32(ctx, 31, 0x158230u);
    ctx->pc = 0x158248u;
    if (runtime->hasFunction(0x158248u)) {
        auto targetFn = runtime->lookupFunction(0x158248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158230u; }
        if (ctx->pc != 0x158230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158248_0x158248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158230u; }
        if (ctx->pc != 0x158230u) { return; }
    }
    ctx->pc = 0x158230u;
label_158230:
    // 0x158230: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x158230u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_158234:
    // 0x158234: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x158234u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158238: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x158238u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15823c: 0x3e00008  jr          $ra
    ctx->pc = 0x15823Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15823Cu;
            // 0x158240: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158220u: goto label_158220;
            case 0x158228u: goto label_158228;
            case 0x158230u: goto label_158230;
            case 0x158234u: goto label_158234;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158244u;
    // 0x158244: 0x0  nop
    ctx->pc = 0x158244u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
