#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012F090
// Address: 0x12f090 - 0x12f720
void sub_0012F090_0x12f090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012F090_0x12f090");
#endif

    switch (ctx->pc) {
        case 0x12f0d0u: goto label_12f0d0;
        case 0x12f0f4u: goto label_12f0f4;
        case 0x12f110u: goto label_12f110;
        case 0x12f140u: goto label_12f140;
        case 0x12f16cu: goto label_12f16c;
        case 0x12f198u: goto label_12f198;
        case 0x12f1bcu: goto label_12f1bc;
        case 0x12f1e8u: goto label_12f1e8;
        case 0x12f210u: goto label_12f210;
        case 0x12f238u: goto label_12f238;
        case 0x12f260u: goto label_12f260;
        case 0x12f28cu: goto label_12f28c;
        case 0x12f2b4u: goto label_12f2b4;
        case 0x12f2e8u: goto label_12f2e8;
        case 0x12f310u: goto label_12f310;
        case 0x12f338u: goto label_12f338;
        case 0x12f360u: goto label_12f360;
        case 0x12f388u: goto label_12f388;
        case 0x12f3b0u: goto label_12f3b0;
        case 0x12f3e4u: goto label_12f3e4;
        case 0x12f40cu: goto label_12f40c;
        case 0x12f428u: goto label_12f428;
        case 0x12f440u: goto label_12f440;
        case 0x12f468u: goto label_12f468;
        case 0x12f49cu: goto label_12f49c;
        case 0x12f4c0u: goto label_12f4c0;
        case 0x12f4e4u: goto label_12f4e4;
        case 0x12f508u: goto label_12f508;
        case 0x12f550u: goto label_12f550;
        case 0x12f57cu: goto label_12f57c;
        case 0x12f5a4u: goto label_12f5a4;
        case 0x12f5c4u: goto label_12f5c4;
        case 0x12f5ecu: goto label_12f5ec;
        case 0x12f610u: goto label_12f610;
        case 0x12f638u: goto label_12f638;
        case 0x12f664u: goto label_12f664;
        case 0x12f690u: goto label_12f690;
        case 0x12f6a0u: goto label_12f6a0;
        case 0x12f6d0u: goto label_12f6d0;
        default: break;
    }

    ctx->pc = 0x12f090u;

    // 0x12f090: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x12f090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x12f094: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12f094u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12f098: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x12f098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x12f09c: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x12f09cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f0a0: 0x8c44875c  lw          $a0, -0x78A4($v0)
    ctx->pc = 0x12f0a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294936412)));
    // 0x12f0a4: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12f0a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12f0a8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12f0a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x12f0ac: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x12f0acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x12f0b0: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12f0b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12f0b4: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x12f0b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x12f0b8: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x12f0b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x12f0bc: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x12f0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x12f0c0: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x12f0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x12f0c4: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x12f0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x12f0c8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x12F0C8u;
    SET_GPR_U32(ctx, 31, 0x12F0D0u);
    ctx->pc = 0x12F0CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F0C8u;
            // 0x12f0cc: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F0D0u; }
        if (ctx->pc != 0x12F0D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F0D0u; }
        if (ctx->pc != 0x12F0D0u) { return; }
    }
    ctx->pc = 0x12F0D0u;
label_12f0d0:
    // 0x12f0d0: 0x40f02d  daddu       $fp, $v0, $zero
    ctx->pc = 0x12f0d0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f0d4: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x12f0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12f0d8: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x12f0d8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x12f0dc: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x12f0dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f0e0: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x12f0e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x12f0e4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x12f0e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f0e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12f0e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f0ec: 0x60f809  jalr        $v1
    ctx->pc = 0x12F0ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12F0F4u);
        ctx->pc = 0x12F0F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F0ECu;
            // 0x12f0f0: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12F0F4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F0D0u: goto label_12f0d0;
            case 0x12F0F4u: goto label_12f0f4;
            case 0x12F110u: goto label_12f110;
            case 0x12F140u: goto label_12f140;
            case 0x12F16Cu: goto label_12f16c;
            case 0x12F198u: goto label_12f198;
            case 0x12F1BCu: goto label_12f1bc;
            case 0x12F1E8u: goto label_12f1e8;
            case 0x12F210u: goto label_12f210;
            case 0x12F238u: goto label_12f238;
            case 0x12F260u: goto label_12f260;
            case 0x12F28Cu: goto label_12f28c;
            case 0x12F2B4u: goto label_12f2b4;
            case 0x12F2D0u: goto label_12f2d0;
            case 0x12F2D4u: goto label_12f2d4;
            case 0x12F2E8u: goto label_12f2e8;
            case 0x12F310u: goto label_12f310;
            case 0x12F338u: goto label_12f338;
            case 0x12F360u: goto label_12f360;
            case 0x12F388u: goto label_12f388;
            case 0x12F3B0u: goto label_12f3b0;
            case 0x12F3E4u: goto label_12f3e4;
            case 0x12F40Cu: goto label_12f40c;
            case 0x12F428u: goto label_12f428;
            case 0x12F440u: goto label_12f440;
            case 0x12F468u: goto label_12f468;
            case 0x12F49Cu: goto label_12f49c;
            case 0x12F4C0u: goto label_12f4c0;
            case 0x12F4E4u: goto label_12f4e4;
            case 0x12F508u: goto label_12f508;
            case 0x12F520u: goto label_12f520;
            case 0x12F550u: goto label_12f550;
            case 0x12F560u: goto label_12f560;
            case 0x12F57Cu: goto label_12f57c;
            case 0x12F5A4u: goto label_12f5a4;
            case 0x12F5C4u: goto label_12f5c4;
            case 0x12F5ECu: goto label_12f5ec;
            case 0x12F610u: goto label_12f610;
            case 0x12F638u: goto label_12f638;
            case 0x12F664u: goto label_12f664;
            case 0x12F674u: goto label_12f674;
            case 0x12F690u: goto label_12f690;
            case 0x12F6A0u: goto label_12f6a0;
            case 0x12F6B8u: goto label_12f6b8;
            case 0x12F6D0u: goto label_12f6d0;
            case 0x12F6E8u: goto label_12f6e8;
            case 0x12F6ECu: goto label_12f6ec;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12F0F4u; }
            if (ctx->pc != 0x12F0F4u) { return; }
        }
        }
    }
    ctx->pc = 0x12F0F4u;
