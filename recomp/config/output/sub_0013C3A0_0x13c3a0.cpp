#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C3A0
// Address: 0x13c3a0 - 0x13c590
void sub_0013C3A0_0x13c3a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C3A0_0x13c3a0");
#endif

    switch (ctx->pc) {
        case 0x13c3f0u: goto label_13c3f0;
        case 0x13c410u: goto label_13c410;
        case 0x13c43cu: goto label_13c43c;
        case 0x13c450u: goto label_13c450;
        case 0x13c45cu: goto label_13c45c;
        case 0x13c468u: goto label_13c468;
        case 0x13c490u: goto label_13c490;
        case 0x13c4a4u: goto label_13c4a4;
        case 0x13c4d0u: goto label_13c4d0;
        case 0x13c4d8u: goto label_13c4d8;
        case 0x13c4e0u: goto label_13c4e0;
        case 0x13c4e8u: goto label_13c4e8;
        case 0x13c4f0u: goto label_13c4f0;
        case 0x13c500u: goto label_13c500;
        case 0x13c508u: goto label_13c508;
        case 0x13c534u: goto label_13c534;
        case 0x13c558u: goto label_13c558;
        default: break;
    }

    ctx->pc = 0x13c3a0u;

    // 0x13c3a0: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x13c3a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x13c3a4: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x13c3a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x13c3a8: 0xffb40120  sd          $s4, 0x120($sp)
    ctx->pc = 0x13c3a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 20));
    // 0x13c3ac: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x13c3acu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c3b0: 0xffb50128  sd          $s5, 0x128($sp)
    ctx->pc = 0x13c3b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 296), GPR_U64(ctx, 21));
    // 0x13c3b4: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x13c3b4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c3b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c3b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c3bc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13c3bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c3c0: 0xffb30118  sd          $s3, 0x118($sp)
    ctx->pc = 0x13c3c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 280), GPR_U64(ctx, 19));
    // 0x13c3c4: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x13c3c4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c3c8: 0xffb60130  sd          $s6, 0x130($sp)
    ctx->pc = 0x13c3c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 22));
    // 0x13c3cc: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x13c3ccu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c3d0: 0xffbe0140  sd          $fp, 0x140($sp)
    ctx->pc = 0x13c3d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 320), GPR_U64(ctx, 30));
    // 0x13c3d4: 0xffb00100  sd          $s0, 0x100($sp)
    ctx->pc = 0x13c3d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 256), GPR_U64(ctx, 16));
    // 0x13c3d8: 0xffb10108  sd          $s1, 0x108($sp)
    ctx->pc = 0x13c3d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 264), GPR_U64(ctx, 17));
    // 0x13c3dc: 0xffb20110  sd          $s2, 0x110($sp)
    ctx->pc = 0x13c3dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 18));
    // 0x13c3e0: 0xffb70138  sd          $s7, 0x138($sp)
    ctx->pc = 0x13c3e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 312), GPR_U64(ctx, 23));
    // 0x13c3e4: 0xffbf0148  sd          $ra, 0x148($sp)
    ctx->pc = 0x13c3e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 328), GPR_U64(ctx, 31));
    // 0x13c3e8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13C3E8u;
    SET_GPR_U32(ctx, 31, 0x13C3F0u);
    ctx->pc = 0x13C3ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C3E8u;
            // 0x13c3ec: 0xf02d  daddu       $fp, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C3F0u; }
        if (ctx->pc != 0x13C3F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C3F0u; }
        if (ctx->pc != 0x13C3F0u) { return; }
    }
    ctx->pc = 0x13C3F0u;
