#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C2120
// Address: 0x1c2120 - 0x1c2260
void sub_001C2120_0x1c2120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C2120_0x1c2120");
#endif

    switch (ctx->pc) {
        case 0x1c2158u: goto label_1c2158;
        case 0x1c2164u: goto label_1c2164;
        case 0x1c216cu: goto label_1c216c;
        case 0x1c2174u: goto label_1c2174;
        case 0x1c2188u: goto label_1c2188;
        case 0x1c2198u: goto label_1c2198;
        case 0x1c21acu: goto label_1c21ac;
        case 0x1c21b4u: goto label_1c21b4;
        case 0x1c21c0u: goto label_1c21c0;
        case 0x1c21ecu: goto label_1c21ec;
        case 0x1c2220u: goto label_1c2220;
        default: break;
    }

    ctx->pc = 0x1c2120u;

    // 0x1c2120: 0x27bdff10  addiu       $sp, $sp, -0xF0
    ctx->pc = 0x1c2120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x1c2124: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1c2124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1c2128: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c2128u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c212c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c212cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c2130: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1c2130u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2134: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c2134u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c2138: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1c2138u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c213c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c213cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c2140: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1c2140u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2144: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c2144u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c2148: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c2148u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c214c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1c214cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2150: 0xc06d584  jal         func_1B5610
    ctx->pc = 0x1C2150u;
    SET_GPR_U32(ctx, 31, 0x1C2158u);
    ctx->pc = 0x1C2154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2150u;
            // 0x1c2154: 0x2404fffe  addiu       $a0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5610u;
    if (runtime->hasFunction(0x1B5610u)) {
        auto targetFn = runtime->lookupFunction(0x1B5610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2158u; }
        if (ctx->pc != 0x1C2158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5610_0x1b5610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2158u; }
        if (ctx->pc != 0x1C2158u) { return; }
    }
    ctx->pc = 0x1C2158u;
label_1c2158:
    // 0x1c2158: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c2158u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c215c: 0xc06d57c  jal         func_1B55F0
    ctx->pc = 0x1C215Cu;
    SET_GPR_U32(ctx, 31, 0x1C2164u);
    ctx->pc = 0x1C2160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C215Cu;
            // 0x1c2160: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55F0u;
    if (runtime->hasFunction(0x1B55F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2164u; }
        if (ctx->pc != 0x1C2164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55F0_0x1b55f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2164u; }
        if (ctx->pc != 0x1C2164u) { return; }
    }
    ctx->pc = 0x1C2164u;
label_1c2164:
    // 0x1c2164: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1C2164u;
    {
        const bool branch_taken_0x1c2164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2164u;
            // 0x1c2168: 0x82820000  lb          $v0, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2164) {
            ctx->pc = 0x1C2228u;
            goto label_1c2228;
        }
    }
    ctx->pc = 0x1C216Cu;
label_1c216c:
    // 0x1c216c: 0xc070898  jal         func_1C2260
    ctx->pc = 0x1C216Cu;
    SET_GPR_U32(ctx, 31, 0x1C2174u);
    ctx->pc = 0x1C2170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C216Cu;
            // 0x1c2170: 0x27a50060  addiu       $a1, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2260u;
    if (runtime->hasFunction(0x1C2260u)) {
        auto targetFn = runtime->lookupFunction(0x1C2260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2174u; }
        if (ctx->pc != 0x1C2174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2260_0x1c2260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2174u; }
        if (ctx->pc != 0x1C2174u) { return; }
    }
    ctx->pc = 0x1C2174u;
label_1c2174:
    // 0x1c2174: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1C2174u;
    {
        const bool branch_taken_0x1c2174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2174u;
            // 0x1c2178: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2174) {
            ctx->pc = 0x1C2218u;
            goto label_1c2218;
        }
    }
    ctx->pc = 0x1C217Cu;
    // 0x1c217c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1c217cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2180: 0xc0708b0  jal         func_1C22C0
    ctx->pc = 0x1C2180u;
    SET_GPR_U32(ctx, 31, 0x1C2188u);
    ctx->pc = 0x1C2184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2180u;
            // 0x1c2184: 0x27a50060  addiu       $a1, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C22C0u;
    if (runtime->hasFunction(0x1C22C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C22C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2188u; }
        if (ctx->pc != 0x1C2188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C22C0_0x1c22c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2188u; }
        if (ctx->pc != 0x1C2188u) { return; }
    }
    ctx->pc = 0x1C2188u;
