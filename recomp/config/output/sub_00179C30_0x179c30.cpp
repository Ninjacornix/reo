#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179C30
// Address: 0x179c30 - 0x179d58
void sub_00179C30_0x179c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179C30_0x179c30");
#endif

    switch (ctx->pc) {
        case 0x179c50u: goto label_179c50;
        case 0x179c94u: goto label_179c94;
        case 0x179cb0u: goto label_179cb0;
        case 0x179d04u: goto label_179d04;
        case 0x179d20u: goto label_179d20;
        default: break;
    }

    ctx->pc = 0x179c30u;

    // 0x179c30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179c30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179c34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179c34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179c38: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179c3c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179c3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179c40: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179c40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179c44: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179c44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179c48: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179C48u;
    SET_GPR_U32(ctx, 31, 0x179C50u);
    ctx->pc = 0x179C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179C48u;
            // 0x179c4c: 0x245000b0  addiu       $s0, $v0, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C50u; }
        if (ctx->pc != 0x179C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C50u; }
        if (ctx->pc != 0x179C50u) { return; }
    }
    ctx->pc = 0x179C50u;
label_179c50:
    // 0x179c50: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179C50u;
    {
        const bool branch_taken_0x179c50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179c50) {
            ctx->pc = 0x179C54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179C50u;
            // 0x179c54: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179C68u;
            goto label_179c68;
        }
    }
    ctx->pc = 0x179C58u;
    // 0x179c58: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x179c58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x179c5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179c60: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179c60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x179c64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179c64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179c68:
    // 0x179c68: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179c68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179c6c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179c6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179c70: 0x3e00008  jr          $ra
    ctx->pc = 0x179C70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179C70u;
            // 0x179c74: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179C50u: goto label_179c50;
            case 0x179C68u: goto label_179c68;
            case 0x179C94u: goto label_179c94;
            case 0x179CB0u: goto label_179cb0;
            case 0x179CD4u: goto label_179cd4;
            case 0x179D04u: goto label_179d04;
            case 0x179D20u: goto label_179d20;
            case 0x179D44u: goto label_179d44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179C78u;
    // 0x179c78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179c78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179c7c: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x179c7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179c80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179c84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179c88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179c8c: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179C8Cu;
    SET_GPR_U32(ctx, 31, 0x179C94u);
    ctx->pc = 0x179C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179C8Cu;
            // 0x179c90: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C94u; }
        if (ctx->pc != 0x179C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C94u; }
        if (ctx->pc != 0x179C94u) { return; }
    }
    ctx->pc = 0x179C94u;
label_179c94:
    // 0x179c94: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x179c94u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179c98: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x179c98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179c9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x179c9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ca0: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x179CA0u;
    {
        const bool branch_taken_0x179ca0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x179CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179CA0u;
            // 0x179ca4: 0x2406000d  addiu       $a2, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ca0) {
            ctx->pc = 0x179CD4u;
            goto label_179cd4;
        }
    }
    ctx->pc = 0x179CA8u;
    // 0x179ca8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x179CA8u;
    SET_GPR_U32(ctx, 31, 0x179CB0u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179CB0u; }
        if (ctx->pc != 0x179CB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179CB0u; }
        if (ctx->pc != 0x179CB0u) { return; }
    }
    ctx->pc = 0x179CB0u;
label_179cb0:
    // 0x179cb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179cb4: 0x6a030007  ldl         $v1, 0x7($s0)
    ctx->pc = 0x179cb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x179cb8: 0x6e030000  ldr         $v1, 0x0($s0)
    ctx->pc = 0x179cb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x179cbc: 0x8a04000b  lwl         $a0, 0xB($s0)
    ctx->pc = 0x179cbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x179cc0: 0x9a040008  lwr         $a0, 0x8($s0)
    ctx->pc = 0x179cc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x179cc4: 0xb2230007  sdl         $v1, 0x7($s1)
    ctx->pc = 0x179cc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179cc8: 0xb6230000  sdr         $v1, 0x0($s1)
    ctx->pc = 0x179cc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179ccc: 0xaa24000b  swl         $a0, 0xB($s1)
    ctx->pc = 0x179cccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x179cd0: 0xba240008  swr         $a0, 0x8($s1)
    ctx->pc = 0x179cd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_179cd4:
    // 0x179cd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179cd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179cd8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179cd8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179cdc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179cdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179ce0: 0x3e00008  jr          $ra
    ctx->pc = 0x179CE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179CE0u;
            // 0x179ce4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179C50u: goto label_179c50;
            case 0x179C68u: goto label_179c68;
            case 0x179C94u: goto label_179c94;
            case 0x179CB0u: goto label_179cb0;
            case 0x179CD4u: goto label_179cd4;
            case 0x179D04u: goto label_179d04;
            case 0x179D20u: goto label_179d20;
            case 0x179D44u: goto label_179d44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179CE8u;
    // 0x179ce8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179ce8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179cec: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x179cecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179cf0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179cf4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179cf8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179cf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179cfc: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179CFCu;
    SET_GPR_U32(ctx, 31, 0x179D04u);
    ctx->pc = 0x179D00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179CFCu;
            // 0x179d00: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179D04u; }
        if (ctx->pc != 0x179D04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179D04u; }
        if (ctx->pc != 0x179D04u) { return; }
    }
    ctx->pc = 0x179D04u;
label_179d04:
    // 0x179d04: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x179d04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179d08: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x179d08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179d0c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x179d0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179d10: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x179D10u;
    {
        const bool branch_taken_0x179d10 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x179D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179D10u;
            // 0x179d14: 0x2406000d  addiu       $a2, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179d10) {
            ctx->pc = 0x179D44u;
            goto label_179d44;
        }
    }
    ctx->pc = 0x179D18u;
    // 0x179d18: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x179D18u;
    SET_GPR_U32(ctx, 31, 0x179D20u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179D20u; }
        if (ctx->pc != 0x179D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179D20u; }
        if (ctx->pc != 0x179D20u) { return; }
    }
    ctx->pc = 0x179D20u;
label_179d20:
    // 0x179d20: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179d20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179d24: 0x6a030013  ldl         $v1, 0x13($s0)
    ctx->pc = 0x179d24u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 19); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x179d28: 0x6e03000c  ldr         $v1, 0xC($s0)
    ctx->pc = 0x179d28u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x179d2c: 0x8a040017  lwl         $a0, 0x17($s0)
    ctx->pc = 0x179d2cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x179d30: 0x9a040014  lwr         $a0, 0x14($s0)
    ctx->pc = 0x179d30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x179d34: 0xb2230007  sdl         $v1, 0x7($s1)
    ctx->pc = 0x179d34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179d38: 0xb6230000  sdr         $v1, 0x0($s1)
    ctx->pc = 0x179d38u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179d3c: 0xaa24000b  swl         $a0, 0xB($s1)
    ctx->pc = 0x179d3cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x179d40: 0xba240008  swr         $a0, 0x8($s1)
    ctx->pc = 0x179d40u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_179d44:
    // 0x179d44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179d44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179d48: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179d48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179d4c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179d4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179d50: 0x3e00008  jr          $ra
    ctx->pc = 0x179D50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179D50u;
            // 0x179d54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179C50u: goto label_179c50;
            case 0x179C68u: goto label_179c68;
            case 0x179C94u: goto label_179c94;
            case 0x179CB0u: goto label_179cb0;
            case 0x179CD4u: goto label_179cd4;
            case 0x179D04u: goto label_179d04;
            case 0x179D20u: goto label_179d20;
            case 0x179D44u: goto label_179d44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179D58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
