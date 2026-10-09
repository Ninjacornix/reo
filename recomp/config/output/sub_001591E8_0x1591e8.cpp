#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001591E8
// Address: 0x1591e8 - 0x159318
void sub_001591E8_0x1591e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001591E8_0x1591e8");
#endif

    switch (ctx->pc) {
        case 0x159204u: goto label_159204;
        case 0x159240u: goto label_159240;
        case 0x1592a0u: goto label_1592a0;
        default: break;
    }

    ctx->pc = 0x1591e8u;

    // 0x1591e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1591e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1591ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1591ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1591f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1591f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1591f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1591f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1591f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1591f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1591fc: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x1591FCu;
    SET_GPR_U32(ctx, 31, 0x159204u);
    ctx->pc = 0x159200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1591FCu;
            // 0x159200: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159204u; }
        if (ctx->pc != 0x159204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159204u; }
        if (ctx->pc != 0x159204u) { return; }
    }
    ctx->pc = 0x159204u;
label_159204:
    // 0x159204: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x159204u;
    {
        const bool branch_taken_0x159204 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x159208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159204u;
            // 0x159208: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159204) {
            ctx->pc = 0x159228u;
            goto label_159228;
        }
    }
    ctx->pc = 0x15920Cu;
    // 0x15920c: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15920cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x159210: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x159210u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159214: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159214u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x159218: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x159218u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15921c: 0x34a5020c  ori         $a1, $a1, 0x20C
    ctx->pc = 0x15921cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)524);
    // 0x159220: 0x80563ce  j           func_158F38
    ctx->pc = 0x159220u;
    ctx->pc = 0x159224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159220u;
            // 0x159224: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x159228u;
label_159228:
    // 0x159228: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x159228u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15922c: 0x260301d0  addiu       $v1, $s0, 0x1D0
    ctx->pc = 0x15922cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 464));
    // 0x159230: 0x651025  or          $v0, $v1, $a1
    ctx->pc = 0x159230u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x159234: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x159234u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x159238: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x159238u;
    {
        const bool branch_taken_0x159238 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15923Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159238u;
            // 0x15923c: 0x26040210  addiu       $a0, $s0, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 528));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159238) {
            ctx->pc = 0x1592A0u;
            goto label_1592a0;
        }
    }
    ctx->pc = 0x159240u;
label_159240:
    // 0x159240: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x159240u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x159244: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x159244u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x159248: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x159248u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x15924c: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x15924cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x159250: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x159250u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x159254: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x159254u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x159258: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x159258u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x15925c: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x15925cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x159260: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x159260u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x159264: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x159264u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x159268: 0xb0a6000f  sdl         $a2, 0xF($a1)
    ctx->pc = 0x159268u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15926c: 0xb4a60008  sdr         $a2, 0x8($a1)
    ctx->pc = 0x15926cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x159270: 0xb0a70017  sdl         $a3, 0x17($a1)
    ctx->pc = 0x159270u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x159274: 0xb4a70010  sdr         $a3, 0x10($a1)
    ctx->pc = 0x159274u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x159278: 0xb0a8001f  sdl         $t0, 0x1F($a1)
    ctx->pc = 0x159278u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15927c: 0xb4a80018  sdr         $t0, 0x18($a1)
    ctx->pc = 0x15927cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x159280: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x159280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x159284: 0x0  nop
    ctx->pc = 0x159284u;
    // NOP
    // 0x159288: 0x0  nop
    ctx->pc = 0x159288u;
    // NOP
    // 0x15928c: 0x1464ffec  bne         $v1, $a0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x15928Cu;
    {
        const bool branch_taken_0x15928c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x159290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15928Cu;
            // 0x159290: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15928c) {
            ctx->pc = 0x159240u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_159240;
        }
    }
    ctx->pc = 0x159294u;
    // 0x159294: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x159294u;
    {
        const bool branch_taken_0x159294 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x159294) {
            ctx->pc = 0x1592D4u;
            goto label_1592d4;
        }
    }
    ctx->pc = 0x15929Cu;
    // 0x15929c: 0x0  nop
    ctx->pc = 0x15929cu;
    // NOP
label_1592a0:
    // 0x1592a0: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x1592a0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1592a4: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x1592a4u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1592a8: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x1592a8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1592ac: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x1592acu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1592b0: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x1592b0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x1592b4: 0xfca60008  sd          $a2, 0x8($a1)
    ctx->pc = 0x1592b4u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 6));
    // 0x1592b8: 0xfca70010  sd          $a3, 0x10($a1)
    ctx->pc = 0x1592b8u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 7));
    // 0x1592bc: 0xfca80018  sd          $t0, 0x18($a1)
    ctx->pc = 0x1592bcu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 8));
    // 0x1592c0: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1592c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1592c4: 0x0  nop
    ctx->pc = 0x1592c4u;
    // NOP
    // 0x1592c8: 0x0  nop
    ctx->pc = 0x1592c8u;
    // NOP
    // 0x1592cc: 0x1464fff4  bne         $v1, $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1592CCu;
    {
        const bool branch_taken_0x1592cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x1592D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1592CCu;
            // 0x1592d0: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1592cc) {
            ctx->pc = 0x1592A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1592a0;
        }
    }
    ctx->pc = 0x1592D4u;
label_1592d4:
    // 0x1592d4: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x1592d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1592d8: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x1592d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1592dc: 0x6864000f  ldl         $a0, 0xF($v1)
    ctx->pc = 0x1592dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1592e0: 0x6c640008  ldr         $a0, 0x8($v1)
    ctx->pc = 0x1592e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1592e4: 0x8c660010  lw          $a2, 0x10($v1)
    ctx->pc = 0x1592e4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1592e8: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x1592e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1592ec: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x1592ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1592f0: 0xb0a4000f  sdl         $a0, 0xF($a1)
    ctx->pc = 0x1592f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1592f4: 0xb4a40008  sdr         $a0, 0x8($a1)
    ctx->pc = 0x1592f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1592f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1592f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1592fc: 0xaca60010  sw          $a2, 0x10($a1)
    ctx->pc = 0x1592fcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 6));
    // 0x159300: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x159300u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159304: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159304u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x159308: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x159308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15930c: 0x3e00008  jr          $ra
    ctx->pc = 0x15930Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x159310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15930Cu;
            // 0x159310: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159204u: goto label_159204;
            case 0x159228u: goto label_159228;
            case 0x159240u: goto label_159240;
            case 0x1592A0u: goto label_1592a0;
            case 0x1592D4u: goto label_1592d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x159314u;
    // 0x159314: 0x0  nop
    ctx->pc = 0x159314u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
