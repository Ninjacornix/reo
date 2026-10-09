#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E896C
// Address: 0x1e896c - 0x1e8aac
void sub_001E896C_0x1e896c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E896C_0x1e896c");
#endif

    switch (ctx->pc) {
        case 0x1e8990u: goto label_1e8990;
        case 0x1e89a8u: goto label_1e89a8;
        case 0x1e89c0u: goto label_1e89c0;
        case 0x1e89f4u: goto label_1e89f4;
        case 0x1e8a28u: goto label_1e8a28;
        case 0x1e8a68u: goto label_1e8a68;
        default: break;
    }

    ctx->pc = 0x1e896cu;

    // 0x1e896c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e896cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e8970: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e8970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e8974: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e8974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e8978: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8978u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e897c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e897cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8980: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e8980u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e8984: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e8984u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e8988: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8988u;
    SET_GPR_U32(ctx, 31, 0x1E8990u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8990u; }
        if (ctx->pc != 0x1E8990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8990u; }
        if (ctx->pc != 0x1E8990u) { return; }
    }
    ctx->pc = 0x1E8990u;
label_1e8990:
    // 0x1e8990: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e8990u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e8994: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e8994u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8998: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e8998u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e899c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e899cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e89a0: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E89A0u;
    SET_GPR_U32(ctx, 31, 0x1E89A8u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89A8u; }
        if (ctx->pc != 0x1E89A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89A8u; }
        if (ctx->pc != 0x1E89A8u) { return; }
    }
    ctx->pc = 0x1E89A8u;
label_1e89a8:
    // 0x1e89a8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e89a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e89ac: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e89acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e89b0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E89B0u;
    {
        const bool branch_taken_0x1e89b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e89b0) {
            ctx->pc = 0x1E89D8u;
            goto label_1e89d8;
        }
    }
    ctx->pc = 0x1E89B8u;
    // 0x1e89b8: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E89B8u;
    SET_GPR_U32(ctx, 31, 0x1E89C0u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89C0u; }
        if (ctx->pc != 0x1E89C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89C0u; }
        if (ctx->pc != 0x1E89C0u) { return; }
    }
    ctx->pc = 0x1E89C0u;
label_1e89c0:
    // 0x1e89c0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e89c0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e89c4: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e89c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e89c8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e89c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e89cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e89ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e89d0: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1E89D0u;
    {
        const bool branch_taken_0x1e89d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e89d0) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E89D8u;
label_1e89d8:
    // 0x1e89d8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e89d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e89dc: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e89dcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e89e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e89e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e89e4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E89E4u;
    {
        const bool branch_taken_0x1e89e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e89e4) {
            ctx->pc = 0x1E8A0Cu;
            goto label_1e8a0c;
        }
    }
    ctx->pc = 0x1E89ECu;
    // 0x1e89ec: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E89ECu;
    SET_GPR_U32(ctx, 31, 0x1E89F4u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89F4u; }
        if (ctx->pc != 0x1E89F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89F4u; }
        if (ctx->pc != 0x1E89F4u) { return; }
    }
    ctx->pc = 0x1E89F4u;
label_1e89f4:
    // 0x1e89f4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e89f4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e89f8: 0x2402006d  addiu       $v0, $zero, 0x6D
    ctx->pc = 0x1e89f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
    // 0x1e89fc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e89fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8a00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8a00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8a04: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E8A04u;
    {
        const bool branch_taken_0x1e8a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8a04) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E8A0Cu;
label_1e8a0c:
    // 0x1e8a0c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e8a0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8a10: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e8a10u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e8a14: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e8a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e8a18: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8A18u;
    {
        const bool branch_taken_0x1e8a18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8a18) {
            ctx->pc = 0x1E8A40u;
            goto label_1e8a40;
        }
    }
    ctx->pc = 0x1E8A20u;
    // 0x1e8a20: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8A20u;
    SET_GPR_U32(ctx, 31, 0x1E8A28u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A28u; }
        if (ctx->pc != 0x1E8A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A28u; }
        if (ctx->pc != 0x1E8A28u) { return; }
    }
    ctx->pc = 0x1E8A28u;
label_1e8a28:
    // 0x1e8a28: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8a28u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a2c: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8a30: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8a30u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8a34: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8a34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8a38: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1E8A38u;
    {
        const bool branch_taken_0x1e8a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8a38) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E8A40u;
label_1e8a40:
    // 0x1e8a40: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e8a40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8a44: 0x88430007  lwl         $v1, 0x7($v0)
    ctx->pc = 0x1e8a44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x1e8a48: 0x98430004  lwr         $v1, 0x4($v0)
    ctx->pc = 0x1e8a48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x1e8a4c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e8a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8a50: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e8a50u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e8a54: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1e8a54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a58: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e8a58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a5c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1e8a5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a60: 0xc075ec0  jal         func_1D7B00
    ctx->pc = 0x1E8A60u;
    SET_GPR_U32(ctx, 31, 0x1E8A68u);
    ctx->pc = 0x1D7B00u;
    if (runtime->hasFunction(0x1D7B00u)) {
        auto targetFn = runtime->lookupFunction(0x1D7B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A68u; }
        if (ctx->pc != 0x1E8A68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7B00_0x1d7b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A68u; }
        if (ctx->pc != 0x1E8A68u) { return; }
    }
    ctx->pc = 0x1E8A68u;
label_1e8a68:
    // 0x1e8a68: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e8a68u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8a6c: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1e8a6cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8a70: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E8A70u;
    {
        const bool branch_taken_0x1e8a70 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e8a70) {
            ctx->pc = 0x1E8A84u;
            goto label_1e8a84;
        }
    }
    ctx->pc = 0x1E8A78u;
    // 0x1e8a78: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1e8a78u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8a7c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1E8A7Cu;
    {
        const bool branch_taken_0x1e8a7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8a7c) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E8A84u;
label_1e8a84:
    // 0x1e8a84: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e8a84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8a88: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e8a88u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8a8c: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e8a8cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8a90: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e8a90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e8a94:
    // 0x1e8a94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8a94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a98: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e8a98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e8a9c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e8a9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e8aa0: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e8aa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e8aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E8990u: goto label_1e8990;
            case 0x1E89A8u: goto label_1e89a8;
            case 0x1E89C0u: goto label_1e89c0;
            case 0x1E89D8u: goto label_1e89d8;
            case 0x1E89F4u: goto label_1e89f4;
            case 0x1E8A0Cu: goto label_1e8a0c;
            case 0x1E8A28u: goto label_1e8a28;
            case 0x1E8A40u: goto label_1e8a40;
            case 0x1E8A68u: goto label_1e8a68;
            case 0x1E8A84u: goto label_1e8a84;
            case 0x1E8A94u: goto label_1e8a94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8AACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
