#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162EF0
// Address: 0x162ef0 - 0x162f48
void sub_00162EF0_0x162ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162EF0_0x162ef0");
#endif

    switch (ctx->pc) {
        case 0x162f04u: goto label_162f04;
        case 0x162f18u: goto label_162f18;
        case 0x162f38u: goto label_162f38;
        default: break;
    }

    ctx->pc = 0x162ef0u;

    // 0x162ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162ef4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162ef8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x162efc: 0xc058d10  jal         func_163440
    ctx->pc = 0x162EFCu;
    SET_GPR_U32(ctx, 31, 0x162F04u);
    ctx->pc = 0x162F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162EFCu;
            // 0x162f00: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F04u; }
        if (ctx->pc != 0x162F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F04u; }
        if (ctx->pc != 0x162F04u) { return; }
    }
    ctx->pc = 0x162F04u;
label_162f04:
    // 0x162f04: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x162f04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x162f08: 0x5443000c  bnel        $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x162F08u;
    {
        const bool branch_taken_0x162f08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x162f08) {
            ctx->pc = 0x162F0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162F08u;
            // 0x162f0c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162F3Cu;
            goto label_162f3c;
        }
    }
    ctx->pc = 0x162F10u;
    // 0x162f10: 0xc058d08  jal         func_163420
    ctx->pc = 0x162F10u;
    SET_GPR_U32(ctx, 31, 0x162F18u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F18u; }
        if (ctx->pc != 0x162F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162F18u; }
        if (ctx->pc != 0x162F18u) { return; }
    }
    ctx->pc = 0x162F18u;
label_162f18:
    // 0x162f18: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x162f18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x162f1c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162F1Cu;
    {
        const bool branch_taken_0x162f1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162F1Cu;
            // 0x162f20: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162f1c) {
            ctx->pc = 0x162F38u;
            goto label_162f38;
        }
    }
    ctx->pc = 0x162F24u;
    // 0x162f24: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x162f24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x162f28: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x162F28u;
    {
        const bool branch_taken_0x162f28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x162f28) {
            ctx->pc = 0x162F2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162F28u;
            // 0x162f2c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162F3Cu;
            goto label_162f3c;
        }
    }
    ctx->pc = 0x162F30u;
    // 0x162f30: 0x40f809  jalr        $v0
    ctx->pc = 0x162F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x162F38u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x162F38u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162F04u: goto label_162f04;
            case 0x162F18u: goto label_162f18;
            case 0x162F38u: goto label_162f38;
            case 0x162F3Cu: goto label_162f3c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162F38u; }
            if (ctx->pc != 0x162F38u) { return; }
        }
        }
    }
    ctx->pc = 0x162F38u;
label_162f38:
    // 0x162f38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162f38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_162f3c:
    // 0x162f3c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162f3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162f40: 0x3e00008  jr          $ra
    ctx->pc = 0x162F40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162F40u;
            // 0x162f44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162F04u: goto label_162f04;
            case 0x162F18u: goto label_162f18;
            case 0x162F38u: goto label_162f38;
            case 0x162F3Cu: goto label_162f3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162F48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
