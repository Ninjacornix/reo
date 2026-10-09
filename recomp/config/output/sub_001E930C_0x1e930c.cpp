#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E930C
// Address: 0x1e930c - 0x1e96b0
void sub_001E930C_0x1e930c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E930C_0x1e930c");
#endif

    switch (ctx->pc) {
        case 0x1e933cu: goto label_1e933c;
        case 0x1e934cu: goto label_1e934c;
        case 0x1e9364u: goto label_1e9364;
        case 0x1e9398u: goto label_1e9398;
        case 0x1e93ccu: goto label_1e93cc;
        case 0x1e93fcu: goto label_1e93fc;
        case 0x1e9450u: goto label_1e9450;
        case 0x1e9468u: goto label_1e9468;
        case 0x1e94c4u: goto label_1e94c4;
        case 0x1e94d4u: goto label_1e94d4;
        case 0x1e94ecu: goto label_1e94ec;
        case 0x1e9520u: goto label_1e9520;
        case 0x1e9588u: goto label_1e9588;
        case 0x1e95bcu: goto label_1e95bc;
        case 0x1e95e8u: goto label_1e95e8;
        case 0x1e95fcu: goto label_1e95fc;
        case 0x1e9610u: goto label_1e9610;
        case 0x1e9670u: goto label_1e9670;
        case 0x1e9684u: goto label_1e9684;
        default: break;
    }

    ctx->pc = 0x1e930cu;

    // 0x1e930c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e930cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e9310: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e9310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e9314: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e9314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e9318: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e9318u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e931c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e931cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e9320: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e9320u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e9324: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e9324u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e9328: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e9328u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e932c: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e932cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e9330: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1e9330u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1e9334: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9334u;
    SET_GPR_U32(ctx, 31, 0x1E933Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E933Cu; }
        if (ctx->pc != 0x1E933Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E933Cu; }
        if (ctx->pc != 0x1E933Cu) { return; }
    }
    ctx->pc = 0x1E933Cu;
label_1e933c:
    // 0x1e933c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e933cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e9340: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e9340u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e9344: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E9344u;
    SET_GPR_U32(ctx, 31, 0x1E934Cu);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E934Cu; }
        if (ctx->pc != 0x1E934Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E934Cu; }
        if (ctx->pc != 0x1E934Cu) { return; }
    }
    ctx->pc = 0x1E934Cu;
label_1e934c:
    // 0x1e934c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e934cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e9350: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9354: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9354u;
    {
        const bool branch_taken_0x1e9354 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9354) {
            ctx->pc = 0x1E937Cu;
            goto label_1e937c;
        }
    }
    ctx->pc = 0x1E935Cu;
    // 0x1e935c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E935Cu;
    SET_GPR_U32(ctx, 31, 0x1E9364u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9364u; }
        if (ctx->pc != 0x1E9364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9364u; }
        if (ctx->pc != 0x1E9364u) { return; }
    }
    ctx->pc = 0x1E9364u;
label_1e9364:
    // 0x1e9364: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9364u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9368: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e9368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e936c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e936cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9370: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9374: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E9374u;
    {
        const bool branch_taken_0x1e9374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9374) {
            ctx->pc = 0x1E9484u;
            goto label_1e9484;
        }
    }
    ctx->pc = 0x1E937Cu;
label_1e937c:
    // 0x1e937c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e937cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9380: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9380u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9384: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9384u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e9388: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9388u;
    {
        const bool branch_taken_0x1e9388 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9388) {
            ctx->pc = 0x1E93B0u;
            goto label_1e93b0;
        }
    }
    ctx->pc = 0x1E9390u;
    // 0x1e9390: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9390u;
    SET_GPR_U32(ctx, 31, 0x1E9398u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9398u; }
        if (ctx->pc != 0x1E9398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9398u; }
        if (ctx->pc != 0x1E9398u) { return; }
    }
    ctx->pc = 0x1E9398u;
