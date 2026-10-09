#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147D30
// Address: 0x147d30 - 0x147d78
void sub_00147D30_0x147d30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147D30_0x147d30");
#endif

    switch (ctx->pc) {
        case 0x147d6cu: goto label_147d6c;
        default: break;
    }

    ctx->pc = 0x147d30u;

    // 0x147d30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x147d30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x147d34: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x147d34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x147d38: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x147d38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x147d3c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x147d3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x147d40: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x147d40u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x147d44: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x147d44u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x147d48: 0x8c870040  lw          $a3, 0x40($a0)
    ctx->pc = 0x147d48u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147d4c: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x147d4cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x147d50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x147d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x147d54: 0xace200c8  sw          $v0, 0xC8($a3)
    ctx->pc = 0x147d54u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 200), GPR_U32(ctx, 2));
    // 0x147d58: 0xace500f0  sw          $a1, 0xF0($a3)
    ctx->pc = 0x147d58u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 240), GPR_U32(ctx, 5));
    // 0x147d5c: 0xace600fc  sw          $a2, 0xFC($a3)
    ctx->pc = 0x147d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 252), GPR_U32(ctx, 6));
    // 0x147d60: 0xace000f4  sw          $zero, 0xF4($a3)
    ctx->pc = 0x147d60u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 244), GPR_U32(ctx, 0));
    // 0x147d64: 0xc05205c  jal         func_148170
    ctx->pc = 0x147D64u;
    SET_GPR_U32(ctx, 31, 0x147D6Cu);
    ctx->pc = 0x147D68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147D64u;
            // 0x147d68: 0xace000f8  sw          $zero, 0xF8($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 248), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148170u;
    if (runtime->hasFunction(0x148170u)) {
        auto targetFn = runtime->lookupFunction(0x148170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147D6Cu; }
        if (ctx->pc != 0x147D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148170_0x148170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147D6Cu; }
        if (ctx->pc != 0x147D6Cu) { return; }
    }
    ctx->pc = 0x147D6Cu;
label_147d6c:
    // 0x147d6c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x147d6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147d70: 0x3e00008  jr          $ra
    ctx->pc = 0x147D70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147D70u;
            // 0x147d74: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147D6Cu: goto label_147d6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147D78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
