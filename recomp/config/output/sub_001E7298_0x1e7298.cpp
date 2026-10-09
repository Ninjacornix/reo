#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7298
// Address: 0x1e7298 - 0x1e7318
void sub_001E7298_0x1e7298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7298_0x1e7298");
#endif

    switch (ctx->pc) {
        case 0x1e72b8u: goto label_1e72b8;
        case 0x1e72fcu: goto label_1e72fc;
        default: break;
    }

    ctx->pc = 0x1e7298u;

    // 0x1e7298: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e7298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e729c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e729cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e72a0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e72a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e72a4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e72a4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e72a8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e72a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e72ac: 0x2404001c  addiu       $a0, $zero, 0x1C
    ctx->pc = 0x1e72acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x1e72b0: 0xc079f1f  jal         func_1E7C7C
    ctx->pc = 0x1E72B0u;
    SET_GPR_U32(ctx, 31, 0x1E72B8u);
    ctx->pc = 0x1E7C7Cu;
    if (runtime->hasFunction(0x1E7C7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E7C7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E72B8u; }
        if (ctx->pc != 0x1E72B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C7C_0x1e7c7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E72B8u; }
        if (ctx->pc != 0x1E72B8u) { return; }
    }
    ctx->pc = 0x1E72B8u;
label_1e72b8:
    // 0x1e72b8: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e72b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e72bc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e72bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e72c0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E72C0u;
    {
        const bool branch_taken_0x1e72c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e72c0) {
            ctx->pc = 0x1E72D4u;
            goto label_1e72d4;
        }
    }
    ctx->pc = 0x1E72C8u;
    // 0x1e72c8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e72c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e72cc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1E72CCu;
    {
        const bool branch_taken_0x1e72cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e72cc) {
            ctx->pc = 0x1E7300u;
            goto label_1e7300;
        }
    }
    ctx->pc = 0x1E72D4u;
label_1e72d4:
    // 0x1e72d4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e72d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e72d8: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x1e72d8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x1e72dc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e72dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e72e0: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e72e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e72e4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e72e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e72e8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e72e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e72ec: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e72ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e72f0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e72f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e72f4: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1E72F4u;
    SET_GPR_U32(ctx, 31, 0x1E72FCu);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E72FCu; }
        if (ctx->pc != 0x1E72FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E72FCu; }
        if (ctx->pc != 0x1E72FCu) { return; }
    }
    ctx->pc = 0x1E72FCu;
label_1e72fc:
    // 0x1e72fc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e72fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
label_1e7300:
    // 0x1e7300: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7300u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7304: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e7304u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e7308: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e7308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e730c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e730cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e7310: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E72B8u: goto label_1e72b8;
            case 0x1E72D4u: goto label_1e72d4;
            case 0x1E72FCu: goto label_1e72fc;
            case 0x1E7300u: goto label_1e7300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7318u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
