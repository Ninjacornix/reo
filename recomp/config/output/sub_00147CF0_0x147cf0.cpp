#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147CF0
// Address: 0x147cf0 - 0x147d2c
void sub_00147CF0_0x147cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147CF0_0x147cf0");
#endif

    switch (ctx->pc) {
        case 0x147d1cu: goto label_147d1c;
        default: break;
    }

    ctx->pc = 0x147cf0u;

    // 0x147cf0: 0x24c30013  addiu       $v1, $a2, 0x13
    ctx->pc = 0x147cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 19));
    // 0x147cf4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x147cf4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x147cf8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x147cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x147cfc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x147cfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x147d00: 0x24c60022  addiu       $a2, $a2, 0x22
    ctx->pc = 0x147d00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 34));
    // 0x147d04: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x147d04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x147d08: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x147d08u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x147d0c: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x147d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147d10: 0x63103  sra         $a2, $a2, 4
    ctx->pc = 0x147d10u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 4));
    // 0x147d14: 0xc052232  jal         func_1488C8
    ctx->pc = 0x147D14u;
    SET_GPR_U32(ctx, 31, 0x147D1Cu);
    ctx->pc = 0x147D18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147D14u;
            // 0x147d18: 0x63100  sll         $a2, $a2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1488C8u;
    if (runtime->hasFunction(0x1488C8u)) {
        auto targetFn = runtime->lookupFunction(0x1488C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147D1Cu; }
        if (ctx->pc != 0x147D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001488C8_0x1488c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147D1Cu; }
        if (ctx->pc != 0x147D1Cu) { return; }
    }
    ctx->pc = 0x147D1Cu;
label_147d1c:
    // 0x147d1c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x147d1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147d20: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x147d20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x147d24: 0x3e00008  jr          $ra
    ctx->pc = 0x147D24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147D24u;
            // 0x147d28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147D1Cu: goto label_147d1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147D2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
