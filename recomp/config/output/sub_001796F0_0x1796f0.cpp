#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001796F0
// Address: 0x1796f0 - 0x179930
void sub_001796F0_0x1796f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001796F0_0x1796f0");
#endif

    switch (ctx->pc) {
        case 0x179710u: goto label_179710;
        case 0x179728u: goto label_179728;
        case 0x179760u: goto label_179760;
        case 0x179778u: goto label_179778;
        case 0x179830u: goto label_179830;
        case 0x179878u: goto label_179878;
        case 0x1798c0u: goto label_1798c0;
        case 0x179908u: goto label_179908;
        default: break;
    }

    ctx->pc = 0x1796f0u;

    // 0x1796f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1796f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1796f4: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x1796f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x1796f8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1796f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1796fc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1796fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179700: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x179700u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x179704: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x179704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x179708: 0xc05e598  jal         func_179660
    ctx->pc = 0x179708u;
    SET_GPR_U32(ctx, 31, 0x179710u);
    ctx->pc = 0x17970Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179708u;
            // 0x17970c: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179660u;
    if (runtime->hasFunction(0x179660u)) {
        auto targetFn = runtime->lookupFunction(0x179660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179710u; }
        if (ctx->pc != 0x179710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179660_0x179660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179710u; }
        if (ctx->pc != 0x179710u) { return; }
    }
    ctx->pc = 0x179710u;
label_179710:
    // 0x179710: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x179710u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179714: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x179714u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179718: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x179718u;
    {
        const bool branch_taken_0x179718 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17971Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179718u;
            // 0x17971c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179718) {
            ctx->pc = 0x17972Cu;
            goto label_17972c;
        }
    }
    ctx->pc = 0x179720u;
    // 0x179720: 0xc05e64c  jal         func_179930
    ctx->pc = 0x179720u;
    SET_GPR_U32(ctx, 31, 0x179728u);
    ctx->pc = 0x179930u;
    if (runtime->hasFunction(0x179930u)) {
        auto targetFn = runtime->lookupFunction(0x179930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179728u; }
        if (ctx->pc != 0x179728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179930_0x179930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179728u; }
        if (ctx->pc != 0x179728u) { return; }
    }
    ctx->pc = 0x179728u;
label_179728:
    // 0x179728: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x179728u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_17972c:
    // 0x17972c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17972cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x179730: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x179730u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x179734: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x179734u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x179738: 0x3e00008  jr          $ra
    ctx->pc = 0x179738u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17973Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179738u;
            // 0x17973c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179710u: goto label_179710;
            case 0x179728u: goto label_179728;
            case 0x17972Cu: goto label_17972c;
            case 0x179760u: goto label_179760;
            case 0x179778u: goto label_179778;
            case 0x1797FCu: goto label_1797fc;
            case 0x179830u: goto label_179830;
            case 0x179848u: goto label_179848;
            case 0x179878u: goto label_179878;
            case 0x179890u: goto label_179890;
            case 0x1798C0u: goto label_1798c0;
            case 0x1798D8u: goto label_1798d8;
            case 0x179908u: goto label_179908;
            case 0x179920u: goto label_179920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179740u;
    // 0x179740: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179744: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179748: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x179748u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17974c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17974cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179750: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179754: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179754u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179758: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179758u;
    SET_GPR_U32(ctx, 31, 0x179760u);
    ctx->pc = 0x17975Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179758u;
            // 0x17975c: 0x245100e0  addiu       $s1, $v0, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179760u; }
        if (ctx->pc != 0x179760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179760u; }
        if (ctx->pc != 0x179760u) { return; }
    }
    ctx->pc = 0x179760u;
