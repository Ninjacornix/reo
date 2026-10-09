#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135C18
// Address: 0x135c18 - 0x135c80
void sub_00135C18_0x135c18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135C18_0x135c18");
#endif

    switch (ctx->pc) {
        case 0x135c3cu: goto label_135c3c;
        default: break;
    }

    ctx->pc = 0x135c18u;

    // 0x135c18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135c18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x135c1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135c1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135c20: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x135c20u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x135c24: 0x26102268  addiu       $s0, $s0, 0x2268
    ctx->pc = 0x135c24u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8808));
    // 0x135c28: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135c2c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x135c2cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135c30: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x135c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x135c34: 0xc042c56  jal         func_10B158
    ctx->pc = 0x135C34u;
    SET_GPR_U32(ctx, 31, 0x135C3Cu);
    ctx->pc = 0x135C38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135C34u;
            // 0x135c38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135C3Cu; }
        if (ctx->pc != 0x135C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135C3Cu; }
        if (ctx->pc != 0x135C3Cu) { return; }
    }
    ctx->pc = 0x135C3Cu;
label_135c3c:
    // 0x135c3c: 0x24460001  addiu       $a2, $v0, 0x1
    ctx->pc = 0x135c3cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x135c40: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x135c40u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x135c44: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x135c44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135c48: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x135C48u;
    {
        const bool branch_taken_0x135c48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135C4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135C48u;
            // 0x135c4c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135c48) {
            ctx->pc = 0x135C68u;
            goto label_135c68;
        }
    }
    ctx->pc = 0x135C50u;
    // 0x135c50: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x135c50u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x135c54: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135c54u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135c58: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135c58u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135c5c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x135c5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135c60: 0x3e00008  jr          $ra
    ctx->pc = 0x135C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135C60u;
            // 0x135c64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135C3Cu: goto label_135c3c;
            case 0x135C68u: goto label_135c68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135C68u;
label_135c68:
    // 0x135c68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135c68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135c6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135c6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135c70: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x135c70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135c74: 0x8041eac  j           func_107AB0
    ctx->pc = 0x135C74u;
    ctx->pc = 0x135C78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135C74u;
            // 0x135c78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135C7Cu;
    // 0x135c7c: 0x0  nop
    ctx->pc = 0x135c7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