label_1e9398:
    // 0x1e9398: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9398u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e939c: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e939cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e93a0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e93a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e93a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e93a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e93a8: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1E93A8u;
    {
        const bool branch_taken_0x1e93a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e93a8) {
            ctx->pc = 0x1E9484u;
            goto label_1e9484;
        }
    }
    ctx->pc = 0x1E93B0u;
label_1e93b0:
    // 0x1e93b0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e93b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e93b4: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e93b4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e93b8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e93b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e93bc: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E93BCu;
    {
        const bool branch_taken_0x1e93bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e93bc) {
            ctx->pc = 0x1E93E4u;
            goto label_1e93e4;
        }
    }
    ctx->pc = 0x1E93C4u;
    // 0x1e93c4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E93C4u;
    SET_GPR_U32(ctx, 31, 0x1E93CCu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E93CCu; }
        if (ctx->pc != 0x1E93CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E93CCu; }
        if (ctx->pc != 0x1E93CCu) { return; }
    }
    ctx->pc = 0x1E93CCu;
label_1e93cc:
    // 0x1e93cc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e93ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e93d0: 0x2402006b  addiu       $v0, $zero, 0x6B
    ctx->pc = 0x1e93d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1e93d4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e93d4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e93d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e93d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e93dc: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E93DCu;
    {
        const bool branch_taken_0x1e93dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e93dc) {
            ctx->pc = 0x1E9484u;
            goto label_1e9484;
        }
    }
    ctx->pc = 0x1E93E4u;
label_1e93e4:
    // 0x1e93e4: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e93e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e93e8: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1e93e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e93ec: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E93ECu;
    {
        const bool branch_taken_0x1e93ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e93ec) {
            ctx->pc = 0x1E9414u;
            goto label_1e9414;
        }
    }
    ctx->pc = 0x1E93F4u;
    // 0x1e93f4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E93F4u;
    SET_GPR_U32(ctx, 31, 0x1E93FCu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E93FCu; }
        if (ctx->pc != 0x1E93FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E93FCu; }
        if (ctx->pc != 0x1E93FCu) { return; }
    }
    ctx->pc = 0x1E93FCu;
label_1e93fc:
    // 0x1e93fc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e93fcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9400: 0x2402007d  addiu       $v0, $zero, 0x7D
    ctx->pc = 0x1e9400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 125));
    // 0x1e9404: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9404u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9408: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e940c: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1E940Cu;
    {
        const bool branch_taken_0x1e940c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e940c) {
            ctx->pc = 0x1E9484u;
            goto label_1e9484;
        }
    }
    ctx->pc = 0x1E9414u;
label_1e9414:
    // 0x1e9414: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9414u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9418: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e9418u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e941c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e941cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9420: 0x84440000  lh          $a0, 0x0($v0)
    ctx->pc = 0x1e9420u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e9424: 0x87c50008  lh          $a1, 0x8($fp)
    ctx->pc = 0x1e9424u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9428: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e9428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e942c: 0x88430007  lwl         $v1, 0x7($v0)
    ctx->pc = 0x1e942cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x1e9430: 0x98430004  lwr         $v1, 0x4($v0)
    ctx->pc = 0x1e9430u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x1e9434: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e9434u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e9438: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e9438u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e943c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e943cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9440: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e9440u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9444: 0x8fc80004  lw          $t0, 0x4($fp)
    ctx->pc = 0x1e9444u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9448: 0xc076114  jal         func_1D8450
    ctx->pc = 0x1E9448u;
    SET_GPR_U32(ctx, 31, 0x1E9450u);
    ctx->pc = 0x1D8450u;
    if (runtime->hasFunction(0x1D8450u)) {
        auto targetFn = runtime->lookupFunction(0x1D8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9450u; }
        if (ctx->pc != 0x1E9450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8450_0x1d8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9450u; }
        if (ctx->pc != 0x1E9450u) { return; }
    }
    ctx->pc = 0x1E9450u;
