#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131258
// Address: 0x131258 - 0x1312bc
void sub_00131258_0x131258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131258_0x131258");
#endif

    switch (ctx->pc) {
        case 0x131280u: goto label_131280;
        case 0x1312a8u: goto label_1312a8;
        default: break;
    }

    ctx->pc = 0x131258u;

    // 0x131258: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131258u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13125c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13125cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131260: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131260u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131264: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x131264u;
    {
        const bool branch_taken_0x131264 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x131268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131264u;
            // 0x131268: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131264) {
            ctx->pc = 0x131298u;
            goto label_131298;
        }
    }
    ctx->pc = 0x13126Cu;
    // 0x13126c: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x13126cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131270: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x131270u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x131274: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x131274u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x131278: 0xc04eb7c  jal         func_13ADF0
    ctx->pc = 0x131278u;
    SET_GPR_U32(ctx, 31, 0x131280u);
    ctx->pc = 0x13127Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131278u;
            // 0x13127c: 0x8e070004  lw          $a3, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ADF0u;
    if (runtime->hasFunction(0x13ADF0u)) {
        auto targetFn = runtime->lookupFunction(0x13ADF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131280u; }
        if (ctx->pc != 0x131280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013ADF0_0x13adf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131280u; }
        if (ctx->pc != 0x131280u) { return; }
    }
    ctx->pc = 0x131280u;
label_131280:
    // 0x131280: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x131280u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x131284: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x131284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131288: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13128c: 0x804eb84  j           func_13AE10
    ctx->pc = 0x13128Cu;
    ctx->pc = 0x131290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13128Cu;
            // 0x131290: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AE10u;
    if (runtime->hasFunction(0x13AE10u)) {
        auto targetFn = runtime->lookupFunction(0x13AE10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AE10_0x13ae10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131294u;
    // 0x131294: 0x0  nop
    ctx->pc = 0x131294u;
    // NOP
label_131298:
    // 0x131298: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131298u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13129c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13129cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1312a0: 0xc04eb7c  jal         func_13ADF0
    ctx->pc = 0x1312A0u;
    SET_GPR_U32(ctx, 31, 0x1312A8u);
    ctx->pc = 0x1312A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312A0u;
            // 0x1312a4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ADF0u;
    if (runtime->hasFunction(0x13ADF0u)) {
        auto targetFn = runtime->lookupFunction(0x13ADF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1312A8u; }
        if (ctx->pc != 0x1312A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013ADF0_0x13adf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1312A8u; }
        if (ctx->pc != 0x1312A8u) { return; }
    }
    ctx->pc = 0x1312A8u;
label_1312a8:
    // 0x1312a8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1312a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1312ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1312acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312b0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1312b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1312b4: 0x804eb84  j           func_13AE10
    ctx->pc = 0x1312B4u;
    ctx->pc = 0x1312B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312B4u;
            // 0x1312b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AE10u;
    if (runtime->hasFunction(0x13AE10u)) {
        auto targetFn = runtime->lookupFunction(0x13AE10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AE10_0x13ae10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1312BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
