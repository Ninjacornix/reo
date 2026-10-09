#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135F50
// Address: 0x135f50 - 0x135fb8
void sub_00135F50_0x135f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135F50_0x135f50");
#endif

    switch (ctx->pc) {
        case 0x135f70u: goto label_135f70;
        case 0x135f90u: goto label_135f90;
        case 0x135fa0u: goto label_135fa0;
        default: break;
    }

    ctx->pc = 0x135f50u;

    // 0x135f50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135f54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135f54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135f58: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x135f58u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x135f5c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x135F5Cu;
    {
        const bool branch_taken_0x135f5c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135F5Cu;
            // 0x135f60: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135f5c) {
            ctx->pc = 0x135F78u;
            goto label_135f78;
        }
    }
    ctx->pc = 0x135F64u;
    // 0x135f64: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135f64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135f68: 0xc04d480  jal         func_135200
    ctx->pc = 0x135F68u;
    SET_GPR_U32(ctx, 31, 0x135F70u);
    ctx->pc = 0x135F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135F68u;
            // 0x135f6c: 0x2484bab0  addiu       $a0, $a0, -0x4550 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949552));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135F70u; }
        if (ctx->pc != 0x135F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135F70u; }
        if (ctx->pc != 0x135F70u) { return; }
    }
    ctx->pc = 0x135F70u;
label_135f70:
    // 0x135f70: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x135F70u;
    {
        const bool branch_taken_0x135f70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135F70u;
            // 0x135f74: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135f70) {
            ctx->pc = 0x135FA4u;
            goto label_135fa4;
        }
    }
    ctx->pc = 0x135F78u;
label_135f78:
    // 0x135f78: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x135f78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x135f7c: 0x8c42002c  lw          $v0, 0x2C($v0)
    ctx->pc = 0x135f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x135f80: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x135F80u;
    {
        const bool branch_taken_0x135f80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135f80) {
            ctx->pc = 0x135F84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135F80u;
            // 0x135f84: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135F98u;
            goto label_135f98;
        }
    }
    ctx->pc = 0x135F88u;
    // 0x135f88: 0x40f809  jalr        $v0
    ctx->pc = 0x135F88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135F90u);
        ctx->pc = 0x135F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135F88u;
            // 0x135f8c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135F90u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135F70u: goto label_135f70;
            case 0x135F78u: goto label_135f78;
            case 0x135F90u: goto label_135f90;
            case 0x135F98u: goto label_135f98;
            case 0x135FA0u: goto label_135fa0;
            case 0x135FA4u: goto label_135fa4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135F90u; }
            if (ctx->pc != 0x135F90u) { return; }
        }
        }
    }
    ctx->pc = 0x135F90u;
label_135f90:
    // 0x135f90: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x135F90u;
    {
        const bool branch_taken_0x135f90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135F90u;
            // 0x135f94: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135f90) {
            ctx->pc = 0x135FA0u;
            goto label_135fa0;
        }
    }
    ctx->pc = 0x135F98u;
label_135f98:
    // 0x135f98: 0xc04d480  jal         func_135200
    ctx->pc = 0x135F98u;
    SET_GPR_U32(ctx, 31, 0x135FA0u);
    ctx->pc = 0x135F9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135F98u;
            // 0x135f9c: 0x2484bad0  addiu       $a0, $a0, -0x4530 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135FA0u; }
        if (ctx->pc != 0x135FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135FA0u; }
        if (ctx->pc != 0x135FA0u) { return; }
    }
    ctx->pc = 0x135FA0u;
label_135fa0:
    // 0x135fa0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x135fa0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_135fa4:
    // 0x135fa4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135fa4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135fa8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135fa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135fac: 0x3e00008  jr          $ra
    ctx->pc = 0x135FACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135FACu;
            // 0x135fb0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135F70u: goto label_135f70;
            case 0x135F78u: goto label_135f78;
            case 0x135F90u: goto label_135f90;
            case 0x135F98u: goto label_135f98;
            case 0x135FA0u: goto label_135fa0;
            case 0x135FA4u: goto label_135fa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135FB4u;
    // 0x135fb4: 0x0  nop
    ctx->pc = 0x135fb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
