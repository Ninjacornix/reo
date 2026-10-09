#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1F50
// Address: 0x1d1f50 - 0x1d1fb8
void sub_001D1F50_0x1d1f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1F50_0x1d1f50");
#endif

    switch (ctx->pc) {
        case 0x1d1facu: goto label_1d1fac;
        default: break;
    }

    ctx->pc = 0x1d1f50u;

    // 0x1d1f50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d1f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d1f54: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1f54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1f58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d1f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d1f5c: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d1f5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d1f60: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D1F60u;
    {
        const bool branch_taken_0x1d1f60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d1f60) {
            ctx->pc = 0x1D1FACu;
            goto label_1d1fac;
        }
    }
    ctx->pc = 0x1D1F68u;
    // 0x1d1f68: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1d1f68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1d1f6c: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d1f6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d1f70: 0x902697b8  lbu         $a2, -0x6848($at)
    ctx->pc = 0x1d1f70u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d1f74: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1d1f74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1d1f78: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1f78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1f7c: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1d1f7cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1d1f80: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1d1f80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1d1f84: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1d1f84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1d1f88: 0x432025  or          $a0, $v0, $v1
    ctx->pc = 0x1d1f88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1d1f8c: 0x38c20001  xori        $v0, $a2, 0x1
    ctx->pc = 0x1d1f8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ (uint64_t)(uint16_t)1);
    // 0x1d1f90: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d1f90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d1f94: 0xa02297b8  sb          $v0, -0x6848($at)
    ctx->pc = 0x1d1f94u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294940600), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d1f98: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d1f98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d1f9c: 0x902297b8  lbu         $v0, -0x6848($at)
    ctx->pc = 0x1d1f9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d1fa0: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x1d1fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x1d1fa4: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1FA4u;
    SET_GPR_U32(ctx, 31, 0x1D1FACu);
    ctx->pc = 0x1D1FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1FA4u;
            // 0x1d1fa8: 0x24451800  addiu       $a1, $v0, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 6144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1FACu; }
        if (ctx->pc != 0x1D1FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1FACu; }
        if (ctx->pc != 0x1D1FACu) { return; }
    }
    ctx->pc = 0x1D1FACu;
label_1d1fac:
    // 0x1d1fac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d1facu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1fb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1FB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1FB0u;
            // 0x1d1fb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1FB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