label_13c3f0:
    // 0x13c3f0: 0x2a83000e  slti        $v1, $s4, 0xE
    ctx->pc = 0x13c3f0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)14) ? 1 : 0);
    // 0x13c3f4: 0x2402000d  addiu       $v0, $zero, 0xD
    ctx->pc = 0x13c3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x13c3f8: 0x43a00a  movz        $s4, $v0, $v1
    ctx->pc = 0x13c3f8u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 2));
    // 0x13c3fc: 0x1a800046  blez        $s4, . + 4 + (0x46 << 2)
    ctx->pc = 0x13C3FCu;
    {
        const bool branch_taken_0x13c3fc = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x13C400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C3FCu;
            // 0x13c400: 0x3c030022  lui         $v1, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c3fc) {
            ctx->pc = 0x13C518u;
            goto label_13c518;
        }
    }
    ctx->pc = 0x13C404u;
    // 0x13c404: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c404u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c408: 0x2a0902d  daddu       $s2, $s5, $zero
    ctx->pc = 0x13c408u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c40c: 0x2457de90  addiu       $s7, $v0, -0x2170
    ctx->pc = 0x13c40cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958736));
label_13c410:
    // 0x13c410: 0x8ee3000c  lw          $v1, 0xC($s7)
    ctx->pc = 0x13c410u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 12)));
    // 0x13c414: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13c414u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c418: 0x8ee20008  lw          $v0, 0x8($s7)
    ctx->pc = 0x13c418u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 8)));
    // 0x13c41c: 0x732018  mult        $a0, $v1, $s3
    ctx->pc = 0x13c41cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 19); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x13c420: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x13c420u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x13c424: 0x931821  addu        $v1, $a0, $s3
    ctx->pc = 0x13c424u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x13c428: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x13c428u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x13c42c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13c42cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13c430: 0x2a28821  addu        $s1, $s5, $v0
    ctx->pc = 0x13c430u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x13c434: 0xc04efa0  jal         func_13BE80
    ctx->pc = 0x13C434u;
    SET_GPR_U32(ctx, 31, 0x13C43Cu);
    ctx->pc = 0x13C438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C434u;
            // 0x13c438: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BE80u;
    if (runtime->hasFunction(0x13BE80u)) {
        auto targetFn = runtime->lookupFunction(0x13BE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C43Cu; }
        if (ctx->pc != 0x13C43Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE80_0x13be80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C43Cu; }
        if (ctx->pc != 0x13C43Cu) { return; }
    }
    ctx->pc = 0x13C43Cu;
label_13c43c:
    // 0x13c43c: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x13c43cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13c440: 0x10400031  beqz        $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x13C440u;
    {
        const bool branch_taken_0x13c440 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C440u;
            // 0x13c444: 0x24046600  addiu       $a0, $zero, 0x6600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c440) {
            ctx->pc = 0x13C508u;
            goto label_13c508;
        }
    }
    ctx->pc = 0x13C448u;
    // 0x13c448: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C448u;
    SET_GPR_U32(ctx, 31, 0x13C450u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C450u; }
        if (ctx->pc != 0x13C450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C450u; }
        if (ctx->pc != 0x13C450u) { return; }
    }
    ctx->pc = 0x13C450u;
label_13c450:
    // 0x13c450: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x13c450u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13c454: 0xc04e146  jal         func_138518
    ctx->pc = 0x13C454u;
    SET_GPR_U32(ctx, 31, 0x13C45Cu);
    ctx->pc = 0x13C458u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C454u;
            // 0x13c458: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138518u;
    if (runtime->hasFunction(0x138518u)) {
        auto targetFn = runtime->lookupFunction(0x138518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C45Cu; }
        if (ctx->pc != 0x13C45Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138518_0x138518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C45Cu; }
        if (ctx->pc != 0x13C45Cu) { return; }
    }
    ctx->pc = 0x13C45Cu;
label_13c45c:
    // 0x13c45c: 0x24046601  addiu       $a0, $zero, 0x6601
    ctx->pc = 0x13c45cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26113));
    // 0x13c460: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C460u;
    SET_GPR_U32(ctx, 31, 0x13C468u);
    ctx->pc = 0x13C464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C460u;
            // 0x13c464: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C468u; }
        if (ctx->pc != 0x13C468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C468u; }
        if (ctx->pc != 0x13C468u) { return; }
    }
    ctx->pc = 0x13C468u;
