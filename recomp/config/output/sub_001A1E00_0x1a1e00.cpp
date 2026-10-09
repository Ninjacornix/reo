#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1E00
// Address: 0x1a1e00 - 0x1a1e40
void sub_001A1E00_0x1a1e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1E00_0x1a1e00");
#endif

    switch (ctx->pc) {
        case 0x1a1e10u: goto label_1a1e10;
        default: break;
    }

    ctx->pc = 0x1a1e00u;

    // 0x1a1e00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a1e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a1e04: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a1e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a1e08: 0xc068768  jal         func_1A1DA0
    ctx->pc = 0x1A1E08u;
    SET_GPR_U32(ctx, 31, 0x1A1E10u);
    ctx->pc = 0x1A1DA0u;
    if (runtime->hasFunction(0x1A1DA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1DA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E10u; }
        if (ctx->pc != 0x1A1E10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1DA0_0x1a1da0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E10u; }
        if (ctx->pc != 0x1A1E10u) { return; }
    }
    ctx->pc = 0x1A1E10u;
label_1a1e10:
    // 0x1a1e10: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1a1e10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1a1e14: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A1E14u;
    {
        const bool branch_taken_0x1a1e14 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a1e14) {
            ctx->pc = 0x1A1E2Cu;
            goto label_1a1e2c;
        }
    }
    ctx->pc = 0x1A1E1Cu;
    // 0x1a1e1c: 0xc4400010  lwc1        $f0, 0x10($v0)
    ctx->pc = 0x1a1e1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a1e20: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a1e20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a1e24: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A1E24u;
    {
        const bool branch_taken_0x1a1e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1E24u;
            // 0x1a1e28: 0xe4a00000  swc1        $f0, 0x0($a1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1e24) {
            ctx->pc = 0x1A1E34u;
            goto label_1a1e34;
        }
    }
    ctx->pc = 0x1A1E2Cu;
label_1a1e2c:
    // 0x1a1e2c: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x1a1e2cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x1a1e30: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a1e30u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a1e34:
    // 0x1a1e34: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a1e34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1e38: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1E38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1E38u;
            // 0x1a1e3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1E10u: goto label_1a1e10;
            case 0x1A1E2Cu: goto label_1a1e2c;
            case 0x1A1E34u: goto label_1a1e34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1E40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