label_12f0f4:
    // 0x12f0f4: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x12f0f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12f0f8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x12f0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f0fc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12f0fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f100: 0x8c47001c  lw          $a3, 0x1C($v0)
    ctx->pc = 0x12f100u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x12f104: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12f104u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f108: 0xe0f809  jalr        $a3
    ctx->pc = 0x12F108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 7);
        SET_GPR_U32(ctx, 31, 0x12F110u);
        ctx->pc = 0x12F10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F108u;
            // 0x12f10c: 0x8fb00004  lw          $s0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12F110u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F0D0u: goto label_12f0d0;
            case 0x12F0F4u: goto label_12f0f4;
            case 0x12F110u: goto label_12f110;
            case 0x12F140u: goto label_12f140;
            case 0x12F16Cu: goto label_12f16c;
            case 0x12F198u: goto label_12f198;
            case 0x12F1BCu: goto label_12f1bc;
            case 0x12F1E8u: goto label_12f1e8;
            case 0x12F210u: goto label_12f210;
            case 0x12F238u: goto label_12f238;
            case 0x12F260u: goto label_12f260;
            case 0x12F28Cu: goto label_12f28c;
            case 0x12F2B4u: goto label_12f2b4;
            case 0x12F2D0u: goto label_12f2d0;
            case 0x12F2D4u: goto label_12f2d4;
            case 0x12F2E8u: goto label_12f2e8;
            case 0x12F310u: goto label_12f310;
            case 0x12F338u: goto label_12f338;
            case 0x12F360u: goto label_12f360;
            case 0x12F388u: goto label_12f388;
            case 0x12F3B0u: goto label_12f3b0;
            case 0x12F3E4u: goto label_12f3e4;
            case 0x12F40Cu: goto label_12f40c;
            case 0x12F428u: goto label_12f428;
            case 0x12F440u: goto label_12f440;
            case 0x12F468u: goto label_12f468;
            case 0x12F49Cu: goto label_12f49c;
            case 0x12F4C0u: goto label_12f4c0;
            case 0x12F4E4u: goto label_12f4e4;
            case 0x12F508u: goto label_12f508;
            case 0x12F520u: goto label_12f520;
            case 0x12F550u: goto label_12f550;
            case 0x12F560u: goto label_12f560;
            case 0x12F57Cu: goto label_12f57c;
            case 0x12F5A4u: goto label_12f5a4;
            case 0x12F5C4u: goto label_12f5c4;
            case 0x12F5ECu: goto label_12f5ec;
            case 0x12F610u: goto label_12f610;
            case 0x12F638u: goto label_12f638;
            case 0x12F664u: goto label_12f664;
            case 0x12F674u: goto label_12f674;
            case 0x12F690u: goto label_12f690;
            case 0x12F6A0u: goto label_12f6a0;
            case 0x12F6B8u: goto label_12f6b8;
            case 0x12F6D0u: goto label_12f6d0;
            case 0x12F6E8u: goto label_12f6e8;
            case 0x12F6ECu: goto label_12f6ec;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12F110u; }
            if (ctx->pc != 0x12F110u) { return; }
        }
        }
    }
    ctx->pc = 0x12F110u;
label_12f110:
    // 0x12f110: 0x8e830048  lw          $v1, 0x48($s4)
    ctx->pc = 0x12f110u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
    // 0x12f114: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x12f114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x12f118: 0x203802a  slt         $s0, $s0, $v1
    ctx->pc = 0x12f118u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12f11c: 0x16000173  bnez        $s0, . + 4 + (0x173 << 2)
    ctx->pc = 0x12F11Cu;
    {
        const bool branch_taken_0x12f11c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F11Cu;
            // 0x12f120: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f11c) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F124u;
    // 0x12f124: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x12f124u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x12f128: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x12f128u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x12f12c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f12cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f130: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f130u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f134: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f134u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f138: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F138u;
    SET_GPR_U32(ctx, 31, 0x12F140u);
    ctx->pc = 0x12F13Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F138u;
            // 0x12f13c: 0xa7a20010  sh          $v0, 0x10($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 16), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F140u; }
        if (ctx->pc != 0x12F140u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F140u; }
        if (ctx->pc != 0x12F140u) { return; }
    }
    ctx->pc = 0x12F140u;
label_12f140:
    // 0x12f140: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f140u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f144: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12f144u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f148: 0x16220168  bne         $s1, $v0, . + 4 + (0x168 << 2)
    ctx->pc = 0x12F148u;
    {
        const bool branch_taken_0x12f148 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x12F14Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F148u;
            // 0x12f14c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f148) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F150u;
    // 0x12f150: 0x86820048  lh          $v0, 0x48($s4)
    ctx->pc = 0x12f150u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 72)));
    // 0x12f154: 0x27a40012  addiu       $a0, $sp, 0x12
    ctx->pc = 0x12f154u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 18));
    // 0x12f158: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f158u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f15c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f15cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f160: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f160u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f164: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F164u;
    SET_GPR_U32(ctx, 31, 0x12F16Cu);
    ctx->pc = 0x12F168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F164u;
            // 0x12f168: 0xa7a20012  sh          $v0, 0x12($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 18), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F16Cu; }
        if (ctx->pc != 0x12F16Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F16Cu; }
        if (ctx->pc != 0x12F16Cu) { return; }
    }
    ctx->pc = 0x12F16Cu;
label_12f16c:
    // 0x12f16c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f16cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f170: 0x1611015e  bne         $s0, $s1, . + 4 + (0x15E << 2)
    ctx->pc = 0x12F170u;
    {
        const bool branch_taken_0x12f170 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F170u;
            // 0x12f174: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f170) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F178u;
    // 0x12f178: 0x8282004c  lb          $v0, 0x4C($s4)
    ctx->pc = 0x12f178u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 76)));
    // 0x12f17c: 0x27b70014  addiu       $s7, $sp, 0x14
    ctx->pc = 0x12f17cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x12f180: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12f180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f184: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f184u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f188: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f188u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f18c: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f18cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f190: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F190u;
    SET_GPR_U32(ctx, 31, 0x12F198u);
    ctx->pc = 0x12F194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F190u;
            // 0x12f194: 0xa3a20014  sb          $v0, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F198u; }
        if (ctx->pc != 0x12F198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F198u; }
        if (ctx->pc != 0x12F198u) { return; }
    }
    ctx->pc = 0x12F198u;
