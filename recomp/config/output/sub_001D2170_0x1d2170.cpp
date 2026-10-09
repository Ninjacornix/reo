#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2170
// Address: 0x1d2170 - 0x1d25b0
void sub_001D2170_0x1d2170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2170_0x1d2170");
#endif

    switch (ctx->pc) {
        case 0x1d21a0u: goto label_1d21a0;
        case 0x1d21b8u: goto label_1d21b8;
        case 0x1d21c8u: goto label_1d21c8;
        case 0x1d21ccu: goto label_1d21cc;
        case 0x1d21f8u: goto label_1d21f8;
        case 0x1d2228u: goto label_1d2228;
        case 0x1d223cu: goto label_1d223c;
        case 0x1d2258u: goto label_1d2258;
        case 0x1d2268u: goto label_1d2268;
        case 0x1d2294u: goto label_1d2294;
        case 0x1d229cu: goto label_1d229c;
        case 0x1d22ecu: goto label_1d22ec;
        case 0x1d2300u: goto label_1d2300;
        case 0x1d2310u: goto label_1d2310;
        case 0x1d2314u: goto label_1d2314;
        case 0x1d2340u: goto label_1d2340;
        case 0x1d2348u: goto label_1d2348;
        case 0x1d2394u: goto label_1d2394;
        case 0x1d239cu: goto label_1d239c;
        case 0x1d23e0u: goto label_1d23e0;
        case 0x1d2408u: goto label_1d2408;
        case 0x1d2418u: goto label_1d2418;
        case 0x1d2420u: goto label_1d2420;
        case 0x1d2430u: goto label_1d2430;
        case 0x1d2438u: goto label_1d2438;
        case 0x1d2494u: goto label_1d2494;
        case 0x1d249cu: goto label_1d249c;
        case 0x1d24d8u: goto label_1d24d8;
        case 0x1d2514u: goto label_1d2514;
        case 0x1d2544u: goto label_1d2544;
        case 0x1d2588u: goto label_1d2588;
        default: break;
    }

    ctx->pc = 0x1d2170u;

    // 0x1d2170: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1d2170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1d2174: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d2174u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d2178: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d2178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d217c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d217cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2180: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d2180u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d2184: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1d2184u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1d2188: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d2188u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d218c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d218cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d2190: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d2190u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d2194: 0x24a564f0  addiu       $a1, $a1, 0x64F0
    ctx->pc = 0x1d2194u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25840));
    // 0x1d2198: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D2198u;
    SET_GPR_U32(ctx, 31, 0x1D21A0u);
    ctx->pc = 0x1D219Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2198u;
            // 0x1d219c: 0x2028821  addu        $s1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21A0u; }
        if (ctx->pc != 0x1D21A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21A0u; }
        if (ctx->pc != 0x1D21A0u) { return; }
    }
    ctx->pc = 0x1D21A0u;
label_1d21a0:
    // 0x1d21a0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d21a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d21a4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d21a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d21a8: 0x8c25440c  lw          $a1, 0x440C($at)
    ctx->pc = 0x1d21a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d21ac: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d21acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d21b0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D21B0u;
    SET_GPR_U32(ctx, 31, 0x1D21B8u);
    ctx->pc = 0x1D21B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D21B0u;
            // 0x1d21b4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21B8u; }
        if (ctx->pc != 0x1D21B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21B8u; }
        if (ctx->pc != 0x1D21B8u) { return; }
    }
    ctx->pc = 0x1D21B8u;
label_1d21b8:
    // 0x1d21b8: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x1D21B8u;
    {
        const bool branch_taken_0x1d21b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D21BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D21B8u;
            // 0x1d21bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d21b8) {
            ctx->pc = 0x1D2268u;
            goto label_1d2268;
        }
    }
    ctx->pc = 0x1D21C0u;
    // 0x1d21c0: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1D21C0u;
    SET_GPR_U32(ctx, 31, 0x1D21C8u);
    ctx->pc = 0x1D21C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D21C0u;
            // 0x1d21c4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21C8u; }
        if (ctx->pc != 0x1D21C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21C8u; }
        if (ctx->pc != 0x1D21C8u) { return; }
    }
    ctx->pc = 0x1D21C8u;
