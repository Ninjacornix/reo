#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016F930
// Address: 0x16f930 - 0x16fb28
void sub_0016F930_0x16f930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016F930_0x16f930");
#endif

    switch (ctx->pc) {
        case 0x16f94cu: goto label_16f94c;
        case 0x16faacu: goto label_16faac;
        case 0x16fabcu: goto label_16fabc;
        case 0x16fadcu: goto label_16fadc;
        case 0x16fae4u: goto label_16fae4;
        case 0x16faf0u: goto label_16faf0;
        default: break;
    }

    ctx->pc = 0x16f930u;

    // 0x16f930: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16f930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16f934: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16f934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16f938: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16f938u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f93c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16f93cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16f940: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16f940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16f944: 0xc05beca  jal         func_16FB28
    ctx->pc = 0x16F944u;
    SET_GPR_U32(ctx, 31, 0x16F94Cu);
    ctx->pc = 0x16F948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F944u;
            // 0x16f948: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16FB28u;
    if (runtime->hasFunction(0x16FB28u)) {
        auto targetFn = runtime->lookupFunction(0x16FB28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F94Cu; }
        if (ctx->pc != 0x16F94Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FB28_0x16fb28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F94Cu; }
        if (ctx->pc != 0x16F94Cu) { return; }
    }
    ctx->pc = 0x16F94Cu;
label_16f94c:
    // 0x16f94c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16F94Cu;
    {
        const bool branch_taken_0x16f94c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F94Cu;
            // 0x16f950: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f94c) {
            ctx->pc = 0x16F970u;
            goto label_16f970;
        }
    }
    ctx->pc = 0x16F954u;
    // 0x16f954: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16f954u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16f958: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16f958u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16f95c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16f95cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f960: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16f960u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f964: 0x34a50f15  ori         $a1, $a1, 0xF15
    ctx->pc = 0x16f964u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3861);
    // 0x16f968: 0x805a704  j           func_169C10
    ctx->pc = 0x16F968u;
    ctx->pc = 0x16F96Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F968u;
            // 0x16f96c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16F970u;
