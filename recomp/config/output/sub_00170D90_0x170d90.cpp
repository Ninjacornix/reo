#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170D90
// Address: 0x170d90 - 0x170e60
void sub_00170D90_0x170d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170D90_0x170d90");
#endif

    switch (ctx->pc) {
        case 0x170db0u: goto label_170db0;
        case 0x170e00u: goto label_170e00;
        case 0x170e20u: goto label_170e20;
        case 0x170e48u: goto label_170e48;
        default: break;
    }

    ctx->pc = 0x170d90u;

    // 0x170d90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x170d94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x170d94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170d98: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170d98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170d9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x170d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170da0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x170da0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170da4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x170da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x170da8: 0xc045198  jal         func_114660
    ctx->pc = 0x170DA8u;
    SET_GPR_U32(ctx, 31, 0x170DB0u);
    ctx->pc = 0x170DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170DA8u;
            // 0x170dac: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170DB0u; }
        if (ctx->pc != 0x170DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170DB0u; }
        if (ctx->pc != 0x170DB0u) { return; }
    }
    ctx->pc = 0x170DB0u;
label_170db0:
    // 0x170db0: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x170db0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x170db4: 0xde020048  ld          $v0, 0x48($s0)
    ctx->pc = 0x170db4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x170db8: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x170db8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x170dbc: 0x8e040040  lw          $a0, 0x40($s0)
    ctx->pc = 0x170dbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x170dc0: 0x222102d  daddu       $v0, $s1, $v0
    ctx->pc = 0x170dc0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 2));
    // 0x170dc4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170dc4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x170dc8: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x170dc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x170dcc: 0xfe020048  sd          $v0, 0x48($s0)
    ctx->pc = 0x170dccu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 2));
    // 0x170dd0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x170dd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170dd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170dd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170dd8: 0x8045190  j           func_114640
    ctx->pc = 0x170DD8u;
    ctx->pc = 0x170DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170DD8u;
            // 0x170ddc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x170DE0u;
    // 0x170de0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170de0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x170de4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x170de4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170de8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170de8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170dec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x170decu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170df0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x170df0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170df4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x170df4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x170df8: 0xc045198  jal         func_114660
    ctx->pc = 0x170DF8u;
    SET_GPR_U32(ctx, 31, 0x170E00u);
    ctx->pc = 0x170DFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170DF8u;
            // 0x170dfc: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170E00u; }
        if (ctx->pc != 0x170E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170E00u; }
        if (ctx->pc != 0x170E00u) { return; }
    }
    ctx->pc = 0x170E00u;
label_170e00:
    // 0x170e00: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x170e00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x170e04: 0xde020048  ld          $v0, 0x48($s0)
    ctx->pc = 0x170e04u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x170e08: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x170e08u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x170e0c: 0x51102f  dsubu       $v0, $v0, $s1
    ctx->pc = 0x170e0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 17));
    // 0x170e10: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x170e10u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x170e14: 0x461000a  bgez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x170E14u;
    {
        const bool branch_taken_0x170e14 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x170E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170E14u;
            // 0x170e18: 0xfe020048  sd          $v0, 0x48($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170e14) {
            ctx->pc = 0x170E40u;
            goto label_170e40;
        }
    }
    ctx->pc = 0x170E1Cu;
    // 0x170e1c: 0x0  nop
    ctx->pc = 0x170e1cu;
    // NOP
label_170e20:
    // 0x170e20: 0x0  nop
    ctx->pc = 0x170e20u;
    // NOP
    // 0x170e24: 0x0  nop
    ctx->pc = 0x170e24u;
    // NOP
    // 0x170e28: 0x0  nop
    ctx->pc = 0x170e28u;
    // NOP
    // 0x170e2c: 0x0  nop
    ctx->pc = 0x170e2cu;
    // NOP
    // 0x170e30: 0x0  nop
    ctx->pc = 0x170e30u;
    // NOP
    // 0x170e34: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x170E34u;
    {
        const bool branch_taken_0x170e34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x170e34) {
            ctx->pc = 0x170E20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_170e20;
        }
    }
    ctx->pc = 0x170E3Cu;
    // 0x170e3c: 0x0  nop
    ctx->pc = 0x170e3cu;
    // NOP
label_170e40:
    // 0x170e40: 0xc045190  jal         func_114640
    ctx->pc = 0x170E40u;
    SET_GPR_U32(ctx, 31, 0x170E48u);
    ctx->pc = 0x170E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170E40u;
            // 0x170e44: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170E48u; }
        if (ctx->pc != 0x170E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170E48u; }
        if (ctx->pc != 0x170E48u) { return; }
    }
    ctx->pc = 0x170E48u;
label_170e48:
    // 0x170e48: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x170e48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170e4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170e4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170e50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170e50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x170e54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x170e54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170e58: 0x3e00008  jr          $ra
    ctx->pc = 0x170E58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170E58u;
            // 0x170e5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170DB0u: goto label_170db0;
            case 0x170E00u: goto label_170e00;
            case 0x170E20u: goto label_170e20;
            case 0x170E40u: goto label_170e40;
            case 0x170E48u: goto label_170e48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170E60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
