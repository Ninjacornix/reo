#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD150
// Address: 0x1cd150 - 0x1cd1c0
void sub_001CD150_0x1cd150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD150_0x1cd150");
#endif

    switch (ctx->pc) {
        case 0x1cd170u: goto label_1cd170;
        case 0x1cd184u: goto label_1cd184;
        case 0x1cd194u: goto label_1cd194;
        default: break;
    }

    ctx->pc = 0x1cd150u;

    // 0x1cd150: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd154: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1cd154u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cd158: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd15c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd15cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd160: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1cd160u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1cd164: 0x26101640  addiu       $s0, $s0, 0x1640
    ctx->pc = 0x1cd164u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5696));
    // 0x1cd168: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1CD168u;
    {
        const bool branch_taken_0x1cd168 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD168u;
            // 0x1cd16c: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd168) {
            ctx->pc = 0x1CD1A4u;
            goto label_1cd1a4;
        }
    }
    ctx->pc = 0x1CD170u;
label_1cd170:
    // 0x1cd170: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1cd170u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cd174: 0x14640009  bne         $v1, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CD174u;
    {
        const bool branch_taken_0x1cd174 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cd174) {
            ctx->pc = 0x1CD19Cu;
            goto label_1cd19c;
        }
    }
    ctx->pc = 0x1CD17Cu;
    // 0x1cd17c: 0xc07328c  jal         func_1CCA30
    ctx->pc = 0x1CD17Cu;
    SET_GPR_U32(ctx, 31, 0x1CD184u);
    ctx->pc = 0x1CD180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD17Cu;
            // 0x1cd180: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCA30u;
    if (runtime->hasFunction(0x1CCA30u)) {
        auto targetFn = runtime->lookupFunction(0x1CCA30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD184u; }
        if (ctx->pc != 0x1CD184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCA30_0x1cca30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD184u; }
        if (ctx->pc != 0x1CD184u) { return; }
    }
    ctx->pc = 0x1CD184u;
label_1cd184:
    // 0x1cd184: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1cd184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd188: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cd188u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd18c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CD18Cu;
    SET_GPR_U32(ctx, 31, 0x1CD194u);
    ctx->pc = 0x1CD190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD18Cu;
            // 0x1cd190: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD194u; }
        if (ctx->pc != 0x1CD194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD194u; }
        if (ctx->pc != 0x1CD194u) { return; }
    }
    ctx->pc = 0x1CD194u;
label_1cd194:
    // 0x1cd194: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CD194u;
    {
        const bool branch_taken_0x1cd194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD194u;
            // 0x1cd198: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd194) {
            ctx->pc = 0x1CD1B4u;
            goto label_1cd1b4;
        }
    }
    ctx->pc = 0x1CD19Cu;
label_1cd19c:
    // 0x1cd19c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cd19cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cd1a0: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x1cd1a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_1cd1a4:
    // 0x1cd1a4: 0x28a30100  slti        $v1, $a1, 0x100
    ctx->pc = 0x1cd1a4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1cd1a8: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1CD1A8u;
    {
        const bool branch_taken_0x1cd1a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cd1a8) {
            ctx->pc = 0x1CD170u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cd170;
        }
    }
    ctx->pc = 0x1CD1B0u;
    // 0x1cd1b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd1b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1cd1b4:
    // 0x1cd1b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd1b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd1b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD1B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD1B8u;
            // 0x1cd1bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD170u: goto label_1cd170;
            case 0x1CD184u: goto label_1cd184;
            case 0x1CD194u: goto label_1cd194;
            case 0x1CD19Cu: goto label_1cd19c;
            case 0x1CD1A4u: goto label_1cd1a4;
            case 0x1CD1B4u: goto label_1cd1b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD1C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
