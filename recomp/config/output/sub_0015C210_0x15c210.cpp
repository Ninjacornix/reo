#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015C210
// Address: 0x15c210 - 0x15c890
void sub_0015C210_0x15c210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015C210_0x15c210");
#endif

    switch (ctx->pc) {
        case 0x15c2b0u: goto label_15c2b0;
        case 0x15c2c8u: goto label_15c2c8;
        case 0x15c2d8u: goto label_15c2d8;
        case 0x15c2e0u: goto label_15c2e0;
        case 0x15c304u: goto label_15c304;
        case 0x15c318u: goto label_15c318;
        case 0x15c330u: goto label_15c330;
        case 0x15c348u: goto label_15c348;
        case 0x15c358u: goto label_15c358;
        case 0x15c368u: goto label_15c368;
        case 0x15c378u: goto label_15c378;
        case 0x15c388u: goto label_15c388;
        case 0x15c398u: goto label_15c398;
        case 0x15c3a8u: goto label_15c3a8;
        case 0x15c408u: goto label_15c408;
        case 0x15c410u: goto label_15c410;
        case 0x15c444u: goto label_15c444;
        case 0x15c4e0u: goto label_15c4e0;
        case 0x15c544u: goto label_15c544;
        case 0x15c598u: goto label_15c598;
        case 0x15c5fcu: goto label_15c5fc;
        case 0x15c650u: goto label_15c650;
        case 0x15c6b4u: goto label_15c6b4;
        case 0x15c74cu: goto label_15c74c;
        case 0x15c7b8u: goto label_15c7b8;
        case 0x15c7ccu: goto label_15c7cc;
        case 0x15c7d4u: goto label_15c7d4;
        case 0x15c7e0u: goto label_15c7e0;
        case 0x15c7f4u: goto label_15c7f4;
        case 0x15c810u: goto label_15c810;
        case 0x15c820u: goto label_15c820;
        case 0x15c830u: goto label_15c830;
        case 0x15c858u: goto label_15c858;
        default: break;
    }

    ctx->pc = 0x15c210u;

    // 0x15c210: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x15c210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x15c214: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x15c214u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x15c218: 0xffb000e0  sd          $s0, 0xE0($sp)
    ctx->pc = 0x15c218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 16));
    // 0x15c21c: 0x3c100027  lui         $s0, 0x27
    ctx->pc = 0x15c21cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)39 << 16));
    // 0x15c220: 0xffb100e8  sd          $s1, 0xE8($sp)
    ctx->pc = 0x15c220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 232), GPR_U64(ctx, 17));
    // 0x15c224: 0x3c110027  lui         $s1, 0x27
    ctx->pc = 0x15c224u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)39 << 16));
    // 0x15c228: 0xffb200f0  sd          $s2, 0xF0($sp)
    ctx->pc = 0x15c228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 240), GPR_U64(ctx, 18));
    // 0x15c22c: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x15c22cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x15c230: 0xffb300f8  sd          $s3, 0xF8($sp)
    ctx->pc = 0x15c230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 248), GPR_U64(ctx, 19));
    // 0x15c234: 0x24728518  addiu       $s2, $v1, -0x7AE8
    ctx->pc = 0x15c234u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 4294935832));
    // 0x15c238: 0xffb40100  sd          $s4, 0x100($sp)
    ctx->pc = 0x15c238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 256), GPR_U64(ctx, 20));
    // 0x15c23c: 0x3c060027  lui         $a2, 0x27
    ctx->pc = 0x15c23cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)39 << 16));
    // 0x15c240: 0xffb50108  sd          $s5, 0x108($sp)
    ctx->pc = 0x15c240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 264), GPR_U64(ctx, 21));
    // 0x15c244: 0x24558514  addiu       $s5, $v0, -0x7AEC
    ctx->pc = 0x15c244u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935828));
    // 0x15c248: 0xffb60110  sd          $s6, 0x110($sp)
    ctx->pc = 0x15c248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 22));
    // 0x15c24c: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x15c24cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c250: 0xffb70118  sd          $s7, 0x118($sp)
    ctx->pc = 0x15c250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 280), GPR_U64(ctx, 23));
    // 0x15c254: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x15c254u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c258: 0xffbe0120  sd          $fp, 0x120($sp)
    ctx->pc = 0x15c258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 30));
    // 0x15c25c: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x15c25cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x15c260: 0xffbf0128  sd          $ra, 0x128($sp)
    ctx->pc = 0x15c260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 296), GPR_U64(ctx, 31));
    // 0x15c264: 0x24b3851c  addiu       $s3, $a1, -0x7AE4
    ctx->pc = 0x15c264u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), 4294935836));
    // 0x15c268: 0x24d48520  addiu       $s4, $a2, -0x7AE0
    ctx->pc = 0x15c268u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), 4294935840));
    // 0x15c26c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x15c26cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c270: 0x8ee20010  lw          $v0, 0x10($s7)
    ctx->pc = 0x15c270u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 16)));
    // 0x15c274: 0x26108530  addiu       $s0, $s0, -0x7AD0
    ctx->pc = 0x15c274u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294935856));
    // 0x15c278: 0x8efe0000  lw          $fp, 0x0($s7)
    ctx->pc = 0x15c278u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x15c27c: 0x2631852c  addiu       $s1, $s1, -0x7AD4
    ctx->pc = 0x15c27cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294935852));
    // 0x15c280: 0xafa200c0  sw          $v0, 0xC0($sp)
    ctx->pc = 0x15c280u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 2));
    // 0x15c284: 0x280402d  daddu       $t0, $s4, $zero
    ctx->pc = 0x15c284u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c288: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x15c288u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c28c: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x15c28cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c290: 0x8ee30008  lw          $v1, 0x8($s7)
    ctx->pc = 0x15c290u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 8)));
    // 0x15c294: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x15c294u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c298: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x15c298u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c29c: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x15c29cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c2a0: 0xafa300c4  sw          $v1, 0xC4($sp)
    ctx->pc = 0x15c2a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 196), GPR_U32(ctx, 3));
    // 0x15c2a4: 0x8ee2000c  lw          $v0, 0xC($s7)
    ctx->pc = 0x15c2a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 12)));
    // 0x15c2a8: 0xc056ee8  jal         func_15BBA0
    ctx->pc = 0x15C2A8u;
    SET_GPR_U32(ctx, 31, 0x15C2B0u);
    ctx->pc = 0x15C2ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C2A8u;
            // 0x15c2ac: 0xafa200c8  sw          $v0, 0xC8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 200), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BBA0u;
    if (runtime->hasFunction(0x15BBA0u)) {
        auto targetFn = runtime->lookupFunction(0x15BBA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2B0u; }
        if (ctx->pc != 0x15C2B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BBA0_0x15bba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2B0u; }
        if (ctx->pc != 0x15C2B0u) { return; }
    }
    ctx->pc = 0x15C2B0u;
label_15c2b0:
    // 0x15c2b0: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x15c2b0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x15c2b4: 0x3c060027  lui         $a2, 0x27
    ctx->pc = 0x15c2b4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)39 << 16));
    // 0x15c2b8: 0x24a58524  addiu       $a1, $a1, -0x7ADC
    ctx->pc = 0x15c2b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294935844));
    // 0x15c2bc: 0x24c68528  addiu       $a2, $a2, -0x7AD8
    ctx->pc = 0x15c2bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294935848));
    // 0x15c2c0: 0xc056f36  jal         func_15BCD8
    ctx->pc = 0x15C2C0u;
    SET_GPR_U32(ctx, 31, 0x15C2C8u);
    ctx->pc = 0x15C2C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C2C0u;
            // 0x15c2c4: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BCD8u;
    if (runtime->hasFunction(0x15BCD8u)) {
        auto targetFn = runtime->lookupFunction(0x15BCD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2C8u; }
        if (ctx->pc != 0x15C2C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BCD8_0x15bcd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2C8u; }
        if (ctx->pc != 0x15C2C8u) { return; }
    }
    ctx->pc = 0x15C2C8u;
