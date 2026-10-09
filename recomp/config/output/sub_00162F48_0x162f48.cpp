#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162F48
// Address: 0x162f48 - 0x162fa0
void sub_00162F48_0x162f48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162F48_0x162f48");
#endif

    switch (ctx->pc) {
        case 0x162f5cu: goto label_162f5c;
        case 0x162f70u: goto label_162f70;
        case 0x162f8cu: goto label_162f8c;
        default: break;
    }

    ctx->pc = 0x162f48u;

    // 0x162f48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162f48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162f4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162f4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162f50: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162f50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x162f54: 0xc058d10  jal         func_163440
    ctx->pc = 0x162F54u;
    SET_GPR_U32(ctx, 31, 0x162F5Cu);
    ctx->pc = 0x162F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162F54u;
            // 0x162f58: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F5Cu; }
        if (ctx->pc != 0x162F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F5Cu; }
        if (ctx->pc != 0x162F5Cu) { return; }
    }
    ctx->pc = 0x162F5Cu;
label_162f5c:
    // 0x162f5c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x162f5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x162f60: 0x5443000b  bnel        $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x162F60u;
    {
        const bool branch_taken_0x162f60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x162f60) {
            ctx->pc = 0x162F64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162F60u;
            // 0x162f64: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162F90u;
            goto label_162f90;
        }
    }
    ctx->pc = 0x162F68u;
    // 0x162f68: 0xc058d08  jal         func_163420
    ctx->pc = 0x162F68u;
    SET_GPR_U32(ctx, 31, 0x162F70u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F70u; }
        if (ctx->pc != 0x162F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F70u; }
        if (ctx->pc != 0x162F70u) { return; }
    }
    ctx->pc = 0x162F70u;
label_162f70:
    // 0x162f70: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162F70u;
    {
        const bool branch_taken_0x162f70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162F70u;
            // 0x162f74: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162f70) {
            ctx->pc = 0x162F8Cu;
            goto label_162f8c;
        }
    }
    ctx->pc = 0x162F78u;
    // 0x162f78: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x162f78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x162f7c: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x162F7Cu;
    {
        const bool branch_taken_0x162f7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x162f7c) {
            ctx->pc = 0x162F80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162F7Cu;
            // 0x162f80: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162F90u;
            goto label_162f90;
        }
    }
    ctx->pc = 0x162F84u;
    // 0x162f84: 0x40f809  jalr        $v0
    ctx->pc = 0x162F84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x162F8Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x162F8Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162F5Cu: goto label_162f5c;
            case 0x162F70u: goto label_162f70;
            case 0x162F8Cu: goto label_162f8c;
            case 0x162F90u: goto label_162f90;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162F8Cu; }
            if (ctx->pc != 0x162F8Cu) { return; }
        }
        }
    }
    ctx->pc = 0x162F8Cu;
label_162f8c:
    // 0x162f8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162f8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_162f90:
    // 0x162f90: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162f90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162f94: 0x3e00008  jr          $ra
    ctx->pc = 0x162F94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162F94u;
            // 0x162f98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162F5Cu: goto label_162f5c;
            case 0x162F70u: goto label_162f70;
            case 0x162F8Cu: goto label_162f8c;
            case 0x162F90u: goto label_162f90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162F9Cu;
    // 0x162f9c: 0x0  nop
    ctx->pc = 0x162f9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
