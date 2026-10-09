#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016CA00
// Address: 0x16ca00 - 0x16cba8
void sub_0016CA00_0x16ca00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016CA00_0x16ca00");
#endif

    switch (ctx->pc) {
        case 0x16ca88u: goto label_16ca88;
        case 0x16ca9cu: goto label_16ca9c;
        case 0x16caf0u: goto label_16caf0;
        case 0x16cb6cu: goto label_16cb6c;
        default: break;
    }

    ctx->pc = 0x16ca00u;

    // 0x16ca00: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16ca00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16ca04: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16ca04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ca08: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16ca08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x16ca0c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16ca0cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ca10: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x16ca10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x16ca14: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16ca14u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ca18: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16ca18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16ca1c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x16ca1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x16ca20: 0x1220005a  beqz        $s1, . + 4 + (0x5A << 2)
    ctx->pc = 0x16CA20u;
    {
        const bool branch_taken_0x16ca20 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CA24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CA20u;
            // 0x16ca24: 0xafa50010  sw          $a1, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ca20) {
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CA28u;
    // 0x16ca28: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x16ca28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x16ca2c: 0x52230058  beql        $s1, $v1, . + 4 + (0x58 << 2)
    ctx->pc = 0x16CA2Cu;
    {
        const bool branch_taken_0x16ca2c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        if (branch_taken_0x16ca2c) {
            ctx->pc = 0x16CA30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CA2Cu;
            // 0x16ca30: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CB90u;
            goto label_16cb90;
        }
    }
    ctx->pc = 0x16CA34u;
    // 0x16ca34: 0x223102b  sltu        $v0, $s1, $v1
    ctx->pc = 0x16ca34u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x16ca38: 0x5440001b  bnel        $v0, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x16CA38u;
    {
        const bool branch_taken_0x16ca38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16ca38) {
            ctx->pc = 0x16CA3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CA38u;
            // 0x16ca3c: 0x8e430008  lw          $v1, 0x8($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CAA8u;
            goto label_16caa8;
        }
    }
    ctx->pc = 0x16CA40u;
    // 0x16ca40: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x16ca40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x16ca44: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x16ca44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16ca48: 0x222182b  sltu        $v1, $s1, $v0
    ctx->pc = 0x16ca48u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x16ca4c: 0x50600016  beql        $v1, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x16CA4Cu;
    {
        const bool branch_taken_0x16ca4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x16ca4c) {
            ctx->pc = 0x16CA50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CA4Cu;
            // 0x16ca50: 0x8e430008  lw          $v1, 0x8($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CAA8u;
            goto label_16caa8;
        }
    }
    ctx->pc = 0x16CA54u;
    // 0x16ca54: 0x2221023  subu        $v0, $s1, $v0
    ctx->pc = 0x16ca54u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x16ca58: 0x24500004  addiu       $s0, $v0, 0x4
    ctx->pc = 0x16ca58u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x16ca5c: 0x1a00001e  blez        $s0, . + 4 + (0x1E << 2)
    ctx->pc = 0x16CA5Cu;
    {
        const bool branch_taken_0x16ca5c = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x16ca5c) {
            ctx->pc = 0x16CAD8u;
            goto label_16cad8;
        }
    }
    ctx->pc = 0x16CA64u;
    // 0x16ca64: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x16ca64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x16ca68: 0x70182a  slt         $v1, $v1, $s0
    ctx->pc = 0x16ca68u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16ca6c: 0x14600047  bnez        $v1, . + 4 + (0x47 << 2)
    ctx->pc = 0x16CA6Cu;
    {
        const bool branch_taken_0x16ca6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16CA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CA6Cu;
            // 0x16ca70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ca6c) {
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CA74u;
    // 0x16ca74: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x16ca74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16ca78: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16ca78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ca7c: 0xd03023  subu        $a2, $a2, $s0
    ctx->pc = 0x16ca7cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x16ca80: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x16CA80u;
    SET_GPR_U32(ctx, 31, 0x16CA88u);
    ctx->pc = 0x16CA84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CA80u;
            // 0x16ca84: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CA88u; }
        if (ctx->pc != 0x16CA88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CA88u; }
        if (ctx->pc != 0x16CA88u) { return; }
    }
    ctx->pc = 0x16CA88u;
label_16ca88:
    // 0x16ca88: 0x8e450008  lw          $a1, 0x8($s2)
    ctx->pc = 0x16ca88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x16ca8c: 0x3b02023  subu        $a0, $sp, $s0
    ctx->pc = 0x16ca8cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 29), GPR_U32(ctx, 16)));
    // 0x16ca90: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16ca90u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ca94: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x16CA94u;
    SET_GPR_U32(ctx, 31, 0x16CA9Cu);
    ctx->pc = 0x16CA98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CA94u;
            // 0x16ca98: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CA9Cu; }
        if (ctx->pc != 0x16CA9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CA9Cu; }
        if (ctx->pc != 0x16CA9Cu) { return; }
    }
    ctx->pc = 0x16CA9Cu;
