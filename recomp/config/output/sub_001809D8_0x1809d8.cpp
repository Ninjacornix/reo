#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001809D8
// Address: 0x1809d8 - 0x180a40
void sub_001809D8_0x1809d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001809D8_0x1809d8");
#endif

    switch (ctx->pc) {
        case 0x180a10u: goto label_180a10;
        default: break;
    }

    ctx->pc = 0x1809d8u;

    // 0x1809d8: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x1809d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x1809dc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1809dcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1809e0: 0x832018  mult        $a0, $a0, $v1
    ctx->pc = 0x1809e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1809e4: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x1809e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1809e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1809e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1809ec: 0x24426188  addiu       $v0, $v0, 0x6188
    ctx->pc = 0x1809ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24968));
    // 0x1809f0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1809f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1809f4: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1809f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1809f8: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1809f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1809fc: 0x24620080  addiu       $v0, $v1, 0x80
    ctx->pc = 0x1809fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 128));
    // 0x180a00: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x180a00u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x180a04: 0x24850100  addiu       $a1, $a0, 0x100
    ctx->pc = 0x180a04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 256));
    // 0x180a08: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x180A08u;
    SET_GPR_U32(ctx, 31, 0x180A10u);
    ctx->pc = 0x180A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180A08u;
            // 0x180a0c: 0xafa30000  sw          $v1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180A10u; }
        if (ctx->pc != 0x180A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180A10u; }
        if (ctx->pc != 0x180A10u) { return; }
    }
    ctx->pc = 0x180A10u;
label_180a10:
    // 0x180a10: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x180a10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180a14: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x180a14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x180a18: 0x8c82007c  lw          $v0, 0x7C($a0)
    ctx->pc = 0x180a18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 124)));
    // 0x180a1c: 0x8ca3007c  lw          $v1, 0x7C($a1)
    ctx->pc = 0x180a1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 124)));
    // 0x180a20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x180a20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180a24: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x180a24u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x180a28: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x180a28u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x180a2c: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x180a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x180a30: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x180a30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x180a34: 0x3e00008  jr          $ra
    ctx->pc = 0x180A34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180A34u;
            // 0x180a38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180A10u: goto label_180a10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180A3Cu;
    // 0x180a3c: 0x0  nop
    ctx->pc = 0x180a3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