label_1d21c8:
    // 0x1d21c8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d21c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d21cc:
    // 0x1d21cc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d21ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d21d0: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1d21d0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d21d4: 0x24426720  addiu       $v0, $v0, 0x6720
    ctx->pc = 0x1d21d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26400));
    // 0x1d21d8: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x1d21d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1d21dc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d21dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d21e0: 0x24426710  addiu       $v0, $v0, 0x6710
    ctx->pc = 0x1d21e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26384));
    // 0x1d21e4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1d21e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1d21e8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1d21e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d21ec: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1d21ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d21f0: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D21F0u;
    SET_GPR_U32(ctx, 31, 0x1D21F8u);
    ctx->pc = 0x1D21F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D21F0u;
            // 0x1d21f4: 0x2222821  addu        $a1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21F8u; }
        if (ctx->pc != 0x1D21F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D21F8u; }
        if (ctx->pc != 0x1D21F8u) { return; }
    }
    ctx->pc = 0x1D21F8u;
label_1d21f8:
    // 0x1d21f8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d21f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d21fc: 0x2a020003  slti        $v0, $s0, 0x3
    ctx->pc = 0x1d21fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d2200: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1D2200u;
    {
        const bool branch_taken_0x1d2200 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d2200) {
            ctx->pc = 0x1D21CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d21cc;
        }
    }
    ctx->pc = 0x1D2208u;
    // 0x1d2208: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2208u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d220c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d220cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d2210: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d2210u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d2214: 0x24846590  addiu       $a0, $a0, 0x6590
    ctx->pc = 0x1d2214u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26000));
    // 0x1d2218: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d2218u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d221c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d221cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2220: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D2220u;
    SET_GPR_U32(ctx, 31, 0x1D2228u);
    ctx->pc = 0x1D2224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2220u;
            // 0x1d2224: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2228u; }
        if (ctx->pc != 0x1D2228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2228u; }
        if (ctx->pc != 0x1D2228u) { return; }
    }
    ctx->pc = 0x1D2228u;
label_1d2228:
    // 0x1d2228: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2228u;
    {
        const bool branch_taken_0x1d2228 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d2228) {
            ctx->pc = 0x1D223Cu;
            goto label_1d223c;
        }
    }
    ctx->pc = 0x1D2230u;
    // 0x1d2230: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1d2230u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d2234: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D2234u;
    SET_GPR_U32(ctx, 31, 0x1D223Cu);
    ctx->pc = 0x1D2238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2234u;
            // 0x1d2238: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D223Cu; }
        if (ctx->pc != 0x1D223Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D223Cu; }
        if (ctx->pc != 0x1D223Cu) { return; }
    }
    ctx->pc = 0x1D223Cu;
label_1d223c:
    // 0x1d223c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d223cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2240: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d2240u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d2244: 0x8c25440c  lw          $a1, 0x440C($at)
    ctx->pc = 0x1d2244u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d2248: 0x248465b0  addiu       $a0, $a0, 0x65B0
    ctx->pc = 0x1d2248u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26032));
    // 0x1d224c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d224cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2250: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D2250u;
    SET_GPR_U32(ctx, 31, 0x1D2258u);
    ctx->pc = 0x1D2254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2250u;
            // 0x1d2254: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2258u; }
        if (ctx->pc != 0x1D2258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2258u; }
        if (ctx->pc != 0x1D2258u) { return; }
    }
    ctx->pc = 0x1D2258u;
