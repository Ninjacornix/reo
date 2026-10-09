#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173860
// Address: 0x173860 - 0x1738c0
void sub_00173860_0x173860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173860_0x173860");
#endif

    switch (ctx->pc) {
        case 0x173888u: goto label_173888;
        case 0x173890u: goto label_173890;
        case 0x17389cu: goto label_17389c;
        default: break;
    }

    ctx->pc = 0x173860u;

    // 0x173860: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173864: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x173864u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173868: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x173868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17386c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17386cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173870: 0x24060030  addiu       $a2, $zero, 0x30
    ctx->pc = 0x173870u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x173874: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173878: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x173878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17387c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17387cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x173880: 0xc0558b4  jal         func_1562D0
    ctx->pc = 0x173880u;
    SET_GPR_U32(ctx, 31, 0x173888u);
    ctx->pc = 0x173884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173880u;
            // 0x173884: 0x24110004  addiu       $s1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173888u; }
        if (ctx->pc != 0x173888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001562D0_0x1562d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173888u; }
        if (ctx->pc != 0x173888u) { return; }
    }
    ctx->pc = 0x173888u;
label_173888:
    // 0x173888: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x173888u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17388c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17388cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_173890:
    // 0x173890: 0x26100020  addiu       $s0, $s0, 0x20
    ctx->pc = 0x173890u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    // 0x173894: 0xc05dd14  jal         func_177450
    ctx->pc = 0x173894u;
    SET_GPR_U32(ctx, 31, 0x17389Cu);
    ctx->pc = 0x173898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173894u;
            // 0x173898: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177450u;
    if (runtime->hasFunction(0x177450u)) {
        auto targetFn = runtime->lookupFunction(0x177450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17389Cu; }
        if (ctx->pc != 0x17389Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177450_0x177450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17389Cu; }
        if (ctx->pc != 0x17389Cu) { return; }
    }
    ctx->pc = 0x17389Cu;
label_17389c:
    // 0x17389c: 0x621fffc  bgez        $s1, . + 4 + (-0x4 << 2)
    ctx->pc = 0x17389Cu;
    {
        const bool branch_taken_0x17389c = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1738A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17389Cu;
            // 0x1738a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17389c) {
            ctx->pc = 0x173890u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173890;
        }
    }
    ctx->pc = 0x1738A4u;
    // 0x1738a4: 0x264400a0  addiu       $a0, $s2, 0xA0
    ctx->pc = 0x1738a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 160));
    // 0x1738a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1738a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1738ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1738acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1738b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1738b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1738b4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1738b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1738b8: 0x805dd14  j           func_177450
    ctx->pc = 0x1738B8u;
    ctx->pc = 0x1738BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1738B8u;
            // 0x1738bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177450u;
    if (runtime->hasFunction(0x177450u)) {
        auto targetFn = runtime->lookupFunction(0x177450u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177450_0x177450(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1738C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
