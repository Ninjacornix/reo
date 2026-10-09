#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173F28
// Address: 0x173f28 - 0x173fb0
void sub_00173F28_0x173f28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173F28_0x173f28");
#endif

    switch (ctx->pc) {
        case 0x173f3cu: goto label_173f3c;
        case 0x173f70u: goto label_173f70;
        case 0x173fa0u: goto label_173fa0;
        default: break;
    }

    ctx->pc = 0x173f28u;

    // 0x173f28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173f28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173f2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173f2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173f30: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x173f30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x173f34: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x173F34u;
    SET_GPR_U32(ctx, 31, 0x173F3Cu);
    ctx->pc = 0x173F38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173F34u;
            // 0x173f38: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173F3Cu; }
        if (ctx->pc != 0x173F3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173F3Cu; }
        if (ctx->pc != 0x173F3Cu) { return; }
    }
    ctx->pc = 0x173F3Cu;
label_173f3c:
    // 0x173f3c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x173f3cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x173f40: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x173f40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173f44: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x173f44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x173f48: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x173F48u;
    {
        const bool branch_taken_0x173f48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173F48u;
            // 0x173f4c: 0x34a50135  ori         $a1, $a1, 0x135 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)309);
        ctx->in_delay_slot = false;
        if (branch_taken_0x173f48) {
            ctx->pc = 0x173F68u;
            goto label_173f68;
        }
    }
    ctx->pc = 0x173F50u;
    // 0x173f50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173f50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173f54: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173f54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173f58: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173f58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173f5c: 0x805a704  j           func_169C10
    ctx->pc = 0x173F5Cu;
    ctx->pc = 0x173F60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173F5Cu;
            // 0x173f60: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173F64u;
    // 0x173f64: 0x0  nop
    ctx->pc = 0x173f64u;
    // NOP
label_173f68:
    // 0x173f68: 0xc059f38  jal         func_167CE0
    ctx->pc = 0x173F68u;
    SET_GPR_U32(ctx, 31, 0x173F70u);
    ctx->pc = 0x173F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173F68u;
            // 0x173f6c: 0x8e051ab4  lw          $a1, 0x1AB4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6836)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CE0u;
    if (runtime->hasFunction(0x167CE0u)) {
        auto targetFn = runtime->lookupFunction(0x167CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173F70u; }
        if (ctx->pc != 0x173F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CE0_0x167ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173F70u; }
        if (ctx->pc != 0x173F70u) { return; }
    }
    ctx->pc = 0x173F70u;
label_173f70:
    // 0x173f70: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x173f70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x173f74: 0xae020044  sw          $v0, 0x44($s0)
    ctx->pc = 0x173f74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 2));
    // 0x173f78: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x173f78u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173f7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173f7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173f80: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173f80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173f84: 0x3e00008  jr          $ra
    ctx->pc = 0x173F84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173F84u;
            // 0x173f88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173F3Cu: goto label_173f3c;
            case 0x173F68u: goto label_173f68;
            case 0x173F70u: goto label_173f70;
            case 0x173FA0u: goto label_173fa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173F8Cu;
    // 0x173f8c: 0x0  nop
    ctx->pc = 0x173f8cu;
    // NOP
    // 0x173f90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173f90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173f94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x173f94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x173f98: 0xc059f40  jal         func_167D00
    ctx->pc = 0x173F98u;
    SET_GPR_U32(ctx, 31, 0x173FA0u);
    ctx->pc = 0x173F9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173F98u;
            // 0x173f9c: 0x8c851ab4  lw          $a1, 0x1AB4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6836)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173FA0u; }
        if (ctx->pc != 0x173FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173FA0u; }
        if (ctx->pc != 0x173FA0u) { return; }
    }
    ctx->pc = 0x173FA0u;
label_173fa0:
    // 0x173fa0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x173fa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173fa4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x173fa4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x173fa8: 0x3e00008  jr          $ra
    ctx->pc = 0x173FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173FA8u;
            // 0x173fac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173F3Cu: goto label_173f3c;
            case 0x173F68u: goto label_173f68;
            case 0x173F70u: goto label_173f70;
            case 0x173FA0u: goto label_173fa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173FB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
