#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001746A8
// Address: 0x1746a8 - 0x174700
void sub_001746A8_0x1746a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001746A8_0x1746a8");
#endif

    switch (ctx->pc) {
        case 0x1746c4u: goto label_1746c4;
        default: break;
    }

    ctx->pc = 0x1746a8u;

    // 0x1746a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1746a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1746ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1746acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1746b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1746b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1746b4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1746b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1746b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1746b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1746bc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1746BCu;
    SET_GPR_U32(ctx, 31, 0x1746C4u);
    ctx->pc = 0x1746C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1746BCu;
            // 0x1746c0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1746C4u; }
        if (ctx->pc != 0x1746C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1746C4u; }
        if (ctx->pc != 0x1746C4u) { return; }
    }
    ctx->pc = 0x1746C4u;
label_1746c4:
    // 0x1746c4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1746c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1746c8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1746C8u;
    {
        const bool branch_taken_0x1746c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1746CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1746C8u;
            // 0x1746cc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1746c8) {
            ctx->pc = 0x1746E8u;
            goto label_1746e8;
        }
    }
    ctx->pc = 0x1746D0u;
    // 0x1746d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1746d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1746d4: 0x34a50151  ori         $a1, $a1, 0x151
    ctx->pc = 0x1746d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)337);
    // 0x1746d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1746d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1746dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1746dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1746e0: 0x805a704  j           func_169C10
    ctx->pc = 0x1746E0u;
    ctx->pc = 0x1746E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1746E0u;
            // 0x1746e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1746E8u;
label_1746e8:
    // 0x1746e8: 0xae112ab0  sw          $s1, 0x2AB0($s0)
    ctx->pc = 0x1746e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 10928), GPR_U32(ctx, 17));
    // 0x1746ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1746ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1746f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1746f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1746f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1746f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1746f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1746F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1746FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1746F8u;
            // 0x1746fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1746C4u: goto label_1746c4;
            case 0x1746E8u: goto label_1746e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174700u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
