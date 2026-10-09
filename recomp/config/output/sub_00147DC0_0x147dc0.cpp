#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147DC0
// Address: 0x147dc0 - 0x147e10
void sub_00147DC0_0x147dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147DC0_0x147dc0");
#endif

    switch (ctx->pc) {
        case 0x147e04u: goto label_147e04;
        default: break;
    }

    ctx->pc = 0x147dc0u;

    // 0x147dc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x147dc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x147dc4: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x147dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x147dc8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x147dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x147dcc: 0xc74018  mult        $t0, $a2, $a3
    ctx->pc = 0x147dccu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x147dd0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x147dd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x147dd4: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x147dd4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x147dd8: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x147dd8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x147ddc: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x147ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147de0: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x147de0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x147de4: 0x73900  sll         $a3, $a3, 4
    ctx->pc = 0x147de4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x147de8: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x147de8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x147dec: 0xac6700f8  sw          $a3, 0xF8($v1)
    ctx->pc = 0x147decu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 248), GPR_U32(ctx, 7));
    // 0x147df0: 0xac6500f0  sw          $a1, 0xF0($v1)
    ctx->pc = 0x147df0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 240), GPR_U32(ctx, 5));
    // 0x147df4: 0xac6800fc  sw          $t0, 0xFC($v1)
    ctx->pc = 0x147df4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 252), GPR_U32(ctx, 8));
    // 0x147df8: 0xac6600f4  sw          $a2, 0xF4($v1)
    ctx->pc = 0x147df8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 244), GPR_U32(ctx, 6));
    // 0x147dfc: 0xc05205c  jal         func_148170
    ctx->pc = 0x147DFCu;
    SET_GPR_U32(ctx, 31, 0x147E04u);
    ctx->pc = 0x147E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147DFCu;
            // 0x147e00: 0xac6000c8  sw          $zero, 0xC8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 200), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148170u;
    if (runtime->hasFunction(0x148170u)) {
        auto targetFn = runtime->lookupFunction(0x148170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147E04u; }
        if (ctx->pc != 0x147E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148170_0x148170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147E04u; }
        if (ctx->pc != 0x147E04u) { return; }
    }
    ctx->pc = 0x147E04u;
label_147e04:
    // 0x147e04: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x147e04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147e08: 0x3e00008  jr          $ra
    ctx->pc = 0x147E08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147E08u;
            // 0x147e0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147E04u: goto label_147e04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147E10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
