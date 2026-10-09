#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CDB8
// Address: 0x11cdb8 - 0x11ce18
void sub_0011CDB8_0x11cdb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CDB8_0x11cdb8");
#endif

    switch (ctx->pc) {
        case 0x11cde8u: goto label_11cde8;
        case 0x11cdf4u: goto label_11cdf4;
        case 0x11ce00u: goto label_11ce00;
        default: break;
    }

    ctx->pc = 0x11cdb8u;

    // 0x11cdb8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11cdb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11cdbc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11cdbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11cdc0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11cdc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11cdc4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11cdc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11cdc8: 0x3c100012  lui         $s0, 0x12
    ctx->pc = 0x11cdc8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)18 << 16));
    // 0x11cdcc: 0x2610d300  addiu       $s0, $s0, -0x2D00
    ctx->pc = 0x11cdccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294955776));
    // 0x11cdd0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11cdd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cdd4: 0xac51a138  sw          $s1, -0x5EC8($v0)
    ctx->pc = 0x11cdd4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294943032), GPR_U32(ctx, 17));
    // 0x11cdd8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11cdd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cddc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11cddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11cde0: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CDE0u;
    SET_GPR_U32(ctx, 31, 0x11CDE8u);
    ctx->pc = 0x11CDE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CDE0u;
            // 0x11cde4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDE8u; }
        if (ctx->pc != 0x11CDE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDE8u; }
        if (ctx->pc != 0x11CDE8u) { return; }
    }
    ctx->pc = 0x11CDE8u;
label_11cde8:
    // 0x11cde8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11cde8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cdec: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CDECu;
    SET_GPR_U32(ctx, 31, 0x11CDF4u);
    ctx->pc = 0x11CDF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CDECu;
            // 0x11cdf0: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDF4u; }
        if (ctx->pc != 0x11CDF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDF4u; }
        if (ctx->pc != 0x11CDF4u) { return; }
    }
    ctx->pc = 0x11CDF4u;
label_11cdf4:
    // 0x11cdf4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11cdf4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cdf8: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CDF8u;
    SET_GPR_U32(ctx, 31, 0x11CE00u);
    ctx->pc = 0x11CDFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CDF8u;
            // 0x11cdfc: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE00u; }
        if (ctx->pc != 0x11CE00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE00u; }
        if (ctx->pc != 0x11CE00u) { return; }
    }
    ctx->pc = 0x11CE00u;
label_11ce00:
    // 0x11ce00: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x11ce00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce04: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ce04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ce08: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ce08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ce0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ce0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ce10: 0x3e00008  jr          $ra
    ctx->pc = 0x11CE10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CE14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE10u;
            // 0x11ce14: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CDE8u: goto label_11cde8;
            case 0x11CDF4u: goto label_11cdf4;
            case 0x11CE00u: goto label_11ce00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CE18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