label_12f198:
    // 0x12f198: 0x14500154  bne         $v0, $s0, . + 4 + (0x154 << 2)
    ctx->pc = 0x12F198u;
    {
        const bool branch_taken_0x12f198 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F198u;
            // 0x12f19c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f198) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F1A0u;
    // 0x12f1a0: 0x92820050  lbu         $v0, 0x50($s4)
    ctx->pc = 0x12f1a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 80)));
    // 0x12f1a4: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12f1a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f1a8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f1a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f1ac: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f1acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f1b0: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f1b0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f1b4: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F1B4u;
    SET_GPR_U32(ctx, 31, 0x12F1BCu);
    ctx->pc = 0x12F1B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F1B4u;
            // 0x12f1b8: 0xa3a20014  sb          $v0, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F1BCu; }
        if (ctx->pc != 0x12F1BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F1BCu; }
        if (ctx->pc != 0x12F1BCu) { return; }
    }
    ctx->pc = 0x12F1BCu;
label_12f1bc:
    // 0x12f1bc: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x12f1bcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f1c0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f1c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f1c4: 0x16320149  bne         $s1, $s2, . + 4 + (0x149 << 2)
    ctx->pc = 0x12F1C4u;
    {
        const bool branch_taken_0x12f1c4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 18));
        ctx->pc = 0x12F1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F1C4u;
            // 0x12f1c8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f1c4) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F1CCu;
    // 0x12f1cc: 0x92820054  lbu         $v0, 0x54($s4)
    ctx->pc = 0x12f1ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 84)));
    // 0x12f1d0: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12f1d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f1d4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f1d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f1d8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f1d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f1dc: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f1dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f1e0: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F1E0u;
    SET_GPR_U32(ctx, 31, 0x12F1E8u);
    ctx->pc = 0x12F1E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F1E0u;
            // 0x12f1e4: 0xa3a20014  sb          $v0, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F1E8u; }
        if (ctx->pc != 0x12F1E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F1E8u; }
        if (ctx->pc != 0x12F1E8u) { return; }
    }
    ctx->pc = 0x12F1E8u;
label_12f1e8:
    // 0x12f1e8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f1e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f1ec: 0x1611013f  bne         $s0, $s1, . + 4 + (0x13F << 2)
    ctx->pc = 0x12F1ECu;
    {
        const bool branch_taken_0x12f1ec = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F1ECu;
            // 0x12f1f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f1ec) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F1F4u;
    // 0x12f1f4: 0x92820058  lbu         $v0, 0x58($s4)
    ctx->pc = 0x12f1f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 88)));
    // 0x12f1f8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12f1f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f1fc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f1fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f200: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f200u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f204: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f204u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f208: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F208u;
    SET_GPR_U32(ctx, 31, 0x12F210u);
    ctx->pc = 0x12F20Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F208u;
            // 0x12f20c: 0xa3a20014  sb          $v0, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F210u; }
        if (ctx->pc != 0x12F210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F210u; }
        if (ctx->pc != 0x12F210u) { return; }
    }
    ctx->pc = 0x12F210u;
label_12f210:
    // 0x12f210: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f210u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f214: 0x16300135  bne         $s1, $s0, . + 4 + (0x135 << 2)
    ctx->pc = 0x12F214u;
    {
        const bool branch_taken_0x12f214 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F214u;
            // 0x12f218: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f214) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F21Cu;
    // 0x12f21c: 0x8e82005c  lw          $v0, 0x5C($s4)
    ctx->pc = 0x12f21cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 92)));
    // 0x12f220: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f224: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f224u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f228: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f228u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f22c: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f22cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f230: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F230u;
    SET_GPR_U32(ctx, 31, 0x12F238u);
    ctx->pc = 0x12F234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F230u;
            // 0x12f234: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F238u; }
        if (ctx->pc != 0x12F238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F238u; }
        if (ctx->pc != 0x12F238u) { return; }
    }
    ctx->pc = 0x12F238u;
label_12f238:
    // 0x12f238: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f238u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f23c: 0x1611012b  bne         $s0, $s1, . + 4 + (0x12B << 2)
    ctx->pc = 0x12F23Cu;
    {
        const bool branch_taken_0x12f23c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F23Cu;
            // 0x12f240: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f23c) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F244u;
    // 0x12f244: 0x8e820060  lw          $v0, 0x60($s4)
    ctx->pc = 0x12f244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 96)));
    // 0x12f248: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f248u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f24c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f24cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f250: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f250u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f254: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f254u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f258: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F258u;
    SET_GPR_U32(ctx, 31, 0x12F260u);
    ctx->pc = 0x12F25Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F258u;
            // 0x12f25c: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F260u; }
        if (ctx->pc != 0x12F260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F260u; }
        if (ctx->pc != 0x12F260u) { return; }
    }
    ctx->pc = 0x12F260u;
label_12f260:
    // 0x12f260: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f260u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f264: 0x16300121  bne         $s1, $s0, . + 4 + (0x121 << 2)
    ctx->pc = 0x12F264u;
    {
        const bool branch_taken_0x12f264 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F264u;
            // 0x12f268: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f264) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F26Cu;
    // 0x12f26c: 0x86820064  lh          $v0, 0x64($s4)
    ctx->pc = 0x12f26cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 100)));
    // 0x12f270: 0x27b60016  addiu       $s6, $sp, 0x16
    ctx->pc = 0x12f270u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 29), 22));
    // 0x12f274: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f274u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f278: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f278u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f27c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f27cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f280: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f280u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f284: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F284u;
    SET_GPR_U32(ctx, 31, 0x12F28Cu);
    ctx->pc = 0x12F288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F284u;
            // 0x12f288: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F28Cu; }
        if (ctx->pc != 0x12F28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F28Cu; }
        if (ctx->pc != 0x12F28Cu) { return; }
    }
    ctx->pc = 0x12F28Cu;