label_1d2258:
    // 0x1d2258: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D2258u;
    {
        const bool branch_taken_0x1d2258 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D225Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2258u;
            // 0x1d225c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2258) {
            ctx->pc = 0x1D2268u;
            goto label_1d2268;
        }
    }
    ctx->pc = 0x1D2260u;
    // 0x1d2260: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D2260u;
    SET_GPR_U32(ctx, 31, 0x1D2268u);
    ctx->pc = 0x1D2264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2260u;
            // 0x1d2264: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2268u; }
        if (ctx->pc != 0x1D2268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2268u; }
        if (ctx->pc != 0x1D2268u) { return; }
    }
    ctx->pc = 0x1D2268u;
label_1d2268:
    // 0x1d2268: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d2268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d226c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d226cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2270: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d2270u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2274: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2274u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2274u;
            // 0x1d2278: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D227Cu;
    // 0x1d227c: 0x0  nop
    ctx->pc = 0x1d227cu;
    // NOP
    // 0x1d2280: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2284: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d2284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2288: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d228c: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1D228Cu;
    SET_GPR_U32(ctx, 31, 0x1D2294u);
    ctx->pc = 0x1D2290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D228Cu;
            // 0x1d2290: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2294u; }
        if (ctx->pc != 0x1D2294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2294u; }
        if (ctx->pc != 0x1D2294u) { return; }
    }
    ctx->pc = 0x1D2294u;
label_1d2294:
    // 0x1d2294: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D2294u;
    SET_GPR_U32(ctx, 31, 0x1D229Cu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D229Cu; }
        if (ctx->pc != 0x1D229Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D229Cu; }
        if (ctx->pc != 0x1D229Cu) { return; }
    }
    ctx->pc = 0x1D229Cu;
label_1d229c:
    // 0x1d229c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d229cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d22a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D22A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D22A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D22A0u;
            // 0x1d22a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D22A8u;
    // 0x1d22a8: 0x0  nop
    ctx->pc = 0x1d22a8u;
    // NOP
    // 0x1d22ac: 0x0  nop
    ctx->pc = 0x1d22acu;
    // NOP
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
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2378u;
    // 0x1d2378: 0x0  nop
    ctx->pc = 0x1d2378u;
    // NOP
    // 0x1d237c: 0x0  nop
    ctx->pc = 0x1d237cu;
    // NOP
    // 0x1d2380: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2384: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d2384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2388: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d238c: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1D238Cu;
    SET_GPR_U32(ctx, 31, 0x1D2394u);
    ctx->pc = 0x1D2390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D238Cu;
            // 0x1d2390: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2394u; }
        if (ctx->pc != 0x1D2394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2394u; }
        if (ctx->pc != 0x1D2394u) { return; }
    }
    ctx->pc = 0x1D2394u;
label_1d2394:
    // 0x1d2394: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D2394u;
    SET_GPR_U32(ctx, 31, 0x1D239Cu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D239Cu; }
        if (ctx->pc != 0x1D239Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D239Cu; }
        if (ctx->pc != 0x1D239Cu) { return; }
    }
    ctx->pc = 0x1D239Cu;
label_1d239c:
    // 0x1d239c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d239cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d23a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D23A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D23A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D23A0u;
            // 0x1d23a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D23A8u;
    // 0x1d23a8: 0x0  nop
    ctx->pc = 0x1d23a8u;
    // NOP
    // 0x1d23ac: 0x0  nop
    ctx->pc = 0x1d23acu;
    // NOP
    // 0x1d23b0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d23b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d23b4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d23b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d23b8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d23b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d23bc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d23bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d23c0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d23c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d23c4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d23c4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23c8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d23c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d23cc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d23ccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23d0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1d23d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23d4: 0x24044200  addiu       $a0, $zero, 0x4200
    ctx->pc = 0x1d23d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16896));
    // 0x1d23d8: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D23D8u;
    SET_GPR_U32(ctx, 31, 0x1D23E0u);
    ctx->pc = 0x1D23DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D23D8u;
            // 0x1d23dc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D23E0u; }
        if (ctx->pc != 0x1D23E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D23E0u; }
        if (ctx->pc != 0x1D23E0u) { return; }
    }
    ctx->pc = 0x1D23E0u;
