#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00118110
// Address: 0x118110 - 0x118170
void sub_00118110_0x118110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00118110_0x118110");
#endif

    switch (ctx->pc) {
        case 0x118148u: goto label_118148;
        case 0x118154u: goto label_118154;
        default: break;
    }

    ctx->pc = 0x118110u;

    // 0x118110: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x118110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x118114: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x118114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x118118: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x118118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x11811c: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x11811cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x118120: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x118120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x118124: 0x8e029de8  lw          $v0, -0x6218($s0)
    ctx->pc = 0x118124u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
    // 0x118128: 0x1443000d  bne         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x118128u;
    {
        const bool branch_taken_0x118128 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x11812Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118128u;
            // 0x11812c: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118128) {
            ctx->pc = 0x118160u;
            goto label_118160;
        }
    }
    ctx->pc = 0x118130u;
    // 0x118130: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x118130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x118134: 0xafa00014  sw          $zero, 0x14($sp)
    ctx->pc = 0x118134u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x118138: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x118138u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x11813c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x11813cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118140: 0xc045188  jal         func_114620
    ctx->pc = 0x118140u;
    SET_GPR_U32(ctx, 31, 0x118148u);
    ctx->pc = 0x118144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118140u;
            // 0x118144: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118148u; }
        if (ctx->pc != 0x118148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118148u; }
        if (ctx->pc != 0x118148u) { return; }
    }
    ctx->pc = 0x118148u;
label_118148:
    // 0x118148: 0xae029de8  sw          $v0, -0x6218($s0)
    ctx->pc = 0x118148u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294942184), GPR_U32(ctx, 2));
    // 0x11814c: 0xc045188  jal         func_114620
    ctx->pc = 0x11814Cu;
    SET_GPR_U32(ctx, 31, 0x118154u);
    ctx->pc = 0x118150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11814Cu;
            // 0x118150: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118154u; }
        if (ctx->pc != 0x118154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118154u; }
        if (ctx->pc != 0x118154u) { return; }
    }
    ctx->pc = 0x118154u;
label_118154:
    // 0x118154: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x118154u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x118158: 0xac629dec  sw          $v0, -0x6214($v1)
    ctx->pc = 0x118158u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942188), GPR_U32(ctx, 2));
    // 0x11815c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11815cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_118160:
    // 0x118160: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x118160u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x118164: 0x3e00008  jr          $ra
    ctx->pc = 0x118164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118164u;
            // 0x118168: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118148u: goto label_118148;
            case 0x118154u: goto label_118154;
            case 0x118160u: goto label_118160;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11816Cu;
    // 0x11816c: 0x0  nop
    ctx->pc = 0x11816cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
