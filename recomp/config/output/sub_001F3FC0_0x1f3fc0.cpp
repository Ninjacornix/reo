#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3FC0
// Address: 0x1f3fc0 - 0x1f4138
void sub_001F3FC0_0x1f3fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3FC0_0x1f3fc0");
#endif

    switch (ctx->pc) {
        case 0x1f3ff0u: goto label_1f3ff0;
        case 0x1f4024u: goto label_1f4024;
        case 0x1f4084u: goto label_1f4084;
        case 0x1f410cu: goto label_1f410c;
        default: break;
    }

    ctx->pc = 0x1f3fc0u;

    // 0x1f3fc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f3fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3fc4: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f3fc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f3fc8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1f3fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1f3fcc: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f3fccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f3fd0: 0xac2057c0  sw          $zero, 0x57C0($at)
    ctx->pc = 0x1f3fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 22464), GPR_U32(ctx, 0));
    // 0x1f3fd4: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f3fd4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f3fd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f3fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f3fdc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f3fdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f3fe0: 0x2484ead0  addiu       $a0, $a0, -0x1530
    ctx->pc = 0x1f3fe0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961872));
    // 0x1f3fe4: 0xac22eaf0  sw          $v0, -0x1510($at)
    ctx->pc = 0x1f3fe4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961904), GPR_U32(ctx, 2));
    // 0x1f3fe8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F3FE8u;
    SET_GPR_U32(ctx, 31, 0x1F3FF0u);
    ctx->pc = 0x1F3FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3FE8u;
            // 0x1f3fec: 0x24a59b20  addiu       $a1, $a1, -0x64E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3FF0u; }
        if (ctx->pc != 0x1F3FF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3FF0u; }
        if (ctx->pc != 0x1F3FF0u) { return; }
    }
    ctx->pc = 0x1F3FF0u;
label_1f3ff0:
    // 0x1f3ff0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f3ff0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f3ff4: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f3ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f3ff8: 0xac20ec70  sw          $zero, -0x1390($at)
    ctx->pc = 0x1f3ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962288), GPR_U32(ctx, 0));
    // 0x1f3ffc: 0x2442ead0  addiu       $v0, $v0, -0x1530
    ctx->pc = 0x1f3ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294961872));
    // 0x1f4000: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f4000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f4004: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1f4004u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4008: 0xac2257c8  sw          $v0, 0x57C8($at)
    ctx->pc = 0x1f4008u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 22472), GPR_U32(ctx, 2));
    // 0x1f400c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f400cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4010: 0xac20ec40  sw          $zero, -0x13C0($at)
    ctx->pc = 0x1f4010u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962240), GPR_U32(ctx, 0));
    // 0x1f4014: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1f4014u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1f4018: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4018u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f401c: 0x24c67310  addiu       $a2, $a2, 0x7310
    ctx->pc = 0x1f401cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 29456));
    // 0x1f4020: 0x2484ec50  addiu       $a0, $a0, -0x13B0
    ctx->pc = 0x1f4020u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962256));
label_1f4024:
    // 0x1f4024: 0x71e3c  dsll32      $v1, $a3, 24
    ctx->pc = 0x1f4024u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 24));
    // 0x1f4028: 0x24e20001  addiu       $v0, $a3, 0x1
    ctx->pc = 0x1f4028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1f402c: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1f402cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1f4030: 0x23e3c  dsll32      $a3, $v0, 24
    ctx->pc = 0x1f4030u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1f4034: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1f4034u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f4038: 0x73e3f  dsra32      $a3, $a3, 24
    ctx->pc = 0x1f4038u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 24));
    // 0x1f403c: 0xc31021  addu        $v0, $a2, $v1
    ctx->pc = 0x1f403cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1f4040: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1f4040u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f4044: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1f4044u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1f4048: 0x28e20005  slti        $v0, $a3, 0x5
    ctx->pc = 0x1f4048u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1f404c: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1F404Cu;
    {
        const bool branch_taken_0x1f404c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F404Cu;
            // 0x1f4050: 0xac650000  sw          $a1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f404c) {
            ctx->pc = 0x1F4024u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f4024;
        }
    }
    ctx->pc = 0x1F4054u;
    // 0x1f4054: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4054u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4058: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4058u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f405c: 0xa020ebd4  sb          $zero, -0x142C($at)
    ctx->pc = 0x1f405cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962132), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f4060: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1f4060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1f4064: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4064u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4068: 0x2484eb00  addiu       $a0, $a0, -0x1500
    ctx->pc = 0x1f4068u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
    // 0x1f406c: 0xa422ebb0  sh          $v0, -0x1450($at)
    ctx->pc = 0x1f406cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294962096), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f4070: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f4070u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4074: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4074u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4078: 0x24060094  addiu       $a2, $zero, 0x94
    ctx->pc = 0x1f4078u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 148));
    // 0x1f407c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F407Cu;
    SET_GPR_U32(ctx, 31, 0x1F4084u);
    ctx->pc = 0x1F4080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F407Cu;
            // 0x1f4080: 0xac20ebd8  sw          $zero, -0x1428($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294962136), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4084u; }
        if (ctx->pc != 0x1F4084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4084u; }
        if (ctx->pc != 0x1F4084u) { return; }
    }
    ctx->pc = 0x1F4084u;
