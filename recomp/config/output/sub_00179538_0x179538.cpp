#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179538
// Address: 0x179538 - 0x179660
void sub_00179538_0x179538(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179538_0x179538");
#endif

    switch (ctx->pc) {
        case 0x179550u: goto label_179550;
        case 0x1795a0u: goto label_1795a0;
        case 0x1795b8u: goto label_1795b8;
        case 0x17960cu: goto label_17960c;
        case 0x179624u: goto label_179624;
        default: break;
    }

    ctx->pc = 0x179538u;

    // 0x179538: 0x24830180  addiu       $v1, $a0, 0x180
    ctx->pc = 0x179538u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 384));
    // 0x17953c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17953cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179540: 0x90620018  lbu         $v0, 0x18($v1)
    ctx->pc = 0x179540u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x179544: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x179544u;
    {
        const bool branch_taken_0x179544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x179548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179544u;
            // 0x179548: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179544) {
            ctx->pc = 0x179568u;
            goto label_179568;
        }
    }
    ctx->pc = 0x17954Cu;
    // 0x17954c: 0x0  nop
    ctx->pc = 0x17954cu;
    // NOP
label_179550:
    // 0x179550: 0x61180  sll         $v0, $a2, 6
    ctx->pc = 0x179550u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
    // 0x179554: 0x28c3001a  slti        $v1, $a2, 0x1A
    ctx->pc = 0x179554u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)26) ? 1 : 0);
    // 0x179558: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x179558u;
    {
        const bool branch_taken_0x179558 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x17955Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179558u;
            // 0x17955c: 0x821021  addu        $v0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179558) {
            ctx->pc = 0x179578u;
            goto label_179578;
        }
    }
    ctx->pc = 0x179560u;
    // 0x179560: 0x24430180  addiu       $v1, $v0, 0x180
    ctx->pc = 0x179560u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 384));
    // 0x179564: 0x90620018  lbu         $v0, 0x18($v1)
    ctx->pc = 0x179564u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 24)));
label_179568:
    // 0x179568: 0x0  nop
    ctx->pc = 0x179568u;
    // NOP
    // 0x17956c: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x17956Cu;
    {
        const bool branch_taken_0x17956c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x17956c) {
            ctx->pc = 0x179570u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17956Cu;
            // 0x179570: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_179550;
        }
    }
    ctx->pc = 0x179574u;
    // 0x179574: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x179574u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_179578:
    // 0x179578: 0x3e00008  jr          $ra
    ctx->pc = 0x179578u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17957Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179578u;
            // 0x17957c: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179550u: goto label_179550;
            case 0x179568u: goto label_179568;
            case 0x179578u: goto label_179578;
            case 0x1795A0u: goto label_1795a0;
            case 0x1795B8u: goto label_1795b8;
            case 0x1795DCu: goto label_1795dc;
            case 0x17960Cu: goto label_17960c;
            case 0x179624u: goto label_179624;
            case 0x179648u: goto label_179648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179580u;
    // 0x179580: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179584: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179588: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x179588u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17958c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17958cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179590: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179594: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179594u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179598: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179598u;
    SET_GPR_U32(ctx, 31, 0x1795A0u);
    ctx->pc = 0x17959Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179598u;
            // 0x17959c: 0x24510040  addiu       $s1, $v0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1795A0u; }
        if (ctx->pc != 0x1795A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1795A0u; }
        if (ctx->pc != 0x1795A0u) { return; }
    }
    ctx->pc = 0x1795A0u;
label_1795a0:
    // 0x1795a0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1795a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1795a4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1795a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1795a8: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1795A8u;
    {
        const bool branch_taken_0x1795a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1795ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1795A8u;
            // 0x1795ac: 0x2406000d  addiu       $a2, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1795a8) {
            ctx->pc = 0x1795DCu;
            goto label_1795dc;
        }
    }
    ctx->pc = 0x1795B0u;
    // 0x1795b0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1795B0u;
    SET_GPR_U32(ctx, 31, 0x1795B8u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1795B8u; }
        if (ctx->pc != 0x1795B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1795B8u; }
        if (ctx->pc != 0x1795B8u) { return; }
    }
    ctx->pc = 0x1795B8u;
