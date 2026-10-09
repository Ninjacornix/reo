#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001658D0
// Address: 0x1658d0 - 0x165a88
void sub_001658D0_0x1658d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001658D0_0x1658d0");
#endif

    switch (ctx->pc) {
        case 0x165918u: goto label_165918;
        case 0x1659a8u: goto label_1659a8;
        case 0x1659bcu: goto label_1659bc;
        case 0x1659d0u: goto label_1659d0;
        case 0x1659e4u: goto label_1659e4;
        case 0x1659f4u: goto label_1659f4;
        case 0x165a00u: goto label_165a00;
        case 0x165a0cu: goto label_165a0c;
        case 0x165a18u: goto label_165a18;
        case 0x165a24u: goto label_165a24;
        case 0x165a30u: goto label_165a30;
        case 0x165a3cu: goto label_165a3c;
        case 0x165a48u: goto label_165a48;
        case 0x165a54u: goto label_165a54;
        case 0x165a60u: goto label_165a60;
        case 0x165a68u: goto label_165a68;
        default: break;
    }

    ctx->pc = 0x1658d0u;

    // 0x1658d0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1658d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1658d4: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x1658d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1658d8: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x1658d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x1658dc: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1658dcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1658e0: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x1658e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x1658e4: 0x24480750  addiu       $t0, $v0, 0x750
    ctx->pc = 0x1658e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 1872));
    // 0x1658e8: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x1658e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x1658ec: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x1658ecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1658f0: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x1658f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x1658f4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1658f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1658f8: 0x8d020008  lw          $v0, 0x8($t0)
    ctx->pc = 0x1658f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x1658fc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1658FCu;
    {
        const bool branch_taken_0x1658fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x165900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1658FCu;
            // 0x165900: 0x34a50c06  ori         $a1, $a1, 0xC06 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3078);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1658fc) {
            ctx->pc = 0x165910u;
            goto label_165910;
        }
    }
    ctx->pc = 0x165904u;
    // 0x165904: 0x8d020018  lw          $v0, 0x18($t0)
    ctx->pc = 0x165904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 24)));
    // 0x165908: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x165908u;
    {
        const bool branch_taken_0x165908 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16590Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165908u;
            // 0x16590c: 0x3c020016  lui         $v0, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165908) {
            ctx->pc = 0x165920u;
            goto label_165920;
        }
    }
    ctx->pc = 0x165910u;
label_165910:
    // 0x165910: 0xc05a704  jal         func_169C10
    ctx->pc = 0x165910u;
    SET_GPR_U32(ctx, 31, 0x165918u);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165918u; }
        if (ctx->pc != 0x165918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165918u; }
        if (ctx->pc != 0x165918u) { return; }
    }
    ctx->pc = 0x165918u;
label_165918:
    // 0x165918: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x165918u;
    {
        const bool branch_taken_0x165918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16591Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165918u;
            // 0x16591c: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165918) {
            ctx->pc = 0x165A70u;
            goto label_165a70;
        }
    }
    ctx->pc = 0x165920u;
