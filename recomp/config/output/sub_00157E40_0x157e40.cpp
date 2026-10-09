#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00157E40
// Address: 0x157e40 - 0x157ef0
void sub_00157E40_0x157e40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00157E40_0x157e40");
#endif

    switch (ctx->pc) {
        case 0x157e6cu: goto label_157e6c;
        default: break;
    }

    ctx->pc = 0x157e40u;

    // 0x157e40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x157e40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x157e44: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x157e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x157e48: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x157e48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x157e4c: 0x108140  sll         $s0, $s0, 5
    ctx->pc = 0x157e4cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 5));
    // 0x157e50: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x157e50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x157e54: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x157e54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x157e58: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x157e58u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x157e5c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x157e5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x157e60: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x157e60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x157e64: 0xc0560f2  jal         func_1583C8
    ctx->pc = 0x157E64u;
    SET_GPR_U32(ctx, 31, 0x157E6Cu);
    ctx->pc = 0x157E68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x157E64u;
            // 0x157e68: 0x26100040  addiu       $s0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1583C8u;
    if (runtime->hasFunction(0x1583C8u)) {
        auto targetFn = runtime->lookupFunction(0x1583C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x157E6Cu; }
        if (ctx->pc != 0x157E6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583C8_0x1583c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x157E6Cu; }
        if (ctx->pc != 0x157E6Cu) { return; }
    }
    ctx->pc = 0x157E6Cu;
label_157e6c:
    // 0x157e6c: 0x3c05ff02  lui         $a1, 0xFF02
    ctx->pc = 0x157e6cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65282 << 16));
    // 0x157e70: 0x2308821  addu        $s1, $s1, $s0
    ctx->pc = 0x157e70u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x157e74: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x157e74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x157e78: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x157E78u;
    {
        const bool branch_taken_0x157e78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x157E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157E78u;
            // 0x157e7c: 0x34a50202  ori         $a1, $a1, 0x202 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)514);
        ctx->in_delay_slot = false;
        if (branch_taken_0x157e78) {
            ctx->pc = 0x157E98u;
            goto label_157e98;
        }
    }
    ctx->pc = 0x157E80u;
    // 0x157e80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x157e80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x157e84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x157e84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x157e88: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x157e88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x157e8c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x157e8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x157e90: 0x805607e  j           func_1581F8
    ctx->pc = 0x157E90u;
    ctx->pc = 0x157E94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x157E90u;
            // 0x157e94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581F8u;
    if (runtime->hasFunction(0x1581F8u)) {
        auto targetFn = runtime->lookupFunction(0x1581F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001581F8_0x1581f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x157E98u;
label_157e98:
    // 0x157e98: 0x6a230007  ldl         $v1, 0x7($s1)
    ctx->pc = 0x157e98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x157e9c: 0x6e230000  ldr         $v1, 0x0($s1)
    ctx->pc = 0x157e9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x157ea0: 0x6a24000f  ldl         $a0, 0xF($s1)
    ctx->pc = 0x157ea0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x157ea4: 0x6e240008  ldr         $a0, 0x8($s1)
    ctx->pc = 0x157ea4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x157ea8: 0x6a250017  ldl         $a1, 0x17($s1)
    ctx->pc = 0x157ea8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x157eac: 0x6e250010  ldr         $a1, 0x10($s1)
    ctx->pc = 0x157eacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x157eb0: 0x6a26001f  ldl         $a2, 0x1F($s1)
    ctx->pc = 0x157eb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x157eb4: 0x6e260018  ldr         $a2, 0x18($s1)
    ctx->pc = 0x157eb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x157eb8: 0xb2430007  sdl         $v1, 0x7($s2)
    ctx->pc = 0x157eb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157ebc: 0xb6430000  sdr         $v1, 0x0($s2)
    ctx->pc = 0x157ebcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157ec0: 0xb244000f  sdl         $a0, 0xF($s2)
    ctx->pc = 0x157ec0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157ec4: 0xb6440008  sdr         $a0, 0x8($s2)
    ctx->pc = 0x157ec4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157ec8: 0xb2450017  sdl         $a1, 0x17($s2)
    ctx->pc = 0x157ec8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157ecc: 0xb6450010  sdr         $a1, 0x10($s2)
    ctx->pc = 0x157eccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157ed0: 0xb246001f  sdl         $a2, 0x1F($s2)
    ctx->pc = 0x157ed0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157ed4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x157ed4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x157ed8: 0xb6460018  sdr         $a2, 0x18($s2)
    ctx->pc = 0x157ed8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157edc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x157edcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x157ee0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x157ee0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x157ee4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x157ee4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x157ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x157EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157EE8u;
            // 0x157eec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157E6Cu: goto label_157e6c;
            case 0x157E98u: goto label_157e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
