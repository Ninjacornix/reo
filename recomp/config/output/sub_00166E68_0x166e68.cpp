#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166E68
// Address: 0x166e68 - 0x166f08
void sub_00166E68_0x166e68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166E68_0x166e68");
#endif

    switch (ctx->pc) {
        case 0x166e98u: goto label_166e98;
        case 0x166ed4u: goto label_166ed4;
        case 0x166ee4u: goto label_166ee4;
        case 0x166eecu: goto label_166eec;
        default: break;
    }

    ctx->pc = 0x166e68u;

    // 0x166e68: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x166e68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x166e6c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x166e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x166e70: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166e70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e74: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x166e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x166e78: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x166e78u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e7c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x166e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x166e80: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x166e80u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e84: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x166e84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e88: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x166e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x166e8c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x166e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x166e90: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x166E90u;
    SET_GPR_U32(ctx, 31, 0x166E98u);
    ctx->pc = 0x166E94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166E90u;
            // 0x166e94: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166E98u; }
        if (ctx->pc != 0x166E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166E98u; }
        if (ctx->pc != 0x166E98u) { return; }
    }
    ctx->pc = 0x166E98u;
label_166e98:
    // 0x166e98: 0xae510004  sw          $s1, 0x4($s2)
    ctx->pc = 0x166e98u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 17));
    // 0x166e9c: 0x26040018  addiu       $a0, $s0, 0x18
    ctx->pc = 0x166e9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x166ea0: 0x6a620007  ldl         $v0, 0x7($s3)
    ctx->pc = 0x166ea0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x166ea4: 0x6e620000  ldr         $v0, 0x0($s3)
    ctx->pc = 0x166ea4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x166ea8: 0x6a63000f  ldl         $v1, 0xF($s3)
    ctx->pc = 0x166ea8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x166eac: 0x6e630008  ldr         $v1, 0x8($s3)
    ctx->pc = 0x166eacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x166eb0: 0x6a650017  ldl         $a1, 0x17($s3)
    ctx->pc = 0x166eb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x166eb4: 0x6e650010  ldr         $a1, 0x10($s3)
    ctx->pc = 0x166eb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x166eb8: 0xb2020007  sdl         $v0, 0x7($s0)
    ctx->pc = 0x166eb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x166ebc: 0xb6020000  sdr         $v0, 0x0($s0)
    ctx->pc = 0x166ebcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x166ec0: 0xb203000f  sdl         $v1, 0xF($s0)
    ctx->pc = 0x166ec0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x166ec4: 0xb6030008  sdr         $v1, 0x8($s0)
    ctx->pc = 0x166ec4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x166ec8: 0xb2050017  sdl         $a1, 0x17($s0)
    ctx->pc = 0x166ec8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x166ecc: 0xc059bc2  jal         func_166F08
    ctx->pc = 0x166ECCu;
    SET_GPR_U32(ctx, 31, 0x166ED4u);
    ctx->pc = 0x166ED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166ECCu;
            // 0x166ed0: 0xb6050010  sdr         $a1, 0x10($s0) (Delay Slot)
        { uint32_t addr = ADD32(GPR_U32(ctx, 16), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x166F08u;
    if (runtime->hasFunction(0x166F08u)) {
        auto targetFn = runtime->lookupFunction(0x166F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166ED4u; }
        if (ctx->pc != 0x166ED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166F08_0x166f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166ED4u; }
        if (ctx->pc != 0x166ED4u) { return; }
    }
    ctx->pc = 0x166ED4u;
label_166ed4:
    // 0x166ed4: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x166ed4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x166ed8: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x166ed8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x166edc: 0xc05d040  jal         func_174100
    ctx->pc = 0x166EDCu;
    SET_GPR_U32(ctx, 31, 0x166EE4u);
    ctx->pc = 0x166EE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166EDCu;
            // 0x166ee0: 0x26040028  addiu       $a0, $s0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174100u;
    if (runtime->hasFunction(0x174100u)) {
        auto targetFn = runtime->lookupFunction(0x174100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166EE4u; }
        if (ctx->pc != 0x166EE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174100_0x174100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166EE4u; }
        if (ctx->pc != 0x166EE4u) { return; }
    }
    ctx->pc = 0x166EE4u;
label_166ee4:
    // 0x166ee4: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x166EE4u;
    SET_GPR_U32(ctx, 31, 0x166EECu);
    ctx->pc = 0x166EE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166EE4u;
            // 0x166ee8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166EECu; }
        if (ctx->pc != 0x166EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166EECu; }
        if (ctx->pc != 0x166EECu) { return; }
    }
    ctx->pc = 0x166EECu;
label_166eec:
    // 0x166eec: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x166eecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166ef0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x166ef0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x166ef4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x166ef4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x166ef8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x166ef8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x166efc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x166efcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x166f00: 0x3e00008  jr          $ra
    ctx->pc = 0x166F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166F00u;
            // 0x166f04: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166E98u: goto label_166e98;
            case 0x166ED4u: goto label_166ed4;
            case 0x166EE4u: goto label_166ee4;
            case 0x166EECu: goto label_166eec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166F08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
