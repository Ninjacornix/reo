#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0420
// Address: 0x1b0420 - 0x1b050c
void sub_001B0420_0x1b0420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0420_0x1b0420");
#endif

    switch (ctx->pc) {
        case 0x1b0434u: goto label_1b0434;
        case 0x1b0448u: goto label_1b0448;
        case 0x1b0480u: goto label_1b0480;
        case 0x1b04e0u: goto label_1b04e0;
        default: break;
    }

    ctx->pc = 0x1b0420u;

    // 0x1b0420: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b0420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b0424: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b0424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b0428: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b0428u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b042c: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1B042Cu;
    SET_GPR_U32(ctx, 31, 0x1B0434u);
    ctx->pc = 0x1B0430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B042Cu;
            // 0x1b0430: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0434u; }
        if (ctx->pc != 0x1B0434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0434u; }
        if (ctx->pc != 0x1B0434u) { return; }
    }
    ctx->pc = 0x1B0434u;
label_1b0434:
    // 0x1b0434: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0434u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0438: 0x1443001a  bne         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B0438u;
    {
        const bool branch_taken_0x1b0438 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B043Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0438u;
            // 0x1b043c: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0438) {
            ctx->pc = 0x1B04A4u;
            goto label_1b04a4;
        }
    }
    ctx->pc = 0x1B0440u;
    // 0x1b0440: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B0440u;
    {
        const bool branch_taken_0x1b0440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0440u;
            // 0x1b0444: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0440) {
            ctx->pc = 0x1B0488u;
            goto label_1b0488;
        }
    }
    ctx->pc = 0x1B0448u;
label_1b0448:
    // 0x1b0448: 0x2463eef0  addiu       $v1, $v1, -0x1110
    ctx->pc = 0x1b0448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294962928));
    // 0x1b044c: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1b044cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b0450: 0x24706d35  addiu       $s0, $v1, 0x6D35
    ctx->pc = 0x1b0450u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 27957));
    // 0x1b0454: 0x90636d35  lbu         $v1, 0x6D35($v1)
    ctx->pc = 0x1b0454u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 27957)));
    // 0x1b0458: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B0458u;
    {
        const bool branch_taken_0x1b0458 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B045Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0458u;
            // 0x1b045c: 0x111900  sll         $v1, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0458) {
            ctx->pc = 0x1B0484u;
            goto label_1b0484;
        }
    }
    ctx->pc = 0x1B0460u;
    // 0x1b0460: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1b0460u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1b0464: 0x712023  subu        $a0, $v1, $s1
    ctx->pc = 0x1b0464u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b0468: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1b0468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1b046c: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x1b046cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b0470: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b0470u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b0474: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1b0474u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1b0478: 0xc15c1d4  jal         func_570750
    ctx->pc = 0x1B0478u;
    SET_GPR_U32(ctx, 31, 0x1B0480u);
    ctx->pc = 0x1B047Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0478u;
            // 0x1b047c: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x570750u;
    {
        auto targetFn = runtime->lookupFunction(0x570750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0480u; }
        if (ctx->pc != 0x1B0480u) { return; }
    }
    ctx->pc = 0x1B0480u;
label_1b0480:
    // 0x1b0480: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1b0480u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1b0484:
    // 0x1b0484: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b0484u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b0488:
    // 0x1b0488: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b0488u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b048c: 0x8c23aea0  lw          $v1, -0x5160($at)
    ctx->pc = 0x1b048cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294946464)));
    // 0x1b0490: 0x223182b  sltu        $v1, $s1, $v1
    ctx->pc = 0x1b0490u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b0494: 0x1460ffec  bnez        $v1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1B0494u;
    {
        const bool branch_taken_0x1b0494 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B0498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0494u;
            // 0x1b0498: 0x3c03004a  lui         $v1, 0x4A (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0494) {
            ctx->pc = 0x1B0448u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0448;
        }
    }
    ctx->pc = 0x1B049Cu;
    // 0x1b049c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1B049Cu;
    {
        const bool branch_taken_0x1b049c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B04A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B049Cu;
            // 0x1b04a0: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b049c) {
            ctx->pc = 0x1B04FCu;
            goto label_1b04fc;
        }
    }
    ctx->pc = 0x1B04A4u;
label_1b04a4:
    // 0x1b04a4: 0x3c03004a  lui         $v1, 0x4A
    ctx->pc = 0x1b04a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
    // 0x1b04a8: 0x9024aded  lbu         $a0, -0x5213($at)
    ctx->pc = 0x1b04a8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b04ac: 0x24635c25  addiu       $v1, $v1, 0x5C25
    ctx->pc = 0x1b04acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23589));
    // 0x1b04b0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b04b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b04b4: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1b04b4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b04b8: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1B04B8u;
    {
        const bool branch_taken_0x1b04b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B04BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B04B8u;
            // 0x1b04bc: 0x41900  sll         $v1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b04b8) {
            ctx->pc = 0x1B04F8u;
            goto label_1b04f8;
        }
    }
    ctx->pc = 0x1B04C0u;
    // 0x1b04c0: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1b04c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1b04c4: 0x642023  subu        $a0, $v1, $a0
    ctx->pc = 0x1b04c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b04c8: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1b04c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1b04cc: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x1b04ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b04d0: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b04d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b04d4: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1b04d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1b04d8: 0xc15c1d4  jal         func_570750
    ctx->pc = 0x1B04D8u;
    SET_GPR_U32(ctx, 31, 0x1B04E0u);
    ctx->pc = 0x1B04DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B04D8u;
            // 0x1b04dc: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x570750u;
    {
        auto targetFn = runtime->lookupFunction(0x570750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B04E0u; }
        if (ctx->pc != 0x1B04E0u) { return; }
    }
    ctx->pc = 0x1B04E0u;
label_1b04e0:
    // 0x1b04e0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b04e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b04e4: 0x3c03004a  lui         $v1, 0x4A
    ctx->pc = 0x1b04e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
    // 0x1b04e8: 0x9024aded  lbu         $a0, -0x5213($at)
    ctx->pc = 0x1b04e8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b04ec: 0x24635c25  addiu       $v1, $v1, 0x5C25
    ctx->pc = 0x1b04ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23589));
    // 0x1b04f0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b04f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b04f4: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1b04f4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_1b04f8:
    // 0x1b04f8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b04f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1b04fc:
    // 0x1b04fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b04fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0500: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0500u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0504: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0504u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0504u;
            // 0x1b0508: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0434u: goto label_1b0434;
            case 0x1B0448u: goto label_1b0448;
            case 0x1B0480u: goto label_1b0480;
            case 0x1B0484u: goto label_1b0484;
            case 0x1B0488u: goto label_1b0488;
            case 0x1B04A4u: goto label_1b04a4;
            case 0x1B04E0u: goto label_1b04e0;
            case 0x1B04F8u: goto label_1b04f8;
            case 0x1B04FCu: goto label_1b04fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B050Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