label_13c468:
    // 0x13c468: 0x601000b  bgez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x13C468u;
    {
        const bool branch_taken_0x13c468 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x13C46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C468u;
            // 0x13c46c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c468) {
            ctx->pc = 0x13C498u;
            goto label_13c498;
        }
    }
    ctx->pc = 0x13C470u;
    // 0x13c470: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13c470u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13c474: 0x8c62dea4  lw          $v0, -0x215C($v1)
    ctx->pc = 0x13c474u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294958756)));
    // 0x13c478: 0x54400023  bnel        $v0, $zero, . + 4 + (0x23 << 2)
    ctx->pc = 0x13C478u;
    {
        const bool branch_taken_0x13c478 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13c478) {
            ctx->pc = 0x13C47Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13C478u;
            // 0x13c47c: 0x27de0001  addiu       $fp, $fp, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13C508u;
            goto label_13c508;
        }
    }
    ctx->pc = 0x13C480u;
    // 0x13c480: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x13c480u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x13c484: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13c484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c488: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C488u;
    SET_GPR_U32(ctx, 31, 0x13C490u);
    ctx->pc = 0x13C48Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C488u;
            // 0x13c48c: 0x2444d158  addiu       $a0, $v0, -0x2EA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C490u; }
        if (ctx->pc != 0x13C490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C490u; }
        if (ctx->pc != 0x13C490u) { return; }
    }
    ctx->pc = 0x13C490u;
label_13c490:
    // 0x13c490: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x13C490u;
    {
        const bool branch_taken_0x13c490 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C490u;
            // 0x13c494: 0x27de0001  addiu       $fp, $fp, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c490) {
            ctx->pc = 0x13C508u;
            goto label_13c508;
        }
    }
    ctx->pc = 0x13C498u;
label_13c498:
    // 0x13c498: 0xae500000  sw          $s0, 0x0($s2)
    ctx->pc = 0x13c498u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 16));
    // 0x13c49c: 0xc04ed4a  jal         func_13B528
    ctx->pc = 0x13C49Cu;
    SET_GPR_U32(ctx, 31, 0x13C4A4u);
    ctx->pc = 0x13C4A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C49Cu;
            // 0x13c4a0: 0x26d60001  addiu       $s6, $s6, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13B528u;
    if (runtime->hasFunction(0x13B528u)) {
        auto targetFn = runtime->lookupFunction(0x13B528u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4A4u; }
        if (ctx->pc != 0x13C4A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B528_0x13b528(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4A4u; }
        if (ctx->pc != 0x13C4A4u) { return; }
    }
    ctx->pc = 0x13C4A4u;
label_13c4a4:
    // 0x13c4a4: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x13c4a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x13c4a8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x13c4a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x13c4ac: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x13c4acu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x13c4b0: 0x2464d180  addiu       $a0, $v1, -0x2E80
    ctx->pc = 0x13c4b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294955392));
    // 0x13c4b4: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x13c4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x13c4b8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13c4b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13c4bc: 0x8c62dea4  lw          $v0, -0x215C($v1)
    ctx->pc = 0x13c4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294958756)));
    // 0x13c4c0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13C4C0u;
    {
        const bool branch_taken_0x13c4c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C4C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C4C0u;
            // 0x13c4c4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c4c0) {
            ctx->pc = 0x13C4D0u;
            goto label_13c4d0;
        }
    }
    ctx->pc = 0x13C4C8u;
    // 0x13c4c8: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C4C8u;
    SET_GPR_U32(ctx, 31, 0x13C4D0u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4D0u; }
        if (ctx->pc != 0x13C4D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4D0u; }
        if (ctx->pc != 0x13C4D0u) { return; }
    }
    ctx->pc = 0x13C4D0u;
label_13c4d0:
    // 0x13c4d0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C4D0u;
    SET_GPR_U32(ctx, 31, 0x13C4D8u);
    ctx->pc = 0x13C4D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C4D0u;
            // 0x13c4d4: 0x24046800  addiu       $a0, $zero, 0x6800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4D8u; }
        if (ctx->pc != 0x13C4D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4D8u; }
        if (ctx->pc != 0x13C4D8u) { return; }
    }
    ctx->pc = 0x13C4D8u;