label_1e9450:
    // 0x1e9450: 0xa7c2001c  sh          $v0, 0x1C($fp)
    ctx->pc = 0x1e9450u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 28), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9454: 0x87c2001c  lh          $v0, 0x1C($fp)
    ctx->pc = 0x1e9454u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e9458: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9458u;
    {
        const bool branch_taken_0x1e9458 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9458) {
            ctx->pc = 0x1E9480u;
            goto label_1e9480;
        }
    }
    ctx->pc = 0x1E9460u;
    // 0x1e9460: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9460u;
    SET_GPR_U32(ctx, 31, 0x1E9468u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9468u; }
        if (ctx->pc != 0x1E9468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9468u; }
        if (ctx->pc != 0x1E9468u) { return; }
    }
    ctx->pc = 0x1E9468u;
label_1e9468:
    // 0x1e9468: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9468u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e946c: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e946cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e9470: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9470u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9474: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9478: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E9478u;
    {
        const bool branch_taken_0x1e9478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9478) {
            ctx->pc = 0x1E9484u;
            goto label_1e9484;
        }
    }
    ctx->pc = 0x1E9480u;
label_1e9480:
    // 0x1e9480: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e9480u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
label_1e9484:
    // 0x1e9484: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e9484u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9488: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e9488u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e948c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e948cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e9490: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e9490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e9494: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9494u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E933Cu: goto label_1e933c;
            case 0x1E934Cu: goto label_1e934c;
            case 0x1E9364u: goto label_1e9364;
            case 0x1E937Cu: goto label_1e937c;
            case 0x1E9398u: goto label_1e9398;
            case 0x1E93B0u: goto label_1e93b0;
            case 0x1E93CCu: goto label_1e93cc;
            case 0x1E93E4u: goto label_1e93e4;
            case 0x1E93FCu: goto label_1e93fc;
            case 0x1E9414u: goto label_1e9414;
            case 0x1E9450u: goto label_1e9450;
            case 0x1E9468u: goto label_1e9468;
            case 0x1E9480u: goto label_1e9480;
            case 0x1E9484u: goto label_1e9484;
            case 0x1E94C4u: goto label_1e94c4;
            case 0x1E94D4u: goto label_1e94d4;
            case 0x1E94ECu: goto label_1e94ec;
            case 0x1E9504u: goto label_1e9504;
            case 0x1E9520u: goto label_1e9520;
            case 0x1E9538u: goto label_1e9538;
            case 0x1E956Cu: goto label_1e956c;
            case 0x1E9588u: goto label_1e9588;
            case 0x1E95A8u: goto label_1e95a8;
            case 0x1E95BCu: goto label_1e95bc;
            case 0x1E95D4u: goto label_1e95d4;
            case 0x1E95E8u: goto label_1e95e8;
            case 0x1E95FCu: goto label_1e95fc;
            case 0x1E9604u: goto label_1e9604;
            case 0x1E9610u: goto label_1e9610;
            case 0x1E9650u: goto label_1e9650;
            case 0x1E9670u: goto label_1e9670;
            case 0x1E967Cu: goto label_1e967c;
            case 0x1E9684u: goto label_1e9684;
            case 0x1E9694u: goto label_1e9694;
            case 0x1E9698u: goto label_1e9698;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E949Cu;
    // 0x1e949c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e949cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e94a0: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e94a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e94a4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e94a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e94a8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e94a8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e94ac: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e94acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e94b0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e94b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e94b4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e94b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e94b8: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e94b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e94bc: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E94BCu;
    SET_GPR_U32(ctx, 31, 0x1E94C4u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E94C4u; }
        if (ctx->pc != 0x1E94C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E94C4u; }
        if (ctx->pc != 0x1E94C4u) { return; }
    }
    ctx->pc = 0x1E94C4u;
label_1e94c4:
    // 0x1e94c4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e94c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e94c8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e94c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e94cc: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E94CCu;
    SET_GPR_U32(ctx, 31, 0x1E94D4u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E94D4u; }
        if (ctx->pc != 0x1E94D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E94D4u; }
        if (ctx->pc != 0x1E94D4u) { return; }
    }
    ctx->pc = 0x1E94D4u;