label_1d23e0:
    // 0x1d23e0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d23e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d23e4: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d23e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d23e8: 0x8c34440c  lw          $s4, 0x440C($at)
    ctx->pc = 0x1d23e8u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d23ec: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1d23ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1d23f0: 0x248465d0  addiu       $a0, $a0, 0x65D0
    ctx->pc = 0x1d23f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26064));
    // 0x1d23f4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d23f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d23f8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d23f8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23fc: 0x2828021  addu        $s0, $s4, $v0
    ctx->pc = 0x1d23fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x1d2400: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D2400u;
    SET_GPR_U32(ctx, 31, 0x1D2408u);
    ctx->pc = 0x1D2404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2400u;
            // 0x1d2404: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2408u; }
        if (ctx->pc != 0x1D2408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2408u; }
        if (ctx->pc != 0x1D2408u) { return; }
    }
    ctx->pc = 0x1D2408u;
label_1d2408:
    // 0x1d2408: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D2408u;
    {
        const bool branch_taken_0x1d2408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D240Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2408u;
            // 0x1d240c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2408) {
            ctx->pc = 0x1D2454u;
            goto label_1d2454;
        }
    }
    ctx->pc = 0x1D2410u;
    // 0x1d2410: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1D2410u;
    SET_GPR_U32(ctx, 31, 0x1D2418u);
    ctx->pc = 0x1D2414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2410u;
            // 0x1d2414: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2418u; }
        if (ctx->pc != 0x1D2418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2418u; }
        if (ctx->pc != 0x1D2418u) { return; }
    }
    ctx->pc = 0x1D2418u;
label_1d2418:
    // 0x1d2418: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1D2418u;
    {
        const bool branch_taken_0x1d2418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D241Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2418u;
            // 0x1d241c: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2418) {
            ctx->pc = 0x1D2448u;
            goto label_1d2448;
        }
    }
    ctx->pc = 0x1D2420u;
label_1d2420:
    // 0x1d2420: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x1d2420u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d2424: 0x26844200  addiu       $a0, $s4, 0x4200
    ctx->pc = 0x1d2424u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 16896));
    // 0x1d2428: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D2428u;
    SET_GPR_U32(ctx, 31, 0x1D2430u);
    ctx->pc = 0x1D242Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2428u;
            // 0x1d242c: 0x2022821  addu        $a1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2430u; }
        if (ctx->pc != 0x1D2430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2430u; }
        if (ctx->pc != 0x1D2430u) { return; }
    }
    ctx->pc = 0x1D2430u;
label_1d2430:
    // 0x1d2430: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1D2430u;
    SET_GPR_U32(ctx, 31, 0x1D2438u);
    ctx->pc = 0x1D2434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2430u;
            // 0x1d2434: 0x26844200  addiu       $a0, $s4, 0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 16896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2438u; }
        if (ctx->pc != 0x1D2438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2438u; }
        if (ctx->pc != 0x1D2438u) { return; }
    }
    ctx->pc = 0x1D2438u;
label_1d2438:
    // 0x1d2438: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1d2438u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1d243c: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x1d243cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d2440: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x1d2440u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x1d2444: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1d2444u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_1d2448:
    // 0x1d2448: 0x291182a  slt         $v1, $s4, $s1
    ctx->pc = 0x1d2448u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1d244c: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1D244Cu;
    {
        const bool branch_taken_0x1d244c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d244c) {
            ctx->pc = 0x1D2420u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2420;
        }
    }
    ctx->pc = 0x1D2454u;
