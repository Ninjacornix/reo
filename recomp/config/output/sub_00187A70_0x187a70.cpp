#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187A70
// Address: 0x187a70 - 0x187ad0
void sub_00187A70_0x187a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187A70_0x187a70");
#endif

    switch (ctx->pc) {
        case 0x187a88u: goto label_187a88;
        case 0x187aacu: goto label_187aac;
        default: break;
    }

    ctx->pc = 0x187a70u;

    // 0x187a70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x187a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x187a74: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x187a74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x187a78: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x187a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x187a7c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x187a7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x187a80: 0xc061e90  jal         func_187A40
    ctx->pc = 0x187A80u;
    SET_GPR_U32(ctx, 31, 0x187A88u);
    ctx->pc = 0x187A84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187A80u;
            // 0x187a84: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187A88u; }
        if (ctx->pc != 0x187A88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187A88u; }
        if (ctx->pc != 0x187A88u) { return; }
    }
    ctx->pc = 0x187A88u;
label_187a88:
    // 0x187a88: 0x1018c0  sll         $v1, $s0, 3
    ctx->pc = 0x187a88u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x187a8c: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x187a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x187a90: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x187a90u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x187a94: 0x2491b8c8  addiu       $s1, $a0, -0x4738
    ctx->pc = 0x187a94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949064));
    // 0x187a98: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x187A98u;
    {
        const bool branch_taken_0x187a98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x187A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187A98u;
            // 0x187a9c: 0x38080  sll         $s0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187a98) {
            ctx->pc = 0x187AB8u;
            goto label_187ab8;
        }
    }
    ctx->pc = 0x187AA0u;
    // 0x187aa0: 0x2301021  addu        $v0, $s1, $s0
    ctx->pc = 0x187aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x187aa4: 0xc062342  jal         func_188D08
    ctx->pc = 0x187AA4u;
    SET_GPR_U32(ctx, 31, 0x187AACu);
    ctx->pc = 0x187AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187AA4u;
            // 0x187aa8: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188D08u;
    if (runtime->hasFunction(0x188D08u)) {
        auto targetFn = runtime->lookupFunction(0x188D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187AACu; }
        if (ctx->pc != 0x187AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188D08_0x188d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187AACu; }
        if (ctx->pc != 0x187AACu) { return; }
    }
    ctx->pc = 0x187AACu;
label_187aac:
    // 0x187aac: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x187aacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x187ab0: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x187ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x187ab4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x187ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_187ab8:
    // 0x187ab8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x187ab8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x187abc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x187abcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x187ac0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x187ac0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187ac4: 0x3e00008  jr          $ra
    ctx->pc = 0x187AC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187AC4u;
            // 0x187ac8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187A88u: goto label_187a88;
            case 0x187AACu: goto label_187aac;
            case 0x187AB8u: goto label_187ab8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187ACCu;
    // 0x187acc: 0x0  nop
    ctx->pc = 0x187accu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
