#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117D88
// Address: 0x117d88 - 0x117e1c
void sub_00117D88_0x117d88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117D88_0x117d88");
#endif

    switch (ctx->pc) {
        case 0x117da8u: goto label_117da8;
        case 0x117dd8u: goto label_117dd8;
        case 0x117e00u: goto label_117e00;
        default: break;
    }

    ctx->pc = 0x117d88u;

    // 0x117d88: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x117d88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x117d8c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x117d8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x117d90: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117d90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117d94: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x117d94u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117d98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117d98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117d9c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x117d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x117da0: 0xc047598  jal         func_11D660
    ctx->pc = 0x117DA0u;
    SET_GPR_U32(ctx, 31, 0x117DA8u);
    ctx->pc = 0x117DA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117DA0u;
            // 0x117da4: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117DA8u; }
        if (ctx->pc != 0x117DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117DA8u; }
        if (ctx->pc != 0x117DA8u) { return; }
    }
    ctx->pc = 0x117DA8u;
label_117da8:
    // 0x117da8: 0x8e500008  lw          $s0, 0x8($s2)
    ctx->pc = 0x117da8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x117dac: 0x16110004  bne         $s0, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x117DACu;
    {
        const bool branch_taken_0x117dac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        if (branch_taken_0x117dac) {
            ctx->pc = 0x117DC0u;
            goto label_117dc0;
        }
    }
    ctx->pc = 0x117DB4u;
    // 0x117db4: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x117db4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x117db8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x117DB8u;
    {
        const bool branch_taken_0x117db8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117DB8u;
            // 0x117dbc: 0xae420008  sw          $v0, 0x8($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117db8) {
            ctx->pc = 0x117DF8u;
            goto label_117df8;
        }
    }
    ctx->pc = 0x117DC0u;
label_117dc0:
    // 0x117dc0: 0x1200000d  beqz        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x117DC0u;
    {
        const bool branch_taken_0x117dc0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117dc0) {
            ctx->pc = 0x117DF8u;
            goto label_117df8;
        }
    }
    ctx->pc = 0x117DC8u;
    // 0x117dc8: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x117dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x117dcc: 0x50710009  beql        $v1, $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x117DCCu;
    {
        const bool branch_taken_0x117dcc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 17));
        if (branch_taken_0x117dcc) {
            ctx->pc = 0x117DD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117DCCu;
            // 0x117dd0: 0x8e220038  lw          $v0, 0x38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117DF4u;
            goto label_117df4;
        }
    }
    ctx->pc = 0x117DD4u;
    // 0x117dd4: 0x0  nop
    ctx->pc = 0x117dd4u;
    // NOP
label_117dd8:
    // 0x117dd8: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x117dd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117ddc: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x117DDCu;
    {
        const bool branch_taken_0x117ddc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117ddc) {
            ctx->pc = 0x117DF8u;
            goto label_117df8;
        }
    }
    ctx->pc = 0x117DE4u;
    // 0x117de4: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x117de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x117de8: 0x1451fffb  bne         $v0, $s1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x117DE8u;
    {
        const bool branch_taken_0x117de8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x117DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117DE8u;
            // 0x117dec: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117de8) {
            ctx->pc = 0x117DD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117dd8;
        }
    }
    ctx->pc = 0x117DF0u;
    // 0x117df0: 0x8e220038  lw          $v0, 0x38($s1)
    ctx->pc = 0x117df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
label_117df4:
    // 0x117df4: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x117df4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_117df8:
    // 0x117df8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x117DF8u;
    SET_GPR_U32(ctx, 31, 0x117E00u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E00u; }
        if (ctx->pc != 0x117E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E00u; }
        if (ctx->pc != 0x117E00u) { return; }
    }
    ctx->pc = 0x117E00u;
label_117e00:
    // 0x117e00: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x117e00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117e04: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x117e04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x117e08: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x117e08u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117e0c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117e0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117e10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117e10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117e14: 0x3e00008  jr          $ra
    ctx->pc = 0x117E14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117E14u;
            // 0x117e18: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117DA8u: goto label_117da8;
            case 0x117DC0u: goto label_117dc0;
            case 0x117DD8u: goto label_117dd8;
            case 0x117DF4u: goto label_117df4;
            case 0x117DF8u: goto label_117df8;
            case 0x117E00u: goto label_117e00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117E1Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
