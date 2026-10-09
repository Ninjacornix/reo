#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8870
// Address: 0x1b8870 - 0x1b8a10
void sub_001B8870_0x1b8870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8870_0x1b8870");
#endif

    switch (ctx->pc) {
        case 0x1b8950u: goto label_1b8950;
        case 0x1b8978u: goto label_1b8978;
        case 0x1b89a0u: goto label_1b89a0;
        case 0x1b89e0u: goto label_1b89e0;
        case 0x1b89fcu: goto label_1b89fc;
        default: break;
    }

    ctx->pc = 0x1b8870u;

label_1b8870:
    // 0x1b8870: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b8870u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b8874: 0x24020029  addiu       $v0, $zero, 0x29
    ctx->pc = 0x1b8874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 41));
    // 0x1b8878: 0x942343da  lhu         $v1, 0x43DA($at)
    ctx->pc = 0x1b8878u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1b887c: 0x10620023  beq         $v1, $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1B887Cu;
    {
        const bool branch_taken_0x1b887c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B8880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B887Cu;
            // 0x1b8880: 0x3c020073  lui         $v0, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)115 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b887c) {
            ctx->pc = 0x1B890Cu;
            goto label_1b890c;
        }
    }
    ctx->pc = 0x1B8884u;
    // 0x1b8884: 0x24020023  addiu       $v0, $zero, 0x23
    ctx->pc = 0x1b8884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x1b8888: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1B8888u;
    {
        const bool branch_taken_0x1b8888 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B888Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8888u;
            // 0x1b888c: 0x3c020073  lui         $v0, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)115 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8888) {
            ctx->pc = 0x1B88F8u;
            goto label_1b88f8;
        }
    }
    ctx->pc = 0x1B8890u;
    // 0x1b8890: 0x2402001c  addiu       $v0, $zero, 0x1C
    ctx->pc = 0x1b8890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x1b8894: 0x10620013  beq         $v1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B8894u;
    {
        const bool branch_taken_0x1b8894 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B8898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8894u;
            // 0x1b8898: 0x3c020073  lui         $v0, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)115 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8894) {
            ctx->pc = 0x1B88E4u;
            goto label_1b88e4;
        }
    }
    ctx->pc = 0x1B889Cu;
    // 0x1b889c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b889cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b88a0: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1B88A0u;
    {
        const bool branch_taken_0x1b88a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B88A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B88A0u;
            // 0x1b88a4: 0x3c020073  lui         $v0, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)115 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b88a0) {
            ctx->pc = 0x1B88D0u;
            goto label_1b88d0;
        }
    }
    ctx->pc = 0x1B88A8u;
    // 0x1b88a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b88a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b88ac: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B88ACu;
    {
        const bool branch_taken_0x1b88ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B88B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B88ACu;
            // 0x1b88b0: 0x3c020073  lui         $v0, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)115 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b88ac) {
            ctx->pc = 0x1B88BCu;
            goto label_1b88bc;
        }
    }
    ctx->pc = 0x1B88B4u;
    // 0x1b88b4: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1B88B4u;
    {
        const bool branch_taken_0x1b88b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B88B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B88B4u;
            // 0x1b88b8: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b88b4) {
            ctx->pc = 0x1B8920u;
            goto label_1b8920;
        }
    }
    ctx->pc = 0x1B88BCu;
label_1b88bc:
    // 0x1b88bc: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1b88bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b88c0: 0x24420ba0  addiu       $v0, $v0, 0xBA0
    ctx->pc = 0x1b88c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2976));
    // 0x1b88c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b88c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b88c8: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1B88C8u;
    {
        const bool branch_taken_0x1b88c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B88CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B88C8u;
            // 0x1b88cc: 0x84440000  lh          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b88c8) {
            ctx->pc = 0x1B891Cu;
            goto label_1b891c;
        }
    }
    ctx->pc = 0x1B88D0u;
label_1b88d0:
    // 0x1b88d0: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1b88d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b88d4: 0x24420d40  addiu       $v0, $v0, 0xD40
    ctx->pc = 0x1b88d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3392));
    // 0x1b88d8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b88d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b88dc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1B88DCu;
    {
        const bool branch_taken_0x1b88dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B88E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B88DCu;
            // 0x1b88e0: 0x84440000  lh          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b88dc) {
            ctx->pc = 0x1B891Cu;
            goto label_1b891c;
        }
    }
    ctx->pc = 0x1B88E4u;
label_1b88e4:
    // 0x1b88e4: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1b88e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b88e8: 0x24420ee0  addiu       $v0, $v0, 0xEE0
    ctx->pc = 0x1b88e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3808));
    // 0x1b88ec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b88ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b88f0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B88F0u;
    {
        const bool branch_taken_0x1b88f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B88F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B88F0u;
            // 0x1b88f4: 0x84440000  lh          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b88f0) {
            ctx->pc = 0x1B891Cu;
            goto label_1b891c;
        }
    }
    ctx->pc = 0x1B88F8u;