label_15c2c8:
    // 0x15c2c8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x15c2c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c2cc: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x15c2ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x15c2d0: 0xc056f84  jal         func_15BE10
    ctx->pc = 0x15C2D0u;
    SET_GPR_U32(ctx, 31, 0x15C2D8u);
    ctx->pc = 0x15C2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C2D0u;
            // 0x15c2d4: 0x27a600a4  addiu       $a2, $sp, 0xA4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 164));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BE10u;
    if (runtime->hasFunction(0x15BE10u)) {
        auto targetFn = runtime->lookupFunction(0x15BE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2D8u; }
        if (ctx->pc != 0x15C2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BE10_0x15be10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2D8u; }
        if (ctx->pc != 0x15C2D8u) { return; }
    }
    ctx->pc = 0x15C2D8u;
label_15c2d8:
    // 0x15c2d8: 0xc056f8c  jal         func_15BE30
    ctx->pc = 0x15C2D8u;
    SET_GPR_U32(ctx, 31, 0x15C2E0u);
    ctx->pc = 0x15BE30u;
    if (runtime->hasFunction(0x15BE30u)) {
        auto targetFn = runtime->lookupFunction(0x15BE30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2E0u; }
        if (ctx->pc != 0x15C2E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BE30_0x15be30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C2E0u; }
        if (ctx->pc != 0x15C2E0u) { return; }
    }
    ctx->pc = 0x15C2E0u;
label_15c2e0:
    // 0x15c2e0: 0xafa200d0  sw          $v0, 0xD0($sp)
    ctx->pc = 0x15c2e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 2));
    // 0x15c2e4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c2e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c2e8: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x15c2e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15c2ec: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x15c2ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15c2f0: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x15c2f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x15c2f4: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x15c2f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x15c2f8: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x15c2f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x15c2fc: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C2FCu;
    SET_GPR_U32(ctx, 31, 0x15C304u);
    ctx->pc = 0x15C300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C2FCu;
            // 0x15c300: 0x24a50040  addiu       $a1, $a1, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C304u; }
        if (ctx->pc != 0x15C304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C304u; }
        if (ctx->pc != 0x15C304u) { return; }
    }
    ctx->pc = 0x15C304u;
label_15c304:
    // 0x15c304: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c304u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c308: 0xafa200b8  sw          $v0, 0xB8($sp)
    ctx->pc = 0x15c308u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 184), GPR_U32(ctx, 2));
    // 0x15c30c: 0x8ea50000  lw          $a1, 0x0($s5)
    ctx->pc = 0x15c30cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x15c310: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C310u;
    SET_GPR_U32(ctx, 31, 0x15C318u);
    ctx->pc = 0x15C314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C310u;
            // 0x15c314: 0x24a50040  addiu       $a1, $a1, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C318u; }
        if (ctx->pc != 0x15C318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C318u; }
        if (ctx->pc != 0x15C318u) { return; }
    }
    ctx->pc = 0x15C318u;
label_15c318:
    // 0x15c318: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c31c: 0x27a30050  addiu       $v1, $sp, 0x50
    ctx->pc = 0x15c31cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x15c320: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x15c320u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c324: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x15c324u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c328: 0xc05701e  jal         func_15C078
    ctx->pc = 0x15C328u;
    SET_GPR_U32(ctx, 31, 0x15C330u);
    ctx->pc = 0x15C32Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C328u;
            // 0x15c32c: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C078u;
    if (runtime->hasFunction(0x15C078u)) {
        auto targetFn = runtime->lookupFunction(0x15C078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C330u; }
        if (ctx->pc != 0x15C330u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015C078_0x15c078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C330u; }
        if (ctx->pc != 0x15C330u) { return; }
    }
    ctx->pc = 0x15C330u;
label_15c330:
    // 0x15c330: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c330u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c334: 0x27a70060  addiu       $a3, $sp, 0x60
    ctx->pc = 0x15c334u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x15c338: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x15c338u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c33c: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x15c33cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c340: 0xc057048  jal         func_15C120
    ctx->pc = 0x15C340u;
    SET_GPR_U32(ctx, 31, 0x15C348u);
    ctx->pc = 0x15C344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C340u;
            // 0x15c344: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C120u;
    if (runtime->hasFunction(0x15C120u)) {
        auto targetFn = runtime->lookupFunction(0x15C120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C348u; }
        if (ctx->pc != 0x15C348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015C120_0x15c120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C348u; }
        if (ctx->pc != 0x15C348u) { return; }
    }
    ctx->pc = 0x15C348u;
label_15c348:
    // 0x15c348: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c348u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c34c: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x15c34cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15c350: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C350u;
    SET_GPR_U32(ctx, 31, 0x15C358u);
    ctx->pc = 0x15C354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C350u;
            // 0x15c354: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C358u; }
        if (ctx->pc != 0x15C358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C358u; }
        if (ctx->pc != 0x15C358u) { return; }
    }
    ctx->pc = 0x15C358u;
label_15c358:
    // 0x15c358: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c358u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c35c: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x15c35cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15c360: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C360u;
    SET_GPR_U32(ctx, 31, 0x15C368u);
    ctx->pc = 0x15C364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C360u;
            // 0x15c364: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C368u; }
        if (ctx->pc != 0x15C368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C368u; }
        if (ctx->pc != 0x15C368u) { return; }
    }
    ctx->pc = 0x15C368u;
label_15c368:
    // 0x15c368: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c36c: 0x24050800  addiu       $a1, $zero, 0x800
    ctx->pc = 0x15c36cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x15c370: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C370u;
    SET_GPR_U32(ctx, 31, 0x15C378u);
    ctx->pc = 0x15C374u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C370u;
            // 0x15c374: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C378u; }
        if (ctx->pc != 0x15C378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C378u; }
        if (ctx->pc != 0x15C378u) { return; }
    }
    ctx->pc = 0x15C378u;
label_15c378:
    // 0x15c378: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c378u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c37c: 0x8fa500a0  lw          $a1, 0xA0($sp)
    ctx->pc = 0x15c37cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x15c380: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C380u;
    SET_GPR_U32(ctx, 31, 0x15C388u);
    ctx->pc = 0x15C384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C380u;
            // 0x15c384: 0xafa200bc  sw          $v0, 0xBC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 188), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C388u; }
        if (ctx->pc != 0x15C388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C388u; }
        if (ctx->pc != 0x15C388u) { return; }
    }
    ctx->pc = 0x15C388u;
label_15c388:
    // 0x15c388: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c38c: 0x8fa500a4  lw          $a1, 0xA4($sp)
    ctx->pc = 0x15c38cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 164)));
    // 0x15c390: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C390u;
    SET_GPR_U32(ctx, 31, 0x15C398u);
    ctx->pc = 0x15C394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C390u;
            // 0x15c394: 0xafa200cc  sw          $v0, 0xCC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 204), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C398u; }
        if (ctx->pc != 0x15C398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C398u; }
        if (ctx->pc != 0x15C398u) { return; }
    }
    ctx->pc = 0x15C398u;