label_165920:
    // 0x165920: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x165920u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x165924: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x165924u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x165928: 0x24424c28  addiu       $v0, $v0, 0x4C28
    ctx->pc = 0x165928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19496));
    // 0x16592c: 0x69050007  ldl         $a1, 0x7($t0)
    ctx->pc = 0x16592cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x165930: 0x6d050000  ldr         $a1, 0x0($t0)
    ctx->pc = 0x165930u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x165934: 0x6909000f  ldl         $t1, 0xF($t0)
    ctx->pc = 0x165934u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x165938: 0x6d090008  ldr         $t1, 0x8($t0)
    ctx->pc = 0x165938u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x16593c: 0x690a0017  ldl         $t2, 0x17($t0)
    ctx->pc = 0x16593cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem << shift)); }
    // 0x165940: 0x6d0a0010  ldr         $t2, 0x10($t0)
    ctx->pc = 0x165940u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem >> shift)); }
    // 0x165944: 0x8d0b0018  lw          $t3, 0x18($t0)
    ctx->pc = 0x165944u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 24)));
    // 0x165948: 0xb0e5000f  sdl         $a1, 0xF($a3)
    ctx->pc = 0x165948u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16594c: 0xb4e50008  sdr         $a1, 0x8($a3)
    ctx->pc = 0x16594cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165950: 0xb0e90017  sdl         $t1, 0x17($a3)
    ctx->pc = 0x165950u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165954: 0xb4e90010  sdr         $t1, 0x10($a3)
    ctx->pc = 0x165954u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165958: 0xb0ea001f  sdl         $t2, 0x1F($a3)
    ctx->pc = 0x165958u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16595c: 0xb4ea0018  sdr         $t2, 0x18($a3)
    ctx->pc = 0x16595cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165960: 0xaceb0020  sw          $t3, 0x20($a3)
    ctx->pc = 0x165960u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 32), GPR_U32(ctx, 11));
    // 0x165964: 0x2405003f  addiu       $a1, $zero, 0x3F
    ctx->pc = 0x165964u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x165968: 0xace30028  sw          $v1, 0x28($a3)
    ctx->pc = 0x165968u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 40), GPR_U32(ctx, 3));
    // 0x16596c: 0x3c11000f  lui         $s1, 0xF
    ctx->pc = 0x16596cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)15 << 16));
    // 0x165970: 0x36314240  ori         $s1, $s1, 0x4240
    ctx->pc = 0x165970u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)16960);
    // 0x165974: 0xace2003c  sw          $v0, 0x3C($a3)
    ctx->pc = 0x165974u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 60), GPR_U32(ctx, 2));
    // 0x165978: 0x26500f60  addiu       $s0, $s2, 0xF60
    ctx->pc = 0x165978u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 3936));
    // 0x16597c: 0xace60044  sw          $a2, 0x44($a3)
    ctx->pc = 0x16597cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 68), GPR_U32(ctx, 6));
    // 0x165980: 0xace00048  sw          $zero, 0x48($a3)
    ctx->pc = 0x165980u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 72), GPR_U32(ctx, 0));
    // 0x165984: 0xace00000  sw          $zero, 0x0($a3)
    ctx->pc = 0x165984u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
    // 0x165988: 0xace00004  sw          $zero, 0x4($a3)
    ctx->pc = 0x165988u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 0));
    // 0x16598c: 0xace60024  sw          $a2, 0x24($a3)
    ctx->pc = 0x16598cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 36), GPR_U32(ctx, 6));
    // 0x165990: 0xace0002c  sw          $zero, 0x2C($a3)
    ctx->pc = 0x165990u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 44), GPR_U32(ctx, 0));
    // 0x165994: 0xace00030  sw          $zero, 0x30($a3)
    ctx->pc = 0x165994u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 48), GPR_U32(ctx, 0));
    // 0x165998: 0xace00034  sw          $zero, 0x34($a3)
    ctx->pc = 0x165998u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 52), GPR_U32(ctx, 0));
    // 0x16599c: 0xace00038  sw          $zero, 0x38($a3)
    ctx->pc = 0x16599cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 56), GPR_U32(ctx, 0));
    // 0x1659a0: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1659A0u;
    SET_GPR_U32(ctx, 31, 0x1659A8u);
    ctx->pc = 0x1659A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1659A0u;
            // 0x1659a4: 0xace00040  sw          $zero, 0x40($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 64), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659A8u; }
        if (ctx->pc != 0x1659A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659A8u; }
        if (ctx->pc != 0x1659A8u) { return; }
    }
    ctx->pc = 0x1659A8u;
label_1659a8:
    // 0x1659a8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1659a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1659ac: 0x24050040  addiu       $a1, $zero, 0x40
    ctx->pc = 0x1659acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1659b0: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x1659b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x1659b4: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1659B4u;
    SET_GPR_U32(ctx, 31, 0x1659BCu);
    ctx->pc = 0x1659B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1659B4u;
            // 0x1659b8: 0xffb10008  sd          $s1, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659BCu; }
        if (ctx->pc != 0x1659BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659BCu; }
        if (ctx->pc != 0x1659BCu) { return; }
    }
    ctx->pc = 0x1659BCu;
label_1659bc:
    // 0x1659bc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1659bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1659c0: 0x24050041  addiu       $a1, $zero, 0x41
    ctx->pc = 0x1659c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x1659c4: 0xffa20010  sd          $v0, 0x10($sp)
    ctx->pc = 0x1659c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 2));
    // 0x1659c8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1659C8u;
    SET_GPR_U32(ctx, 31, 0x1659D0u);
    ctx->pc = 0x1659CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1659C8u;
            // 0x1659cc: 0xffb10018  sd          $s1, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659D0u; }
        if (ctx->pc != 0x1659D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659D0u; }
        if (ctx->pc != 0x1659D0u) { return; }
    }
    ctx->pc = 0x1659D0u;
