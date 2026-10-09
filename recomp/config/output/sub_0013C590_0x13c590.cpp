#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C590
// Address: 0x13c590 - 0x13c7c0
void sub_0013C590_0x13c590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C590_0x13c590");
#endif

    switch (ctx->pc) {
        case 0x13c5f0u: goto label_13c5f0;
        case 0x13c61cu: goto label_13c61c;
        case 0x13c630u: goto label_13c630;
        case 0x13c638u: goto label_13c638;
        case 0x13c644u: goto label_13c644;
        case 0x13c660u: goto label_13c660;
        case 0x13c680u: goto label_13c680;
        case 0x13c6b8u: goto label_13c6b8;
        case 0x13c6c0u: goto label_13c6c0;
        case 0x13c740u: goto label_13c740;
        case 0x13c768u: goto label_13c768;
        default: break;
    }

    ctx->pc = 0x13c590u;

    // 0x13c590: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x13c590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x13c594: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c594u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c598: 0xffb70138  sd          $s7, 0x138($sp)
    ctx->pc = 0x13c598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 312), GPR_U64(ctx, 23));
    // 0x13c59c: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x13c59cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c5a0: 0xffb00100  sd          $s0, 0x100($sp)
    ctx->pc = 0x13c5a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 256), GPR_U64(ctx, 16));
    // 0x13c5a4: 0x2443de90  addiu       $v1, $v0, -0x2170
    ctx->pc = 0x13c5a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958736));
    // 0x13c5a8: 0xffb10108  sd          $s1, 0x108($sp)
    ctx->pc = 0x13c5a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 264), GPR_U64(ctx, 17));
    // 0x13c5ac: 0xffb20110  sd          $s2, 0x110($sp)
    ctx->pc = 0x13c5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 18));
    // 0x13c5b0: 0xffb30118  sd          $s3, 0x118($sp)
    ctx->pc = 0x13c5b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 280), GPR_U64(ctx, 19));
    // 0x13c5b4: 0xffb40120  sd          $s4, 0x120($sp)
    ctx->pc = 0x13c5b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 20));
    // 0x13c5b8: 0xffb50128  sd          $s5, 0x128($sp)
    ctx->pc = 0x13c5b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 296), GPR_U64(ctx, 21));
    // 0x13c5bc: 0xffb60130  sd          $s6, 0x130($sp)
    ctx->pc = 0x13c5bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 22));
    // 0x13c5c0: 0xffbe0140  sd          $fp, 0x140($sp)
    ctx->pc = 0x13c5c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 320), GPR_U64(ctx, 30));
    // 0x13c5c4: 0xffbf0148  sd          $ra, 0x148($sp)
    ctx->pc = 0x13c5c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 328), GPR_U64(ctx, 31));
    // 0x13c5c8: 0x8c730000  lw          $s3, 0x0($v1)
    ctx->pc = 0x13c5c8u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13c5cc: 0x1260003d  beqz        $s3, . + 4 + (0x3D << 2)
    ctx->pc = 0x13C5CCu;
    {
        const bool branch_taken_0x13c5cc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C5D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C5CCu;
            // 0x13c5d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c5cc) {
            ctx->pc = 0x13C6C4u;
            goto label_13c6c4;
        }
    }
    ctx->pc = 0x13C5D4u;
    // 0x13c5d4: 0x8c740004  lw          $s4, 0x4($v1)
    ctx->pc = 0x13c5d4u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x13c5d8: 0x1280002f  beqz        $s4, . + 4 + (0x2F << 2)
    ctx->pc = 0x13C5D8u;
    {
        const bool branch_taken_0x13c5d8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C5D8u;
            // 0x13c5dc: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c5d8) {
            ctx->pc = 0x13C698u;
            goto label_13c698;
        }
    }
    ctx->pc = 0x13C5E0u;
    // 0x13c5e0: 0x60b02d  daddu       $s6, $v1, $zero
    ctx->pc = 0x13c5e0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c5e4: 0x3c1e0022  lui         $fp, 0x22
    ctx->pc = 0x13c5e4u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)34 << 16));
    // 0x13c5e8: 0x24150002  addiu       $s5, $zero, 0x2
    ctx->pc = 0x13c5e8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13c5ec: 0x260882d  daddu       $s1, $s3, $zero
    ctx->pc = 0x13c5ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_13c5f0:
    // 0x13c5f0: 0x8ec2000c  lw          $v0, 0xC($s6)
    ctx->pc = 0x13c5f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x13c5f4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13c5f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c5f8: 0x8ed00008  lw          $s0, 0x8($s6)
    ctx->pc = 0x13c5f8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x13c5fc: 0x521818  mult        $v1, $v0, $s2
    ctx->pc = 0x13c5fcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x13c600: 0x1080c0  sll         $s0, $s0, 3
    ctx->pc = 0x13c600u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x13c604: 0x721021  addu        $v0, $v1, $s2
    ctx->pc = 0x13c604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x13c608: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13c608u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13c60c: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x13c60cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13c610: 0x2708021  addu        $s0, $s3, $s0
    ctx->pc = 0x13c610u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x13c614: 0xc04efa0  jal         func_13BE80
    ctx->pc = 0x13C614u;
    SET_GPR_U32(ctx, 31, 0x13C61Cu);
    ctx->pc = 0x13C618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C614u;
            // 0x13c618: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BE80u;
    if (runtime->hasFunction(0x13BE80u)) {
        auto targetFn = runtime->lookupFunction(0x13BE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C61Cu; }
        if (ctx->pc != 0x13C61Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE80_0x13be80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C61Cu; }
        if (ctx->pc != 0x13C61Cu) { return; }
    }
    ctx->pc = 0x13C61Cu;
