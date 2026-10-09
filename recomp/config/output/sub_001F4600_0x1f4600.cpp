#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4600
// Address: 0x1f4600 - 0x1f47e0
void sub_001F4600_0x1f4600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4600_0x1f4600");
#endif

    switch (ctx->pc) {
        case 0x1f4620u: goto label_1f4620;
        case 0x1f4674u: goto label_1f4674;
        case 0x1f4758u: goto label_1f4758;
        default: break;
    }

    ctx->pc = 0x1f4600u;

    // 0x1f4600: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f4600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f4604: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1f4604u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1f4608: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f4608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f460c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f460cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f4610: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f4610u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4614: 0x8c840010  lw          $a0, 0x10($a0)
    ctx->pc = 0x1f4614u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1f4618: 0xc075a4c  jal         func_1D6930
    ctx->pc = 0x1F4618u;
    SET_GPR_U32(ctx, 31, 0x1F4620u);
    ctx->pc = 0x1F461Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4618u;
            // 0x1f461c: 0x24a5b6b4  addiu       $a1, $a1, -0x494C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294948532));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6930u;
    if (runtime->hasFunction(0x1D6930u)) {
        auto targetFn = runtime->lookupFunction(0x1D6930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4620u; }
        if (ctx->pc != 0x1F4620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6930_0x1d6930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4620u; }
        if (ctx->pc != 0x1F4620u) { return; }
    }
    ctx->pc = 0x1F4620u;
label_1f4620:
    // 0x1f4620: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4620u;
    {
        const bool branch_taken_0x1f4620 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F4624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4620u;
            // 0x1f4624: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4620) {
            ctx->pc = 0x1F4630u;
            goto label_1f4630;
        }
    }
    ctx->pc = 0x1F4628u;
    // 0x1f4628: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1F4628u;
    {
        const bool branch_taken_0x1f4628 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F462Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4628u;
            // 0x1f462c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4628) {
            ctx->pc = 0x1F47CCu;
            goto label_1f47cc;
        }
    }
    ctx->pc = 0x1F4630u;
label_1f4630:
    // 0x1f4630: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1f4630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f4634: 0x8423b6b4  lh          $v1, -0x494C($at)
    ctx->pc = 0x1f4634u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948532)));
    // 0x1f4638: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4638u;
    {
        const bool branch_taken_0x1f4638 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F463Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4638u;
            // 0x1f463c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4638) {
            ctx->pc = 0x1F4648u;
            goto label_1f4648;
        }
    }
    ctx->pc = 0x1F4640u;
    // 0x1f4640: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1F4640u;
    {
        const bool branch_taken_0x1f4640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4640u;
            // 0x1f4644: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4640) {
            ctx->pc = 0x1F47D0u;
            goto label_1f47d0;
        }
    }
    ctx->pc = 0x1F4648u;
label_1f4648:
    // 0x1f4648: 0x92020030  lbu         $v0, 0x30($s0)
    ctx->pc = 0x1f4648u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1f464c: 0x14400024  bnez        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1F464Cu;
    {
        const bool branch_taken_0x1f464c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F464Cu;
            // 0x1f4650: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f464c) {
            ctx->pc = 0x1F46E0u;
            goto label_1f46e0;
        }
    }
    ctx->pc = 0x1F4654u;
    // 0x1f4654: 0x9422b6ba  lhu         $v0, -0x4946($at)
    ctx->pc = 0x1f4654u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948538)));
    // 0x1f4658: 0x2c420008  sltiu       $v0, $v0, 0x8
    ctx->pc = 0x1f4658u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x1f465c: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1F465Cu;
    {
        const bool branch_taken_0x1f465c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f465c) {
            ctx->pc = 0x1F46E0u;
            goto label_1f46e0;
        }
    }
    ctx->pc = 0x1F4664u;
    // 0x1f4664: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f4664u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f4668: 0x8e050024  lw          $a1, 0x24($s0)
    ctx->pc = 0x1f4668u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1f466c: 0xc075a98  jal         func_1D6A60
    ctx->pc = 0x1F466Cu;
    SET_GPR_U32(ctx, 31, 0x1F4674u);
    ctx->pc = 0x1F4670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F466Cu;
            // 0x1f4670: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A60u;
    if (runtime->hasFunction(0x1D6A60u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4674u; }
        if (ctx->pc != 0x1F4674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A60_0x1d6a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4674u; }
        if (ctx->pc != 0x1F4674u) { return; }
    }
    ctx->pc = 0x1F4674u;
label_1f4674:
    // 0x1f4674: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1f4674u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f4678: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4678u;
    {
        const bool branch_taken_0x1f4678 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f4678) {
            ctx->pc = 0x1F4688u;
            goto label_1f4688;
        }
    }
    ctx->pc = 0x1F4680u;
    // 0x1f4680: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x1F4680u;
    {
        const bool branch_taken_0x1f4680 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4680u;
            // 0x1f4684: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4680) {
            ctx->pc = 0x1F47CCu;
            goto label_1f47cc;
        }
    }
    ctx->pc = 0x1F4688u;
