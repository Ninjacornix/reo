#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001476C8
// Address: 0x1476c8 - 0x14779c
void sub_001476C8_0x1476c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001476C8_0x1476c8");
#endif

    ctx->pc = 0x1476c8u;

    // 0x1476c8: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1476c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1476cc: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1476ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1476d0: 0x3442e010  ori         $v0, $v0, 0xE010
    ctx->pc = 0x1476d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57360);
    // 0x1476d4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1476d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1476d8: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1476d8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1476dc: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1476dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1476e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1476E0u;
    {
        const bool branch_taken_0x1476e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1476E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1476E0u;
            // 0x1476e4: 0x3407ffff  ori         $a3, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1476e0) {
            ctx->pc = 0x1476F8u;
            goto label_1476f8;
        }
    }
    ctx->pc = 0x1476E8u;
    // 0x1476e8: 0xf  sync
    ctx->pc = 0x1476e8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1476ec: 0x42000038  ei
    ctx->pc = 0x1476ecu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1476f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1476F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1476F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1476F0u;
            // 0x1476f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1476F8u;
label_1476f8:
    // 0x1476f8: 0xe2102b  sltu        $v0, $a3, $v0
    ctx->pc = 0x1476f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1476fc: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1476FCu;
    {
        const bool branch_taken_0x1476fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x147700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1476FCu;
            // 0x147700: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1476fc) {
            ctx->pc = 0x14775Cu;
            goto label_14775c;
        }
    }
    ctx->pc = 0x147704u;
    // 0x147704: 0x8cc40004  lw          $a0, 0x4($a2)
    ctx->pc = 0x147704u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x147708: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147708u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x14770c: 0x3442b410  ori         $v0, $v0, 0xB410
    ctx->pc = 0x14770cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46096);
    // 0x147710: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x147710u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x147714: 0x3463b420  ori         $v1, $v1, 0xB420
    ctx->pc = 0x147714u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46112);
    // 0x147718: 0xac670000  sw          $a3, 0x0($v1)
    ctx->pc = 0x147718u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 7));
    // 0x14771c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x14771cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x147720: 0x3442b400  ori         $v0, $v0, 0xB400
    ctx->pc = 0x147720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46080);
    // 0x147724: 0x24030101  addiu       $v1, $zero, 0x101
    ctx->pc = 0x147724u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x147728: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x147728u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14772c: 0x3c05000f  lui         $a1, 0xF
    ctx->pc = 0x14772cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)15 << 16));
    // 0x147730: 0x34a5fff0  ori         $a1, $a1, 0xFFF0
    ctx->pc = 0x147730u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65520);
    // 0x147734: 0x3c040fff  lui         $a0, 0xFFF
    ctx->pc = 0x147734u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4095 << 16));
    // 0x147738: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x147738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x14773c: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x14773cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x147740: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x147740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x147744: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x147744u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x147748: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x147748u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x14774c: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x14774cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x147750: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x147750u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x147754: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x147754u;
    {
        const bool branch_taken_0x147754 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x147758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147754u;
            // 0x147758: 0xacc30004  sw          $v1, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147754) {
            ctx->pc = 0x14778Cu;
            goto label_14778c;
        }
    }
    ctx->pc = 0x14775Cu;
label_14775c:
    // 0x14775c: 0x8cc40004  lw          $a0, 0x4($a2)
    ctx->pc = 0x14775cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x147760: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147760u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x147764: 0x3442b410  ori         $v0, $v0, 0xB410
    ctx->pc = 0x147764u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46096);
    // 0x147768: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x147768u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x14776c: 0x3463b420  ori         $v1, $v1, 0xB420
    ctx->pc = 0x14776cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46112);
    // 0x147770: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147770u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x147774: 0x24050101  addiu       $a1, $zero, 0x101
    ctx->pc = 0x147774u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x147778: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x147778u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14777c: 0x3442b400  ori         $v0, $v0, 0xB400
    ctx->pc = 0x14777cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46080);
    // 0x147780: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x147780u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x147784: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x147784u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x147788: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x147788u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_14778c:
    // 0x14778c: 0xf  sync
    ctx->pc = 0x14778cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x147790: 0x42000038  ei
    ctx->pc = 0x147790u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x147794: 0x3e00008  jr          $ra
    ctx->pc = 0x147794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147794u;
            // 0x147798: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14779Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
