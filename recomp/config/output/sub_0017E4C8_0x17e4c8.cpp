#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E4C8
// Address: 0x17e4c8 - 0x17e6a0
void sub_0017E4C8_0x17e4c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E4C8_0x17e4c8");
#endif

    switch (ctx->pc) {
        case 0x17e554u: goto label_17e554;
        case 0x17e570u: goto label_17e570;
        case 0x17e58cu: goto label_17e58c;
        case 0x17e5d8u: goto label_17e5d8;
        case 0x17e618u: goto label_17e618;
        case 0x17e670u: goto label_17e670;
        case 0x17e68cu: goto label_17e68c;
        default: break;
    }

    ctx->pc = 0x17e4c8u;

    // 0x17e4c8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17e4c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17e4cc: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x17e4ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x17e4d0: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x17e4d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x17e4d4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e4d4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e4d8: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x17e4d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x17e4dc: 0x27b10010  addiu       $s1, $sp, 0x10
    ctx->pc = 0x17e4dcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17e4e0: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x17e4e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x17e4e4: 0x27b20020  addiu       $s2, $sp, 0x20
    ctx->pc = 0x17e4e4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x17e4e8: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x17e4e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x17e4ec: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x17e4ecu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e4f0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17e4f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x17e4f4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17e4f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17e4f8: 0x246a1538  addiu       $t2, $v1, 0x1538
    ctx->pc = 0x17e4f8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 3), 5432));
    // 0x17e4fc: 0x69470007  ldl         $a3, 0x7($t2)
    ctx->pc = 0x17e4fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 10), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x17e500: 0x6d470000  ldr         $a3, 0x0($t2)
    ctx->pc = 0x17e500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 10), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x17e504: 0xb3a70007  sdl         $a3, 0x7($sp)
    ctx->pc = 0x17e504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17e508: 0xb7a70000  sdr         $a3, 0x0($sp)
    ctx->pc = 0x17e508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17e50c: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17e50cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17e510: 0x24a91550  addiu       $t1, $a1, 0x1550
    ctx->pc = 0x17e510u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 5), 5456));
    // 0x17e514: 0x69230007  ldl         $v1, 0x7($t1)
    ctx->pc = 0x17e514u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x17e518: 0x6d230000  ldr         $v1, 0x0($t1)
    ctx->pc = 0x17e518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x17e51c: 0xb2230007  sdl         $v1, 0x7($s1)
    ctx->pc = 0x17e51cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17e520: 0xb6230000  sdr         $v1, 0x0($s1)
    ctx->pc = 0x17e520u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17e524: 0x26040002  addiu       $a0, $s0, 0x2
    ctx->pc = 0x17e524u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x17e528: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x17e528u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x17e52c: 0x24c71568  addiu       $a3, $a2, 0x1568
    ctx->pc = 0x17e52cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 5480));
    // 0x17e530: 0x68ea0007  ldl         $t2, 0x7($a3)
    ctx->pc = 0x17e530u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem << shift)); }
    // 0x17e534: 0x6cea0000  ldr         $t2, 0x0($a3)
    ctx->pc = 0x17e534u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem >> shift)); }
    // 0x17e538: 0xb24a0007  sdl         $t2, 0x7($s2)
    ctx->pc = 0x17e538u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17e53c: 0xb64a0000  sdr         $t2, 0x0($s2)
    ctx->pc = 0x17e53cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17e540: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x17e540u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e544: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17e544u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17e548: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x17e548u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x17e54c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x17E54Cu;
    SET_GPR_U32(ctx, 31, 0x17E554u);
    ctx->pc = 0x17E550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E54Cu;
            // 0x17e550: 0x8c650000  lw          $a1, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E554u; }
        if (ctx->pc != 0x17E554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E554u; }
        if (ctx->pc != 0x17E554u) { return; }
    }
    ctx->pc = 0x17E554u;