label_12f28c:
    // 0x12f28c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f28cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f290: 0x16110116  bne         $s0, $s1, . + 4 + (0x116 << 2)
    ctx->pc = 0x12F290u;
    {
        const bool branch_taken_0x12f290 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F290u;
            // 0x12f294: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f290) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F298u;
    // 0x12f298: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x12f298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f29c: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12f29cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f2a0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f2a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f2a4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f2a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f2a8: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f2a8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f2ac: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F2ACu;
    SET_GPR_U32(ctx, 31, 0x12F2B4u);
    ctx->pc = 0x12F2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F2ACu;
            // 0x12f2b0: 0xa3a20014  sb          $v0, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F2B4u; }
        if (ctx->pc != 0x12F2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F2B4u; }
        if (ctx->pc != 0x12F2B4u) { return; }
    }
    ctx->pc = 0x12F2B4u;
label_12f2b4:
    // 0x12f2b4: 0x1450010d  bne         $v0, $s0, . + 4 + (0x10D << 2)
    ctx->pc = 0x12F2B4u;
    {
        const bool branch_taken_0x12f2b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F2B4u;
            // 0x12f2b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f2b4) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F2BCu;
    // 0x12f2bc: 0x868202d0  lh          $v0, 0x2D0($s4)
    ctx->pc = 0x12f2bcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 720)));
    // 0x12f2c0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12F2C0u;
    {
        const bool branch_taken_0x12f2c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F2C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F2C0u;
            // 0x12f2c4: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f2c0) {
            ctx->pc = 0x12F2D0u;
            goto label_12f2d0;
        }
    }
    ctx->pc = 0x12F2C8u;
    // 0x12f2c8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12F2C8u;
    {
        const bool branch_taken_0x12f2c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12F2CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F2C8u;
            // 0x12f2cc: 0xa3a00014  sb          $zero, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f2c8) {
            ctx->pc = 0x12F2D4u;
            goto label_12f2d4;
        }
    }
    ctx->pc = 0x12F2D0u;
label_12f2d0:
    // 0x12f2d0: 0xa3a20014  sb          $v0, 0x14($sp)
    ctx->pc = 0x12f2d0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 2));
label_12f2d4:
    // 0x12f2d4: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12f2d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f2d8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f2d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f2dc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f2dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f2e0: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F2E0u;
    SET_GPR_U32(ctx, 31, 0x12F2E8u);
    ctx->pc = 0x12F2E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F2E0u;
            // 0x12f2e4: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F2E8u; }
        if (ctx->pc != 0x12F2E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F2E8u; }
        if (ctx->pc != 0x12F2E8u) { return; }
    }
    ctx->pc = 0x12F2E8u;
label_12f2e8:
    // 0x12f2e8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f2e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f2ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12f2ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f2f0: 0x160200fe  bne         $s0, $v0, . + 4 + (0xFE << 2)
    ctx->pc = 0x12F2F0u;
    {
        const bool branch_taken_0x12f2f0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x12F2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F2F0u;
            // 0x12f2f4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f2f0) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F2F8u;
    // 0x12f2f8: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f2fc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f2fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f300: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f300u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f304: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f304u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f308: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F308u;
    SET_GPR_U32(ctx, 31, 0x12F310u);
    ctx->pc = 0x12F30Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F308u;
            // 0x12f30c: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F310u; }
        if (ctx->pc != 0x12F310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F310u; }
        if (ctx->pc != 0x12F310u) { return; }
    }
    ctx->pc = 0x12F310u;
label_12f310:
    // 0x12f310: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f310u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f314: 0x163000f5  bne         $s1, $s0, . + 4 + (0xF5 << 2)
    ctx->pc = 0x12F314u;
    {
        const bool branch_taken_0x12f314 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F314u;
            // 0x12f318: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f314) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F31Cu;
    // 0x12f31c: 0x968202c8  lhu         $v0, 0x2C8($s4)
    ctx->pc = 0x12f31cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 712)));
    // 0x12f320: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f320u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f324: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f324u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f328: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f328u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f32c: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f32cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f330: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F330u;
    SET_GPR_U32(ctx, 31, 0x12F338u);
    ctx->pc = 0x12F334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F330u;
            // 0x12f334: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F338u; }
        if (ctx->pc != 0x12F338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F338u; }
        if (ctx->pc != 0x12F338u) { return; }
    }
    ctx->pc = 0x12F338u;
label_12f338:
    // 0x12f338: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f338u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f33c: 0x161100eb  bne         $s0, $s1, . + 4 + (0xEB << 2)
    ctx->pc = 0x12F33Cu;
    {
        const bool branch_taken_0x12f33c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F33Cu;
            // 0x12f340: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f33c) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F344u;
    // 0x12f344: 0x968202cc  lhu         $v0, 0x2CC($s4)
    ctx->pc = 0x12f344u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 716)));
    // 0x12f348: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f348u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f34c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f34cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f350: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f350u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f354: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f354u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f358: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F358u;
    SET_GPR_U32(ctx, 31, 0x12F360u);
    ctx->pc = 0x12F35Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F358u;
            // 0x12f35c: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F360u; }
        if (ctx->pc != 0x12F360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F360u; }
        if (ctx->pc != 0x12F360u) { return; }
    }
    ctx->pc = 0x12F360u;
label_12f360:
    // 0x12f360: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f360u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f364: 0x163000e1  bne         $s1, $s0, . + 4 + (0xE1 << 2)
    ctx->pc = 0x12F364u;
    {
        const bool branch_taken_0x12f364 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F364u;
            // 0x12f368: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f364) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F36Cu;
    // 0x12f36c: 0x968202ca  lhu         $v0, 0x2CA($s4)
    ctx->pc = 0x12f36cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 714)));
    // 0x12f370: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f370u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f374: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f374u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f378: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f378u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f37c: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f37cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f380: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F380u;
    SET_GPR_U32(ctx, 31, 0x12F388u);
    ctx->pc = 0x12F384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F380u;
            // 0x12f384: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F388u; }
        if (ctx->pc != 0x12F388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F388u; }
        if (ctx->pc != 0x12F388u) { return; }
    }
    ctx->pc = 0x12F388u;
label_12f388:
    // 0x12f388: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f388u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f38c: 0x161100d7  bne         $s0, $s1, . + 4 + (0xD7 << 2)
    ctx->pc = 0x12F38Cu;
    {
        const bool branch_taken_0x12f38c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F38Cu;
            // 0x12f390: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f38c) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F394u;
    // 0x12f394: 0x968202ce  lhu         $v0, 0x2CE($s4)
    ctx->pc = 0x12f394u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 718)));
    // 0x12f398: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f398u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f39c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f39cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f3a0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f3a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f3a4: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f3a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f3a8: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F3A8u;
    SET_GPR_U32(ctx, 31, 0x12F3B0u);
    ctx->pc = 0x12F3ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F3A8u;
            // 0x12f3ac: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F3B0u; }
        if (ctx->pc != 0x12F3B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F3B0u; }
        if (ctx->pc != 0x12F3B0u) { return; }
    }
    ctx->pc = 0x12F3B0u;