label_1f4688:
    // 0x1f4688: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x1f4688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1f468c: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1f468cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f4690: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1f4690u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1f4694: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1f4694u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1f4698: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x1f4698u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x1f469c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f469cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f46a0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f46a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f46a4: 0xa6020036  sh          $v0, 0x36($s0)
    ctx->pc = 0x1f46a4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 54), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f46a8: 0x96020036  lhu         $v0, 0x36($s0)
    ctx->pc = 0x1f46a8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 54)));
    // 0x1f46ac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F46ACu;
    {
        const bool branch_taken_0x1f46ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F46B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F46ACu;
            // 0x1f46b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f46ac) {
            ctx->pc = 0x1F46BCu;
            goto label_1f46bc;
        }
    }
    ctx->pc = 0x1F46B4u;
    // 0x1f46b4: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x1F46B4u;
    {
        const bool branch_taken_0x1f46b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F46B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F46B4u;
            // 0x1f46b8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f46b4) {
            ctx->pc = 0x1F47CCu;
            goto label_1f47cc;
        }
    }
    ctx->pc = 0x1F46BCu;
label_1f46bc:
    // 0x1f46bc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f46bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f46c0: 0xa2020030  sb          $v0, 0x30($s0)
    ctx->pc = 0x1f46c0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 48), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f46c4: 0xa6000032  sh          $zero, 0x32($s0)
    ctx->pc = 0x1f46c4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 50), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f46c8: 0xa6000034  sh          $zero, 0x34($s0)
    ctx->pc = 0x1f46c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 52), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f46cc: 0xa2020038  sb          $v0, 0x38($s0)
    ctx->pc = 0x1f46ccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 56), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f46d0: 0x9422b6ba  lhu         $v0, -0x4946($at)
    ctx->pc = 0x1f46d0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948538)));
    // 0x1f46d4: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x1f46d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
    // 0x1f46d8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f46d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f46dc: 0xa422b6ba  sh          $v0, -0x4946($at)
    ctx->pc = 0x1f46dcu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294948538), (uint16_t)GPR_U32(ctx, 2));
label_1f46e0:
    // 0x1f46e0: 0x92020030  lbu         $v0, 0x30($s0)
    ctx->pc = 0x1f46e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1f46e4: 0x10400039  beqz        $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x1F46E4u;
    {
        const bool branch_taken_0x1f46e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F46E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F46E4u;
            // 0x1f46e8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f46e4) {
            ctx->pc = 0x1F47CCu;
            goto label_1f47cc;
        }
    }
    ctx->pc = 0x1F46ECu;
    // 0x1f46ec: 0x92020038  lbu         $v0, 0x38($s0)
    ctx->pc = 0x1f46ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1f46f0: 0x28410002  slti        $at, $v0, 0x2
    ctx->pc = 0x1f46f0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1f46f4: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F46F4u;
    {
        const bool branch_taken_0x1f46f4 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F46F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F46F4u;
            // 0x1f46f8: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f46f4) {
            ctx->pc = 0x1F4700u;
            goto label_1f4700;
        }
    }
    ctx->pc = 0x1F46FCu;
    // 0x1f46fc: 0xa6000032  sh          $zero, 0x32($s0)
    ctx->pc = 0x1f46fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 50), (uint16_t)GPR_U32(ctx, 0));
label_1f4700:
    // 0x1f4700: 0x96040032  lhu         $a0, 0x32($s0)
    ctx->pc = 0x1f4700u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 50)));
    // 0x1f4704: 0x96030036  lhu         $v1, 0x36($s0)
    ctx->pc = 0x1f4704u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 54)));
    // 0x1f4708: 0x9422b6ba  lhu         $v0, -0x4946($at)
    ctx->pc = 0x1f4708u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948538)));
    // 0x1f470c: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1f470cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1f4710: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1f4710u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1f4714: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F4714u;
    {
        const bool branch_taken_0x1f4714 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f4714) {
            ctx->pc = 0x1F4720u;
            goto label_1f4720;
        }
    }
    ctx->pc = 0x1F471Cu;
    // 0x1f471c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f471cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1f4720:
    // 0x1f4720: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x1f4720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1f4724: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1f4724u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1f4728: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1f4728u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1f472c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F472Cu;
    {
        const bool branch_taken_0x1f472c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F472Cu;
            // 0x1f4730: 0x3082a  slt         $at, $zero, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f472c) {
            ctx->pc = 0x1F473Cu;
            goto label_1f473c;
        }
    }
    ctx->pc = 0x1F4734u;
    // 0x1f4734: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f4734u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4738: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1f4738u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
label_1f473c:
    // 0x1f473c: 0x10200022  beqz        $at, . + 4 + (0x22 << 2)
    ctx->pc = 0x1F473Cu;
    {
        const bool branch_taken_0x1f473c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f473c) {
            ctx->pc = 0x1F47C8u;
            goto label_1f47c8;
        }
    }
    ctx->pc = 0x1F4744u;
    // 0x1f4744: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f4744u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f4748: 0x3343c  dsll32      $a2, $v1, 16
    ctx->pc = 0x1f4748u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1f474c: 0x8e050028  lw          $a1, 0x28($s0)
    ctx->pc = 0x1f474cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1f4750: 0xc075a98  jal         func_1D6A60
    ctx->pc = 0x1F4750u;
    SET_GPR_U32(ctx, 31, 0x1F4758u);
    ctx->pc = 0x1F4754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4750u;
            // 0x1f4754: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A60u;
    if (runtime->hasFunction(0x1D6A60u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4758u; }
        if (ctx->pc != 0x1F4758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A60_0x1d6a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4758u; }
        if (ctx->pc != 0x1F4758u) { return; }
    }
    ctx->pc = 0x1F4758u;