label_17e554:
    // 0x17e554: 0x8e630004  lw          $v1, 0x4($s3)
    ctx->pc = 0x17e554u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x17e558: 0x26040003  addiu       $a0, $s0, 0x3
    ctx->pc = 0x17e558u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 3));
    // 0x17e55c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x17e55cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e560: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x17e560u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x17e564: 0x2238821  addu        $s1, $s1, $v1
    ctx->pc = 0x17e564u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x17e568: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x17E568u;
    SET_GPR_U32(ctx, 31, 0x17E570u);
    ctx->pc = 0x17E56Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E568u;
            // 0x17e56c: 0x8e250000  lw          $a1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E570u; }
        if (ctx->pc != 0x17E570u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E570u; }
        if (ctx->pc != 0x17E570u) { return; }
    }
    ctx->pc = 0x17E570u;
label_17e570:
    // 0x17e570: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x17e570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x17e574: 0x26040004  addiu       $a0, $s0, 0x4
    ctx->pc = 0x17e574u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17e578: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x17e578u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e57c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x17e57cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x17e580: 0x2439021  addu        $s2, $s2, $v1
    ctx->pc = 0x17e580u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x17e584: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x17E584u;
    SET_GPR_U32(ctx, 31, 0x17E58Cu);
    ctx->pc = 0x17E588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E584u;
            // 0x17e588: 0x8e450000  lw          $a1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E58Cu; }
        if (ctx->pc != 0x17E58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E58Cu; }
        if (ctx->pc != 0x17E58Cu) { return; }
    }
    ctx->pc = 0x17E58Cu;
label_17e58c:
    // 0x17e58c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17e58cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17e590: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x17e590u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17e594: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x17e594u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17e598: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x17e598u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17e59c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x17e59cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17e5a0: 0x3e00008  jr          $ra
    ctx->pc = 0x17E5A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E5A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5A0u;
            // 0x17e5a4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E554u: goto label_17e554;
            case 0x17E570u: goto label_17e570;
            case 0x17E58Cu: goto label_17e58c;
            case 0x17E5BCu: goto label_17e5bc;
            case 0x17E5C8u: goto label_17e5c8;
            case 0x17E5D8u: goto label_17e5d8;
            case 0x17E5DCu: goto label_17e5dc;
            case 0x17E5FCu: goto label_17e5fc;
            case 0x17E608u: goto label_17e608;
            case 0x17E618u: goto label_17e618;
            case 0x17E61Cu: goto label_17e61c;
            case 0x17E644u: goto label_17e644;
            case 0x17E650u: goto label_17e650;
            case 0x17E670u: goto label_17e670;
            case 0x17E68Cu: goto label_17e68c;
            case 0x17E690u: goto label_17e690;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E5A8u;
    // 0x17e5a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17e5a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17e5ac: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E5ACu;
    {
        const bool branch_taken_0x17e5ac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5ACu;
            // 0x17e5b0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5ac) {
            ctx->pc = 0x17E5BCu;
            goto label_17e5bc;
        }
    }
    ctx->pc = 0x17E5B4u;
    // 0x17e5b4: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E5B4u;
    {
        const bool branch_taken_0x17e5b4 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17E5B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5B4u;
            // 0x17e5b8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5b4) {
            ctx->pc = 0x17E5C8u;
            goto label_17e5c8;
        }
    }
    ctx->pc = 0x17E5BCu;
label_17e5bc:
    // 0x17e5bc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17E5BCu;
    {
        const bool branch_taken_0x17e5bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5BCu;
            // 0x17e5c0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5bc) {
            ctx->pc = 0x17E5DCu;
            goto label_17e5dc;
        }
    }
    ctx->pc = 0x17E5C4u;
    // 0x17e5c4: 0x0  nop
    ctx->pc = 0x17e5c4u;
    // NOP
label_17e5c8:
    // 0x17e5c8: 0x24840012  addiu       $a0, $a0, 0x12
    ctx->pc = 0x17e5c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18));
    // 0x17e5cc: 0x24a51530  addiu       $a1, $a1, 0x1530
    ctx->pc = 0x17e5ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5424));
    // 0x17e5d0: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E5D0u;
    SET_GPR_U32(ctx, 31, 0x17E5D8u);
    ctx->pc = 0x17E5D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5D0u;
            // 0x17e5d4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E5D8u; }
        if (ctx->pc != 0x17E5D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E5D8u; }
        if (ctx->pc != 0x17E5D8u) { return; }
    }
    ctx->pc = 0x17E5D8u;