label_179760:
    // 0x179760: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x179760u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179764: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x179764u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179768: 0x10400024  beqz        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x179768u;
    {
        const bool branch_taken_0x179768 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17976Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179768u;
            // 0x17976c: 0x24060041  addiu       $a2, $zero, 0x41 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179768) {
            ctx->pc = 0x1797FCu;
            goto label_1797fc;
        }
    }
    ctx->pc = 0x179770u;
    // 0x179770: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x179770u;
    SET_GPR_U32(ctx, 31, 0x179778u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179778u; }
        if (ctx->pc != 0x179778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179778u; }
        if (ctx->pc != 0x179778u) { return; }
    }
    ctx->pc = 0x179778u;
label_179778:
    // 0x179778: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179778u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17977c: 0x6a230007  ldl         $v1, 0x7($s1)
    ctx->pc = 0x17977cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x179780: 0x6e230000  ldr         $v1, 0x0($s1)
    ctx->pc = 0x179780u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x179784: 0x6a24000f  ldl         $a0, 0xF($s1)
    ctx->pc = 0x179784u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x179788: 0x6e240008  ldr         $a0, 0x8($s1)
    ctx->pc = 0x179788u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x17978c: 0x6a250017  ldl         $a1, 0x17($s1)
    ctx->pc = 0x17978cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x179790: 0x6e250010  ldr         $a1, 0x10($s1)
    ctx->pc = 0x179790u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x179794: 0x6a26001f  ldl         $a2, 0x1F($s1)
    ctx->pc = 0x179794u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x179798: 0x6e260018  ldr         $a2, 0x18($s1)
    ctx->pc = 0x179798u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x17979c: 0xb2030007  sdl         $v1, 0x7($s0)
    ctx->pc = 0x17979cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797a0: 0xb6030000  sdr         $v1, 0x0($s0)
    ctx->pc = 0x1797a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797a4: 0xb204000f  sdl         $a0, 0xF($s0)
    ctx->pc = 0x1797a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797a8: 0xb6040008  sdr         $a0, 0x8($s0)
    ctx->pc = 0x1797a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797ac: 0xb2050017  sdl         $a1, 0x17($s0)
    ctx->pc = 0x1797acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797b0: 0xb6050010  sdr         $a1, 0x10($s0)
    ctx->pc = 0x1797b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797b4: 0xb206001f  sdl         $a2, 0x1F($s0)
    ctx->pc = 0x1797b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797b8: 0xb6060018  sdr         $a2, 0x18($s0)
    ctx->pc = 0x1797b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797bc: 0x6a230027  ldl         $v1, 0x27($s1)
    ctx->pc = 0x1797bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1797c0: 0x6e230020  ldr         $v1, 0x20($s1)
    ctx->pc = 0x1797c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1797c4: 0x6a24002f  ldl         $a0, 0x2F($s1)
    ctx->pc = 0x1797c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1797c8: 0x6e240028  ldr         $a0, 0x28($s1)
    ctx->pc = 0x1797c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1797cc: 0x6a250037  ldl         $a1, 0x37($s1)
    ctx->pc = 0x1797ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1797d0: 0x6e250030  ldr         $a1, 0x30($s1)
    ctx->pc = 0x1797d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1797d4: 0x6a26003f  ldl         $a2, 0x3F($s1)
    ctx->pc = 0x1797d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1797d8: 0x6e260038  ldr         $a2, 0x38($s1)
    ctx->pc = 0x1797d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1797dc: 0xb2030027  sdl         $v1, 0x27($s0)
    ctx->pc = 0x1797dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797e0: 0xb6030020  sdr         $v1, 0x20($s0)
    ctx->pc = 0x1797e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797e4: 0xb204002f  sdl         $a0, 0x2F($s0)
    ctx->pc = 0x1797e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797e8: 0xb6040028  sdr         $a0, 0x28($s0)
    ctx->pc = 0x1797e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797ec: 0xb2050037  sdl         $a1, 0x37($s0)
    ctx->pc = 0x1797ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797f0: 0xb6050030  sdr         $a1, 0x30($s0)
    ctx->pc = 0x1797f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797f4: 0xb206003f  sdl         $a2, 0x3F($s0)
    ctx->pc = 0x1797f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1797f8: 0xb6060038  sdr         $a2, 0x38($s0)
    ctx->pc = 0x1797f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_1797fc:
    // 0x1797fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1797fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179800: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179800u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179804: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179804u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179808: 0x3e00008  jr          $ra
    ctx->pc = 0x179808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17980Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179808u;
            // 0x17980c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179710u: goto label_179710;
            case 0x179728u: goto label_179728;
            case 0x17972Cu: goto label_17972c;
            case 0x179760u: goto label_179760;
            case 0x179778u: goto label_179778;
            case 0x1797FCu: goto label_1797fc;
            case 0x179830u: goto label_179830;
            case 0x179848u: goto label_179848;
            case 0x179878u: goto label_179878;
            case 0x179890u: goto label_179890;
            case 0x1798C0u: goto label_1798c0;
            case 0x1798D8u: goto label_1798d8;
            case 0x179908u: goto label_179908;
            case 0x179920u: goto label_179920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179810u;
    // 0x179810: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179814: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179818: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17981c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17981cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179820: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179824: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179824u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179828: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179828u;
    SET_GPR_U32(ctx, 31, 0x179830u);
    ctx->pc = 0x17982Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179828u;
            // 0x17982c: 0x24500080  addiu       $s0, $v0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179830u; }
        if (ctx->pc != 0x179830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179830u; }
        if (ctx->pc != 0x179830u) { return; }
    }
    ctx->pc = 0x179830u;