label_1b88f8:
    // 0x1b88f8: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1b88f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b88fc: 0x24421080  addiu       $v0, $v0, 0x1080
    ctx->pc = 0x1b88fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4224));
    // 0x1b8900: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8904: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B8904u;
    {
        const bool branch_taken_0x1b8904 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8904u;
            // 0x1b8908: 0x84440000  lh          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8904) {
            ctx->pc = 0x1B891Cu;
            goto label_1b891c;
        }
    }
    ctx->pc = 0x1B890Cu;
label_1b890c:
    // 0x1b890c: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1b890cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b8910: 0x24421220  addiu       $v0, $v0, 0x1220
    ctx->pc = 0x1b8910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4640));
    // 0x1b8914: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8918: 0x84440000  lh          $a0, 0x0($v0)
    ctx->pc = 0x1b8918u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_1b891c:
    // 0x1b891c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1b891cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1b8920:
    // 0x1b8920: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8920u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8870u: goto label_1b8870;
            case 0x1B88BCu: goto label_1b88bc;
            case 0x1B88D0u: goto label_1b88d0;
            case 0x1B88E4u: goto label_1b88e4;
            case 0x1B88F8u: goto label_1b88f8;
            case 0x1B890Cu: goto label_1b890c;
            case 0x1B891Cu: goto label_1b891c;
            case 0x1B8920u: goto label_1b8920;
            case 0x1B8950u: goto label_1b8950;
            case 0x1B8978u: goto label_1b8978;
            case 0x1B8984u: goto label_1b8984;
            case 0x1B89A0u: goto label_1b89a0;
            case 0x1B89A8u: goto label_1b89a8;
            case 0x1B89E0u: goto label_1b89e0;
            case 0x1B89E8u: goto label_1b89e8;
            case 0x1B89FCu: goto label_1b89fc;
            case 0x1B8A00u: goto label_1b8a00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8928u;
    // 0x1b8928: 0x0  nop
    ctx->pc = 0x1b8928u;
    // NOP
    // 0x1b892c: 0x0  nop
    ctx->pc = 0x1b892cu;
    // NOP
    // 0x1b8930: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b8930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b8934: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b8934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b8938: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b8938u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b893c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b893cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b8940: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b8940u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8944: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1b8944u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8948: 0xc06e21c  jal         func_1B8870
    ctx->pc = 0x1B8948u;
    SET_GPR_U32(ctx, 31, 0x1B8950u);
    ctx->pc = 0x1B894Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8948u;
            // 0x1b894c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8870u;
    goto label_1b8870;
    ctx->pc = 0x1B8950u;
label_1b8950:
    // 0x1b8950: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b8950u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8954: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1b8954u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b8958: 0x12030013  beq         $s0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B8958u;
    {
        const bool branch_taken_0x1b8958 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b8958) {
            ctx->pc = 0x1B89A8u;
            goto label_1b89a8;
        }
    }
    ctx->pc = 0x1B8960u;
    // 0x1b8960: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B8960u;
    {
        const bool branch_taken_0x1b8960 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B8964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8960u;
            // 0x1b8964: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8960) {
            ctx->pc = 0x1B8984u;
            goto label_1b8984;
        }
    }
    ctx->pc = 0x1B8968u;
    // 0x1b8968: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b8968u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b896c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b896cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8970: 0xc06e4ec  jal         func_1B93B0
    ctx->pc = 0x1B8970u;
    SET_GPR_U32(ctx, 31, 0x1B8978u);
    ctx->pc = 0x1B8974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8970u;
            // 0x1b8974: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8978u; }
        if (ctx->pc != 0x1B8978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8978u; }
        if (ctx->pc != 0x1B8978u) { return; }
    }
    ctx->pc = 0x1B8978u;
label_1b8978:
    // 0x1b8978: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b8978u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b897c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B897Cu;
    {
        const bool branch_taken_0x1b897c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B897Cu;
            // 0x1b8980: 0xa4306550  sh          $s0, 0x6550($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 25936), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b897c) {
            ctx->pc = 0x1B89A8u;
            goto label_1b89a8;
        }
    }
    ctx->pc = 0x1B8984u;
label_1b8984:
    // 0x1b8984: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b8984u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b8988: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b8988u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b898c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b898cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8990: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8990u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8994: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8994u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8998: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8998u;
    SET_GPR_U32(ctx, 31, 0x1B89A0u);
    ctx->pc = 0x1B899Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8998u;
            // 0x1b899c: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89A0u; }
        if (ctx->pc != 0x1B89A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89A0u; }
        if (ctx->pc != 0x1B89A0u) { return; }
    }
    ctx->pc = 0x1B89A0u;