label_12f3b0:
    // 0x12f3b0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f3b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f3b4: 0x163000cd  bne         $s1, $s0, . + 4 + (0xCD << 2)
    ctx->pc = 0x12F3B4u;
    {
        const bool branch_taken_0x12f3b4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F3B4u;
            // 0x12f3b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f3b4) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F3BCu;
    // 0x12f3bc: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x12f3bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x12f3c0: 0x18600057  blez        $v1, . + 4 + (0x57 << 2)
    ctx->pc = 0x12F3C0u;
    {
        const bool branch_taken_0x12f3c0 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12F3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F3C0u;
            // 0x12f3c4: 0x2412001c  addiu       $s2, $zero, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f3c0) {
            ctx->pc = 0x12F520u;
            goto label_12f520;
        }
    }
    ctx->pc = 0x12F3C8u;
    // 0x12f3c8: 0x96820068  lhu         $v0, 0x68($s4)
    ctx->pc = 0x12f3c8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 104)));
    // 0x12f3cc: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f3ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f3d0: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f3d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f3d4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f3d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f3d8: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f3d8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f3dc: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F3DCu;
    SET_GPR_U32(ctx, 31, 0x12F3E4u);
    ctx->pc = 0x12F3E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F3DCu;
            // 0x12f3e0: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F3E4u; }
        if (ctx->pc != 0x12F3E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F3E4u; }
        if (ctx->pc != 0x12F3E4u) { return; }
    }
    ctx->pc = 0x12F3E4u;
label_12f3e4:
    // 0x12f3e4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f3e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f3e8: 0x161100c0  bne         $s0, $s1, . + 4 + (0xC0 << 2)
    ctx->pc = 0x12F3E8u;
    {
        const bool branch_taken_0x12f3e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F3E8u;
            // 0x12f3ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f3e8) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F3F0u;
    // 0x12f3f0: 0x9682006c  lhu         $v0, 0x6C($s4)
    ctx->pc = 0x12f3f0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x12f3f4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f3f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f3f8: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f3f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f3fc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f3fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f400: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f400u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f404: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F404u;
    SET_GPR_U32(ctx, 31, 0x12F40Cu);
    ctx->pc = 0x12F408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F404u;
            // 0x12f408: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F40Cu; }
        if (ctx->pc != 0x12F40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F40Cu; }
        if (ctx->pc != 0x12F40Cu) { return; }
    }
    ctx->pc = 0x12F40Cu;
label_12f40c:
    // 0x12f40c: 0x145000b7  bne         $v0, $s0, . + 4 + (0xB7 << 2)
    ctx->pc = 0x12F40Cu;
    {
        const bool branch_taken_0x12f40c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F40Cu;
            // 0x12f410: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f40c) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F414u;
    // 0x12f414: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x12f414u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x12f418: 0x24120020  addiu       $s2, $zero, 0x20
    ctx->pc = 0x12f418u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x12f41c: 0x18600040  blez        $v1, . + 4 + (0x40 << 2)
    ctx->pc = 0x12F41Cu;
    {
        const bool branch_taken_0x12f41c = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12F420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F41Cu;
            // 0x12f420: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f41c) {
            ctx->pc = 0x12F520u;
            goto label_12f520;
        }
    }
    ctx->pc = 0x12F424u;
    // 0x12f424: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f424u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_12f428:
    // 0x12f428: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f428u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f42c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f42cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f430: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f430u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f434: 0xa7b50016  sh          $s5, 0x16($sp)
    ctx->pc = 0x12f434u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 21));
    // 0x12f438: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F438u;
    SET_GPR_U32(ctx, 31, 0x12F440u);
    ctx->pc = 0x12F43Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F438u;
            // 0x12f43c: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F440u; }
        if (ctx->pc != 0x12F440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F440u; }
        if (ctx->pc != 0x12F440u) { return; }
    }
    ctx->pc = 0x12F440u;
label_12f440:
    // 0x12f440: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f440u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f444: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f444u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f448: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f448u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f44c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f44cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f450: 0x160600a5  bne         $s0, $a2, . + 4 + (0xA5 << 2)
    ctx->pc = 0x12F450u;
    {
        const bool branch_taken_0x12f450 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 6));
        ctx->pc = 0x12F454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F450u;
            // 0x12f454: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f450) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F458u;
    // 0x12f458: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x12f458u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x12f45c: 0xa7b00016  sh          $s0, 0x16($sp)
    ctx->pc = 0x12f45cu;
    WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 16));
    // 0x12f460: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F460u;
    SET_GPR_U32(ctx, 31, 0x12F468u);
    ctx->pc = 0x12F464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F460u;
            // 0x12f464: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F468u; }
        if (ctx->pc != 0x12F468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F468u; }
        if (ctx->pc != 0x12F468u) { return; }
    }
    ctx->pc = 0x12F468u;
label_12f468:
    // 0x12f468: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x12f468u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x12f46c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f46cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f470: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x12f470u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x12f474: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f474u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f478: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x12f478u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x12f47c: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f47cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f480: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x12f480u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x12f484: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f484u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f488: 0x16300097  bne         $s1, $s0, . + 4 + (0x97 << 2)
    ctx->pc = 0x12F488u;
    {
        const bool branch_taken_0x12f488 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F488u;
            // 0x12f48c: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f488) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F490u;
    // 0x12f490: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x12f490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x12f494: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F494u;
    SET_GPR_U32(ctx, 31, 0x12F49Cu);
    ctx->pc = 0x12F498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F494u;
            // 0x12f498: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F49Cu; }
        if (ctx->pc != 0x12F49Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F49Cu; }
        if (ctx->pc != 0x12F49Cu) { return; }
    }
    ctx->pc = 0x12F49Cu;
