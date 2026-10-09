#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147E78
// Address: 0x147e78 - 0x147ed8
void sub_00147E78_0x147e78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147E78_0x147e78");
#endif

    switch (ctx->pc) {
        case 0x147eb4u: goto label_147eb4;
        case 0x147ec0u: goto label_147ec0;
        default: break;
    }

    ctx->pc = 0x147e78u;

    // 0x147e78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x147e78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x147e7c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x147e7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147e80: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x147e80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x147e84: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x147e84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x147e88: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x147e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x147e8c: 0x8c500040  lw          $s0, 0x40($v0)
    ctx->pc = 0x147e8cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x147e90: 0xae0010a0  sw          $zero, 0x10A0($s0)
    ctx->pc = 0x147e90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4256), GPR_U32(ctx, 0));
    // 0x147e94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x147e94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147e98: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x147e98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x147e9c: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x147e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x147ea0: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x147ea0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x147ea4: 0xac400008  sw          $zero, 0x8($v0)
    ctx->pc = 0x147ea4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x147ea8: 0xae0000c4  sw          $zero, 0xC4($s0)
    ctx->pc = 0x147ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 196), GPR_U32(ctx, 0));
    // 0x147eac: 0xc0521d8  jal         func_148760
    ctx->pc = 0x147EACu;
    SET_GPR_U32(ctx, 31, 0x147EB4u);
    ctx->pc = 0x147EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147EACu;
            // 0x147eb0: 0xae030098  sw          $v1, 0x98($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 152), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148760u;
    if (runtime->hasFunction(0x148760u)) {
        auto targetFn = runtime->lookupFunction(0x148760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147EB4u; }
        if (ctx->pc != 0x147EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148760_0x148760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147EB4u; }
        if (ctx->pc != 0x147EB4u) { return; }
    }
    ctx->pc = 0x147EB4u;
label_147eb4:
    // 0x147eb4: 0xae000130  sw          $zero, 0x130($s0)
    ctx->pc = 0x147eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 304), GPR_U32(ctx, 0));
    // 0x147eb8: 0xc05219c  jal         func_148670
    ctx->pc = 0x147EB8u;
    SET_GPR_U32(ctx, 31, 0x147EC0u);
    ctx->pc = 0x147EBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147EB8u;
            // 0x147ebc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148670u;
    if (runtime->hasFunction(0x148670u)) {
        auto targetFn = runtime->lookupFunction(0x148670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147EC0u; }
        if (ctx->pc != 0x147EC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148670_0x148670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147EC0u; }
        if (ctx->pc != 0x147EC0u) { return; }
    }
    ctx->pc = 0x147EC0u;
label_147ec0:
    // 0x147ec0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x147ec0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147ec4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x147ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x147ec8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x147ec8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x147ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147ECCu;
            // 0x147ed0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147EB4u: goto label_147eb4;
            case 0x147EC0u: goto label_147ec0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147ED4u;
    // 0x147ed4: 0x0  nop
    ctx->pc = 0x147ed4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
