#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102F08
// Address: 0x102f08 - 0x102f78
void sub_00102F08_0x102f08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102F08_0x102f08");
#endif

    switch (ctx->pc) {
        case 0x102f38u: goto label_102f38;
        case 0x102f48u: goto label_102f48;
        case 0x102f50u: goto label_102f50;
        default: break;
    }

    ctx->pc = 0x102f08u;

    // 0x102f08: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x102f08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x102f0c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x102f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x102f10: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102f10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102f14: 0x3c110100  lui         $s1, 0x100
    ctx->pc = 0x102f14u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)256 << 16));
    // 0x102f18: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x102f18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x102f1c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x102f1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102f20: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x102f20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x102f24: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x102f24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x102f28: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x102f28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x102f2c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x102F2Cu;
    {
        const bool branch_taken_0x102f2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102F2Cu;
            // 0x102f30: 0x3c120023  lui         $s2, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102f2c) {
            ctx->pc = 0x102F60u;
            goto label_102f60;
        }
    }
    ctx->pc = 0x102F34u;
    // 0x102f34: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x102f34u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_102f38:
    // 0x102f38: 0x6210005  bgez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x102F38u;
    {
        const bool branch_taken_0x102f38 = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x102f38) {
            ctx->pc = 0x102F50u;
            goto label_102f50;
        }
    }
    ctx->pc = 0x102F40u;
    // 0x102f40: 0xc045a12  jal         func_116848
    ctx->pc = 0x102F40u;
    SET_GPR_U32(ctx, 31, 0x102F48u);
    ctx->pc = 0x102F44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102F40u;
            // 0x102f44: 0x264476f8  addiu       $a0, $s2, 0x76F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 30456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102F48u; }
        if (ctx->pc != 0x102F48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102F48u; }
        if (ctx->pc != 0x102F48u) { return; }
    }
    ctx->pc = 0x102F48u;
label_102f48:
    // 0x102f48: 0xc040da8  jal         func_1036A0
    ctx->pc = 0x102F48u;
    SET_GPR_U32(ctx, 31, 0x102F50u);
    ctx->pc = 0x102F4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102F48u;
            // 0x102f4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1036A0u;
    if (runtime->hasFunction(0x1036A0u)) {
        auto targetFn = runtime->lookupFunction(0x1036A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102F50u; }
        if (ctx->pc != 0x102F50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001036A0_0x1036a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102F50u; }
        if (ctx->pc != 0x102F50u) { return; }
    }
    ctx->pc = 0x102F50u;
label_102f50:
    // 0x102f50: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x102f50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x102f54: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x102f54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x102f58: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x102F58u;
    {
        const bool branch_taken_0x102f58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102F58u;
            // 0x102f5c: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102f58) {
            ctx->pc = 0x102F38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_102f38;
        }
    }
    ctx->pc = 0x102F60u;
label_102f60:
    // 0x102f60: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x102f60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x102f64: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x102f64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102f68: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x102f68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102f6c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102f6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102f70: 0x3e00008  jr          $ra
    ctx->pc = 0x102F70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102F70u;
            // 0x102f74: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102F38u: goto label_102f38;
            case 0x102F48u: goto label_102f48;
            case 0x102F50u: goto label_102f50;
            case 0x102F60u: goto label_102f60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102F78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
