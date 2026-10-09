#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180A40
// Address: 0x180a40 - 0x180aa0
void sub_00180A40_0x180a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180A40_0x180a40");
#endif

    switch (ctx->pc) {
        case 0x180a54u: goto label_180a54;
        default: break;
    }

    ctx->pc = 0x180a40u;

    // 0x180a40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x180a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x180a44: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x180a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x180a48: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x180a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x180a4c: 0xc06025c  jal         func_180970
    ctx->pc = 0x180A4Cu;
    SET_GPR_U32(ctx, 31, 0x180A54u);
    ctx->pc = 0x180A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180A4Cu;
            // 0x180a50: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180970u;
    if (runtime->hasFunction(0x180970u)) {
        auto targetFn = runtime->lookupFunction(0x180970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180A54u; }
        if (ctx->pc != 0x180A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180970_0x180970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180A54u; }
        if (ctx->pc != 0x180A54u) { return; }
    }
    ctx->pc = 0x180A54u;
label_180a54:
    // 0x180a54: 0x8c45007c  lw          $a1, 0x7C($v0)
    ctx->pc = 0x180a54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 124)));
    // 0x180a58: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x180A58u;
    {
        const bool branch_taken_0x180a58 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x180A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180A58u;
            // 0x180a5c: 0x24040334  addiu       $a0, $zero, 0x334 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180a58) {
            ctx->pc = 0x180A80u;
            goto label_180a80;
        }
    }
    ctx->pc = 0x180A60u;
    // 0x180a60: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x180a60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x180a64: 0x2042018  mult        $a0, $s0, $a0
    ctx->pc = 0x180a64u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x180a68: 0x24426188  addiu       $v0, $v0, 0x6188
    ctx->pc = 0x180a68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24968));
    // 0x180a6c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x180a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x180a70: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x180a70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x180a74: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x180a74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x180a78: 0x54a30003  bnel        $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x180A78u;
    {
        const bool branch_taken_0x180a78 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x180a78) {
            ctx->pc = 0x180A7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x180A78u;
            // 0x180a7c: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180A88u;
            goto label_180a88;
        }
    }
    ctx->pc = 0x180A80u;
label_180a80:
    // 0x180a80: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x180A80u;
    {
        const bool branch_taken_0x180a80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180A80u;
            // 0x180a84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180a80) {
            ctx->pc = 0x180A8Cu;
            goto label_180a8c;
        }
    }
    ctx->pc = 0x180A88u;
label_180a88:
    // 0x180a88: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x180a88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_180a8c:
    // 0x180a8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x180a8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180a90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180a90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180a94: 0x3e00008  jr          $ra
    ctx->pc = 0x180A94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180A94u;
            // 0x180a98: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180A54u: goto label_180a54;
            case 0x180A80u: goto label_180a80;
            case 0x180A88u: goto label_180a88;
            case 0x180A8Cu: goto label_180a8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180A9Cu;
    // 0x180a9c: 0x0  nop
    ctx->pc = 0x180a9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