label_15c398:
    // 0x15c398: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c398u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c39c: 0x8fa500d0  lw          $a1, 0xD0($sp)
    ctx->pc = 0x15c39cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x15c3a0: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C3A0u;
    SET_GPR_U32(ctx, 31, 0x15C3A8u);
    ctx->pc = 0x15C3A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C3A0u;
            // 0x15c3a4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C3A8u; }
        if (ctx->pc != 0x15C3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C3A8u; }
        if (ctx->pc != 0x15C3A8u) { return; }
    }
    ctx->pc = 0x15C3A8u;
label_15c3a8:
    // 0x15c3a8: 0x8fa800b8  lw          $t0, 0xB8($sp)
    ctx->pc = 0x15c3a8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x15c3ac: 0x11000013  beqz        $t0, . + 4 + (0x13 << 2)
    ctx->pc = 0x15C3ACu;
    {
        const bool branch_taken_0x15c3ac = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C3ACu;
            // 0x15c3b0: 0xafa200d4  sw          $v0, 0xD4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 212), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c3ac) {
            ctx->pc = 0x15C3FCu;
            goto label_15c3fc;
        }
    }
    ctx->pc = 0x15C3B4u;
    // 0x15c3b4: 0x12600012  beqz        $s3, . + 4 + (0x12 << 2)
    ctx->pc = 0x15C3B4u;
    {
        const bool branch_taken_0x15c3b4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C3B4u;
            // 0x15c3b8: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c3b4) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3BCu;
    // 0x15c3bc: 0x16800010  bnez        $s4, . + 4 + (0x10 << 2)
    ctx->pc = 0x15C3BCu;
    {
        const bool branch_taken_0x15c3bc = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        if (branch_taken_0x15c3bc) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3C4u;
    // 0x15c3c4: 0x1640000e  bnez        $s2, . + 4 + (0xE << 2)
    ctx->pc = 0x15C3C4u;
    {
        const bool branch_taken_0x15c3c4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x15c3c4) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3CCu;
    // 0x15c3cc: 0x12a0000c  beqz        $s5, . + 4 + (0xC << 2)
    ctx->pc = 0x15C3CCu;
    {
        const bool branch_taken_0x15c3cc = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x15c3cc) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3D4u;
    // 0x15c3d4: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x15C3D4u;
    {
        const bool branch_taken_0x15c3d4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C3D4u;
            // 0x15c3d8: 0x8fa900bc  lw          $t1, 0xBC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 188)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c3d4) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3DCu;
    // 0x15c3dc: 0x11200008  beqz        $t1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15C3DCu;
    {
        const bool branch_taken_0x15c3dc = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C3E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C3DCu;
            // 0x15c3e0: 0x8faa00cc  lw          $t2, 0xCC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 204)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c3dc) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3E4u;
    // 0x15c3e4: 0x11400006  beqz        $t2, . + 4 + (0x6 << 2)
    ctx->pc = 0x15C3E4u;
    {
        const bool branch_taken_0x15c3e4 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        if (branch_taken_0x15c3e4) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3ECu;
    // 0x15c3ec: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15C3ECu;
    {
        const bool branch_taken_0x15c3ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15c3ec) {
            ctx->pc = 0x15C400u;
            goto label_15c400;
        }
    }
    ctx->pc = 0x15C3F4u;
    // 0x15c3f4: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15C3F4u;
    {
        const bool branch_taken_0x15c3f4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x15C3F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C3F4u;
            // 0x15c3f8: 0x2402ffc0  addiu       $v0, $zero, -0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c3f4) {
            ctx->pc = 0x15C418u;
            goto label_15c418;
        }
    }
    ctx->pc = 0x15C3FCu;
label_15c3fc:
    // 0x15c3fc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c3fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_15c400:
    // 0x15c400: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15C400u;
    SET_GPR_U32(ctx, 31, 0x15C408u);
    ctx->pc = 0x15C404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C400u;
            // 0x15c404: 0x2484e798  addiu       $a0, $a0, -0x1868 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C408u; }
        if (ctx->pc != 0x15C408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C408u; }
        if (ctx->pc != 0x15C408u) { return; }
    }
    ctx->pc = 0x15C408u;
label_15c408:
    // 0x15c408: 0xc0575d0  jal         func_15D740
    ctx->pc = 0x15C408u;
    SET_GPR_U32(ctx, 31, 0x15C410u);
    ctx->pc = 0x15C40Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C408u;
            // 0x15c40c: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D740u;
    if (runtime->hasFunction(0x15D740u)) {
        auto targetFn = runtime->lookupFunction(0x15D740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C410u; }
        if (ctx->pc != 0x15C410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D740_0x15d740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C410u; }
        if (ctx->pc != 0x15C410u) { return; }
    }
    ctx->pc = 0x15C410u;
label_15c410:
    // 0x15c410: 0x10000112  b           . + 4 + (0x112 << 2)
    ctx->pc = 0x15C410u;
    {
        const bool branch_taken_0x15c410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C410u;
            // 0x15c414: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c410) {
            ctx->pc = 0x15C85Cu;
            goto label_15c85c;
        }
    }
    ctx->pc = 0x15C418u;
label_15c418:
    // 0x15c418: 0x2663003f  addiu       $v1, $s3, 0x3F
    ctx->pc = 0x15c418u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 63));
    // 0x15c41c: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x15c41cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x15c420: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x15c420u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c424: 0x27a500a8  addiu       $a1, $sp, 0xA8
    ctx->pc = 0x15c424u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
    // 0x15c428: 0x27a600ac  addiu       $a2, $sp, 0xAC
    ctx->pc = 0x15c428u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 172));
    // 0x15c42c: 0x27a700b0  addiu       $a3, $sp, 0xB0
    ctx->pc = 0x15c42cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x15c430: 0x27a800b4  addiu       $t0, $sp, 0xB4
    ctx->pc = 0x15c430u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 180));
    // 0x15c434: 0x3c100027  lui         $s0, 0x27
    ctx->pc = 0x15c434u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)39 << 16));
    // 0x15c438: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x15c438u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x15c43c: 0xc056f22  jal         func_15BC88
    ctx->pc = 0x15C43Cu;
    SET_GPR_U32(ctx, 31, 0x15C444u);
    ctx->pc = 0x15C440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C43Cu;
            // 0x15c440: 0xae038510  sw          $v1, -0x7AF0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4294935824), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BC88u;
    if (runtime->hasFunction(0x15BC88u)) {
        auto targetFn = runtime->lookupFunction(0x15BC88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C444u; }
        if (ctx->pc != 0x15C444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BC88_0x15bc88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C444u; }
        if (ctx->pc != 0x15C444u) { return; }
    }
    ctx->pc = 0x15C444u;