label_1e94d4:
    // 0x1e94d4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e94d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e94d8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e94d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e94dc: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E94DCu;
    {
        const bool branch_taken_0x1e94dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e94dc) {
            ctx->pc = 0x1E9504u;
            goto label_1e9504;
        }
    }
    ctx->pc = 0x1E94E4u;
    // 0x1e94e4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E94E4u;
    SET_GPR_U32(ctx, 31, 0x1E94ECu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E94ECu; }
        if (ctx->pc != 0x1E94ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E94ECu; }
        if (ctx->pc != 0x1E94ECu) { return; }
    }
    ctx->pc = 0x1E94ECu;
label_1e94ec:
    // 0x1e94ec: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e94ecu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e94f0: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e94f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e94f4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e94f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e94f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e94f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e94fc: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1E94FCu;
    {
        const bool branch_taken_0x1e94fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e94fc) {
            ctx->pc = 0x1E9698u;
            goto label_1e9698;
        }
    }
    ctx->pc = 0x1E9504u;
label_1e9504:
    // 0x1e9504: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9508: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9508u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e950c: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e950cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e9510: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9510u;
    {
        const bool branch_taken_0x1e9510 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e9510) {
            ctx->pc = 0x1E9538u;
            goto label_1e9538;
        }
    }
    ctx->pc = 0x1E9518u;
    // 0x1e9518: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9518u;
    SET_GPR_U32(ctx, 31, 0x1E9520u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9520u; }
        if (ctx->pc != 0x1E9520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9520u; }
        if (ctx->pc != 0x1E9520u) { return; }
    }
    ctx->pc = 0x1E9520u;
label_1e9520:
    // 0x1e9520: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9520u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9524: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e9524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e9528: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9528u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e952c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e952cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9530: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x1E9530u;
    {
        const bool branch_taken_0x1e9530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9530) {
            ctx->pc = 0x1E9698u;
            goto label_1e9698;
        }
    }
    ctx->pc = 0x1E9538u;
label_1e9538:
    // 0x1e9538: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9538u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e953c: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e953cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e9540: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9540u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e9544: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9548: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e9548u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e954c: 0x1062002d  beq         $v1, $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1E954Cu;
    {
        const bool branch_taken_0x1e954c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e954c) {
            ctx->pc = 0x1E9604u;
            goto label_1e9604;
        }
    }
    ctx->pc = 0x1E9554u;
    // 0x1e9554: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e9554u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e9558: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e9558u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e955c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E955Cu;
    {
        const bool branch_taken_0x1e955c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e955c) {
            ctx->pc = 0x1E956Cu;
            goto label_1e956c;
        }
    }
    ctx->pc = 0x1E9564u;
    // 0x1e9564: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x1E9564u;
    {
        const bool branch_taken_0x1e9564 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9564) {
            ctx->pc = 0x1E967Cu;
            goto label_1e967c;
        }
    }
    ctx->pc = 0x1E956Cu;
label_1e956c:
    // 0x1e956c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e956cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9570: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e9570u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e9574: 0x27c30018  addiu       $v1, $fp, 0x18
    ctx->pc = 0x1e9574u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e9578: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9578u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e957c: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e957cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9580: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1E9580u;
    SET_GPR_U32(ctx, 31, 0x1E9588u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9588u; }
        if (ctx->pc != 0x1E9588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9588u; }
        if (ctx->pc != 0x1E9588u) { return; }
    }
    ctx->pc = 0x1E9588u;
label_1e9588:
    // 0x1e9588: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e9588u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e958c: 0x87c30014  lh          $v1, 0x14($fp)
    ctx->pc = 0x1e958cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9590: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1e9590u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1e9594: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E9594u;
    {
        const bool branch_taken_0x1e9594 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e9594) {
            ctx->pc = 0x1E95A8u;
            goto label_1e95a8;
        }
    }
    ctx->pc = 0x1E959Cu;
    // 0x1e959c: 0xa7c00014  sh          $zero, 0x14($fp)
    ctx->pc = 0x1e959cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 0));
    // 0x1e95a0: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1E95A0u;
    {
        const bool branch_taken_0x1e95a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e95a0) {
            ctx->pc = 0x1E9694u;
            goto label_1e9694;
        }
    }
    ctx->pc = 0x1E95A8u;
