#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128410
// Address: 0x128410 - 0x1284d0
void sub_00128410_0x128410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128410_0x128410");
#endif

    switch (ctx->pc) {
        case 0x128438u: goto label_128438;
        case 0x128478u: goto label_128478;
        case 0x12848cu: goto label_12848c;
        case 0x1284a0u: goto label_1284a0;
        default: break;
    }

    ctx->pc = 0x128410u;

    // 0x128410: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128414: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128414u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128418: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12841c: 0x2463c8bc  addiu       $v1, $v1, -0x3744
    ctx->pc = 0x12841cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953148));
    // 0x128420: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x128420u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x128424: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x128424u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x128428: 0x14400025  bnez        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x128428u;
    {
        const bool branch_taken_0x128428 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12842Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128428u;
            // 0x12842c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128428) {
            ctx->pc = 0x1284C0u;
            goto label_1284c0;
        }
    }
    ctx->pc = 0x128430u;
    // 0x128430: 0xc04a502  jal         func_129408
    ctx->pc = 0x128430u;
    SET_GPR_U32(ctx, 31, 0x128438u);
    ctx->pc = 0x129408u;
    if (runtime->hasFunction(0x129408u)) {
        auto targetFn = runtime->lookupFunction(0x129408u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128438u; }
        if (ctx->pc != 0x128438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129408_0x129408(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128438u; }
        if (ctx->pc != 0x128438u) { return; }
    }
    ctx->pc = 0x128438u;
label_128438:
    // 0x128438: 0x3c0a0021  lui         $t2, 0x21
    ctx->pc = 0x128438u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)33 << 16));
    // 0x12843c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12843cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x128440: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128440u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128444: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x128444u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x128448: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x128448u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x12844c: 0x3c090021  lui         $t1, 0x21
    ctx->pc = 0x12844cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)33 << 16));
    // 0x128450: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128450u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128454: 0x2484d208  addiu       $a0, $a0, -0x2DF8
    ctx->pc = 0x128454u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955528));
    // 0x128458: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x128458u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x12845c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x12845cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x128460: 0xac60d230  sw          $zero, -0x2DD0($v1)
    ctx->pc = 0x128460u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294955568), GPR_U32(ctx, 0));
    // 0x128464: 0xad42d234  sw          $v0, -0x2DCC($t2)
    ctx->pc = 0x128464u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 4294955572), GPR_U32(ctx, 2));
    // 0x128468: 0xace0d22c  sw          $zero, -0x2DD4($a3)
    ctx->pc = 0x128468u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294955564), GPR_U32(ctx, 0));
    // 0x12846c: 0xad00d100  sw          $zero, -0x2F00($t0)
    ctx->pc = 0x12846cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4294955264), GPR_U32(ctx, 0));
    // 0x128470: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x128470u;
    SET_GPR_U32(ctx, 31, 0x128478u);
    ctx->pc = 0x128474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128470u;
            // 0x128474: 0xad20d228  sw          $zero, -0x2DD8($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 4294955560), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128478u; }
        if (ctx->pc != 0x128478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128478u; }
        if (ctx->pc != 0x128478u) { return; }
    }
    ctx->pc = 0x128478u;
label_128478:
    // 0x128478: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128478u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12847c: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x12847cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x128480: 0x2484d108  addiu       $a0, $a0, -0x2EF8
    ctx->pc = 0x128480u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955272));
    // 0x128484: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x128484u;
    SET_GPR_U32(ctx, 31, 0x12848Cu);
    ctx->pc = 0x128488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128484u;
            // 0x128488: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12848Cu; }
        if (ctx->pc != 0x12848Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12848Cu; }
        if (ctx->pc != 0x12848Cu) { return; }
    }
    ctx->pc = 0x12848Cu;
label_12848c:
    // 0x12848c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12848cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x128490: 0x2484cd00  addiu       $a0, $a0, -0x3300
    ctx->pc = 0x128490u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954240));
    // 0x128494: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128494u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128498: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x128498u;
    SET_GPR_U32(ctx, 31, 0x1284A0u);
    ctx->pc = 0x12849Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128498u;
            // 0x12849c: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1284A0u; }
        if (ctx->pc != 0x1284A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1284A0u; }
        if (ctx->pc != 0x1284A0u) { return; }
    }
    ctx->pc = 0x1284A0u;
label_1284a0:
    // 0x1284a0: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1284a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1284a4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1284a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1284a8: 0x2484c8c0  addiu       $a0, $a0, -0x3740
    ctx->pc = 0x1284a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953152));
    // 0x1284ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1284acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1284b0: 0x24060440  addiu       $a2, $zero, 0x440
    ctx->pc = 0x1284b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1088));
    // 0x1284b4: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1284B4u;
    ctx->pc = 0x1284B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1284B4u;
            // 0x1284b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1284BCu;
    // 0x1284bc: 0x0  nop
    ctx->pc = 0x1284bcu;
    // NOP
label_1284c0:
    // 0x1284c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1284c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1284c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1284C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1284C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1284C4u;
            // 0x1284c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128438u: goto label_128438;
            case 0x128478u: goto label_128478;
            case 0x12848Cu: goto label_12848c;
            case 0x1284A0u: goto label_1284a0;
            case 0x1284C0u: goto label_1284c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1284CCu;
    // 0x1284cc: 0x0  nop
    ctx->pc = 0x1284ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
