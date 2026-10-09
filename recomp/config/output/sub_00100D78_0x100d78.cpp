#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100D78
// Address: 0x100d78 - 0x100e18
void sub_00100D78_0x100d78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100D78_0x100d78");
#endif

    switch (ctx->pc) {
        case 0x100da4u: goto label_100da4;
        case 0x100db0u: goto label_100db0;
        case 0x100db8u: goto label_100db8;
        case 0x100dccu: goto label_100dcc;
        case 0x100df8u: goto label_100df8;
        default: break;
    }

    ctx->pc = 0x100d78u;

    // 0x100d78: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x100d78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x100d7c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x100d7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x100d80: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100d80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100d84: 0x14800015  bnez        $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x100D84u;
    {
        const bool branch_taken_0x100d84 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x100D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100D84u;
            // 0x100d88: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100d84) {
            ctx->pc = 0x100DDCu;
            goto label_100ddc;
        }
    }
    ctx->pc = 0x100D8Cu;
    // 0x100d8c: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100d90: 0x8c437910  lw          $v1, 0x7910($v0)
    ctx->pc = 0x100d90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100d94: 0x18600003  blez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x100D94u;
    {
        const bool branch_taken_0x100d94 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100D94u;
            // 0x100d98: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100d94) {
            ctx->pc = 0x100DA4u;
            goto label_100da4;
        }
    }
    ctx->pc = 0x100D9Cu;
    // 0x100d9c: 0xc045a12  jal         func_116848
    ctx->pc = 0x100D9Cu;
    SET_GPR_U32(ctx, 31, 0x100DA4u);
    ctx->pc = 0x100DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100D9Cu;
            // 0x100da0: 0x24847558  addiu       $a0, $a0, 0x7558 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30040));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DA4u; }
        if (ctx->pc != 0x100DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DA4u; }
        if (ctx->pc != 0x100DA4u) { return; }
    }
    ctx->pc = 0x100DA4u;
label_100da4:
    // 0x100da4: 0x3c110020  lui         $s1, 0x20
    ctx->pc = 0x100da4u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
    // 0x100da8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x100DA8u;
    {
        const bool branch_taken_0x100da8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100DA8u;
            // 0x100dac: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100da8) {
            ctx->pc = 0x100DB8u;
            goto label_100db8;
        }
    }
    ctx->pc = 0x100DB0u;
label_100db0:
    // 0x100db0: 0xc0455a0  jal         func_115680
    ctx->pc = 0x100DB0u;
    SET_GPR_U32(ctx, 31, 0x100DB8u);
    ctx->pc = 0x100DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100DB0u;
            // 0x100db4: 0x24040fa0  addiu       $a0, $zero, 0xFA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115680u;
    if (runtime->hasFunction(0x115680u)) {
        auto targetFn = runtime->lookupFunction(0x115680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DB8u; }
        if (ctx->pc != 0x100DB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115680_0x115680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DB8u; }
        if (ctx->pc != 0x100DB8u) { return; }
    }
    ctx->pc = 0x100DB8u;
label_100db8:
    // 0x100db8: 0x8e227934  lw          $v0, 0x7934($s1)
    ctx->pc = 0x100db8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31028)));
    // 0x100dbc: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x100DBCu;
    {
        const bool branch_taken_0x100dbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x100dbc) {
            ctx->pc = 0x100DB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100db0;
        }
    }
    ctx->pc = 0x100DC4u;
    // 0x100dc4: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x100DC4u;
    SET_GPR_U32(ctx, 31, 0x100DCCu);
    ctx->pc = 0x100DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100DC4u;
            // 0x100dc8: 0x26048ad0  addiu       $a0, $s0, -0x7530 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4294937296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DCCu; }
        if (ctx->pc != 0x100DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DCCu; }
        if (ctx->pc != 0x100DCCu) { return; }
    }
    ctx->pc = 0x100DCCu;
label_100dcc:
    // 0x100dcc: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x100DCCu;
    {
        const bool branch_taken_0x100dcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100DCCu;
            // 0x100dd0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100dcc) {
            ctx->pc = 0x100DB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100db0;
        }
    }
    ctx->pc = 0x100DD4u;
    // 0x100dd4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x100DD4u;
    {
        const bool branch_taken_0x100dd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100DD4u;
            // 0x100dd8: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100dd4) {
            ctx->pc = 0x100E08u;
            goto label_100e08;
        }
    }
    ctx->pc = 0x100DDCu;
label_100ddc:
    // 0x100ddc: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100de0: 0x8c437934  lw          $v1, 0x7934($v0)
    ctx->pc = 0x100de0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31028)));
    // 0x100de4: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x100DE4u;
    {
        const bool branch_taken_0x100de4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x100DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100DE4u;
            // 0x100de8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100de4) {
            ctx->pc = 0x100E04u;
            goto label_100e04;
        }
    }
    ctx->pc = 0x100DECu;
    // 0x100dec: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x100decu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x100df0: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x100DF0u;
    SET_GPR_U32(ctx, 31, 0x100DF8u);
    ctx->pc = 0x100DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100DF0u;
            // 0x100df4: 0x24848ad0  addiu       $a0, $a0, -0x7530 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DF8u; }
        if (ctx->pc != 0x100DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100DF8u; }
        if (ctx->pc != 0x100DF8u) { return; }
    }
    ctx->pc = 0x100DF8u;
label_100df8:
    // 0x100df8: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x100DF8u;
    {
        const bool branch_taken_0x100df8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100DF8u;
            // 0x100dfc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100df8) {
            ctx->pc = 0x100E04u;
            goto label_100e04;
        }
    }
    ctx->pc = 0x100E00u;
    // 0x100e00: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x100e00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_100e04:
    // 0x100e04: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x100e04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_100e08:
    // 0x100e08: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x100e08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100e0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x100e0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100e10: 0x3e00008  jr          $ra
    ctx->pc = 0x100E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100E10u;
            // 0x100e14: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100DA4u: goto label_100da4;
            case 0x100DB0u: goto label_100db0;
            case 0x100DB8u: goto label_100db8;
            case 0x100DCCu: goto label_100dcc;
            case 0x100DDCu: goto label_100ddc;
            case 0x100DF8u: goto label_100df8;
            case 0x100E04u: goto label_100e04;
            case 0x100E08u: goto label_100e08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100E18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
