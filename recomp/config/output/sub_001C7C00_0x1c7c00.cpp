#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7C00
// Address: 0x1c7c00 - 0x1c7c70
void sub_001C7C00_0x1c7c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7C00_0x1c7c00");
#endif

    switch (ctx->pc) {
        case 0x1c7c44u: goto label_1c7c44;
        case 0x1c7c54u: goto label_1c7c54;
        default: break;
    }

    ctx->pc = 0x1c7c00u;

    // 0x1c7c00: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7C38u: goto label_1c7c38;
            case 0x1C7C44u: goto label_1c7c44;
            case 0x1C7C54u: goto label_1c7c54;
            case 0x1C7C5Cu: goto label_1c7c5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7C08u;
    // 0x1c7c08: 0x0  nop
    ctx->pc = 0x1c7c08u;
    // NOP
    // 0x1c7c0c: 0x0  nop
    ctx->pc = 0x1c7c0cu;
    // NOP
    // 0x1c7c10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c7c10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c7c14: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7c14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7c18: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c7c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c7c1c: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1c7c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1c7c20: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7c20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7c24: 0x90235056  lbu         $v1, 0x5056($at)
    ctx->pc = 0x1c7c24u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20566)));
    // 0x1c7c28: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7C28u;
    {
        const bool branch_taken_0x1c7c28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C7C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7C28u;
            // 0x1c7c2c: 0x3c040033  lui         $a0, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7c28) {
            ctx->pc = 0x1C7C38u;
            goto label_1c7c38;
        }
    }
    ctx->pc = 0x1C7C30u;
    // 0x1c7c30: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C7C30u;
    {
        const bool branch_taken_0x1c7c30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7C30u;
            // 0x1c7c34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7c30) {
            ctx->pc = 0x1C7C5Cu;
            goto label_1c7c5c;
        }
    }
    ctx->pc = 0x1C7C38u;
label_1c7c38:
    // 0x1c7c38: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1c7c38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7c3c: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1C7C3Cu;
    SET_GPR_U32(ctx, 31, 0x1C7C44u);
    ctx->pc = 0x1C7C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7C3Cu;
            // 0x1c7c40: 0x248437b0  addiu       $a0, $a0, 0x37B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7C44u; }
        if (ctx->pc != 0x1C7C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7C44u; }
        if (ctx->pc != 0x1C7C44u) { return; }
    }
    ctx->pc = 0x1C7C44u;
label_1c7c44:
    // 0x1c7c44: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7c44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7c48: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1c7c48u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1c7c4c: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1C7C4Cu;
    SET_GPR_U32(ctx, 31, 0x1C7C54u);
    ctx->pc = 0x1C7C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7C4Cu;
            // 0x1c7c50: 0x24843bd0  addiu       $a0, $a0, 0x3BD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7C54u; }
        if (ctx->pc != 0x1C7C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7C54u; }
        if (ctx->pc != 0x1C7C54u) { return; }
    }
    ctx->pc = 0x1C7C54u;
label_1c7c54:
    // 0x1c7c54: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1c7c54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1c7c58: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1c7c58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c7c5c:
    // 0x1c7c5c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c7c5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c7c60: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c7c60u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c7c64: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7C64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7C64u;
            // 0x1c7c68: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7C38u: goto label_1c7c38;
            case 0x1C7C44u: goto label_1c7c44;
            case 0x1C7C54u: goto label_1c7c54;
            case 0x1C7C5Cu: goto label_1c7c5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7C6Cu;
    // 0x1c7c6c: 0x0  nop
    ctx->pc = 0x1c7c6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