label_1b89a0:
    // 0x1b89a0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b89a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b89a4: 0xa4306550  sh          $s0, 0x6550($at)
    ctx->pc = 0x1b89a4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 25936), (uint16_t)GPR_U32(ctx, 16));
label_1b89a8:
    // 0x1b89a8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b89a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b89ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b89acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b89b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b89b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b89b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B89B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B89B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89B4u;
            // 0x1b89b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8870u: goto label_1b8870;
            case 0x1B88BCu: goto label_1b88bc;
            case 0x1B88D0u: goto label_1b88d0;
            case 0x1B88E4u: goto label_1b88e4;
            case 0x1B88F8u: goto label_1b88f8;
            case 0x1B890Cu: goto label_1b890c;
            case 0x1B891Cu: goto label_1b891c;
            case 0x1B8920u: goto label_1b8920;
            case 0x1B8950u: goto label_1b8950;
            case 0x1B8978u: goto label_1b8978;
            case 0x1B8984u: goto label_1b8984;
            case 0x1B89A0u: goto label_1b89a0;
            case 0x1B89A8u: goto label_1b89a8;
            case 0x1B89E0u: goto label_1b89e0;
            case 0x1B89E8u: goto label_1b89e8;
            case 0x1B89FCu: goto label_1b89fc;
            case 0x1B8A00u: goto label_1b8a00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B89BCu;
    // 0x1b89bc: 0x0  nop
    ctx->pc = 0x1b89bcu;
    // NOP
    // 0x1b89c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b89c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b89c4: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1b89c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b89c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b89c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b89cc: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B89CCu;
    {
        const bool branch_taken_0x1b89cc = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B89D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89CCu;
            // 0x1b89d0: 0xc0502d  daddu       $t2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b89cc) {
            ctx->pc = 0x1B89E8u;
            goto label_1b89e8;
        }
    }
    ctx->pc = 0x1B89D4u;
    // 0x1b89d4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b89d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b89d8: 0xc06e4ec  jal         func_1B93B0
    ctx->pc = 0x1B89D8u;
    SET_GPR_U32(ctx, 31, 0x1B89E0u);
    ctx->pc = 0x1B89DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89D8u;
            // 0x1b89dc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89E0u; }
        if (ctx->pc != 0x1B89E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89E0u; }
        if (ctx->pc != 0x1B89E0u) { return; }
    }
    ctx->pc = 0x1B89E0u;
label_1b89e0:
    // 0x1b89e0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B89E0u;
    {
        const bool branch_taken_0x1b89e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B89E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89E0u;
            // 0x1b89e4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b89e0) {
            ctx->pc = 0x1B8A00u;
            goto label_1b8a00;
        }
    }
    ctx->pc = 0x1B89E8u;
label_1b89e8:
    // 0x1b89e8: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b89e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b89ec: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b89ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b89f0: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b89f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b89f4: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B89F4u;
    SET_GPR_U32(ctx, 31, 0x1B89FCu);
    ctx->pc = 0x1B89F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89F4u;
            // 0x1b89f8: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89FCu; }
        if (ctx->pc != 0x1B89FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89FCu; }
        if (ctx->pc != 0x1B89FCu) { return; }
    }
    ctx->pc = 0x1B89FCu;
label_1b89fc:
    // 0x1b89fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b89fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1b8a00:
    // 0x1b8a00: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8A00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8A00u;
            // 0x1b8a04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8870u: goto label_1b8870;
            case 0x1B88BCu: goto label_1b88bc;
            case 0x1B88D0u: goto label_1b88d0;
            case 0x1B88E4u: goto label_1b88e4;
            case 0x1B88F8u: goto label_1b88f8;
            case 0x1B890Cu: goto label_1b890c;
            case 0x1B891Cu: goto label_1b891c;
            case 0x1B8920u: goto label_1b8920;
            case 0x1B8950u: goto label_1b8950;
            case 0x1B8978u: goto label_1b8978;
            case 0x1B8984u: goto label_1b8984;
            case 0x1B89A0u: goto label_1b89a0;
            case 0x1B89A8u: goto label_1b89a8;
            case 0x1B89E0u: goto label_1b89e0;
            case 0x1B89E8u: goto label_1b89e8;
            case 0x1B89FCu: goto label_1b89fc;
            case 0x1B8A00u: goto label_1b8a00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8A08u;
    // 0x1b8a08: 0x0  nop
    ctx->pc = 0x1b8a08u;
    // NOP
    // 0x1b8a0c: 0x0  nop
    ctx->pc = 0x1b8a0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