label_12f49c:
    // 0x12f49c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f49cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f4a0: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f4a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f4a4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f4a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f4a8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f4a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f4ac: 0x1611008e  bne         $s0, $s1, . + 4 + (0x8E << 2)
    ctx->pc = 0x12F4ACu;
    {
        const bool branch_taken_0x12f4ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F4ACu;
            // 0x12f4b0: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f4ac) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F4B4u;
    // 0x12f4b4: 0x8e820074  lw          $v0, 0x74($s4)
    ctx->pc = 0x12f4b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x12f4b8: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F4B8u;
    SET_GPR_U32(ctx, 31, 0x12F4C0u);
    ctx->pc = 0x12F4BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F4B8u;
            // 0x12f4bc: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F4C0u; }
        if (ctx->pc != 0x12F4C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F4C0u; }
        if (ctx->pc != 0x12F4C0u) { return; }
    }
    ctx->pc = 0x12F4C0u;
label_12f4c0:
    // 0x12f4c0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f4c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f4c4: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f4c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f4c8: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f4c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f4cc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f4ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f4d0: 0x16300085  bne         $s1, $s0, . + 4 + (0x85 << 2)
    ctx->pc = 0x12F4D0u;
    {
        const bool branch_taken_0x12f4d0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F4D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F4D0u;
            // 0x12f4d4: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f4d0) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F4D8u;
    // 0x12f4d8: 0x8e820078  lw          $v0, 0x78($s4)
    ctx->pc = 0x12f4d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 120)));
    // 0x12f4dc: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F4DCu;
    SET_GPR_U32(ctx, 31, 0x12F4E4u);
    ctx->pc = 0x12F4E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F4DCu;
            // 0x12f4e0: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F4E4u; }
        if (ctx->pc != 0x12F4E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F4E4u; }
        if (ctx->pc != 0x12F4E4u) { return; }
    }
    ctx->pc = 0x12F4E4u;
label_12f4e4:
    // 0x12f4e4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f4e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f4e8: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f4e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f4ec: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f4ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f4f0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f4f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f4f4: 0x1611007c  bne         $s0, $s1, . + 4 + (0x7C << 2)
    ctx->pc = 0x12F4F4u;
    {
        const bool branch_taken_0x12f4f4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F4F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F4F4u;
            // 0x12f4f8: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f4f4) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F4FCu;
    // 0x12f4fc: 0x8e82007c  lw          $v0, 0x7C($s4)
    ctx->pc = 0x12f4fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 124)));
    // 0x12f500: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F500u;
    SET_GPR_U32(ctx, 31, 0x12F508u);
    ctx->pc = 0x12F504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F500u;
            // 0x12f504: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F508u; }
        if (ctx->pc != 0x12F508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F508u; }
        if (ctx->pc != 0x12F508u) { return; }
    }
    ctx->pc = 0x12F508u;
label_12f508:
    // 0x12f508: 0x14500078  bne         $v0, $s0, . + 4 + (0x78 << 2)
    ctx->pc = 0x12F508u;
    {
        const bool branch_taken_0x12f508 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F508u;
            // 0x12f50c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f508) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F510u;
    // 0x12f510: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x12f510u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x12f514: 0x2a3102a  slt         $v0, $s5, $v1
    ctx->pc = 0x12f514u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12f518: 0x1440ffc3  bnez        $v0, . + 4 + (-0x3D << 2)
    ctx->pc = 0x12F518u;
    {
        const bool branch_taken_0x12f518 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F51Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F518u;
            // 0x12f51c: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f518) {
            ctx->pc = 0x12F428u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12f428;
        }
    }
    ctx->pc = 0x12F520u;
label_12f520:
    // 0x12f520: 0x829002d6  lb          $s0, 0x2D6($s4)
    ctx->pc = 0x12f520u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 726)));
    // 0x12f524: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12f524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f528: 0x56020052  bnel        $s0, $v0, . + 4 + (0x52 << 2)
    ctx->pc = 0x12F528u;
    {
        const bool branch_taken_0x12f528 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x12f528) {
            ctx->pc = 0x12F52Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12F528u;
            // 0x12f52c: 0x8e830048  lw          $v1, 0x48($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12F674u;
            goto label_12f674;
        }
    }
    ctx->pc = 0x12F530u;
    // 0x12f530: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x12F530u;
    {
        const bool branch_taken_0x12f530 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F530u;
            // 0x12f534: 0x3c024149  lui         $v0, 0x4149 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16713 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f530) {
            ctx->pc = 0x12F560u;
            goto label_12f560;
        }
    }
    ctx->pc = 0x12F538u;
    // 0x12f538: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f538u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f53c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f53cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f540: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f540u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f544: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f544u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f548: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F548u;
    SET_GPR_U32(ctx, 31, 0x12F550u);
    ctx->pc = 0x12F54Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F548u;
            // 0x12f54c: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F550u; }
        if (ctx->pc != 0x12F550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F550u; }
        if (ctx->pc != 0x12F550u) { return; }
    }
    ctx->pc = 0x12F550u;
label_12f550:
    // 0x12f550: 0x14500066  bne         $v0, $s0, . + 4 + (0x66 << 2)
    ctx->pc = 0x12F550u;
    {
        const bool branch_taken_0x12f550 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F550u;
            // 0x12f554: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f550) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F558u;
    // 0x12f558: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x12f558u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x12f55c: 0x3c024149  lui         $v0, 0x4149
    ctx->pc = 0x12f55cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16713 << 16));
label_12f560:
    // 0x12f560: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f564: 0x34424e46  ori         $v0, $v0, 0x4E46
    ctx->pc = 0x12f564u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)20038);
    // 0x12f568: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f568u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f56c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f56cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f570: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f570u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f574: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F574u;
    SET_GPR_U32(ctx, 31, 0x12F57Cu);
    ctx->pc = 0x12F578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F574u;
            // 0x12f578: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F57Cu; }
        if (ctx->pc != 0x12F57Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F57Cu; }
        if (ctx->pc != 0x12F57Cu) { return; }
    }
    ctx->pc = 0x12F57Cu;
