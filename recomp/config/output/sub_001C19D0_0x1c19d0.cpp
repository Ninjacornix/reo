#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C19D0
// Address: 0x1c19d0 - 0x1c1a84
void sub_001C19D0_0x1c19d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C19D0_0x1c19d0");
#endif

    ctx->pc = 0x1c19d0u;

    // 0x1c19d0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1c19d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c19d4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c19d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c19d8: 0x90a30005  lbu         $v1, 0x5($a1)
    ctx->pc = 0x1c19d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c19dc: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1c19dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1c19e0: 0x90a40007  lbu         $a0, 0x7($a1)
    ctx->pc = 0x1c19e0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c19e4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c19e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c19e8: 0x24490688  addiu       $t1, $v0, 0x688
    ctx->pc = 0x1c19e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 1672));
    // 0x1c19ec: 0x69260007  ldl         $a2, 0x7($t1)
    ctx->pc = 0x1c19ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1c19f0: 0x6d260000  ldr         $a2, 0x0($t1)
    ctx->pc = 0x1c19f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1c19f4: 0x8927000b  lwl         $a3, 0xB($t1)
    ctx->pc = 0x1c19f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 7) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 7, (int32_t)merged); }
    // 0x1c19f8: 0x99270008  lwr         $a3, 0x8($t1)
    ctx->pc = 0x1c19f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 7) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 7) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 7, merged64); }
    // 0x1c19fc: 0xb3a60007  sdl         $a2, 0x7($sp)
    ctx->pc = 0x1c19fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1a00: 0xb7a60000  sdr         $a2, 0x0($sp)
    ctx->pc = 0x1c1a00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1a04: 0xaba7000b  swl         $a3, 0xB($sp)
    ctx->pc = 0x1c1a04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1a08: 0xbba70008  swr         $a3, 0x8($sp)
    ctx->pc = 0x1c1a08u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1a0c: 0x30840003  andi        $a0, $a0, 0x3
    ctx->pc = 0x1c1a0cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x1c1a10: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1A10u;
    {
        const bool branch_taken_0x1c1a10 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A10u;
            // 0x1c1a14: 0xa0a30005  sb          $v1, 0x5($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a10) {
            ctx->pc = 0x1C1A20u;
            goto label_1c1a20;
        }
    }
    ctx->pc = 0x1C1A18u;
    // 0x1c1a18: 0x2402001d  addiu       $v0, $zero, 0x1D
    ctx->pc = 0x1c1a18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1c1a1c: 0xa3a20001  sb          $v0, 0x1($sp)
    ctx->pc = 0x1c1a1cu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 1), (uint8_t)GPR_U32(ctx, 2));
label_1c1a20:
    // 0x1c1a20: 0x90a20006  lbu         $v0, 0x6($a1)
    ctx->pc = 0x1c1a20u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1a24: 0x90a40005  lbu         $a0, 0x5($a1)
    ctx->pc = 0x1c1a24u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c1a28: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1c1a28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1c1a2c: 0x8043ffff  lb          $v1, -0x1($v0)
    ctx->pc = 0x1c1a2cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x1c1a30: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x1c1a30u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1c1a34: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C1A34u;
    {
        const bool branch_taken_0x1c1a34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A34u;
            // 0x1c1a38: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a34) {
            ctx->pc = 0x1C1A7Cu;
            goto label_1c1a7c;
        }
    }
    ctx->pc = 0x1C1A3Cu;
    // 0x1c1a3c: 0x90a30006  lbu         $v1, 0x6($a1)
    ctx->pc = 0x1c1a3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1a40: 0xa0a20005  sb          $v0, 0x5($a1)
    ctx->pc = 0x1c1a40u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c1a44: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1c1a44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1c1a48: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c1a48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c1a4c: 0x306200ff  andi        $v0, $v1, 0xFF
    ctx->pc = 0x1c1a4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1c1a50: 0x1444000a  bne         $v0, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C1A50u;
    {
        const bool branch_taken_0x1c1a50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1C1A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A50u;
            // 0x1c1a54: 0xa0a30006  sb          $v1, 0x6($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a50) {
            ctx->pc = 0x1C1A7Cu;
            goto label_1c1a7c;
        }
    }
    ctx->pc = 0x1C1A58u;
    // 0x1c1a58: 0x90a30007  lbu         $v1, 0x7($a1)
    ctx->pc = 0x1c1a58u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c1a5c: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1c1a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c1a60: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1A60u;
    {
        const bool branch_taken_0x1c1a60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C1A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A60u;
            // 0x1c1a64: 0x24620001  addiu       $v0, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a60) {
            ctx->pc = 0x1C1A70u;
            goto label_1c1a70;
        }
    }
    ctx->pc = 0x1C1A68u;
    // 0x1c1a68: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1A68u;
    {
        const bool branch_taken_0x1c1a68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A68u;
            // 0x1c1a6c: 0xa0a00007  sb          $zero, 0x7($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 7), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a68) {
            ctx->pc = 0x1C1A74u;
            goto label_1c1a74;
        }
    }
    ctx->pc = 0x1C1A70u;
label_1c1a70:
    // 0x1c1a70: 0xa0a20007  sb          $v0, 0x7($a1)
    ctx->pc = 0x1c1a70u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 7), (uint8_t)GPR_U32(ctx, 2));
label_1c1a74:
    // 0x1c1a74: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c1a74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1a78: 0xa0a20006  sb          $v0, 0x6($a1)
    ctx->pc = 0x1c1a78u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 2));
label_1c1a7c:
    // 0x1c1a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A7Cu;
            // 0x1c1a80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1A20u: goto label_1c1a20;
            case 0x1C1A70u: goto label_1c1a70;
            case 0x1C1A74u: goto label_1c1a74;
            case 0x1C1A7Cu: goto label_1c1a7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1A84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