label_13c61c:
    // 0x13c61c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x13c61cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13c620: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x13C620u;
    {
        const bool branch_taken_0x13c620 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C620u;
            // 0x13c624: 0x24046900  addiu       $a0, $zero, 0x6900 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26880));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c620) {
            ctx->pc = 0x13C680u;
            goto label_13c680;
        }
    }
    ctx->pc = 0x13C628u;
    // 0x13c628: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C628u;
    SET_GPR_U32(ctx, 31, 0x13C630u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C630u; }
        if (ctx->pc != 0x13C630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C630u; }
        if (ctx->pc != 0x13C630u) { return; }
    }
    ctx->pc = 0x13C630u;
label_13c630:
    // 0x13c630: 0xc04e160  jal         func_138580
    ctx->pc = 0x13C630u;
    SET_GPR_U32(ctx, 31, 0x13C638u);
    ctx->pc = 0x13C634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C630u;
            // 0x13c634: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C638u; }
        if (ctx->pc != 0x13C638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C638u; }
        if (ctx->pc != 0x13C638u) { return; }
    }
    ctx->pc = 0x13C638u;
label_13c638:
    // 0x13c638: 0x24046901  addiu       $a0, $zero, 0x6901
    ctx->pc = 0x13c638u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26881));
    // 0x13c63c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13C63Cu;
    SET_GPR_U32(ctx, 31, 0x13C644u);
    ctx->pc = 0x13C640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C63Cu;
            // 0x13c640: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C644u; }
        if (ctx->pc != 0x13C644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C644u; }
        if (ctx->pc != 0x13C644u) { return; }
    }
    ctx->pc = 0x13C644u;
label_13c644:
    // 0x13c644: 0x6010008  bgez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13C644u;
    {
        const bool branch_taken_0x13c644 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x13C648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C644u;
            // 0x13c648: 0x8fc2dea4  lw          $v0, -0x215C($fp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4294958756)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c644) {
            ctx->pc = 0x13C668u;
            goto label_13c668;
        }
    }
    ctx->pc = 0x13C64Cu;
    // 0x13c64c: 0x1055000c  beq         $v0, $s5, . + 4 + (0xC << 2)
    ctx->pc = 0x13C64Cu;
    {
        const bool branch_taken_0x13c64c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 21));
        ctx->pc = 0x13C650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C64Cu;
            // 0x13c650: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c64c) {
            ctx->pc = 0x13C680u;
            goto label_13c680;
        }
    }
    ctx->pc = 0x13C654u;
    // 0x13c654: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13c654u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c658: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C658u;
    SET_GPR_U32(ctx, 31, 0x13C660u);
    ctx->pc = 0x13C65Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C658u;
            // 0x13c65c: 0x2444d1e8  addiu       $a0, $v0, -0x2E18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C660u; }
        if (ctx->pc != 0x13C660u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C660u; }
        if (ctx->pc != 0x13C660u) { return; }
    }
    ctx->pc = 0x13C660u;