label_13c4d8:
    // 0x13c4d8: 0xc04e160  jal         func_138580
    ctx->pc = 0x13C4D8u;
    SET_GPR_U32(ctx, 31, 0x13C4E0u);
    ctx->pc = 0x13C4DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C4D8u;
            // 0x13c4dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4E0u; }
        if (ctx->pc != 0x13C4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4E0u; }
        if (ctx->pc != 0x13C4E0u) { return; }
    }
    ctx->pc = 0x13C4E0u;
label_13c4e0:
    // 0x13c4e0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C4E0u;
    SET_GPR_U32(ctx, 31, 0x13C4E8u);
    ctx->pc = 0x13C4E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C4E0u;
            // 0x13c4e4: 0x24046801  addiu       $a0, $zero, 0x6801 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26625));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4E8u; }
        if (ctx->pc != 0x13C4E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4E8u; }
        if (ctx->pc != 0x13C4E8u) { return; }
    }
    ctx->pc = 0x13C4E8u;
label_13c4e8:
    // 0x13c4e8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C4E8u;
    SET_GPR_U32(ctx, 31, 0x13C4F0u);
    ctx->pc = 0x13C4ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C4E8u;
            // 0x13c4ec: 0x24046700  addiu       $a0, $zero, 0x6700 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4F0u; }
        if (ctx->pc != 0x13C4F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C4F0u; }
        if (ctx->pc != 0x13C4F0u) { return; }
    }
    ctx->pc = 0x13C4F0u;
label_13c4f0:
    // 0x13c4f0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c4f4: 0x8c45dea0  lw          $a1, -0x2160($v0)
    ctx->pc = 0x13c4f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958752)));
    // 0x13c4f8: 0xc04e146  jal         func_138518
    ctx->pc = 0x13C4F8u;
    SET_GPR_U32(ctx, 31, 0x13C500u);
    ctx->pc = 0x13C4FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C4F8u;
            // 0x13c4fc: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138518u;
    if (runtime->hasFunction(0x138518u)) {
        auto targetFn = runtime->lookupFunction(0x138518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C500u; }
        if (ctx->pc != 0x13C500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138518_0x138518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C500u; }
        if (ctx->pc != 0x13C500u) { return; }
    }
    ctx->pc = 0x13C500u;
label_13c500:
    // 0x13c500: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C500u;
    SET_GPR_U32(ctx, 31, 0x13C508u);
    ctx->pc = 0x13C504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C500u;
            // 0x13c504: 0x24046701  addiu       $a0, $zero, 0x6701 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26369));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C508u; }
        if (ctx->pc != 0x13C508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C508u; }
        if (ctx->pc != 0x13C508u) { return; }
    }
    ctx->pc = 0x13C508u;
label_13c508:
    // 0x13c508: 0x274102a  slt         $v0, $s3, $s4
    ctx->pc = 0x13c508u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x13c50c: 0x1440ffc0  bnez        $v0, . + 4 + (-0x40 << 2)
    ctx->pc = 0x13C50Cu;
    {
        const bool branch_taken_0x13c50c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C50Cu;
            // 0x13c510: 0x26520008  addiu       $s2, $s2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c50c) {
            ctx->pc = 0x13C410u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13c410;
        }
    }
    ctx->pc = 0x13C514u;
    // 0x13c514: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13c514u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
label_13c518:
    // 0x13c518: 0x2470dea4  addiu       $s0, $v1, -0x215C
    ctx->pc = 0x13c518u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958756));
    // 0x13c51c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13c51cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13c520: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13C520u;
    {
        const bool branch_taken_0x13c520 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C520u;
            // 0x13c524: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c520) {
            ctx->pc = 0x13C534u;
            goto label_13c534;
        }
    }
    ctx->pc = 0x13C528u;
    // 0x13c528: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13c528u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13c52c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C52Cu;
    SET_GPR_U32(ctx, 31, 0x13C534u);
    ctx->pc = 0x13C530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C52Cu;
            // 0x13c530: 0x2484d1a0  addiu       $a0, $a0, -0x2E60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955424));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C534u; }
        if (ctx->pc != 0x13C534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C534u; }
        if (ctx->pc != 0x13C534u) { return; }
    }
    ctx->pc = 0x13C534u;
