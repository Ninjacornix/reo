#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BD78
// Address: 0x11bd78 - 0x11be78
void sub_0011BD78_0x11bd78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BD78_0x11bd78");
#endif

    switch (ctx->pc) {
        case 0x11bda0u: goto label_11bda0;
        case 0x11bdb4u: goto label_11bdb4;
        case 0x11bdf8u: goto label_11bdf8;
        case 0x11be38u: goto label_11be38;
        default: break;
    }

    ctx->pc = 0x11bd78u;

    // 0x11bd78: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11bd78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11bd7c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11bd7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11bd80: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x11bd80u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x11bd84: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11bd84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11bd88: 0x8e429e00  lw          $v0, -0x6200($s2)
    ctx->pc = 0x11bd88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942208)));
    // 0x11bd8c: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11bd8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11bd90: 0x4410032  bgez        $v0, . + 4 + (0x32 << 2)
    ctx->pc = 0x11BD90u;
    {
        const bool branch_taken_0x11bd90 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD90u;
            // 0x11bd94: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bd90) {
            ctx->pc = 0x11BE5Cu;
            goto label_11be5c;
        }
    }
    ctx->pc = 0x11BD98u;
    // 0x11bd98: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x11bd98u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x11bd9c: 0x2630e600  addiu       $s0, $s1, -0x1A00
    ctx->pc = 0x11bd9cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294960640));
label_11bda0:
    // 0x11bda0: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x11bda0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x11bda4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11bda4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bda8: 0x34a50006  ori         $a1, $a1, 0x6
    ctx->pc = 0x11bda8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)6);
    // 0x11bdac: 0xc045e06  jal         func_117818
    ctx->pc = 0x11BDACu;
    SET_GPR_U32(ctx, 31, 0x11BDB4u);
    ctx->pc = 0x11BDB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BDACu;
            // 0x11bdb0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BDB4u; }
        if (ctx->pc != 0x11BDB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BDB4u; }
        if (ctx->pc != 0x11BDB4u) { return; }
    }
    ctx->pc = 0x11BDB4u;
label_11bdb4:
    // 0x11bdb4: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BDB4u;
    {
        const bool branch_taken_0x11bdb4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bdb4) {
            ctx->pc = 0x11BDB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BDB4u;
            // 0x11bdb8: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BDC4u;
            goto label_11bdc4;
        }
    }
    ctx->pc = 0x11BDBCu;
    // 0x11bdbc: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x11BDBCu;
    {
        const bool branch_taken_0x11bdbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BDC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BDBCu;
            // 0x11bdc0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bdbc) {
            ctx->pc = 0x11BE60u;
            goto label_11be60;
        }
    }
    ctx->pc = 0x11BDC4u;
label_11bdc4:
    // 0x11bdc4: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x11BDC4u;
    {
        const bool branch_taken_0x11bdc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BDC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BDC4u;
            // 0x11bdc8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bdc4) {
            ctx->pc = 0x11BE2Cu;
            goto label_11be2c;
        }
    }
    ctx->pc = 0x11BDCCu;
    // 0x11bdcc: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x11bdccu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x11bdd0: 0xae409e00  sw          $zero, -0x6200($s2)
    ctx->pc = 0x11bdd0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294942208), GPR_U32(ctx, 0));
    // 0x11bdd4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bdd4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bdd8: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x11bdd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x11bddc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bddcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bde0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11bde0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bde4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11bde4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bde8: 0x2629e400  addiu       $t1, $s1, -0x1C00
    ctx->pc = 0x11bde8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 17), 4294960128));
    // 0x11bdec: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bdecu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bdf0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BDF0u;
    SET_GPR_U32(ctx, 31, 0x11BDF8u);
    ctx->pc = 0x11BDF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BDF0u;
            // 0x11bdf4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BDF8u; }
        if (ctx->pc != 0x11BDF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BDF8u; }
        if (ctx->pc != 0x11BDF8u) { return; }
    }
    ctx->pc = 0x11BDF8u;
