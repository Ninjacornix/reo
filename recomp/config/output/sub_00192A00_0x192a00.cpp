#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192A00
// Address: 0x192a00 - 0x192a60
void sub_00192A00_0x192a00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192A00_0x192a00");
#endif

    switch (ctx->pc) {
        case 0x192a20u: goto label_192a20;
        case 0x192a48u: goto label_192a48;
        default: break;
    }

    ctx->pc = 0x192a00u;

    // 0x192a00: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x192a00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x192a04: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x192a04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x192a08: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192a08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x192a0c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x192a0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192a10: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x192a10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192a14: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x192a14u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192a18: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x192A18u;
    SET_GPR_U32(ctx, 31, 0x192A20u);
    ctx->pc = 0x192A1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192A18u;
            // 0x192a1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A20u; }
        if (ctx->pc != 0x192A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A20u; }
        if (ctx->pc != 0x192A20u) { return; }
    }
    ctx->pc = 0x192A20u;
label_192a20:
    // 0x192a20: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192a20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x192a24: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x192a24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192a28: 0xac224168  sw          $v0, 0x4168($at)
    ctx->pc = 0x192a28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16744), GPR_U32(ctx, 2));
    // 0x192a2c: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x192a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x192a30: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192a30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x192a34: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x192a34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x192a38: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x192a38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x192a3c: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x192a3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x192a40: 0xc064a98  jal         func_192A60
    ctx->pc = 0x192A40u;
    SET_GPR_U32(ctx, 31, 0x192A48u);
    ctx->pc = 0x192A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192A40u;
            // 0x192a44: 0xac30fe40  sw          $s0, -0x1C0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966848), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192A60u;
    if (runtime->hasFunction(0x192A60u)) {
        auto targetFn = runtime->lookupFunction(0x192A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A48u; }
        if (ctx->pc != 0x192A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192A60_0x192a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192A48u; }
        if (ctx->pc != 0x192A48u) { return; }
    }
    ctx->pc = 0x192A48u;
label_192a48:
    // 0x192a48: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x192a48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192a4c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192a50: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x192a50u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192a54: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x192a54u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192a58: 0x3e00008  jr          $ra
    ctx->pc = 0x192A58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192A58u;
            // 0x192a5c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192A20u: goto label_192a20;
            case 0x192A48u: goto label_192a48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192A60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