label_15c444:
    // 0x15c444: 0x8fa300b4  lw          $v1, 0xB4($sp)
    ctx->pc = 0x15c444u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 180)));
    // 0x15c448: 0x3c140023  lui         $s4, 0x23
    ctx->pc = 0x15c448u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)35 << 16));
    // 0x15c44c: 0x8fa700a8  lw          $a3, 0xA8($sp)
    ctx->pc = 0x15c44cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x15c450: 0x2662de08  addiu       $v0, $s3, -0x21F8
    ctx->pc = 0x15c450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294958600));
    // 0x15c454: 0x8fa600ac  lw          $a2, 0xAC($sp)
    ctx->pc = 0x15c454u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x15c458: 0x2684de30  addiu       $a0, $s4, -0x21D0
    ctx->pc = 0x15c458u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294958640));
    // 0x15c45c: 0x8fa500b0  lw          $a1, 0xB0($sp)
    ctx->pc = 0x15c45cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x15c460: 0x24080002  addiu       $t0, $zero, 0x2
    ctx->pc = 0x15c460u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15c464: 0xac910018  sw          $s1, 0x18($a0)
    ctx->pc = 0x15c464u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 17));
    // 0x15c468: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x15c468u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x15c46c: 0xac400020  sw          $zero, 0x20($v0)
    ctx->pc = 0x15c46cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 0));
    // 0x15c470: 0xac430004  sw          $v1, 0x4($v0)
    ctx->pc = 0x15c470u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
    // 0x15c474: 0xac950008  sw          $s5, 0x8($a0)
    ctx->pc = 0x15c474u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 21));
    // 0x15c478: 0xac470014  sw          $a3, 0x14($v0)
    ctx->pc = 0x15c478u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 7));
    // 0x15c47c: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x15c47cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x15c480: 0xac470008  sw          $a3, 0x8($v0)
    ctx->pc = 0x15c480u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 7));
    // 0x15c484: 0xac46000c  sw          $a2, 0xC($v0)
    ctx->pc = 0x15c484u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 6));
    // 0x15c488: 0xac400010  sw          $zero, 0x10($v0)
    ctx->pc = 0x15c488u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x15c48c: 0x8fa300c0  lw          $v1, 0xC0($sp)
    ctx->pc = 0x15c48cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x15c490: 0x13c8003b  beq         $fp, $t0, . + 4 + (0x3B << 2)
    ctx->pc = 0x15C490u;
    {
        const bool branch_taken_0x15c490 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 8));
        ctx->pc = 0x15C494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C490u;
            // 0x15c494: 0xac43001c  sw          $v1, 0x1C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c490) {
            ctx->pc = 0x15C580u;
            goto label_15c580;
        }
    }
    ctx->pc = 0x15C498u;
    // 0x15c498: 0x2bc20003  slti        $v0, $fp, 0x3
    ctx->pc = 0x15c498u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 30) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x15c49c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15C49Cu;
    {
        const bool branch_taken_0x15c49c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C4A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C49Cu;
            // 0x15c4a0: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c49c) {
            ctx->pc = 0x15C4B8u;
            goto label_15c4b8;
        }
    }
    ctx->pc = 0x15C4A4u;
    // 0x15c4a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15c4a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15c4a8: 0x13c20007  beq         $fp, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15C4A8u;
    {
        const bool branch_taken_0x15c4a8 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 2));
        ctx->pc = 0x15C4ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C4A8u;
            // 0x15c4ac: 0x3c030027  lui         $v1, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c4a8) {
            ctx->pc = 0x15C4C8u;
            goto label_15c4c8;
        }
    }
    ctx->pc = 0x15C4B0u;
    // 0x15c4b0: 0x10000099  b           . + 4 + (0x99 << 2)
    ctx->pc = 0x15C4B0u;
    {
        const bool branch_taken_0x15c4b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C4B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C4B0u;
            // 0x15c4b4: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c4b0) {
            ctx->pc = 0x15C718u;
            goto label_15c718;
        }
    }
    ctx->pc = 0x15C4B8u;
label_15c4b8:
    // 0x15c4b8: 0x13c2005f  beq         $fp, $v0, . + 4 + (0x5F << 2)
    ctx->pc = 0x15C4B8u;
    {
        const bool branch_taken_0x15c4b8 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 2));
        ctx->pc = 0x15C4BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C4B8u;
            // 0x15c4bc: 0x3c030027  lui         $v1, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c4b8) {
            ctx->pc = 0x15C638u;
            goto label_15c638;
        }
    }
    ctx->pc = 0x15C4C0u;
    // 0x15c4c0: 0x10000095  b           . + 4 + (0x95 << 2)
    ctx->pc = 0x15C4C0u;
    {
        const bool branch_taken_0x15c4c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C4C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C4C0u;
            // 0x15c4c4: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c4c0) {
            ctx->pc = 0x15C718u;
            goto label_15c718;
        }
    }
    ctx->pc = 0x15C4C8u;
label_15c4c8:
    // 0x15c4c8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15c4c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15c4cc: 0x2463dd30  addiu       $v1, $v1, -0x22D0
    ctx->pc = 0x15c4ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958384));
    // 0x15c4d0: 0x30620007  andi        $v0, $v1, 0x7
    ctx->pc = 0x15c4d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x15c4d4: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x15C4D4u;
    {
        const bool branch_taken_0x15c4d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C4D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C4D4u;
            // 0x15c4d8: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c4d4) {
            ctx->pc = 0x15C540u;
            goto label_15c540;
        }
    }
    ctx->pc = 0x15C4DCu;
    // 0x15c4dc: 0x24620040  addiu       $v0, $v1, 0x40
    ctx->pc = 0x15c4dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_15c4e0:
    // 0x15c4e0: 0x68640007  ldl         $a0, 0x7($v1)
    ctx->pc = 0x15c4e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x15c4e4: 0x6c640000  ldr         $a0, 0x0($v1)
    ctx->pc = 0x15c4e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x15c4e8: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x15c4e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x15c4ec: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x15c4ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x15c4f0: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x15c4f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x15c4f4: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x15c4f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x15c4f8: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x15c4f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x15c4fc: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x15c4fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x15c500: 0xb0a40007  sdl         $a0, 0x7($a1)
    ctx->pc = 0x15c500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c504: 0xb4a40000  sdr         $a0, 0x0($a1)
    ctx->pc = 0x15c504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c508: 0xb0a6000f  sdl         $a2, 0xF($a1)
    ctx->pc = 0x15c508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c50c: 0xb4a60008  sdr         $a2, 0x8($a1)
    ctx->pc = 0x15c50cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c510: 0xb0a70017  sdl         $a3, 0x17($a1)
    ctx->pc = 0x15c510u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c514: 0xb4a70010  sdr         $a3, 0x10($a1)
    ctx->pc = 0x15c514u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c518: 0xb0a8001f  sdl         $t0, 0x1F($a1)
    ctx->pc = 0x15c518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c51c: 0xb4a80018  sdr         $t0, 0x18($a1)
    ctx->pc = 0x15c51cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c520: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x15c520u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x15c524: 0x0  nop
    ctx->pc = 0x15c524u;
    // NOP
    // 0x15c528: 0x0  nop
    ctx->pc = 0x15c528u;
    // NOP
    // 0x15c52c: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x15C52Cu;
    {
        const bool branch_taken_0x15c52c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15C530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C52Cu;
            // 0x15c530: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c52c) {
            ctx->pc = 0x15C4E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15c4e0;
        }
    }
    ctx->pc = 0x15C534u;
    // 0x15c534: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x15C534u;
    {
        const bool branch_taken_0x15c534 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C534u;
            // 0x15c538: 0x8e028510  lw          $v0, -0x7AF0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294935824)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c534) {
            ctx->pc = 0x15C6ECu;
            goto label_15c6ec;
        }
    }
    ctx->pc = 0x15C53Cu;
    // 0x15c53c: 0x0  nop
    ctx->pc = 0x15c53cu;
    // NOP
