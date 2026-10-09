#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001630D8
// Address: 0x1630d8 - 0x163138
void sub_001630D8_0x1630d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001630D8_0x1630d8");
#endif

    switch (ctx->pc) {
        case 0x1630f4u: goto label_1630f4;
        case 0x163108u: goto label_163108;
        case 0x163124u: goto label_163124;
        default: break;
    }

    ctx->pc = 0x1630d8u;

    // 0x1630d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1630d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1630dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1630dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1630e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1630e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1630e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1630e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1630e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1630e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1630ec: 0xc058d10  jal         func_163440
    ctx->pc = 0x1630ECu;
    SET_GPR_U32(ctx, 31, 0x1630F4u);
    ctx->pc = 0x1630F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1630ECu;
            // 0x1630f0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1630F4u; }
        if (ctx->pc != 0x1630F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1630F4u; }
        if (ctx->pc != 0x1630F4u) { return; }
    }
    ctx->pc = 0x1630F4u;
label_1630f4:
    // 0x1630f4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1630f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1630f8: 0x5443000b  bnel        $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1630F8u;
    {
        const bool branch_taken_0x1630f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1630f8) {
            ctx->pc = 0x1630FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1630F8u;
            // 0x1630fc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163128u;
            goto label_163128;
        }
    }
    ctx->pc = 0x163100u;
    // 0x163100: 0xc058d08  jal         func_163420
    ctx->pc = 0x163100u;
    SET_GPR_U32(ctx, 31, 0x163108u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163108u; }
        if (ctx->pc != 0x163108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163108u; }
        if (ctx->pc != 0x163108u) { return; }
    }
    ctx->pc = 0x163108u;
label_163108:
    // 0x163108: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x163108u;
    {
        const bool branch_taken_0x163108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16310Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163108u;
            // 0x16310c: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163108) {
            ctx->pc = 0x163124u;
            goto label_163124;
        }
    }
    ctx->pc = 0x163110u;
    // 0x163110: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x163110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x163114: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x163114u;
    {
        const bool branch_taken_0x163114 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x163114) {
            ctx->pc = 0x163118u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163114u;
            // 0x163118: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163128u;
            goto label_163128;
        }
    }
    ctx->pc = 0x16311Cu;
    // 0x16311c: 0x40f809  jalr        $v0
    ctx->pc = 0x16311Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x163124u);
        ctx->pc = 0x163120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16311Cu;
            // 0x163120: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x163124u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163124u; }
            if (ctx->pc != 0x163124u) { return; }
        }
        }
    }
    ctx->pc = 0x163124u;
label_163124:
    // 0x163124: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163124u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_163128:
    // 0x163128: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163128u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16312c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16312cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163130: 0x3e00008  jr          $ra
    ctx->pc = 0x163130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163130u;
            // 0x163134: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163138u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