label_1c2188:
    // 0x1c2188: 0x16600005  bnez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C2188u;
    {
        const bool branch_taken_0x1c2188 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C218Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2188u;
            // 0x1c218c: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2188) {
            ctx->pc = 0x1C21A0u;
            goto label_1c21a0;
        }
    }
    ctx->pc = 0x1C2190u;
    // 0x1c2190: 0xc06de28  jal         func_1B78A0
    ctx->pc = 0x1C2190u;
    SET_GPR_U32(ctx, 31, 0x1C2198u);
    ctx->pc = 0x1C2194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2190u;
            // 0x1c2194: 0x27a40060  addiu       $a0, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B78A0u;
    if (runtime->hasFunction(0x1B78A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B78A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2198u; }
        if (ctx->pc != 0x1C2198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B78A0_0x1b78a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2198u; }
        if (ctx->pc != 0x1C2198u) { return; }
    }
    ctx->pc = 0x1C2198u;
label_1c2198:
    // 0x1c2198: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1C2198u;
    {
        const bool branch_taken_0x1c2198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2198) {
            ctx->pc = 0x1C2224u;
            goto label_1c2224;
        }
    }
    ctx->pc = 0x1C21A0u;
label_1c21a0:
    // 0x1c21a0: 0x27b00060  addiu       $s0, $sp, 0x60
    ctx->pc = 0x1c21a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1c21a4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1C21A4u;
    {
        const bool branch_taken_0x1c21a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C21A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C21A4u;
            // 0x1c21a8: 0x27b100ec  addiu       $s1, $sp, 0xEC (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 236));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c21a4) {
            ctx->pc = 0x1C2204u;
            goto label_1c2204;
        }
    }
    ctx->pc = 0x1C21ACu;
label_1c21ac:
    // 0x1c21ac: 0xc06db50  jal         func_1B6D40
    ctx->pc = 0x1C21ACu;
    SET_GPR_U32(ctx, 31, 0x1C21B4u);
    ctx->pc = 0x1C21B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C21ACu;
            // 0x1c21b0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6D40u;
    if (runtime->hasFunction(0x1B6D40u)) {
        auto targetFn = runtime->lookupFunction(0x1B6D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C21B4u; }
        if (ctx->pc != 0x1C21B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6D40_0x1b6d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C21B4u; }
        if (ctx->pc != 0x1C21B4u) { return; }
    }
    ctx->pc = 0x1C21B4u;
label_1c21b4:
    // 0x1c21b4: 0x30430003  andi        $v1, $v0, 0x3
    ctx->pc = 0x1c21b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1c21b8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C21B8u;
    {
        const bool branch_taken_0x1c21b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C21BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C21B8u;
            // 0x1c21bc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c21b8) {
            ctx->pc = 0x1C21D4u;
            goto label_1c21d4;
        }
    }
    ctx->pc = 0x1C21C0u;
label_1c21c0:
    // 0x1c21c0: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1c21c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c21c4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1c21c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1c21c8: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1c21c8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c21cc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1c21ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1c21d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c21d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1c21d4:
    // 0x1c21d4: 0x83102a  slt         $v0, $a0, $v1
    ctx->pc = 0x1c21d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c21d8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1C21D8u;
    {
        const bool branch_taken_0x1c21d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c21d8) {
            ctx->pc = 0x1C21C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c21c0;
        }
    }
    ctx->pc = 0x1C21E0u;
    // 0x1c21e0: 0x27a400ec  addiu       $a0, $sp, 0xEC
    ctx->pc = 0x1c21e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 236));
    // 0x1c21e4: 0xc06de28  jal         func_1B78A0
    ctx->pc = 0x1C21E4u;
    SET_GPR_U32(ctx, 31, 0x1C21ECu);
    ctx->pc = 0x1C21E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C21E4u;
            // 0x1c21e8: 0xa2200000  sb          $zero, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B78A0u;
    if (runtime->hasFunction(0x1B78A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B78A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C21ECu; }
        if (ctx->pc != 0x1C21ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B78A0_0x1b78a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C21ECu; }
        if (ctx->pc != 0x1C21ECu) { return; }
    }
    ctx->pc = 0x1C21ECu;