label_16ca9c:
    // 0x16ca9c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x16CA9Cu;
    {
        const bool branch_taken_0x16ca9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x16ca9c) {
            ctx->pc = 0x16CAE8u;
            goto label_16cae8;
        }
    }
    ctx->pc = 0x16CAA4u;
    // 0x16caa4: 0x0  nop
    ctx->pc = 0x16caa4u;
    // NOP
label_16caa8:
    // 0x16caa8: 0x223102b  sltu        $v0, $s1, $v1
    ctx->pc = 0x16caa8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x16caac: 0x14400037  bnez        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x16CAACu;
    {
        const bool branch_taken_0x16caac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16CAB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CAACu;
            // 0x16cab0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16caac) {
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CAB4u;
    // 0x16cab4: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x16cab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x16cab8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x16cab8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16cabc: 0x222182b  sltu        $v1, $s1, $v0
    ctx->pc = 0x16cabcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x16cac0: 0x50600032  beql        $v1, $zero, . + 4 + (0x32 << 2)
    ctx->pc = 0x16CAC0u;
    {
        const bool branch_taken_0x16cac0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x16cac0) {
            ctx->pc = 0x16CAC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CAC0u;
            // 0x16cac4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CAC8u;
    // 0x16cac8: 0x2221823  subu        $v1, $s1, $v0
    ctx->pc = 0x16cac8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x16cacc: 0x24700004  addiu       $s0, $v1, 0x4
    ctx->pc = 0x16caccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x16cad0: 0x1e00002e  bgtz        $s0, . + 4 + (0x2E << 2)
    ctx->pc = 0x16CAD0u;
    {
        const bool branch_taken_0x16cad0 = (GPR_S64(ctx, 16) > 0);
        ctx->pc = 0x16CAD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CAD0u;
            // 0x16cad4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cad0) {
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CAD8u;
label_16cad8:
    // 0x16cad8: 0x8a220003  lwl         $v0, 0x3($s1)
    ctx->pc = 0x16cad8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x16cadc: 0x9a220000  lwr         $v0, 0x0($s1)
    ctx->pc = 0x16cadcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x16cae0: 0xaba20003  swl         $v0, 0x3($sp)
    ctx->pc = 0x16cae0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x16cae4: 0xbba20000  swr         $v0, 0x0($sp)
    ctx->pc = 0x16cae4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_16cae8:
    // 0x16cae8: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x16CAE8u;
    SET_GPR_U32(ctx, 31, 0x16CAF0u);
    ctx->pc = 0x16CAECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CAE8u;
            // 0x16caec: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CAF0u; }
        if (ctx->pc != 0x16CAF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CAF0u; }
        if (ctx->pc != 0x16CAF0u) { return; }
    }
    ctx->pc = 0x16CAF0u;
label_16caf0:
    // 0x16caf0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16caf0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16caf4: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x16caf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x16caf8: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x16CAF8u;
    {
        const bool branch_taken_0x16caf8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16CAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CAF8u;
            // 0x16cafc: 0x2c620009  sltiu       $v0, $v1, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)9) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16caf8) {
            ctx->pc = 0x16CB38u;
            goto label_16cb38;
        }
    }
    ctx->pc = 0x16CB00u;
    // 0x16cb00: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16CB00u;
    {
        const bool branch_taken_0x16cb00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB00u;
            // 0x16cb04: 0x24020040  addiu       $v0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb00) {
            ctx->pc = 0x16CB20u;
            goto label_16cb20;
        }
    }
    ctx->pc = 0x16CB08u;
    // 0x16cb08: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x16cb08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16cb0c: 0x10620010  beq         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x16CB0Cu;
    {
        const bool branch_taken_0x16cb0c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16CB10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB0Cu;
            // 0x16cb10: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb0c) {
            ctx->pc = 0x16CB50u;
            goto label_16cb50;
        }
    }
    ctx->pc = 0x16CB14u;
    // 0x16cb14: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x16CB14u;
    {
        const bool branch_taken_0x16cb14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CB18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB14u;
            // 0x16cb18: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb14) {
            ctx->pc = 0x16CB90u;
            goto label_16cb90;
        }
    }
    ctx->pc = 0x16CB1Cu;
    // 0x16cb1c: 0x0  nop
    ctx->pc = 0x16cb1cu;
    // NOP
