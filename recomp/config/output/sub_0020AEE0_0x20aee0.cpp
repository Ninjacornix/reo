#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020AEE0
// Address: 0x20aee0 - 0x20b080
void sub_0020AEE0_0x20aee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020AEE0_0x20aee0");
#endif

    switch (ctx->pc) {
        case 0x20af18u: goto label_20af18;
        case 0x20af90u: goto label_20af90;
        case 0x20b020u: goto label_20b020;
        case 0x20b04cu: goto label_20b04c;
        default: break;
    }

    ctx->pc = 0x20aee0u;

    // 0x20aee0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x20aee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x20aee4: 0x3c0c8007  lui         $t4, 0x8007
    ctx->pc = 0x20aee4u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)32775 << 16));
    // 0x20aee8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x20aee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x20aeec: 0x80682d  daddu       $t5, $a0, $zero
    ctx->pc = 0x20aeecu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20aef0: 0x8d826700  lw          $v0, 0x6700($t4)
    ctx->pc = 0x20aef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 26368)));
    // 0x20aef4: 0x180882d  daddu       $s1, $t4, $zero
    ctx->pc = 0x20aef4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20aef8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x20aef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x20aefc: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x20aefcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x20af00: 0x18400058  blez        $v0, . + 4 + (0x58 << 2)
    ctx->pc = 0x20AF00u;
    {
        const bool branch_taken_0x20af00 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x20AF04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AF00u;
            // 0x20af04: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20af00) {
            ctx->pc = 0x20B064u;
            goto label_20b064;
        }
    }
    ctx->pc = 0x20AF08u;
    // 0x20af08: 0x18400056  blez        $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x20AF08u;
    {
        const bool branch_taken_0x20af08 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x20AF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AF08u;
            // 0x20af0c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20af08) {
            ctx->pc = 0x20B064u;
            goto label_20b064;
        }
    }
    ctx->pc = 0x20AF10u;
    // 0x20af10: 0x3c0b8007  lui         $t3, 0x8007
    ctx->pc = 0x20af10u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32775 << 16));
    // 0x20af14: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x20af14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
label_20af18:
    // 0x20af18: 0x25656740  addiu       $a1, $t3, 0x6740
    ctx->pc = 0x20af18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 11), 26432));
    // 0x20af1c: 0x1032018  mult        $a0, $t0, $v1
    ctx->pc = 0x20af1cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x20af20: 0xa41021  addu        $v0, $a1, $a0
    ctx->pc = 0x20af20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x20af24: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x20af24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x20af28: 0x15a3004a  bne         $t5, $v1, . + 4 + (0x4A << 2)
    ctx->pc = 0x20AF28u;
    {
        const bool branch_taken_0x20af28 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 3));
        ctx->pc = 0x20AF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AF28u;
            // 0x20af2c: 0x8d826700  lw          $v0, 0x6700($t4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 26368)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20af28) {
            ctx->pc = 0x20B054u;
            goto label_20b054;
        }
    }
    ctx->pc = 0x20AF30u;
    // 0x20af30: 0x3c03b000  lui         $v1, 0xB000
    ctx->pc = 0x20af30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)45056 << 16));
    // 0x20af34: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x20af34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x20af38: 0x34631820  ori         $v1, $v1, 0x1820
    ctx->pc = 0x20af38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)6176);
    // 0x20af3c: 0x94850000  lhu         $a1, 0x0($a0)
    ctx->pc = 0x20af3cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x20af40: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x20af40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x20af44: 0x14a20008  bne         $a1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x20AF44u;
    {
        const bool branch_taken_0x20af44 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x20AF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AF44u;
            // 0x20af48: 0x24030014  addiu       $v1, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20af44) {
            ctx->pc = 0x20AF68u;
            goto label_20af68;
        }
    }
    ctx->pc = 0x20AF4Cu;
    // 0x20af4c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x20af4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x20af50: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x20af50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x20af54: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x20af54u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x20af58: 0x30631000  andi        $v1, $v1, 0x1000
    ctx->pc = 0x20af58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4096);
    // 0x20af5c: 0x14600043  bnez        $v1, . + 4 + (0x43 << 2)
    ctx->pc = 0x20AF5Cu;
    {
        const bool branch_taken_0x20af5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x20AF60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AF5Cu;
            // 0x20af60: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20af5c) {
            ctx->pc = 0x20B06Cu;
            goto label_20b06c;
        }
    }
    ctx->pc = 0x20AF64u;
    // 0x20af64: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x20af64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
