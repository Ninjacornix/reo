#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FDB0
// Address: 0x15fdb0 - 0x15fe2c
void sub_0015FDB0_0x15fdb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FDB0_0x15fdb0");
#endif

    switch (ctx->pc) {
        case 0x15fdccu: goto label_15fdcc;
        case 0x15fdf8u: goto label_15fdf8;
        default: break;
    }

    ctx->pc = 0x15fdb0u;

    // 0x15fdb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fdb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fdb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fdb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fdb8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fdb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fdbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15fdbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15fdc0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15fdc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15fdc4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FDC4u;
    SET_GPR_U32(ctx, 31, 0x15FDCCu);
    ctx->pc = 0x15FDC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDC4u;
            // 0x15fdc8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDCCu; }
        if (ctx->pc != 0x15FDCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDCCu; }
        if (ctx->pc != 0x15FDCCu) { return; }
    }
    ctx->pc = 0x15FDCCu;
label_15fdcc:
    // 0x15fdcc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fdccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fdd0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15fdd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fdd4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FDD4u;
    {
        const bool branch_taken_0x15fdd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FDD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDD4u;
            // 0x15fdd8: 0x2484f458  addiu       $a0, $a0, -0xBA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964312));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fdd4) {
            ctx->pc = 0x15FDF0u;
            goto label_15fdf0;
        }
    }
    ctx->pc = 0x15FDDCu;
    // 0x15fddc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fddcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fde0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fde0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fde4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fde4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fde8: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FDE8u;
    ctx->pc = 0x15FDECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDE8u;
            // 0x15fdec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FDF0u;
label_15fdf0:
    // 0x15fdf0: 0xc05c8ec  jal         func_1723B0
    ctx->pc = 0x15FDF0u;
    SET_GPR_U32(ctx, 31, 0x15FDF8u);
    ctx->pc = 0x15FDF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDF0u;
            // 0x15fdf4: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1723B0u;
    if (runtime->hasFunction(0x1723B0u)) {
        auto targetFn = runtime->lookupFunction(0x1723B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDF8u; }
        if (ctx->pc != 0x15FDF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001723B0_0x1723b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDF8u; }
        if (ctx->pc != 0x15FDF8u) { return; }
    }
    ctx->pc = 0x15FDF8u;
label_15fdf8:
    // 0x15fdf8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fdf8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fdfc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FDFCu;
    {
        const bool branch_taken_0x15fdfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FE00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDFCu;
            // 0x15fe00: 0x2484f488  addiu       $a0, $a0, -0xB78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964360));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fdfc) {
            ctx->pc = 0x15FE18u;
            goto label_15fe18;
        }
    }
    ctx->pc = 0x15FE04u;
    // 0x15fe04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fe04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fe08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fe08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fe0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fe0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fe10: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FE10u;
    ctx->pc = 0x15FE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE10u;
            // 0x15fe14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FE18u;
label_15fe18:
    // 0x15fe18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fe18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fe1c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fe1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fe20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fe20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fe24: 0x3e00008  jr          $ra
    ctx->pc = 0x15FE24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE24u;
            // 0x15fe28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FDCCu: goto label_15fdcc;
            case 0x15FDF0u: goto label_15fdf0;
            case 0x15FDF8u: goto label_15fdf8;
            case 0x15FE18u: goto label_15fe18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FE2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
