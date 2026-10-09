#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117708
// Address: 0x117708 - 0x117748
void sub_00117708_0x117708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117708_0x117708");
#endif

    switch (ctx->pc) {
        case 0x117730u: goto label_117730;
        default: break;
    }

    ctx->pc = 0x117708u;

    // 0x117708: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x117708u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11770c: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x11770cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117710: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x117710u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117714: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x117714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x117718: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x117718u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x11771c: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x11771cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117720: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x117720u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117724: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x117724u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117728: 0xc045b92  jal         func_116E48
    ctx->pc = 0x117728u;
    SET_GPR_U32(ctx, 31, 0x117730u);
    ctx->pc = 0x11772Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117728u;
            // 0x11772c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E48u;
    if (runtime->hasFunction(0x116E48u)) {
        auto targetFn = runtime->lookupFunction(0x116E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117730u; }
        if (ctx->pc != 0x117730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E48_0x116e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117730u; }
        if (ctx->pc != 0x117730u) { return; }
    }
    ctx->pc = 0x117730u;
label_117730:
    // 0x117730: 0x24030800  addiu       $v1, $zero, 0x800
    ctx->pc = 0x117730u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x117734: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x117734u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117738: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x117738u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x11773c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x11773cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117740: 0x3e00008  jr          $ra
    ctx->pc = 0x117740u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117740u;
            // 0x117744: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117730u: goto label_117730;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117748u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