label_1c21ec:
    // 0x1c21ec: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1c21ecu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1c21f0: 0x253102a  slt         $v0, $s2, $s3
    ctx->pc = 0x1c21f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x1c21f4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C21F4u;
    {
        const bool branch_taken_0x1c21f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C21F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C21F4u;
            // 0x1c21f8: 0x27b100ec  addiu       $s1, $sp, 0xEC (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 236));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c21f4) {
            ctx->pc = 0x1C2204u;
            goto label_1c2204;
        }
    }
    ctx->pc = 0x1C21FCu;
    // 0x1c21fc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1C21FCu;
    {
        const bool branch_taken_0x1c21fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C21FCu;
            // 0x1c2200: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c21fc) {
            ctx->pc = 0x1C2234u;
            goto label_1c2234;
        }
    }
    ctx->pc = 0x1C2204u;
label_1c2204:
    // 0x1c2204: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1c2204u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c2208: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1C2208u;
    {
        const bool branch_taken_0x1c2208 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2208) {
            ctx->pc = 0x1C21ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c21ac;
        }
    }
    ctx->pc = 0x1C2210u;
    // 0x1c2210: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C2210u;
    {
        const bool branch_taken_0x1c2210 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2210) {
            ctx->pc = 0x1C2224u;
            goto label_1c2224;
        }
    }
    ctx->pc = 0x1C2218u;
label_1c2218:
    // 0x1c2218: 0xc0708d8  jal         func_1C2360
    ctx->pc = 0x1C2218u;
    SET_GPR_U32(ctx, 31, 0x1C2220u);
    ctx->pc = 0x1C221Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2218u;
            // 0x1c221c: 0x27a40060  addiu       $a0, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2360u;
    if (runtime->hasFunction(0x1C2360u)) {
        auto targetFn = runtime->lookupFunction(0x1C2360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2220u; }
        if (ctx->pc != 0x1C2220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2360_0x1c2360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2220u; }
        if (ctx->pc != 0x1C2220u) { return; }
    }
    ctx->pc = 0x1C2220u;
label_1c2220:
    // 0x1c2220: 0x200a02d  daddu       $s4, $s0, $zero
    ctx->pc = 0x1c2220u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c2224:
    // 0x1c2224: 0x82820000  lb          $v0, 0x0($s4)
    ctx->pc = 0x1c2224u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
label_1c2228:
    // 0x1c2228: 0x1440ffd0  bnez        $v0, . + 4 + (-0x30 << 2)
    ctx->pc = 0x1C2228u;
    {
        const bool branch_taken_0x1c2228 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C222Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2228u;
            // 0x1c222c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2228) {
            ctx->pc = 0x1C216Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c216c;
        }
    }
    ctx->pc = 0x1C2230u;
    // 0x1c2230: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c2230u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c2234:
    // 0x1c2234: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1c2234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c2238: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c2238u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c223c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c223cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c2240: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c2240u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c2244: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c2244u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c2248: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c2248u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c224c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C224Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C2250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C224Cu;
            // 0x1c2250: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C2158u: goto label_1c2158;
            case 0x1C2164u: goto label_1c2164;
            case 0x1C216Cu: goto label_1c216c;
            case 0x1C2174u: goto label_1c2174;
            case 0x1C2188u: goto label_1c2188;
            case 0x1C2198u: goto label_1c2198;
            case 0x1C21A0u: goto label_1c21a0;
            case 0x1C21ACu: goto label_1c21ac;
            case 0x1C21B4u: goto label_1c21b4;
            case 0x1C21C0u: goto label_1c21c0;
            case 0x1C21D4u: goto label_1c21d4;
            case 0x1C21ECu: goto label_1c21ec;
            case 0x1C2204u: goto label_1c2204;
            case 0x1C2218u: goto label_1c2218;
            case 0x1C2220u: goto label_1c2220;
            case 0x1C2224u: goto label_1c2224;
            case 0x1C2228u: goto label_1c2228;
            case 0x1C2234u: goto label_1c2234;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C2254u;
    // 0x1c2254: 0x0  nop
    ctx->pc = 0x1c2254u;
    // NOP
    // 0x1c2258: 0x0  nop
    ctx->pc = 0x1c2258u;
    // NOP
    // 0x1c225c: 0x0  nop
    ctx->pc = 0x1c225cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
