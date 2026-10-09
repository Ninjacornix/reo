#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001325E8
// Address: 0x1325e8 - 0x132634
void sub_001325E8_0x1325e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001325E8_0x1325e8");
#endif

    switch (ctx->pc) {
        case 0x132600u: goto label_132600;
        default: break;
    }

    ctx->pc = 0x1325e8u;

    // 0x1325e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1325e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1325ec: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1325ECu;
    {
        const bool branch_taken_0x1325ec = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1325F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1325ECu;
            // 0x1325f0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1325ec) {
            ctx->pc = 0x132608u;
            goto label_132608;
        }
    }
    ctx->pc = 0x1325F4u;
    // 0x1325f4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1325f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1325f8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1325F8u;
    SET_GPR_U32(ctx, 31, 0x132600u);
    ctx->pc = 0x1325FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1325F8u;
            // 0x1325fc: 0x2484b058  addiu       $a0, $a0, -0x4FA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132600u; }
        if (ctx->pc != 0x132600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132600u; }
        if (ctx->pc != 0x132600u) { return; }
    }
    ctx->pc = 0x132600u;
label_132600:
    // 0x132600: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x132600u;
    {
        const bool branch_taken_0x132600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132600u;
            // 0x132604: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132600) {
            ctx->pc = 0x132628u;
            goto label_132628;
        }
    }
    ctx->pc = 0x132608u;
label_132608:
    // 0x132608: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x132608u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x13260c: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x13260cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x132610: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x132610u;
    {
        const bool branch_taken_0x132610 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x132610) {
            ctx->pc = 0x132614u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x132610u;
            // 0x132614: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x132628u;
            goto label_132628;
        }
    }
    ctx->pc = 0x132618u;
    // 0x132618: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x132618u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x13261c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13261cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132620: 0x804b686  j           func_12DA18
    ctx->pc = 0x132620u;
    ctx->pc = 0x132624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132620u;
            // 0x132624: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA18u;
    if (runtime->hasFunction(0x12DA18u)) {
        auto targetFn = runtime->lookupFunction(0x12DA18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012DA18_0x12da18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132628u;
label_132628:
    // 0x132628: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132628u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13262c: 0x3e00008  jr          $ra
    ctx->pc = 0x13262Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13262Cu;
            // 0x132630: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132600u: goto label_132600;
            case 0x132608u: goto label_132608;
            case 0x132628u: goto label_132628;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132634u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
