#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00113988
// Address: 0x113988 - 0x113b08
void sub_00113988_0x113988(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00113988_0x113988");
#endif

    switch (ctx->pc) {
        case 0x1139c0u: goto label_1139c0;
        case 0x113a58u: goto label_113a58;
        case 0x113ac8u: goto label_113ac8;
        default: break;
    }

    ctx->pc = 0x113988u;

    // 0x113988: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x113988u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11398c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11398cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113990: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x113990u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x113994: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x113994u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x113998: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x113998u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11399c: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x11399cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1139a0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1139a0u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1139a4: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x1139a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x1139a8: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1139A8u;
    {
        const bool branch_taken_0x1139a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1139ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1139A8u;
            // 0x1139ac: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1139a8) {
            ctx->pc = 0x1139DCu;
            goto label_1139dc;
        }
    }
    ctx->pc = 0x1139B0u;
    // 0x1139b0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1139b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1139b4: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x1139b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x1139b8: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x1139b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x1139bc: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x1139bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_1139c0:
    // 0x1139c0: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x1139c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1139c4: 0x1440003d  bnez        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x1139C4u;
    {
        const bool branch_taken_0x1139c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1139C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1139C4u;
            // 0x1139c8: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1139c4) {
            ctx->pc = 0x113ABCu;
            goto label_113abc;
        }
    }
    ctx->pc = 0x1139CCu;
    // 0x1139cc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1139ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1139d0: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x1139d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x1139d4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1139D4u;
    {
        const bool branch_taken_0x1139d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1139D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1139D4u;
            // 0x1139d8: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1139d4) {
            ctx->pc = 0x1139C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1139c0;
        }
    }
    ctx->pc = 0x1139DCu;
label_1139dc:
    // 0x1139dc: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1139dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1139e0: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1139e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1139e4: 0x3442a020  ori         $v0, $v0, 0xA020
    ctx->pc = 0x1139e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40992);
    // 0x1139e8: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1139e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1139ec: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x1139ecu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x1139f0: 0xe41824  and         $v1, $a3, $a0
    ctx->pc = 0x1139f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & GPR_U64(ctx, 4));
    // 0x1139f4: 0x14640008  bne         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1139F4u;
    {
        const bool branch_taken_0x1139f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x1139F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1139F4u;
            // 0x1139f8: 0x3c020fff  lui         $v0, 0xFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1139f4) {
            ctx->pc = 0x113A18u;
            goto label_113a18;
        }
    }
    ctx->pc = 0x1139FCu;
    // 0x1139fc: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1139fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113a00: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x113a00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x113a04: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x113a04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x113a08: 0xe21024  and         $v0, $a3, $v0
    ctx->pc = 0x113a08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 2));
    // 0x113a0c: 0x3463a010  ori         $v1, $v1, 0xA010
    ctx->pc = 0x113a0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40976);
    // 0x113a10: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x113A10u;
    {
        const bool branch_taken_0x113a10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113A10u;
            // 0x113a14: 0x441025  or          $v0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113a10) {
            ctx->pc = 0x113A28u;
            goto label_113a28;
        }
    }
    ctx->pc = 0x113A18u;
label_113a18:
    // 0x113a18: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113a18u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113a1c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x113a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x113a20: 0x3463a010  ori         $v1, $v1, 0xA010
    ctx->pc = 0x113a20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40976);
    // 0x113a24: 0xe21024  and         $v0, $a3, $v0
    ctx->pc = 0x113a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 2));
label_113a28:
    // 0x113a28: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x113a28u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x113a2c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113a30: 0x24040101  addiu       $a0, $zero, 0x101
    ctx->pc = 0x113a30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x113a34: 0x3442a000  ori         $v0, $v0, 0xA000
    ctx->pc = 0x113a34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40960);
    // 0x113a38: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x113a38u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x113a3c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x113a3cu;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113a40: 0x30630100  andi        $v1, $v1, 0x100
    ctx->pc = 0x113a40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)256);
    // 0x113a44: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x113A44u;
    {
        const bool branch_taken_0x113a44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x113A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113A44u;
            // 0x113a48: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113a44) {
            ctx->pc = 0x113A74u;
            goto label_113a74;
        }
    }
    ctx->pc = 0x113A4Cu;
    // 0x113a4c: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x113a4cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x113a50: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x113a50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x113a54: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x113a54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_113a58:
    // 0x113a58: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x113a58u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x113a5c: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x113A5Cu;
    {
        const bool branch_taken_0x113a5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113A5Cu;
            // 0x113a60: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113a5c) {
            ctx->pc = 0x113ABCu;
            goto label_113abc;
        }
    }
    ctx->pc = 0x113A64u;
    // 0x113a64: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x113a64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113a68: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x113a68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x113a6c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113A6Cu;
    {
        const bool branch_taken_0x113a6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113A6Cu;
            // 0x113a70: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113a6c) {
            ctx->pc = 0x113A58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113a58;
        }
    }
    ctx->pc = 0x113A74u;