label_1f4758:
    // 0x1f4758: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4758u;
    {
        const bool branch_taken_0x1f4758 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F475Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4758u;
            // 0x1f475c: 0x3043ffff  andi        $v1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4758) {
            ctx->pc = 0x1F4768u;
            goto label_1f4768;
        }
    }
    ctx->pc = 0x1F4760u;
    // 0x1f4760: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1F4760u;
    {
        const bool branch_taken_0x1f4760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4760u;
            // 0x1f4764: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4760) {
            ctx->pc = 0x1F47CCu;
            goto label_1f47cc;
        }
    }
    ctx->pc = 0x1F4768u;
label_1f4768:
    // 0x1f4768: 0x96020032  lhu         $v0, 0x32($s0)
    ctx->pc = 0x1f4768u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 50)));
    // 0x1f476c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1f476cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f4770: 0xa6020032  sh          $v0, 0x32($s0)
    ctx->pc = 0x1f4770u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 50), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f4774: 0x96020032  lhu         $v0, 0x32($s0)
    ctx->pc = 0x1f4774u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 50)));
    // 0x1f4778: 0x96030036  lhu         $v1, 0x36($s0)
    ctx->pc = 0x1f4778u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 54)));
    // 0x1f477c: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1F477Cu;
    {
        const bool branch_taken_0x1f477c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f477c) {
            ctx->pc = 0x1F4798u;
            goto label_1f4798;
        }
    }
    ctx->pc = 0x1F4784u;
    // 0x1f4784: 0xa6000036  sh          $zero, 0x36($s0)
    ctx->pc = 0x1f4784u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 54), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f4788: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f4788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f478c: 0xa6000034  sh          $zero, 0x34($s0)
    ctx->pc = 0x1f478cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 52), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f4790: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1F4790u;
    {
        const bool branch_taken_0x1f4790 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4790u;
            // 0x1f4794: 0xa2000030  sb          $zero, 0x30($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 48), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4790) {
            ctx->pc = 0x1F47CCu;
            goto label_1f47cc;
        }
    }
    ctx->pc = 0x1F4798u;
label_1f4798:
    // 0x1f4798: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x1f4798u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1f479c: 0x1444000a  bne         $v0, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1F479Cu;
    {
        const bool branch_taken_0x1f479c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x1f479c) {
            ctx->pc = 0x1F47C8u;
            goto label_1f47c8;
        }
    }
    ctx->pc = 0x1F47A4u;
    // 0x1f47a4: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1f47a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1f47a8: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1f47a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f47ac: 0xa6020036  sh          $v0, 0x36($s0)
    ctx->pc = 0x1f47acu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 54), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f47b0: 0xa6000034  sh          $zero, 0x34($s0)
    ctx->pc = 0x1f47b0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 52), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f47b4: 0x92020038  lbu         $v0, 0x38($s0)
    ctx->pc = 0x1f47b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1f47b8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f47b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f47bc: 0xa2020038  sb          $v0, 0x38($s0)
    ctx->pc = 0x1f47bcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 56), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f47c0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F47C0u;
    {
        const bool branch_taken_0x1f47c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F47C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F47C0u;
            // 0x1f47c4: 0x304200ff  andi        $v0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f47c0) {
            ctx->pc = 0x1F47CCu;
            goto label_1f47cc;
        }
    }
    ctx->pc = 0x1F47C8u;
label_1f47c8:
    // 0x1f47c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f47c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f47cc:
    // 0x1f47cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f47ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f47d0:
    // 0x1f47d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f47d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f47d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F47D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F47D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F47D4u;
            // 0x1f47d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4620u: goto label_1f4620;
            case 0x1F4630u: goto label_1f4630;
            case 0x1F4648u: goto label_1f4648;
            case 0x1F4674u: goto label_1f4674;
            case 0x1F4688u: goto label_1f4688;
            case 0x1F46BCu: goto label_1f46bc;
            case 0x1F46E0u: goto label_1f46e0;
            case 0x1F4700u: goto label_1f4700;
            case 0x1F4720u: goto label_1f4720;
            case 0x1F473Cu: goto label_1f473c;
            case 0x1F4758u: goto label_1f4758;
            case 0x1F4768u: goto label_1f4768;
            case 0x1F4798u: goto label_1f4798;
            case 0x1F47C8u: goto label_1f47c8;
            case 0x1F47CCu: goto label_1f47cc;
            case 0x1F47D0u: goto label_1f47d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F47DCu;
    // 0x1f47dc: 0x0  nop
    ctx->pc = 0x1f47dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
