#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A4B8
// Address: 0x16a4b8 - 0x16a598
void sub_0016A4B8_0x16a4b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A4B8_0x16a4b8");
#endif

    switch (ctx->pc) {
        case 0x16a508u: goto label_16a508;
        case 0x16a520u: goto label_16a520;
        case 0x16a52cu: goto label_16a52c;
        case 0x16a564u: goto label_16a564;
        default: break;
    }

    ctx->pc = 0x16a4b8u;

    // 0x16a4b8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16a4b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16a4bc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16a4bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16a4c0: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x16a4c0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a4c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16a4c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a4c8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x16a4c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a4cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16a4ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16a4d0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16a4d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x16a4d4: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x16a4d4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a4d8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16a4d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16a4dc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16a4dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16a4e0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16a4e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x16a4e4: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x16a4e4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x16a4e8: 0x8eb20028  lw          $s2, 0x28($s5)
    ctx->pc = 0x16a4e8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x16a4ec: 0x26420003  addiu       $v0, $s2, 0x3
    ctx->pc = 0x16a4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 3));
    // 0x16a4f0: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x16a4f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16a4f4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A4F4u;
    {
        const bool branch_taken_0x16a4f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A4F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A4F4u;
            // 0x16a4f8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a4f4) {
            ctx->pc = 0x16A510u;
            goto label_16a510;
        }
    }
    ctx->pc = 0x16A4FCu;
    // 0x16a4fc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16a4fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a500: 0xc05a966  jal         func_16A598
    ctx->pc = 0x16A500u;
    SET_GPR_U32(ctx, 31, 0x16A508u);
    ctx->pc = 0x16A504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A500u;
            // 0x16a504: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A598u;
    if (runtime->hasFunction(0x16A598u)) {
        auto targetFn = runtime->lookupFunction(0x16A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A508u; }
        if (ctx->pc != 0x16A508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A598_0x16a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A508u; }
        if (ctx->pc != 0x16A508u) { return; }
    }
    ctx->pc = 0x16A508u;
label_16a508:
    // 0x16a508: 0x54400019  bnel        $v0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x16A508u;
    {
        const bool branch_taken_0x16a508 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a508) {
            ctx->pc = 0x16A50Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A508u;
            // 0x16a50c: 0xae720000  sw          $s2, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A570u;
            goto label_16a570;
        }
    }
    ctx->pc = 0x16A510u;
label_16a510:
    // 0x16a510: 0x2a020004  slti        $v0, $s0, 0x4
    ctx->pc = 0x16a510u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x16a514: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x16A514u;
    {
        const bool branch_taken_0x16a514 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A514u;
            // 0x16a518: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a514) {
            ctx->pc = 0x16A548u;
            goto label_16a548;
        }
    }
    ctx->pc = 0x16A51Cu;
    // 0x16a51c: 0x3c14000d  lui         $s4, 0xD
    ctx->pc = 0x16a51cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)13 << 16));
label_16a520:
    // 0x16a520: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16a520u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a524: 0xc055f4a  jal         func_157D28
    ctx->pc = 0x16A524u;
    SET_GPR_U32(ctx, 31, 0x16A52Cu);
    ctx->pc = 0x16A528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A524u;
            // 0x16a528: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157D28u;
    if (runtime->hasFunction(0x157D28u)) {
        auto targetFn = runtime->lookupFunction(0x157D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A52Cu; }
        if (ctx->pc != 0x16A52Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157D28_0x157d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A52Cu; }
        if (ctx->pc != 0x16A52Cu) { return; }
    }
    ctx->pc = 0x16A52Cu;
label_16a52c:
    // 0x16a52c: 0x541024  and         $v0, $v0, $s4
    ctx->pc = 0x16a52cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 20));
    // 0x16a530: 0x5440000f  bnel        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x16A530u;
    {
        const bool branch_taken_0x16a530 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a530) {
            ctx->pc = 0x16A534u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A530u;
            // 0x16a534: 0xae720000  sw          $s2, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A570u;
            goto label_16a570;
        }
    }
    ctx->pc = 0x16A538u;
    // 0x16a538: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x16a538u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x16a53c: 0x2a020004  slti        $v0, $s0, 0x4
    ctx->pc = 0x16a53cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x16a540: 0x1040fff7  beqz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x16A540u;
    {
        const bool branch_taken_0x16a540 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A540u;
            // 0x16a544: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a540) {
            ctx->pc = 0x16A520u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16a520;
        }
    }
    ctx->pc = 0x16A548u;
label_16a548:
    // 0x16a548: 0x2602ffff  addiu       $v0, $s0, -0x1
    ctx->pc = 0x16a548u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x16a54c: 0x2c420003  sltiu       $v0, $v0, 0x3
    ctx->pc = 0x16a54cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x16a550: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x16A550u;
    {
        const bool branch_taken_0x16a550 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16a550) {
            ctx->pc = 0x16A554u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A550u;
            // 0x16a554: 0xae720000  sw          $s2, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A570u;
            goto label_16a570;
        }
    }
    ctx->pc = 0x16A558u;
    // 0x16a558: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x16a558u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a55c: 0xc05a976  jal         func_16A5D8
    ctx->pc = 0x16A55Cu;
    SET_GPR_U32(ctx, 31, 0x16A564u);
    ctx->pc = 0x16A560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A55Cu;
            // 0x16a560: 0x2302821  addu        $a1, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A5D8u;
    if (runtime->hasFunction(0x16A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x16A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A564u; }
        if (ctx->pc != 0x16A564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A5D8_0x16a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A564u; }
        if (ctx->pc != 0x16A564u) { return; }
    }
    ctx->pc = 0x16A564u;
label_16a564:
    // 0x16a564: 0x2501821  addu        $v1, $s2, $s0
    ctx->pc = 0x16a564u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x16a568: 0x62900b  movn        $s2, $v1, $v0
    ctx->pc = 0x16a568u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 3));
    // 0x16a56c: 0xae720000  sw          $s2, 0x0($s3)
    ctx->pc = 0x16a56cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 18));
label_16a570:
    // 0x16a570: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a570u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a574: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a574u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a578: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a578u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a57c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a57cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a580: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16a580u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a584: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16a584u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a588: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16a588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a58c: 0x3e00008  jr          $ra
    ctx->pc = 0x16A58Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A58Cu;
            // 0x16a590: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A508u: goto label_16a508;
            case 0x16A510u: goto label_16a510;
            case 0x16A520u: goto label_16a520;
            case 0x16A52Cu: goto label_16a52c;
            case 0x16A548u: goto label_16a548;
            case 0x16A564u: goto label_16a564;
            case 0x16A570u: goto label_16a570;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A594u;
    // 0x16a594: 0x0  nop
    ctx->pc = 0x16a594u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