label_16cb20:
    // 0x16cb20: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x16CB20u;
    {
        const bool branch_taken_0x16cb20 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16CB24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB20u;
            // 0x16cb24: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb20) {
            ctx->pc = 0x16CB88u;
            goto label_16cb88;
        }
    }
    ctx->pc = 0x16CB28u;
    // 0x16cb28: 0x10620017  beq         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x16CB28u;
    {
        const bool branch_taken_0x16cb28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16CB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB28u;
            // 0x16cb2c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb28) {
            ctx->pc = 0x16CB88u;
            goto label_16cb88;
        }
    }
    ctx->pc = 0x16CB30u;
    // 0x16cb30: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x16CB30u;
    {
        const bool branch_taken_0x16cb30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB30u;
            // 0x16cb34: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb30) {
            ctx->pc = 0x16CB90u;
            goto label_16cb90;
        }
    }
    ctx->pc = 0x16CB38u;
label_16cb38:
    // 0x16cb38: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x16cb38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16cb3c: 0x30420040  andi        $v0, $v0, 0x40
    ctx->pc = 0x16cb3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)64);
    // 0x16cb40: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x16CB40u;
    {
        const bool branch_taken_0x16cb40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB40u;
            // 0x16cb44: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb40) {
            ctx->pc = 0x16CB88u;
            goto label_16cb88;
        }
    }
    ctx->pc = 0x16CB48u;
    // 0x16cb48: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x16CB48u;
    {
        const bool branch_taken_0x16cb48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CB4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB48u;
            // 0x16cb4c: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb48) {
            ctx->pc = 0x16CB64u;
            goto label_16cb64;
        }
    }
    ctx->pc = 0x16CB50u;
label_16cb50:
    // 0x16cb50: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x16cb50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16cb54: 0x30420048  andi        $v0, $v0, 0x48
    ctx->pc = 0x16cb54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)72);
    // 0x16cb58: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x16CB58u;
    {
        const bool branch_taken_0x16cb58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CB5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB58u;
            // 0x16cb5c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb58) {
            ctx->pc = 0x16CB88u;
            goto label_16cb88;
        }
    }
    ctx->pc = 0x16CB60u;
    // 0x16cb60: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x16cb60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_16cb64:
    // 0x16cb64: 0xc05b326  jal         func_16CC98
    ctx->pc = 0x16CB64u;
    SET_GPR_U32(ctx, 31, 0x16CB6Cu);
    ctx->pc = 0x16CB68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB64u;
            // 0x16cb68: 0x27a60010  addiu       $a2, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16CC98u;
    if (runtime->hasFunction(0x16CC98u)) {
        auto targetFn = runtime->lookupFunction(0x16CC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CB6Cu; }
        if (ctx->pc != 0x16CB6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016CC98_0x16cc98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CB6Cu; }
        if (ctx->pc != 0x16CB6Cu) { return; }
    }
    ctx->pc = 0x16CB6Cu;
label_16cb6c:
    // 0x16cb6c: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x16CB6Cu;
    {
        const bool branch_taken_0x16cb6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16cb6c) {
            ctx->pc = 0x16CB70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB6Cu;
            // 0x16cb70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CB74u;
    // 0x16cb74: 0x54510005  bnel        $v0, $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x16CB74u;
    {
        const bool branch_taken_0x16cb74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x16cb74) {
            ctx->pc = 0x16CB78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB74u;
            // 0x16cb78: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CB7Cu;
    // 0x16cb7c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16CB7Cu;
    {
        const bool branch_taken_0x16cb7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CB80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB7Cu;
            // 0x16cb80: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cb7c) {
            ctx->pc = 0x16CB8Cu;
            goto label_16cb8c;
        }
    }
    ctx->pc = 0x16CB84u;
    // 0x16cb84: 0x0  nop
    ctx->pc = 0x16cb84u;
    // NOP
label_16cb88:
    // 0x16cb88: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16cb88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16cb8c:
    // 0x16cb8c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16cb8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_16cb90:
    // 0x16cb90: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x16cb90u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16cb94: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x16cb94u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16cb98: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x16cb98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16cb9c: 0x3e00008  jr          $ra
    ctx->pc = 0x16CB9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16CBA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CB9Cu;
            // 0x16cba0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16CA88u: goto label_16ca88;
            case 0x16CA9Cu: goto label_16ca9c;
            case 0x16CAA8u: goto label_16caa8;
            case 0x16CAD8u: goto label_16cad8;
            case 0x16CAE8u: goto label_16cae8;
            case 0x16CAF0u: goto label_16caf0;
            case 0x16CB20u: goto label_16cb20;
            case 0x16CB38u: goto label_16cb38;
            case 0x16CB50u: goto label_16cb50;
            case 0x16CB64u: goto label_16cb64;
            case 0x16CB6Cu: goto label_16cb6c;
            case 0x16CB88u: goto label_16cb88;
            case 0x16CB8Cu: goto label_16cb8c;
            case 0x16CB90u: goto label_16cb90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16CBA4u;
    // 0x16cba4: 0x0  nop
    ctx->pc = 0x16cba4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
