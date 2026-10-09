#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0E70
// Address: 0x1c0e70 - 0x1c0ee0
void sub_001C0E70_0x1c0e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0E70_0x1c0e70");
#endif

    switch (ctx->pc) {
        case 0x1c0e98u: goto label_1c0e98;
        case 0x1c0ed0u: goto label_1c0ed0;
        default: break;
    }

    ctx->pc = 0x1c0e70u;

    // 0x1c0e70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0e74: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c0e78: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0e78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0e7c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1c0e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0e80: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0E80u;
    {
        const bool branch_taken_0x1c0e80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E80u;
            // 0x1c0e84: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e80) {
            ctx->pc = 0x1C0E90u;
            goto label_1c0e90;
        }
    }
    ctx->pc = 0x1C0E88u;
    // 0x1c0e88: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C0E88u;
    {
        const bool branch_taken_0x1c0e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0E88u;
            // 0x1c0e8c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0e88) {
            ctx->pc = 0x1C0EC8u;
            goto label_1c0ec8;
        }
    }
    ctx->pc = 0x1C0E90u;
label_1c0e90:
    // 0x1c0e90: 0xc070008  jal         func_1C0020
    ctx->pc = 0x1C0E90u;
    SET_GPR_U32(ctx, 31, 0x1C0E98u);
    ctx->pc = 0x1C0020u;
    if (runtime->hasFunction(0x1C0020u)) {
        auto targetFn = runtime->lookupFunction(0x1C0020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E98u; }
        if (ctx->pc != 0x1C0E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0020_0x1c0020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0E98u; }
        if (ctx->pc != 0x1C0E98u) { return; }
    }
    ctx->pc = 0x1C0E98u;
label_1c0e98:
    // 0x1c0e98: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0e98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0e9c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C0E9Cu;
    {
        const bool branch_taken_0x1c0e9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0e9c) {
            ctx->pc = 0x1C0EBCu;
            goto label_1c0ebc;
        }
    }
    ctx->pc = 0x1C0EA4u;
    // 0x1c0ea4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0EA4u;
    {
        const bool branch_taken_0x1c0ea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0ea4) {
            ctx->pc = 0x1C0EB4u;
            goto label_1c0eb4;
        }
    }
    ctx->pc = 0x1C0EACu;
    // 0x1c0eac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0EACu;
    {
        const bool branch_taken_0x1c0eac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0eac) {
            ctx->pc = 0x1C0EC4u;
            goto label_1c0ec4;
        }
    }
    ctx->pc = 0x1C0EB4u;
label_1c0eb4:
    // 0x1c0eb4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0EB4u;
    {
        const bool branch_taken_0x1c0eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0EB4u;
            // 0x1c0eb8: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0eb4) {
            ctx->pc = 0x1C0EC4u;
            goto label_1c0ec4;
        }
    }
    ctx->pc = 0x1C0EBCu;
label_1c0ebc:
    // 0x1c0ebc: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0ec0: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c0ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c0ec4:
    // 0x1c0ec4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c0ec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c0ec8:
    // 0x1c0ec8: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C0EC8u;
    SET_GPR_U32(ctx, 31, 0x1C0ED0u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0ED0u; }
        if (ctx->pc != 0x1C0ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0ED0u; }
        if (ctx->pc != 0x1C0ED0u) { return; }
    }
    ctx->pc = 0x1C0ED0u;
label_1c0ed0:
    // 0x1c0ed0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c0ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0ed4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0ed4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0ED8u;
            // 0x1c0edc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0E90u: goto label_1c0e90;
            case 0x1C0E98u: goto label_1c0e98;
            case 0x1C0EB4u: goto label_1c0eb4;
            case 0x1C0EBCu: goto label_1c0ebc;
            case 0x1C0EC4u: goto label_1c0ec4;
            case 0x1C0EC8u: goto label_1c0ec8;
            case 0x1C0ED0u: goto label_1c0ed0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0EE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
