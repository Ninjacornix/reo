#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5900
// Address: 0x1f5900 - 0x1f5b50
void sub_001F5900_0x1f5900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5900_0x1f5900");
#endif

    switch (ctx->pc) {
        case 0x1f592cu: goto label_1f592c;
        case 0x1f5938u: goto label_1f5938;
        case 0x1f594cu: goto label_1f594c;
        case 0x1f5988u: goto label_1f5988;
        case 0x1f5990u: goto label_1f5990;
        case 0x1f5a30u: goto label_1f5a30;
        case 0x1f5a58u: goto label_1f5a58;
        case 0x1f5a94u: goto label_1f5a94;
        case 0x1f5ac4u: goto label_1f5ac4;
        case 0x1f5accu: goto label_1f5acc;
        default: break;
    }

    ctx->pc = 0x1f5900u;

    // 0x1f5900: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f5900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f5904: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5904u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5908: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f5908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f590c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f590cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5910: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f5910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5914: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1F5914u;
    {
        const bool branch_taken_0x1f5914 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5914u;
            // 0x1f5918: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5914) {
            ctx->pc = 0x1F59ACu;
            goto label_1f59ac;
        }
    }
    ctx->pc = 0x1F591Cu;
    // 0x1f591c: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x1f591cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1f5920: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1f5920u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f5924: 0xc07d284  jal         func_1F4A10
    ctx->pc = 0x1F5924u;
    SET_GPR_U32(ctx, 31, 0x1F592Cu);
    ctx->pc = 0x1F5928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5924u;
            // 0x1f5928: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4A10u;
    if (runtime->hasFunction(0x1F4A10u)) {
        auto targetFn = runtime->lookupFunction(0x1F4A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F592Cu; }
        if (ctx->pc != 0x1F592Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4A10_0x1f4a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F592Cu; }
        if (ctx->pc != 0x1F592Cu) { return; }
    }
    ctx->pc = 0x1F592Cu;
label_1f592c:
    // 0x1f592c: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1f592cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1f5930: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F5930u;
    SET_GPR_U32(ctx, 31, 0x1F5938u);
    ctx->pc = 0x1F5934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5930u;
            // 0x1f5934: 0x24849b38  addiu       $a0, $a0, -0x64C8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5938u; }
        if (ctx->pc != 0x1F5938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5938u; }
        if (ctx->pc != 0x1F5938u) { return; }
    }
    ctx->pc = 0x1F5938u;
label_1f5938:
    // 0x1f5938: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f5938u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f593c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f593cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5940: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f5940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5944: 0xc07d330  jal         func_1F4CC0
    ctx->pc = 0x1F5944u;
    SET_GPR_U32(ctx, 31, 0x1F594Cu);
    ctx->pc = 0x1F5948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5944u;
            // 0x1f5948: 0x24a59b38  addiu       $a1, $a1, -0x64C8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4CC0u;
    if (runtime->hasFunction(0x1F4CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F594Cu; }
        if (ctx->pc != 0x1F594Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4CC0_0x1f4cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F594Cu; }
        if (ctx->pc != 0x1F594Cu) { return; }
    }
    ctx->pc = 0x1F594Cu;
label_1f594c:
    // 0x1f594c: 0x9603002c  lhu         $v1, 0x2C($s0)
    ctx->pc = 0x1f594cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f5950: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1f5950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f5954: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1f5954u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1f5958: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x1f5958u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1f595c: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f595cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f5960: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1f5960u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1f5964: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1f5964u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1f5968: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f5968u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f596c: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x1f596cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f5970: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f5970u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f5974: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1f5974u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f5978: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f5978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f597c: 0x2343c  dsll32      $a2, $v0, 16
    ctx->pc = 0x1f597cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f5980: 0xc075aa4  jal         func_1D6A90
    ctx->pc = 0x1F5980u;
    SET_GPR_U32(ctx, 31, 0x1F5988u);
    ctx->pc = 0x1F5984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5980u;
            // 0x1f5984: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A90u;
    if (runtime->hasFunction(0x1D6A90u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5988u; }
        if (ctx->pc != 0x1F5988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A90_0x1d6a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5988u; }
        if (ctx->pc != 0x1F5988u) { return; }
    }
    ctx->pc = 0x1F5988u;
label_1f5988:
    // 0x1f5988: 0xc07d16c  jal         func_1F45B0
    ctx->pc = 0x1F5988u;
    SET_GPR_U32(ctx, 31, 0x1F5990u);
    ctx->pc = 0x1F598Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5988u;
            // 0x1f598c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45B0u;
    if (runtime->hasFunction(0x1F45B0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5990u; }
        if (ctx->pc != 0x1F5990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45B0_0x1f45b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5990u; }
        if (ctx->pc != 0x1F5990u) { return; }
    }
    ctx->pc = 0x1F5990u;
