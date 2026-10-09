#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140300
// Address: 0x140300 - 0x140434
void sub_00140300_0x140300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140300_0x140300");
#endif

    switch (ctx->pc) {
        case 0x140348u: goto label_140348;
        case 0x140360u: goto label_140360;
        case 0x1403e4u: goto label_1403e4;
        case 0x140418u: goto label_140418;
        default: break;
    }

    ctx->pc = 0x140300u;

    // 0x140300: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x140300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x140304: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x140304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x140308: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x140308u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14030c: 0x2e420004  sltiu       $v0, $s2, 0x4
    ctx->pc = 0x14030cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x140310: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x140310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x140314: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x140314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x140318: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x140318u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14031c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x14031cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x140320: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x140320u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140324: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x140324u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x140328: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x140328u;
    {
        const bool branch_taken_0x140328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14032Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140328u;
            // 0x14032c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140328) {
            ctx->pc = 0x140358u;
            goto label_140358;
        }
    }
    ctx->pc = 0x140330u;
    // 0x140330: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140334: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x140334u;
    {
        const bool branch_taken_0x140334 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140334) {
            ctx->pc = 0x140338u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140334u;
            // 0x140338: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14034Cu;
            goto label_14034c;
        }
    }
    ctx->pc = 0x14033Cu;
    // 0x14033c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x14033cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140340: 0x40f809  jalr        $v0
    ctx->pc = 0x140340u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140348u);
        ctx->pc = 0x140344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140340u;
            // 0x140344: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140348u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140348u; }
            if (ctx->pc != 0x140348u) { return; }
        }
        }
    }
    ctx->pc = 0x140348u;
label_140348:
    // 0x140348: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x140348u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_14034c:
    // 0x14034c: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x14034Cu;
    {
        const bool branch_taken_0x14034c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14034Cu;
            // 0x140350: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14034c) {
            ctx->pc = 0x140418u;
            goto label_140418;
        }
    }
    ctx->pc = 0x140354u;
    // 0x140354: 0x0  nop
    ctx->pc = 0x140354u;
    // NOP
label_140358:
    // 0x140358: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140358u;
    SET_GPR_U32(ctx, 31, 0x140360u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140360u; }
        if (ctx->pc != 0x140360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140360u; }
        if (ctx->pc != 0x140360u) { return; }
    }
    ctx->pc = 0x140360u;
label_140360:
    // 0x140360: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x140360u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x140364: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x140364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x140368: 0x24450018  addiu       $a1, $v0, 0x18
    ctx->pc = 0x140368u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x14036c: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x14036cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x140370: 0x10800025  beqz        $a0, . + 4 + (0x25 << 2)
    ctx->pc = 0x140370u;
    {
        const bool branch_taken_0x140370 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x140374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140370u;
            // 0x140374: 0x24920008  addiu       $s2, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140370) {
            ctx->pc = 0x140408u;
            goto label_140408;
        }
    }
    ctx->pc = 0x140378u;
    // 0x140378: 0x6a420007  ldl         $v0, 0x7($s2)
    ctx->pc = 0x140378u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x14037c: 0x6e420000  ldr         $v0, 0x0($s2)
    ctx->pc = 0x14037cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x140380: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x140380u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140384: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x140384u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140388: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x140388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x14038c: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x14038cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x140390: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x140390u;
    {
        const bool branch_taken_0x140390 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x140390) {
            ctx->pc = 0x140394u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140390u;
            // 0x140394: 0x82030005  lb          $v1, 0x5($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1403C0u;
            goto label_1403c0;
        }
    }
    ctx->pc = 0x140398u;
    // 0x140398: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x140398u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14039c: 0x6ba80007  ldl         $t0, 0x7($sp)
    ctx->pc = 0x14039cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1403a0: 0x6fa80000  ldr         $t0, 0x0($sp)
    ctx->pc = 0x1403a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1403a4: 0xb2280007  sdl         $t0, 0x7($s1)
    ctx->pc = 0x1403a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403a8: 0xb6280000  sdr         $t0, 0x0($s1)
    ctx->pc = 0x1403a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403ac: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1403acu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1403b0: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1403b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1403b4: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1403b4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1403b8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1403B8u;
    {
        const bool branch_taken_0x1403b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1403BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1403B8u;
            // 0x1403bc: 0xae040014  sw          $a0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1403b8) {
            ctx->pc = 0x140410u;
            goto label_140410;
        }
    }
    ctx->pc = 0x1403C0u;
label_1403c0:
    // 0x1403c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1403c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1403c4: 0x54620011  bnel        $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1403C4u;
    {
        const bool branch_taken_0x1403c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1403c4) {
            ctx->pc = 0x1403C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1403C4u;
            // 0x1403c8: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14040Cu;
            goto label_14040c;
        }
    }
    ctx->pc = 0x1403CCu;
    // 0x1403cc: 0x27b00010  addiu       $s0, $sp, 0x10
    ctx->pc = 0x1403ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1403d0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1403d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1403d4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1403d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1403d8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1403d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1403dc: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x1403DCu;
    SET_GPR_U32(ctx, 31, 0x1403E4u);
    ctx->pc = 0x1403E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1403DCu;
            // 0x1403e0: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1403E4u; }
        if (ctx->pc != 0x1403E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1403E4u; }
        if (ctx->pc != 0x1403E4u) { return; }
    }
    ctx->pc = 0x1403E4u;
label_1403e4:
    // 0x1403e4: 0x6ba80007  ldl         $t0, 0x7($sp)
    ctx->pc = 0x1403e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1403e8: 0x6fa80000  ldr         $t0, 0x0($sp)
    ctx->pc = 0x1403e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1403ec: 0xb2280007  sdl         $t0, 0x7($s1)
    ctx->pc = 0x1403ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403f0: 0xb6280000  sdr         $t0, 0x0($s1)
    ctx->pc = 0x1403f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403f4: 0x6a050007  ldl         $a1, 0x7($s0)
    ctx->pc = 0x1403f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1403f8: 0x6e050000  ldr         $a1, 0x0($s0)
    ctx->pc = 0x1403f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1403fc: 0xb2450007  sdl         $a1, 0x7($s2)
    ctx->pc = 0x1403fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140400: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x140400u;
    {
        const bool branch_taken_0x140400 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140400u;
            // 0x140404: 0xb6450000  sdr         $a1, 0x0($s2) (Delay Slot)
        { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x140400) {
            ctx->pc = 0x140410u;
            goto label_140410;
        }
    }
    ctx->pc = 0x140408u;
label_140408:
    // 0x140408: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x140408u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_14040c:
    // 0x14040c: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x14040cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
label_140410:
    // 0x140410: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x140410u;
    SET_GPR_U32(ctx, 31, 0x140418u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140418u; }
        if (ctx->pc != 0x140418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140418u; }
        if (ctx->pc != 0x140418u) { return; }
    }
    ctx->pc = 0x140418u;
label_140418:
    // 0x140418: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x140418u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14041c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x14041cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x140420: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x140420u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x140424: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x140424u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x140428: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x140428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14042c: 0x3e00008  jr          $ra
    ctx->pc = 0x14042Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14042Cu;
            // 0x140430: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140434u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