label_1e95a8:
    // 0x1e95a8: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e95a8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e95ac: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E95ACu;
    {
        const bool branch_taken_0x1e95ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e95ac) {
            ctx->pc = 0x1E95D4u;
            goto label_1e95d4;
        }
    }
    ctx->pc = 0x1E95B4u;
    // 0x1e95b4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E95B4u;
    SET_GPR_U32(ctx, 31, 0x1E95BCu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E95BCu; }
        if (ctx->pc != 0x1E95BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E95BCu; }
        if (ctx->pc != 0x1E95BCu) { return; }
    }
    ctx->pc = 0x1E95BCu;
label_1e95bc:
    // 0x1e95bc: 0x87c30014  lh          $v1, 0x14($fp)
    ctx->pc = 0x1e95bcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e95c0: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e95c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e95c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e95c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e95c8: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e95c8u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e95cc: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E95CCu;
    {
        const bool branch_taken_0x1e95cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e95cc) {
            ctx->pc = 0x1E9694u;
            goto label_1e9694;
        }
    }
    ctx->pc = 0x1E95D4u;
label_1e95d4:
    // 0x1e95d4: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e95d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e95d8: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e95d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e95dc: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e95dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e95e0: 0xc07cd84  jal         func_1F3610
    ctx->pc = 0x1E95E0u;
    SET_GPR_U32(ctx, 31, 0x1E95E8u);
    ctx->pc = 0x1F3610u;
    if (runtime->hasFunction(0x1F3610u)) {
        auto targetFn = runtime->lookupFunction(0x1F3610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E95E8u; }
        if (ctx->pc != 0x1E95E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3610_0x1f3610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E95E8u; }
        if (ctx->pc != 0x1E95E8u) { return; }
    }
    ctx->pc = 0x1E95E8u;
label_1e95e8:
    // 0x1e95e8: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e95e8u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e95ec: 0x8f84802c  lw          $a0, -0x7FD4($gp)
    ctx->pc = 0x1e95ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934572)));
    // 0x1e95f0: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e95f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e95f4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E95F4u;
    SET_GPR_U32(ctx, 31, 0x1E95FCu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E95FCu; }
        if (ctx->pc != 0x1E95FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E95FCu; }
        if (ctx->pc != 0x1E95FCu) { return; }
    }
    ctx->pc = 0x1E95FCu;
label_1e95fc:
    // 0x1e95fc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1E95FCu;
    {
        const bool branch_taken_0x1e95fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e95fc) {
            ctx->pc = 0x1E9694u;
            goto label_1e9694;
        }
    }
    ctx->pc = 0x1E9604u;
label_1e9604:
    // 0x1e9604: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e9604u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9608: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E9608u;
    SET_GPR_U32(ctx, 31, 0x1E9610u);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9610u; }
        if (ctx->pc != 0x1E9610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9610u; }
        if (ctx->pc != 0x1E9610u) { return; }
    }
    ctx->pc = 0x1E9610u;
label_1e9610:
    // 0x1e9610: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e9610u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9614: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e9614u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9618: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1E9618u;
    {
        const bool branch_taken_0x1e9618 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9618) {
            ctx->pc = 0x1E9694u;
            goto label_1e9694;
        }
    }
    ctx->pc = 0x1E9620u;
    // 0x1e9620: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9624: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9624u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9628: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e962c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1E962Cu;
    {
        const bool branch_taken_0x1e962c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e962c) {
            ctx->pc = 0x1E9650u;
            goto label_1e9650;
        }
    }
    ctx->pc = 0x1E9634u;
    // 0x1e9634: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9634u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9638: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9638u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e963c: 0x24020ff4  addiu       $v0, $zero, 0xFF4
    ctx->pc = 0x1e963cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4084));
    // 0x1e9640: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E9640u;
    {
        const bool branch_taken_0x1e9640 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9640) {
            ctx->pc = 0x1E9650u;
            goto label_1e9650;
        }
    }
    ctx->pc = 0x1E9648u;
    // 0x1e9648: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1E9648u;
    {
        const bool branch_taken_0x1e9648 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9648) {
            ctx->pc = 0x1E9694u;
            goto label_1e9694;
        }
    }
    ctx->pc = 0x1E9650u;
