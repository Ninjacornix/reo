#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CAA8
// Address: 0x13caa8 - 0x13cb30
void sub_0013CAA8_0x13caa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CAA8_0x13caa8");
#endif

    ctx->pc = 0x13caa8u;

    // 0x13caa8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13caa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13caac: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x13caacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cab0: 0x14800011  bnez        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x13CAB0u;
    {
        const bool branch_taken_0x13cab0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CAB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CAB0u;
            // 0x13cab4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cab0) {
            ctx->pc = 0x13CAF8u;
            goto label_13caf8;
        }
    }
    ctx->pc = 0x13CAB8u;
    // 0x13cab8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13cab8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13cabc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x13cabcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x13cac0: 0x2447d300  addiu       $a3, $v0, -0x2D00
    ctx->pc = 0x13cac0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955776));
    // 0x13cac4: 0x2466dfb0  addiu       $a2, $v1, -0x2050
    ctx->pc = 0x13cac4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 4294959024));
    // 0x13cac8: 0x88e40003  lwl         $a0, 0x3($a3)
    ctx->pc = 0x13cac8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x13cacc: 0x98e40000  lwr         $a0, 0x0($a3)
    ctx->pc = 0x13caccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x13cad0: 0x80e50004  lb          $a1, 0x4($a3)
    ctx->pc = 0x13cad0u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x13cad4: 0xa8c40003  swl         $a0, 0x3($a2)
    ctx->pc = 0x13cad4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x13cad8: 0xb8c40000  swr         $a0, 0x0($a2)
    ctx->pc = 0x13cad8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x13cadc: 0xa0c50004  sb          $a1, 0x4($a2)
    ctx->pc = 0x13cadcu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 4), (uint8_t)GPR_U32(ctx, 5));
    // 0x13cae0: 0x80e40005  lb          $a0, 0x5($a3)
    ctx->pc = 0x13cae0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 5)));
    // 0x13cae4: 0xa0c40005  sb          $a0, 0x5($a2)
    ctx->pc = 0x13cae4u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 5), (uint8_t)GPR_U32(ctx, 4));
    // 0x13cae8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13cae8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13caec: 0x3e00008  jr          $ra
    ctx->pc = 0x13CAECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CAF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CAECu;
            // 0x13caf0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CAF8u: goto label_13caf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CAF4u;
    // 0x13caf4: 0x0  nop
    ctx->pc = 0x13caf4u;
    // NOP
label_13caf8:
    // 0x13caf8: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13caf8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13cafc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13cafcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13cb00: 0x2484dfb0  addiu       $a0, $a0, -0x2050
    ctx->pc = 0x13cb00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959024));
    // 0x13cb04: 0x8042bf0  j           func_10AFC0
    ctx->pc = 0x13CB04u;
    ctx->pc = 0x13CB08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB04u;
            // 0x13cb08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13CB0Cu;
    // 0x13cb0c: 0x0  nop
    ctx->pc = 0x13cb0cu;
    // NOP
    // 0x13cb10: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13cb10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13cb14: 0x3e00008  jr          $ra
    ctx->pc = 0x13CB14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CB18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB14u;
            // 0x13cb18: 0x2442dfb0  addiu       $v0, $v0, -0x2050 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294959024));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CAF8u: goto label_13caf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CB1Cu;
    // 0x13cb1c: 0x0  nop
    ctx->pc = 0x13cb1cu;
    // NOP
    // 0x13cb20: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13cb20u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13cb24: 0x3e00008  jr          $ra
    ctx->pc = 0x13CB24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CB28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB24u;
            // 0x13cb28: 0x8c62dea0  lw          $v0, -0x2160($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294958752)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CAF8u: goto label_13caf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CB2Cu;
    // 0x13cb2c: 0x0  nop
    ctx->pc = 0x13cb2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
