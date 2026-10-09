#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158EB8
// Address: 0x158eb8 - 0x158f34
void sub_00158EB8_0x158eb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158EB8_0x158eb8");
#endif

    switch (ctx->pc) {
        case 0x158ed4u: goto label_158ed4;
        default: break;
    }

    ctx->pc = 0x158eb8u;

    // 0x158eb8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x158eb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x158ebc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158ebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158ec0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x158ec0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158ec4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x158ec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158ec8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x158ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x158ecc: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x158ECCu;
    SET_GPR_U32(ctx, 31, 0x158ED4u);
    ctx->pc = 0x158ED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158ECCu;
            // 0x158ed0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158ED4u; }
        if (ctx->pc != 0x158ED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158ED4u; }
        if (ctx->pc != 0x158ED4u) { return; }
    }
    ctx->pc = 0x158ED4u;
label_158ed4:
    // 0x158ed4: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x158ed4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x158ed8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x158ED8u;
    {
        const bool branch_taken_0x158ed8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x158EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158ED8u;
            // 0x158edc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158ed8) {
            ctx->pc = 0x158EF8u;
            goto label_158ef8;
        }
    }
    ctx->pc = 0x158EE0u;
    // 0x158ee0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x158ee0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158ee4: 0x34a50204  ori         $a1, $a1, 0x204
    ctx->pc = 0x158ee4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)516);
    // 0x158ee8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x158ee8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158eec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x158eecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x158ef0: 0x80563ce  j           func_158F38
    ctx->pc = 0x158EF0u;
    ctx->pc = 0x158EF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158EF0u;
            // 0x158ef4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x158EF8u;
label_158ef8:
    // 0x158ef8: 0x6a03022b  ldl         $v1, 0x22B($s0)
    ctx->pc = 0x158ef8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 555); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x158efc: 0x6e030224  ldr         $v1, 0x224($s0)
    ctx->pc = 0x158efcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 548); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x158f00: 0x6a040233  ldl         $a0, 0x233($s0)
    ctx->pc = 0x158f00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 563); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x158f04: 0x6e04022c  ldr         $a0, 0x22C($s0)
    ctx->pc = 0x158f04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 556); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x158f08: 0x8e050234  lw          $a1, 0x234($s0)
    ctx->pc = 0x158f08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 564)));
    // 0x158f0c: 0xb2230007  sdl         $v1, 0x7($s1)
    ctx->pc = 0x158f0cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x158f10: 0xb6230000  sdr         $v1, 0x0($s1)
    ctx->pc = 0x158f10u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x158f14: 0xb224000f  sdl         $a0, 0xF($s1)
    ctx->pc = 0x158f14u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x158f18: 0xb6240008  sdr         $a0, 0x8($s1)
    ctx->pc = 0x158f18u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x158f1c: 0xae250010  sw          $a1, 0x10($s1)
    ctx->pc = 0x158f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 5));
    // 0x158f20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x158f20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158f24: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x158f24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158f28: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x158f28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x158f2c: 0x3e00008  jr          $ra
    ctx->pc = 0x158F2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158F2Cu;
            // 0x158f30: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158ED4u: goto label_158ed4;
            case 0x158EF8u: goto label_158ef8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158F34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
