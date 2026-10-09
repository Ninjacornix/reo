#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C64C0
// Address: 0x1c64c0 - 0x1c6670
void sub_001C64C0_0x1c64c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C64C0_0x1c64c0");
#endif

    switch (ctx->pc) {
        case 0x1c64e0u: goto label_1c64e0;
        case 0x1c64f8u: goto label_1c64f8;
        case 0x1c6538u: goto label_1c6538;
        case 0x1c6590u: goto label_1c6590;
        case 0x1c6628u: goto label_1c6628;
        case 0x1c6640u: goto label_1c6640;
        case 0x1c6648u: goto label_1c6648;
        default: break;
    }

    ctx->pc = 0x1c64c0u;

    // 0x1c64c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c64c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c64c4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c64c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c64c8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c64c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c64cc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c64ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c64d0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c64d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c64d4: 0x8c9001b8  lw          $s0, 0x1B8($a0)
    ctx->pc = 0x1c64d4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 440)));
    // 0x1c64d8: 0xc072250  jal         func_1C8940
    ctx->pc = 0x1C64D8u;
    SET_GPR_U32(ctx, 31, 0x1C64E0u);
    ctx->pc = 0x1C64DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C64D8u;
            // 0x1c64dc: 0x26240014  addiu       $a0, $s1, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8940u;
    if (runtime->hasFunction(0x1C8940u)) {
        auto targetFn = runtime->lookupFunction(0x1C8940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C64E0u; }
        if (ctx->pc != 0x1C64E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8940_0x1c8940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C64E0u; }
        if (ctx->pc != 0x1C64E0u) { return; }
    }
    ctx->pc = 0x1C64E0u;
label_1c64e0:
    // 0x1c64e0: 0x8e2301bc  lw          $v1, 0x1BC($s1)
    ctx->pc = 0x1c64e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 444)));
    // 0x1c64e4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1c64e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c64e8: 0x8e2201b8  lw          $v0, 0x1B8($s1)
    ctx->pc = 0x1c64e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 440)));
    // 0x1c64ec: 0x26240014  addiu       $a0, $s1, 0x14
    ctx->pc = 0x1c64ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x1c64f0: 0xc072258  jal         func_1C8960
    ctx->pc = 0x1C64F0u;
    SET_GPR_U32(ctx, 31, 0x1C64F8u);
    ctx->pc = 0x1C64F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C64F0u;
            // 0x1c64f4: 0x623023  subu        $a2, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8960u;
    if (runtime->hasFunction(0x1C8960u)) {
        auto targetFn = runtime->lookupFunction(0x1C8960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C64F8u; }
        if (ctx->pc != 0x1C64F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8960_0x1c8960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C64F8u; }
        if (ctx->pc != 0x1C64F8u) { return; }
    }
    ctx->pc = 0x1C64F8u;
