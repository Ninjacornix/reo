#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170630
// Address: 0x170630 - 0x1706d0
void sub_00170630_0x170630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170630_0x170630");
#endif

    switch (ctx->pc) {
        case 0x170648u: goto label_170648;
        case 0x170668u: goto label_170668;
        case 0x1706b8u: goto label_1706b8;
        default: break;
    }

    ctx->pc = 0x170630u;

    // 0x170630: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x170634: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x170634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x170638: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170638u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17063c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17063cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x170640: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x170640u;
    SET_GPR_U32(ctx, 31, 0x170648u);
    ctx->pc = 0x170644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170640u;
            // 0x170644: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170648u; }
        if (ctx->pc != 0x170648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170648u; }
        if (ctx->pc != 0x170648u) { return; }
    }
    ctx->pc = 0x170648u;
label_170648:
    // 0x170648: 0x8e021b30  lw          $v0, 0x1B30($s0)
    ctx->pc = 0x170648u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
    // 0x17064c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x17064cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170650: 0x8c440138  lw          $a0, 0x138($v0)
    ctx->pc = 0x170650u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 312)));
    // 0x170654: 0x18800014  blez        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x170654u;
    {
        const bool branch_taken_0x170654 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x170658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170654u;
            // 0x170658: 0x2450013c  addiu       $s0, $v0, 0x13C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 316));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170654) {
            ctx->pc = 0x1706A8u;
            goto label_1706a8;
        }
    }
    ctx->pc = 0x17065Cu;
    // 0x17065c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x17065Cu;
    {
        const bool branch_taken_0x17065c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x170660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17065Cu;
            // 0x170660: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17065c) {
            ctx->pc = 0x170678u;
            goto label_170678;
        }
    }
    ctx->pc = 0x170664u;
    // 0x170664: 0x0  nop
    ctx->pc = 0x170664u;
    // NOP
label_170668:
    // 0x170668: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x170668u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x17066c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x17066Cu;
    {
        const bool branch_taken_0x17066c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x170670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17066Cu;
            // 0x170670: 0x26100080  addiu       $s0, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17066c) {
            ctx->pc = 0x1706A8u;
            goto label_1706a8;
        }
    }
    ctx->pc = 0x170674u;
    // 0x170674: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x170674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_170678:
    // 0x170678: 0x0  nop
    ctx->pc = 0x170678u;
    // NOP
    // 0x17067c: 0x0  nop
    ctx->pc = 0x17067cu;
    // NOP
    // 0x170680: 0x0  nop
    ctx->pc = 0x170680u;
    // NOP
    // 0x170684: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x170684u;
    {
        const bool branch_taken_0x170684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x170684) {
            ctx->pc = 0x170688u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170684u;
            // 0x170688: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170668u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_170668;
        }
    }
    ctx->pc = 0x17068Cu;
    // 0x17068c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x17068cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x170690: 0x0  nop
    ctx->pc = 0x170690u;
    // NOP
    // 0x170694: 0x0  nop
    ctx->pc = 0x170694u;
    // NOP
    // 0x170698: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x170698u;
    {
        const bool branch_taken_0x170698 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x170698) {
            ctx->pc = 0x17069Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170698u;
            // 0x17069c: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170668u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_170668;
        }
    }
    ctx->pc = 0x1706A0u;
    // 0x1706a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1706a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1706a4: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1706a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_1706a8:
    // 0x1706a8: 0x641026  xor         $v0, $v1, $a0
    ctx->pc = 0x1706a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 4));
    // 0x1706ac: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1706acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1706b0: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1706B0u;
    SET_GPR_U32(ctx, 31, 0x1706B8u);
    ctx->pc = 0x1706B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1706B0u;
            // 0x1706b4: 0x2800a  movz        $s0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1706B8u; }
        if (ctx->pc != 0x1706B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1706B8u; }
        if (ctx->pc != 0x1706B8u) { return; }
    }
    ctx->pc = 0x1706B8u;
label_1706b8:
    // 0x1706b8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1706b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1706bc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1706bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1706c0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1706c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1706c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1706C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1706C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1706C4u;
            // 0x1706c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170648u: goto label_170648;
            case 0x170668u: goto label_170668;
            case 0x170678u: goto label_170678;
            case 0x1706A8u: goto label_1706a8;
            case 0x1706B8u: goto label_1706b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1706CCu;
    // 0x1706cc: 0x0  nop
    ctx->pc = 0x1706ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