label_12f57c:
    // 0x12f57c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f57cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f580: 0x1630005a  bne         $s1, $s0, . + 4 + (0x5A << 2)
    ctx->pc = 0x12F580u;
    {
        const bool branch_taken_0x12f580 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F580u;
            // 0x12f584: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f580) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F588u;
    // 0x12f588: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x12f588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x12f58c: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x12f58cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12f590: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x12f590u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12f594: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f594u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f598: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f598u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f59c: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F59Cu;
    SET_GPR_U32(ctx, 31, 0x12F5A4u);
    ctx->pc = 0x12F5A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F59Cu;
            // 0x12f5a0: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F5A4u; }
        if (ctx->pc != 0x12F5A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F5A4u; }
        if (ctx->pc != 0x12F5A4u) { return; }
    }
    ctx->pc = 0x12F5A4u;
label_12f5a4:
    // 0x12f5a4: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x12f5a4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f5a8: 0x16b1004f  bne         $s5, $s1, . + 4 + (0x4F << 2)
    ctx->pc = 0x12F5A8u;
    {
        const bool branch_taken_0x12f5a8 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F5ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F5A8u;
            // 0x12f5ac: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f5a8) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F5B0u;
    // 0x12f5b0: 0x268402d7  addiu       $a0, $s4, 0x2D7
    ctx->pc = 0x12f5b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 727));
    // 0x12f5b4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f5b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f5b8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x12f5b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12f5bc: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F5BCu;
    SET_GPR_U32(ctx, 31, 0x12F5C4u);
    ctx->pc = 0x12F5C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F5BCu;
            // 0x12f5c0: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F5C4u; }
        if (ctx->pc != 0x12F5C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F5C4u; }
        if (ctx->pc != 0x12F5C4u) { return; }
    }
    ctx->pc = 0x12F5C4u;
label_12f5c4:
    // 0x12f5c4: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x12f5c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12f5c8: 0x14430047  bne         $v0, $v1, . + 4 + (0x47 << 2)
    ctx->pc = 0x12F5C8u;
    {
        const bool branch_taken_0x12f5c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x12F5CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F5C8u;
            // 0x12f5cc: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f5c8) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F5D0u;
    // 0x12f5d0: 0x968202e8  lhu         $v0, 0x2E8($s4)
    ctx->pc = 0x12f5d0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 744)));
    // 0x12f5d4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f5d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f5d8: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f5d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f5dc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f5dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f5e0: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f5e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f5e4: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F5E4u;
    SET_GPR_U32(ctx, 31, 0x12F5ECu);
    ctx->pc = 0x12F5E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F5E4u;
            // 0x12f5e8: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F5ECu; }
        if (ctx->pc != 0x12F5ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F5ECu; }
        if (ctx->pc != 0x12F5ECu) { return; }
    }
    ctx->pc = 0x12F5ECu;
label_12f5ec:
    // 0x12f5ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f5ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f5f0: 0x1615003d  bne         $s0, $s5, . + 4 + (0x3D << 2)
    ctx->pc = 0x12F5F0u;
    {
        const bool branch_taken_0x12f5f0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 21));
        ctx->pc = 0x12F5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F5F0u;
            // 0x12f5f4: 0x26520010  addiu       $s2, $s2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f5f0) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F5F8u;
    // 0x12f5f8: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f5f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f5fc: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f5fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f600: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f600u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f604: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f604u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f608: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F608u;
    SET_GPR_U32(ctx, 31, 0x12F610u);
    ctx->pc = 0x12F60Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F608u;
            // 0x12f60c: 0xa7a00016  sh          $zero, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F610u; }
        if (ctx->pc != 0x12F610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F610u; }
        if (ctx->pc != 0x12F610u) { return; }
    }
    ctx->pc = 0x12F610u;
label_12f610:
    // 0x12f610: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12f610u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f614: 0x16300034  bne         $s1, $s0, . + 4 + (0x34 << 2)
    ctx->pc = 0x12F614u;
    {
        const bool branch_taken_0x12f614 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F614u;
            // 0x12f618: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f614) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F61Cu;
    // 0x12f61c: 0x968202ea  lhu         $v0, 0x2EA($s4)
    ctx->pc = 0x12f61cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 746)));
    // 0x12f620: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f620u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f624: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f624u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f628: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f628u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f62c: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f62cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f630: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F630u;
    SET_GPR_U32(ctx, 31, 0x12F638u);
    ctx->pc = 0x12F634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F630u;
            // 0x12f634: 0xa7a20016  sh          $v0, 0x16($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F638u; }
        if (ctx->pc != 0x12F638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F638u; }
        if (ctx->pc != 0x12F638u) { return; }
    }
    ctx->pc = 0x12F638u;
label_12f638:
    // 0x12f638: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12f638u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f63c: 0x1611002a  bne         $s0, $s1, . + 4 + (0x2A << 2)
    ctx->pc = 0x12F63Cu;
    {
        const bool branch_taken_0x12f63c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F63Cu;
            // 0x12f640: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f63c) {
            ctx->pc = 0x12F6E8u;
            goto label_12f6e8;
        }
    }
    ctx->pc = 0x12F644u;
    // 0x12f644: 0x968202ec  lhu         $v0, 0x2EC($s4)
    ctx->pc = 0x12f644u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 748)));
    // 0x12f648: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x12f648u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f64c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x12f64cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12f650: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f650u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f654: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f654u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f658: 0xa7a20016  sh          $v0, 0x16($sp)
    ctx->pc = 0x12f658u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 22), (uint16_t)GPR_U32(ctx, 2));
    // 0x12f65c: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F65Cu;
    SET_GPR_U32(ctx, 31, 0x12F664u);
    ctx->pc = 0x12F660u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F65Cu;
            // 0x12f660: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F664u; }
        if (ctx->pc != 0x12F664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F664u; }
        if (ctx->pc != 0x12F664u) { return; }
    }
    ctx->pc = 0x12F664u;
label_12f664:
    // 0x12f664: 0x14500021  bne         $v0, $s0, . + 4 + (0x21 << 2)
    ctx->pc = 0x12F664u;
    {
        const bool branch_taken_0x12f664 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x12F668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F664u;
            // 0x12f668: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f664) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F66Cu;
    // 0x12f66c: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x12f66cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x12f670: 0x8e830048  lw          $v1, 0x48($s4)
    ctx->pc = 0x12f670u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
label_12f674:
    // 0x12f674: 0x7e8023  subu        $s0, $v1, $fp
    ctx->pc = 0x12f674u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 30)));
    // 0x12f678: 0x250102a  slt         $v0, $s2, $s0
    ctx->pc = 0x12f678u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12f67c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x12F67Cu;
    {
        const bool branch_taken_0x12f67c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12F680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F67Cu;
            // 0x12f680: 0xa3a00014  sb          $zero, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f67c) {
            ctx->pc = 0x12F6B8u;
            goto label_12f6b8;
        }
    }
    ctx->pc = 0x12F684u;
    // 0x12f684: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12f684u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f688: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12f688u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f68c: 0x0  nop
    ctx->pc = 0x12f68cu;
    // NOP
