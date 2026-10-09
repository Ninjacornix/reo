#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162E50
// Address: 0x162e50 - 0x162ea8
void sub_00162E50_0x162e50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162E50_0x162e50");
#endif

    switch (ctx->pc) {
        case 0x162e6cu: goto label_162e6c;
        case 0x162e88u: goto label_162e88;
        default: break;
    }

    ctx->pc = 0x162e50u;

    // 0x162e50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162e50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162e54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162e54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162e58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x162e58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162e5c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x162e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162e60: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162e60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162e64: 0xc058d08  jal         func_163420
    ctx->pc = 0x162E64u;
    SET_GPR_U32(ctx, 31, 0x162E6Cu);
    ctx->pc = 0x162E68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162E64u;
            // 0x162e68: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162E6Cu; }
        if (ctx->pc != 0x162E6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162E6Cu; }
        if (ctx->pc != 0x162E6Cu) { return; }
    }
    ctx->pc = 0x162E6Cu;
label_162e6c:
    // 0x162e6c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x162E6Cu;
    {
        const bool branch_taken_0x162e6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E6Cu;
            // 0x162e70: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162e6c) {
            ctx->pc = 0x162E8Cu;
            goto label_162e8c;
        }
    }
    ctx->pc = 0x162E74u;
    // 0x162e74: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x162e74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x162e78: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x162E78u;
    {
        const bool branch_taken_0x162e78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E78u;
            // 0x162e7c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162e78) {
            ctx->pc = 0x162E8Cu;
            goto label_162e8c;
        }
    }
    ctx->pc = 0x162E80u;
    // 0x162e80: 0x40f809  jalr        $v0
    ctx->pc = 0x162E80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x162E88u);
        ctx->pc = 0x162E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E80u;
            // 0x162e84: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x162E88u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162E6Cu: goto label_162e6c;
            case 0x162E88u: goto label_162e88;
            case 0x162E8Cu: goto label_162e8c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162E88u; }
            if (ctx->pc != 0x162E88u) { return; }
        }
        }
    }
    ctx->pc = 0x162E88u;
label_162e88:
    // 0x162e88: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x162e88u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_162e8c:
    // 0x162e8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162e8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162e90: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x162e90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162e94: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162e94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162e98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162e9c: 0x3e00008  jr          $ra
    ctx->pc = 0x162E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162E9Cu;
            // 0x162ea0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162E6Cu: goto label_162e6c;
            case 0x162E88u: goto label_162e88;
            case 0x162E8Cu: goto label_162e8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162EA4u;
    // 0x162ea4: 0x0  nop
    ctx->pc = 0x162ea4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