label_15c540:
    // 0x15c540: 0x24620040  addiu       $v0, $v1, 0x40
    ctx->pc = 0x15c540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_15c544:
    // 0x15c544: 0xdc690000  ld          $t1, 0x0($v1)
    ctx->pc = 0x15c544u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15c548: 0xdc6a0008  ld          $t2, 0x8($v1)
    ctx->pc = 0x15c548u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x15c54c: 0xdc640010  ld          $a0, 0x10($v1)
    ctx->pc = 0x15c54cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x15c550: 0xdc660018  ld          $a2, 0x18($v1)
    ctx->pc = 0x15c550u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15c554: 0xfca90000  sd          $t1, 0x0($a1)
    ctx->pc = 0x15c554u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 9));
    // 0x15c558: 0xfcaa0008  sd          $t2, 0x8($a1)
    ctx->pc = 0x15c558u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 10));
    // 0x15c55c: 0xfca40010  sd          $a0, 0x10($a1)
    ctx->pc = 0x15c55cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 4));
    // 0x15c560: 0xfca60018  sd          $a2, 0x18($a1)
    ctx->pc = 0x15c560u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 6));
    // 0x15c564: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x15c564u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x15c568: 0x0  nop
    ctx->pc = 0x15c568u;
    // NOP
    // 0x15c56c: 0x0  nop
    ctx->pc = 0x15c56cu;
    // NOP
    // 0x15c570: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x15C570u;
    {
        const bool branch_taken_0x15c570 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15C574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C570u;
            // 0x15c574: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c570) {
            ctx->pc = 0x15C544u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15c544;
        }
    }
    ctx->pc = 0x15C578u;
    // 0x15c578: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x15C578u;
    {
        const bool branch_taken_0x15c578 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C57Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C578u;
            // 0x15c57c: 0x8e028510  lw          $v0, -0x7AF0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294935824)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c578) {
            ctx->pc = 0x15C6ECu;
            goto label_15c6ec;
        }
    }
    ctx->pc = 0x15C580u;
label_15c580:
    // 0x15c580: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15c580u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15c584: 0x2463dd78  addiu       $v1, $v1, -0x2288
    ctx->pc = 0x15c584u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958456));
    // 0x15c588: 0x30620007  andi        $v0, $v1, 0x7
    ctx->pc = 0x15c588u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x15c58c: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x15C58Cu;
    {
        const bool branch_taken_0x15c58c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C58Cu;
            // 0x15c590: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c58c) {
            ctx->pc = 0x15C5F8u;
            goto label_15c5f8;
        }
    }
    ctx->pc = 0x15C594u;
    // 0x15c594: 0x24620040  addiu       $v0, $v1, 0x40
    ctx->pc = 0x15c594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_15c598:
    // 0x15c598: 0x68640007  ldl         $a0, 0x7($v1)
    ctx->pc = 0x15c598u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x15c59c: 0x6c640000  ldr         $a0, 0x0($v1)
    ctx->pc = 0x15c59cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x15c5a0: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x15c5a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x15c5a4: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x15c5a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x15c5a8: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x15c5a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x15c5ac: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x15c5acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x15c5b0: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x15c5b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x15c5b4: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x15c5b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x15c5b8: 0xb0a40007  sdl         $a0, 0x7($a1)
    ctx->pc = 0x15c5b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5bc: 0xb4a40000  sdr         $a0, 0x0($a1)
    ctx->pc = 0x15c5bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5c0: 0xb0a6000f  sdl         $a2, 0xF($a1)
    ctx->pc = 0x15c5c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5c4: 0xb4a60008  sdr         $a2, 0x8($a1)
    ctx->pc = 0x15c5c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5c8: 0xb0a70017  sdl         $a3, 0x17($a1)
    ctx->pc = 0x15c5c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5cc: 0xb4a70010  sdr         $a3, 0x10($a1)
    ctx->pc = 0x15c5ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5d0: 0xb0a8001f  sdl         $t0, 0x1F($a1)
    ctx->pc = 0x15c5d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5d4: 0xb4a80018  sdr         $t0, 0x18($a1)
    ctx->pc = 0x15c5d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c5d8: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x15c5d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x15c5dc: 0x0  nop
    ctx->pc = 0x15c5dcu;
    // NOP
    // 0x15c5e0: 0x0  nop
    ctx->pc = 0x15c5e0u;
    // NOP
    // 0x15c5e4: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x15C5E4u;
    {
        const bool branch_taken_0x15c5e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15C5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C5E4u;
            // 0x15c5e8: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c5e4) {
            ctx->pc = 0x15C598u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15c598;
        }
    }
    ctx->pc = 0x15C5ECu;
    // 0x15c5ec: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x15C5ECu;
    {
        const bool branch_taken_0x15c5ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C5F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C5ECu;
            // 0x15c5f0: 0x8e028510  lw          $v0, -0x7AF0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294935824)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c5ec) {
            ctx->pc = 0x15C6ECu;
            goto label_15c6ec;
        }
    }
    ctx->pc = 0x15C5F4u;
    // 0x15c5f4: 0x0  nop
    ctx->pc = 0x15c5f4u;
    // NOP
label_15c5f8:
    // 0x15c5f8: 0x24620040  addiu       $v0, $v1, 0x40
    ctx->pc = 0x15c5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_15c5fc:
    // 0x15c5fc: 0xdc690000  ld          $t1, 0x0($v1)
    ctx->pc = 0x15c5fcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15c600: 0xdc6a0008  ld          $t2, 0x8($v1)
    ctx->pc = 0x15c600u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x15c604: 0xdc640010  ld          $a0, 0x10($v1)
    ctx->pc = 0x15c604u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x15c608: 0xdc660018  ld          $a2, 0x18($v1)
    ctx->pc = 0x15c608u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15c60c: 0xfca90000  sd          $t1, 0x0($a1)
    ctx->pc = 0x15c60cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 9));
    // 0x15c610: 0xfcaa0008  sd          $t2, 0x8($a1)
    ctx->pc = 0x15c610u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 10));
    // 0x15c614: 0xfca40010  sd          $a0, 0x10($a1)
    ctx->pc = 0x15c614u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 4));
    // 0x15c618: 0xfca60018  sd          $a2, 0x18($a1)
    ctx->pc = 0x15c618u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 6));
    // 0x15c61c: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x15c61cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x15c620: 0x0  nop
    ctx->pc = 0x15c620u;
    // NOP
    // 0x15c624: 0x0  nop
    ctx->pc = 0x15c624u;
    // NOP
    // 0x15c628: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x15C628u;
    {
        const bool branch_taken_0x15c628 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15C62Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C628u;
            // 0x15c62c: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c628) {
            ctx->pc = 0x15C5FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15c5fc;
        }
    }
    ctx->pc = 0x15C630u;
    // 0x15c630: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x15C630u;
    {
        const bool branch_taken_0x15c630 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C630u;
            // 0x15c634: 0x8e028510  lw          $v0, -0x7AF0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294935824)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c630) {
            ctx->pc = 0x15C6ECu;
            goto label_15c6ec;
        }
    }
    ctx->pc = 0x15C638u;
