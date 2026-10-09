#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2150
// Address: 0x1b2150 - 0x1b2278
void sub_001B2150_0x1b2150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2150_0x1b2150");
#endif

    switch (ctx->pc) {
        case 0x1b2168u: goto label_1b2168;
        case 0x1b2174u: goto label_1b2174;
        case 0x1b2180u: goto label_1b2180;
        case 0x1b2188u: goto label_1b2188;
        case 0x1b219cu: goto label_1b219c;
        case 0x1b21b4u: goto label_1b21b4;
        case 0x1b21c8u: goto label_1b21c8;
        case 0x1b21e0u: goto label_1b21e0;
        case 0x1b21f4u: goto label_1b21f4;
        case 0x1b220cu: goto label_1b220c;
        case 0x1b222cu: goto label_1b222c;
        case 0x1b224cu: goto label_1b224c;
        default: break;
    }

    ctx->pc = 0x1b2150u;

    // 0x1b2150: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b2150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b2154: 0x3c04004f  lui         $a0, 0x4F
    ctx->pc = 0x1b2154u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)79 << 16));
    // 0x1b2158: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b2158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b215c: 0x2484a8c0  addiu       $a0, $a0, -0x5740
    ctx->pc = 0x1b215cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944960));
    // 0x1b2160: 0xc06c84c  jal         func_1B2130
    ctx->pc = 0x1B2160u;
    SET_GPR_U32(ctx, 31, 0x1B2168u);
    ctx->pc = 0x1B2164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2160u;
            // 0x1b2164: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2130u;
    if (runtime->hasFunction(0x1B2130u)) {
        auto targetFn = runtime->lookupFunction(0x1B2130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2168u; }
        if (ctx->pc != 0x1B2168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2130_0x1b2130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2168u; }
        if (ctx->pc != 0x1B2168u) { return; }
    }
    ctx->pc = 0x1B2168u;
label_1b2168:
    // 0x1b2168: 0x3c04004f  lui         $a0, 0x4F
    ctx->pc = 0x1b2168u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)79 << 16));
    // 0x1b216c: 0xc06c84c  jal         func_1B2130
    ctx->pc = 0x1B216Cu;
    SET_GPR_U32(ctx, 31, 0x1B2174u);
    ctx->pc = 0x1B2170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B216Cu;
            // 0x1b2170: 0x24848970  addiu       $a0, $a0, -0x7690 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2130u;
    if (runtime->hasFunction(0x1B2130u)) {
        auto targetFn = runtime->lookupFunction(0x1B2130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2174u; }
        if (ctx->pc != 0x1B2174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2130_0x1b2130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2174u; }
        if (ctx->pc != 0x1B2174u) { return; }
    }
    ctx->pc = 0x1B2174u;
label_1b2174:
    // 0x1b2174: 0x3c04004e  lui         $a0, 0x4E
    ctx->pc = 0x1b2174u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)78 << 16));
    // 0x1b2178: 0xc06c84c  jal         func_1B2130
    ctx->pc = 0x1B2178u;
    SET_GPR_U32(ctx, 31, 0x1B2180u);
    ctx->pc = 0x1B217Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2178u;
            // 0x1b217c: 0x24846a20  addiu       $a0, $a0, 0x6A20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2130u;
    if (runtime->hasFunction(0x1B2130u)) {
        auto targetFn = runtime->lookupFunction(0x1B2130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2180u; }
        if (ctx->pc != 0x1B2180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2130_0x1b2130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2180u; }
        if (ctx->pc != 0x1B2180u) { return; }
    }
    ctx->pc = 0x1B2180u;
label_1b2180:
    // 0x1b2180: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b2180u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2184: 0x24031f44  addiu       $v1, $zero, 0x1F44
    ctx->pc = 0x1b2184u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
