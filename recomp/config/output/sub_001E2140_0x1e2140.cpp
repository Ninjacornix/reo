#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E2140
// Address: 0x1e2140 - 0x1e2338
void sub_001E2140_0x1e2140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E2140_0x1e2140");
#endif

    switch (ctx->pc) {
        case 0x1e21f4u: goto label_1e21f4;
        case 0x1e2228u: goto label_1e2228;
        case 0x1e224cu: goto label_1e224c;
        case 0x1e22d4u: goto label_1e22d4;
        case 0x1e2304u: goto label_1e2304;
        default: break;
    }

    ctx->pc = 0x1e2140u;

    // 0x1e2140: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2144: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2148: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e214c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e214cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2150: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2150u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2154: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2154u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2158: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2158u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e215c: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e215cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e2160: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2160u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2164: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2168: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2168u;
    {
        const bool branch_taken_0x1e2168 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2168) {
            ctx->pc = 0x1E2190u;
            goto label_1e2190;
        }
    }
    ctx->pc = 0x1E2170u;
    // 0x1e2170: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2174: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2174u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2178: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2178u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e217c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e217cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2180: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2184: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2184u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2188: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2188u;
    {
        const bool branch_taken_0x1e2188 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2188) {
            ctx->pc = 0x1E21A4u;
            goto label_1e21a4;
        }
    }
    ctx->pc = 0x1E2190u;
label_1e2190:
    // 0x1e2190: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2194: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2194u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2198: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2198u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e219c: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E219Cu;
    {
        const bool branch_taken_0x1e219c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e219c) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E21A4u;
label_1e21a4:
    // 0x1e21a4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e21a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e21a8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e21a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e21ac: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e21acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e21b0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e21b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e21b4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e21b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e21b8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e21b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e21bc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e21bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e21c0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e21c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e21c4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e21c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e21c8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E21C8u;
    {
        const bool branch_taken_0x1e21c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e21c8) {
            ctx->pc = 0x1E21E4u;
            goto label_1e21e4;
        }
    }
    ctx->pc = 0x1E21D0u;
    // 0x1e21d0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e21d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e21d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e21d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e21d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e21d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e21dc: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E21DCu;
    {
        const bool branch_taken_0x1e21dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e21dc) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E21E4u;
label_1e21e4:
    // 0x1e21e4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e21e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e21e8: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e21e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e21ec: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E21ECu;
    SET_GPR_U32(ctx, 31, 0x1E21F4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E21F4u; }
        if (ctx->pc != 0x1E21F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E21F4u; }
        if (ctx->pc != 0x1E21F4u) { return; }
    }
    ctx->pc = 0x1E21F4u;
label_1e21f4:
    // 0x1e21f4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e21f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e21f8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e21f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e21fc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E21FCu;
    {
        const bool branch_taken_0x1e21fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e21fc) {
            ctx->pc = 0x1E2218u;
            goto label_1e2218;
        }
    }
    ctx->pc = 0x1E2204u;
    // 0x1e2204: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2208: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2208u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e220c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e220cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2210: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E2210u;
    {
        const bool branch_taken_0x1e2210 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2210) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E2218u;
label_1e2218:
    // 0x1e2218: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2218u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e221c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e221cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e2220: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2220u;
    SET_GPR_U32(ctx, 31, 0x1E2228u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2228u; }
        if (ctx->pc != 0x1E2228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2228u; }
        if (ctx->pc != 0x1E2228u) { return; }
    }
    ctx->pc = 0x1E2228u;
label_1e2228:
    // 0x1e2228: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2228u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e222c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e222cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2230: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2230u;
    {
        const bool branch_taken_0x1e2230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2230) {
            ctx->pc = 0x1E2260u;
            goto label_1e2260;
        }
    }
    ctx->pc = 0x1E2238u;
    // 0x1e2238: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2238u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e223c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e223cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2240: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e2240u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2244: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2244u;
    SET_GPR_U32(ctx, 31, 0x1E224Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E224Cu; }
        if (ctx->pc != 0x1E224Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E224Cu; }
        if (ctx->pc != 0x1E224Cu) { return; }
    }
    ctx->pc = 0x1E224Cu;
label_1e224c:
    // 0x1e224c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e224cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2250: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2250u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2254: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2254u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2258: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E2258u;
    {
        const bool branch_taken_0x1e2258 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2258) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E2260u;
label_1e2260:
    // 0x1e2260: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2260u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2264: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2268: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2268u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e226c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e226cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2270: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2270u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2274: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2274u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2278: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2278u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e227c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e227cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2280: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2280u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2284: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2284u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2288: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e228c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e228cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e2290: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2290u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2294: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2294u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2298: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2298u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e229c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e229cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e22a0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e22a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e22a4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e22a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e22a8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e22a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e22ac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e22acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e22b0: 0x90420615  lbu         $v0, 0x615($v0)
    ctx->pc = 0x1e22b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1557)));
    // 0x1e22b4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e22b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e22b8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e22b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e22bc: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e22bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e22c0: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e22c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e22c4: 0x24080005  addiu       $t0, $zero, 0x5
    ctx->pc = 0x1e22c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e22c8: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e22c8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e22cc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E22CCu;
    SET_GPR_U32(ctx, 31, 0x1E22D4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E22D4u; }
        if (ctx->pc != 0x1E22D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E22D4u; }
        if (ctx->pc != 0x1E22D4u) { return; }
    }
    ctx->pc = 0x1E22D4u;
label_1e22d4:
    // 0x1e22d4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E22D4u;
    {
        const bool branch_taken_0x1e22d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e22d4) {
            ctx->pc = 0x1E22F0u;
            goto label_1e22f0;
        }
    }
    ctx->pc = 0x1E22DCu;
    // 0x1e22dc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e22dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e22e0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e22e0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e22e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e22e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e22e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E22E8u;
    {
        const bool branch_taken_0x1e22e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e22e8) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E22F0u;
label_1e22f0:
    // 0x1e22f0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e22f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e22f4: 0x2405001e  addiu       $a1, $zero, 0x1E
    ctx->pc = 0x1e22f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1e22f8: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e22f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e22fc: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E22FCu;
    SET_GPR_U32(ctx, 31, 0x1E2304u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2304u; }
        if (ctx->pc != 0x1E2304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2304u; }
        if (ctx->pc != 0x1E2304u) { return; }
    }
    ctx->pc = 0x1E2304u;
label_1e2304:
    // 0x1e2304: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e2304u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2308: 0x90640615  lbu         $a0, 0x615($v1)
    ctx->pc = 0x1e2308u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1557)));
    // 0x1e230c: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e230cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2310: 0xa0620615  sb          $v0, 0x615($v1)
    ctx->pc = 0x1e2310u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1557), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2314: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2314u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2318: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2318u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e231c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e231cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e2320:
    // 0x1e2320: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2320u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2324: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2324u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2328: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e232c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e232cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2330: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2338u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
