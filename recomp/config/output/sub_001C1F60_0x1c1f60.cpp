#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1F60
// Address: 0x1c1f60 - 0x1c1fb0
void sub_001C1F60_0x1c1f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1F60_0x1c1f60");
#endif

    switch (ctx->pc) {
        case 0x1c1f9cu: goto label_1c1f9c;
        default: break;
    }

    ctx->pc = 0x1c1f60u;

    // 0x1c1f60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c1f60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c1f64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1f64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1f68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c1f68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c1f6c: 0x8c264480  lw          $a2, 0x4480($at)
    ctx->pc = 0x1c1f6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17536)));
    // 0x1c1f70: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1F70u;
    {
        const bool branch_taken_0x1c1f70 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1F70u;
            // 0x1c1f74: 0x41b00  sll         $v1, $a0, 12 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1f70) {
            ctx->pc = 0x1C1F80u;
            goto label_1c1f80;
        }
    }
    ctx->pc = 0x1C1F78u;
    // 0x1c1f78: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C1F78u;
    {
        const bool branch_taken_0x1c1f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1F78u;
            // 0x1c1f7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1f78) {
            ctx->pc = 0x1C1FA4u;
            goto label_1c1fa4;
        }
    }
    ctx->pc = 0x1C1F80u;
label_1c1f80:
    // 0x1c1f80: 0x51180  sll         $v0, $a1, 6
    ctx->pc = 0x1c1f80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x1c1f84: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x1c1f84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1c1f88: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c1f88u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c1f8c: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1c1f8cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1c1f90: 0x24a56e10  addiu       $a1, $a1, 0x6E10
    ctx->pc = 0x1c1f90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28176));
    // 0x1c1f94: 0xc07071c  jal         func_1C1C70
    ctx->pc = 0x1C1F94u;
    SET_GPR_U32(ctx, 31, 0x1C1F9Cu);
    ctx->pc = 0x1C1F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1F94u;
            // 0x1c1f98: 0xc0202d  daddu       $a0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1C70u;
    if (runtime->hasFunction(0x1C1C70u)) {
        auto targetFn = runtime->lookupFunction(0x1C1C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1F9Cu; }
        if (ctx->pc != 0x1C1F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1C70_0x1c1c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1F9Cu; }
        if (ctx->pc != 0x1C1F9Cu) { return; }
    }
    ctx->pc = 0x1C1F9Cu;
label_1c1f9c:
    // 0x1c1f9c: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1c1f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1c1fa0: 0x24426e10  addiu       $v0, $v0, 0x6E10
    ctx->pc = 0x1c1fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28176));
label_1c1fa4:
    // 0x1c1fa4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c1fa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1fa8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1FA8u;
            // 0x1c1fac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1F80u: goto label_1c1f80;
            case 0x1C1F9Cu: goto label_1c1f9c;
            case 0x1C1FA4u: goto label_1c1fa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1FB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
