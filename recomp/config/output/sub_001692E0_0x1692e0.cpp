#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001692E0
// Address: 0x1692e0 - 0x169330
void sub_001692E0_0x1692e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001692E0_0x1692e0");
#endif

    switch (ctx->pc) {
        case 0x169304u: goto label_169304;
        default: break;
    }

    ctx->pc = 0x1692e0u;

    // 0x1692e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1692e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1692e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1692e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1692e8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1692e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1692ec: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1692ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1692f0: 0x8e032ab0  lw          $v1, 0x2AB0($s0)
    ctx->pc = 0x1692f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x1692f4: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1692F4u;
    {
        const bool branch_taken_0x1692f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1692F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1692F4u;
            // 0x1692f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1692f4) {
            ctx->pc = 0x16931Cu;
            goto label_16931c;
        }
    }
    ctx->pc = 0x1692FCu;
    // 0x1692fc: 0xc05aefa  jal         func_16BBE8
    ctx->pc = 0x1692FCu;
    SET_GPR_U32(ctx, 31, 0x169304u);
    ctx->pc = 0x16BBE8u;
    if (runtime->hasFunction(0x16BBE8u)) {
        auto targetFn = runtime->lookupFunction(0x16BBE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169304u; }
        if (ctx->pc != 0x169304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BBE8_0x16bbe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169304u; }
        if (ctx->pc != 0x169304u) { return; }
    }
    ctx->pc = 0x169304u;
label_169304:
    // 0x169304: 0x58400004  blezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x169304u;
    {
        const bool branch_taken_0x169304 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x169304) {
            ctx->pc = 0x169308u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x169304u;
            // 0x169308: 0x8e022ab0  lw          $v0, 0x2AB0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x169318u;
            goto label_169318;
        }
    }
    ctx->pc = 0x16930Cu;
    // 0x16930c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16930Cu;
    {
        const bool branch_taken_0x16930c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x169310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16930Cu;
            // 0x169310: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16930c) {
            ctx->pc = 0x16931Cu;
            goto label_16931c;
        }
    }
    ctx->pc = 0x169314u;
    // 0x169314: 0x0  nop
    ctx->pc = 0x169314u;
    // NOP
label_169318:
    // 0x169318: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x169318u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_16931c:
    // 0x16931c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16931cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169320: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x169320u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169324: 0x3e00008  jr          $ra
    ctx->pc = 0x169324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169324u;
            // 0x169328: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169304u: goto label_169304;
            case 0x169318u: goto label_169318;
            case 0x16931Cu: goto label_16931c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16932Cu;
    // 0x16932c: 0x0  nop
    ctx->pc = 0x16932cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