label_12f690:
    // 0x12f690: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f690u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f694: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12f694u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f698: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F698u;
    SET_GPR_U32(ctx, 31, 0x12F6A0u);
    ctx->pc = 0x12F69Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F698u;
            // 0x12f69c: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F6A0u; }
        if (ctx->pc != 0x12F6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F6A0u; }
        if (ctx->pc != 0x12F6A0u) { return; }
    }
    ctx->pc = 0x12F6A0u;
label_12f6a0:
    // 0x12f6a0: 0x14510012  bne         $v0, $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0x12F6A0u;
    {
        const bool branch_taken_0x12f6a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x12F6A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F6A0u;
            // 0x12f6a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f6a0) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F6A8u;
    // 0x12f6a8: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x12f6a8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x12f6ac: 0x250102a  slt         $v0, $s2, $s0
    ctx->pc = 0x12f6acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12f6b0: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x12F6B0u;
    {
        const bool branch_taken_0x12f6b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12F6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F6B0u;
            // 0x12f6b4: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f6b0) {
            ctx->pc = 0x12F690u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12f690;
        }
    }
    ctx->pc = 0x12F6B8u;
label_12f6b8:
    // 0x12f6b8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12f6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12f6bc: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12f6bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f6c0: 0x8c44875c  lw          $a0, -0x78A4($v0)
    ctx->pc = 0x12f6c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294936412)));
    // 0x12f6c4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12f6c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12f6c8: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12F6C8u;
    SET_GPR_U32(ctx, 31, 0x12F6D0u);
    ctx->pc = 0x12F6CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F6C8u;
            // 0x12f6cc: 0x3c0302d  daddu       $a2, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F6D0u; }
        if (ctx->pc != 0x12F6D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F6D0u; }
        if (ctx->pc != 0x12F6D0u) { return; }
    }
    ctx->pc = 0x12F6D0u;
label_12f6d0:
    // 0x12f6d0: 0x545e0006  bnel        $v0, $fp, . + 4 + (0x6 << 2)
    ctx->pc = 0x12F6D0u;
    {
        const bool branch_taken_0x12f6d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 30));
        if (branch_taken_0x12f6d0) {
            ctx->pc = 0x12F6D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12F6D0u;
            // 0x12f6d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F6D8u;
    // 0x12f6d8: 0x25e9021  addu        $s2, $s2, $fp
    ctx->pc = 0x12f6d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 30)));
    // 0x12f6dc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12F6DCu;
    {
        const bool branch_taken_0x12f6dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12F6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F6DCu;
            // 0x12f6e0: 0x26420004  addiu       $v0, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f6dc) {
            ctx->pc = 0x12F6ECu;
            goto label_12f6ec;
        }
    }
    ctx->pc = 0x12F6E4u;
    // 0x12f6e4: 0x0  nop
    ctx->pc = 0x12f6e4u;
    // NOP
label_12f6e8:
    // 0x12f6e8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12f6e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12f6ec:
    // 0x12f6ec: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12f6ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12f6f0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12f6f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12f6f4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x12f6f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12f6f8: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x12f6f8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12f6fc: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x12f6fcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12f700: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x12f700u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12f704: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x12f704u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12f708: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x12f708u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12f70c: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x12f70cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x12f710: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x12f710u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x12f714: 0x3e00008  jr          $ra
    ctx->pc = 0x12F714u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12F718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F714u;
            // 0x12f718: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F0D0u: goto label_12f0d0;
            case 0x12F0F4u: goto label_12f0f4;
            case 0x12F110u: goto label_12f110;
            case 0x12F140u: goto label_12f140;
            case 0x12F16Cu: goto label_12f16c;
            case 0x12F198u: goto label_12f198;
            case 0x12F1BCu: goto label_12f1bc;
            case 0x12F1E8u: goto label_12f1e8;
            case 0x12F210u: goto label_12f210;
            case 0x12F238u: goto label_12f238;
            case 0x12F260u: goto label_12f260;
            case 0x12F28Cu: goto label_12f28c;
            case 0x12F2B4u: goto label_12f2b4;
            case 0x12F2D0u: goto label_12f2d0;
            case 0x12F2D4u: goto label_12f2d4;
            case 0x12F2E8u: goto label_12f2e8;
            case 0x12F310u: goto label_12f310;
            case 0x12F338u: goto label_12f338;
            case 0x12F360u: goto label_12f360;
            case 0x12F388u: goto label_12f388;
            case 0x12F3B0u: goto label_12f3b0;
            case 0x12F3E4u: goto label_12f3e4;
            case 0x12F40Cu: goto label_12f40c;
            case 0x12F428u: goto label_12f428;
            case 0x12F440u: goto label_12f440;
            case 0x12F468u: goto label_12f468;
            case 0x12F49Cu: goto label_12f49c;
            case 0x12F4C0u: goto label_12f4c0;
            case 0x12F4E4u: goto label_12f4e4;
            case 0x12F508u: goto label_12f508;
            case 0x12F520u: goto label_12f520;
            case 0x12F550u: goto label_12f550;
            case 0x12F560u: goto label_12f560;
            case 0x12F57Cu: goto label_12f57c;
            case 0x12F5A4u: goto label_12f5a4;
            case 0x12F5C4u: goto label_12f5c4;
            case 0x12F5ECu: goto label_12f5ec;
            case 0x12F610u: goto label_12f610;
            case 0x12F638u: goto label_12f638;
            case 0x12F664u: goto label_12f664;
            case 0x12F674u: goto label_12f674;
            case 0x12F690u: goto label_12f690;
            case 0x12F6A0u: goto label_12f6a0;
            case 0x12F6B8u: goto label_12f6b8;
            case 0x12F6D0u: goto label_12f6d0;
            case 0x12F6E8u: goto label_12f6e8;
            case 0x12F6ECu: goto label_12f6ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12F71Cu;
    // 0x12f71c: 0x0  nop
    ctx->pc = 0x12f71cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