label_113a74:
    // 0x113a74: 0xdce20050  ld          $v0, 0x50($a3)
    ctx->pc = 0x113a74u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 7), 80)));
    // 0x113a78: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113a78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113a7c: 0x3463a020  ori         $v1, $v1, 0xA020
    ctx->pc = 0x113a7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40992);
    // 0x113a80: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x113a80u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x113a84: 0x30427fff  andi        $v0, $v0, 0x7FFF
    ctx->pc = 0x113a84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x113a88: 0x1052024  and         $a0, $t0, $a1
    ctx->pc = 0x113a88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 8) & GPR_U64(ctx, 5));
    // 0x113a8c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x113a8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x113a90: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x113a90u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x113a94: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x113a94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x113a98: 0x1485000d  bne         $a0, $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x113A98u;
    {
        const bool branch_taken_0x113a98 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 5));
        ctx->pc = 0x113A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113A98u;
            // 0x113a9c: 0x3c020fff  lui         $v0, 0xFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113a98) {
            ctx->pc = 0x113AD0u;
            goto label_113ad0;
        }
    }
    ctx->pc = 0x113AA0u;
    // 0x113aa0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113aa4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x113aa4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x113aa8: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x113aa8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x113aac: 0x1021024  and         $v0, $t0, $v0
    ctx->pc = 0x113aacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
    // 0x113ab0: 0x3463a010  ori         $v1, $v1, 0xA010
    ctx->pc = 0x113ab0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40976);
    // 0x113ab4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x113AB4u;
    {
        const bool branch_taken_0x113ab4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113AB4u;
            // 0x113ab8: 0x441025  or          $v0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113ab4) {
            ctx->pc = 0x113AE0u;
            goto label_113ae0;
        }
    }
    ctx->pc = 0x113ABCu;
label_113abc:
    // 0x113abc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113abcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x113ac0: 0xc045a12  jal         func_116848
    ctx->pc = 0x113AC0u;
    SET_GPR_U32(ctx, 31, 0x113AC8u);
    ctx->pc = 0x113AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113AC0u;
            // 0x113ac4: 0x248488e0  addiu       $a0, $a0, -0x7720 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936800));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113AC8u; }
        if (ctx->pc != 0x113AC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113AC8u; }
        if (ctx->pc != 0x113AC8u) { return; }
    }
    ctx->pc = 0x113AC8u;
label_113ac8:
    // 0x113ac8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x113AC8u;
    {
        const bool branch_taken_0x113ac8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113AC8u;
            // 0x113acc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113ac8) {
            ctx->pc = 0x113AF8u;
            goto label_113af8;
        }
    }
    ctx->pc = 0x113AD0u;
label_113ad0:
    // 0x113ad0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113ad0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113ad4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x113ad4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x113ad8: 0x3463a010  ori         $v1, $v1, 0xA010
    ctx->pc = 0x113ad8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40976);
    // 0x113adc: 0x1021024  and         $v0, $t0, $v0
    ctx->pc = 0x113adcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
label_113ae0:
    // 0x113ae0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x113ae0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x113ae4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113ae8: 0x24040101  addiu       $a0, $zero, 0x101
    ctx->pc = 0x113ae8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x113aec: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x113aecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x113af0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x113af0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113af4: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x113af4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_113af8:
    // 0x113af8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x113af8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113afc: 0x3e00008  jr          $ra
    ctx->pc = 0x113AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113AFCu;
            // 0x113b00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1139C0u: goto label_1139c0;
            case 0x1139DCu: goto label_1139dc;
            case 0x113A18u: goto label_113a18;
            case 0x113A28u: goto label_113a28;
            case 0x113A58u: goto label_113a58;
            case 0x113A74u: goto label_113a74;
            case 0x113ABCu: goto label_113abc;
            case 0x113AC8u: goto label_113ac8;
            case 0x113AD0u: goto label_113ad0;
            case 0x113AE0u: goto label_113ae0;
            case 0x113AF8u: goto label_113af8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113B04u;
    // 0x113b04: 0x0  nop
    ctx->pc = 0x113b04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
