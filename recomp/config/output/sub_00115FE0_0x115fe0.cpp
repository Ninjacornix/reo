#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115FE0
// Address: 0x115fe0 - 0x116014
void sub_00115FE0_0x115fe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115FE0_0x115fe0");
#endif

    switch (ctx->pc) {
        case 0x115ff8u: goto label_115ff8;
        default: break;
    }

    ctx->pc = 0x115fe0u;

    // 0x115fe0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x115fe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x115fe4: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x115fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x115fe8: 0x14820007  bne         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x115FE8u;
    {
        const bool branch_taken_0x115fe8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x115FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115FE8u;
            // 0x115fec: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115fe8) {
            ctx->pc = 0x116008u;
            goto label_116008;
        }
    }
    ctx->pc = 0x115FF0u;
    // 0x115ff0: 0xc0457bc  jal         func_115EF0
    ctx->pc = 0x115FF0u;
    SET_GPR_U32(ctx, 31, 0x115FF8u);
    ctx->pc = 0x115FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115FF0u;
            // 0x115ff4: 0x2404000d  addiu       $a0, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115EF0u;
    if (runtime->hasFunction(0x115EF0u)) {
        auto targetFn = runtime->lookupFunction(0x115EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115FF8u; }
        if (ctx->pc != 0x115FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115EF0_0x115ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115FF8u; }
        if (ctx->pc != 0x115FF8u) { return; }
    }
    ctx->pc = 0x115FF8u;
label_115ff8:
    // 0x115ff8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x115ff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115ffc: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x115ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x116000: 0x80457bc  j           func_115EF0
    ctx->pc = 0x116000u;
    ctx->pc = 0x116004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116000u;
            // 0x116004: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115EF0u;
    if (runtime->hasFunction(0x115EF0u)) {
        auto targetFn = runtime->lookupFunction(0x115EF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00115EF0_0x115ef0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x116008u;
label_116008:
    // 0x116008: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x116008u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11600c: 0x80457bc  j           func_115EF0
    ctx->pc = 0x11600Cu;
    ctx->pc = 0x116010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11600Cu;
            // 0x116010: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115EF0u;
    if (runtime->hasFunction(0x115EF0u)) {
        auto targetFn = runtime->lookupFunction(0x115EF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00115EF0_0x115ef0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x116014u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
