#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100E18
// Address: 0x100e18 - 0x100e88
void sub_00100E18_0x100e18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100E18_0x100e18");
#endif

    switch (ctx->pc) {
        case 0x100e40u: goto label_100e40;
        case 0x100e48u: goto label_100e48;
        case 0x100e50u: goto label_100e50;
        case 0x100e58u: goto label_100e58;
        case 0x100e74u: goto label_100e74;
        default: break;
    }

    ctx->pc = 0x100e18u;

    // 0x100e18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x100e18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x100e1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x100e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x100e20: 0x14800011  bnez        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x100E20u;
    {
        const bool branch_taken_0x100e20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x100E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100E20u;
            // 0x100e24: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100e20) {
            ctx->pc = 0x100E68u;
            goto label_100e68;
        }
    }
    ctx->pc = 0x100E28u;
    // 0x100e28: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100e28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100e2c: 0x8c437910  lw          $v1, 0x7910($v0)
    ctx->pc = 0x100e2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100e30: 0x18600003  blez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x100E30u;
    {
        const bool branch_taken_0x100e30 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100E30u;
            // 0x100e34: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100e30) {
            ctx->pc = 0x100E40u;
            goto label_100e40;
        }
    }
    ctx->pc = 0x100E38u;
    // 0x100e38: 0xc045a12  jal         func_116848
    ctx->pc = 0x100E38u;
    SET_GPR_U32(ctx, 31, 0x100E40u);
    ctx->pc = 0x100E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100E38u;
            // 0x100e3c: 0x24847568  addiu       $a0, $a0, 0x7568 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30056));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E40u; }
        if (ctx->pc != 0x100E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E40u; }
        if (ctx->pc != 0x100E40u) { return; }
    }
    ctx->pc = 0x100E40u;
label_100e40:
    // 0x100e40: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x100E40u;
    {
        const bool branch_taken_0x100e40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100E40u;
            // 0x100e44: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100e40) {
            ctx->pc = 0x100E50u;
            goto label_100e50;
        }
    }
    ctx->pc = 0x100E48u;
label_100e48:
    // 0x100e48: 0xc0455a0  jal         func_115680
    ctx->pc = 0x100E48u;
    SET_GPR_U32(ctx, 31, 0x100E50u);
    ctx->pc = 0x100E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100E48u;
            // 0x100e4c: 0x24040fa0  addiu       $a0, $zero, 0xFA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115680u;
    if (runtime->hasFunction(0x115680u)) {
        auto targetFn = runtime->lookupFunction(0x115680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E50u; }
        if (ctx->pc != 0x100E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115680_0x115680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E50u; }
        if (ctx->pc != 0x100E50u) { return; }
    }
    ctx->pc = 0x100E50u;
label_100e50:
    // 0x100e50: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x100E50u;
    SET_GPR_U32(ctx, 31, 0x100E58u);
    ctx->pc = 0x100E54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100E50u;
            // 0x100e54: 0x26049480  addiu       $a0, $s0, -0x6B80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4294939776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E58u; }
        if (ctx->pc != 0x100E58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E58u; }
        if (ctx->pc != 0x100E58u) { return; }
    }
    ctx->pc = 0x100E58u;
label_100e58:
    // 0x100e58: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x100E58u;
    {
        const bool branch_taken_0x100e58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100E58u;
            // 0x100e5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100e58) {
            ctx->pc = 0x100E48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100e48;
        }
    }
    ctx->pc = 0x100E60u;
    // 0x100e60: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x100E60u;
    {
        const bool branch_taken_0x100e60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100E60u;
            // 0x100e64: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100e60) {
            ctx->pc = 0x100E78u;
            goto label_100e78;
        }
    }
    ctx->pc = 0x100E68u;
label_100e68:
    // 0x100e68: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x100e68u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x100e6c: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x100E6Cu;
    SET_GPR_U32(ctx, 31, 0x100E74u);
    ctx->pc = 0x100E70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100E6Cu;
            // 0x100e70: 0x24849480  addiu       $a0, $a0, -0x6B80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E74u; }
        if (ctx->pc != 0x100E74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100E74u; }
        if (ctx->pc != 0x100E74u) { return; }
    }
    ctx->pc = 0x100E74u;
label_100e74:
    // 0x100e74: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x100e74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_100e78:
    // 0x100e78: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x100e78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100e7c: 0x3e00008  jr          $ra
    ctx->pc = 0x100E7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100E7Cu;
            // 0x100e80: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100E40u: goto label_100e40;
            case 0x100E48u: goto label_100e48;
            case 0x100E50u: goto label_100e50;
            case 0x100E58u: goto label_100e58;
            case 0x100E68u: goto label_100e68;
            case 0x100E74u: goto label_100e74;
            case 0x100E78u: goto label_100e78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100E84u;
    // 0x100e84: 0x0  nop
    ctx->pc = 0x100e84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