label_1795b8:
    // 0x1795b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1795b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1795bc: 0x6a230007  ldl         $v1, 0x7($s1)
    ctx->pc = 0x1795bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1795c0: 0x6e230000  ldr         $v1, 0x0($s1)
    ctx->pc = 0x1795c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1795c4: 0x8a24000b  lwl         $a0, 0xB($s1)
    ctx->pc = 0x1795c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x1795c8: 0x9a240008  lwr         $a0, 0x8($s1)
    ctx->pc = 0x1795c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x1795cc: 0xb2030007  sdl         $v1, 0x7($s0)
    ctx->pc = 0x1795ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1795d0: 0xb6030000  sdr         $v1, 0x0($s0)
    ctx->pc = 0x1795d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1795d4: 0xaa04000b  swl         $a0, 0xB($s0)
    ctx->pc = 0x1795d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1795d8: 0xba040008  swr         $a0, 0x8($s0)
    ctx->pc = 0x1795d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_1795dc:
    // 0x1795dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1795dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1795e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1795e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1795e4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1795e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1795e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1795E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1795ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1795E8u;
            // 0x1795ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179550u: goto label_179550;
            case 0x179568u: goto label_179568;
            case 0x179578u: goto label_179578;
            case 0x1795A0u: goto label_1795a0;
            case 0x1795B8u: goto label_1795b8;
            case 0x1795DCu: goto label_1795dc;
            case 0x17960Cu: goto label_17960c;
            case 0x179624u: goto label_179624;
            case 0x179648u: goto label_179648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1795F0u;
    // 0x1795f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1795f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1795f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1795f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1795f8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1795f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1795fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1795fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179600: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179604: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179604u;
    SET_GPR_U32(ctx, 31, 0x17960Cu);
    ctx->pc = 0x179608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179604u;
            // 0x179608: 0x8c910004  lw          $s1, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17960Cu; }
        if (ctx->pc != 0x17960Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17960Cu; }
        if (ctx->pc != 0x17960Cu) { return; }
    }
    ctx->pc = 0x17960Cu;
label_17960c:
    // 0x17960c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17960cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179610: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x179610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179614: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x179614u;
    {
        const bool branch_taken_0x179614 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x179618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179614u;
            // 0x179618: 0x2406000d  addiu       $a2, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179614) {
            ctx->pc = 0x179648u;
            goto label_179648;
        }
    }
    ctx->pc = 0x17961Cu;
    // 0x17961c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x17961Cu;
    SET_GPR_U32(ctx, 31, 0x179624u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179624u; }
        if (ctx->pc != 0x179624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179624u; }
        if (ctx->pc != 0x179624u) { return; }
    }
    ctx->pc = 0x179624u;
label_179624:
    // 0x179624: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179628: 0x6a230053  ldl         $v1, 0x53($s1)
    ctx->pc = 0x179628u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 83); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x17962c: 0x6e23004c  ldr         $v1, 0x4C($s1)
    ctx->pc = 0x17962cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 76); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x179630: 0x8a240057  lwl         $a0, 0x57($s1)
    ctx->pc = 0x179630u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 87); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x179634: 0x9a240054  lwr         $a0, 0x54($s1)
    ctx->pc = 0x179634u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 84); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x179638: 0xb2030007  sdl         $v1, 0x7($s0)
    ctx->pc = 0x179638u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17963c: 0xb6030000  sdr         $v1, 0x0($s0)
    ctx->pc = 0x17963cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179640: 0xaa04000b  swl         $a0, 0xB($s0)
    ctx->pc = 0x179640u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x179644: 0xba040008  swr         $a0, 0x8($s0)
    ctx->pc = 0x179644u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_179648:
    // 0x179648: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179648u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17964c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17964cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179650: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179650u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179654: 0x3e00008  jr          $ra
    ctx->pc = 0x179654u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179654u;
            // 0x179658: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179550u: goto label_179550;
            case 0x179568u: goto label_179568;
            case 0x179578u: goto label_179578;
            case 0x1795A0u: goto label_1795a0;
            case 0x1795B8u: goto label_1795b8;
            case 0x1795DCu: goto label_1795dc;
            case 0x17960Cu: goto label_17960c;
            case 0x179624u: goto label_179624;
            case 0x179648u: goto label_179648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17965Cu;
    // 0x17965c: 0x0  nop
    ctx->pc = 0x17965cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