label_1d2454:
    // 0x1d2454: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d2454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d2458: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d2458u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d245c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d245cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d2460: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d2460u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2464: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d2464u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2468: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d2468u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d246c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D246Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D246Cu;
            // 0x1d2470: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2474u;
    // 0x1d2474: 0x0  nop
    ctx->pc = 0x1d2474u;
    // NOP
    // 0x1d2478: 0x0  nop
    ctx->pc = 0x1d2478u;
    // NOP
    // 0x1d247c: 0x0  nop
    ctx->pc = 0x1d247cu;
    // NOP
    // 0x1d2480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2484: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d2484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2488: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d248c: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1D248Cu;
    SET_GPR_U32(ctx, 31, 0x1D2494u);
    ctx->pc = 0x1D2490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D248Cu;
            // 0x1d2490: 0x24044200  addiu       $a0, $zero, 0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2494u; }
        if (ctx->pc != 0x1D2494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2494u; }
        if (ctx->pc != 0x1D2494u) { return; }
    }
    ctx->pc = 0x1D2494u;
label_1d2494:
    // 0x1d2494: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D2494u;
    SET_GPR_U32(ctx, 31, 0x1D249Cu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D249Cu; }
        if (ctx->pc != 0x1D249Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D249Cu; }
        if (ctx->pc != 0x1D249Cu) { return; }
    }
    ctx->pc = 0x1D249Cu;
label_1d249c:
    // 0x1d249c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d249cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d24a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D24A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D24A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D24A0u;
            // 0x1d24a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D24A8u;
    // 0x1d24a8: 0x0  nop
    ctx->pc = 0x1d24a8u;
    // NOP
    // 0x1d24ac: 0x0  nop
    ctx->pc = 0x1d24acu;
    // NOP
    // 0x1d24b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d24b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d24b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d24b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d24b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d24b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d24bc: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d24bcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d24c0: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D24C0u;
    {
        const bool branch_taken_0x1d24c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d24c0) {
            ctx->pc = 0x1D24D8u;
            goto label_1d24d8;
        }
    }
    ctx->pc = 0x1D24C8u;
    // 0x1d24c8: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1d24c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1d24cc: 0x24052a00  addiu       $a1, $zero, 0x2A00
    ctx->pc = 0x1d24ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10752));
    // 0x1d24d0: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D24D0u;
    SET_GPR_U32(ctx, 31, 0x1D24D8u);
    ctx->pc = 0x1D24D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D24D0u;
            // 0x1d24d4: 0x22400  sll         $a0, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D24D8u; }
        if (ctx->pc != 0x1D24D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D24D8u; }
        if (ctx->pc != 0x1D24D8u) { return; }
    }
    ctx->pc = 0x1D24D8u;
label_1d24d8:
    // 0x1d24d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d24d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d24dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D24DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D24E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D24DCu;
            // 0x1d24e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D24E4u;
    // 0x1d24e4: 0x0  nop
    ctx->pc = 0x1d24e4u;
    // NOP
    // 0x1d24e8: 0x0  nop
    ctx->pc = 0x1d24e8u;
    // NOP
    // 0x1d24ec: 0x0  nop
    ctx->pc = 0x1d24ecu;
    // NOP
    // 0x1d24f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d24f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d24f4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d24f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d24f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d24f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d24fc: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d24fcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2500: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2500u;
    {
        const bool branch_taken_0x1d2500 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2500u;
            // 0x1d2504: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2500) {
            ctx->pc = 0x1D2514u;
            goto label_1d2514;
        }
    }
    ctx->pc = 0x1D2508u;
    // 0x1d2508: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d2508u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d250c: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D250Cu;
    SET_GPR_U32(ctx, 31, 0x1D2514u);
    ctx->pc = 0x1D2510u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D250Cu;
            // 0x1d2510: 0x24052000  addiu       $a1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2514u; }
        if (ctx->pc != 0x1D2514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2514u; }
        if (ctx->pc != 0x1D2514u) { return; }
    }
    ctx->pc = 0x1D2514u;