label_1659d0:
    // 0x1659d0: 0x24050042  addiu       $a1, $zero, 0x42
    ctx->pc = 0x1659d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x1659d4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1659d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1659d8: 0xffa20020  sd          $v0, 0x20($sp)
    ctx->pc = 0x1659d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 2));
    // 0x1659dc: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1659DCu;
    SET_GPR_U32(ctx, 31, 0x1659E4u);
    ctx->pc = 0x1659E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1659DCu;
            // 0x1659e0: 0xffb10028  sd          $s1, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659E4u; }
        if (ctx->pc != 0x1659E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659E4u; }
        if (ctx->pc != 0x1659E4u) { return; }
    }
    ctx->pc = 0x1659E4u;
label_1659e4:
    // 0x1659e4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1659e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1659e8: 0xffa20030  sd          $v0, 0x30($sp)
    ctx->pc = 0x1659e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 2));
    // 0x1659ec: 0xc05df2c  jal         func_177CB0
    ctx->pc = 0x1659ECu;
    SET_GPR_U32(ctx, 31, 0x1659F4u);
    ctx->pc = 0x1659F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1659ECu;
            // 0x1659f0: 0xffb10038  sd          $s1, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177CB0u;
    if (runtime->hasFunction(0x177CB0u)) {
        auto targetFn = runtime->lookupFunction(0x177CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659F4u; }
        if (ctx->pc != 0x1659F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177CB0_0x177cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1659F4u; }
        if (ctx->pc != 0x1659F4u) { return; }
    }
    ctx->pc = 0x1659F4u;
label_1659f4:
    // 0x1659f4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1659f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1659f8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1659F8u;
    SET_GPR_U32(ctx, 31, 0x165A00u);
    ctx->pc = 0x1659FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1659F8u;
            // 0x1659fc: 0x24050048  addiu       $a1, $zero, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A00u; }
        if (ctx->pc != 0x165A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A00u; }
        if (ctx->pc != 0x165A00u) { return; }
    }
    ctx->pc = 0x165A00u;
label_165a00:
    // 0x165a00: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165a00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a04: 0xc05df74  jal         func_177DD0
    ctx->pc = 0x165A04u;
    SET_GPR_U32(ctx, 31, 0x165A0Cu);
    ctx->pc = 0x165A08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A04u;
            // 0x165a08: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177DD0u;
    if (runtime->hasFunction(0x177DD0u)) {
        auto targetFn = runtime->lookupFunction(0x177DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A0Cu; }
        if (ctx->pc != 0x165A0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177DD0_0x177dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A0Cu; }
        if (ctx->pc != 0x165A0Cu) { return; }
    }
    ctx->pc = 0x165A0Cu;
label_165a0c:
    // 0x165a0c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165a0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a10: 0xc05df76  jal         func_177DD8
    ctx->pc = 0x165A10u;
    SET_GPR_U32(ctx, 31, 0x165A18u);
    ctx->pc = 0x165A14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A10u;
            // 0x165a14: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177DD8u;
    if (runtime->hasFunction(0x177DD8u)) {
        auto targetFn = runtime->lookupFunction(0x177DD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A18u; }
        if (ctx->pc != 0x165A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177DD8_0x177dd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A18u; }
        if (ctx->pc != 0x165A18u) { return; }
    }
    ctx->pc = 0x165A18u;
label_165a18:
    // 0x165a18: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165a18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a1c: 0xc05df7c  jal         func_177DF0
    ctx->pc = 0x165A1Cu;
    SET_GPR_U32(ctx, 31, 0x165A24u);
    ctx->pc = 0x165A20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A1Cu;
            // 0x165a20: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177DF0u;
    if (runtime->hasFunction(0x177DF0u)) {
        auto targetFn = runtime->lookupFunction(0x177DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A24u; }
        if (ctx->pc != 0x165A24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177DF0_0x177df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A24u; }
        if (ctx->pc != 0x165A24u) { return; }
    }
    ctx->pc = 0x165A24u;
label_165a24:
    // 0x165a24: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165a24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a28: 0xc05df82  jal         func_177E08
    ctx->pc = 0x165A28u;
    SET_GPR_U32(ctx, 31, 0x165A30u);
    ctx->pc = 0x165A2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A28u;
            // 0x165a2c: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177E08u;
    if (runtime->hasFunction(0x177E08u)) {
        auto targetFn = runtime->lookupFunction(0x177E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A30u; }
        if (ctx->pc != 0x165A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177E08_0x177e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A30u; }
        if (ctx->pc != 0x165A30u) { return; }
    }
    ctx->pc = 0x165A30u;