label_20af68:
    // 0x20af68: 0x8d896700  lw          $t1, 0x6700($t4)
    ctx->pc = 0x20af68u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 26368)));
    // 0x20af6c: 0x1031818  mult        $v1, $t0, $v1
    ctx->pc = 0x20af6cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x20af70: 0x25646740  addiu       $a0, $t3, 0x6740
    ctx->pc = 0x20af70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 11), 26432));
    // 0x20af74: 0x2522ffff  addiu       $v0, $t1, -0x1
    ctx->pc = 0x20af74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x20af78: 0x100382d  daddu       $a3, $t0, $zero
    ctx->pc = 0x20af78u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20af7c: 0x102102a  slt         $v0, $t0, $v0
    ctx->pc = 0x20af7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x20af80: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x20af80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x20af84: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x20AF84u;
    {
        const bool branch_taken_0x20af84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20AF88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AF84u;
            // 0x20af88: 0x94700002  lhu         $s0, 0x2($v1) (Delay Slot)
        SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20af84) {
            ctx->pc = 0x20AFECu;
            goto label_20afec;
        }
    }
    ctx->pc = 0x20AF8Cu;
    // 0x20af8c: 0x3c0a8007  lui         $t2, 0x8007
    ctx->pc = 0x20af8cu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)32775 << 16));
label_20af90:
    // 0x20af90: 0x24e30001  addiu       $v1, $a3, 0x1
    ctx->pc = 0x20af90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x20af94: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x20af94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x20af98: 0x651018  mult        $v0, $v1, $a1
    ctx->pc = 0x20af98u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x20af9c: 0xe52018  mult        $a0, $a3, $a1
    ctx->pc = 0x20af9cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x20afa0: 0x25666740  addiu       $a2, $t3, 0x6740
    ctx->pc = 0x20afa0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 11), 26432));
    // 0x20afa4: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x20afa4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20afa8: 0x462821  addu        $a1, $v0, $a2
    ctx->pc = 0x20afa8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x20afac: 0x862021  addu        $a0, $a0, $a2
    ctx->pc = 0x20afacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x20afb0: 0x2522ffff  addiu       $v0, $t1, -0x1
    ctx->pc = 0x20afb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x20afb4: 0x68a30007  ldl         $v1, 0x7($a1)
    ctx->pc = 0x20afb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x20afb8: 0x6ca30000  ldr         $v1, 0x0($a1)
    ctx->pc = 0x20afb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x20afbc: 0x68a6000f  ldl         $a2, 0xF($a1)
    ctx->pc = 0x20afbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x20afc0: 0x6ca60008  ldr         $a2, 0x8($a1)
    ctx->pc = 0x20afc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x20afc4: 0x8cae0010  lw          $t6, 0x10($a1)
    ctx->pc = 0x20afc4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x20afc8: 0xb0830007  sdl         $v1, 0x7($a0)
    ctx->pc = 0x20afc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20afcc: 0xb4830000  sdr         $v1, 0x0($a0)
    ctx->pc = 0x20afccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20afd0: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x20afd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20afd4: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x20afd4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20afd8: 0xe2102a  slt         $v0, $a3, $v0
    ctx->pc = 0x20afd8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x20afdc: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x20AFDCu;
    {
        const bool branch_taken_0x20afdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20AFE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AFDCu;
            // 0x20afe0: 0xac8e0010  sw          $t6, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20afdc) {
            ctx->pc = 0x20AF90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20af90;
        }
    }
    ctx->pc = 0x20AFE4u;
    // 0x20afe4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x20AFE4u;
    {
        const bool branch_taken_0x20afe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20AFE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AFE4u;
            // 0x20afe8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20afe4) {
            ctx->pc = 0x20AFF4u;
            goto label_20aff4;
        }
    }
    ctx->pc = 0x20AFECu;
