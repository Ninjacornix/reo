#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001324F8
// Address: 0x1324f8 - 0x132548
void sub_001324F8_0x1324f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001324F8_0x1324f8");
#endif

    switch (ctx->pc) {
        case 0x132510u: goto label_132510;
        default: break;
    }

    ctx->pc = 0x1324f8u;

    // 0x1324f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1324f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1324fc: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1324FCu;
    {
        const bool branch_taken_0x1324fc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1324FCu;
            // 0x132500: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1324fc) {
            ctx->pc = 0x132518u;
            goto label_132518;
        }
    }
    ctx->pc = 0x132504u;
    // 0x132504: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132504u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132508: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132508u;
    SET_GPR_U32(ctx, 31, 0x132510u);
    ctx->pc = 0x13250Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132508u;
            // 0x13250c: 0x2484afc8  addiu       $a0, $a0, -0x5038 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946760));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132510u; }
        if (ctx->pc != 0x132510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132510u; }
        if (ctx->pc != 0x132510u) { return; }
    }
    ctx->pc = 0x132510u;
label_132510:
    // 0x132510: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x132510u;
    {
        const bool branch_taken_0x132510 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132510u;
            // 0x132514: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132510) {
            ctx->pc = 0x132538u;
            goto label_132538;
        }
    }
    ctx->pc = 0x132518u;
label_132518:
    // 0x132518: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x132518u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x13251c: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x13251cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x132520: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x132520u;
    {
        const bool branch_taken_0x132520 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x132520) {
            ctx->pc = 0x132524u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x132520u;
            // 0x132524: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x132538u;
            goto label_132538;
        }
    }
    ctx->pc = 0x132528u;
    // 0x132528: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x132528u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x13252c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13252cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132530: 0x804b5e4  j           func_12D790
    ctx->pc = 0x132530u;
    ctx->pc = 0x132534u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132530u;
            // 0x132534: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D790u;
    if (runtime->hasFunction(0x12D790u)) {
        auto targetFn = runtime->lookupFunction(0x12D790u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D790_0x12d790(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132538u;
label_132538:
    // 0x132538: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132538u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13253c: 0x3e00008  jr          $ra
    ctx->pc = 0x13253Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13253Cu;
            // 0x132540: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132510u: goto label_132510;
            case 0x132518u: goto label_132518;
            case 0x132538u: goto label_132538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132544u;
    // 0x132544: 0x0  nop
    ctx->pc = 0x132544u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
