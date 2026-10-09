#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162DE8
// Address: 0x162de8 - 0x162e50
void sub_00162DE8_0x162de8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162DE8_0x162de8");
#endif

    switch (ctx->pc) {
        case 0x162e0cu: goto label_162e0c;
        case 0x162e2cu: goto label_162e2c;
        default: break;
    }

    ctx->pc = 0x162de8u;

    // 0x162de8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162de8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162dec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162decu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162df0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x162df0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162df4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x162df4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162df8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x162df8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162dfc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x162dfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x162e00: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x162e00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x162e04: 0xc058d08  jal         func_163420
    ctx->pc = 0x162E04u;
    SET_GPR_U32(ctx, 31, 0x162E0Cu);
    ctx->pc = 0x162E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162E04u;
            // 0x162e08: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162E0Cu; }
        if (ctx->pc != 0x162E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162E0Cu; }
        if (ctx->pc != 0x162E0Cu) { return; }
    }
    ctx->pc = 0x162E0Cu;
label_162e0c:
    // 0x162e0c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x162E0Cu;
    {
        const bool branch_taken_0x162e0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E0Cu;
            // 0x162e10: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162e0c) {
            ctx->pc = 0x162E30u;
            goto label_162e30;
        }
    }
    ctx->pc = 0x162E14u;
    // 0x162e14: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x162e14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x162e18: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x162E18u;
    {
        const bool branch_taken_0x162e18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E18u;
            // 0x162e1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162e18) {
            ctx->pc = 0x162E30u;
            goto label_162e30;
        }
    }
    ctx->pc = 0x162E20u;
    // 0x162e20: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x162e20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162e24: 0x40f809  jalr        $v0
    ctx->pc = 0x162E24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x162E2Cu);
        ctx->pc = 0x162E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E24u;
            // 0x162e28: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x162E2Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162E0Cu: goto label_162e0c;
            case 0x162E2Cu: goto label_162e2c;
            case 0x162E30u: goto label_162e30;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162E2Cu; }
            if (ctx->pc != 0x162E2Cu) { return; }
        }
        }
    }
    ctx->pc = 0x162E2Cu;
label_162e2c:
    // 0x162e2c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x162e2cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_162e30:
    // 0x162e30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162e30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162e34: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x162e34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162e38: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162e38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162e3c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x162e3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162e40: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x162e40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x162e44: 0x3e00008  jr          $ra
    ctx->pc = 0x162E44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E44u;
            // 0x162e48: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162E0Cu: goto label_162e0c;
            case 0x162E2Cu: goto label_162e2c;
            case 0x162E30u: goto label_162e30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162E4Cu;
    // 0x162e4c: 0x0  nop
    ctx->pc = 0x162e4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
