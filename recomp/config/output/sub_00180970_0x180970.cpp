#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180970
// Address: 0x180970 - 0x1809d8
void sub_00180970_0x180970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180970_0x180970");
#endif

    switch (ctx->pc) {
        case 0x1809a8u: goto label_1809a8;
        default: break;
    }

    ctx->pc = 0x180970u;

    // 0x180970: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x180970u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x180974: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x180974u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x180978: 0x832018  mult        $a0, $a0, $v1
    ctx->pc = 0x180978u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x18097c: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x18097cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x180980: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x180980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x180984: 0x24426188  addiu       $v0, $v0, 0x6188
    ctx->pc = 0x180984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24968));
    // 0x180988: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x180988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18098c: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x18098cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x180990: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x180990u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180994: 0x24620080  addiu       $v0, $v1, 0x80
    ctx->pc = 0x180994u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 128));
    // 0x180998: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x180998u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x18099c: 0x248500ff  addiu       $a1, $a0, 0xFF
    ctx->pc = 0x18099cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 255));
    // 0x1809a0: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x1809A0u;
    SET_GPR_U32(ctx, 31, 0x1809A8u);
    ctx->pc = 0x1809A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1809A0u;
            // 0x1809a4: 0xafa30000  sw          $v1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1809A8u; }
        if (ctx->pc != 0x1809A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1809A8u; }
        if (ctx->pc != 0x1809A8u) { return; }
    }
    ctx->pc = 0x1809A8u;
label_1809a8:
    // 0x1809a8: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1809a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1809ac: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x1809acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1809b0: 0x8c82007c  lw          $v0, 0x7C($a0)
    ctx->pc = 0x1809b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 124)));
    // 0x1809b4: 0x8ca3007c  lw          $v1, 0x7C($a1)
    ctx->pc = 0x1809b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 124)));
    // 0x1809b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1809b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1809bc: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1809bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1809c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1809c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1809c4: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x1809c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x1809c8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1809c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1809cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1809CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1809D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1809CCu;
            // 0x1809d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1809A8u: goto label_1809a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1809D4u;
    // 0x1809d4: 0x0  nop
    ctx->pc = 0x1809d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