label_16f970:
    // 0x16f970: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16f970u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x16f974: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x16f974u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x16f978: 0x24476068  addiu       $a3, $v0, 0x6068
    ctx->pc = 0x16f978u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 24680));
    // 0x16f97c: 0x68e30007  ldl         $v1, 0x7($a3)
    ctx->pc = 0x16f97cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16f980: 0x6ce30000  ldr         $v1, 0x0($a3)
    ctx->pc = 0x16f980u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16f984: 0x68e5000f  ldl         $a1, 0xF($a3)
    ctx->pc = 0x16f984u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x16f988: 0x6ce50008  ldr         $a1, 0x8($a3)
    ctx->pc = 0x16f988u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x16f98c: 0x68e60017  ldl         $a2, 0x17($a3)
    ctx->pc = 0x16f98cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x16f990: 0x6ce60010  ldr         $a2, 0x10($a3)
    ctx->pc = 0x16f990u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x16f994: 0xb203000b  sdl         $v1, 0xB($s0)
    ctx->pc = 0x16f994u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f998: 0xb6030004  sdr         $v1, 0x4($s0)
    ctx->pc = 0x16f998u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 4); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f99c: 0xb2050013  sdl         $a1, 0x13($s0)
    ctx->pc = 0x16f99cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 19); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9a0: 0xb605000c  sdr         $a1, 0xC($s0)
    ctx->pc = 0x16f9a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9a4: 0xb206001b  sdl         $a2, 0x1B($s0)
    ctx->pc = 0x16f9a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9a8: 0xb6060014  sdr         $a2, 0x14($s0)
    ctx->pc = 0x16f9a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9ac: 0x68e3001f  ldl         $v1, 0x1F($a3)
    ctx->pc = 0x16f9acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16f9b0: 0x6ce30018  ldr         $v1, 0x18($a3)
    ctx->pc = 0x16f9b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16f9b4: 0x8ce50020  lw          $a1, 0x20($a3)
    ctx->pc = 0x16f9b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x16f9b8: 0xb2030023  sdl         $v1, 0x23($s0)
    ctx->pc = 0x16f9b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9bc: 0xb603001c  sdr         $v1, 0x1C($s0)
    ctx->pc = 0x16f9bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9c0: 0xae050024  sw          $a1, 0x24($s0)
    ctx->pc = 0x16f9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 5));
    // 0x16f9c4: 0x26030030  addiu       $v1, $s0, 0x30
    ctx->pc = 0x16f9c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x16f9c8: 0x24070005  addiu       $a3, $zero, 0x5
    ctx->pc = 0x16f9c8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16f9cc: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16f9ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x16f9d0: 0x248b6090  addiu       $t3, $a0, 0x6090
    ctx->pc = 0x16f9d0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 4), 24720));
    // 0x16f9d4: 0x69680007  ldl         $t0, 0x7($t3)
    ctx->pc = 0x16f9d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x16f9d8: 0x6d680000  ldr         $t0, 0x0($t3)
    ctx->pc = 0x16f9d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x16f9dc: 0xb208002f  sdl         $t0, 0x2F($s0)
    ctx->pc = 0x16f9dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9e0: 0xb6080028  sdr         $t0, 0x28($s0)
    ctx->pc = 0x16f9e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f9e4: 0x240800c0  addiu       $t0, $zero, 0xC0
    ctx->pc = 0x16f9e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x16f9e8: 0x24090001  addiu       $t1, $zero, 0x1
    ctx->pc = 0x16f9e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16f9ec: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x16f9ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f9f0: 0x244b6098  addiu       $t3, $v0, 0x6098
    ctx->pc = 0x16f9f0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 2), 24728));
    // 0x16f9f4: 0x69640007  ldl         $a0, 0x7($t3)
    ctx->pc = 0x16f9f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16f9f8: 0x6d640000  ldr         $a0, 0x0($t3)
    ctx->pc = 0x16f9f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16f9fc: 0x6966000f  ldl         $a2, 0xF($t3)
    ctx->pc = 0x16f9fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x16fa00: 0x6d660008  ldr         $a2, 0x8($t3)
    ctx->pc = 0x16fa00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x16fa04: 0x696a0017  ldl         $t2, 0x17($t3)
    ctx->pc = 0x16fa04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem << shift)); }
    // 0x16fa08: 0x6d6a0010  ldr         $t2, 0x10($t3)
    ctx->pc = 0x16fa08u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem >> shift)); }
    // 0x16fa0c: 0xb0640007  sdl         $a0, 0x7($v1)
    ctx->pc = 0x16fa0cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa10: 0xb4640000  sdr         $a0, 0x0($v1)
    ctx->pc = 0x16fa10u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa14: 0xb066000f  sdl         $a2, 0xF($v1)
    ctx->pc = 0x16fa14u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa18: 0xb4660008  sdr         $a2, 0x8($v1)
    ctx->pc = 0x16fa18u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa1c: 0xb06a0017  sdl         $t2, 0x17($v1)
    ctx->pc = 0x16fa1cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa20: 0xb46a0010  sdr         $t2, 0x10($v1)
    ctx->pc = 0x16fa20u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa24: 0x6964001f  ldl         $a0, 0x1F($t3)
    ctx->pc = 0x16fa24u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16fa28: 0x6d640018  ldr         $a0, 0x18($t3)
    ctx->pc = 0x16fa28u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16fa2c: 0x69660027  ldl         $a2, 0x27($t3)
    ctx->pc = 0x16fa2cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x16fa30: 0x6d660020  ldr         $a2, 0x20($t3)
    ctx->pc = 0x16fa30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x16fa34: 0x696a002f  ldl         $t2, 0x2F($t3)
    ctx->pc = 0x16fa34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem << shift)); }
    // 0x16fa38: 0x6d6a0028  ldr         $t2, 0x28($t3)
    ctx->pc = 0x16fa38u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem >> shift)); }
    // 0x16fa3c: 0xb064001f  sdl         $a0, 0x1F($v1)
    ctx->pc = 0x16fa3cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa40: 0xb4640018  sdr         $a0, 0x18($v1)
    ctx->pc = 0x16fa40u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa44: 0xb0660027  sdl         $a2, 0x27($v1)
    ctx->pc = 0x16fa44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa48: 0xb4660020  sdr         $a2, 0x20($v1)
    ctx->pc = 0x16fa48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa4c: 0xb06a002f  sdl         $t2, 0x2F($v1)
    ctx->pc = 0x16fa4cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa50: 0xb46a0028  sdr         $t2, 0x28($v1)
    ctx->pc = 0x16fa50u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa54: 0x69640037  ldl         $a0, 0x37($t3)
    ctx->pc = 0x16fa54u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16fa58: 0x6d640030  ldr         $a0, 0x30($t3)
    ctx->pc = 0x16fa58u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16fa5c: 0x6966003f  ldl         $a2, 0x3F($t3)
    ctx->pc = 0x16fa5cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x16fa60: 0x6d660038  ldr         $a2, 0x38($t3)
    ctx->pc = 0x16fa60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 11), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x16fa64: 0xb0640037  sdl         $a0, 0x37($v1)
    ctx->pc = 0x16fa64u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa68: 0xb4640030  sdr         $a0, 0x30($v1)
    ctx->pc = 0x16fa68u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa6c: 0xb066003f  sdl         $a2, 0x3F($v1)
    ctx->pc = 0x16fa6cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa70: 0xb4660038  sdr         $a2, 0x38($v1)
    ctx->pc = 0x16fa70u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16fa74: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x16fa74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x16fa78: 0xae070074  sw          $a3, 0x74($s0)
    ctx->pc = 0x16fa78u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 7));
    // 0x16fa7c: 0x2604013c  addiu       $a0, $s0, 0x13C
    ctx->pc = 0x16fa7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 316));
    // 0x16fa80: 0xae080078  sw          $t0, 0x78($s0)
    ctx->pc = 0x16fa80u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 120), GPR_U32(ctx, 8));
    // 0x16fa84: 0xae090108  sw          $t1, 0x108($s0)
    ctx->pc = 0x16fa84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 264), GPR_U32(ctx, 9));
    // 0x16fa88: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x16fa88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x16fa8c: 0xae000070  sw          $zero, 0x70($s0)
    ctx->pc = 0x16fa8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 112), GPR_U32(ctx, 0));
    // 0x16fa90: 0xae000104  sw          $zero, 0x104($s0)
    ctx->pc = 0x16fa90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 260), GPR_U32(ctx, 0));
    // 0x16fa94: 0xae00007c  sw          $zero, 0x7C($s0)
    ctx->pc = 0x16fa94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 124), GPR_U32(ctx, 0));
    // 0x16fa98: 0xae000080  sw          $zero, 0x80($s0)
    ctx->pc = 0x16fa98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 128), GPR_U32(ctx, 0));
    // 0x16fa9c: 0xae00012c  sw          $zero, 0x12C($s0)
    ctx->pc = 0x16fa9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 300), GPR_U32(ctx, 0));
    // 0x16faa0: 0xae000130  sw          $zero, 0x130($s0)
    ctx->pc = 0x16faa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 304), GPR_U32(ctx, 0));
    // 0x16faa4: 0xc05befc  jal         func_16FBF0
    ctx->pc = 0x16FAA4u;
    SET_GPR_U32(ctx, 31, 0x16FAACu);
    ctx->pc = 0x16FAA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FAA4u;
            // 0x16faa8: 0xae000134  sw          $zero, 0x134($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 308), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16FBF0u;
    if (runtime->hasFunction(0x16FBF0u)) {
        auto targetFn = runtime->lookupFunction(0x16FBF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FAACu; }
        if (ctx->pc != 0x16FAACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FBF0_0x16fbf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FAACu; }
        if (ctx->pc != 0x16FAACu) { return; }
    }
    ctx->pc = 0x16FAACu;
