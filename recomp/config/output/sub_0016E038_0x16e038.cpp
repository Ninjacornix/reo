#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E038
// Address: 0x16e038 - 0x16e0e0
void sub_0016E038_0x16e038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E038_0x16e038");
#endif

    switch (ctx->pc) {
        case 0x16e068u: goto label_16e068;
        case 0x16e07cu: goto label_16e07c;
        default: break;
    }

    ctx->pc = 0x16e038u;

    // 0x16e038: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16e038u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16e03c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16e03cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16e040: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x16e040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x16e044: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16e044u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e048: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16e048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16e04c: 0x26300cdc  addiu       $s0, $s1, 0xCDC
    ctx->pc = 0x16e04cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 3292));
    // 0x16e050: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x16e050u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e054: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x16e054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16e058: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x16E058u;
    {
        const bool branch_taken_0x16e058 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E05Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E058u;
            // 0x16e05c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e058) {
            ctx->pc = 0x16E0CCu;
            goto label_16e0cc;
        }
    }
    ctx->pc = 0x16E060u;
    // 0x16e060: 0xc05b87c  jal         func_16E1F0
    ctx->pc = 0x16E060u;
    SET_GPR_U32(ctx, 31, 0x16E068u);
    ctx->pc = 0x16E1F0u;
    if (runtime->hasFunction(0x16E1F0u)) {
        auto targetFn = runtime->lookupFunction(0x16E1F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E068u; }
        if (ctx->pc != 0x16E068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E1F0_0x16e1f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E068u; }
        if (ctx->pc != 0x16E068u) { return; }
    }
    ctx->pc = 0x16E068u;
label_16e068:
    // 0x16e068: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16e068u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e06c: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x16e06cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x16e070: 0x27a60024  addiu       $a2, $sp, 0x24
    ctx->pc = 0x16e070u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    // 0x16e074: 0xc05da70  jal         func_1769C0
    ctx->pc = 0x16E074u;
    SET_GPR_U32(ctx, 31, 0x16E07Cu);
    ctx->pc = 0x16E078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E074u;
            // 0x16e078: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769C0u;
    if (runtime->hasFunction(0x1769C0u)) {
        auto targetFn = runtime->lookupFunction(0x1769C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E07Cu; }
        if (ctx->pc != 0x16E07Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769C0_0x1769c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E07Cu; }
        if (ctx->pc != 0x16E07Cu) { return; }
    }
    ctx->pc = 0x16E07Cu;
label_16e07c:
    // 0x16e07c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16e07cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16e080: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x16e080u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16e084: 0x8fa40024  lw          $a0, 0x24($sp)
    ctx->pc = 0x16e084u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x16e088: 0x6ba50007  ldl         $a1, 0x7($sp)
    ctx->pc = 0x16e088u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x16e08c: 0x6fa50000  ldr         $a1, 0x0($sp)
    ctx->pc = 0x16e08cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x16e090: 0x6ba6000f  ldl         $a2, 0xF($sp)
    ctx->pc = 0x16e090u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x16e094: 0x6fa60008  ldr         $a2, 0x8($sp)
    ctx->pc = 0x16e094u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x16e098: 0x6ba70017  ldl         $a3, 0x17($sp)
    ctx->pc = 0x16e098u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x16e09c: 0x6fa70010  ldr         $a3, 0x10($sp)
    ctx->pc = 0x16e09cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x16e0a0: 0x8fa80018  lw          $t0, 0x18($sp)
    ctx->pc = 0x16e0a0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16e0a4: 0xb2250ce7  sdl         $a1, 0xCE7($s1)
    ctx->pc = 0x16e0a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3303); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e0a8: 0xb6250ce0  sdr         $a1, 0xCE0($s1)
    ctx->pc = 0x16e0a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3296); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e0ac: 0xb2260cef  sdl         $a2, 0xCEF($s1)
    ctx->pc = 0x16e0acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3311); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e0b0: 0xb6260ce8  sdr         $a2, 0xCE8($s1)
    ctx->pc = 0x16e0b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3304); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e0b4: 0xb2270cf7  sdl         $a3, 0xCF7($s1)
    ctx->pc = 0x16e0b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3319); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e0b8: 0xb6270cf0  sdr         $a3, 0xCF0($s1)
    ctx->pc = 0x16e0b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3312); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e0bc: 0xae280cf8  sw          $t0, 0xCF8($s1)
    ctx->pc = 0x16e0bcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 3320), GPR_U32(ctx, 8));
    // 0x16e0c0: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x16e0c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x16e0c4: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x16e0c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x16e0c8: 0xae040024  sw          $a0, 0x24($s0)
    ctx->pc = 0x16e0c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 4));
label_16e0cc:
    // 0x16e0cc: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x16e0ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16e0d0: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x16e0d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16e0d4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16e0d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16e0d8: 0x3e00008  jr          $ra
    ctx->pc = 0x16E0D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E0DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E0D8u;
            // 0x16e0dc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E068u: goto label_16e068;
            case 0x16E07Cu: goto label_16e07c;
            case 0x16E0CCu: goto label_16e0cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E0E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