label_1f5990:
    // 0x1f5990: 0x2841ffff  slti        $at, $v0, -0x1
    ctx->pc = 0x1f5990u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1f5994: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F5994u;
    {
        const bool branch_taken_0x1f5994 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f5994) {
            ctx->pc = 0x1F59A4u;
            goto label_1f59a4;
        }
    }
    ctx->pc = 0x1F599Cu;
    // 0x1f599c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F599Cu;
    {
        const bool branch_taken_0x1f599c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F59A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F599Cu;
            // 0x1f59a0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f599c) {
            ctx->pc = 0x1F59B4u;
            goto label_1f59b4;
        }
    }
    ctx->pc = 0x1F59A4u;
label_1f59a4:
    // 0x1f59a4: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1f59a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1f59a8: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f59a8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f59ac:
    // 0x1f59ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f59acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f59b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f59b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f59b4:
    // 0x1f59b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f59b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f59b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F59B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F59BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F59B8u;
            // 0x1f59bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F592Cu: goto label_1f592c;
            case 0x1F5938u: goto label_1f5938;
            case 0x1F594Cu: goto label_1f594c;
            case 0x1F5988u: goto label_1f5988;
            case 0x1F5990u: goto label_1f5990;
            case 0x1F59A4u: goto label_1f59a4;
            case 0x1F59ACu: goto label_1f59ac;
            case 0x1F59B4u: goto label_1f59b4;
            case 0x1F5A28u: goto label_1f5a28;
            case 0x1F5A30u: goto label_1f5a30;
            case 0x1F5A48u: goto label_1f5a48;
            case 0x1F5A58u: goto label_1f5a58;
            case 0x1F5A8Cu: goto label_1f5a8c;
            case 0x1F5A94u: goto label_1f5a94;
            case 0x1F5ABCu: goto label_1f5abc;
            case 0x1F5AC4u: goto label_1f5ac4;
            case 0x1F5ACCu: goto label_1f5acc;
            case 0x1F5B00u: goto label_1f5b00;
            case 0x1F5B30u: goto label_1f5b30;
            case 0x1F5B34u: goto label_1f5b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F59C0u;
    // 0x1f59c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f59c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f59c4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f59c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f59c8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1f59c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1f59cc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f59ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f59d0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f59d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f59d4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f59d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f59d8: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f59d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f59dc: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x1f59dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f59e0: 0x10400053  beqz        $v0, . + 4 + (0x53 << 2)
    ctx->pc = 0x1F59E0u;
    {
        const bool branch_taken_0x1f59e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F59E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F59E0u;
            // 0x1f59e4: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f59e0) {
            ctx->pc = 0x1F5B30u;
            goto label_1f5b30;
        }
    }
    ctx->pc = 0x1F59E8u;
    // 0x1f59e8: 0x80630006  lb          $v1, 0x6($v1)
    ctx->pc = 0x1f59e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 6)));
    // 0x1f59ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f59ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f59f0: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F59F0u;
    {
        const bool branch_taken_0x1f59f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F59F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F59F0u;
            // 0x1f59f4: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f59f0) {
            ctx->pc = 0x1F5A28u;
            goto label_1f5a28;
        }
    }
    ctx->pc = 0x1F59F8u;
    // 0x1f59f8: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f59f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f59fc: 0xae42008c  sw          $v0, 0x8C($s2)
    ctx->pc = 0x1f59fcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 140), GPR_U32(ctx, 2));
    // 0x1f5a00: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x1f5a00u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f5a04: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f5a04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5a08: 0xa2400001  sb          $zero, 0x1($s2)
    ctx->pc = 0x1f5a08u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5a0c: 0xa2400002  sb          $zero, 0x2($s2)
    ctx->pc = 0x1f5a0cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5a10: 0xa2400003  sb          $zero, 0x3($s2)
    ctx->pc = 0x1f5a10u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5a14: 0xa6400004  sh          $zero, 0x4($s2)
    ctx->pc = 0x1f5a14u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5a18: 0xa6400006  sh          $zero, 0x6($s2)
    ctx->pc = 0x1f5a18u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5a1c: 0xa6400008  sh          $zero, 0x8($s2)
    ctx->pc = 0x1f5a1cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5a20: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1F5A20u;
    {
        const bool branch_taken_0x1f5a20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5A20u;
            // 0x1f5a24: 0xa640000a  sh          $zero, 0xA($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5a20) {
            ctx->pc = 0x1F5B34u;
            goto label_1f5b34;
        }
    }
    ctx->pc = 0x1F5A28u;
