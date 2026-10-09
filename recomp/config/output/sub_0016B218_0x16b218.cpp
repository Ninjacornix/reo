#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B218
// Address: 0x16b218 - 0x16b268
void sub_0016B218_0x16b218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B218_0x16b218");
#endif

    switch (ctx->pc) {
        case 0x16b23cu: goto label_16b23c;
        case 0x16b24cu: goto label_16b24c;
        default: break;
    }

    ctx->pc = 0x16b218u;

    // 0x16b218: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16b218u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16b21c: 0x3c030008  lui         $v1, 0x8
    ctx->pc = 0x16b21cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8 << 16));
    // 0x16b220: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b224: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b224u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b228: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16b228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16b22c: 0x14a3000a  bne         $a1, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x16B22Cu;
    {
        const bool branch_taken_0x16b22c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x16B230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B22Cu;
            // 0x16b230: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b22c) {
            ctx->pc = 0x16B258u;
            goto label_16b258;
        }
    }
    ctx->pc = 0x16B234u;
    // 0x16b234: 0xc059f74  jal         func_167DD0
    ctx->pc = 0x16B234u;
    SET_GPR_U32(ctx, 31, 0x16B23Cu);
    ctx->pc = 0x167DD0u;
    if (runtime->hasFunction(0x167DD0u)) {
        auto targetFn = runtime->lookupFunction(0x167DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B23Cu; }
        if (ctx->pc != 0x16B23Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167DD0_0x167dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B23Cu; }
        if (ctx->pc != 0x16B23Cu) { return; }
    }
    ctx->pc = 0x16B23Cu;
label_16b23c:
    // 0x16b23c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16B23Cu;
    {
        const bool branch_taken_0x16b23c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16B240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B23Cu;
            // 0x16b240: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b23c) {
            ctx->pc = 0x16B254u;
            goto label_16b254;
        }
    }
    ctx->pc = 0x16B244u;
    // 0x16b244: 0xc059f7c  jal         func_167DF0
    ctx->pc = 0x16B244u;
    SET_GPR_U32(ctx, 31, 0x16B24Cu);
    ctx->pc = 0x167DF0u;
    if (runtime->hasFunction(0x167DF0u)) {
        auto targetFn = runtime->lookupFunction(0x167DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B24Cu; }
        if (ctx->pc != 0x16B24Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167DF0_0x167df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B24Cu; }
        if (ctx->pc != 0x16B24Cu) { return; }
    }
    ctx->pc = 0x16B24Cu;
label_16b24c:
    // 0x16b24c: 0x50400002  beql        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x16B24Cu;
    {
        const bool branch_taken_0x16b24c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16b24c) {
            ctx->pc = 0x16B250u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B24Cu;
            // 0x16b250: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B258u;
            goto label_16b258;
        }
    }
    ctx->pc = 0x16B254u;
label_16b254:
    // 0x16b254: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16b254u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16b258:
    // 0x16b258: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b258u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b25c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16b25cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b260: 0x3e00008  jr          $ra
    ctx->pc = 0x16B260u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B260u;
            // 0x16b264: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B23Cu: goto label_16b23c;
            case 0x16B24Cu: goto label_16b24c;
            case 0x16B254u: goto label_16b254;
            case 0x16B258u: goto label_16b258;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B268u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
