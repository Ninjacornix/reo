#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146140
// Address: 0x146140 - 0x146200
void sub_00146140_0x146140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146140_0x146140");
#endif

    switch (ctx->pc) {
        case 0x146158u: goto label_146158;
        case 0x146160u: goto label_146160;
        case 0x14616cu: goto label_14616c;
        default: break;
    }

    ctx->pc = 0x146140u;

    // 0x146140: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x146140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x146144: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x146148: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x146148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x14614c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x14614Cu;
    {
        const bool branch_taken_0x14614c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14614Cu;
            // 0x146150: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14614c) {
            ctx->pc = 0x146160u;
            goto label_146160;
        }
    }
    ctx->pc = 0x146154u;
    // 0x146154: 0x0  nop
    ctx->pc = 0x146154u;
    // NOP
label_146158:
    // 0x146158: 0xc051636  jal         func_1458D8
    ctx->pc = 0x146158u;
    SET_GPR_U32(ctx, 31, 0x146160u);
    ctx->pc = 0x1458D8u;
    if (runtime->hasFunction(0x1458D8u)) {
        auto targetFn = runtime->lookupFunction(0x1458D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146160u; }
        if (ctx->pc != 0x146160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146160u; }
        if (ctx->pc != 0x146160u) { return; }
    }
    ctx->pc = 0x146160u;
label_146160:
    // 0x146160: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146160u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146164: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146164u;
    SET_GPR_U32(ctx, 31, 0x14616Cu);
    ctx->pc = 0x146168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146164u;
            // 0x146168: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14616Cu; }
        if (ctx->pc != 0x14616Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14616Cu; }
        if (ctx->pc != 0x14616Cu) { return; }
    }
    ctx->pc = 0x14616Cu;
label_14616c:
    // 0x14616c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14616cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146170: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x146170u;
    {
        const bool branch_taken_0x146170 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x146174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146170u;
            // 0x146174: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146170) {
            ctx->pc = 0x146158u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_146158;
        }
    }
    ctx->pc = 0x146178u;
    // 0x146178: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x146178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14617c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14617cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146180: 0x3e00008  jr          $ra
    ctx->pc = 0x146180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146180u;
            // 0x146184: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146158u: goto label_146158;
            case 0x146160u: goto label_146160;
            case 0x14616Cu: goto label_14616c;
            case 0x1461BCu: goto label_1461bc;
            case 0x1461C0u: goto label_1461c0;
            case 0x1461C4u: goto label_1461c4;
            case 0x1461E4u: goto label_1461e4;
            case 0x1461E8u: goto label_1461e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146188u;
    // 0x146188: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x146188u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14618c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x14618cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146190: 0x8cc30168  lw          $v1, 0x168($a2)
    ctx->pc = 0x146190u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 360)));
    // 0x146194: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x146194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x146198: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x146198u;
    {
        const bool branch_taken_0x146198 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x14619Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146198u;
            // 0x14619c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146198) {
            ctx->pc = 0x1461C0u;
            goto label_1461c0;
        }
    }
    ctx->pc = 0x1461A0u;
    // 0x1461a0: 0x50a00008  beql        $a1, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x1461A0u;
    {
        const bool branch_taken_0x1461a0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1461a0) {
            ctx->pc = 0x1461A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1461A0u;
            // 0x1461a4: 0x8cc20864  lw          $v0, 0x864($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 2148)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1461C4u;
            goto label_1461c4;
        }
    }
    ctx->pc = 0x1461A8u;
    // 0x1461a8: 0x4a30004  bgezl       $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1461A8u;
    {
        const bool branch_taken_0x1461a8 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1461a8) {
            ctx->pc = 0x1461ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1461A8u;
            // 0x1461ac: 0xacc0086c  sw          $zero, 0x86C($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 2156), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1461BCu;
            goto label_1461bc;
        }
    }
    ctx->pc = 0x1461B0u;
    // 0x1461b0: 0x8cc2086c  lw          $v0, 0x86C($a2)
    ctx->pc = 0x1461b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 2156)));
    // 0x1461b4: 0x2c470001  sltiu       $a3, $v0, 0x1
    ctx->pc = 0x1461b4u;
    SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1461b8: 0xacc0086c  sw          $zero, 0x86C($a2)
    ctx->pc = 0x1461b8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 2156), GPR_U32(ctx, 0));
label_1461bc:
    // 0x1461bc: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1461bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1461c0:
    // 0x1461c0: 0x8cc20864  lw          $v0, 0x864($a2)
    ctx->pc = 0x1461c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 2148)));
label_1461c4:
    // 0x1461c4: 0x451821  addu        $v1, $v0, $a1
    ctx->pc = 0x1461c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1461c8: 0x10e00006  beqz        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1461C8u;
    {
        const bool branch_taken_0x1461c8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x1461CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1461C8u;
            // 0x1461cc: 0xacc301c4  sw          $v1, 0x1C4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 452), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1461c8) {
            ctx->pc = 0x1461E4u;
            goto label_1461e4;
        }
    }
    ctx->pc = 0x1461D0u;
    // 0x1461d0: 0x85102a  slt         $v0, $a0, $a1
    ctx->pc = 0x1461d0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1461d4: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1461D4u;
    {
        const bool branch_taken_0x1461d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1461d4) {
            ctx->pc = 0x1461D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1461D4u;
            // 0x1461d8: 0x8cc20868  lw          $v0, 0x868($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 2152)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1461E8u;
            goto label_1461e8;
        }
    }
    ctx->pc = 0x1461DCu;
    // 0x1461dc: 0x24620400  addiu       $v0, $v1, 0x400
    ctx->pc = 0x1461dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1024));
    // 0x1461e0: 0xacc201c4  sw          $v0, 0x1C4($a2)
    ctx->pc = 0x1461e0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 452), GPR_U32(ctx, 2));
label_1461e4:
    // 0x1461e4: 0x8cc20868  lw          $v0, 0x868($a2)
    ctx->pc = 0x1461e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 2152)));
label_1461e8:
    // 0x1461e8: 0x8cc401c4  lw          $a0, 0x1C4($a2)
    ctx->pc = 0x1461e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 452)));
    // 0x1461ec: 0x44182a  slt         $v1, $v0, $a0
    ctx->pc = 0x1461ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1461f0: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x1461f0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x1461f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1461F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1461F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1461F4u;
            // 0x1461f8: 0xacc20868  sw          $v0, 0x868($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 2152), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146158u: goto label_146158;
            case 0x146160u: goto label_146160;
            case 0x14616Cu: goto label_14616c;
            case 0x1461BCu: goto label_1461bc;
            case 0x1461C0u: goto label_1461c0;
            case 0x1461C4u: goto label_1461c4;
            case 0x1461E4u: goto label_1461e4;
            case 0x1461E8u: goto label_1461e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1461FCu;
    // 0x1461fc: 0x0  nop
    ctx->pc = 0x1461fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