label_1f5a28:
    // 0x1f5a28: 0xc07d1f8  jal         func_1F47E0
    ctx->pc = 0x1F5A28u;
    SET_GPR_U32(ctx, 31, 0x1F5A30u);
    ctx->pc = 0x1F47E0u;
    if (runtime->hasFunction(0x1F47E0u)) {
        auto targetFn = runtime->lookupFunction(0x1F47E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5A30u; }
        if (ctx->pc != 0x1F5A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F47E0_0x1f47e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5A30u; }
        if (ctx->pc != 0x1F5A30u) { return; }
    }
    ctx->pc = 0x1F5A30u;
label_1f5a30:
    // 0x1f5a30: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f5a30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f5a34: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F5A34u;
    {
        const bool branch_taken_0x1f5a34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F5A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5A34u;
            // 0x1f5a38: 0x3c050036  lui         $a1, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)54 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5a34) {
            ctx->pc = 0x1F5A48u;
            goto label_1f5a48;
        }
    }
    ctx->pc = 0x1F5A3Cu;
    // 0x1f5a3c: 0x24020012  addiu       $v0, $zero, 0x12
    ctx->pc = 0x1f5a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1f5a40: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1F5A40u;
    {
        const bool branch_taken_0x1f5a40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5A40u;
            // 0x1f5a44: 0xa2420001  sb          $v0, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5a40) {
            ctx->pc = 0x1F5B30u;
            goto label_1f5b30;
        }
    }
    ctx->pc = 0x1F5A48u;
label_1f5a48:
    // 0x1f5a48: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1f5a48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5a4c: 0x24a5ebf0  addiu       $a1, $a1, -0x1410
    ctx->pc = 0x1f5a4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962160));
    // 0x1f5a50: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F5A50u;
    SET_GPR_U32(ctx, 31, 0x1F5A58u);
    ctx->pc = 0x1F5A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5A50u;
            // 0x1f5a54: 0x2406001f  addiu       $a2, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5A58u; }
        if (ctx->pc != 0x1F5A58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5A58u; }
        if (ctx->pc != 0x1F5A58u) { return; }
    }
    ctx->pc = 0x1F5A58u;
label_1f5a58:
    // 0x1f5a58: 0x441000c  bgez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1F5A58u;
    {
        const bool branch_taken_0x1f5a58 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F5A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5A58u;
            // 0x1f5a5c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5a58) {
            ctx->pc = 0x1F5A8Cu;
            goto label_1f5a8c;
        }
    }
    ctx->pc = 0x1F5A60u;
    // 0x1f5a60: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f5a60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f5a64: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f5a64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5a68: 0xae43008c  sw          $v1, 0x8C($s2)
    ctx->pc = 0x1f5a68u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 140), GPR_U32(ctx, 3));
    // 0x1f5a6c: 0xa2420000  sb          $v0, 0x0($s2)
    ctx->pc = 0x1f5a6cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f5a70: 0xa2400001  sb          $zero, 0x1($s2)
    ctx->pc = 0x1f5a70u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5a74: 0xa2400002  sb          $zero, 0x2($s2)
    ctx->pc = 0x1f5a74u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5a78: 0xa2400003  sb          $zero, 0x3($s2)
    ctx->pc = 0x1f5a78u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5a7c: 0xa6400004  sh          $zero, 0x4($s2)
    ctx->pc = 0x1f5a7cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5a80: 0xa6400006  sh          $zero, 0x6($s2)
    ctx->pc = 0x1f5a80u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5a84: 0xa6400008  sh          $zero, 0x8($s2)
    ctx->pc = 0x1f5a84u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5a88: 0xa640000a  sh          $zero, 0xA($s2)
    ctx->pc = 0x1f5a88u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f5a8c:
    // 0x1f5a8c: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F5A8Cu;
    SET_GPR_U32(ctx, 31, 0x1F5A94u);
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5A94u; }
        if (ctx->pc != 0x1F5A94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5A94u; }
        if (ctx->pc != 0x1F5A94u) { return; }
    }
    ctx->pc = 0x1F5A94u;
label_1f5a94:
    // 0x1f5a94: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5a94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5a98: 0xa422ebe0  sh          $v0, -0x1420($at)
    ctx->pc = 0x1f5a98u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294962144), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f5a9c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5a9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5aa0: 0x9422ebe0  lhu         $v0, -0x1420($at)
    ctx->pc = 0x1f5aa0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294962144)));
    // 0x1f5aa4: 0x28410004  slti        $at, $v0, 0x4
    ctx->pc = 0x1f5aa4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1f5aa8: 0x14200004  bnez        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F5AA8u;
    {
        const bool branch_taken_0x1f5aa8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F5AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5AA8u;
            // 0x1f5aac: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5aa8) {
            ctx->pc = 0x1F5ABCu;
            goto label_1f5abc;
        }
    }
    ctx->pc = 0x1F5AB0u;
    // 0x1f5ab0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1f5ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f5ab4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5ab4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5ab8: 0xa422ebe0  sh          $v0, -0x1420($at)
    ctx->pc = 0x1f5ab8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294962144), (uint16_t)GPR_U32(ctx, 2));