label_13c660:
    // 0x13c660: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13C660u;
    {
        const bool branch_taken_0x13c660 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C660u;
            // 0x13c664: 0x254102b  sltu        $v0, $s2, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 20)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c660) {
            ctx->pc = 0x13C684u;
            goto label_13c684;
        }
    }
    ctx->pc = 0x13C668u;
label_13c668:
    // 0x13c668: 0x10550005  beq         $v0, $s5, . + 4 + (0x5 << 2)
    ctx->pc = 0x13C668u;
    {
        const bool branch_taken_0x13c668 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 21));
        ctx->pc = 0x13C66Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C668u;
            // 0x13c66c: 0x26f70001  addiu       $s7, $s7, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c668) {
            ctx->pc = 0x13C680u;
            goto label_13c680;
        }
    }
    ctx->pc = 0x13C670u;
    // 0x13c670: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x13c670u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x13c674: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13c674u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c678: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C678u;
    SET_GPR_U32(ctx, 31, 0x13C680u);
    ctx->pc = 0x13C67Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C678u;
            // 0x13c67c: 0x2464d210  addiu       $a0, $v1, -0x2DF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294955536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C680u; }
        if (ctx->pc != 0x13C680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C680u; }
        if (ctx->pc != 0x13C680u) { return; }
    }
    ctx->pc = 0x13C680u;
label_13c680:
    // 0x13c680: 0x254102b  sltu        $v0, $s2, $s4
    ctx->pc = 0x13c680u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 20)) ? 1 : 0);
label_13c684:
    // 0x13c684: 0x1440ffda  bnez        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x13C684u;
    {
        const bool branch_taken_0x13c684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C684u;
            // 0x13c688: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c684) {
            ctx->pc = 0x13C5F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13c5f0;
        }
    }
    ctx->pc = 0x13C68Cu;
    // 0x13c68c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13C68Cu;
    {
        const bool branch_taken_0x13c68c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C68Cu;
            // 0x13c690: 0x8fc3dea4  lw          $v1, -0x215C($fp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4294958756)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c68c) {
            ctx->pc = 0x13C6A0u;
            goto label_13c6a0;
        }
    }
    ctx->pc = 0x13C694u;
    // 0x13c694: 0x0  nop
    ctx->pc = 0x13c694u;
    // NOP
label_13c698:
    // 0x13c698: 0x3c1e0022  lui         $fp, 0x22
    ctx->pc = 0x13c698u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)34 << 16));
    // 0x13c69c: 0x8fc3dea4  lw          $v1, -0x215C($fp)
    ctx->pc = 0x13c69cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4294958756)));
label_13c6a0:
    // 0x13c6a0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x13c6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13c6a4: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13C6A4u;
    {
        const bool branch_taken_0x13c6a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13C6A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C6A4u;
            // 0x13c6a8: 0x2e0282d  daddu       $a1, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c6a4) {
            ctx->pc = 0x13C6B8u;
            goto label_13c6b8;
        }
    }
    ctx->pc = 0x13C6ACu;
    // 0x13c6ac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13c6acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13c6b0: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C6B0u;
    SET_GPR_U32(ctx, 31, 0x13C6B8u);
    ctx->pc = 0x13C6B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C6B0u;
            // 0x13c6b4: 0x2484d230  addiu       $a0, $a0, -0x2DD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C6B8u; }
        if (ctx->pc != 0x13C6B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C6B8u; }
        if (ctx->pc != 0x13C6B8u) { return; }
    }
    ctx->pc = 0x13C6B8u;
