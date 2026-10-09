#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6510
// Address: 0x1c6510 - 0x1c65d0
void sub_001C6510_0x1c6510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6510_0x1c6510");
#endif

    switch (ctx->pc) {
        case 0x1c6538u: goto label_1c6538;
        case 0x1c6590u: goto label_1c6590;
        default: break;
    }

    ctx->pc = 0x1c6510u;

    // 0x1c6510: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c6510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c6514: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c6514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c6518: 0x27a5003f  addiu       $a1, $sp, 0x3F
    ctx->pc = 0x1c6518u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 63));
    // 0x1c651c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c651cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c6520: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c6520u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6524: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c6524u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c6528: 0x26240028  addiu       $a0, $s1, 0x28
    ctx->pc = 0x1c6528u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 40));
    // 0x1c652c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1c652cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6530: 0xc072198  jal         func_1C8660
    ctx->pc = 0x1C6530u;
    SET_GPR_U32(ctx, 31, 0x1C6538u);
    ctx->pc = 0x1C6534u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6530u;
            // 0x1c6534: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8660u;
    if (runtime->hasFunction(0x1C8660u)) {
        auto targetFn = runtime->lookupFunction(0x1C8660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6538u; }
        if (ctx->pc != 0x1C6538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8660_0x1c8660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6538u; }
        if (ctx->pc != 0x1C6538u) { return; }
    }
    ctx->pc = 0x1C6538u;
label_1c6538:
    // 0x1c6538: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c6538u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c653c: 0x1043000d  beq         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1C653Cu;
    {
        const bool branch_taken_0x1c653c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c653c) {
            ctx->pc = 0x1C6574u;
            goto label_1c6574;
        }
    }
    ctx->pc = 0x1C6544u;
    // 0x1c6544: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c6544u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c6548: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C6548u;
    {
        const bool branch_taken_0x1c6548 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c6548) {
            ctx->pc = 0x1C656Cu;
            goto label_1c656c;
        }
    }
    ctx->pc = 0x1C6550u;
    // 0x1c6550: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x1c6550u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1c6554: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6554u;
    {
        const bool branch_taken_0x1c6554 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c6554) {
            ctx->pc = 0x1C6564u;
            goto label_1c6564;
        }
    }
    ctx->pc = 0x1C655Cu;
    // 0x1c655c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C655Cu;
    {
        const bool branch_taken_0x1c655c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c655c) {
            ctx->pc = 0x1C6580u;
            goto label_1c6580;
        }
    }
    ctx->pc = 0x1C6564u;
label_1c6564:
    // 0x1c6564: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C6564u;
    {
        const bool branch_taken_0x1c6564 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6564u;
            // 0x1c6568: 0x24100040  addiu       $s0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6564) {
            ctx->pc = 0x1C6580u;
            goto label_1c6580;
        }
    }
    ctx->pc = 0x1C656Cu;
label_1c656c:
    // 0x1c656c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C656Cu;
    {
        const bool branch_taken_0x1c656c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C656Cu;
            // 0x1c6570: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c656c) {
            ctx->pc = 0x1C6580u;
            goto label_1c6580;
        }
    }
    ctx->pc = 0x1C6574u;
label_1c6574:
    // 0x1c6574: 0x93a2003f  lbu         $v0, 0x3F($sp)
    ctx->pc = 0x1c6574u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 63)));
    // 0x1c6578: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x1c6578u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c657c: 0xa22201ce  sb          $v0, 0x1CE($s1)
    ctx->pc = 0x1c657cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 462), (uint8_t)GPR_U32(ctx, 2));
label_1c6580:
    // 0x1c6580: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C6580u;
    {
        const bool branch_taken_0x1c6580 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C6584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6580u;
            // 0x1c6584: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6580) {
            ctx->pc = 0x1C659Cu;
            goto label_1c659c;
        }
    }
    ctx->pc = 0x1C6588u;
    // 0x1c6588: 0xc072254  jal         func_1C8950
    ctx->pc = 0x1C6588u;
    SET_GPR_U32(ctx, 31, 0x1C6590u);
    ctx->pc = 0x1C8950u;
    if (runtime->hasFunction(0x1C8950u)) {
        auto targetFn = runtime->lookupFunction(0x1C8950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6590u; }
        if (ctx->pc != 0x1C6590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8950_0x1c8950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6590u; }
        if (ctx->pc != 0x1C6590u) { return; }
    }
    ctx->pc = 0x1C6590u;
label_1c6590:
    // 0x1c6590: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C6590u;
    {
        const bool branch_taken_0x1c6590 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c6590) {
            ctx->pc = 0x1C659Cu;
            goto label_1c659c;
        }
    }
    ctx->pc = 0x1C6598u;
    // 0x1c6598: 0x24100080  addiu       $s0, $zero, 0x80
    ctx->pc = 0x1c6598u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
label_1c659c:
    // 0x1c659c: 0x962301e0  lhu         $v1, 0x1E0($s1)
    ctx->pc = 0x1c659cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 480)));
    // 0x1c65a0: 0x962201e8  lhu         $v0, 0x1E8($s1)
    ctx->pc = 0x1c65a0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 488)));
    // 0x1c65a4: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1c65a4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c65a8: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C65A8u;
    {
        const bool branch_taken_0x1c65a8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C65ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C65A8u;
            // 0x1c65ac: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c65a8) {
            ctx->pc = 0x1C65BCu;
            goto label_1c65bc;
        }
    }
    ctx->pc = 0x1C65B0u;
    // 0x1c65b0: 0xa62001e0  sh          $zero, 0x1E0($s1)
    ctx->pc = 0x1c65b0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 480), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c65b4: 0x24100040  addiu       $s0, $zero, 0x40
    ctx->pc = 0x1c65b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1c65b8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1c65b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c65bc:
    // 0x1c65bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c65bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c65c0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c65c0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c65c4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c65c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c65c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C65C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C65CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C65C8u;
            // 0x1c65cc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6538u: goto label_1c6538;
            case 0x1C6564u: goto label_1c6564;
            case 0x1C656Cu: goto label_1c656c;
            case 0x1C6574u: goto label_1c6574;
            case 0x1C6580u: goto label_1c6580;
            case 0x1C6590u: goto label_1c6590;
            case 0x1C659Cu: goto label_1c659c;
            case 0x1C65BCu: goto label_1c65bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C65D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