label_16faac:
    // 0x16faac: 0xae000084  sw          $zero, 0x84($s0)
    ctx->pc = 0x16faacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 0));
    // 0x16fab0: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x16fab0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
    // 0x16fab4: 0xc05bf20  jal         func_16FC80
    ctx->pc = 0x16FAB4u;
    SET_GPR_U32(ctx, 31, 0x16FABCu);
    ctx->pc = 0x16FAB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FAB4u;
            // 0x16fab8: 0x2604008c  addiu       $a0, $s0, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 140));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16FC80u;
    if (runtime->hasFunction(0x16FC80u)) {
        auto targetFn = runtime->lookupFunction(0x16FC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FABCu; }
        if (ctx->pc != 0x16FABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FC80_0x16fc80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FABCu; }
        if (ctx->pc != 0x16FABCu) { return; }
    }
    ctx->pc = 0x16FABCu;
label_16fabc:
    // 0x16fabc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x16fabcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16fac0: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x16fac0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x16fac4: 0xae0300e0  sw          $v1, 0xE0($s0)
    ctx->pc = 0x16fac4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 3));
    // 0x16fac8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x16fac8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x16facc: 0xae0000e4  sw          $zero, 0xE4($s0)
    ctx->pc = 0x16faccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 228), GPR_U32(ctx, 0));
    // 0x16fad0: 0xae0200e8  sw          $v0, 0xE8($s0)
    ctx->pc = 0x16fad0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 232), GPR_U32(ctx, 2));
    // 0x16fad4: 0xc05b658  jal         func_16D960
    ctx->pc = 0x16FAD4u;
    SET_GPR_U32(ctx, 31, 0x16FADCu);
    ctx->pc = 0x16FAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FAD4u;
            // 0x16fad8: 0x260400ec  addiu       $a0, $s0, 0xEC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 236));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D960u;
    if (runtime->hasFunction(0x16D960u)) {
        auto targetFn = runtime->lookupFunction(0x16D960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FADCu; }
        if (ctx->pc != 0x16FADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D960_0x16d960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FADCu; }
        if (ctx->pc != 0x16FADCu) { return; }
    }
    ctx->pc = 0x16FADCu;
