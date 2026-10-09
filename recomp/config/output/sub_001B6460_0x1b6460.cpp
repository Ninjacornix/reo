#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6460
// Address: 0x1b6460 - 0x1b64f0
void sub_001B6460_0x1b6460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6460_0x1b6460");
#endif

    ctx->pc = 0x1b6460u;

    // 0x1b6460: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x1b6460u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1b6464: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x1b6464u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1b6468: 0x28c100a0  slti        $at, $a2, 0xA0
    ctx->pc = 0x1b6468u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b646c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B646Cu;
    {
        const bool branch_taken_0x1b646c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B646Cu;
            // 0x1b6470: 0x308500ff  andi        $a1, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b646c) {
            ctx->pc = 0x1B647Cu;
            goto label_1b647c;
        }
    }
    ctx->pc = 0x1B6474u;
    // 0x1b6474: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B6474u;
    {
        const bool branch_taken_0x1b6474 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6474u;
            // 0x1b6478: 0x24020071  addiu       $v0, $zero, 0x71 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6474) {
            ctx->pc = 0x1B6480u;
            goto label_1b6480;
        }
    }
    ctx->pc = 0x1B647Cu;
label_1b647c:
    // 0x1b647c: 0x240200b1  addiu       $v0, $zero, 0xB1
    ctx->pc = 0x1b647cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 177));
label_1b6480:
    // 0x1b6480: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b6480u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b6484: 0xc31823  subu        $v1, $a2, $v1
    ctx->pc = 0x1b6484u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b6488: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x1b6488u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1b648c: 0x3066ffff  andi        $a2, $v1, 0xFFFF
    ctx->pc = 0x1b648cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1b6490: 0x28410080  slti        $at, $v0, 0x80
    ctx->pc = 0x1b6490u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b6494: 0x61840  sll         $v1, $a2, 1
    ctx->pc = 0x1b6494u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1b6498: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b6498u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b649c: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B649Cu;
    {
        const bool branch_taken_0x1b649c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B64A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B649Cu;
            // 0x1b64a0: 0x3064ffff  andi        $a0, $v1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b649c) {
            ctx->pc = 0x1B64ACu;
            goto label_1b64ac;
        }
    }
    ctx->pc = 0x1B64A4u;
    // 0x1b64a4: 0x24a2ffff  addiu       $v0, $a1, -0x1
    ctx->pc = 0x1b64a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1b64a8: 0x3045ffff  andi        $a1, $v0, 0xFFFF
    ctx->pc = 0x1b64a8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1b64ac:
    // 0x1b64ac: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x1b64acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1b64b0: 0x2842009e  slti        $v0, $v0, 0x9E
    ctx->pc = 0x1b64b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)158) ? 1 : 0);
    // 0x1b64b4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B64B4u;
    {
        const bool branch_taken_0x1b64b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B64B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B64B4u;
            // 0x1b64b8: 0x24a2ffe1  addiu       $v0, $a1, -0x1F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967265));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b64b4) {
            ctx->pc = 0x1B64D0u;
            goto label_1b64d0;
        }
    }
    ctx->pc = 0x1B64BCu;
    // 0x1b64bc: 0x24a3ff83  addiu       $v1, $a1, -0x7D
    ctx->pc = 0x1b64bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967171));
    // 0x1b64c0: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1b64c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b64c4: 0x3065ffff  andi        $a1, $v1, 0xFFFF
    ctx->pc = 0x1b64c4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1b64c8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B64C8u;
    {
        const bool branch_taken_0x1b64c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B64CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B64C8u;
            // 0x1b64cc: 0x3044ffff  andi        $a0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b64c8) {
            ctx->pc = 0x1B64D4u;
            goto label_1b64d4;
        }
    }
    ctx->pc = 0x1B64D0u;
label_1b64d0:
    // 0x1b64d0: 0x3045ffff  andi        $a1, $v0, 0xFFFF
    ctx->pc = 0x1b64d0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1b64d4:
    // 0x1b64d4: 0x3083ffff  andi        $v1, $a0, 0xFFFF
    ctx->pc = 0x1b64d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1b64d8: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x1b64d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1b64dc: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1b64dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1b64e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B64E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B64E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B64E0u;
            // 0x1b64e4: 0x621025  or          $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B647Cu: goto label_1b647c;
            case 0x1B6480u: goto label_1b6480;
            case 0x1B64ACu: goto label_1b64ac;
            case 0x1B64D0u: goto label_1b64d0;
            case 0x1B64D4u: goto label_1b64d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B64E8u;
    // 0x1b64e8: 0x0  nop
    ctx->pc = 0x1b64e8u;
    // NOP
    // 0x1b64ec: 0x0  nop
    ctx->pc = 0x1b64ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
