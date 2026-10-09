#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162D88
// Address: 0x162d88 - 0x162de8
void sub_00162D88_0x162d88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162D88_0x162d88");
#endif

    switch (ctx->pc) {
        case 0x162d9cu: goto label_162d9c;
        case 0x162da4u: goto label_162da4;
        case 0x162dd8u: goto label_162dd8;
        default: break;
    }

    ctx->pc = 0x162d88u;

    // 0x162d88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162d88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162d8c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162d8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162d90: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162d90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x162d94: 0xc058d04  jal         func_163410
    ctx->pc = 0x162D94u;
    SET_GPR_U32(ctx, 31, 0x162D9Cu);
    ctx->pc = 0x163410u;
    if (runtime->hasFunction(0x163410u)) {
        auto targetFn = runtime->lookupFunction(0x163410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162D9Cu; }
        if (ctx->pc != 0x162D9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163410_0x163410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162D9Cu; }
        if (ctx->pc != 0x162D9Cu) { return; }
    }
    ctx->pc = 0x162D9Cu;
label_162d9c:
    // 0x162d9c: 0xc058d08  jal         func_163420
    ctx->pc = 0x162D9Cu;
    SET_GPR_U32(ctx, 31, 0x162DA4u);
    ctx->pc = 0x162DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162D9Cu;
            // 0x162da0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162DA4u; }
        if (ctx->pc != 0x162DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162DA4u; }
        if (ctx->pc != 0x162DA4u) { return; }
    }
    ctx->pc = 0x162DA4u;
label_162da4:
    // 0x162da4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x162da4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162da8: 0x5080000c  beql        $a0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x162DA8u;
    {
        const bool branch_taken_0x162da8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x162da8) {
            ctx->pc = 0x162DACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162DA8u;
            // 0x162dac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162DDCu;
            goto label_162ddc;
        }
    }
    ctx->pc = 0x162DB0u;
    // 0x162db0: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x162db0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x162db4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x162DB4u;
    {
        const bool branch_taken_0x162db4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162DB4u;
            // 0x162db8: 0x2443ffff  addiu       $v1, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162db4) {
            ctx->pc = 0x162DD8u;
            goto label_162dd8;
        }
    }
    ctx->pc = 0x162DBCu;
    // 0x162dbc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x162DBCu;
    {
        const bool branch_taken_0x162dbc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x162DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162DBCu;
            // 0x162dc0: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162dbc) {
            ctx->pc = 0x162DD8u;
            goto label_162dd8;
        }
    }
    ctx->pc = 0x162DC4u;
    // 0x162dc4: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x162dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x162dc8: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x162DC8u;
    {
        const bool branch_taken_0x162dc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x162dc8) {
            ctx->pc = 0x162DCCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162DC8u;
            // 0x162dcc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162DDCu;
            goto label_162ddc;
        }
    }
    ctx->pc = 0x162DD0u;
    // 0x162dd0: 0x40f809  jalr        $v0
    ctx->pc = 0x162DD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x162DD8u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x162DD8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162D9Cu: goto label_162d9c;
            case 0x162DA4u: goto label_162da4;
            case 0x162DD8u: goto label_162dd8;
            case 0x162DDCu: goto label_162ddc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162DD8u; }
            if (ctx->pc != 0x162DD8u) { return; }
        }
        }
    }
    ctx->pc = 0x162DD8u;
label_162dd8:
    // 0x162dd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162dd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_162ddc:
    // 0x162ddc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162ddcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162de0: 0x3e00008  jr          $ra
    ctx->pc = 0x162DE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162DE0u;
            // 0x162de4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162D9Cu: goto label_162d9c;
            case 0x162DA4u: goto label_162da4;
            case 0x162DD8u: goto label_162dd8;
            case 0x162DDCu: goto label_162ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162DE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