label_15c638:
    // 0x15c638: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15c638u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15c63c: 0x2463ddc0  addiu       $v1, $v1, -0x2240
    ctx->pc = 0x15c63cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958528));
    // 0x15c640: 0x30620007  andi        $v0, $v1, 0x7
    ctx->pc = 0x15c640u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x15c644: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x15C644u;
    {
        const bool branch_taken_0x15c644 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C644u;
            // 0x15c648: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c644) {
            ctx->pc = 0x15C6B0u;
            goto label_15c6b0;
        }
    }
    ctx->pc = 0x15C64Cu;
    // 0x15c64c: 0x24620040  addiu       $v0, $v1, 0x40
    ctx->pc = 0x15c64cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_15c650:
    // 0x15c650: 0x68640007  ldl         $a0, 0x7($v1)
    ctx->pc = 0x15c650u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x15c654: 0x6c640000  ldr         $a0, 0x0($v1)
    ctx->pc = 0x15c654u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x15c658: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x15c658u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x15c65c: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x15c65cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x15c660: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x15c660u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x15c664: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x15c664u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x15c668: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x15c668u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x15c66c: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x15c66cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x15c670: 0xb0a40007  sdl         $a0, 0x7($a1)
    ctx->pc = 0x15c670u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c674: 0xb4a40000  sdr         $a0, 0x0($a1)
    ctx->pc = 0x15c674u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c678: 0xb0a6000f  sdl         $a2, 0xF($a1)
    ctx->pc = 0x15c678u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c67c: 0xb4a60008  sdr         $a2, 0x8($a1)
    ctx->pc = 0x15c67cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c680: 0xb0a70017  sdl         $a3, 0x17($a1)
    ctx->pc = 0x15c680u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c684: 0xb4a70010  sdr         $a3, 0x10($a1)
    ctx->pc = 0x15c684u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c688: 0xb0a8001f  sdl         $t0, 0x1F($a1)
    ctx->pc = 0x15c688u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c68c: 0xb4a80018  sdr         $t0, 0x18($a1)
    ctx->pc = 0x15c68cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15c690: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x15c690u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x15c694: 0x0  nop
    ctx->pc = 0x15c694u;
    // NOP
    // 0x15c698: 0x0  nop
    ctx->pc = 0x15c698u;
    // NOP
    // 0x15c69c: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x15C69Cu;
    {
        const bool branch_taken_0x15c69c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15C6A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C69Cu;
            // 0x15c6a0: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c69c) {
            ctx->pc = 0x15C650u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15c650;
        }
    }
    ctx->pc = 0x15C6A4u;
    // 0x15c6a4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x15C6A4u;
    {
        const bool branch_taken_0x15c6a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C6A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C6A4u;
            // 0x15c6a8: 0x8e028510  lw          $v0, -0x7AF0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294935824)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c6a4) {
            ctx->pc = 0x15C6ECu;
            goto label_15c6ec;
        }
    }
    ctx->pc = 0x15C6ACu;
    // 0x15c6ac: 0x0  nop
    ctx->pc = 0x15c6acu;
    // NOP
label_15c6b0:
    // 0x15c6b0: 0x24620040  addiu       $v0, $v1, 0x40
    ctx->pc = 0x15c6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_15c6b4:
    // 0x15c6b4: 0xdc690000  ld          $t1, 0x0($v1)
    ctx->pc = 0x15c6b4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15c6b8: 0xdc6a0008  ld          $t2, 0x8($v1)
    ctx->pc = 0x15c6b8u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x15c6bc: 0xdc640010  ld          $a0, 0x10($v1)
    ctx->pc = 0x15c6bcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x15c6c0: 0xdc660018  ld          $a2, 0x18($v1)
    ctx->pc = 0x15c6c0u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15c6c4: 0xfca90000  sd          $t1, 0x0($a1)
    ctx->pc = 0x15c6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 9));
    // 0x15c6c8: 0xfcaa0008  sd          $t2, 0x8($a1)
    ctx->pc = 0x15c6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 10));
    // 0x15c6cc: 0xfca40010  sd          $a0, 0x10($a1)
    ctx->pc = 0x15c6ccu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 4));
    // 0x15c6d0: 0xfca60018  sd          $a2, 0x18($a1)
    ctx->pc = 0x15c6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 6));
    // 0x15c6d4: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x15c6d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x15c6d8: 0x0  nop
    ctx->pc = 0x15c6d8u;
    // NOP
    // 0x15c6dc: 0x0  nop
    ctx->pc = 0x15c6dcu;
    // NOP
    // 0x15c6e0: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x15C6E0u;
    {
        const bool branch_taken_0x15c6e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15C6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C6E0u;
            // 0x15c6e4: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c6e0) {
            ctx->pc = 0x15C6B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15c6b4;
        }
    }
    ctx->pc = 0x15C6E8u;
    // 0x15c6e8: 0x8e028510  lw          $v0, -0x7AF0($s0)
    ctx->pc = 0x15c6e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294935824)));
label_15c6ec:
    // 0x15c6ec: 0x24040800  addiu       $a0, $zero, 0x800
    ctx->pc = 0x15c6ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x15c6f0: 0x8c670000  lw          $a3, 0x0($v1)
    ctx->pc = 0x15c6f0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15c6f4: 0xaca70000  sw          $a3, 0x0($a1)
    ctx->pc = 0x15c6f4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 7));
    // 0x15c6f8: 0xaec20130  sw          $v0, 0x130($s6)
    ctx->pc = 0x15c6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 304), GPR_U32(ctx, 2));
    // 0x15c6fc: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x15c6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x15c700: 0x8c438514  lw          $v1, -0x7AEC($v0)
    ctx->pc = 0x15c700u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294935828)));
    // 0x15c704: 0xaec40138  sw          $a0, 0x138($s6)
    ctx->pc = 0x15c704u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 312), GPR_U32(ctx, 4));
    // 0x15c708: 0x2463f800  addiu       $v1, $v1, -0x800
    ctx->pc = 0x15c708u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294965248));
    // 0x15c70c: 0xaec30134  sw          $v1, 0x134($s6)
    ctx->pc = 0x15c70cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 308), GPR_U32(ctx, 3));
    // 0x15c710: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x15c710u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x15c714: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15c714u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
label_15c718:
    // 0x15c718: 0x24728518  addiu       $s2, $v1, -0x7AE8
    ctx->pc = 0x15c718u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 4294935832));
    // 0x15c71c: 0x8c43de4c  lw          $v1, -0x21B4($v0)
    ctx->pc = 0x15c71cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958668)));
    // 0x15c720: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x15c720u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15c724: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15C724u;
    {
        const bool branch_taken_0x15c724 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C724u;
            // 0x15c728: 0xafa30028  sw          $v1, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c724) {
            ctx->pc = 0x15C744u;
            goto label_15c744;
        }
    }
    ctx->pc = 0x15C72Cu;
    // 0x15c72c: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x15c72cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x15c730: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x15C730u;
    {
        const bool branch_taken_0x15c730 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x15c730) {
            ctx->pc = 0x15C734u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15C730u;
            // 0x15c734: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x15C738u;
            goto label_15c738;
        }
    }
    ctx->pc = 0x15C738u;
label_15c738:
    // 0x15c738: 0x1010  mfhi        $v0
    ctx->pc = 0x15c738u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x15c73c: 0x821023  subu        $v0, $a0, $v0
    ctx->pc = 0x15c73cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x15c740: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x15c740u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_15c744:
    // 0x15c744: 0xc056f70  jal         func_15BDC0
    ctx->pc = 0x15C744u;
    SET_GPR_U32(ctx, 31, 0x15C74Cu);
    ctx->pc = 0x15C748u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C744u;
            // 0x15c748: 0x8ee40024  lw          $a0, 0x24($s7) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BDC0u;
    if (runtime->hasFunction(0x15BDC0u)) {
        auto targetFn = runtime->lookupFunction(0x15BDC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C74Cu; }
        if (ctx->pc != 0x15C74Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BDC0_0x15bdc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C74Cu; }
        if (ctx->pc != 0x15C74Cu) { return; }
    }
    ctx->pc = 0x15C74Cu;