label_179830:
    // 0x179830: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179830u;
    {
        const bool branch_taken_0x179830 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179830) {
            ctx->pc = 0x179834u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179830u;
            // 0x179834: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179848u;
            goto label_179848;
        }
    }
    ctx->pc = 0x179838u;
    // 0x179838: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x179838u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17983c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17983cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179840: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179840u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x179844: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179844u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179848:
    // 0x179848: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179848u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17984c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17984cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179850: 0x3e00008  jr          $ra
    ctx->pc = 0x179850u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179850u;
            // 0x179854: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179710u: goto label_179710;
            case 0x179728u: goto label_179728;
            case 0x17972Cu: goto label_17972c;
            case 0x179760u: goto label_179760;
            case 0x179778u: goto label_179778;
            case 0x1797FCu: goto label_1797fc;
            case 0x179830u: goto label_179830;
            case 0x179848u: goto label_179848;
            case 0x179878u: goto label_179878;
            case 0x179890u: goto label_179890;
            case 0x1798C0u: goto label_1798c0;
            case 0x1798D8u: goto label_1798d8;
            case 0x179908u: goto label_179908;
            case 0x179920u: goto label_179920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179858u;
    // 0x179858: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17985c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17985cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179860: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179864: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179864u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179868: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17986c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x17986cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179870: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179870u;
    SET_GPR_U32(ctx, 31, 0x179878u);
    ctx->pc = 0x179874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179870u;
            // 0x179874: 0x24500080  addiu       $s0, $v0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179878u; }
        if (ctx->pc != 0x179878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179878u; }
        if (ctx->pc != 0x179878u) { return; }
    }
    ctx->pc = 0x179878u;