label_1b2188:
    // 0x1b2188: 0x3c02004d  lui         $v0, 0x4D
    ctx->pc = 0x1b2188u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)77 << 16));
    // 0x1b218c: 0x2031818  mult        $v1, $s0, $v1
    ctx->pc = 0x1b218cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b2190: 0x24427000  addiu       $v0, $v0, 0x7000
    ctx->pc = 0x1b2190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28672));
    // 0x1b2194: 0xc06c84c  jal         func_1B2130
    ctx->pc = 0x1B2194u;
    SET_GPR_U32(ctx, 31, 0x1B219Cu);
    ctx->pc = 0x1B2198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2194u;
            // 0x1b2198: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2130u;
    if (runtime->hasFunction(0x1B2130u)) {
        auto targetFn = runtime->lookupFunction(0x1B2130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B219Cu; }
        if (ctx->pc != 0x1B219Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2130_0x1b2130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B219Cu; }
        if (ctx->pc != 0x1B219Cu) { return; }
    }
    ctx->pc = 0x1B219Cu;
label_1b219c:
    // 0x1b219c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b219cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b21a0: 0x2a020008  slti        $v0, $s0, 0x8
    ctx->pc = 0x1b21a0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b21a4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B21A4u;
    {
        const bool branch_taken_0x1b21a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B21A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B21A4u;
            // 0x1b21a8: 0x24031f44  addiu       $v1, $zero, 0x1F44 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b21a4) {
            ctx->pc = 0x1B2188u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2188;
        }
    }
    ctx->pc = 0x1B21ACu;
    // 0x1b21ac: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b21acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b21b0: 0x24031f44  addiu       $v1, $zero, 0x1F44
    ctx->pc = 0x1b21b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
label_1b21b4:
    // 0x1b21b4: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b21b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b21b8: 0x2031818  mult        $v1, $s0, $v1
    ctx->pc = 0x1b21b8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b21bc: 0x24423750  addiu       $v0, $v0, 0x3750
    ctx->pc = 0x1b21bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14160));
    // 0x1b21c0: 0xc06c84c  jal         func_1B2130
    ctx->pc = 0x1B21C0u;
    SET_GPR_U32(ctx, 31, 0x1B21C8u);
    ctx->pc = 0x1B21C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B21C0u;
            // 0x1b21c4: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2130u;
    if (runtime->hasFunction(0x1B2130u)) {
        auto targetFn = runtime->lookupFunction(0x1B2130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B21C8u; }
        if (ctx->pc != 0x1B21C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2130_0x1b2130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B21C8u; }
        if (ctx->pc != 0x1B21C8u) { return; }
    }
    ctx->pc = 0x1B21C8u;
label_1b21c8:
    // 0x1b21c8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b21c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b21cc: 0x2a02000a  slti        $v0, $s0, 0xA
    ctx->pc = 0x1b21ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1b21d0: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B21D0u;
    {
        const bool branch_taken_0x1b21d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B21D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B21D0u;
            // 0x1b21d4: 0x24031f44  addiu       $v1, $zero, 0x1F44 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b21d0) {
            ctx->pc = 0x1B21B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b21b4;
        }
    }
    ctx->pc = 0x1B21D8u;
    // 0x1b21d8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b21d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b21dc: 0x24030c84  addiu       $v1, $zero, 0xC84
    ctx->pc = 0x1b21dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3204));
label_1b21e0:
    // 0x1b21e0: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b21e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b21e4: 0x2031818  mult        $v1, $s0, $v1
    ctx->pc = 0x1b21e4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b21e8: 0x2442ec30  addiu       $v0, $v0, -0x13D0
    ctx->pc = 0x1b21e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962224));
    // 0x1b21ec: 0xc06c848  jal         func_1B2120
    ctx->pc = 0x1B21ECu;
    SET_GPR_U32(ctx, 31, 0x1B21F4u);
    ctx->pc = 0x1B21F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B21ECu;
            // 0x1b21f0: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2120u;
    if (runtime->hasFunction(0x1B2120u)) {
        auto targetFn = runtime->lookupFunction(0x1B2120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B21F4u; }
        if (ctx->pc != 0x1B21F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2120_0x1b2120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B21F4u; }
        if (ctx->pc != 0x1B21F4u) { return; }
    }
    ctx->pc = 0x1B21F4u;
