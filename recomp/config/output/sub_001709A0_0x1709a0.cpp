#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001709A0
// Address: 0x1709a0 - 0x1709f0
void sub_001709A0_0x1709a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001709A0_0x1709a0");
#endif

    ctx->pc = 0x1709a0u;

    // 0x1709a0: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1709a0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1709a4: 0x3c030fff  lui         $v1, 0xFFF
    ctx->pc = 0x1709a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4095 << 16));
    // 0x1709a8: 0x8ce40008  lw          $a0, 0x8($a3)
    ctx->pc = 0x1709a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1709ac: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x1709acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x1709b0: 0x8ce60004  lw          $a2, 0x4($a3)
    ctx->pc = 0x1709b0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1709b4: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1709b4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1709b8: 0x862021  addu        $a0, $a0, $a2
    ctx->pc = 0x1709b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1709bc: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x1709bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x1709c0: 0x832024  and         $a0, $a0, $v1
    ctx->pc = 0x1709c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1709c4: 0x10a40007  beq         $a1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1709C4u;
    {
        const bool branch_taken_0x1709c4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1709C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1709C4u;
            // 0x1709c8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1709c4) {
            ctx->pc = 0x1709E4u;
            goto label_1709e4;
        }
    }
    ctx->pc = 0x1709CCu;
    // 0x1709cc: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x1709ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1709d0: 0xa21023  subu        $v0, $a1, $v0
    ctx->pc = 0x1709d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1709d4: 0x244407ff  addiu       $a0, $v0, 0x7FF
    ctx->pc = 0x1709d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x1709d8: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1709d8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1709dc: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x1709dcu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x1709e0: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x1709e0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
label_1709e4:
    // 0x1709e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1709E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1709E4u: goto label_1709e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1709ECu;
    // 0x1709ec: 0x0  nop
    ctx->pc = 0x1709ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