label_11bdf8:
    // 0x11bdf8: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11BDF8u;
    {
        const bool branch_taken_0x11bdf8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BDFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BDF8u;
            // 0x11bdfc: 0x3c030026  lui         $v1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bdf8) {
            ctx->pc = 0x11BE0Cu;
            goto label_11be0c;
        }
    }
    ctx->pc = 0x11BE00u;
    // 0x11be00: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11be00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11be04: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x11BE04u;
    {
        const bool branch_taken_0x11be04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BE04u;
            // 0x11be08: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11be04) {
            ctx->pc = 0x11BE60u;
            goto label_11be60;
        }
    }
    ctx->pc = 0x11BE0Cu;
label_11be0c:
    // 0x11be0c: 0x2627e400  addiu       $a3, $s1, -0x1C00
    ctx->pc = 0x11be0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 4294960128));
    // 0x11be10: 0x2466e628  addiu       $a2, $v1, -0x19D8
    ctx->pc = 0x11be10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 4294960680));
    // 0x11be14: 0x88e40003  lwl         $a0, 0x3($a3)
    ctx->pc = 0x11be14u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x11be18: 0x98e40000  lwr         $a0, 0x0($a3)
    ctx->pc = 0x11be18u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x11be1c: 0xa8c40003  swl         $a0, 0x3($a2)
    ctx->pc = 0x11be1cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11be20: 0xb8c40000  swr         $a0, 0x0($a2)
    ctx->pc = 0x11be20u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11be24: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x11BE24u;
    {
        const bool branch_taken_0x11be24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BE24u;
            // 0x11be28: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11be24) {
            ctx->pc = 0x11BE60u;
            goto label_11be60;
        }
    }
    ctx->pc = 0x11BE2Cu;
label_11be2c:
    // 0x11be2c: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x11be2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x11be30: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x11be30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11be34: 0x0  nop
    ctx->pc = 0x11be34u;
    // NOP
label_11be38:
    // 0x11be38: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x11be38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x11be3c: 0x0  nop
    ctx->pc = 0x11be3cu;
    // NOP
    // 0x11be40: 0x0  nop
    ctx->pc = 0x11be40u;
    // NOP
    // 0x11be44: 0x0  nop
    ctx->pc = 0x11be44u;
    // NOP
    // 0x11be48: 0x0  nop
    ctx->pc = 0x11be48u;
    // NOP
    // 0x11be4c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11BE4Cu;
    {
        const bool branch_taken_0x11be4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x11be4c) {
            ctx->pc = 0x11BE38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11be38;
        }
    }
    ctx->pc = 0x11BE54u;
    // 0x11be54: 0x1000ffd2  b           . + 4 + (-0x2E << 2)
    ctx->pc = 0x11BE54u;
    {
        const bool branch_taken_0x11be54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BE58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BE54u;
            // 0x11be58: 0x2630e600  addiu       $s0, $s1, -0x1A00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294960640));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11be54) {
            ctx->pc = 0x11BDA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11bda0;
        }
    }
    ctx->pc = 0x11BE5Cu;
label_11be5c:
    // 0x11be5c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11be5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11be60:
    // 0x11be60: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11be60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11be64: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11be64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11be68: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11be68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11be6c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11be6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11be70: 0x3e00008  jr          $ra
    ctx->pc = 0x11BE70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BE70u;
            // 0x11be74: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BDA0u: goto label_11bda0;
            case 0x11BDB4u: goto label_11bdb4;
            case 0x11BDC4u: goto label_11bdc4;
            case 0x11BDF8u: goto label_11bdf8;
            case 0x11BE0Cu: goto label_11be0c;
            case 0x11BE2Cu: goto label_11be2c;
            case 0x11BE38u: goto label_11be38;
            case 0x11BE5Cu: goto label_11be5c;
            case 0x11BE60u: goto label_11be60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BE78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
