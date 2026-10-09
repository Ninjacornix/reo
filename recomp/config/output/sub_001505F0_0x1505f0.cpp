#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001505F0
// Address: 0x1505f0 - 0x15066c
void sub_001505F0_0x1505f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001505F0_0x1505f0");
#endif

    switch (ctx->pc) {
        case 0x15060cu: goto label_15060c;
        default: break;
    }

    ctx->pc = 0x1505f0u;

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
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
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
            case 0x15060Cu: goto label_15060c;
            case 0x150630u: goto label_150630;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15066Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