label_13c534:
    // 0x13c534: 0x1bc00009  blez        $fp, . + 4 + (0x9 << 2)
    ctx->pc = 0x13C534u;
    {
        const bool branch_taken_0x13c534 = (GPR_S64(ctx, 30) <= 0);
        ctx->pc = 0x13C538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C534u;
            // 0x13c538: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c534) {
            ctx->pc = 0x13C55Cu;
            goto label_13c55c;
        }
    }
    ctx->pc = 0x13C53Cu;
    // 0x13c53c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x13c53cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13c540: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x13c540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13c544: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13C544u;
    {
        const bool branch_taken_0x13c544 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13C548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C544u;
            // 0x13c548: 0x2405000a  addiu       $a1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c544) {
            ctx->pc = 0x13C558u;
            goto label_13c558;
        }
    }
    ctx->pc = 0x13C54Cu;
    // 0x13c54c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13c54cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13c550: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C550u;
    SET_GPR_U32(ctx, 31, 0x13C558u);
    ctx->pc = 0x13C554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C550u;
            // 0x13c554: 0x2484d1b8  addiu       $a0, $a0, -0x2E48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C558u; }
        if (ctx->pc != 0x13C558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C558u; }
        if (ctx->pc != 0x13C558u) { return; }
    }
    ctx->pc = 0x13C558u;
label_13c558:
    // 0x13c558: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x13c558u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_13c55c:
    // 0x13c55c: 0xdfb00100  ld          $s0, 0x100($sp)
    ctx->pc = 0x13c55cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x13c560: 0xdfb10108  ld          $s1, 0x108($sp)
    ctx->pc = 0x13c560u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 264)));
    // 0x13c564: 0xdfb20110  ld          $s2, 0x110($sp)
    ctx->pc = 0x13c564u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x13c568: 0xdfb30118  ld          $s3, 0x118($sp)
    ctx->pc = 0x13c568u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 280)));
    // 0x13c56c: 0xdfb40120  ld          $s4, 0x120($sp)
    ctx->pc = 0x13c56cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x13c570: 0xdfb50128  ld          $s5, 0x128($sp)
    ctx->pc = 0x13c570u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 296)));
    // 0x13c574: 0xdfb60130  ld          $s6, 0x130($sp)
    ctx->pc = 0x13c574u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x13c578: 0xdfb70138  ld          $s7, 0x138($sp)
    ctx->pc = 0x13c578u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 312)));
    // 0x13c57c: 0xdfbe0140  ld          $fp, 0x140($sp)
    ctx->pc = 0x13c57cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x13c580: 0xdfbf0148  ld          $ra, 0x148($sp)
    ctx->pc = 0x13c580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 328)));
    // 0x13c584: 0x3e00008  jr          $ra
    ctx->pc = 0x13C584u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C584u;
            // 0x13c588: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C3F0u: goto label_13c3f0;
            case 0x13C410u: goto label_13c410;
            case 0x13C43Cu: goto label_13c43c;
            case 0x13C450u: goto label_13c450;
            case 0x13C45Cu: goto label_13c45c;
            case 0x13C468u: goto label_13c468;
            case 0x13C490u: goto label_13c490;
            case 0x13C498u: goto label_13c498;
            case 0x13C4A4u: goto label_13c4a4;
            case 0x13C4D0u: goto label_13c4d0;
            case 0x13C4D8u: goto label_13c4d8;
            case 0x13C4E0u: goto label_13c4e0;
            case 0x13C4E8u: goto label_13c4e8;
            case 0x13C4F0u: goto label_13c4f0;
            case 0x13C500u: goto label_13c500;
            case 0x13C508u: goto label_13c508;
            case 0x13C518u: goto label_13c518;
            case 0x13C534u: goto label_13c534;
            case 0x13C558u: goto label_13c558;
            case 0x13C55Cu: goto label_13c55c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C58Cu;
    // 0x13c58c: 0x0  nop
    ctx->pc = 0x13c58cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