label_1d2514:
    // 0x1d2514: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d2514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2518: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D251Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2518u;
            // 0x1d251c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2520u;
    // 0x1d2520: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2524: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2524u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2528: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d252c: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d252cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2530: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2530u;
    {
        const bool branch_taken_0x1d2530 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2530u;
            // 0x1d2534: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2530) {
            ctx->pc = 0x1D2544u;
            goto label_1d2544;
        }
    }
    ctx->pc = 0x1D2538u;
    // 0x1d2538: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d2538u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d253c: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D253Cu;
    SET_GPR_U32(ctx, 31, 0x1D2544u);
    ctx->pc = 0x1D2540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D253Cu;
            // 0x1d2540: 0x24052400  addiu       $a1, $zero, 0x2400 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2544u; }
        if (ctx->pc != 0x1D2544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2544u; }
        if (ctx->pc != 0x1D2544u) { return; }
    }
    ctx->pc = 0x1D2544u;
label_1d2544:
    // 0x1d2544: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d2544u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2548: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D254Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2548u;
            // 0x1d254c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2550u;
    // 0x1d2550: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d2550u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2554: 0x8073784  j           func_1CDE10
    ctx->pc = 0x1D2554u;
    ctx->pc = 0x1D2558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2554u;
            // 0x1d2558: 0x24052500  addiu       $a1, $zero, 0x2500 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CDE10_0x1cde10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D255Cu;
    // 0x1d255c: 0x0  nop
    ctx->pc = 0x1d255cu;
    // NOP
    // 0x1d2560: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2564: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2568: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d256c: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d256cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2570: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D2570u;
    {
        const bool branch_taken_0x1d2570 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d2570) {
            ctx->pc = 0x1D2588u;
            goto label_1d2588;
        }
    }
    ctx->pc = 0x1D2578u;
    // 0x1d2578: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1d2578u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1d257c: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x1d257cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1d2580: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D2580u;
    SET_GPR_U32(ctx, 31, 0x1D2588u);
    ctx->pc = 0x1D2584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2580u;
            // 0x1d2584: 0x24453000  addiu       $a1, $v0, 0x3000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 12288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2588u; }
        if (ctx->pc != 0x1D2588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2588u; }
        if (ctx->pc != 0x1D2588u) { return; }
    }
    ctx->pc = 0x1D2588u;
label_1d2588:
    // 0x1d2588: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d2588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d258c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D258Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D258Cu;
            // 0x1d2590: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D21A0u: goto label_1d21a0;
            case 0x1D21B8u: goto label_1d21b8;
            case 0x1D21C8u: goto label_1d21c8;
            case 0x1D21CCu: goto label_1d21cc;
            case 0x1D21F8u: goto label_1d21f8;
            case 0x1D2228u: goto label_1d2228;
            case 0x1D223Cu: goto label_1d223c;
            case 0x1D2258u: goto label_1d2258;
            case 0x1D2268u: goto label_1d2268;
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            case 0x1D22ECu: goto label_1d22ec;
            case 0x1D2300u: goto label_1d2300;
            case 0x1D2310u: goto label_1d2310;
            case 0x1D2314u: goto label_1d2314;
            case 0x1D2340u: goto label_1d2340;
            case 0x1D2348u: goto label_1d2348;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2594u;
    // 0x1d2594: 0x0  nop
    ctx->pc = 0x1d2594u;
    // NOP
    // 0x1d2598: 0x0  nop
    ctx->pc = 0x1d2598u;
    // NOP
    // 0x1d259c: 0x0  nop
    ctx->pc = 0x1d259cu;
    // NOP
    // 0x1d25a0: 0x80738fc  j           func_1CE3F0
    ctx->pc = 0x1D25A0u;
    ctx->pc = 0x1CE3F0u;
    if (runtime->hasFunction(0x1CE3F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CE3F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CE3F0_0x1ce3f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D25A8u;
    // 0x1d25a8: 0x0  nop
    ctx->pc = 0x1d25a8u;
    // NOP
    // 0x1d25ac: 0x0  nop
    ctx->pc = 0x1d25acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