label_15c74c:
    // 0x15c74c: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x15c74cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15c750: 0x27a60050  addiu       $a2, $sp, 0x50
    ctx->pc = 0x15c750u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x15c754: 0x27aa0060  addiu       $t2, $sp, 0x60
    ctx->pc = 0x15c754u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x15c758: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x15c758u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x15c75c: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x15c75cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x15c760: 0x8c68851c  lw          $t0, -0x7AE4($v1)
    ctx->pc = 0x15c760u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294935836)));
    // 0x15c764: 0x2664de08  addiu       $a0, $s3, -0x21F8
    ctx->pc = 0x15c764u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294958600));
    // 0x15c768: 0x8ca38520  lw          $v1, -0x7AE0($a1)
    ctx->pc = 0x15c768u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294935840)));
    // 0x15c76c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x15c76cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c770: 0x140302d  daddu       $a2, $t2, $zero
    ctx->pc = 0x15c770u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c774: 0x8faa00b8  lw          $t2, 0xB8($sp)
    ctx->pc = 0x15c774u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x15c778: 0x8fa900a0  lw          $t1, 0xA0($sp)
    ctx->pc = 0x15c778u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x15c77c: 0xafaa0004  sw          $t2, 0x4($sp)
    ctx->pc = 0x15c77cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 10));
    // 0x15c780: 0xafa70008  sw          $a3, 0x8($sp)
    ctx->pc = 0x15c780u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
    // 0x15c784: 0xafa8000c  sw          $t0, 0xC($sp)
    ctx->pc = 0x15c784u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 8));
    // 0x15c788: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x15c788u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x15c78c: 0x8fa700c4  lw          $a3, 0xC4($sp)
    ctx->pc = 0x15c78cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 196)));
    // 0x15c790: 0x8fa300c0  lw          $v1, 0xC0($sp)
    ctx->pc = 0x15c790u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x15c794: 0x8fa800c8  lw          $t0, 0xC8($sp)
    ctx->pc = 0x15c794u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x15c798: 0x8faa00cc  lw          $t2, 0xCC($sp)
    ctx->pc = 0x15c798u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 204)));
    // 0x15c79c: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x15c79cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    // 0x15c7a0: 0xafa3002c  sw          $v1, 0x2C($sp)
    ctx->pc = 0x15c7a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 3));
    // 0x15c7a4: 0xafa70030  sw          $a3, 0x30($sp)
    ctx->pc = 0x15c7a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 7));
    // 0x15c7a8: 0xafa80034  sw          $t0, 0x34($sp)
    ctx->pc = 0x15c7a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 8));
    // 0x15c7ac: 0xafaa003c  sw          $t2, 0x3C($sp)
    ctx->pc = 0x15c7acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 10));
    // 0x15c7b0: 0xc05af2a  jal         func_16BCA8
    ctx->pc = 0x15C7B0u;
    SET_GPR_U32(ctx, 31, 0x15C7B8u);
    ctx->pc = 0x15C7B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C7B0u;
            // 0x15c7b4: 0xafa90040  sw          $t1, 0x40($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BCA8u;
    if (runtime->hasFunction(0x16BCA8u)) {
        auto targetFn = runtime->lookupFunction(0x16BCA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7B8u; }
        if (ctx->pc != 0x15C7B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BCA8_0x16bca8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7B8u; }
        if (ctx->pc != 0x15C7B8u) { return; }
    }
    ctx->pc = 0x15C7B8u;
label_15c7b8:
    // 0x15c7b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15c7b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15c7bc: 0x17c20003  bne         $fp, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15C7BCu;
    {
        const bool branch_taken_0x15c7bc = (GPR_U64(ctx, 30) != GPR_U64(ctx, 2));
        if (branch_taken_0x15c7bc) {
            ctx->pc = 0x15C7CCu;
            goto label_15c7cc;
        }
    }
    ctx->pc = 0x15C7C4u;
    // 0x15c7c4: 0xc059240  jal         func_164900
    ctx->pc = 0x15C7C4u;
    SET_GPR_U32(ctx, 31, 0x15C7CCu);
    ctx->pc = 0x15C7C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C7C4u;
            // 0x15c7c8: 0x2684de30  addiu       $a0, $s4, -0x21D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294958640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164900u;
    if (runtime->hasFunction(0x164900u)) {
        auto targetFn = runtime->lookupFunction(0x164900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7CCu; }
        if (ctx->pc != 0x15C7CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164900_0x164900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7CCu; }
        if (ctx->pc != 0x15C7CCu) { return; }
    }
    ctx->pc = 0x15C7CCu;
label_15c7cc:
    // 0x15c7cc: 0xc05c548  jal         func_171520
    ctx->pc = 0x15C7CCu;
    SET_GPR_U32(ctx, 31, 0x15C7D4u);
    ctx->pc = 0x15C7D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C7CCu;
            // 0x15c7d0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171520u;
    if (runtime->hasFunction(0x171520u)) {
        auto targetFn = runtime->lookupFunction(0x171520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7D4u; }
        if (ctx->pc != 0x15C7D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171520_0x171520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7D4u; }
        if (ctx->pc != 0x15C7D4u) { return; }
    }
    ctx->pc = 0x15C7D4u;
label_15c7d4:
    // 0x15c7d4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15c7d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c7d8: 0xc05cd2e  jal         func_1734B8
    ctx->pc = 0x15C7D8u;
    SET_GPR_U32(ctx, 31, 0x15C7E0u);
    ctx->pc = 0x15C7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C7D8u;
            // 0x15c7dc: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1734B8u;
    if (runtime->hasFunction(0x1734B8u)) {
        auto targetFn = runtime->lookupFunction(0x1734B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7E0u; }
        if (ctx->pc != 0x15C7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001734B8_0x1734b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7E0u; }
        if (ctx->pc != 0x15C7E0u) { return; }
    }
    ctx->pc = 0x15C7E0u;
label_15c7e0:
    // 0x15c7e0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15c7e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c7e4: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15C7E4u;
    {
        const bool branch_taken_0x15c7e4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x15C7E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C7E4u;
            // 0x15c7e8: 0x3c050016  lui         $a1, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c7e4) {
            ctx->pc = 0x15C800u;
            goto label_15c800;
        }
    }
    ctx->pc = 0x15C7ECu;
    // 0x15c7ec: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15C7ECu;
    SET_GPR_U32(ctx, 31, 0x15C7F4u);
    ctx->pc = 0x15C7F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C7ECu;
            // 0x15c7f0: 0x2404fecf  addiu       $a0, $zero, -0x131 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966991));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7F4u; }
        if (ctx->pc != 0x15C7F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C7F4u; }
        if (ctx->pc != 0x15C7F4u) { return; }
    }
    ctx->pc = 0x15C7F4u;
label_15c7f4:
    // 0x15c7f4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c7f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15c7f8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x15C7F8u;
    {
        const bool branch_taken_0x15c7f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C7FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C7F8u;
            // 0x15c7fc: 0x2484e7b8  addiu       $a0, $a0, -0x1848 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961080));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c7f8) {
            ctx->pc = 0x15C828u;
            goto label_15c828;
        }
    }
    ctx->pc = 0x15C800u;
label_15c800:
    // 0x15c800: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15c800u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c804: 0x24a5ec08  addiu       $a1, $a1, -0x13F8
    ctx->pc = 0x15c804u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962184));
    // 0x15c808: 0xc05a730  jal         func_169CC0
    ctx->pc = 0x15C808u;
    SET_GPR_U32(ctx, 31, 0x15C810u);
    ctx->pc = 0x15C80Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C808u;
            // 0x15c80c: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169CC0u;
    if (runtime->hasFunction(0x169CC0u)) {
        auto targetFn = runtime->lookupFunction(0x169CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C810u; }
        if (ctx->pc != 0x15C810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169CC0_0x169cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C810u; }
        if (ctx->pc != 0x15C810u) { return; }
    }
    ctx->pc = 0x15C810u;