label_16fadc:
    // 0x16fadc: 0xc05bf28  jal         func_16FCA0
    ctx->pc = 0x16FADCu;
    SET_GPR_U32(ctx, 31, 0x16FAE4u);
    ctx->pc = 0x16FAE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FADCu;
            // 0x16fae0: 0x2604093c  addiu       $a0, $s0, 0x93C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2364));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16FCA0u;
    if (runtime->hasFunction(0x16FCA0u)) {
        auto targetFn = runtime->lookupFunction(0x16FCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FAE4u; }
        if (ctx->pc != 0x16FAE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FCA0_0x16fca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FAE4u; }
        if (ctx->pc != 0x16FAE4u) { return; }
    }
    ctx->pc = 0x16FAE4u;
label_16fae4:
    // 0x16fae4: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x16fae4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x16fae8: 0x260209d0  addiu       $v0, $s0, 0x9D0
    ctx->pc = 0x16fae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 2512));
    // 0x16faec: 0x260308e4  addiu       $v1, $s0, 0x8E4
    ctx->pc = 0x16faecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 2276));
label_16faf0:
    // 0x16faf0: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x16faf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x16faf4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x16faf4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x16faf8: 0x2463ff80  addiu       $v1, $v1, -0x80
    ctx->pc = 0x16faf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967168));
    // 0x16fafc: 0x0  nop
    ctx->pc = 0x16fafcu;
    // NOP
    // 0x16fb00: 0x0  nop
    ctx->pc = 0x16fb00u;
    // NOP
    // 0x16fb04: 0x481fffa  bgez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x16FB04u;
    {
        const bool branch_taken_0x16fb04 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x16FB08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FB04u;
            // 0x16fb08: 0x2442fff8  addiu       $v0, $v0, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fb04) {
            ctx->pc = 0x16FAF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16faf0;
        }
    }
    ctx->pc = 0x16FB0Cu;
    // 0x16fb0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16fb0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16fb10: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16fb10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16fb14: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16fb14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16fb18: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16fb18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16fb1c: 0x3e00008  jr          $ra
    ctx->pc = 0x16FB1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16FB20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FB1Cu;
            // 0x16fb20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F94Cu: goto label_16f94c;
            case 0x16F970u: goto label_16f970;
            case 0x16FAACu: goto label_16faac;
            case 0x16FABCu: goto label_16fabc;
            case 0x16FADCu: goto label_16fadc;
            case 0x16FAE4u: goto label_16fae4;
            case 0x16FAF0u: goto label_16faf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16FB24u;
    // 0x16fb24: 0x0  nop
    ctx->pc = 0x16fb24u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
