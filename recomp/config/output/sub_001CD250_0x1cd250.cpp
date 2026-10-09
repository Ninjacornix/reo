#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD250
// Address: 0x1cd250 - 0x1cd2c0
void sub_001CD250_0x1cd250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD250_0x1cd250");
#endif

    switch (ctx->pc) {
        case 0x1cd260u: goto label_1cd260;
        case 0x1cd274u: goto label_1cd274;
        default: break;
    }

    ctx->pc = 0x1cd250u;

    // 0x1cd250: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cd250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cd254: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cd254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cd258: 0xc07340c  jal         func_1CD030
    ctx->pc = 0x1CD258u;
    SET_GPR_U32(ctx, 31, 0x1CD260u);
    ctx->pc = 0x1CD030u;
    if (runtime->hasFunction(0x1CD030u)) {
        auto targetFn = runtime->lookupFunction(0x1CD030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD260u; }
        if (ctx->pc != 0x1CD260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD030_0x1cd030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD260u; }
        if (ctx->pc != 0x1CD260u) { return; }
    }
    ctx->pc = 0x1CD260u;
label_1cd260:
    // 0x1cd260: 0x3c060034  lui         $a2, 0x34
    ctx->pc = 0x1cd260u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)52 << 16));
    // 0x1cd264: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1cd264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd268: 0x24c61640  addiu       $a2, $a2, 0x1640
    ctx->pc = 0x1cd268u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5696));
    // 0x1cd26c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CD26Cu;
    {
        const bool branch_taken_0x1cd26c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD26Cu;
            // 0x1cd270: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd26c) {
            ctx->pc = 0x1CD29Cu;
            goto label_1cd29c;
        }
    }
    ctx->pc = 0x1CD274u;
label_1cd274:
    // 0x1cd274: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1cd274u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1cd278: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CD278u;
    {
        const bool branch_taken_0x1cd278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd278) {
            ctx->pc = 0x1CD294u;
            goto label_1cd294;
        }
    }
    ctx->pc = 0x1CD280u;
    // 0x1cd280: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1cd280u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1cd284: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CD284u;
    {
        const bool branch_taken_0x1cd284 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cd284) {
            ctx->pc = 0x1CD294u;
            goto label_1cd294;
        }
    }
    ctx->pc = 0x1CD28Cu;
    // 0x1cd28c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CD28Cu;
    {
        const bool branch_taken_0x1cd28c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD28Cu;
            // 0x1cd290: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd28c) {
            ctx->pc = 0x1CD2ACu;
            goto label_1cd2ac;
        }
    }
    ctx->pc = 0x1CD294u;
label_1cd294:
    // 0x1cd294: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cd294u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cd298: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x1cd298u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
label_1cd29c:
    // 0x1cd29c: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x1cd29cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1cd2a0: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1CD2A0u;
    {
        const bool branch_taken_0x1cd2a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD2A0u;
            // 0x1cd2a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd2a0) {
            ctx->pc = 0x1CD274u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cd274;
        }
    }
    ctx->pc = 0x1CD2A8u;
    // 0x1cd2a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cd2a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1cd2ac:
    // 0x1cd2ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD2ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD2B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD2ACu;
            // 0x1cd2b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD260u: goto label_1cd260;
            case 0x1CD274u: goto label_1cd274;
            case 0x1CD294u: goto label_1cd294;
            case 0x1CD29Cu: goto label_1cd29c;
            case 0x1CD2ACu: goto label_1cd2ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD2B4u;
    // 0x1cd2b4: 0x0  nop
    ctx->pc = 0x1cd2b4u;
    // NOP
    // 0x1cd2b8: 0x0  nop
    ctx->pc = 0x1cd2b8u;
    // NOP
    // 0x1cd2bc: 0x0  nop
    ctx->pc = 0x1cd2bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