label_15c810:
    // 0x15c810: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x15C810u;
    {
        const bool branch_taken_0x15c810 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15c810) {
            ctx->pc = 0x15C814u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15C810u;
            // 0x15c814: 0x8fa200d4  lw          $v0, 0xD4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 212)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15C838u;
            goto label_15c838;
        }
    }
    ctx->pc = 0x15C818u;
    // 0x15c818: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15C818u;
    SET_GPR_U32(ctx, 31, 0x15C820u);
    ctx->pc = 0x15C81Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C818u;
            // 0x15c81c: 0x2404fed1  addiu       $a0, $zero, -0x12F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966993));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C820u; }
        if (ctx->pc != 0x15C820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C820u; }
        if (ctx->pc != 0x15C820u) { return; }
    }
    ctx->pc = 0x15C820u;
label_15c820:
    // 0x15c820: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c820u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15c824: 0x2484e7e8  addiu       $a0, $a0, -0x1818
    ctx->pc = 0x15c824u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961128));
label_15c828:
    // 0x15c828: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15C828u;
    SET_GPR_U32(ctx, 31, 0x15C830u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C830u; }
        if (ctx->pc != 0x15C830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C830u; }
        if (ctx->pc != 0x15C830u) { return; }
    }
    ctx->pc = 0x15C830u;
label_15c830:
    // 0x15c830: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x15C830u;
    {
        const bool branch_taken_0x15c830 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C830u;
            // 0x15c834: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c830) {
            ctx->pc = 0x15C85Cu;
            goto label_15c85c;
        }
    }
    ctx->pc = 0x15C838u;
label_15c838:
    // 0x15c838: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x15c838u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c83c: 0x24060800  addiu       $a2, $zero, 0x800
    ctx->pc = 0x15c83cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x15c840: 0x24070040  addiu       $a3, $zero, 0x40
    ctx->pc = 0x15c840u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x15c844: 0xaec20110  sw          $v0, 0x110($s6)
    ctx->pc = 0x15c844u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 272), GPR_U32(ctx, 2));
    // 0x15c848: 0x8fa300d0  lw          $v1, 0xD0($sp)
    ctx->pc = 0x15c848u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x15c84c: 0xaec30114  sw          $v1, 0x114($s6)
    ctx->pc = 0x15c84cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 276), GPR_U32(ctx, 3));
    // 0x15c850: 0xc057224  jal         func_15C890
    ctx->pc = 0x15C850u;
    SET_GPR_U32(ctx, 31, 0x15C858u);
    ctx->pc = 0x15C854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C850u;
            // 0x15c854: 0x8fa500bc  lw          $a1, 0xBC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C890u;
    if (runtime->hasFunction(0x15C890u)) {
        auto targetFn = runtime->lookupFunction(0x15C890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C858u; }
        if (ctx->pc != 0x15C858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015C890_0x15c890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C858u; }
        if (ctx->pc != 0x15C858u) { return; }
    }
    ctx->pc = 0x15C858u;
label_15c858:
    // 0x15c858: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15c858u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_15c85c:
    // 0x15c85c: 0xdfb000e0  ld          $s0, 0xE0($sp)
    ctx->pc = 0x15c85cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x15c860: 0xdfb100e8  ld          $s1, 0xE8($sp)
    ctx->pc = 0x15c860u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 232)));
    // 0x15c864: 0xdfb200f0  ld          $s2, 0xF0($sp)
    ctx->pc = 0x15c864u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x15c868: 0xdfb300f8  ld          $s3, 0xF8($sp)
    ctx->pc = 0x15c868u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 248)));
    // 0x15c86c: 0xdfb40100  ld          $s4, 0x100($sp)
    ctx->pc = 0x15c86cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x15c870: 0xdfb50108  ld          $s5, 0x108($sp)
    ctx->pc = 0x15c870u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 264)));
    // 0x15c874: 0xdfb60110  ld          $s6, 0x110($sp)
    ctx->pc = 0x15c874u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x15c878: 0xdfb70118  ld          $s7, 0x118($sp)
    ctx->pc = 0x15c878u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 280)));
    // 0x15c87c: 0xdfbe0120  ld          $fp, 0x120($sp)
    ctx->pc = 0x15c87cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x15c880: 0xdfbf0128  ld          $ra, 0x128($sp)
    ctx->pc = 0x15c880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 296)));
    // 0x15c884: 0x3e00008  jr          $ra
    ctx->pc = 0x15C884u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15C888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C884u;
            // 0x15c888: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15C2B0u: goto label_15c2b0;
            case 0x15C2C8u: goto label_15c2c8;
            case 0x15C2D8u: goto label_15c2d8;
            case 0x15C2E0u: goto label_15c2e0;
            case 0x15C304u: goto label_15c304;
            case 0x15C318u: goto label_15c318;
            case 0x15C330u: goto label_15c330;
            case 0x15C348u: goto label_15c348;
            case 0x15C358u: goto label_15c358;
            case 0x15C368u: goto label_15c368;
            case 0x15C378u: goto label_15c378;
            case 0x15C388u: goto label_15c388;
            case 0x15C398u: goto label_15c398;
            case 0x15C3A8u: goto label_15c3a8;
            case 0x15C3FCu: goto label_15c3fc;
            case 0x15C400u: goto label_15c400;
            case 0x15C408u: goto label_15c408;
            case 0x15C410u: goto label_15c410;
            case 0x15C418u: goto label_15c418;
            case 0x15C444u: goto label_15c444;
            case 0x15C4B8u: goto label_15c4b8;
            case 0x15C4C8u: goto label_15c4c8;
            case 0x15C4E0u: goto label_15c4e0;
            case 0x15C540u: goto label_15c540;
            case 0x15C544u: goto label_15c544;
            case 0x15C580u: goto label_15c580;
            case 0x15C598u: goto label_15c598;
            case 0x15C5F8u: goto label_15c5f8;
            case 0x15C5FCu: goto label_15c5fc;
            case 0x15C638u: goto label_15c638;
            case 0x15C650u: goto label_15c650;
            case 0x15C6B0u: goto label_15c6b0;
            case 0x15C6B4u: goto label_15c6b4;
            case 0x15C6ECu: goto label_15c6ec;
            case 0x15C718u: goto label_15c718;
            case 0x15C738u: goto label_15c738;
            case 0x15C744u: goto label_15c744;
            case 0x15C74Cu: goto label_15c74c;
            case 0x15C7B8u: goto label_15c7b8;
            case 0x15C7CCu: goto label_15c7cc;
            case 0x15C7D4u: goto label_15c7d4;
            case 0x15C7E0u: goto label_15c7e0;
            case 0x15C7F4u: goto label_15c7f4;
            case 0x15C800u: goto label_15c800;
            case 0x15C810u: goto label_15c810;
            case 0x15C820u: goto label_15c820;
            case 0x15C828u: goto label_15c828;
            case 0x15C830u: goto label_15c830;
            case 0x15C838u: goto label_15c838;
            case 0x15C858u: goto label_15c858;
            case 0x15C85Cu: goto label_15c85c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15C88Cu;
    // 0x15c88c: 0x0  nop
    ctx->pc = 0x15c88cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