label_17e5d8:
    // 0x17e5d8: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x17e5d8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_17e5dc:
    // 0x17e5dc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17e5dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e5e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17E5E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5E0u;
            // 0x17e5e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E554u: goto label_17e554;
            case 0x17E570u: goto label_17e570;
            case 0x17E58Cu: goto label_17e58c;
            case 0x17E5BCu: goto label_17e5bc;
            case 0x17E5C8u: goto label_17e5c8;
            case 0x17E5D8u: goto label_17e5d8;
            case 0x17E5DCu: goto label_17e5dc;
            case 0x17E5FCu: goto label_17e5fc;
            case 0x17E608u: goto label_17e608;
            case 0x17E618u: goto label_17e618;
            case 0x17E61Cu: goto label_17e61c;
            case 0x17E644u: goto label_17e644;
            case 0x17E650u: goto label_17e650;
            case 0x17E670u: goto label_17e670;
            case 0x17E68Cu: goto label_17e68c;
            case 0x17E690u: goto label_17e690;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E5E8u;
    // 0x17e5e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17e5e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17e5ec: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E5ECu;
    {
        const bool branch_taken_0x17e5ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E5F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5ECu;
            // 0x17e5f0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5ec) {
            ctx->pc = 0x17E5FCu;
            goto label_17e5fc;
        }
    }
    ctx->pc = 0x17E5F4u;
    // 0x17e5f4: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E5F4u;
    {
        const bool branch_taken_0x17e5f4 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17E5F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5F4u;
            // 0x17e5f8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5f4) {
            ctx->pc = 0x17E608u;
            goto label_17e608;
        }
    }
    ctx->pc = 0x17E5FCu;
label_17e5fc:
    // 0x17e5fc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17E5FCu;
    {
        const bool branch_taken_0x17e5fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5FCu;
            // 0x17e600: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5fc) {
            ctx->pc = 0x17E61Cu;
            goto label_17e61c;
        }
    }
    ctx->pc = 0x17E604u;
    // 0x17e604: 0x0  nop
    ctx->pc = 0x17e604u;
    // NOP
label_17e608:
    // 0x17e608: 0x24840013  addiu       $a0, $a0, 0x13
    ctx->pc = 0x17e608u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19));
    // 0x17e60c: 0x24a51548  addiu       $a1, $a1, 0x1548
    ctx->pc = 0x17e60cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5448));
    // 0x17e610: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E610u;
    SET_GPR_U32(ctx, 31, 0x17E618u);
    ctx->pc = 0x17E614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E610u;
            // 0x17e614: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E618u; }
        if (ctx->pc != 0x17E618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E618u; }
        if (ctx->pc != 0x17E618u) { return; }
    }
    ctx->pc = 0x17E618u;
label_17e618:
    // 0x17e618: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x17e618u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_17e61c:
    // 0x17e61c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17e61cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e620: 0x3e00008  jr          $ra
    ctx->pc = 0x17E620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E620u;
            // 0x17e624: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E554u: goto label_17e554;
            case 0x17E570u: goto label_17e570;
            case 0x17E58Cu: goto label_17e58c;
            case 0x17E5BCu: goto label_17e5bc;
            case 0x17E5C8u: goto label_17e5c8;
            case 0x17E5D8u: goto label_17e5d8;
            case 0x17E5DCu: goto label_17e5dc;
            case 0x17E5FCu: goto label_17e5fc;
            case 0x17E608u: goto label_17e608;
            case 0x17E618u: goto label_17e618;
            case 0x17E61Cu: goto label_17e61c;
            case 0x17E644u: goto label_17e644;
            case 0x17E650u: goto label_17e650;
            case 0x17E670u: goto label_17e670;
            case 0x17E68Cu: goto label_17e68c;
            case 0x17E690u: goto label_17e690;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E628u;
    // 0x17e628: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17e628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17e62c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17e62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17e630: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e630u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e634: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E634u;
    {
        const bool branch_taken_0x17e634 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E634u;
            // 0x17e638: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e634) {
            ctx->pc = 0x17E644u;
            goto label_17e644;
        }
    }
    ctx->pc = 0x17E63Cu;
    // 0x17e63c: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E63Cu;
    {
        const bool branch_taken_0x17e63c = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17E640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E63Cu;
            // 0x17e640: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e63c) {
            ctx->pc = 0x17E650u;
            goto label_17e650;
        }
    }
    ctx->pc = 0x17E644u;
