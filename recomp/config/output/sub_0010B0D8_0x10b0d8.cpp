#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010B0D8
// Address: 0x10b0d8 - 0x10b154
void sub_0010B0D8_0x10b0d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010B0D8_0x10b0d8");
#endif

    switch (ctx->pc) {
        case 0x10b0e8u: goto label_10b0e8;
        case 0x10b110u: goto label_10b110;
        default: break;
    }

    ctx->pc = 0x10b0d8u;

    // 0x10b0d8: 0x90880000  lbu         $t0, 0x0($a0)
    ctx->pc = 0x10b0d8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b0dc: 0x100102d  daddu       $v0, $t0, $zero
    ctx->pc = 0x10b0dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b0e0: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x10B0E0u;
    {
        const bool branch_taken_0x10b0e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B0E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B0E0u;
            // 0x10b0e4: 0x80482d  daddu       $t1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b0e0) {
            ctx->pc = 0x10B14Cu;
            goto label_10b14c;
        }
    }
    ctx->pc = 0x10B0E8u;
label_10b0e8:
    // 0x10b0e8: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x10b0e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b0ec: 0x80c30000  lb          $v1, 0x0($a2)
    ctx->pc = 0x10b0ecu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10b0f0: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x10B0F0u;
    {
        const bool branch_taken_0x10b0f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B0F0u;
            // 0x10b0f4: 0x90c70000  lbu         $a3, 0x0($a2) (Delay Slot)
        SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b0f0) {
            ctx->pc = 0x10B13Cu;
            goto label_10b13c;
        }
    }
    ctx->pc = 0x10B0F8u;
    // 0x10b0f8: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x10b0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x10b0fc: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x10b0fcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10b100: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x10B100u;
    {
        const bool branch_taken_0x10b100 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x10B104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B100u;
            // 0x10b104: 0x81600  sll         $v0, $t0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b100) {
            ctx->pc = 0x10B134u;
            goto label_10b134;
        }
    }
    ctx->pc = 0x10B108u;
    // 0x10b108: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x10b108u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10b10c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x10b10cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_10b110:
    // 0x10b110: 0x80c30000  lb          $v1, 0x0($a2)
    ctx->pc = 0x10b110u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10b114: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x10B114u;
    {
        const bool branch_taken_0x10b114 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B114u;
            // 0x10b118: 0x90c70000  lbu         $a3, 0x0($a2) (Delay Slot)
        SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b114) {
            ctx->pc = 0x10B13Cu;
            goto label_10b13c;
        }
    }
    ctx->pc = 0x10B11Cu;
    // 0x10b11c: 0x0  nop
    ctx->pc = 0x10b11cu;
    // NOP
    // 0x10b120: 0x0  nop
    ctx->pc = 0x10b120u;
    // NOP
    // 0x10b124: 0x0  nop
    ctx->pc = 0x10b124u;
    // NOP
    // 0x10b128: 0x0  nop
    ctx->pc = 0x10b128u;
    // NOP
    // 0x10b12c: 0x5443fff8  bnel        $v0, $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10B12Cu;
    {
        const bool branch_taken_0x10b12c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x10b12c) {
            ctx->pc = 0x10B130u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B12Cu;
            // 0x10b130: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B110u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b110;
        }
    }
    ctx->pc = 0x10B134u;
label_10b134:
    // 0x10b134: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x10B134u;
    {
        const bool branch_taken_0x10b134 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b134) {
            ctx->pc = 0x10B14Cu;
            goto label_10b14c;
        }
    }
    ctx->pc = 0x10B13Cu;
label_10b13c:
    // 0x10b13c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10b13cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10b140: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x10b140u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b144: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x10B144u;
    {
        const bool branch_taken_0x10b144 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B144u;
            // 0x10b148: 0x40402d  daddu       $t0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b144) {
            ctx->pc = 0x10B0E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b0e8;
        }
    }
    ctx->pc = 0x10B14Cu;
label_10b14c:
    // 0x10b14c: 0x3e00008  jr          $ra
    ctx->pc = 0x10B14Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B14Cu;
            // 0x10b150: 0x891023  subu        $v0, $a0, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B0E8u: goto label_10b0e8;
            case 0x10B110u: goto label_10b110;
            case 0x10B134u: goto label_10b134;
            case 0x10B13Cu: goto label_10b13c;
            case 0x10B14Cu: goto label_10b14c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B154u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
