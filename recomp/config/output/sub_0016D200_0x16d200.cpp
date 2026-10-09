#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D200
// Address: 0x16d200 - 0x16d2b0
void sub_0016D200_0x16d200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D200_0x16d200");
#endif

    switch (ctx->pc) {
        case 0x16d234u: goto label_16d234;
        default: break;
    }

    ctx->pc = 0x16d200u;

    // 0x16d200: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16d200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16d204: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16d204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16d208: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16d208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16d20c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16d20cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d210: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16d210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16d214: 0x26320d2c  addiu       $s2, $s1, 0xD2C
    ctx->pc = 0x16d214u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 3372));
    // 0x16d218: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16d218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16d21c: 0x26301b28  addiu       $s0, $s1, 0x1B28
    ctx->pc = 0x16d21cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 6952));
    // 0x16d220: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x16d220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x16d224: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D224u;
    {
        const bool branch_taken_0x16d224 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x16D228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D224u;
            // 0x16d228: 0x8e050010  lw          $a1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d224) {
            ctx->pc = 0x16D23Cu;
            goto label_16d23c;
        }
    }
    ctx->pc = 0x16D22Cu;
    // 0x16d22c: 0xc059d4a  jal         func_167528
    ctx->pc = 0x16D22Cu;
    SET_GPR_U32(ctx, 31, 0x16D234u);
    ctx->pc = 0x167528u;
    if (runtime->hasFunction(0x167528u)) {
        auto targetFn = runtime->lookupFunction(0x167528u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D234u; }
        if (ctx->pc != 0x16D234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167528_0x167528(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D234u; }
        if (ctx->pc != 0x16D234u) { return; }
    }
    ctx->pc = 0x16D234u;
label_16d234:
    // 0x16d234: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x16d234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x16d238: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x16d238u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
label_16d23c:
    // 0x16d23c: 0x8e420020  lw          $v0, 0x20($s2)
    ctx->pc = 0x16d23cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x16d240: 0x4410015  bgez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x16D240u;
    {
        const bool branch_taken_0x16d240 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x16D244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D240u;
            // 0x16d244: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d240) {
            ctx->pc = 0x16D298u;
            goto label_16d298;
        }
    }
    ctx->pc = 0x16D248u;
    // 0x16d248: 0x6a220d0b  ldl         $v0, 0xD0B($s1)
    ctx->pc = 0x16d248u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3339); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16d24c: 0x6e220d04  ldr         $v0, 0xD04($s1)
    ctx->pc = 0x16d24cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3332); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16d250: 0x6a230d13  ldl         $v1, 0xD13($s1)
    ctx->pc = 0x16d250u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3347); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16d254: 0x6e230d0c  ldr         $v1, 0xD0C($s1)
    ctx->pc = 0x16d254u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3340); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16d258: 0x6a240d1b  ldl         $a0, 0xD1B($s1)
    ctx->pc = 0x16d258u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3355); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16d25c: 0x6e240d14  ldr         $a0, 0xD14($s1)
    ctx->pc = 0x16d25cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3348); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16d260: 0x6a250d23  ldl         $a1, 0xD23($s1)
    ctx->pc = 0x16d260u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3363); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x16d264: 0x6e250d1c  ldr         $a1, 0xD1C($s1)
    ctx->pc = 0x16d264u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3356); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x16d268: 0xb2420007  sdl         $v0, 0x7($s2)
    ctx->pc = 0x16d268u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d26c: 0xb6420000  sdr         $v0, 0x0($s2)
    ctx->pc = 0x16d26cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d270: 0xb243000f  sdl         $v1, 0xF($s2)
    ctx->pc = 0x16d270u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d274: 0xb6430008  sdr         $v1, 0x8($s2)
    ctx->pc = 0x16d274u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d278: 0xb2440017  sdl         $a0, 0x17($s2)
    ctx->pc = 0x16d278u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d27c: 0xb6440010  sdr         $a0, 0x10($s2)
    ctx->pc = 0x16d27cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d280: 0xb245001f  sdl         $a1, 0x1F($s2)
    ctx->pc = 0x16d280u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d284: 0xb6450018  sdr         $a1, 0x18($s2)
    ctx->pc = 0x16d284u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d288: 0x6a220d2b  ldl         $v0, 0xD2B($s1)
    ctx->pc = 0x16d288u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3371); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16d28c: 0x6e220d24  ldr         $v0, 0xD24($s1)
    ctx->pc = 0x16d28cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3364); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16d290: 0xb2420027  sdl         $v0, 0x27($s2)
    ctx->pc = 0x16d290u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d294: 0xb6420020  sdr         $v0, 0x20($s2)
    ctx->pc = 0x16d294u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_16d298:
    // 0x16d298: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16d298u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16d29c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16d29cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16d2a0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16d2a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16d2a4: 0x3e00008  jr          $ra
    ctx->pc = 0x16D2A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D2A4u;
            // 0x16d2a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D234u: goto label_16d234;
            case 0x16D23Cu: goto label_16d23c;
            case 0x16D298u: goto label_16d298;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D2ACu;
    // 0x16d2ac: 0x0  nop
    ctx->pc = 0x16d2acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
