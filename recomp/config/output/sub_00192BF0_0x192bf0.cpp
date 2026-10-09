#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192BF0
// Address: 0x192bf0 - 0x192c74
void sub_00192BF0_0x192bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192BF0_0x192bf0");
#endif

    switch (ctx->pc) {
        case 0x192c18u: goto label_192c18;
        case 0x192c44u: goto label_192c44;
        case 0x192c58u: goto label_192c58;
        default: break;
    }

    ctx->pc = 0x192bf0u;

    // 0x192bf0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x192bf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x192bf4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x192bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x192bf8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x192bf8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x192bfc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192bfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x192c00: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x192c00u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c04: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x192c04u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192c08: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x192c08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c0c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x192c0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c10: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x192C10u;
    SET_GPR_U32(ctx, 31, 0x192C18u);
    ctx->pc = 0x192C14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192C10u;
            // 0x192c14: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C18u; }
        if (ctx->pc != 0x192C18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C18u; }
        if (ctx->pc != 0x192C18u) { return; }
    }
    ctx->pc = 0x192C18u;
label_192c18:
    // 0x192c18: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192c18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x192c1c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x192c1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c20: 0xac224168  sw          $v0, 0x4168($at)
    ctx->pc = 0x192c20u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16744), GPR_U32(ctx, 2));
    // 0x192c24: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x192c24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c28: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x192c28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x192c2c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192c2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x192c30: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x192c30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x192c34: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x192c34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x192c38: 0x0  nop
    ctx->pc = 0x192c38u;
    // NOP
    // 0x192c3c: 0xc064b44  jal         func_192D10
    ctx->pc = 0x192C3Cu;
    SET_GPR_U32(ctx, 31, 0x192C44u);
    ctx->pc = 0x192C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192C3Cu;
            // 0x192c40: 0x628021  addu        $s0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192D10u;
    if (runtime->hasFunction(0x192D10u)) {
        auto targetFn = runtime->lookupFunction(0x192D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C44u; }
        if (ctx->pc != 0x192C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C44u; }
        if (ctx->pc != 0x192C44u) { return; }
    }
    ctx->pc = 0x192C44u;
label_192c44:
    // 0x192c44: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x192C44u;
    {
        const bool branch_taken_0x192c44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x192C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192C44u;
            // 0x192c48: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192c44) {
            ctx->pc = 0x192C58u;
            goto label_192c58;
        }
    }
    ctx->pc = 0x192C4Cu;
    // 0x192c4c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x192c4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c50: 0xc064b20  jal         func_192C80
    ctx->pc = 0x192C50u;
    SET_GPR_U32(ctx, 31, 0x192C58u);
    ctx->pc = 0x192C54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192C50u;
            // 0x192c54: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192C80u;
    if (runtime->hasFunction(0x192C80u)) {
        auto targetFn = runtime->lookupFunction(0x192C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C58u; }
        if (ctx->pc != 0x192C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192C80_0x192c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C58u; }
        if (ctx->pc != 0x192C58u) { return; }
    }
    ctx->pc = 0x192C58u;
label_192c58:
    // 0x192c58: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x192c58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x192c5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192c60: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x192c60u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192c64: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x192c64u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192c68: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x192c68u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x192C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192C6Cu;
            // 0x192c70: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192C18u: goto label_192c18;
            case 0x192C44u: goto label_192c44;
            case 0x192C58u: goto label_192c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192C74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
