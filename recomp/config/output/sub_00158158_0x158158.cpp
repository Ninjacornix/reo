#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158158
// Address: 0x158158 - 0x1581d0
void sub_00158158_0x158158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158158_0x158158");
#endif

    switch (ctx->pc) {
        case 0x158190u: goto label_158190;
        case 0x1581a4u: goto label_1581a4;
        case 0x1581b8u: goto label_1581b8;
        default: break;
    }

    ctx->pc = 0x158158u;

    // 0x158158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x158158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15815c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15815cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x158160: 0x8c43d870  lw          $v1, -0x2790($v0)
    ctx->pc = 0x158160u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957168)));
    // 0x158164: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158168: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x158168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15816c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15816cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x158170: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x158170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x158174: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x158174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x158178: 0x1840000d  blez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x158178u;
    {
        const bool branch_taken_0x158178 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x15817Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158178u;
            // 0x15817c: 0x24640010  addiu       $a0, $v1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158178) {
            ctx->pc = 0x1581B0u;
            goto label_1581b0;
        }
    }
    ctx->pc = 0x158180u;
    // 0x158180: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x158180u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158184: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x158184u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158188: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x158188u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15818c: 0x0  nop
    ctx->pc = 0x15818cu;
    // NOP
label_158190:
    // 0x158190: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x158190u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x158194: 0x50520004  beql        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x158194u;
    {
        const bool branch_taken_0x158194 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        if (branch_taken_0x158194) {
            ctx->pc = 0x158198u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158194u;
            // 0x158198: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1581A8u;
            goto label_1581a8;
        }
    }
    ctx->pc = 0x15819Cu;
    // 0x15819c: 0xc05615a  jal         func_158568
    ctx->pc = 0x15819Cu;
    SET_GPR_U32(ctx, 31, 0x1581A4u);
    ctx->pc = 0x1581A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15819Cu;
            // 0x1581a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158568u;
    if (runtime->hasFunction(0x158568u)) {
        auto targetFn = runtime->lookupFunction(0x158568u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1581A4u; }
        if (ctx->pc != 0x1581A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158568_0x158568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1581A4u; }
        if (ctx->pc != 0x1581A4u) { return; }
    }
    ctx->pc = 0x1581A4u;
label_1581a4:
    // 0x1581a4: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1581a4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_1581a8:
    // 0x1581a8: 0x1620fff9  bnez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1581A8u;
    {
        const bool branch_taken_0x1581a8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1581ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1581A8u;
            // 0x1581ac: 0x261000c0  addiu       $s0, $s0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1581a8) {
            ctx->pc = 0x158190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_158190;
        }
    }
    ctx->pc = 0x1581B0u;
label_1581b0:
    // 0x1581b0: 0xc0558e8  jal         func_1563A0
    ctx->pc = 0x1581B0u;
    SET_GPR_U32(ctx, 31, 0x1581B8u);
    ctx->pc = 0x1563A0u;
    if (runtime->hasFunction(0x1563A0u)) {
        auto targetFn = runtime->lookupFunction(0x1563A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1581B8u; }
        if (ctx->pc != 0x1581B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001563A0_0x1563a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1581B8u; }
        if (ctx->pc != 0x1581B8u) { return; }
    }
    ctx->pc = 0x1581B8u;
label_1581b8:
    // 0x1581b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1581b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1581bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1581bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1581c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1581c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1581c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1581c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1581c8: 0x8055f72  j           func_157DC8
    ctx->pc = 0x1581C8u;
    ctx->pc = 0x1581CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1581C8u;
            // 0x1581cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157DC8u;
    if (runtime->hasFunction(0x157DC8u)) {
        auto targetFn = runtime->lookupFunction(0x157DC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00157DC8_0x157dc8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1581D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
