#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182C48
// Address: 0x182c48 - 0x182ca0
void sub_00182C48_0x182c48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182C48_0x182c48");
#endif

    switch (ctx->pc) {
        case 0x182c5cu: goto label_182c5c;
        default: break;
    }

    ctx->pc = 0x182c48u;

    // 0x182c48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x182c48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x182c4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182c50: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x182c50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x182c54: 0xc060b02  jal         func_182C08
    ctx->pc = 0x182C54u;
    SET_GPR_U32(ctx, 31, 0x182C5Cu);
    ctx->pc = 0x182C58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182C54u;
            // 0x182c58: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C08u;
    if (runtime->hasFunction(0x182C08u)) {
        auto targetFn = runtime->lookupFunction(0x182C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182C5Cu; }
        if (ctx->pc != 0x182C5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C08_0x182c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182C5Cu; }
        if (ctx->pc != 0x182C5Cu) { return; }
    }
    ctx->pc = 0x182C5Cu;
label_182c5c:
    // 0x182c5c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x182c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x182c60: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x182c60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182c64: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x182c64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x182c68: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x182C68u;
    {
        const bool branch_taken_0x182c68 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x182C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182C68u;
            // 0x182c6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182c68) {
            ctx->pc = 0x182C90u;
            goto label_182c90;
        }
    }
    ctx->pc = 0x182C70u;
    // 0x182c70: 0x54850005  bnel        $a0, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x182C70u;
    {
        const bool branch_taken_0x182c70 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 5));
        if (branch_taken_0x182c70) {
            ctx->pc = 0x182C74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182C70u;
            // 0x182c74: 0x3c027fff  lui         $v0, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182C88u;
            goto label_182c88;
        }
    }
    ctx->pc = 0x182C78u;
    // 0x182c78: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x182c78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x182c7c: 0x34630059  ori         $v1, $v1, 0x59
    ctx->pc = 0x182c7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)89);
    // 0x182c80: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x182C80u;
    {
        const bool branch_taken_0x182c80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182C84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182C80u;
            // 0x182c84: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182c80) {
            ctx->pc = 0x182C90u;
            goto label_182c90;
        }
    }
    ctx->pc = 0x182C88u;
label_182c88:
    // 0x182c88: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x182c88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x182c8c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x182c8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
label_182c90:
    // 0x182c90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182c90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x182c94: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x182c94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x182c98: 0x3e00008  jr          $ra
    ctx->pc = 0x182C98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182C98u;
            // 0x182c9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182C5Cu: goto label_182c5c;
            case 0x182C88u: goto label_182c88;
            case 0x182C90u: goto label_182c90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182CA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
