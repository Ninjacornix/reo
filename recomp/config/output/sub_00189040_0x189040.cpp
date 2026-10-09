#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189040
// Address: 0x189040 - 0x1890b0
void sub_00189040_0x189040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189040_0x189040");
#endif

    switch (ctx->pc) {
        case 0x189088u: goto label_189088;
        case 0x18909cu: goto label_18909c;
        default: break;
    }

    ctx->pc = 0x189040u;

    // 0x189040: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x189040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x189044: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x189044u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x189048: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x189048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x18904c: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18904cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x189050: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x189050u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x189054: 0xac440c00  sw          $a0, 0xC00($v0)
    ctx->pc = 0x189054u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 4));
    // 0x189058: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189058u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x18905c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18905cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x189060: 0x24640b88  addiu       $a0, $v1, 0xB88
    ctx->pc = 0x189060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2952));
    // 0x189064: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189064u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x189068: 0x34a51316  ori         $a1, $a1, 0x1316
    ctx->pc = 0x189068u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4886);
    // 0x18906c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18906cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189070: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x189070u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189074: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x189074u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189078: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x189078u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18907c: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x18907cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189080: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189080u;
    SET_GPR_U32(ctx, 31, 0x189088u);
    ctx->pc = 0x189084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189080u;
            // 0x189084: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189088u; }
        if (ctx->pc != 0x189088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189088u; }
        if (ctx->pc != 0x189088u) { return; }
    }
    ctx->pc = 0x189088u;
label_189088:
    // 0x189088: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x189088u;
    {
        const bool branch_taken_0x189088 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x189088) {
            ctx->pc = 0x18908Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x189088u;
            // 0x18908c: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1890A0u;
            goto label_1890a0;
        }
    }
    ctx->pc = 0x189090u;
    // 0x189090: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189090u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189094: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189094u;
    SET_GPR_U32(ctx, 31, 0x18909Cu);
    ctx->pc = 0x189098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189094u;
            // 0x189098: 0x248419a0  addiu       $a0, $a0, 0x19A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18909Cu; }
        if (ctx->pc != 0x18909Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18909Cu; }
        if (ctx->pc != 0x18909Cu) { return; }
    }
    ctx->pc = 0x18909Cu;
label_18909c:
    // 0x18909c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18909cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1890a0:
    // 0x1890a0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1890a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1890a4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1890a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1890a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1890A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1890ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1890A8u;
            // 0x1890ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189088u: goto label_189088;
            case 0x18909Cu: goto label_18909c;
            case 0x1890A0u: goto label_1890a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1890B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
