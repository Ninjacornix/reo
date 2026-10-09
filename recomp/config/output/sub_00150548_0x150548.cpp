#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150548
// Address: 0x150548 - 0x1506c0
void sub_00150548_0x150548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150548_0x150548");
#endif

    switch (ctx->pc) {
        case 0x1505a4u: goto label_1505a4;
        case 0x15060cu: goto label_15060c;
        case 0x150698u: goto label_150698;
        case 0x1506a8u: goto label_1506a8;
        default: break;
    }

    ctx->pc = 0x150548u;

    // 0x150548: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150548u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15054c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x15054cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x150550: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x150550u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x150554: 0x2484d858  addiu       $a0, $a0, -0x27A8
    ctx->pc = 0x150554u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957144));
    // 0x150558: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150558u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15055c: 0x805415a  j           func_150568
    ctx->pc = 0x15055Cu;
    ctx->pc = 0x150560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15055Cu;
            // 0x150560: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150568u;
    goto label_150568;
    ctx->pc = 0x150564u;
    // 0x150564: 0x0  nop
    ctx->pc = 0x150564u;
    // NOP
label_150568:
    // 0x150568: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x150568u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x15056c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x15056cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x150570: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x150570u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x150574: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x150574u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x150578: 0x3e00008  jr          $ra
    ctx->pc = 0x150578u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15057Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150578u;
            // 0x15057c: 0xac80000c  sw          $zero, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150568u: goto label_150568;
            case 0x1505A4u: goto label_1505a4;
            case 0x1505D0u: goto label_1505d0;
            case 0x15060Cu: goto label_15060c;
            case 0x150630u: goto label_150630;
            case 0x150670u: goto label_150670;
            case 0x150698u: goto label_150698;
            case 0x1506A0u: goto label_1506a0;
            case 0x1506A8u: goto label_1506a8;
            case 0x1506ACu: goto label_1506ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150580u;
    // 0x150580: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x150580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x150584: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150588: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x150588u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15058c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15058cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x150590: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x150590u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150594: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x150594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x150598: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x150598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15059c: 0xc05578e  jal         func_155E38
    ctx->pc = 0x15059Cu;
    SET_GPR_U32(ctx, 31, 0x1505A4u);
    ctx->pc = 0x1505A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15059Cu;
            // 0x1505a0: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1505A4u; }
        if (ctx->pc != 0x1505A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1505A4u; }
        if (ctx->pc != 0x1505A4u) { return; }
    }
    ctx->pc = 0x1505A4u;
label_1505a4:
    // 0x1505a4: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1505a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1505a8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1505a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1505ac: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1505acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1505b0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1505B0u;
    {
        const bool branch_taken_0x1505b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1505B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1505B0u;
            // 0x1505b4: 0x34a50203  ori         $a1, $a1, 0x203 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)515);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1505b0) {
            ctx->pc = 0x1505D0u;
            goto label_1505d0;
        }
    }
    ctx->pc = 0x1505B8u;
    // 0x1505b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1505b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1505bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1505bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1505c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1505c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1505c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1505c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1505c8: 0x805419c  j           func_150670
    ctx->pc = 0x1505C8u;
    ctx->pc = 0x1505CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1505C8u;
            // 0x1505cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    goto label_150670;
    ctx->pc = 0x1505D0u;
label_1505d0:
    // 0x1505d0: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x1505d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1505d4: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x1505d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x1505d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1505d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1505dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1505dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1505e0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1505e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1505e4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1505e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1505e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1505E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1505ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1505E8u;
            // 0x1505ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150568u: goto label_150568;
            case 0x1505A4u: goto label_1505a4;
            case 0x1505D0u: goto label_1505d0;
            case 0x15060Cu: goto label_15060c;
            case 0x150630u: goto label_150630;
            case 0x150670u: goto label_150670;
            case 0x150698u: goto label_150698;
            case 0x1506A0u: goto label_1506a0;
            case 0x1506A8u: goto label_1506a8;
            case 0x1506ACu: goto label_1506ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1505F0u;
    // 0x1505f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1505f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1505f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1505f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1505f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1505f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1505fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1505fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x150600: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x150600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x150604: 0xc05578e  jal         func_155E38
    ctx->pc = 0x150604u;
    SET_GPR_U32(ctx, 31, 0x15060Cu);
    ctx->pc = 0x150608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150604u;
            // 0x150608: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15060Cu; }
        if (ctx->pc != 0x15060Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15060Cu; }
        if (ctx->pc != 0x15060Cu) { return; }
    }
    ctx->pc = 0x15060Cu;
label_15060c:
    // 0x15060c: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15060cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150610: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x150610u;
    {
        const bool branch_taken_0x150610 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150610u;
            // 0x150614: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150610) {
            ctx->pc = 0x150630u;
            goto label_150630;
        }
    }
    ctx->pc = 0x150618u;
    // 0x150618: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150618u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15061c: 0x34a50204  ori         $a1, $a1, 0x204
    ctx->pc = 0x15061cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)516);
    // 0x150620: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150620u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150624: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150628: 0x805419c  j           func_150670
    ctx->pc = 0x150628u;
    ctx->pc = 0x15062Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150628u;
            // 0x15062c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    goto label_150670;
    ctx->pc = 0x150630u;
