#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107AB0
// Address: 0x107ab0 - 0x107b60
void sub_00107AB0_0x107ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107AB0_0x107ab0");
#endif

    switch (ctx->pc) {
        case 0x107ad4u: goto label_107ad4;
        case 0x107b0cu: goto label_107b0c;
        case 0x107b3cu: goto label_107b3c;
        default: break;
    }

    ctx->pc = 0x107ab0u;

    // 0x107ab0: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x107ab0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107ab4: 0x2cc20020  sltiu       $v0, $a2, 0x20
    ctx->pc = 0x107ab4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x107ab8: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x107AB8u;
    {
        const bool branch_taken_0x107ab8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107AB8u;
            // 0x107abc: 0x100182d  daddu       $v1, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107ab8) {
            ctx->pc = 0x107B2Cu;
            goto label_107b2c;
        }
    }
    ctx->pc = 0x107AC0u;
    // 0x107ac0: 0xa81025  or          $v0, $a1, $t0
    ctx->pc = 0x107ac0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 8));
    // 0x107ac4: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x107ac4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x107ac8: 0x54400019  bnel        $v0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x107AC8u;
    {
        const bool branch_taken_0x107ac8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x107ac8) {
            ctx->pc = 0x107ACCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107AC8u;
            // 0x107acc: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107B30u;
            goto label_107b30;
        }
    }
    ctx->pc = 0x107AD0u;
    // 0x107ad0: 0x100382d  daddu       $a3, $t0, $zero
    ctx->pc = 0x107ad0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_107ad4:
    // 0x107ad4: 0x78a30000  lq          $v1, 0x0($a1)
    ctx->pc = 0x107ad4u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x107ad8: 0x24c6ffe0  addiu       $a2, $a2, -0x20
    ctx->pc = 0x107ad8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967264));
    // 0x107adc: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x107adcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x107ae0: 0x2cc40020  sltiu       $a0, $a2, 0x20
    ctx->pc = 0x107ae0u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x107ae4: 0x7ce30000  sq          $v1, 0x0($a3)
    ctx->pc = 0x107ae4u;
    WRITE128(ADD32(GPR_U32(ctx, 7), 0), GPR_VEC(ctx, 3));
    // 0x107ae8: 0x24e70010  addiu       $a3, $a3, 0x10
    ctx->pc = 0x107ae8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x107aec: 0x78a20000  lq          $v0, 0x0($a1)
    ctx->pc = 0x107aecu;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x107af0: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x107af0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x107af4: 0x7ce20000  sq          $v0, 0x0($a3)
    ctx->pc = 0x107af4u;
    WRITE128(ADD32(GPR_U32(ctx, 7), 0), GPR_VEC(ctx, 2));
    // 0x107af8: 0x1080fff6  beqz        $a0, . + 4 + (-0xA << 2)
    ctx->pc = 0x107AF8u;
    {
        const bool branch_taken_0x107af8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x107AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107AF8u;
            // 0x107afc: 0x24e70010  addiu       $a3, $a3, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107af8) {
            ctx->pc = 0x107AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107ad4;
        }
    }
    ctx->pc = 0x107B00u;
    // 0x107b00: 0x2cc20008  sltiu       $v0, $a2, 0x8
    ctx->pc = 0x107b00u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x107b04: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x107B04u;
    {
        const bool branch_taken_0x107b04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107B04u;
            // 0x107b08: 0xe0182d  daddu       $v1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107b04) {
            ctx->pc = 0x107B2Cu;
            goto label_107b2c;
        }
    }
    ctx->pc = 0x107B0Cu;
label_107b0c:
    // 0x107b0c: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x107b0cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x107b10: 0x24c6fff8  addiu       $a2, $a2, -0x8
    ctx->pc = 0x107b10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967288));
    // 0x107b14: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x107b14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x107b18: 0x2cc20008  sltiu       $v0, $a2, 0x8
    ctx->pc = 0x107b18u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x107b1c: 0xfce30000  sd          $v1, 0x0($a3)
    ctx->pc = 0x107b1cu;
    WRITE64(ADD32(GPR_U32(ctx, 7), 0), GPR_U64(ctx, 3));
    // 0x107b20: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x107B20u;
    {
        const bool branch_taken_0x107b20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107B20u;
            // 0x107b24: 0x24e70008  addiu       $a3, $a3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107b20) {
            ctx->pc = 0x107B0Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107b0c;
        }
    }
    ctx->pc = 0x107B28u;
    // 0x107b28: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x107b28u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_107b2c:
    // 0x107b2c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x107b2cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_107b30:
    // 0x107b30: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x107b30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x107b34: 0x10c20008  beq         $a2, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x107B34u;
    {
        const bool branch_taken_0x107b34 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x107B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107B34u;
            // 0x107b38: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107b34) {
            ctx->pc = 0x107B58u;
            goto label_107b58;
        }
    }
    ctx->pc = 0x107B3Cu;
label_107b3c:
    // 0x107b3c: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x107b3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x107b40: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x107b40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x107b44: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x107b44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x107b48: 0xa0620000  sb          $v0, 0x0($v1)
    ctx->pc = 0x107b48u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x107b4c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x107b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x107b50: 0x14c4fffa  bne         $a2, $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x107B50u;
    {
        const bool branch_taken_0x107b50 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        if (branch_taken_0x107b50) {
            ctx->pc = 0x107B3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107b3c;
        }
    }
    ctx->pc = 0x107B58u;
label_107b58:
    // 0x107b58: 0x3e00008  jr          $ra
    ctx->pc = 0x107B58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107B58u;
            // 0x107b5c: 0x100102d  daddu       $v0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107AD4u: goto label_107ad4;
            case 0x107B0Cu: goto label_107b0c;
            case 0x107B2Cu: goto label_107b2c;
            case 0x107B30u: goto label_107b30;
            case 0x107B3Cu: goto label_107b3c;
            case 0x107B58u: goto label_107b58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107B60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
