#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001890B0
// Address: 0x1890b0 - 0x189120
void sub_001890B0_0x1890b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001890B0_0x1890b0");
#endif

    switch (ctx->pc) {
        case 0x1890f8u: goto label_1890f8;
        case 0x18910cu: goto label_18910c;
        default: break;
    }

    ctx->pc = 0x1890b0u;

    // 0x1890b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1890b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1890b4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1890b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1890b8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1890b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1890bc: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x1890bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x1890c0: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x1890c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x1890c4: 0xac440c00  sw          $a0, 0xC00($v0)
    ctx->pc = 0x1890c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 4));
    // 0x1890c8: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x1890c8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1890cc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1890ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1890d0: 0x24640b88  addiu       $a0, $v1, 0xB88
    ctx->pc = 0x1890d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2952));
    // 0x1890d4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1890d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1890d8: 0x34a51317  ori         $a1, $a1, 0x1317
    ctx->pc = 0x1890d8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4887);
    // 0x1890dc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1890dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1890e0: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1890e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1890e4: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x1890e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1890e8: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1890e8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1890ec: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x1890ecu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1890f0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1890F0u;
    SET_GPR_U32(ctx, 31, 0x1890F8u);
    ctx->pc = 0x1890F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1890F0u;
            // 0x1890f4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1890F8u; }
        if (ctx->pc != 0x1890F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1890F8u; }
        if (ctx->pc != 0x1890F8u) { return; }
    }
    ctx->pc = 0x1890F8u;
label_1890f8:
    // 0x1890f8: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1890F8u;
    {
        const bool branch_taken_0x1890f8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1890f8) {
            ctx->pc = 0x1890FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1890F8u;
            // 0x1890fc: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x189110u;
            goto label_189110;
        }
    }
    ctx->pc = 0x189100u;
    // 0x189100: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189100u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189104: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189104u;
    SET_GPR_U32(ctx, 31, 0x18910Cu);
    ctx->pc = 0x189108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189104u;
            // 0x189108: 0x248419c0  addiu       $a0, $a0, 0x19C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18910Cu; }
        if (ctx->pc != 0x18910Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18910Cu; }
        if (ctx->pc != 0x18910Cu) { return; }
    }
    ctx->pc = 0x18910Cu;
label_18910c:
    // 0x18910c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18910cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_189110:
    // 0x189110: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x189110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189114: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x189114u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189118: 0x3e00008  jr          $ra
    ctx->pc = 0x189118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18911Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189118u;
            // 0x18911c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1890F8u: goto label_1890f8;
            case 0x18910Cu: goto label_18910c;
            case 0x189110u: goto label_189110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