label_150630:
    // 0x150630: 0x6a02000b  ldl         $v0, 0xB($s0)
    ctx->pc = 0x150630u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x150634: 0x6e020004  ldr         $v0, 0x4($s0)
    ctx->pc = 0x150634u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 4); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x150638: 0x6a030013  ldl         $v1, 0x13($s0)
    ctx->pc = 0x150638u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 19); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x15063c: 0x6e03000c  ldr         $v1, 0xC($s0)
    ctx->pc = 0x15063cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x150640: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x150640u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x150644: 0xb2220007  sdl         $v0, 0x7($s1)
    ctx->pc = 0x150644u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150648: 0xb6220000  sdr         $v0, 0x0($s1)
    ctx->pc = 0x150648u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15064c: 0xb223000f  sdl         $v1, 0xF($s1)
    ctx->pc = 0x15064cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150650: 0xb6230008  sdr         $v1, 0x8($s1)
    ctx->pc = 0x150650u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150654: 0xae240010  sw          $a0, 0x10($s1)
    ctx->pc = 0x150654u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 4));
    // 0x150658: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150658u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15065c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15065cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150660: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150660u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150664: 0x3e00008  jr          $ra
    ctx->pc = 0x150664u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150664u;
            // 0x150668: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150568u: goto label_150568;
            case 0x1505A4u: goto label_1505a4;
            case 0x1505D0u: goto label_1505d0;
            case 0x15060Cu: goto label_15060c;
            case 0x150630u: goto label_150630;
            case 0x150670u: goto label_150670;
            case 0x150698u: goto label_150698;
            case 0x1506A0u: goto label_1506a0;
            case 0x1506A8u: goto label_1506a8;
            case 0x1506ACu: goto label_1506ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15066Cu;
    // 0x15066c: 0x0  nop
    ctx->pc = 0x15066cu;
    // NOP
label_150670:
    // 0x150670: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150674: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x150674u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150678: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15067c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15067cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150680: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x150680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x150684: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x150684u;
    {
        const bool branch_taken_0x150684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x150688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150684u;
            // 0x150688: 0x24440004  addiu       $a0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150684) {
            ctx->pc = 0x1506A0u;
            goto label_1506a0;
        }
    }
    ctx->pc = 0x15068Cu;
    // 0x15068c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x15068cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x150690: 0xc0541b0  jal         func_1506C0
    ctx->pc = 0x150690u;
    SET_GPR_U32(ctx, 31, 0x150698u);
    ctx->pc = 0x150694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150690u;
            // 0x150694: 0x2484d858  addiu       $a0, $a0, -0x27A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1506C0u;
    if (runtime->hasFunction(0x1506C0u)) {
        auto targetFn = runtime->lookupFunction(0x1506C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150698u; }
        if (ctx->pc != 0x150698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001506C0_0x1506c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150698u; }
        if (ctx->pc != 0x150698u) { return; }
    }
    ctx->pc = 0x150698u;
label_150698:
    // 0x150698: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x150698u;
    {
        const bool branch_taken_0x150698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15069Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150698u;
            // 0x15069c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150698) {
            ctx->pc = 0x1506ACu;
            goto label_1506ac;
        }
    }
    ctx->pc = 0x1506A0u;
label_1506a0:
    // 0x1506a0: 0xc0541b0  jal         func_1506C0
    ctx->pc = 0x1506A0u;
    SET_GPR_U32(ctx, 31, 0x1506A8u);
    ctx->pc = 0x1506C0u;
    if (runtime->hasFunction(0x1506C0u)) {
        auto targetFn = runtime->lookupFunction(0x1506C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1506A8u; }
        if (ctx->pc != 0x1506A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001506C0_0x1506c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1506A8u; }
        if (ctx->pc != 0x1506A8u) { return; }
    }
    ctx->pc = 0x1506A8u;
label_1506a8:
    // 0x1506a8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1506a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1506ac:
    // 0x1506ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1506acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1506b0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1506b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1506b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1506B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1506B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1506B4u;
            // 0x1506b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150568u: goto label_150568;
            case 0x1505A4u: goto label_1505a4;
            case 0x1505D0u: goto label_1505d0;
            case 0x15060Cu: goto label_15060c;
            case 0x150630u: goto label_150630;
            case 0x150670u: goto label_150670;
            case 0x150698u: goto label_150698;
            case 0x1506A0u: goto label_1506a0;
            case 0x1506A8u: goto label_1506a8;
            case 0x1506ACu: goto label_1506ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1506BCu;
    // 0x1506bc: 0x0  nop
    ctx->pc = 0x1506bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