label_13c6b8:
    // 0x13c6b8: 0xc04f1f0  jal         func_13C7C0
    ctx->pc = 0x13C6B8u;
    SET_GPR_U32(ctx, 31, 0x13C6C0u);
    ctx->pc = 0x13C7C0u;
    if (runtime->hasFunction(0x13C7C0u)) {
        auto targetFn = runtime->lookupFunction(0x13C7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C6C0u; }
        if (ctx->pc != 0x13C6C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7C0_0x13c7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C6C0u; }
        if (ctx->pc != 0x13C6C0u) { return; }
    }
    ctx->pc = 0x13C6C0u;
label_13c6c0:
    // 0x13c6c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13c6c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13c6c4:
    // 0x13c6c4: 0xdfb00100  ld          $s0, 0x100($sp)
    ctx->pc = 0x13c6c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x13c6c8: 0xdfb10108  ld          $s1, 0x108($sp)
    ctx->pc = 0x13c6c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 264)));
    // 0x13c6cc: 0xdfb20110  ld          $s2, 0x110($sp)
    ctx->pc = 0x13c6ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x13c6d0: 0xdfb30118  ld          $s3, 0x118($sp)
    ctx->pc = 0x13c6d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 280)));
    // 0x13c6d4: 0xdfb40120  ld          $s4, 0x120($sp)
    ctx->pc = 0x13c6d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x13c6d8: 0xdfb50128  ld          $s5, 0x128($sp)
    ctx->pc = 0x13c6d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 296)));
    // 0x13c6dc: 0xdfb60130  ld          $s6, 0x130($sp)
    ctx->pc = 0x13c6dcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x13c6e0: 0xdfb70138  ld          $s7, 0x138($sp)
    ctx->pc = 0x13c6e0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 312)));
    // 0x13c6e4: 0xdfbe0140  ld          $fp, 0x140($sp)
    ctx->pc = 0x13c6e4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x13c6e8: 0xdfbf0148  ld          $ra, 0x148($sp)
    ctx->pc = 0x13c6e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 328)));
    // 0x13c6ec: 0x3e00008  jr          $ra
    ctx->pc = 0x13C6ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C6F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C6ECu;
            // 0x13c6f0: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C5F0u: goto label_13c5f0;
            case 0x13C61Cu: goto label_13c61c;
            case 0x13C630u: goto label_13c630;
            case 0x13C638u: goto label_13c638;
            case 0x13C644u: goto label_13c644;
            case 0x13C660u: goto label_13c660;
            case 0x13C668u: goto label_13c668;
            case 0x13C680u: goto label_13c680;
            case 0x13C684u: goto label_13c684;
            case 0x13C698u: goto label_13c698;
            case 0x13C6A0u: goto label_13c6a0;
            case 0x13C6B8u: goto label_13c6b8;
            case 0x13C6C0u: goto label_13c6c0;
            case 0x13C6C4u: goto label_13c6c4;
            case 0x13C740u: goto label_13c740;
            case 0x13C768u: goto label_13c768;
            case 0x13C788u: goto label_13c788;
            case 0x13C790u: goto label_13c790;
            case 0x13C798u: goto label_13c798;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C6F4u;
    // 0x13c6f4: 0x0  nop
    ctx->pc = 0x13c6f4u;
    // NOP
    // 0x13c6f8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13c6f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13c6fc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13c6fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13c700: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x13c700u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c704: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13c704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13c708: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x13c708u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c70c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13c70cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13c710: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x13c710u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c714: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13c714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13c718: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x13c718u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c71c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x13c71cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x13c720: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x13c720u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c724: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13c724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13c728: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13c728u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13c72c: 0x1a800018  blez        $s4, . + 4 + (0x18 << 2)
    ctx->pc = 0x13C72Cu;
    {
        const bool branch_taken_0x13c72c = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x13C730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C72Cu;
            // 0x13c730: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c72c) {
            ctx->pc = 0x13C790u;
            goto label_13c790;
        }
    }
    ctx->pc = 0x13C734u;
    // 0x13c734: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c734u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c738: 0x240882d  daddu       $s1, $s2, $zero
    ctx->pc = 0x13c738u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c73c: 0x2455de90  addiu       $s5, $v0, -0x2170
    ctx->pc = 0x13c73cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958736));
