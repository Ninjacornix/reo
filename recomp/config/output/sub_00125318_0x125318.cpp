#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125318
// Address: 0x125318 - 0x125370
void sub_00125318_0x125318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125318_0x125318");
#endif

    switch (ctx->pc) {
        case 0x12535cu: goto label_12535c;
        default: break;
    }

    ctx->pc = 0x125318u;

    // 0x125318: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x125318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12531c: 0x24830048  addiu       $v1, $a0, 0x48
    ctx->pc = 0x12531cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 72));
    // 0x125320: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x125320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x125324: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x125324u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x125328: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x125328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12532c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x12532cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125330: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x125330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x125334: 0x8c670014  lw          $a3, 0x14($v1)
    ctx->pc = 0x125334u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x125338: 0x8c68001c  lw          $t0, 0x1C($v1)
    ctx->pc = 0x125338u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12533c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x12533cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x125340: 0x8c900008  lw          $s0, 0x8($a0)
    ctx->pc = 0x125340u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x125344: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x125344u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x125348: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x125348u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12534c: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x12534cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x125350: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x125350u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125354: 0xc04d3f4  jal         func_134FD0
    ctx->pc = 0x125354u;
    SET_GPR_U32(ctx, 31, 0x12535Cu);
    ctx->pc = 0x125358u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125354u;
            // 0x125358: 0xe84021  addu        $t0, $a3, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134FD0u;
    if (runtime->hasFunction(0x134FD0u)) {
        auto targetFn = runtime->lookupFunction(0x134FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12535Cu; }
        if (ctx->pc != 0x12535Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134FD0_0x134fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12535Cu; }
        if (ctx->pc != 0x12535Cu) { return; }
    }
    ctx->pc = 0x12535Cu;
label_12535c:
    // 0x12535c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12535cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125360: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x125360u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125364: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125364u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125368: 0x804d400  j           func_135000
    ctx->pc = 0x125368u;
    ctx->pc = 0x12536Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125368u;
            // 0x12536c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135000u;
    if (runtime->hasFunction(0x135000u)) {
        auto targetFn = runtime->lookupFunction(0x135000u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135000_0x135000(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125370u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