label_17e644:
    // 0x17e644: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x17E644u;
    {
        const bool branch_taken_0x17e644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E644u;
            // 0x17e648: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e644) {
            ctx->pc = 0x17E690u;
            goto label_17e690;
        }
    }
    ctx->pc = 0x17E64Cu;
    // 0x17e64c: 0x0  nop
    ctx->pc = 0x17e64cu;
    // NOP
label_17e650:
    // 0x17e650: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17e650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e654: 0x24a51570  addiu       $a1, $a1, 0x1570
    ctx->pc = 0x17e654u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5488));
    // 0x17e658: 0x82020010  lb          $v0, 0x10($s0)
    ctx->pc = 0x17e658u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17e65c: 0x82030011  lb          $v1, 0x11($s0)
    ctx->pc = 0x17e65cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 17)));
    // 0x17e660: 0xa3a20000  sb          $v0, 0x0($sp)
    ctx->pc = 0x17e660u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x17e664: 0xa3a30001  sb          $v1, 0x1($sp)
    ctx->pc = 0x17e664u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x17e668: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E668u;
    SET_GPR_U32(ctx, 31, 0x17E670u);
    ctx->pc = 0x17E66Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E668u;
            // 0x17e66c: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E670u; }
        if (ctx->pc != 0x17E670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E670u; }
        if (ctx->pc != 0x17E670u) { return; }
    }
    ctx->pc = 0x17E670u;
label_17e670:
    // 0x17e670: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17e670u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17e674: 0x26040014  addiu       $a0, $s0, 0x14
    ctx->pc = 0x17e674u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17e678: 0x24a51560  addiu       $a1, $a1, 0x1560
    ctx->pc = 0x17e678u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5472));
    // 0x17e67c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E67Cu;
    {
        const bool branch_taken_0x17e67c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E67Cu;
            // 0x17e680: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e67c) {
            ctx->pc = 0x17E690u;
            goto label_17e690;
        }
    }
    ctx->pc = 0x17E684u;
    // 0x17e684: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E684u;
    SET_GPR_U32(ctx, 31, 0x17E68Cu);
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E68Cu; }
        if (ctx->pc != 0x17E68Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E68Cu; }
        if (ctx->pc != 0x17E68Cu) { return; }
    }
    ctx->pc = 0x17E68Cu;
label_17e68c:
    // 0x17e68c: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x17e68cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_17e690:
    // 0x17e690: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17e690u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e694: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17e694u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e698: 0x3e00008  jr          $ra
    ctx->pc = 0x17E698u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E698u;
            // 0x17e69c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E554u: goto label_17e554;
            case 0x17E570u: goto label_17e570;
            case 0x17E58Cu: goto label_17e58c;
            case 0x17E5BCu: goto label_17e5bc;
            case 0x17E5C8u: goto label_17e5c8;
            case 0x17E5D8u: goto label_17e5d8;
            case 0x17E5DCu: goto label_17e5dc;
            case 0x17E5FCu: goto label_17e5fc;
            case 0x17E608u: goto label_17e608;
            case 0x17E618u: goto label_17e618;
            case 0x17E61Cu: goto label_17e61c;
            case 0x17E644u: goto label_17e644;
            case 0x17E650u: goto label_17e650;
            case 0x17E670u: goto label_17e670;
            case 0x17E68Cu: goto label_17e68c;
            case 0x17E690u: goto label_17e690;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E6A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