label_20afec:
    // 0x20afec: 0x3c0a8007  lui         $t2, 0x8007
    ctx->pc = 0x20afecu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)32775 << 16));
    // 0x20aff0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x20aff0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_20aff4:
    // 0x20aff4: 0x8d846700  lw          $a0, 0x6700($t4)
    ctx->pc = 0x20aff4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 26368)));
    // 0x20aff8: 0xdd436708  ld          $v1, 0x6708($t2)
    ctx->pc = 0x20aff8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 10), 26376)));
    // 0x20affc: 0x1a21014  dsllv       $v0, $v0, $t5
    ctx->pc = 0x20affcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 13) & 0x3F));
    // 0x20b000: 0x21027  nor         $v0, $zero, $v0
    ctx->pc = 0x20b000u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x20b004: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x20b004u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x20b008: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x20b008u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x20b00c: 0xad846700  sw          $a0, 0x6700($t4)
    ctx->pc = 0x20b00cu;
    WRITE32(ADD32(GPR_U32(ctx, 12), 26368), GPR_U32(ctx, 4));
    // 0x20b010: 0x15000003  bnez        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x20B010u;
    {
        const bool branch_taken_0x20b010 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x20B014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B010u;
            // 0x20b014: 0xfd436708  sd          $v1, 0x6708($t2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 10), 26376), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b010) {
            ctx->pc = 0x20B020u;
            goto label_20b020;
        }
    }
    ctx->pc = 0x20B018u;
    // 0x20b018: 0xc01d918  jal         func_076460
    ctx->pc = 0x20B018u;
    SET_GPR_U32(ctx, 31, 0x20B020u);
    ctx->pc = 0x20B01Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20B018u;
            // 0x20b01c: 0x95646740  lhu         $a0, 0x6740($t3) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 26432)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76460u;
    {
        auto targetFn = runtime->lookupFunction(0x76460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20B020u; }
        if (ctx->pc != 0x20B020u) { return; }
    }
    ctx->pc = 0x20B020u;
label_20b020:
    // 0x20b020: 0x8e226700  lw          $v0, 0x6700($s1)
    ctx->pc = 0x20b020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 26368)));
    // 0x20b024: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x20B024u;
    {
        const bool branch_taken_0x20b024 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20B028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B024u;
            // 0x20b028: 0x24030083  addiu       $v1, $zero, 0x83 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 131));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b024) {
            ctx->pc = 0x20B038u;
            goto label_20b038;
        }
    }
    ctx->pc = 0x20B02Cu;
    // 0x20b02c: 0x3c02b000  lui         $v0, 0xB000
    ctx->pc = 0x20b02cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)45056 << 16));
    // 0x20b030: 0x34421810  ori         $v0, $v0, 0x1810
    ctx->pc = 0x20b030u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6160);
    // 0x20b034: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x20b034u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_20b038:
    // 0x20b038: 0x3c02b000  lui         $v0, 0xB000
    ctx->pc = 0x20b038u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)45056 << 16));
    // 0x20b03c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x20b03cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b040: 0x34421800  ori         $v0, $v0, 0x1800
    ctx->pc = 0x20b040u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6144);
    // 0x20b044: 0xc01d80e  jal         func_076038
    ctx->pc = 0x20B044u;
    SET_GPR_U32(ctx, 31, 0x20B04Cu);
    ctx->pc = 0x20B048u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20B044u;
            // 0x20b048: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76038u;
    {
        auto targetFn = runtime->lookupFunction(0x76038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20B04Cu; }
        if (ctx->pc != 0x20B04Cu) { return; }
    }
    ctx->pc = 0x20B04Cu;
label_20b04c:
    // 0x20b04c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x20B04Cu;
    {
        const bool branch_taken_0x20b04c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20B050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B04Cu;
            // 0x20b050: 0x503023  subu        $a2, $v0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b04c) {
            ctx->pc = 0x20B064u;
            goto label_20b064;
        }
    }
    ctx->pc = 0x20B054u;
label_20b054:
    // 0x20b054: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x20b054u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x20b058: 0x102102a  slt         $v0, $t0, $v0
    ctx->pc = 0x20b058u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x20b05c: 0x1440ffae  bnez        $v0, . + 4 + (-0x52 << 2)
    ctx->pc = 0x20B05Cu;
    {
        const bool branch_taken_0x20b05c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20B060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B05Cu;
            // 0x20b060: 0x24030014  addiu       $v1, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b05c) {
            ctx->pc = 0x20AF18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20af18;
        }
    }
    ctx->pc = 0x20B064u;
label_20b064:
    // 0x20b064: 0xf  sync
    ctx->pc = 0x20b064u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20b068: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x20b068u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_20b06c:
    // 0x20b06c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x20b06cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x20b070: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x20b070u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20b074: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x20b074u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x20b078: 0x3e00008  jr          $ra
    ctx->pc = 0x20B078u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20B07Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B078u;
            // 0x20b07c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20AF18u: goto label_20af18;
            case 0x20AF68u: goto label_20af68;
            case 0x20AF90u: goto label_20af90;
            case 0x20AFECu: goto label_20afec;
            case 0x20AFF4u: goto label_20aff4;
            case 0x20B020u: goto label_20b020;
            case 0x20B038u: goto label_20b038;
            case 0x20B04Cu: goto label_20b04c;
            case 0x20B054u: goto label_20b054;
            case 0x20B064u: goto label_20b064;
            case 0x20B06Cu: goto label_20b06c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20B080u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