label_13c740:
    // 0x13c740: 0x8ea2000c  lw          $v0, 0xC($s5)
    ctx->pc = 0x13c740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 12)));
    // 0x13c744: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x13c744u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c748: 0x8ea50008  lw          $a1, 0x8($s5)
    ctx->pc = 0x13c748u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x13c74c: 0x501818  mult        $v1, $v0, $s0
    ctx->pc = 0x13c74cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x13c750: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x13c750u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x13c754: 0x701021  addu        $v0, $v1, $s0
    ctx->pc = 0x13c754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x13c758: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x13c758u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x13c75c: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x13c75cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x13c760: 0xc04f002  jal         func_13C008
    ctx->pc = 0x13C760u;
    SET_GPR_U32(ctx, 31, 0x13C768u);
    ctx->pc = 0x13C764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C760u;
            // 0x13c764: 0x2452821  addu        $a1, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C008u;
    if (runtime->hasFunction(0x13C008u)) {
        auto targetFn = runtime->lookupFunction(0x13C008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C768u; }
        if (ctx->pc != 0x13C768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C008_0x13c008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C768u; }
        if (ctx->pc != 0x13C768u) { return; }
    }
    ctx->pc = 0x13C768u;
label_13c768:
    // 0x13c768: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13C768u;
    {
        const bool branch_taken_0x13c768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C76Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C768u;
            // 0x13c76c: 0x214182a  slt         $v1, $s0, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c768) {
            ctx->pc = 0x13C788u;
            goto label_13c788;
        }
    }
    ctx->pc = 0x13C770u;
    // 0x13c770: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13c770u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13c774: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x13c774u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x13c778: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13c778u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13c77c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x13C77Cu;
    {
        const bool branch_taken_0x13c77c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C77Cu;
            // 0x13c780: 0xae630004  sw          $v1, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c77c) {
            ctx->pc = 0x13C798u;
            goto label_13c798;
        }
    }
    ctx->pc = 0x13C784u;
    // 0x13c784: 0x0  nop
    ctx->pc = 0x13c784u;
    // NOP
label_13c788:
    // 0x13c788: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x13C788u;
    {
        const bool branch_taken_0x13c788 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C78Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C788u;
            // 0x13c78c: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c788) {
            ctx->pc = 0x13C740u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13c740;
        }
    }
    ctx->pc = 0x13C790u;
label_13c790:
    // 0x13c790: 0xae600004  sw          $zero, 0x4($s3)
    ctx->pc = 0x13c790u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 0));
    // 0x13c794: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x13c794u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
label_13c798:
    // 0x13c798: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13c798u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13c79c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13c79cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13c7a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13c7a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13c7a4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13c7a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13c7a8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13c7a8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13c7ac: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13c7acu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13c7b0: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x13c7b0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13c7b4: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x13c7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13c7b8: 0x3e00008  jr          $ra
    ctx->pc = 0x13C7B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C7B8u;
            // 0x13c7bc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C5F0u: goto label_13c5f0;
            case 0x13C61Cu: goto label_13c61c;
            case 0x13C630u: goto label_13c630;
            case 0x13C638u: goto label_13c638;
            case 0x13C644u: goto label_13c644;
            case 0x13C660u: goto label_13c660;
            case 0x13C668u: goto label_13c668;
            case 0x13C680u: goto label_13c680;
            case 0x13C684u: goto label_13c684;
            case 0x13C698u: goto label_13c698;
            case 0x13C6A0u: goto label_13c6a0;
            case 0x13C6B8u: goto label_13c6b8;
            case 0x13C6C0u: goto label_13c6c0;
            case 0x13C6C4u: goto label_13c6c4;
            case 0x13C740u: goto label_13c740;
            case 0x13C768u: goto label_13c768;
            case 0x13C788u: goto label_13c788;
            case 0x13C790u: goto label_13c790;
            case 0x13C798u: goto label_13c798;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C7C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