label_1f4084:
    // 0x1f4084: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1f4084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1f4088: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4088u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f408c: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f408cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f4090: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4090u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4094: 0x8c22eb14  lw          $v0, -0x14EC($at)
    ctx->pc = 0x1f4094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961940)));
    // 0x1f4098: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1f4098u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1f409c: 0x41082a  slt         $at, $v0, $at
    ctx->pc = 0x1f409cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1f40a0: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F40A0u;
    {
        const bool branch_taken_0x1f40a0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F40A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F40A0u;
            // 0x1f40a4: 0x24020300  addiu       $v0, $zero, 0x300 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f40a0) {
            ctx->pc = 0x1F40B8u;
            goto label_1f40b8;
        }
    }
    ctx->pc = 0x1F40A8u;
    // 0x1f40a8: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1f40a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1f40ac: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40b0: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f40b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f40b4: 0x24020300  addiu       $v0, $zero, 0x300
    ctx->pc = 0x1f40b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
label_1f40b8:
    // 0x1f40b8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40bc: 0xac22eb18  sw          $v0, -0x14E8($at)
    ctx->pc = 0x1f40bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961944), GPR_U32(ctx, 2));
    // 0x1f40c0: 0x3c030036  lui         $v1, 0x36
    ctx->pc = 0x1f40c0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
    // 0x1f40c4: 0x2463efa0  addiu       $v1, $v1, -0x1060
    ctx->pc = 0x1f40c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963104));
    // 0x1f40c8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40cc: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f40ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f40d0: 0xac23eb1c  sw          $v1, -0x14E4($at)
    ctx->pc = 0x1f40d0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961948), GPR_U32(ctx, 3));
    // 0x1f40d4: 0x2442ec90  addiu       $v0, $v0, -0x1370
    ctx->pc = 0x1f40d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962320));
    // 0x1f40d8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40dc: 0xac22eb24  sw          $v0, -0x14DC($at)
    ctx->pc = 0x1f40dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961956), GPR_U32(ctx, 2));
    // 0x1f40e0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40e4: 0x8c23eb1c  lw          $v1, -0x14E4($at)
    ctx->pc = 0x1f40e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961948)));
    // 0x1f40e8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40ec: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1f40ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1f40f0: 0x8c22eb24  lw          $v0, -0x14DC($at)
    ctx->pc = 0x1f40f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961956)));
    // 0x1f40f4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40f8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f40f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f40fc: 0xac23eb20  sw          $v1, -0x14E0($at)
    ctx->pc = 0x1f40fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961952), GPR_U32(ctx, 3));
    // 0x1f4100: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4100u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4104: 0xc042652  jal         func_109948
    ctx->pc = 0x1F4104u;
    SET_GPR_U32(ctx, 31, 0x1F410Cu);
    ctx->pc = 0x1F4108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4104u;
            // 0x1f4108: 0xac22eb28  sw          $v0, -0x14D8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294961960), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x109948u;
    if (runtime->hasFunction(0x109948u)) {
        auto targetFn = runtime->lookupFunction(0x109948u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F410Cu; }
        if (ctx->pc != 0x1F410Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00109948_0x109948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F410Cu; }
        if (ctx->pc != 0x1F410Cu) { return; }
    }
    ctx->pc = 0x1F410Cu;
label_1f410c:
    // 0x1f410c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f410cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4110: 0xa022eb31  sb          $v0, -0x14CF($at)
    ctx->pc = 0x1f4110u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961969), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4114: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f4114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f4118: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4118u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f411c: 0xa022eb38  sb          $v0, -0x14C8($at)
    ctx->pc = 0x1f411cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961976), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4120: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4120u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4124: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f4124u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4128: 0xac20eb90  sw          $zero, -0x1470($at)
    ctx->pc = 0x1f4128u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962064), GPR_U32(ctx, 0));
    // 0x1f412c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1f412cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4130: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4130u;
            // 0x1f4134: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4138u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