label_1c64f8:
    // 0x1c64f8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c64f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c64fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c64fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c6500: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c6500u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6504: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6504u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6504u;
            // 0x1c6508: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C64E0u: goto label_1c64e0;
            case 0x1C64F8u: goto label_1c64f8;
            case 0x1C6538u: goto label_1c6538;
            case 0x1C6564u: goto label_1c6564;
            case 0x1C656Cu: goto label_1c656c;
            case 0x1C6574u: goto label_1c6574;
            case 0x1C6580u: goto label_1c6580;
            case 0x1C6590u: goto label_1c6590;
            case 0x1C659Cu: goto label_1c659c;
            case 0x1C65BCu: goto label_1c65bc;
            case 0x1C65ECu: goto label_1c65ec;
            case 0x1C6628u: goto label_1c6628;
            case 0x1C6640u: goto label_1c6640;
            case 0x1C6648u: goto label_1c6648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C650Cu;
    // 0x1c650c: 0x0  nop
    ctx->pc = 0x1c650cu;
    // NOP
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
            case 0x1C64E0u: goto label_1c64e0;
            case 0x1C64F8u: goto label_1c64f8;
            case 0x1C6538u: goto label_1c6538;
            case 0x1C6564u: goto label_1c6564;
            case 0x1C656Cu: goto label_1c656c;
            case 0x1C6574u: goto label_1c6574;
            case 0x1C6580u: goto label_1c6580;
            case 0x1C6590u: goto label_1c6590;
            case 0x1C659Cu: goto label_1c659c;
            case 0x1C65BCu: goto label_1c65bc;
            case 0x1C65ECu: goto label_1c65ec;
            case 0x1C6628u: goto label_1c6628;
            case 0x1C6640u: goto label_1c6640;
            case 0x1C6648u: goto label_1c6648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C65D0u;
    // 0x1c65d0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1c65d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c65d4: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1c65d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1c65d8: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1c65d8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c65dc: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C65DCu;
    {
        const bool branch_taken_0x1c65dc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C65E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C65DCu;
            // 0x1c65e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c65dc) {
            ctx->pc = 0x1C65ECu;
            goto label_1c65ec;
        }
    }
    ctx->pc = 0x1C65E4u;
    // 0x1c65e4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1c65e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1c65e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c65e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1c65ec:
    // 0x1c65ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1C65ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C64E0u: goto label_1c64e0;
            case 0x1C64F8u: goto label_1c64f8;
            case 0x1C6538u: goto label_1c6538;
            case 0x1C6564u: goto label_1c6564;
            case 0x1C656Cu: goto label_1c656c;
            case 0x1C6574u: goto label_1c6574;
            case 0x1C6580u: goto label_1c6580;
            case 0x1C6590u: goto label_1c6590;
            case 0x1C659Cu: goto label_1c659c;
            case 0x1C65BCu: goto label_1c65bc;
            case 0x1C65ECu: goto label_1c65ec;
            case 0x1C6628u: goto label_1c6628;
            case 0x1C6640u: goto label_1c6640;
            case 0x1C6648u: goto label_1c6648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C65F4u;
    // 0x1c65f4: 0x0  nop
    ctx->pc = 0x1c65f4u;
    // NOP
    // 0x1c65f8: 0x0  nop
    ctx->pc = 0x1c65f8u;
    // NOP
    // 0x1c65fc: 0x0  nop
    ctx->pc = 0x1c65fcu;
    // NOP
    // 0x1c6600: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1c6600u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6604: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1c6604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6608: 0x8071688  j           func_1C5A20
    ctx->pc = 0x1C6608u;
    ctx->pc = 0x1C660Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6608u;
            // 0x1c660c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5A20u;
    if (runtime->hasFunction(0x1C5A20u)) {
        auto targetFn = runtime->lookupFunction(0x1C5A20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C5A20_0x1c5a20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6610u;
    // 0x1c6610: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c6610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c6614: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c6614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c6618: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c6618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c661c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c661cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6620: 0xc072254  jal         func_1C8950
    ctx->pc = 0x1C6620u;
    SET_GPR_U32(ctx, 31, 0x1C6628u);
    ctx->pc = 0x1C6624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6620u;
            // 0x1c6624: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8950u;
    if (runtime->hasFunction(0x1C8950u)) {
        auto targetFn = runtime->lookupFunction(0x1C8950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6628u; }
        if (ctx->pc != 0x1C6628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8950_0x1c8950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6628u; }
        if (ctx->pc != 0x1C6628u) { return; }
    }
    ctx->pc = 0x1C6628u;
label_1c6628:
    // 0x1c6628: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c6628u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c662c: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x1c662cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c6630: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1c6630u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1c6634: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1c6634u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6638: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x1C6638u;
    SET_GPR_U32(ctx, 31, 0x1C6640u);
    ctx->pc = 0x1C663Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6638u;
            // 0x1c663c: 0x822821  addu        $a1, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6640u; }
        if (ctx->pc != 0x1C6640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6640u; }
        if (ctx->pc != 0x1C6640u) { return; }
    }
    ctx->pc = 0x1C6640u;
label_1c6640:
    // 0x1c6640: 0xc072294  jal         func_1C8A50
    ctx->pc = 0x1C6640u;
    SET_GPR_U32(ctx, 31, 0x1C6648u);
    ctx->pc = 0x1C6644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6640u;
            // 0x1c6644: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8A50u;
    {
        auto targetFn = runtime->lookupFunction(0x1C8A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6648u; }
        if (ctx->pc != 0x1C6648u) { return; }
    }
    ctx->pc = 0x1C6648u;
label_1c6648:
    // 0x1c6648: 0xae30000c  sw          $s0, 0xC($s1)
    ctx->pc = 0x1c6648u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 16));
    // 0x1c664c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c664cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c6650: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c6650u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c6654: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c6654u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6658: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C665Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6658u;
            // 0x1c665c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C64E0u: goto label_1c64e0;
            case 0x1C64F8u: goto label_1c64f8;
            case 0x1C6538u: goto label_1c6538;
            case 0x1C6564u: goto label_1c6564;
            case 0x1C656Cu: goto label_1c656c;
            case 0x1C6574u: goto label_1c6574;
            case 0x1C6580u: goto label_1c6580;
            case 0x1C6590u: goto label_1c6590;
            case 0x1C659Cu: goto label_1c659c;
            case 0x1C65BCu: goto label_1c65bc;
            case 0x1C65ECu: goto label_1c65ec;
            case 0x1C6628u: goto label_1c6628;
            case 0x1C6640u: goto label_1c6640;
            case 0x1C6648u: goto label_1c6648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6660u;
    // 0x1c6660: 0x8072200  j           func_1C8800
    ctx->pc = 0x1C6660u;
    ctx->pc = 0x1C6664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6660u;
            // 0x1c6664: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8800u;
    {
        auto targetFn = runtime->lookupFunction(0x1C8800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1C6668u;
    // 0x1c6668: 0x0  nop
    ctx->pc = 0x1c6668u;
    // NOP
    // 0x1c666c: 0x0  nop
    ctx->pc = 0x1c666cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