label_1e9650:
    // 0x1e9650: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9654: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1e9654u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e9658: 0x87c30008  lh          $v1, 0x8($fp)
    ctx->pc = 0x1e9658u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e965c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e965cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9660: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e9660u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9664: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e9664u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9668: 0xc07601c  jal         func_1D8070
    ctx->pc = 0x1E9668u;
    SET_GPR_U32(ctx, 31, 0x1E9670u);
    ctx->pc = 0x1D8070u;
    if (runtime->hasFunction(0x1D8070u)) {
        auto targetFn = runtime->lookupFunction(0x1D8070u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9670u; }
        if (ctx->pc != 0x1E9670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8070_0x1d8070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9670u; }
        if (ctx->pc != 0x1E9670u) { return; }
    }
    ctx->pc = 0x1E9670u;
label_1e9670:
    // 0x1e9670: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e9670u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9674: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E9674u;
    {
        const bool branch_taken_0x1e9674 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9674) {
            ctx->pc = 0x1E9694u;
            goto label_1e9694;
        }
    }
    ctx->pc = 0x1E967Cu;
label_1e967c:
    // 0x1e967c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E967Cu;
    SET_GPR_U32(ctx, 31, 0x1E9684u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9684u; }
        if (ctx->pc != 0x1E9684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9684u; }
        if (ctx->pc != 0x1E9684u) { return; }
    }
    ctx->pc = 0x1E9684u;
label_1e9684:
    // 0x1e9684: 0x2403006b  addiu       $v1, $zero, 0x6B
    ctx->pc = 0x1e9684u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1e9688: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e9688u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e968c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e968cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9690: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e9690u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
label_1e9694:
    // 0x1e9694: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e9694u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
label_1e9698:
    // 0x1e9698: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e9698u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e969c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e969cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e96a0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e96a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e96a4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e96a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e96a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E96A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E933Cu: goto label_1e933c;
            case 0x1E934Cu: goto label_1e934c;
            case 0x1E9364u: goto label_1e9364;
            case 0x1E937Cu: goto label_1e937c;
            case 0x1E9398u: goto label_1e9398;
            case 0x1E93B0u: goto label_1e93b0;
            case 0x1E93CCu: goto label_1e93cc;
            case 0x1E93E4u: goto label_1e93e4;
            case 0x1E93FCu: goto label_1e93fc;
            case 0x1E9414u: goto label_1e9414;
            case 0x1E9450u: goto label_1e9450;
            case 0x1E9468u: goto label_1e9468;
            case 0x1E9480u: goto label_1e9480;
            case 0x1E9484u: goto label_1e9484;
            case 0x1E94C4u: goto label_1e94c4;
            case 0x1E94D4u: goto label_1e94d4;
            case 0x1E94ECu: goto label_1e94ec;
            case 0x1E9504u: goto label_1e9504;
            case 0x1E9520u: goto label_1e9520;
            case 0x1E9538u: goto label_1e9538;
            case 0x1E956Cu: goto label_1e956c;
            case 0x1E9588u: goto label_1e9588;
            case 0x1E95A8u: goto label_1e95a8;
            case 0x1E95BCu: goto label_1e95bc;
            case 0x1E95D4u: goto label_1e95d4;
            case 0x1E95E8u: goto label_1e95e8;
            case 0x1E95FCu: goto label_1e95fc;
            case 0x1E9604u: goto label_1e9604;
            case 0x1E9610u: goto label_1e9610;
            case 0x1E9650u: goto label_1e9650;
            case 0x1E9670u: goto label_1e9670;
            case 0x1E967Cu: goto label_1e967c;
            case 0x1E9684u: goto label_1e9684;
            case 0x1E9694u: goto label_1e9694;
            case 0x1E9698u: goto label_1e9698;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E96B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