label_1f5abc:
    // 0x1f5abc: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F5ABCu;
    {
        const bool branch_taken_0x1f5abc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f5abc) {
            ctx->pc = 0x1F5B00u;
            goto label_1f5b00;
        }
    }
    ctx->pc = 0x1F5AC4u;
label_1f5ac4:
    // 0x1f5ac4: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5AC4u;
    SET_GPR_U32(ctx, 31, 0x1F5ACCu);
    ctx->pc = 0x1F5AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5AC4u;
            // 0x1f5ac8: 0x118080  sll         $s0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5ACCu; }
        if (ctx->pc != 0x1F5ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5ACCu; }
        if (ctx->pc != 0x1F5ACCu) { return; }
    }
    ctx->pc = 0x1F5ACCu;
label_1f5acc:
    // 0x1f5acc: 0x3c030036  lui         $v1, 0x36
    ctx->pc = 0x1f5accu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
    // 0x1f5ad0: 0x112340  sll         $a0, $s1, 13
    ctx->pc = 0x1f5ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 13));
    // 0x1f5ad4: 0x2463ebe0  addiu       $v1, $v1, -0x1420
    ctx->pc = 0x1f5ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294962144));
    // 0x1f5ad8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1f5ad8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1f5adc: 0x702821  addu        $a1, $v1, $s0
    ctx->pc = 0x1f5adcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1f5ae0: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1f5ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1f5ae4: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1f5ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1f5ae8: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f5ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f5aec: 0x24637ad0  addiu       $v1, $v1, 0x7AD0
    ctx->pc = 0x1f5aecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 31440));
    // 0x1f5af0: 0x2442ec78  addiu       $v0, $v0, -0x1388
    ctx->pc = 0x1f5af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962296));
    // 0x1f5af4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1f5af4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1f5af8: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1f5af8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1f5afc: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1f5afcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_1f5b00:
    // 0x1f5b00: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5b00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5b04: 0x9422ebe0  lhu         $v0, -0x1420($at)
    ctx->pc = 0x1f5b04u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294962144)));
    // 0x1f5b08: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1f5b08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1f5b0c: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1F5B0Cu;
    {
        const bool branch_taken_0x1f5b0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F5B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5B0Cu;
            // 0x1f5b10: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5b0c) {
            ctx->pc = 0x1F5AC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f5ac4;
        }
    }
    ctx->pc = 0x1F5B14u;
    // 0x1f5b14: 0xae40003c  sw          $zero, 0x3C($s2)
    ctx->pc = 0x1f5b14u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 60), GPR_U32(ctx, 0));
    // 0x1f5b18: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5b18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5b1c: 0xac20ec14  sw          $zero, -0x13EC($at)
    ctx->pc = 0x1f5b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962196), GPR_U32(ctx, 0));
    // 0x1f5b20: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1f5b20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1f5b24: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5b24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5b28: 0xa020ec10  sb          $zero, -0x13F0($at)
    ctx->pc = 0x1f5b28u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962192), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5b2c: 0xa2420001  sb          $v0, 0x1($s2)
    ctx->pc = 0x1f5b2cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f5b30:
    // 0x1f5b30: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f5b30u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f5b34:
    // 0x1f5b34: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1f5b34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f5b38: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f5b38u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f5b3c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f5b3cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f5b40: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f5b40u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f5b44: 0x3e00008  jr          $ra
    ctx->pc = 0x1F5B44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F5B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5B44u;
            // 0x1f5b48: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F592Cu: goto label_1f592c;
            case 0x1F5938u: goto label_1f5938;
            case 0x1F594Cu: goto label_1f594c;
            case 0x1F5988u: goto label_1f5988;
            case 0x1F5990u: goto label_1f5990;
            case 0x1F59A4u: goto label_1f59a4;
            case 0x1F59ACu: goto label_1f59ac;
            case 0x1F59B4u: goto label_1f59b4;
            case 0x1F5A28u: goto label_1f5a28;
            case 0x1F5A30u: goto label_1f5a30;
            case 0x1F5A48u: goto label_1f5a48;
            case 0x1F5A58u: goto label_1f5a58;
            case 0x1F5A8Cu: goto label_1f5a8c;
            case 0x1F5A94u: goto label_1f5a94;
            case 0x1F5ABCu: goto label_1f5abc;
            case 0x1F5AC4u: goto label_1f5ac4;
            case 0x1F5ACCu: goto label_1f5acc;
            case 0x1F5B00u: goto label_1f5b00;
            case 0x1F5B30u: goto label_1f5b30;
            case 0x1F5B34u: goto label_1f5b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F5B4Cu;
    // 0x1f5b4c: 0x0  nop
    ctx->pc = 0x1f5b4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
