#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122EF0
// Address: 0x122ef0 - 0x122fa0
void sub_00122EF0_0x122ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122EF0_0x122ef0");
#endif

    ctx->pc = 0x122ef0u;

    // 0x122ef0: 0x80702d  daddu       $t6, $a0, $zero
    ctx->pc = 0x122ef0u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122ef4: 0x8dc300bc  lw          $v1, 0xBC($t6)
    ctx->pc = 0x122ef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 188)));
    // 0x122ef8: 0x10600027  beqz        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x122EF8u;
    {
        const bool branch_taken_0x122ef8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x122EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122EF8u;
            // 0x122efc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122ef8) {
            ctx->pc = 0x122F98u;
            goto label_122f98;
        }
    }
    ctx->pc = 0x122F00u;
    // 0x122f00: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x122f00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x122f04: 0x8dcc003c  lw          $t4, 0x3C($t6)
    ctx->pc = 0x122f04u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 60)));
    // 0x122f08: 0x8dcd0040  lw          $t5, 0x40($t6)
    ctx->pc = 0x122f08u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x122f0c: 0x240a0001  addiu       $t2, $zero, 0x1
    ctx->pc = 0x122f0cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122f10: 0x8dcb0044  lw          $t3, 0x44($t6)
    ctx->pc = 0x122f10u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x122f14: 0x24090600  addiu       $t1, $zero, 0x600
    ctx->pc = 0x122f14u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x122f18: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x122f18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x122f1c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x122f1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x122f20: 0x2405007f  addiu       $a1, $zero, 0x7F
    ctx->pc = 0x122f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x122f24: 0x2406000f  addiu       $a2, $zero, 0xF
    ctx->pc = 0x122f24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x122f28: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x122f28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122f2c: 0x2408007f  addiu       $t0, $zero, 0x7F
    ctx->pc = 0x122f2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x122f30: 0x3402bb80  ori         $v0, $zero, 0xBB80
    ctx->pc = 0x122f30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
    // 0x122f34: 0xa1ca000e  sb          $t2, 0xE($t6)
    ctx->pc = 0x122f34u;
    WRITE8(ADD32(GPR_U32(ctx, 14), 14), (uint8_t)GPR_U32(ctx, 10));
    // 0x122f38: 0xa1c4000d  sb          $a0, 0xD($t6)
    ctx->pc = 0x122f38u;
    WRITE8(ADD32(GPR_U32(ctx, 14), 13), (uint8_t)GPR_U32(ctx, 4));
    // 0x122f3c: 0xadc30018  sw          $v1, 0x18($t6)
    ctx->pc = 0x122f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 24), GPR_U32(ctx, 3));
    // 0x122f40: 0xa1c5000f  sb          $a1, 0xF($t6)
    ctx->pc = 0x122f40u;
    WRITE8(ADD32(GPR_U32(ctx, 14), 15), (uint8_t)GPR_U32(ctx, 5));
    // 0x122f44: 0xa5c60098  sh          $a2, 0x98($t6)
    ctx->pc = 0x122f44u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 152), (uint16_t)GPR_U32(ctx, 6));
    // 0x122f48: 0xadc70050  sw          $a3, 0x50($t6)
    ctx->pc = 0x122f48u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 80), GPR_U32(ctx, 7));
    // 0x122f4c: 0xadc80054  sw          $t0, 0x54($t6)
    ctx->pc = 0x122f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 84), GPR_U32(ctx, 8));
    // 0x122f50: 0xadc90058  sw          $t1, 0x58($t6)
    ctx->pc = 0x122f50u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 88), GPR_U32(ctx, 9));
    // 0x122f54: 0xadcc005c  sw          $t4, 0x5C($t6)
    ctx->pc = 0x122f54u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 92), GPR_U32(ctx, 12));
    // 0x122f58: 0xadcd0060  sw          $t5, 0x60($t6)
    ctx->pc = 0x122f58u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 96), GPR_U32(ctx, 13));
    // 0x122f5c: 0xadcb0064  sw          $t3, 0x64($t6)
    ctx->pc = 0x122f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 100), GPR_U32(ctx, 11));
    // 0x122f60: 0xadc00088  sw          $zero, 0x88($t6)
    ctx->pc = 0x122f60u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 136), GPR_U32(ctx, 0));
    // 0x122f64: 0xa5ca0002  sh          $t2, 0x2($t6)
    ctx->pc = 0x122f64u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 10));
    // 0x122f68: 0xadc90010  sw          $t1, 0x10($t6)
    ctx->pc = 0x122f68u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 16), GPR_U32(ctx, 9));
    // 0x122f6c: 0xadc0008c  sw          $zero, 0x8C($t6)
    ctx->pc = 0x122f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 140), GPR_U32(ctx, 0));
    // 0x122f70: 0xa5c0001c  sh          $zero, 0x1C($t6)
    ctx->pc = 0x122f70u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x122f74: 0xa5c00024  sh          $zero, 0x24($t6)
    ctx->pc = 0x122f74u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x122f78: 0xa5c00026  sh          $zero, 0x26($t6)
    ctx->pc = 0x122f78u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x122f7c: 0xadc00020  sw          $zero, 0x20($t6)
    ctx->pc = 0x122f7cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 32), GPR_U32(ctx, 0));
    // 0x122f80: 0xadc00028  sw          $zero, 0x28($t6)
    ctx->pc = 0x122f80u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 40), GPR_U32(ctx, 0));
    // 0x122f84: 0xadc0002c  sw          $zero, 0x2C($t6)
    ctx->pc = 0x122f84u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 44), GPR_U32(ctx, 0));
    // 0x122f88: 0xadc00030  sw          $zero, 0x30($t6)
    ctx->pc = 0x122f88u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 48), GPR_U32(ctx, 0));
    // 0x122f8c: 0xadc00034  sw          $zero, 0x34($t6)
    ctx->pc = 0x122f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 52), GPR_U32(ctx, 0));
    // 0x122f90: 0xadc20014  sw          $v0, 0x14($t6)
    ctx->pc = 0x122f90u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 20), GPR_U32(ctx, 2));
    // 0x122f94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x122f94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_122f98:
    // 0x122f98: 0x3e00008  jr          $ra
    ctx->pc = 0x122F98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122FA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
