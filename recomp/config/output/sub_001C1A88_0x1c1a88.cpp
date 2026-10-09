#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1A88
// Address: 0x1c1a88 - 0x1c1b2c
void sub_001C1A88_0x1c1a88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1A88_0x1c1a88");
#endif

    ctx->pc = 0x1c1a88u;

    // 0x1c1a88: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1c1a88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1a8c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c1a8cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c1a90: 0x90a30005  lbu         $v1, 0x5($a1)
    ctx->pc = 0x1c1a90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c1a94: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1c1a94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1c1a98: 0x90a40007  lbu         $a0, 0x7($a1)
    ctx->pc = 0x1c1a98u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c1a9c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1c1a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1c1aa0: 0x24490688  addiu       $t1, $v0, 0x688
    ctx->pc = 0x1c1aa0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 1672));
    // 0x1c1aa4: 0x69260007  ldl         $a2, 0x7($t1)
    ctx->pc = 0x1c1aa4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1c1aa8: 0x6d260000  ldr         $a2, 0x0($t1)
    ctx->pc = 0x1c1aa8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1c1aac: 0x8927000b  lwl         $a3, 0xB($t1)
    ctx->pc = 0x1c1aacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 7) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 7, (int32_t)merged); }
    // 0x1c1ab0: 0x99270008  lwr         $a3, 0x8($t1)
    ctx->pc = 0x1c1ab0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 7) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 7) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 7, merged64); }
    // 0x1c1ab4: 0xb3a60007  sdl         $a2, 0x7($sp)
    ctx->pc = 0x1c1ab4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1ab8: 0xb7a60000  sdr         $a2, 0x0($sp)
    ctx->pc = 0x1c1ab8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1abc: 0xaba7000b  swl         $a3, 0xB($sp)
    ctx->pc = 0x1c1abcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1ac0: 0xbba70008  swr         $a3, 0x8($sp)
    ctx->pc = 0x1c1ac0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1ac4: 0x30840003  andi        $a0, $a0, 0x3
    ctx->pc = 0x1c1ac4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x1c1ac8: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1AC8u;
    {
        const bool branch_taken_0x1c1ac8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1AC8u;
            // 0x1c1acc: 0xa0a30005  sb          $v1, 0x5($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1ac8) {
            ctx->pc = 0x1C1AD8u;
            goto label_1c1ad8;
        }
    }
    ctx->pc = 0x1C1AD0u;
    // 0x1c1ad0: 0x2402001d  addiu       $v0, $zero, 0x1D
    ctx->pc = 0x1c1ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1c1ad4: 0xa3a20001  sb          $v0, 0x1($sp)
    ctx->pc = 0x1c1ad4u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 1), (uint8_t)GPR_U32(ctx, 2));
label_1c1ad8:
    // 0x1c1ad8: 0x90a20005  lbu         $v0, 0x5($a1)
    ctx->pc = 0x1c1ad8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c1adc: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C1ADCu;
    {
        const bool branch_taken_0x1c1adc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c1adc) {
            ctx->pc = 0x1C1B24u;
            goto label_1c1b24;
        }
    }
    ctx->pc = 0x1C1AE4u;
    // 0x1c1ae4: 0x90a20006  lbu         $v0, 0x6($a1)
    ctx->pc = 0x1c1ae4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1ae8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c1ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c1aec: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1c1aecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c1af0: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C1AF0u;
    {
        const bool branch_taken_0x1c1af0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1AF0u;
            // 0x1c1af4: 0xa0a20006  sb          $v0, 0x6($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1af0) {
            ctx->pc = 0x1C1B14u;
            goto label_1c1b14;
        }
    }
    ctx->pc = 0x1C1AF8u;
    // 0x1c1af8: 0x90a20007  lbu         $v0, 0x7($a1)
    ctx->pc = 0x1c1af8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c1afc: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1AFCu;
    {
        const bool branch_taken_0x1c1afc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1AFCu;
            // 0x1c1b00: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1afc) {
            ctx->pc = 0x1C1B08u;
            goto label_1c1b08;
        }
    }
    ctx->pc = 0x1C1B04u;
    // 0x1c1b04: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1c1b04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
label_1c1b08:
    // 0x1c1b08: 0xa0a20007  sb          $v0, 0x7($a1)
    ctx->pc = 0x1c1b08u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 7), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c1b0c: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x1c1b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1c1b10: 0xa0a20006  sb          $v0, 0x6($a1)
    ctx->pc = 0x1c1b10u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 2));
label_1c1b14:
    // 0x1c1b14: 0x90a20006  lbu         $v0, 0x6($a1)
    ctx->pc = 0x1c1b14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1b18: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1c1b18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1c1b1c: 0x9043ffff  lbu         $v1, -0x1($v0)
    ctx->pc = 0x1c1b1cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x1c1b20: 0xa0a30005  sb          $v1, 0x5($a1)
    ctx->pc = 0x1c1b20u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 3));
label_1c1b24:
    // 0x1c1b24: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1B24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B24u;
            // 0x1c1b28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1AD8u: goto label_1c1ad8;
            case 0x1C1B08u: goto label_1c1b08;
            case 0x1C1B14u: goto label_1c1b14;
            case 0x1C1B24u: goto label_1c1b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1B2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