label_1b21f4:
    // 0x1b21f4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b21f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b21f8: 0x2a020006  slti        $v0, $s0, 0x6
    ctx->pc = 0x1b21f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1b21fc: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B21FCu;
    {
        const bool branch_taken_0x1b21fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B21FCu;
            // 0x1b2200: 0x24030c84  addiu       $v1, $zero, 0xC84 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3204));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b21fc) {
            ctx->pc = 0x1B21E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b21e0;
        }
    }
    ctx->pc = 0x1B2204u;
    // 0x1b2204: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b2204u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2208: 0x101980  sll         $v1, $s0, 6
    ctx->pc = 0x1b2208u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 6));
label_1b220c:
    // 0x1b220c: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b220cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b2210: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1b2210u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b2214: 0x2442d4a0  addiu       $v0, $v0, -0x2B60
    ctx->pc = 0x1b2214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956192));
    // 0x1b2218: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b2218u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b221c: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1b221cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b2220: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b2220u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b2224: 0xc06c850  jal         func_1B2140
    ctx->pc = 0x1B2224u;
    SET_GPR_U32(ctx, 31, 0x1B222Cu);
    ctx->pc = 0x1B2228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2224u;
            // 0x1b2228: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2140u;
    if (runtime->hasFunction(0x1B2140u)) {
        auto targetFn = runtime->lookupFunction(0x1B2140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B222Cu; }
        if (ctx->pc != 0x1B222Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2140_0x1b2140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B222Cu; }
        if (ctx->pc != 0x1B222Cu) { return; }
    }
    ctx->pc = 0x1B222Cu;
label_1b222c:
    // 0x1b222c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b222cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b2230: 0x2a030006  slti        $v1, $s0, 0x6
    ctx->pc = 0x1b2230u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1b2234: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x1B2234u;
    {
        const bool branch_taken_0x1b2234 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2234u;
            // 0x1b2238: 0x101980  sll         $v1, $s0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2234) {
            ctx->pc = 0x1B220Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b220c;
        }
    }
    ctx->pc = 0x1B223Cu;
    // 0x1b223c: 0x2406003d  addiu       $a2, $zero, 0x3D
    ctx->pc = 0x1b223cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
    // 0x1b2240: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2240u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2244: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1b2244u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b2248: 0x2484aeb0  addiu       $a0, $a0, -0x5150
    ctx->pc = 0x1b2248u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946480));
label_1b224c:
    // 0x1b224c: 0x861821  addu        $v1, $a0, $a2
    ctx->pc = 0x1b224cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1b2250: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1b2250u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1b2254: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1b2254u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b2258: 0x0  nop
    ctx->pc = 0x1b2258u;
    // NOP
    // 0x1b225c: 0x0  nop
    ctx->pc = 0x1b225cu;
    // NOP
    // 0x1b2260: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B2260u;
    {
        const bool branch_taken_0x1b2260 = (GPR_S64(ctx, 6) >= 0);
        if (branch_taken_0x1b2260) {
            ctx->pc = 0x1B224Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b224c;
        }
    }
    ctx->pc = 0x1B2268u;
    // 0x1b2268: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b2268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b226c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b226cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2270: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2270u;
            // 0x1b2274: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2168u: goto label_1b2168;
            case 0x1B2174u: goto label_1b2174;
            case 0x1B2180u: goto label_1b2180;
            case 0x1B2188u: goto label_1b2188;
            case 0x1B219Cu: goto label_1b219c;
            case 0x1B21B4u: goto label_1b21b4;
            case 0x1B21C8u: goto label_1b21c8;
            case 0x1B21E0u: goto label_1b21e0;
            case 0x1B21F4u: goto label_1b21f4;
            case 0x1B220Cu: goto label_1b220c;
            case 0x1B222Cu: goto label_1b222c;
            case 0x1B224Cu: goto label_1b224c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2278u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
