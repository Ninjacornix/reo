#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117E20
// Address: 0x117e20 - 0x117eb0
void sub_00117E20_0x117e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117E20_0x117e20");
#endif

    switch (ctx->pc) {
        case 0x117e38u: goto label_117e38;
        case 0x117e70u: goto label_117e70;
        case 0x117e98u: goto label_117e98;
        default: break;
    }

    ctx->pc = 0x117e20u;

    // 0x117e20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x117e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x117e24: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117e28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117e2c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x117e2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x117e30: 0xc047598  jal         func_11D660
    ctx->pc = 0x117E30u;
    SET_GPR_U32(ctx, 31, 0x117E38u);
    ctx->pc = 0x117E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117E30u;
            // 0x117e34: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E38u; }
        if (ctx->pc != 0x117E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E38u; }
        if (ctx->pc != 0x117E38u) { return; }
    }
    ctx->pc = 0x117E38u;
label_117e38:
    // 0x117e38: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x117e38u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x117e3c: 0x2463c9c0  addiu       $v1, $v1, -0x3640
    ctx->pc = 0x117e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953408));
    // 0x117e40: 0x8c700028  lw          $s0, 0x28($v1)
    ctx->pc = 0x117e40u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x117e44: 0x16110004  bne         $s0, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x117E44u;
    {
        const bool branch_taken_0x117e44 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        if (branch_taken_0x117e44) {
            ctx->pc = 0x117E58u;
            goto label_117e58;
        }
    }
    ctx->pc = 0x117E4Cu;
    // 0x117e4c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x117e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x117e50: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x117E50u;
    {
        const bool branch_taken_0x117e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117E50u;
            // 0x117e54: 0xac620028  sw          $v0, 0x28($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117e50) {
            ctx->pc = 0x117E90u;
            goto label_117e90;
        }
    }
    ctx->pc = 0x117E58u;
label_117e58:
    // 0x117e58: 0x1200000d  beqz        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x117E58u;
    {
        const bool branch_taken_0x117e58 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117e58) {
            ctx->pc = 0x117E90u;
            goto label_117e90;
        }
    }
    ctx->pc = 0x117E60u;
    // 0x117e60: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x117e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x117e64: 0x50710009  beql        $v1, $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x117E64u;
    {
        const bool branch_taken_0x117e64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 17));
        if (branch_taken_0x117e64) {
            ctx->pc = 0x117E68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117E64u;
            // 0x117e68: 0x8e220014  lw          $v0, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117E8Cu;
            goto label_117e8c;
        }
    }
    ctx->pc = 0x117E6Cu;
    // 0x117e6c: 0x0  nop
    ctx->pc = 0x117e6cu;
    // NOP
label_117e70:
    // 0x117e70: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x117e70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117e74: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x117E74u;
    {
        const bool branch_taken_0x117e74 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117e74) {
            ctx->pc = 0x117E90u;
            goto label_117e90;
        }
    }
    ctx->pc = 0x117E7Cu;
    // 0x117e7c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x117e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x117e80: 0x1451fffb  bne         $v0, $s1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x117E80u;
    {
        const bool branch_taken_0x117e80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x117E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117E80u;
            // 0x117e84: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117e80) {
            ctx->pc = 0x117E70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117e70;
        }
    }
    ctx->pc = 0x117E88u;
    // 0x117e88: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x117e88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_117e8c:
    // 0x117e8c: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x117e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
label_117e90:
    // 0x117e90: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x117E90u;
    SET_GPR_U32(ctx, 31, 0x117E98u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E98u; }
        if (ctx->pc != 0x117E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E98u; }
        if (ctx->pc != 0x117E98u) { return; }
    }
    ctx->pc = 0x117E98u;
label_117e98:
    // 0x117e98: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x117e98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117e9c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x117e9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117ea0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117ea0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117ea4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117ea4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117ea8: 0x3e00008  jr          $ra
    ctx->pc = 0x117EA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117EA8u;
            // 0x117eac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117E38u: goto label_117e38;
            case 0x117E58u: goto label_117e58;
            case 0x117E70u: goto label_117e70;
            case 0x117E8Cu: goto label_117e8c;
            case 0x117E90u: goto label_117e90;
            case 0x117E98u: goto label_117e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117EB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
