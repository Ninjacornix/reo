#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA8A0
// Address: 0x1ba8a0 - 0x1ba920
void sub_001BA8A0_0x1ba8a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA8A0_0x1ba8a0");
#endif

    switch (ctx->pc) {
        case 0x1ba914u: goto label_1ba914;
        default: break;
    }

    ctx->pc = 0x1ba8a0u;

    // 0x1ba8a0: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1ba8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ba8a4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ba8a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ba8a8: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1ba8a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ba8ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ba8acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ba8b0: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1ba8b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1ba8b4: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x1ba8b4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1ba8b8: 0x24630a10  addiu       $v1, $v1, 0xA10
    ctx->pc = 0x1ba8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2576));
    // 0x1ba8bc: 0x644821  addu        $t1, $v1, $a0
    ctx->pc = 0x1ba8bcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ba8c0: 0x8d230010  lw          $v1, 0x10($t1)
    ctx->pc = 0x1ba8c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x1ba8c4: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1BA8C4u;
    {
        const bool branch_taken_0x1ba8c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba8c4) {
            ctx->pc = 0x1BA914u;
            goto label_1ba914;
        }
    }
    ctx->pc = 0x1BA8CCu;
    // 0x1ba8cc: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1ba8ccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1ba8d0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1ba8d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba8d4: 0x1464000f  bne         $v1, $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x1BA8D4u;
    {
        const bool branch_taken_0x1ba8d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1ba8d4) {
            ctx->pc = 0x1BA914u;
            goto label_1ba914;
        }
    }
    ctx->pc = 0x1BA8DCu;
    // 0x1ba8dc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1ba8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ba8e0: 0x27a6001f  addiu       $a2, $sp, 0x1F
    ctx->pc = 0x1ba8e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
    // 0x1ba8e4: 0xa3a2001f  sb          $v0, 0x1F($sp)
    ctx->pc = 0x1ba8e4u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ba8e8: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1ba8e8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba8ec: 0x90a30001  lbu         $v1, 0x1($a1)
    ctx->pc = 0x1ba8ecu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x1ba8f0: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x1ba8f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1ba8f4: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1ba8f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ba8f8: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1ba8f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1ba8fc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1ba8fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba900: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ba900u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ba904: 0xa7a2001c  sh          $v0, 0x1C($sp)
    ctx->pc = 0x1ba904u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 28), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ba908: 0x91240006  lbu         $a0, 0x6($t1)
    ctx->pc = 0x1ba908u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 6)));
    // 0x1ba90c: 0xc062620  jal         func_189880
    ctx->pc = 0x1BA90Cu;
    SET_GPR_U32(ctx, 31, 0x1BA914u);
    ctx->pc = 0x1BA910u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA90Cu;
            // 0x1ba910: 0x27a8001c  addiu       $t0, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189880u;
    if (runtime->hasFunction(0x189880u)) {
        auto targetFn = runtime->lookupFunction(0x189880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA914u; }
        if (ctx->pc != 0x1BA914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189880_0x189880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA914u; }
        if (ctx->pc != 0x1BA914u) { return; }
    }
    ctx->pc = 0x1BA914u;
label_1ba914:
    // 0x1ba914: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ba914u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba918: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA918u;
            // 0x1ba91c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA914u: goto label_1ba914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA920u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