label_165a30:
    // 0x165a30: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165a30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a34: 0xc05df88  jal         func_177E20
    ctx->pc = 0x165A34u;
    SET_GPR_U32(ctx, 31, 0x165A3Cu);
    ctx->pc = 0x165A38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A34u;
            // 0x165a38: 0x27a50030  addiu       $a1, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177E20u;
    if (runtime->hasFunction(0x177E20u)) {
        auto targetFn = runtime->lookupFunction(0x177E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A3Cu; }
        if (ctx->pc != 0x165A3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177E20_0x177e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A3Cu; }
        if (ctx->pc != 0x165A3Cu) { return; }
    }
    ctx->pc = 0x165A3Cu;
label_165a3c:
    // 0x165a3c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x165a3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a40: 0xc05d58a  jal         func_175628
    ctx->pc = 0x165A40u;
    SET_GPR_U32(ctx, 31, 0x165A48u);
    ctx->pc = 0x165A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A40u;
            // 0x165a44: 0x2405003e  addiu       $a1, $zero, 0x3E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A48u; }
        if (ctx->pc != 0x165A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A48u; }
        if (ctx->pc != 0x165A48u) { return; }
    }
    ctx->pc = 0x165A48u;
label_165a48:
    // 0x165a48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165a48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a4c: 0xc05df8e  jal         func_177E38
    ctx->pc = 0x165A4Cu;
    SET_GPR_U32(ctx, 31, 0x165A54u);
    ctx->pc = 0x165A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A4Cu;
            // 0x165a50: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177E38u;
    if (runtime->hasFunction(0x177E38u)) {
        auto targetFn = runtime->lookupFunction(0x177E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A54u; }
        if (ctx->pc != 0x165A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177E38_0x177e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A54u; }
        if (ctx->pc != 0x165A54u) { return; }
    }
    ctx->pc = 0x165A54u;
label_165a54:
    // 0x165a54: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x165a54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a58: 0xc05d58a  jal         func_175628
    ctx->pc = 0x165A58u;
    SET_GPR_U32(ctx, 31, 0x165A60u);
    ctx->pc = 0x165A5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A58u;
            // 0x165a5c: 0x2405003d  addiu       $a1, $zero, 0x3D (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A60u; }
        if (ctx->pc != 0x165A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A60u; }
        if (ctx->pc != 0x165A60u) { return; }
    }
    ctx->pc = 0x165A60u;
label_165a60:
    // 0x165a60: 0xc05f9de  jal         func_17E778
    ctx->pc = 0x165A60u;
    SET_GPR_U32(ctx, 31, 0x165A68u);
    ctx->pc = 0x165A64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165A60u;
            // 0x165a64: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E778u;
    if (runtime->hasFunction(0x17E778u)) {
        auto targetFn = runtime->lookupFunction(0x17E778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A68u; }
        if (ctx->pc != 0x165A68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E778_0x17e778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165A68u; }
        if (ctx->pc != 0x165A68u) { return; }
    }
    ctx->pc = 0x165A68u;
label_165a68:
    // 0x165a68: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165a68u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165a6c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x165a6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_165a70:
    // 0x165a70: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x165a70u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x165a74: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x165a74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x165a78: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x165a78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x165a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x165A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165A7Cu;
            // 0x165a80: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165910u: goto label_165910;
            case 0x165918u: goto label_165918;
            case 0x165920u: goto label_165920;
            case 0x1659A8u: goto label_1659a8;
            case 0x1659BCu: goto label_1659bc;
            case 0x1659D0u: goto label_1659d0;
            case 0x1659E4u: goto label_1659e4;
            case 0x1659F4u: goto label_1659f4;
            case 0x165A00u: goto label_165a00;
            case 0x165A0Cu: goto label_165a0c;
            case 0x165A18u: goto label_165a18;
            case 0x165A24u: goto label_165a24;
            case 0x165A30u: goto label_165a30;
            case 0x165A3Cu: goto label_165a3c;
            case 0x165A48u: goto label_165a48;
            case 0x165A54u: goto label_165a54;
            case 0x165A60u: goto label_165a60;
            case 0x165A68u: goto label_165a68;
            case 0x165A70u: goto label_165a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165A84u;
    // 0x165a84: 0x0  nop
    ctx->pc = 0x165a84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
