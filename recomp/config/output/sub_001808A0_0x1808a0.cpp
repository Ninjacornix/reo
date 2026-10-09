#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001808A0
// Address: 0x1808a0 - 0x180918
void sub_001808A0_0x1808a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001808A0_0x1808a0");
#endif

    switch (ctx->pc) {
        case 0x1808d0u: goto label_1808d0;
        case 0x1808fcu: goto label_1808fc;
        default: break;
    }

    ctx->pc = 0x1808a0u;

    // 0x1808a0: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x1808a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x1808a4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1808a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1808a8: 0x832018  mult        $a0, $a0, $v1
    ctx->pc = 0x1808a8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1808ac: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x1808acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1808b0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1808b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1808b4: 0x24426188  addiu       $v0, $v0, 0x6188
    ctx->pc = 0x1808b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24968));
    // 0x1808b8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1808b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1808bc: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1808bcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1808c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1808c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1808c4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1808c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1808c8: 0x8c500010  lw          $s0, 0x10($v0)
    ctx->pc = 0x1808c8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1808cc: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1808ccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1808d0:
    // 0x1808d0: 0x2604001c  addiu       $a0, $s0, 0x1C
    ctx->pc = 0x1808d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 28));
    // 0x1808d4: 0xae00007c  sw          $zero, 0x7C($s0)
    ctx->pc = 0x1808d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 124), GPR_U32(ctx, 0));
    // 0x1808d8: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1808d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1808dc: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1808dcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1808e0: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1808e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1808e4: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1808e4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1808e8: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1808e8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x1808ec: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1808ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1808f0: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1808f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1808f4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1808F4u;
    SET_GPR_U32(ctx, 31, 0x1808FCu);
    ctx->pc = 0x1808F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1808F4u;
            // 0x1808f8: 0x26100080  addiu       $s0, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1808FCu; }
        if (ctx->pc != 0x1808FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1808FCu; }
        if (ctx->pc != 0x1808FCu) { return; }
    }
    ctx->pc = 0x1808FCu;
label_1808fc:
    // 0x1808fc: 0x623fff4  bgezl       $s1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1808FCu;
    {
        const bool branch_taken_0x1808fc = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x1808fc) {
            ctx->pc = 0x180900u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1808FCu;
            // 0x180900: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1808D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1808d0;
        }
    }
    ctx->pc = 0x180904u;
    // 0x180904: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x180904u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x180908: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x180908u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18090c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18090cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180910: 0x3e00008  jr          $ra
    ctx->pc = 0x180910u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180910u;
            // 0x180914: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1808D0u: goto label_1808d0;
            case 0x1808FCu: goto label_1808fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180918u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
