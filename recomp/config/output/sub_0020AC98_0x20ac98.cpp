#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020AC98
// Address: 0x20ac98 - 0x20ad9c
void sub_0020AC98_0x20ac98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020AC98_0x20ac98");
#endif

    switch (ctx->pc) {
        case 0x20ace0u: goto label_20ace0;
        case 0x20acf8u: goto label_20acf8;
        case 0x20ad18u: goto label_20ad18;
        default: break;
    }

    ctx->pc = 0x20ac98u;

    // 0x20ac98: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x20ac98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x20ac9c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x20ac9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x20aca0: 0x3c138007  lui         $s3, 0x8007
    ctx->pc = 0x20aca0u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32775 << 16));
    // 0x20aca4: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x20aca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x20aca8: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x20aca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x20acac: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x20acacu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20acb0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x20acb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x20acb4: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x20acb4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20acb8: 0x8e626700  lw          $v0, 0x6700($s3)
    ctx->pc = 0x20acb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 26368)));
    // 0x20acbc: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x20acbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20acc0: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x20acc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x20acc4: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x20acc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x20acc8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x20acc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x20accc: 0x18400028  blez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x20ACCCu;
    {
        const bool branch_taken_0x20accc = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x20ACD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20ACCCu;
            // 0x20acd0: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20accc) {
            ctx->pc = 0x20AD70u;
            goto label_20ad70;
        }
    }
    ctx->pc = 0x20ACD4u;
    // 0x20acd4: 0x3c148007  lui         $s4, 0x8007
    ctx->pc = 0x20acd4u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32775 << 16));
    // 0x20acd8: 0x24120014  addiu       $s2, $zero, 0x14
    ctx->pc = 0x20acd8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x20acdc: 0x0  nop
    ctx->pc = 0x20acdcu;
    // NOP
label_20ace0:
    // 0x20ace0: 0x26916740  addiu       $s1, $s4, 0x6740
    ctx->pc = 0x20ace0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 20), 26432));
    // 0x20ace4: 0x2121018  mult        $v0, $s0, $s2
    ctx->pc = 0x20ace4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x20ace8: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x20ace8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20acec: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x20acecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x20acf0: 0xc01d80e  jal         func_076038
    ctx->pc = 0x20ACF0u;
    SET_GPR_U32(ctx, 31, 0x20ACF8u);
    ctx->pc = 0x20ACF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20ACF0u;
            // 0x20acf4: 0x94450000  lhu         $a1, 0x0($v0) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76038u;
    {
        auto targetFn = runtime->lookupFunction(0x76038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20ACF8u; }
        if (ctx->pc != 0x20ACF8u) { return; }
    }
    ctx->pc = 0x20ACF8u;
label_20acf8:
    // 0x20acf8: 0x2a2102a  slt         $v0, $s5, $v0
    ctx->pc = 0x20acf8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x20acfc: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x20ACFCu;
    {
        const bool branch_taken_0x20acfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20AD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20ACFCu;
            // 0x20ad00: 0x8e626700  lw          $v0, 0x6700($s3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 26368)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20acfc) {
            ctx->pc = 0x20AD60u;
            goto label_20ad60;
        }
    }
    ctx->pc = 0x20AD04u;
    // 0x20ad04: 0x2444ffff  addiu       $a0, $v0, -0x1
    ctx->pc = 0x20ad04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x20ad08: 0x90182a  slt         $v1, $a0, $s0
    ctx->pc = 0x20ad08u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x20ad0c: 0x14600018  bnez        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x20AD0Cu;
    {
        const bool branch_taken_0x20ad0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x20AD10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AD0Cu;
            // 0x20ad10: 0x921018  mult        $v0, $a0, $s2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x20ad0c) {
            ctx->pc = 0x20AD70u;
            goto label_20ad70;
        }
    }
    ctx->pc = 0x20AD14u;
    // 0x20ad14: 0x511821  addu        $v1, $v0, $s1
    ctx->pc = 0x20ad14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
label_20ad18:
    // 0x20ad18: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x20ad18u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x20ad1c: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x20ad1cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x20ad20: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x20ad20u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x20ad24: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x20ad24u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x20ad28: 0x8c670010  lw          $a3, 0x10($v1)
    ctx->pc = 0x20ad28u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x20ad2c: 0xb065001b  sdl         $a1, 0x1B($v1)
    ctx->pc = 0x20ad2cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20ad30: 0xb4650014  sdr         $a1, 0x14($v1)
    ctx->pc = 0x20ad30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20ad34: 0xb0660023  sdl         $a2, 0x23($v1)
    ctx->pc = 0x20ad34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20ad38: 0xb466001c  sdr         $a2, 0x1C($v1)
    ctx->pc = 0x20ad38u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20ad3c: 0xac670024  sw          $a3, 0x24($v1)
    ctx->pc = 0x20ad3cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 36), GPR_U32(ctx, 7));
    // 0x20ad40: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x20ad40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x20ad44: 0x2463ffec  addiu       $v1, $v1, -0x14
    ctx->pc = 0x20ad44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967276));
    // 0x20ad48: 0x90102a  slt         $v0, $a0, $s0
    ctx->pc = 0x20ad48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x20ad4c: 0x0  nop
    ctx->pc = 0x20ad4cu;
    // NOP
    // 0x20ad50: 0x1040fff1  beqz        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x20AD50u;
    {
        const bool branch_taken_0x20ad50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x20ad50) {
            ctx->pc = 0x20AD18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20ad18;
        }
    }
    ctx->pc = 0x20AD58u;
    // 0x20ad58: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x20AD58u;
    {
        const bool branch_taken_0x20ad58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20AD5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AD58u;
            // 0x20ad5c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20ad58) {
            ctx->pc = 0x20AD74u;
            goto label_20ad74;
        }
    }
    ctx->pc = 0x20AD60u;
label_20ad60:
    // 0x20ad60: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x20ad60u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x20ad64: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x20ad64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x20ad68: 0x1440ffdd  bnez        $v0, . + 4 + (-0x23 << 2)
    ctx->pc = 0x20AD68u;
    {
        const bool branch_taken_0x20ad68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20AD6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AD68u;
            // 0x20ad6c: 0x24120014  addiu       $s2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20ad68) {
            ctx->pc = 0x20ACE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20ace0;
        }
    }
    ctx->pc = 0x20AD70u;
label_20ad70:
    // 0x20ad70: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x20ad70u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_20ad74:
    // 0x20ad74: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x20ad74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x20ad78: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x20ad78u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x20ad7c: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x20ad7cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x20ad80: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x20ad80u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x20ad84: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x20ad84u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x20ad88: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x20ad88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x20ad8c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x20ad8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20ad90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x20ad90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x20ad94: 0x3e00008  jr          $ra
    ctx->pc = 0x20AD94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20AD98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AD94u;
            // 0x20ad98: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20ACE0u: goto label_20ace0;
            case 0x20ACF8u: goto label_20acf8;
            case 0x20AD18u: goto label_20ad18;
            case 0x20AD60u: goto label_20ad60;
            case 0x20AD70u: goto label_20ad70;
            case 0x20AD74u: goto label_20ad74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20AD9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
