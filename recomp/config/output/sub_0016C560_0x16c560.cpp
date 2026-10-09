#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C560
// Address: 0x16c560 - 0x16c5a8
void sub_0016C560_0x16c560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C560_0x16c560");
#endif

    switch (ctx->pc) {
        case 0x16c58cu: goto label_16c58c;
        default: break;
    }

    ctx->pc = 0x16c560u;

    // 0x16c560: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16c560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c564: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x16c564u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c568: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16c568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16c56c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16c56cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c570: 0x8cb009fc  lw          $s0, 0x9FC($a1)
    ctx->pc = 0x16c570u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 2556)));
    // 0x16c574: 0x8ca2002c  lw          $v0, 0x2C($a1)
    ctx->pc = 0x16c574u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x16c578: 0x101827  nor         $v1, $zero, $s0
    ctx->pc = 0x16c578u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 16)));
    // 0x16c57c: 0x43800a  movz        $s0, $v0, $v1
    ctx->pc = 0x16c57cu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
    // 0x16c580: 0x50282a  slt         $a1, $v0, $s0
    ctx->pc = 0x16c580u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16c584: 0xc05c164  jal         func_170590
    ctx->pc = 0x16C584u;
    SET_GPR_U32(ctx, 31, 0x16C58Cu);
    ctx->pc = 0x16C588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C584u;
            // 0x16c588: 0x45800b  movn        $s0, $v0, $a1 (Delay Slot)
        if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170590u;
    if (runtime->hasFunction(0x170590u)) {
        auto targetFn = runtime->lookupFunction(0x170590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C58Cu; }
        if (ctx->pc != 0x16C58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170590_0x170590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C58Cu; }
        if (ctx->pc != 0x16C58Cu) { return; }
    }
    ctx->pc = 0x16C58Cu;
label_16c58c:
    // 0x16c58c: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x16c58cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16c590: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c590u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c594: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16c594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c598: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x16c598u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x16c59c: 0x3e00008  jr          $ra
    ctx->pc = 0x16C59Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C5A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C59Cu;
            // 0x16c5a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C58Cu: goto label_16c58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C5A4u;
    // 0x16c5a4: 0x0  nop
    ctx->pc = 0x16c5a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
