#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0E00
// Address: 0x1c0e00 - 0x1c0e70
void sub_001C0E00_0x1c0e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0E00_0x1c0e00");
#endif

    switch (ctx->pc) {
        case 0x1c0e28u: goto label_1c0e28;
        case 0x1c0e60u: goto label_1c0e60;
        default: break;
    }

    ctx->pc = 0x1c0e00u;

    // 0x1c0e00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0e04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c0e08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0e08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0e0c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1c0e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0e10: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E10u;
    {
        const bool branch_taken_0x1c0e10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E10u;
            // 0x1c0e14: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e10) {
            ctx->pc = 0x1C0E20u;
            goto label_1c0e20;
        }
    }
    ctx->pc = 0x1C0E18u;
    // 0x1c0e18: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C0E18u;
    {
        const bool branch_taken_0x1c0e18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E18u;
            // 0x1c0e1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e18) {
            ctx->pc = 0x1C0E58u;
            goto label_1c0e58;
        }
    }
    ctx->pc = 0x1C0E20u;
label_1c0e20:
    // 0x1c0e20: 0xc06ffdc  jal         func_1BFF70
    ctx->pc = 0x1C0E20u;
    SET_GPR_U32(ctx, 31, 0x1C0E28u);
    ctx->pc = 0x1BFF70u;
    if (runtime->hasFunction(0x1BFF70u)) {
        auto targetFn = runtime->lookupFunction(0x1BFF70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E28u; }
        if (ctx->pc != 0x1C0E28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFF70_0x1bff70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E28u; }
        if (ctx->pc != 0x1C0E28u) { return; }
    }
    ctx->pc = 0x1C0E28u;
label_1c0e28:
    // 0x1c0e28: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0e28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0e2c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C0E2Cu;
    {
        const bool branch_taken_0x1c0e2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0e2c) {
            ctx->pc = 0x1C0E4Cu;
            goto label_1c0e4c;
        }
    }
    ctx->pc = 0x1C0E34u;
    // 0x1c0e34: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E34u;
    {
        const bool branch_taken_0x1c0e34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0e34) {
            ctx->pc = 0x1C0E44u;
            goto label_1c0e44;
        }
    }
    ctx->pc = 0x1C0E3Cu;
    // 0x1c0e3c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0E3Cu;
    {
        const bool branch_taken_0x1c0e3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0e3c) {
            ctx->pc = 0x1C0E54u;
            goto label_1c0e54;
        }
    }
    ctx->pc = 0x1C0E44u;
label_1c0e44:
    // 0x1c0e44: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E44u;
    {
        const bool branch_taken_0x1c0e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E44u;
            // 0x1c0e48: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e44) {
            ctx->pc = 0x1C0E54u;
            goto label_1c0e54;
        }
    }
    ctx->pc = 0x1C0E4Cu;
label_1c0e4c:
    // 0x1c0e4c: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0e50: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c0e50u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c0e54:
    // 0x1c0e54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c0e54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c0e58:
    // 0x1c0e58: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C0E58u;
    SET_GPR_U32(ctx, 31, 0x1C0E60u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E60u; }
        if (ctx->pc != 0x1C0E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E60u; }
        if (ctx->pc != 0x1C0E60u) { return; }
    }
    ctx->pc = 0x1C0E60u;
label_1c0e60:
    // 0x1c0e60: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c0e60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0e64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0e64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0e68: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E68u;
            // 0x1c0e6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E20u: goto label_1c0e20;
            case 0x1C0E28u: goto label_1c0e28;
            case 0x1C0E44u: goto label_1c0e44;
            case 0x1C0E4Cu: goto label_1c0e4c;
            case 0x1C0E54u: goto label_1c0e54;
            case 0x1C0E58u: goto label_1c0e58;
            case 0x1C0E60u: goto label_1c0e60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0E70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