label_179878:
    // 0x179878: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179878u;
    {
        const bool branch_taken_0x179878 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179878) {
            ctx->pc = 0x17987Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179878u;
            // 0x17987c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179890u;
            goto label_179890;
        }
    }
    ctx->pc = 0x179880u;
    // 0x179880: 0x92030004  lbu         $v1, 0x4($s0)
    ctx->pc = 0x179880u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x179884: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179888: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179888u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x17988c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17988cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179890:
    // 0x179890: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179890u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179894: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179898: 0x3e00008  jr          $ra
    ctx->pc = 0x179898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17989Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179898u;
            // 0x17989c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179710u: goto label_179710;
            case 0x179728u: goto label_179728;
            case 0x17972Cu: goto label_17972c;
            case 0x179760u: goto label_179760;
            case 0x179778u: goto label_179778;
            case 0x1797FCu: goto label_1797fc;
            case 0x179830u: goto label_179830;
            case 0x179848u: goto label_179848;
            case 0x179878u: goto label_179878;
            case 0x179890u: goto label_179890;
            case 0x1798C0u: goto label_1798c0;
            case 0x1798D8u: goto label_1798d8;
            case 0x179908u: goto label_179908;
            case 0x179920u: goto label_179920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1798A0u;
    // 0x1798a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1798a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1798a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1798a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1798a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1798a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1798ac: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1798acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1798b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1798b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1798b4: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1798b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1798b8: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x1798B8u;
    SET_GPR_U32(ctx, 31, 0x1798C0u);
    ctx->pc = 0x1798BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1798B8u;
            // 0x1798bc: 0x24500080  addiu       $s0, $v0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1798C0u; }
        if (ctx->pc != 0x1798C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1798C0u; }
        if (ctx->pc != 0x1798C0u) { return; }
    }
    ctx->pc = 0x1798C0u;
label_1798c0:
    // 0x1798c0: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1798C0u;
    {
        const bool branch_taken_0x1798c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1798c0) {
            ctx->pc = 0x1798C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1798C0u;
            // 0x1798c4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1798D8u;
            goto label_1798d8;
        }
    }
    ctx->pc = 0x1798C8u;
    // 0x1798c8: 0x86030008  lh          $v1, 0x8($s0)
    ctx->pc = 0x1798c8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1798cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1798ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1798d0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1798d0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1798d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1798d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1798d8:
    // 0x1798d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1798d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1798dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1798dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1798e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1798E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1798E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1798E0u;
            // 0x1798e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179710u: goto label_179710;
            case 0x179728u: goto label_179728;
            case 0x17972Cu: goto label_17972c;
            case 0x179760u: goto label_179760;
            case 0x179778u: goto label_179778;
            case 0x1797FCu: goto label_1797fc;
            case 0x179830u: goto label_179830;
            case 0x179848u: goto label_179848;
            case 0x179878u: goto label_179878;
            case 0x179890u: goto label_179890;
            case 0x1798C0u: goto label_1798c0;
            case 0x1798D8u: goto label_1798d8;
            case 0x179908u: goto label_179908;
            case 0x179920u: goto label_179920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1798E8u;
    // 0x1798e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1798e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1798ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1798ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1798f0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1798f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1798f4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1798f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1798f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1798f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1798fc: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1798fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179900: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179900u;
    SET_GPR_U32(ctx, 31, 0x179908u);
    ctx->pc = 0x179904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179900u;
            // 0x179904: 0x24500080  addiu       $s0, $v0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179908u; }
        if (ctx->pc != 0x179908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179908u; }
        if (ctx->pc != 0x179908u) { return; }
    }
    ctx->pc = 0x179908u;
label_179908:
    // 0x179908: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179908u;
    {
        const bool branch_taken_0x179908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179908) {
            ctx->pc = 0x17990Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179908u;
            // 0x17990c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179920u;
            goto label_179920;
        }
    }
    ctx->pc = 0x179910u;
    // 0x179910: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x179910u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x179914: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179918: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179918u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x17991c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17991cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179920:
    // 0x179920: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179920u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179924: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179928: 0x3e00008  jr          $ra
    ctx->pc = 0x179928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17992Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179928u;
            // 0x17992c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179710u: goto label_179710;
            case 0x179728u: goto label_179728;
            case 0x17972Cu: goto label_17972c;
            case 0x179760u: goto label_179760;
            case 0x179778u: goto label_179778;
            case 0x1797FCu: goto label_1797fc;
            case 0x179830u: goto label_179830;
            case 0x179848u: goto label_179848;
            case 0x179878u: goto label_179878;
            case 0x179890u: goto label_179890;
            case 0x1798C0u: goto label_1798c0;
            case 0x1798D8u: goto label_1798d8;
            case 0x179908u: goto label_179908;
            case 0x179920u: goto label_179920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
