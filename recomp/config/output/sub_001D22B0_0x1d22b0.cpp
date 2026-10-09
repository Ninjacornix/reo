#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D22B0
// Address: 0x1d22b0 - 0x1d2378
void sub_001D22B0_0x1d22b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D22B0_0x1d22b0");
#endif

    switch (ctx->pc) {
        case 0x1d22ecu: goto label_1d22ec;
        case 0x1d2300u: goto label_1d2300;
        case 0x1d2310u: goto label_1d2310;
        case 0x1d2314u: goto label_1d2314;
        case 0x1d2340u: goto label_1d2340;
        case 0x1d2348u: goto label_1d2348;
        default: break;
    }

    ctx->pc = 0x1d22b0u;

    // 0x1d22b0: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x1d22b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x1d22b4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d22b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d22b8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d22b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d22bc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d22bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d22c0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d22c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d22c4: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1d22c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1d22c8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d22c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d22cc: 0x24a564f0  addiu       $a1, $a1, 0x64F0
    ctx->pc = 0x1d22ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25840));
    // 0x1d22d0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d22d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d22d4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d22d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d22d8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d22d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d22dc: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d22dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d22e0: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d22e0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d22e4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D22E4u;
    SET_GPR_U32(ctx, 31, 0x1D22ECu);
    ctx->pc = 0x1D22E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D22E4u;
            // 0x1d22e8: 0x2028821  addu        $s1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D22ECu; }
        if (ctx->pc != 0x1D22ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D22ECu; }
        if (ctx->pc != 0x1D22ECu) { return; }
    }
    ctx->pc = 0x1D22ECu;
label_1d22ec:
    // 0x1d22ec: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d22ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d22f0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d22f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d22f4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d22f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d22f8: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D22F8u;
    SET_GPR_U32(ctx, 31, 0x1D2300u);
    ctx->pc = 0x1D22FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D22F8u;
            // 0x1d22fc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2300u; }
        if (ctx->pc != 0x1D2300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2300u; }
        if (ctx->pc != 0x1D2300u) { return; }
    }
    ctx->pc = 0x1D2300u;
label_1d2300:
    // 0x1d2300: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1D2300u;
    {
        const bool branch_taken_0x1d2300 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2300u;
            // 0x1d2304: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2300) {
            ctx->pc = 0x1D235Cu;
            goto label_1d235c;
        }
    }
    ctx->pc = 0x1D2308u;
    // 0x1d2308: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1D2308u;
    SET_GPR_U32(ctx, 31, 0x1D2310u);
    ctx->pc = 0x1D230Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2308u;
            // 0x1d230c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2310u; }
        if (ctx->pc != 0x1D2310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2310u; }
        if (ctx->pc != 0x1D2310u) { return; }
    }
    ctx->pc = 0x1D2310u;
label_1d2310:
    // 0x1d2310: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d2310u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d2314:
    // 0x1d2314: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2314u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2318: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1d2318u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d231c: 0x24426750  addiu       $v0, $v0, 0x6750
    ctx->pc = 0x1d231cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26448));
    // 0x1d2320: 0x439821  addu        $s3, $v0, $v1
    ctx->pc = 0x1d2320u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2324: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d2324u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d2328: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x1d2328u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d232c: 0x24426730  addiu       $v0, $v0, 0x6730
    ctx->pc = 0x1d232cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26416));
    // 0x1d2330: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d2330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2334: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1d2334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2338: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D2338u;
    SET_GPR_U32(ctx, 31, 0x1D2340u);
    ctx->pc = 0x1D233Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2338u;
            // 0x1d233c: 0x2222821  addu        $a1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2340u; }
        if (ctx->pc != 0x1D2340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2340u; }
        if (ctx->pc != 0x1D2340u) { return; }
    }
    ctx->pc = 0x1D2340u;
label_1d2340:
    // 0x1d2340: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1D2340u;
    SET_GPR_U32(ctx, 31, 0x1D2348u);
    ctx->pc = 0x1D2344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2340u;
            // 0x1d2344: 0x8e640000  lw          $a0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2348u; }
        if (ctx->pc != 0x1D2348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2348u; }
        if (ctx->pc != 0x1D2348u) { return; }
    }
    ctx->pc = 0x1D2348u;
label_1d2348:
    // 0x1d2348: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d2348u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d234c: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1d234cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1d2350: 0x2a030006  slti        $v1, $s0, 0x6
    ctx->pc = 0x1d2350u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1d2354: 0x1460ffef  bnez        $v1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1D2354u;
    {
        const bool branch_taken_0x1d2354 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2354u;
            // 0x1d2358: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2354) {
            ctx->pc = 0x1D2314u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2314;
        }
    }
    ctx->pc = 0x1D235Cu;
label_1d235c:
    // 0x1d235c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d235cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d2360: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d2360u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d2364: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d2364u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2368: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d2368u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d236c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d236cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2370: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2370u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2370u;
            // 0x1d2374: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2378u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
