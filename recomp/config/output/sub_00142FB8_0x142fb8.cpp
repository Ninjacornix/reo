#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142FB8
// Address: 0x142fb8 - 0x143f88
void sub_00142FB8_0x142fb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142FB8_0x142fb8");
#endif

    switch (ctx->pc) {
        case 0x143030u: goto label_143030;
        case 0x143068u: goto label_143068;
        case 0x14307cu: goto label_14307c;
        case 0x1430f0u: goto label_1430f0;
        case 0x1431fcu: goto label_1431fc;
        case 0x143270u: goto label_143270;
        case 0x143278u: goto label_143278;
        case 0x14332cu: goto label_14332c;
        case 0x1433c8u: goto label_1433c8;
        case 0x1433e8u: goto label_1433e8;
        case 0x14349cu: goto label_14349c;
        case 0x143548u: goto label_143548;
        case 0x143550u: goto label_143550;
        case 0x14363cu: goto label_14363c;
        case 0x1436f8u: goto label_1436f8;
        case 0x143730u: goto label_143730;
        case 0x1437f4u: goto label_1437f4;
        case 0x143890u: goto label_143890;
        case 0x143898u: goto label_143898;
        case 0x143964u: goto label_143964;
        case 0x143a28u: goto label_143a28;
        case 0x143a48u: goto label_143a48;
        case 0x143b14u: goto label_143b14;
        case 0x143be8u: goto label_143be8;
        case 0x143bf0u: goto label_143bf0;
        case 0x143cf4u: goto label_143cf4;
        case 0x143dd8u: goto label_143dd8;
        case 0x143e10u: goto label_143e10;
        case 0x143ed8u: goto label_143ed8;
        case 0x143f38u: goto label_143f38;
        default: break;
    }

    ctx->pc = 0x142fb8u;

    // 0x142fb8: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x142fb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x142fbc: 0x24020140  addiu       $v0, $zero, 0x140
    ctx->pc = 0x142fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x142fc0: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x142fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x142fc4: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x142fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x142fc8: 0xa22818  mult        $a1, $a1, $v0
    ctx->pc = 0x142fc8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x142fcc: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x142fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x142fd0: 0xffbe0090  sd          $fp, 0x90($sp)
    ctx->pc = 0x142fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x142fd4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x142fd4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142fd8: 0xffb70080  sd          $s7, 0x80($sp)
    ctx->pc = 0x142fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x142fdc: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x142fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x142fe0: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x142fe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x142fe4: 0x2851021  addu        $v0, $s4, $a1
    ctx->pc = 0x142fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
    // 0x142fe8: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x142fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x142fec: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x142fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x142ff0: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x142ff0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x142ff4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x142ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x142ff8: 0x8c4306e0  lw          $v1, 0x6E0($v0)
    ctx->pc = 0x142ff8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1760)));
    // 0x142ffc: 0x10600027  beqz        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x142FFCu;
    {
        const bool branch_taken_0x142ffc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x143000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142FFCu;
            // 0x143000: 0x268206d4  addiu       $v0, $s4, 0x6D4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1748));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142ffc) {
            ctx->pc = 0x14309Cu;
            goto label_14309c;
        }
    }
    ctx->pc = 0x143004u;
    // 0x143004: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x143004u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x143008: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x143008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x14300c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14300cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x143010: 0x18600026  blez        $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x143010u;
    {
        const bool branch_taken_0x143010 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x143014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143010u;
            // 0x143014: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143010) {
            ctx->pc = 0x1430ACu;
            goto label_1430ac;
        }
    }
    ctx->pc = 0x143018u;
    // 0x143018: 0x268306d8  addiu       $v1, $s4, 0x6D8
    ctx->pc = 0x143018u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 1752));
    // 0x14301c: 0x269705d0  addiu       $s7, $s4, 0x5D0
    ctx->pc = 0x14301cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 20), 1488));
    // 0x143020: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x143020u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x143024: 0x269605e0  addiu       $s6, $s4, 0x5E0
    ctx->pc = 0x143024u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 20), 1504));
    // 0x143028: 0x269e06d0  addiu       $fp, $s4, 0x6D0
    ctx->pc = 0x143028u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 20), 1744));
    // 0x14302c: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x14302cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_143030:
    // 0x143030: 0x24110140  addiu       $s1, $zero, 0x140
    ctx->pc = 0x143030u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x143034: 0x2413001c  addiu       $s3, $zero, 0x1C
    ctx->pc = 0x143034u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x143038: 0x158080  sll         $s0, $s5, 2
    ctx->pc = 0x143038u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 21), 2));
    // 0x14303c: 0x518818  mult        $s1, $v0, $s1
    ctx->pc = 0x14303cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 17, (int32_t)result); }
    // 0x143040: 0x72b39818  mult1       $s3, $s5, $s3
    ctx->pc = 0x143040u;
    { int64_t result = (int64_t)GPR_S32(ctx, 21) * (int64_t)GPR_S32(ctx, 19); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 19, (int32_t)result); }
    // 0x143044: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x143044u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x143048: 0x2118021  addu        $s0, $s0, $s1
    ctx->pc = 0x143048u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x14304c: 0x263205a8  addiu       $s2, $s1, 0x5A8
    ctx->pc = 0x14304cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 1448));
    // 0x143050: 0x2f01021  addu        $v0, $s7, $s0
    ctx->pc = 0x143050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
    // 0x143054: 0x2929021  addu        $s2, $s4, $s2
    ctx->pc = 0x143054u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
    // 0x143058: 0x26640048  addiu       $a0, $s3, 0x48
    ctx->pc = 0x143058u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 72));
    // 0x14305c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14305cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x143060: 0x60f809  jalr        $v1
    ctx->pc = 0x143060u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x143068u);
        ctx->pc = 0x143064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143060u;
            // 0x143064: 0x2442021  addu        $a0, $s2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x143068u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x143068u; }
            if (ctx->pc != 0x143068u) { return; }
        }
        }
    }
    ctx->pc = 0x143068u;
label_143068:
    // 0x143068: 0x2d08021  addu        $s0, $s6, $s0
    ctx->pc = 0x143068u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 16)));
    // 0x14306c: 0x267300b8  addiu       $s3, $s3, 0xB8
    ctx->pc = 0x14306cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 184));
    // 0x143070: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x143070u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x143074: 0x40f809  jalr        $v0
    ctx->pc = 0x143074u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x14307Cu);
        ctx->pc = 0x143078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143074u;
            // 0x143078: 0x2532021  addu        $a0, $s2, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x14307Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x14307Cu; }
            if (ctx->pc != 0x14307Cu) { return; }
        }
        }
    }
    ctx->pc = 0x14307Cu;
label_14307c:
    // 0x14307c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x14307cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x143080: 0x718821  addu        $s1, $v1, $s1
    ctx->pc = 0x143080u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x143084: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x143084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x143088: 0x2a2102a  slt         $v0, $s5, $v0
    ctx->pc = 0x143088u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x14308c: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x14308Cu;
    {
        const bool branch_taken_0x14308c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x143090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14308Cu;
            // 0x143090: 0x8fa20000  lw          $v0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14308c) {
            ctx->pc = 0x143030u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143030;
        }
    }
    ctx->pc = 0x143094u;
    // 0x143094: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x143094u;
    {
        const bool branch_taken_0x143094 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x143098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143094u;
            // 0x143098: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143094) {
            ctx->pc = 0x1430BCu;
            goto label_1430bc;
        }
    }
    ctx->pc = 0x14309Cu;
label_14309c:
    // 0x14309c: 0x268206d8  addiu       $v0, $s4, 0x6D8
    ctx->pc = 0x14309cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1752));
    // 0x1430a0: 0x269e06d0  addiu       $fp, $s4, 0x6D0
    ctx->pc = 0x1430a0u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 20), 1744));
    // 0x1430a4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1430A4u;
    {
        const bool branch_taken_0x1430a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1430A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1430A4u;
            // 0x1430a8: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1430a4) {
            ctx->pc = 0x1430B8u;
            goto label_1430b8;
        }
    }
    ctx->pc = 0x1430ACu;
label_1430ac:
    // 0x1430ac: 0x268306d8  addiu       $v1, $s4, 0x6D8
    ctx->pc = 0x1430acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 1752));
    // 0x1430b0: 0x269e06d0  addiu       $fp, $s4, 0x6D0
    ctx->pc = 0x1430b0u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 20), 1744));
    // 0x1430b4: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x1430b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
label_1430b8:
    // 0x1430b8: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1430b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1430bc:
    // 0x1430bc: 0x24020140  addiu       $v0, $zero, 0x140
    ctx->pc = 0x1430bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x1430c0: 0x622018  mult        $a0, $v1, $v0
    ctx->pc = 0x1430c0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1430c4: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x1430c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1430c8: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x1430c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1430cc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1430ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1430d0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1430D0u;
    {
        const bool branch_taken_0x1430d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1430D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1430D0u;
            // 0x1430d4: 0x2841021  addu        $v0, $s4, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1430d0) {
            ctx->pc = 0x1430F0u;
            goto label_1430f0;
        }
    }
    ctx->pc = 0x1430D8u;
    // 0x1430d8: 0x8c4306e4  lw          $v1, 0x6E4($v0)
    ctx->pc = 0x1430d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1764)));
    // 0x1430dc: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1430DCu;
    {
        const bool branch_taken_0x1430dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1430E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1430DCu;
            // 0x1430e0: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1430dc) {
            ctx->pc = 0x1430F0u;
            goto label_1430f0;
        }
    }
    ctx->pc = 0x1430E4u;
    // 0x1430e4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1430e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1430e8: 0xc05221c  jal         func_148870
    ctx->pc = 0x1430E8u;
    SET_GPR_U32(ctx, 31, 0x1430F0u);
    ctx->pc = 0x1430ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1430E8u;
            // 0x1430ec: 0x24a5ddb0  addiu       $a1, $a1, -0x2250 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1430F0u; }
        if (ctx->pc != 0x1430F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1430F0u; }
        if (ctx->pc != 0x1430F0u) { return; }
    }
    ctx->pc = 0x1430F0u;
label_1430f0:
    // 0x1430f0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1430f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1430f4: 0x24020140  addiu       $v0, $zero, 0x140
    ctx->pc = 0x1430f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x1430f8: 0x622818  mult        $a1, $v1, $v0
    ctx->pc = 0x1430f8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x1430fc: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x1430fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x143100: 0x451821  addu        $v1, $v0, $a1
    ctx->pc = 0x143100u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x143104: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x143104u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x143108: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x143108u;
    {
        const bool branch_taken_0x143108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14310Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143108u;
            // 0x14310c: 0x2851021  addu        $v0, $s4, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143108) {
            ctx->pc = 0x143150u;
            goto label_143150;
        }
    }
    ctx->pc = 0x143110u;
    // 0x143110: 0x3c51021  addu        $v0, $fp, $a1
    ctx->pc = 0x143110u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 5)));
    // 0x143114: 0x2851821  addu        $v1, $s4, $a1
    ctx->pc = 0x143114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
    // 0x143118: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x143118u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14311c: 0x8c6505ac  lw          $a1, 0x5AC($v1)
    ctx->pc = 0x14311cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1452)));
    // 0x143120: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x143120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x143124: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x143124u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x143128: 0xdfb70080  ld          $s7, 0x80($sp)
    ctx->pc = 0x143128u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x14312c: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x14312cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x143130: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x143130u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x143134: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x143134u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x143138: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x143138u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14313c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x14313cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x143140: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x143140u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x143144: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x143144u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x143148: 0x8050fca  j           func_143F28
    ctx->pc = 0x143148u;
    ctx->pc = 0x14314Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x143148u;
            // 0x14314c: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x143F28u;
    goto label_143f28;
    ctx->pc = 0x143150u;
label_143150:
    // 0x143150: 0x8c4306e4  lw          $v1, 0x6E4($v0)
    ctx->pc = 0x143150u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1764)));
    // 0x143154: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x143154u;
    {
        const bool branch_taken_0x143154 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x143158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143154u;
            // 0x143158: 0x3c51021  addu        $v0, $fp, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143154) {
            ctx->pc = 0x143194u;
            goto label_143194;
        }
    }
    ctx->pc = 0x14315Cu;
    // 0x14315c: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x14315cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x143160: 0x8e850834  lw          $a1, 0x834($s4)
    ctx->pc = 0x143160u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 2100)));
    // 0x143164: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x143164u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x143168: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x143168u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x14316c: 0xdfb70080  ld          $s7, 0x80($sp)
    ctx->pc = 0x14316cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x143170: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x143170u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x143174: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x143174u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x143178: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x143178u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14317c: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x14317cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x143180: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x143180u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x143184: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x143184u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x143188: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x143188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14318c: 0x8050fca  j           func_143F28
    ctx->pc = 0x14318Cu;
    ctx->pc = 0x143190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14318Cu;
            // 0x143190: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x143F28u;
    goto label_143f28;
    ctx->pc = 0x143194u;
label_143194:
    // 0x143194: 0x2851821  addu        $v1, $s4, $a1
    ctx->pc = 0x143194u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
    // 0x143198: 0x8e850834  lw          $a1, 0x834($s4)
    ctx->pc = 0x143198u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 2100)));
    // 0x14319c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14319cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1431a0: 0x8c6605ac  lw          $a2, 0x5AC($v1)
    ctx->pc = 0x1431a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1452)));
    // 0x1431a4: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x1431a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1431a8: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x1431a8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1431ac: 0xdfb70080  ld          $s7, 0x80($sp)
    ctx->pc = 0x1431acu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1431b0: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x1431b0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1431b4: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x1431b4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1431b8: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x1431b8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1431bc: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x1431bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1431c0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1431c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1431c4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1431c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1431c8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1431c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1431cc: 0x8050fb2  j           func_143EC8
    ctx->pc = 0x1431CCu;
    ctx->pc = 0x1431D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1431CCu;
            // 0x1431d0: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x143EC8u;
    goto label_143ec8;
    ctx->pc = 0x1431D4u;
    // 0x1431d4: 0x0  nop
    ctx->pc = 0x1431d4u;
    // NOP
    // 0x1431d8: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1431d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1431dc: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1431dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1431e0: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x1431e0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1431e4: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1431e4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1431e8: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x1431e8u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1431ec: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x1431ecu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1431f0: 0xc5840  sll         $t3, $t4, 1
    ctx->pc = 0x1431f0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x1431f4: 0x240fffff  addiu       $t7, $zero, -0x1
    ctx->pc = 0x1431f4u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1431f8: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x1431f8u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
label_1431fc:
    // 0x1431fc: 0x78a80000  lq          $t0, 0x0($a1)
    ctx->pc = 0x1431fcu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143200: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143200u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143204: 0x78c90000  lq          $t1, 0x0($a2)
    ctx->pc = 0x143204u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143208: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143208u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x14320c: 0x712856e8  qfsrv       $t2, $t1, $t0
    ctx->pc = 0x14320cu;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143210: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143210u;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143214: 0x700a4ea8  pextub      $t1, $zero, $t2
    ctx->pc = 0x143214u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143218: 0x7dc80000  sq          $t0, 0x0($t6)
    ctx->pc = 0x143218u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 8));
    // 0x14321c: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x14321cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x143220: 0x7dc90010  sq          $t1, 0x10($t6)
    ctx->pc = 0x143220u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 9));
    // 0x143224: 0x1ce0fff5  bgtz        $a3, . + 4 + (-0xB << 2)
    ctx->pc = 0x143224u;
    {
        const bool branch_taken_0x143224 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143224u;
            // 0x143228: 0x1cb7021  addu        $t6, $t6, $t3 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 11)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143224) {
            ctx->pc = 0x1431FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1431fc;
        }
    }
    ctx->pc = 0x14322Cu;
    // 0x14322c: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x14322cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x143230: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x143230u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x143234: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143234u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143238: 0x1e75024  and         $t2, $t7, $a3
    ctx->pc = 0x143238u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 15) & GPR_U64(ctx, 7));
    // 0x14323c: 0x1540ffef  bnez        $t2, . + 4 + (-0x11 << 2)
    ctx->pc = 0x14323Cu;
    {
        const bool branch_taken_0x14323c = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14323Cu;
            // 0x143240: 0x782d  daddu       $t7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14323c) {
            ctx->pc = 0x1431FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1431fc;
        }
    }
    ctx->pc = 0x143244u;
    // 0x143244: 0x3e00008  jr          $ra
    ctx->pc = 0x143244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14324Cu;
    // 0x14324c: 0x0  nop
    ctx->pc = 0x14324cu;
    // NOP
    // 0x143250: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143250u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143254: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143254u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143258: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143258u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14325c: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x14325cu;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143260: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x143260u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143264: 0xc5840  sll         $t3, $t4, 1
    ctx->pc = 0x143264u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x143268: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143268u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x14326c: 0x2418ffff  addiu       $t8, $zero, -0x1
    ctx->pc = 0x14326cu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_143270:
    // 0x143270: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143270u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143274: 0x240fffff  addiu       $t7, $zero, -0x1
    ctx->pc = 0x143274u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_143278:
    // 0x143278: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143278u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x14327c: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x14327cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143280: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143280u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143284: 0x71084ee8  qfsrv       $t1, $t0, $t0
    ctx->pc = 0x143284u;
    SET_GPR_VEC(ctx, 9, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143288: 0x70094688  pextlb      $t0, $zero, $t1
    ctx->pc = 0x143288u;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 9)));
    // 0x14328c: 0x7dc80000  sq          $t0, 0x0($t6)
    ctx->pc = 0x14328cu;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 8));
    // 0x143290: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143290u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143294: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143294u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143298: 0x1cb7021  addu        $t6, $t6, $t3
    ctx->pc = 0x143298u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 11)));
    // 0x14329c: 0x1ce0fff6  bgtz        $a3, . + 4 + (-0xA << 2)
    ctx->pc = 0x14329Cu;
    {
        const bool branch_taken_0x14329c = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1432A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14329Cu;
            // 0x1432a0: 0xcc3021  addu        $a2, $a2, $t4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14329c) {
            ctx->pc = 0x143278u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143278;
        }
    }
    ctx->pc = 0x1432A4u;
    // 0x1432a4: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x1432a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x1432a8: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x1432a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x1432ac: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x1432acu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1432b0: 0x1e75024  and         $t2, $t7, $a3
    ctx->pc = 0x1432b0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 15) & GPR_U64(ctx, 7));
    // 0x1432b4: 0x1540fff0  bnez        $t2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1432B4u;
    {
        const bool branch_taken_0x1432b4 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x1432B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1432B4u;
            // 0x1432b8: 0x782d  daddu       $t7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1432b4) {
            ctx->pc = 0x143278u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143278;
        }
    }
    ctx->pc = 0x1432BCu;
    // 0x1432bc: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1432bcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1432c0: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1432c0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1432c4: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1432c4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1432c8: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x1432c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x1432cc: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x1432ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x1432d0: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x1432d0u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x1432d4: 0x1700ffe6  bnez        $t8, . + 4 + (-0x1A << 2)
    ctx->pc = 0x1432D4u;
    {
        const bool branch_taken_0x1432d4 = (GPR_U64(ctx, 24) != GPR_U64(ctx, 0));
        ctx->pc = 0x1432D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1432D4u;
            // 0x1432d8: 0xc02d  daddu       $t8, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1432d4) {
            ctx->pc = 0x143270u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143270;
        }
    }
    ctx->pc = 0x1432DCu;
    // 0x1432dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1432DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1432E4u;
    // 0x1432e4: 0x0  nop
    ctx->pc = 0x1432e4u;
    // NOP
    // 0x1432e8: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x1432e8u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x1432ec: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x1432ecu;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x1432f0: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1432f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1432f4: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1432f4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1432f8: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x1432f8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1432fc: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1432fcu;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143300: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143300u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143304: 0x8c980010  lw          $t8, 0x10($a0)
    ctx->pc = 0x143304u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143308: 0x78a80000  lq          $t0, 0x0($a1)
    ctx->pc = 0x143308u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x14330c: 0x186040  sll         $t4, $t8, 1
    ctx->pc = 0x14330cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 24), 1));
    // 0x143310: 0x78c90000  lq          $t1, 0x0($a2)
    ctx->pc = 0x143310u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143314: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143314u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143318: 0x712856e8  qfsrv       $t2, $t1, $t0
    ctx->pc = 0x143318u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x14331c: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x14331cu;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143320: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x143320u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x143324: 0x10e00015  beqz        $a3, . + 4 + (0x15 << 2)
    ctx->pc = 0x143324u;
    {
        const bool branch_taken_0x143324 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x143328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143324u;
            // 0x143328: 0x700a4ea8  pextub      $t1, $zero, $t2 (Delay Slot)
        SET_GPR_VEC(ctx, 9, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143324) {
            ctx->pc = 0x14337Cu;
            goto label_14337c;
        }
    }
    ctx->pc = 0x14332Cu;
label_14332c:
    // 0x14332c: 0xb82821  addu        $a1, $a1, $t8
    ctx->pc = 0x14332cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 24)));
    // 0x143330: 0xd83021  addu        $a2, $a2, $t8
    ctx->pc = 0x143330u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 24)));
    // 0x143334: 0x78aa0000  lq          $t2, 0x0($a1)
    ctx->pc = 0x143334u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143338: 0x78cf0000  lq          $t7, 0x0($a2)
    ctx->pc = 0x143338u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14333c: 0x71ea16e8  qfsrv       $v0, $t7, $t2
    ctx->pc = 0x14333cu;
    SET_GPR_VEC(ctx, 2, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143340: 0x70025688  pextlb      $t2, $zero, $v0
    ctx->pc = 0x143340u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143344: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143344u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143348: 0x70027ea8  pextub      $t7, $zero, $v0
    ctx->pc = 0x143348u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x14334c: 0x710a1108  paddh       $v0, $t0, $t2
    ctx->pc = 0x14334cu;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 10)));
    // 0x143350: 0x712f1908  paddh       $v1, $t1, $t7
    ctx->pc = 0x143350u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 15)));
    // 0x143354: 0x714044a9  por         $t0, $t2, $zero
    ctx->pc = 0x143354u;
    SET_GPR_VEC(ctx, 8, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143358: 0x71e04ca9  por         $t1, $t7, $zero
    ctx->pc = 0x143358u;
    SET_GPR_VEC(ctx, 9, PS2_POR(GPR_VEC(ctx, 15), GPR_VEC(ctx, 0)));
    // 0x14335c: 0x70591108  paddh       $v0, $v0, $t9
    ctx->pc = 0x14335cu;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x143360: 0x70791908  paddh       $v1, $v1, $t9
    ctx->pc = 0x143360u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 25)));
    // 0x143364: 0x70021076  psrlh       $v0, $v0, 1
    ctx->pc = 0x143364u;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 2), 1));
    // 0x143368: 0x70031876  psrlh       $v1, $v1, 1
    ctx->pc = 0x143368u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 3), 1));
    // 0x14336c: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x14336cu;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x143370: 0x7dc30010  sq          $v1, 0x10($t6)
    ctx->pc = 0x143370u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 3));
    // 0x143374: 0x1ce0ffed  bgtz        $a3, . + 4 + (-0x13 << 2)
    ctx->pc = 0x143374u;
    {
        const bool branch_taken_0x143374 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143374u;
            // 0x143378: 0x1cc7021  addu        $t6, $t6, $t4 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143374) {
            ctx->pc = 0x14332Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14332c;
        }
    }
    ctx->pc = 0x14337Cu;
label_14337c:
    // 0x14337c: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x14337cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x143380: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x143380u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x143384: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143384u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143388: 0x1675024  and         $t2, $t3, $a3
    ctx->pc = 0x143388u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x14338c: 0x1540ffe7  bnez        $t2, . + 4 + (-0x19 << 2)
    ctx->pc = 0x14338Cu;
    {
        const bool branch_taken_0x14338c = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14338Cu;
            // 0x143390: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14338c) {
            ctx->pc = 0x14332Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14332c;
        }
    }
    ctx->pc = 0x143394u;
    // 0x143394: 0x3e00008  jr          $ra
    ctx->pc = 0x143394u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14339Cu;
    // 0x14339c: 0x0  nop
    ctx->pc = 0x14339cu;
    // NOP
    // 0x1433a0: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x1433a0u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x1433a4: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x1433a4u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x1433a8: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1433a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1433ac: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1433acu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1433b0: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1433b0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1433b4: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x1433b4u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1433b8: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x1433b8u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1433bc: 0x240b0001  addiu       $t3, $zero, 0x1
    ctx->pc = 0x1433bcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1433c0: 0xcc040  sll         $t8, $t4, 1
    ctx->pc = 0x1433c0u;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x1433c4: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x1433c4u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
label_1433c8:
    // 0x1433c8: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x1433c8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1433cc: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x1433ccu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1433d0: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x1433d0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1433d4: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x1433d4u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x1433d8: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x1433d8u;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x1433dc: 0x356b8000  ori         $t3, $t3, 0x8000
    ctx->pc = 0x1433dcu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)32768);
    // 0x1433e0: 0x10e00010  beqz        $a3, . + 4 + (0x10 << 2)
    ctx->pc = 0x1433E0u;
    {
        const bool branch_taken_0x1433e0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x1433E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1433E0u;
            // 0x1433e4: 0x70087e88  pextlb      $t7, $zero, $t0 (Delay Slot)
        SET_GPR_VEC(ctx, 15, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1433e0) {
            ctx->pc = 0x143424u;
            goto label_143424;
        }
    }
    ctx->pc = 0x1433E8u;
label_1433e8:
    // 0x1433e8: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x1433e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x1433ec: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x1433ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x1433f0: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x1433f0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1433f4: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x1433f4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1433f8: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x1433f8u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x1433fc: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x1433fcu;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143400: 0x70085688  pextlb      $t2, $zero, $t0
    ctx->pc = 0x143400u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x143404: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143404u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143408: 0x714f4908  paddh       $t1, $t2, $t7
    ctx->pc = 0x143408u;
    SET_GPR_VEC(ctx, 9, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15)));
    // 0x14340c: 0x71407ca9  por         $t7, $t2, $zero
    ctx->pc = 0x14340cu;
    SET_GPR_VEC(ctx, 15, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143410: 0x71395108  paddh       $t2, $t1, $t9
    ctx->pc = 0x143410u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 25)));
    // 0x143414: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x143414u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143418: 0x7dca0000  sq          $t2, 0x0($t6)
    ctx->pc = 0x143418u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 10));
    // 0x14341c: 0x1ce0fff2  bgtz        $a3, . + 4 + (-0xE << 2)
    ctx->pc = 0x14341Cu;
    {
        const bool branch_taken_0x14341c = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14341Cu;
            // 0x143420: 0x1d87021  addu        $t6, $t6, $t8 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14341c) {
            ctx->pc = 0x1433E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1433e8;
        }
    }
    ctx->pc = 0x143424u;
label_143424:
    // 0x143424: 0x700b53f7  psrah       $t2, $t3, 15
    ctx->pc = 0x143424u;
    SET_GPR_VEC(ctx, 10, _mm_srai_epi16(GPR_VEC(ctx, 11), 15));
    // 0x143428: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x143428u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x14342c: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x14342cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143430: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x143430u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x143434: 0x1475024  and         $t2, $t2, $a3
    ctx->pc = 0x143434u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & GPR_U64(ctx, 7));
    // 0x143438: 0x1540ffeb  bnez        $t2, . + 4 + (-0x15 << 2)
    ctx->pc = 0x143438u;
    {
        const bool branch_taken_0x143438 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x14343Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143438u;
            // 0x14343c: 0x316b7fff  andi        $t3, $t3, 0x7FFF (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)32767);
        ctx->in_delay_slot = false;
        if (branch_taken_0x143438) {
            ctx->pc = 0x1433E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1433e8;
        }
    }
    ctx->pc = 0x143440u;
    // 0x143440: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143440u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143444: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143444u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143448: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143448u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14344c: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x14344cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x143450: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x143450u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x143454: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x143454u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x143458: 0x316a0001  andi        $t2, $t3, 0x1
    ctx->pc = 0x143458u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)1);
    // 0x14345c: 0x1540ffda  bnez        $t2, . + 4 + (-0x26 << 2)
    ctx->pc = 0x14345Cu;
    {
        const bool branch_taken_0x14345c = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14345Cu;
            // 0x143460: 0x316bfffe  andi        $t3, $t3, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x14345c) {
            ctx->pc = 0x1433C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1433c8;
        }
    }
    ctx->pc = 0x143464u;
    // 0x143464: 0x3e00008  jr          $ra
    ctx->pc = 0x143464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14346Cu;
    // 0x14346c: 0x0  nop
    ctx->pc = 0x14346cu;
    // NOP
    // 0x143470: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143470u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143474: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143474u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143478: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143478u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14347c: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x14347cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143480: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143480u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143484: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143484u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143488: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143488u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14348c: 0x24180001  addiu       $t8, $zero, 0x1
    ctx->pc = 0x14348cu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x143490: 0x8c890010  lw          $t1, 0x10($a0)
    ctx->pc = 0x143490u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143494: 0x94040  sll         $t0, $t1, 1
    ctx->pc = 0x143494u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x143498: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x143498u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_14349c:
    // 0x14349c: 0x78aa0000  lq          $t2, 0x0($a1)
    ctx->pc = 0x14349cu;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1434a0: 0x78cf0000  lq          $t7, 0x0($a2)
    ctx->pc = 0x1434a0u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1434a4: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x1434a4u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x1434a8: 0x71ea16e8  qfsrv       $v0, $t7, $t2
    ctx->pc = 0x1434a8u;
    SET_GPR_VEC(ctx, 2, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x1434ac: 0x714f1ee8  qfsrv       $v1, $t2, $t7
    ctx->pc = 0x1434acu;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15), ctx->sa & 0x7F));
    // 0x1434b0: 0x70025688  pextlb      $t2, $zero, $v0
    ctx->pc = 0x1434b0u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x1434b4: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x1434b4u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x1434b8: 0x70027ea8  pextub      $t7, $zero, $v0
    ctx->pc = 0x1434b8u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x1434bc: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x1434bcu;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x1434c0: 0x70621ee8  qfsrv       $v1, $v1, $v0
    ctx->pc = 0x1434c0u;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 3), GPR_VEC(ctx, 2), ctx->sa & 0x7F));
    // 0x1434c4: 0x70031688  pextlb      $v0, $zero, $v1
    ctx->pc = 0x1434c4u;
    SET_GPR_VEC(ctx, 2, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x1434c8: 0x70031ea8  pextub      $v1, $zero, $v1
    ctx->pc = 0x1434c8u;
    SET_GPR_VEC(ctx, 3, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x1434cc: 0x71425108  paddh       $t2, $t2, $v0
    ctx->pc = 0x1434ccu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 2)));
    // 0x1434d0: 0x71e37908  paddh       $t7, $t7, $v1
    ctx->pc = 0x1434d0u;
    SET_GPR_VEC(ctx, 15, PS2_PADDH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 3)));
    // 0x1434d4: 0x71591108  paddh       $v0, $t2, $t9
    ctx->pc = 0x1434d4u;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x1434d8: 0x71f91908  paddh       $v1, $t7, $t9
    ctx->pc = 0x1434d8u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x1434dc: 0x70021076  psrlh       $v0, $v0, 1
    ctx->pc = 0x1434dcu;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 2), 1));
    // 0x1434e0: 0x70031876  psrlh       $v1, $v1, 1
    ctx->pc = 0x1434e0u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 3), 1));
    // 0x1434e4: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x1434e4u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x1434e8: 0x7dc30010  sq          $v1, 0x10($t6)
    ctx->pc = 0x1434e8u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 3));
    // 0x1434ec: 0xa92821  addu        $a1, $a1, $t1
    ctx->pc = 0x1434ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x1434f0: 0xc93021  addu        $a2, $a2, $t1
    ctx->pc = 0x1434f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0x1434f4: 0x1ce0ffe9  bgtz        $a3, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1434F4u;
    {
        const bool branch_taken_0x1434f4 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1434F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1434F4u;
            // 0x1434f8: 0x1c87021  addu        $t6, $t6, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1434f4) {
            ctx->pc = 0x14349Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14349c;
        }
    }
    ctx->pc = 0x1434FCu;
    // 0x1434fc: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x1434fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x143500: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x143500u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x143504: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143504u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143508: 0x1676024  and         $t4, $t3, $a3
    ctx->pc = 0x143508u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x14350c: 0x1580ffe3  bnez        $t4, . + 4 + (-0x1D << 2)
    ctx->pc = 0x14350Cu;
    {
        const bool branch_taken_0x14350c = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x143510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14350Cu;
            // 0x143510: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14350c) {
            ctx->pc = 0x14349Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14349c;
        }
    }
    ctx->pc = 0x143514u;
    // 0x143514: 0x3e00008  jr          $ra
    ctx->pc = 0x143514u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14351Cu;
    // 0x14351c: 0x0  nop
    ctx->pc = 0x14351cu;
    // NOP
    // 0x143520: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143520u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143524: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143524u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143528: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143528u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14352c: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x14352cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143530: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143530u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143534: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143534u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143538: 0x24180001  addiu       $t8, $zero, 0x1
    ctx->pc = 0x143538u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14353c: 0x240cffff  addiu       $t4, $zero, -0x1
    ctx->pc = 0x14353cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x143540: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x143540u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143544: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x143544u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
label_143548:
    // 0x143548: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143548u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14354c: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x14354cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_143550:
    // 0x143550: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143550u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143554: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143554u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143558: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143558u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x14355c: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x14355cu;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143560: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x143560u;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143564: 0x70084e88  pextlb      $t1, $zero, $t0
    ctx->pc = 0x143564u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x143568: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143568u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x14356c: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x14356cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x143570: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x143570u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x143574: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143574u;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143578: 0x700856e8  qfsrv       $t2, $zero, $t0
    ctx->pc = 0x143578u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x14357c: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x14357cu;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143580: 0x71285108  paddh       $t2, $t1, $t0
    ctx->pc = 0x143580u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143584: 0x71595108  paddh       $t2, $t2, $t9
    ctx->pc = 0x143584u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x143588: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x143588u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x14358c: 0x7dca0000  sq          $t2, 0x0($t6)
    ctx->pc = 0x14358cu;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 10));
    // 0x143590: 0x1ce0ffef  bgtz        $a3, . + 4 + (-0x11 << 2)
    ctx->pc = 0x143590u;
    {
        const bool branch_taken_0x143590 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143590u;
            // 0x143594: 0x1c27021  addu        $t6, $t6, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143590) {
            ctx->pc = 0x143550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143550;
        }
    }
    ctx->pc = 0x143598u;
    // 0x143598: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x143598u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x14359c: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x14359cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x1435a0: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x1435a0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1435a4: 0x1675024  and         $t2, $t3, $a3
    ctx->pc = 0x1435a4u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x1435a8: 0x1540ffe9  bnez        $t2, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1435A8u;
    {
        const bool branch_taken_0x1435a8 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x1435ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1435A8u;
            // 0x1435ac: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1435a8) {
            ctx->pc = 0x143550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143550;
        }
    }
    ctx->pc = 0x1435B0u;
    // 0x1435b0: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1435b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1435b4: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1435b4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1435b8: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1435b8u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1435bc: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x1435bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x1435c0: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x1435c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x1435c4: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x1435c4u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x1435c8: 0x1580ffdf  bnez        $t4, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1435C8u;
    {
        const bool branch_taken_0x1435c8 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x1435CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1435C8u;
            // 0x1435cc: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1435c8) {
            ctx->pc = 0x143548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143548;
        }
    }
    ctx->pc = 0x1435D0u;
    // 0x1435d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1435D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1435D8u;
    // 0x1435d8: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x1435d8u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x1435dc: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x1435dcu;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x1435e0: 0x7019c874  psllh       $t9, $t9, 1
    ctx->pc = 0x1435e0u;
    SET_GPR_VEC(ctx, 25, _mm_slli_epi16(GPR_VEC(ctx, 25), 1));
    // 0x1435e4: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1435e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1435e8: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1435e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1435ec: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x1435ecu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1435f0: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1435f0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1435f4: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x1435f4u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1435f8: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x1435f8u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1435fc: 0x24180001  addiu       $t8, $zero, 0x1
    ctx->pc = 0x1435fcu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x143600: 0x78a80000  lq          $t0, 0x0($a1)
    ctx->pc = 0x143600u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143604: 0x78c90000  lq          $t1, 0x0($a2)
    ctx->pc = 0x143604u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143608: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143608u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x14360c: 0x712856e8  qfsrv       $t2, $t1, $t0
    ctx->pc = 0x14360cu;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143610: 0x71097ee8  qfsrv       $t7, $t0, $t1
    ctx->pc = 0x143610u;
    SET_GPR_VEC(ctx, 15, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 9), ctx->sa & 0x7F));
    // 0x143614: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143614u;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143618: 0x700a4ea8  pextub      $t1, $zero, $t2
    ctx->pc = 0x143618u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x14361c: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x14361cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x143620: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143620u;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143624: 0x71ea7ee8  qfsrv       $t7, $t7, $t2
    ctx->pc = 0x143624u;
    SET_GPR_VEC(ctx, 15, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143628: 0x700f5688  pextlb      $t2, $zero, $t7
    ctx->pc = 0x143628u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 15)));
    // 0x14362c: 0x700f7ea8  pextub      $t7, $zero, $t7
    ctx->pc = 0x14362cu;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 15)));
    // 0x143630: 0x710a4108  paddh       $t0, $t0, $t2
    ctx->pc = 0x143630u;
    SET_GPR_VEC(ctx, 8, PS2_PADDH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 10)));
    // 0x143634: 0x10e0001e  beqz        $a3, . + 4 + (0x1E << 2)
    ctx->pc = 0x143634u;
    {
        const bool branch_taken_0x143634 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x143638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143634u;
            // 0x143638: 0x712f4908  paddh       $t1, $t1, $t7 (Delay Slot)
        SET_GPR_VEC(ctx, 9, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 15)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143634) {
            ctx->pc = 0x1436B0u;
            goto label_1436b0;
        }
    }
    ctx->pc = 0x14363Cu;
label_14363c:
    // 0x14363c: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x14363cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143640: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x143640u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x143644: 0x78aa0000  lq          $t2, 0x0($a1)
    ctx->pc = 0x143644u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143648: 0x78cf0000  lq          $t7, 0x0($a2)
    ctx->pc = 0x143648u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14364c: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x14364cu;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143650: 0x71ea16e8  qfsrv       $v0, $t7, $t2
    ctx->pc = 0x143650u;
    SET_GPR_VEC(ctx, 2, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143654: 0x714f1ee8  qfsrv       $v1, $t2, $t7
    ctx->pc = 0x143654u;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15), ctx->sa & 0x7F));
    // 0x143658: 0x70025688  pextlb      $t2, $zero, $v0
    ctx->pc = 0x143658u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x14365c: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x14365cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143660: 0x70027ea8  pextub      $t7, $zero, $v0
    ctx->pc = 0x143660u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143664: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143664u;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143668: 0x70621ee8  qfsrv       $v1, $v1, $v0
    ctx->pc = 0x143668u;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 3), GPR_VEC(ctx, 2), ctx->sa & 0x7F));
    // 0x14366c: 0x70031688  pextlb      $v0, $zero, $v1
    ctx->pc = 0x14366cu;
    SET_GPR_VEC(ctx, 2, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x143670: 0x70031ea8  pextub      $v1, $zero, $v1
    ctx->pc = 0x143670u;
    SET_GPR_VEC(ctx, 3, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x143674: 0x71425108  paddh       $t2, $t2, $v0
    ctx->pc = 0x143674u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 2)));
    // 0x143678: 0x71e37908  paddh       $t7, $t7, $v1
    ctx->pc = 0x143678u;
    SET_GPR_VEC(ctx, 15, PS2_PADDH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 3)));
    // 0x14367c: 0x710a1108  paddh       $v0, $t0, $t2
    ctx->pc = 0x14367cu;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 10)));
    // 0x143680: 0x712f1908  paddh       $v1, $t1, $t7
    ctx->pc = 0x143680u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 15)));
    // 0x143684: 0x714044a9  por         $t0, $t2, $zero
    ctx->pc = 0x143684u;
    SET_GPR_VEC(ctx, 8, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143688: 0x71e04ca9  por         $t1, $t7, $zero
    ctx->pc = 0x143688u;
    SET_GPR_VEC(ctx, 9, PS2_POR(GPR_VEC(ctx, 15), GPR_VEC(ctx, 0)));
    // 0x14368c: 0x70591108  paddh       $v0, $v0, $t9
    ctx->pc = 0x14368cu;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x143690: 0x70791908  paddh       $v1, $v1, $t9
    ctx->pc = 0x143690u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 25)));
    // 0x143694: 0x700210b6  psrlh       $v0, $v0, 2
    ctx->pc = 0x143694u;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 2), 2));
    // 0x143698: 0x700318b6  psrlh       $v1, $v1, 2
    ctx->pc = 0x143698u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 3), 2));
    // 0x14369c: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x14369cu;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x1436a0: 0xc5040  sll         $t2, $t4, 1
    ctx->pc = 0x1436a0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x1436a4: 0x7dc30010  sq          $v1, 0x10($t6)
    ctx->pc = 0x1436a4u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 3));
    // 0x1436a8: 0x1ce0ffe4  bgtz        $a3, . + 4 + (-0x1C << 2)
    ctx->pc = 0x1436A8u;
    {
        const bool branch_taken_0x1436a8 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1436ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1436A8u;
            // 0x1436ac: 0x1ca7021  addu        $t6, $t6, $t2 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1436a8) {
            ctx->pc = 0x14363Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14363c;
        }
    }
    ctx->pc = 0x1436B0u;
label_1436b0:
    // 0x1436b0: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x1436b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x1436b4: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x1436b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x1436b8: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x1436b8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1436bc: 0x1675024  and         $t2, $t3, $a3
    ctx->pc = 0x1436bcu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x1436c0: 0x1540ffde  bnez        $t2, . + 4 + (-0x22 << 2)
    ctx->pc = 0x1436C0u;
    {
        const bool branch_taken_0x1436c0 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x1436C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1436C0u;
            // 0x1436c4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1436c0) {
            ctx->pc = 0x14363Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14363c;
        }
    }
    ctx->pc = 0x1436C8u;
    // 0x1436c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1436C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1436D0u;
    // 0x1436d0: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x1436d0u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x1436d4: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x1436d4u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x1436d8: 0x7019c874  psllh       $t9, $t9, 1
    ctx->pc = 0x1436d8u;
    SET_GPR_VEC(ctx, 25, _mm_slli_epi16(GPR_VEC(ctx, 25), 1));
    // 0x1436dc: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1436dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1436e0: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1436e0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1436e4: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1436e4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1436e8: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x1436e8u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1436ec: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x1436ecu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1436f0: 0x24180001  addiu       $t8, $zero, 0x1
    ctx->pc = 0x1436f0u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1436f4: 0x240b0001  addiu       $t3, $zero, 0x1
    ctx->pc = 0x1436f4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1436f8:
    // 0x1436f8: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x1436f8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1436fc: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x1436fcu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143700: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143700u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143704: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143704u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143708: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143708u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x14370c: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x14370cu;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143710: 0x70084e88  pextlb      $t1, $zero, $t0
    ctx->pc = 0x143710u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x143714: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143714u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143718: 0x356b8000  ori         $t3, $t3, 0x8000
    ctx->pc = 0x143718u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)32768);
    // 0x14371c: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x14371cu;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143720: 0x700856e8  qfsrv       $t2, $zero, $t0
    ctx->pc = 0x143720u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143724: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143724u;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143728: 0x10e00016  beqz        $a3, . + 4 + (0x16 << 2)
    ctx->pc = 0x143728u;
    {
        const bool branch_taken_0x143728 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x14372Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143728u;
            // 0x14372c: 0x71287908  paddh       $t7, $t1, $t0 (Delay Slot)
        SET_GPR_VEC(ctx, 15, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143728) {
            ctx->pc = 0x143784u;
            goto label_143784;
        }
    }
    ctx->pc = 0x143730u;
label_143730:
    // 0x143730: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x143730u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x143734: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143734u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143738: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143738u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14373c: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x14373cu;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143740: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143740u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143744: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x143744u;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143748: 0x70084e88  pextlb      $t1, $zero, $t0
    ctx->pc = 0x143748u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x14374c: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x14374cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143750: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143750u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143754: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143754u;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143758: 0x700856e8  qfsrv       $t2, $zero, $t0
    ctx->pc = 0x143758u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x14375c: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x14375cu;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143760: 0x71285108  paddh       $t2, $t1, $t0
    ctx->pc = 0x143760u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143764: 0x714f4908  paddh       $t1, $t2, $t7
    ctx->pc = 0x143764u;
    SET_GPR_VEC(ctx, 9, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15)));
    // 0x143768: 0x71407ca9  por         $t7, $t2, $zero
    ctx->pc = 0x143768u;
    SET_GPR_VEC(ctx, 15, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x14376c: 0x71395108  paddh       $t2, $t1, $t9
    ctx->pc = 0x14376cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 25)));
    // 0x143770: 0xc4040  sll         $t0, $t4, 1
    ctx->pc = 0x143770u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x143774: 0x700a50b6  psrlh       $t2, $t2, 2
    ctx->pc = 0x143774u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 2));
    // 0x143778: 0x7dca0000  sq          $t2, 0x0($t6)
    ctx->pc = 0x143778u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 10));
    // 0x14377c: 0x1ce0ffec  bgtz        $a3, . + 4 + (-0x14 << 2)
    ctx->pc = 0x14377Cu;
    {
        const bool branch_taken_0x14377c = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14377Cu;
            // 0x143780: 0x1c87021  addu        $t6, $t6, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14377c) {
            ctx->pc = 0x143730u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143730;
        }
    }
    ctx->pc = 0x143784u;
label_143784:
    // 0x143784: 0x700b53f7  psrah       $t2, $t3, 15
    ctx->pc = 0x143784u;
    SET_GPR_VEC(ctx, 10, _mm_srai_epi16(GPR_VEC(ctx, 11), 15));
    // 0x143788: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x143788u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x14378c: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x14378cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143790: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x143790u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x143794: 0x1475024  and         $t2, $t2, $a3
    ctx->pc = 0x143794u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & GPR_U64(ctx, 7));
    // 0x143798: 0x1540ffe5  bnez        $t2, . + 4 + (-0x1B << 2)
    ctx->pc = 0x143798u;
    {
        const bool branch_taken_0x143798 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x14379Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143798u;
            // 0x14379c: 0x316b7fff  andi        $t3, $t3, 0x7FFF (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)32767);
        ctx->in_delay_slot = false;
        if (branch_taken_0x143798) {
            ctx->pc = 0x143730u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143730;
        }
    }
    ctx->pc = 0x1437A0u;
    // 0x1437a0: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1437a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1437a4: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1437a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1437a8: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1437a8u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1437ac: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x1437acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x1437b0: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x1437b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x1437b4: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x1437b4u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x1437b8: 0x316a0001  andi        $t2, $t3, 0x1
    ctx->pc = 0x1437b8u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)1);
    // 0x1437bc: 0x1540ffce  bnez        $t2, . + 4 + (-0x32 << 2)
    ctx->pc = 0x1437BCu;
    {
        const bool branch_taken_0x1437bc = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x1437C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1437BCu;
            // 0x1437c0: 0x316bfffe  andi        $t3, $t3, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1437bc) {
            ctx->pc = 0x1436F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1436f8;
        }
    }
    ctx->pc = 0x1437C4u;
    // 0x1437c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1437C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1437CCu;
    // 0x1437cc: 0x0  nop
    ctx->pc = 0x1437ccu;
    // NOP
    // 0x1437d0: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1437d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1437d4: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1437d4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1437d8: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x1437d8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1437dc: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1437dcu;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1437e0: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x1437e0u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1437e4: 0x8c890010  lw          $t1, 0x10($a0)
    ctx->pc = 0x1437e4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1437e8: 0x94040  sll         $t0, $t1, 1
    ctx->pc = 0x1437e8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1437ec: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x1437ecu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1437f0: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x1437f0u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
label_1437f4:
    // 0x1437f4: 0x78aa0000  lq          $t2, 0x0($a1)
    ctx->pc = 0x1437f4u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1437f8: 0x78cf0000  lq          $t7, 0x0($a2)
    ctx->pc = 0x1437f8u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1437fc: 0x71ea16e8  qfsrv       $v0, $t7, $t2
    ctx->pc = 0x1437fcu;
    SET_GPR_VEC(ctx, 2, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143800: 0x70025688  pextlb      $t2, $zero, $v0
    ctx->pc = 0x143800u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143804: 0x70027ea8  pextub      $t7, $zero, $v0
    ctx->pc = 0x143804u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143808: 0x79c20000  lq          $v0, 0x0($t6)
    ctx->pc = 0x143808u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14380c: 0x79c30010  lq          $v1, 0x10($t6)
    ctx->pc = 0x14380cu;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 14), 16)));
    // 0x143810: 0x704a1108  paddh       $v0, $v0, $t2
    ctx->pc = 0x143810u;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 10)));
    // 0x143814: 0x706f1908  paddh       $v1, $v1, $t7
    ctx->pc = 0x143814u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 15)));
    // 0x143818: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143818u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x14381c: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x14381cu;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143820: 0x70595108  paddh       $t2, $v0, $t9
    ctx->pc = 0x143820u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x143824: 0x700a1076  psrlh       $v0, $t2, 1
    ctx->pc = 0x143824u;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143828: 0x70795108  paddh       $t2, $v1, $t9
    ctx->pc = 0x143828u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 25)));
    // 0x14382c: 0x700a1876  psrlh       $v1, $t2, 1
    ctx->pc = 0x14382cu;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143830: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x143830u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x143834: 0x7dc30010  sq          $v1, 0x10($t6)
    ctx->pc = 0x143834u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 3));
    // 0x143838: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143838u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x14383c: 0xa92821  addu        $a1, $a1, $t1
    ctx->pc = 0x14383cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x143840: 0x1c87021  addu        $t6, $t6, $t0
    ctx->pc = 0x143840u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 8)));
    // 0x143844: 0x1ce0ffeb  bgtz        $a3, . + 4 + (-0x15 << 2)
    ctx->pc = 0x143844u;
    {
        const bool branch_taken_0x143844 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143844u;
            // 0x143848: 0xc93021  addu        $a2, $a2, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143844) {
            ctx->pc = 0x1437F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1437f4;
        }
    }
    ctx->pc = 0x14384Cu;
    // 0x14384c: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x14384cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x143850: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x143850u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x143854: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143854u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143858: 0x1676024  and         $t4, $t3, $a3
    ctx->pc = 0x143858u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x14385c: 0x1580ffe5  bnez        $t4, . + 4 + (-0x1B << 2)
    ctx->pc = 0x14385Cu;
    {
        const bool branch_taken_0x14385c = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x143860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14385Cu;
            // 0x143860: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14385c) {
            ctx->pc = 0x1437F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1437f4;
        }
    }
    ctx->pc = 0x143864u;
    // 0x143864: 0x3e00008  jr          $ra
    ctx->pc = 0x143864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14386Cu;
    // 0x14386c: 0x0  nop
    ctx->pc = 0x14386cu;
    // NOP
    // 0x143870: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143870u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143874: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143874u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143878: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143878u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14387c: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x14387cu;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143880: 0x240cffff  addiu       $t4, $zero, -0x1
    ctx->pc = 0x143880u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x143884: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x143884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143888: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x143888u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x14388c: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x14388cu;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
label_143890:
    // 0x143890: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143890u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143894: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x143894u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_143898:
    // 0x143898: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143898u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x14389c: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x14389cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1438a0: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x1438a0u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x1438a4: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x1438a4u;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x1438a8: 0x70084e88  pextlb      $t1, $zero, $t0
    ctx->pc = 0x1438a8u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x1438ac: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x1438acu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x1438b0: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x1438b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1438b4: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x1438b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1438b8: 0x79c80000  lq          $t0, 0x0($t6)
    ctx->pc = 0x1438b8u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x1438bc: 0x71285108  paddh       $t2, $t1, $t0
    ctx->pc = 0x1438bcu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x1438c0: 0x71404988  pcgth       $t1, $t2, $zero
    ctx->pc = 0x1438c0u;
    SET_GPR_VEC(ctx, 9, PS2_PCGTH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x1438c4: 0x70094bf6  psrlh       $t1, $t1, 15
    ctx->pc = 0x1438c4u;
    SET_GPR_VEC(ctx, 9, _mm_srli_epi16(GPR_VEC(ctx, 9), 15));
    // 0x1438c8: 0x71495108  paddh       $t2, $t2, $t1
    ctx->pc = 0x1438c8u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 9)));
    // 0x1438cc: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x1438ccu;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x1438d0: 0x7dca0000  sq          $t2, 0x0($t6)
    ctx->pc = 0x1438d0u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 10));
    // 0x1438d4: 0x1ce0fff0  bgtz        $a3, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1438D4u;
    {
        const bool branch_taken_0x1438d4 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1438D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1438D4u;
            // 0x1438d8: 0x1c27021  addu        $t6, $t6, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1438d4) {
            ctx->pc = 0x143898u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143898;
        }
    }
    ctx->pc = 0x1438DCu;
    // 0x1438dc: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x1438dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x1438e0: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x1438e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x1438e4: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x1438e4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1438e8: 0x1675024  and         $t2, $t3, $a3
    ctx->pc = 0x1438e8u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x1438ec: 0x1540ffea  bnez        $t2, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1438ECu;
    {
        const bool branch_taken_0x1438ec = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x1438F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1438ECu;
            // 0x1438f0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1438ec) {
            ctx->pc = 0x143898u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143898;
        }
    }
    ctx->pc = 0x1438F4u;
    // 0x1438f4: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1438f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1438f8: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x1438f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1438fc: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x1438fcu;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143900: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x143900u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x143904: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x143904u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x143908: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x143908u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x14390c: 0x1580ffe0  bnez        $t4, . + 4 + (-0x20 << 2)
    ctx->pc = 0x14390Cu;
    {
        const bool branch_taken_0x14390c = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x143910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14390Cu;
            // 0x143910: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14390c) {
            ctx->pc = 0x143890u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143890;
        }
    }
    ctx->pc = 0x143914u;
    // 0x143914: 0x3e00008  jr          $ra
    ctx->pc = 0x143914u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14391Cu;
    // 0x14391c: 0x0  nop
    ctx->pc = 0x14391cu;
    // NOP
    // 0x143920: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143920u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143924: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143924u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143928: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143928u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14392c: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x14392cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143930: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143930u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143934: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143934u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143938: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143938u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14393c: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x14393cu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143940: 0x78a80000  lq          $t0, 0x0($a1)
    ctx->pc = 0x143940u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143944: 0x78c90000  lq          $t1, 0x0($a2)
    ctx->pc = 0x143944u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143948: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143948u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x14394c: 0x712856e8  qfsrv       $t2, $t1, $t0
    ctx->pc = 0x14394cu;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143950: 0xcc040  sll         $t8, $t4, 1
    ctx->pc = 0x143950u;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x143954: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143954u;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143958: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x143958u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x14395c: 0x10e0001f  beqz        $a3, . + 4 + (0x1F << 2)
    ctx->pc = 0x14395Cu;
    {
        const bool branch_taken_0x14395c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x143960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14395Cu;
            // 0x143960: 0x700a4ea8  pextub      $t1, $zero, $t2 (Delay Slot)
        SET_GPR_VEC(ctx, 9, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14395c) {
            ctx->pc = 0x1439DCu;
            goto label_1439dc;
        }
    }
    ctx->pc = 0x143964u;
label_143964:
    // 0x143964: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143964u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143968: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x143968u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x14396c: 0x78aa0000  lq          $t2, 0x0($a1)
    ctx->pc = 0x14396cu;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143970: 0x78cf0000  lq          $t7, 0x0($a2)
    ctx->pc = 0x143970u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143974: 0x71ea16e8  qfsrv       $v0, $t7, $t2
    ctx->pc = 0x143974u;
    SET_GPR_VEC(ctx, 2, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143978: 0x70025688  pextlb      $t2, $zero, $v0
    ctx->pc = 0x143978u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x14397c: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x14397cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143980: 0x70027ea8  pextub      $t7, $zero, $v0
    ctx->pc = 0x143980u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143984: 0x710a1108  paddh       $v0, $t0, $t2
    ctx->pc = 0x143984u;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 10)));
    // 0x143988: 0x712f1908  paddh       $v1, $t1, $t7
    ctx->pc = 0x143988u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 15)));
    // 0x14398c: 0x714044a9  por         $t0, $t2, $zero
    ctx->pc = 0x14398cu;
    SET_GPR_VEC(ctx, 8, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143990: 0x71e04ca9  por         $t1, $t7, $zero
    ctx->pc = 0x143990u;
    SET_GPR_VEC(ctx, 9, PS2_POR(GPR_VEC(ctx, 15), GPR_VEC(ctx, 0)));
    // 0x143994: 0x70591108  paddh       $v0, $v0, $t9
    ctx->pc = 0x143994u;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x143998: 0x70791908  paddh       $v1, $v1, $t9
    ctx->pc = 0x143998u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 25)));
    // 0x14399c: 0x70021076  psrlh       $v0, $v0, 1
    ctx->pc = 0x14399cu;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 2), 1));
    // 0x1439a0: 0x70031876  psrlh       $v1, $v1, 1
    ctx->pc = 0x1439a0u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 3), 1));
    // 0x1439a4: 0x79ca0000  lq          $t2, 0x0($t6)
    ctx->pc = 0x1439a4u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x1439a8: 0x79cf0010  lq          $t7, 0x10($t6)
    ctx->pc = 0x1439a8u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 14), 16)));
    // 0x1439ac: 0x704a1108  paddh       $v0, $v0, $t2
    ctx->pc = 0x1439acu;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 10)));
    // 0x1439b0: 0x706f1908  paddh       $v1, $v1, $t7
    ctx->pc = 0x1439b0u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 15)));
    // 0x1439b4: 0x70595108  paddh       $t2, $v0, $t9
    ctx->pc = 0x1439b4u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x1439b8: 0x700a1076  psrlh       $v0, $t2, 1
    ctx->pc = 0x1439b8u;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x1439bc: 0x70605188  pcgth       $t2, $v1, $zero
    ctx->pc = 0x1439bcu;
    SET_GPR_VEC(ctx, 10, PS2_PCGTH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 0)));
    // 0x1439c0: 0x700a53f6  psrlh       $t2, $t2, 15
    ctx->pc = 0x1439c0u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 15));
    // 0x1439c4: 0x706a5108  paddh       $t2, $v1, $t2
    ctx->pc = 0x1439c4u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 10)));
    // 0x1439c8: 0x700a1876  psrlh       $v1, $t2, 1
    ctx->pc = 0x1439c8u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x1439cc: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x1439ccu;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x1439d0: 0x7dc30010  sq          $v1, 0x10($t6)
    ctx->pc = 0x1439d0u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 3));
    // 0x1439d4: 0x1ce0ffe3  bgtz        $a3, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1439D4u;
    {
        const bool branch_taken_0x1439d4 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1439D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1439D4u;
            // 0x1439d8: 0x1d87021  addu        $t6, $t6, $t8 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1439d4) {
            ctx->pc = 0x143964u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143964;
        }
    }
    ctx->pc = 0x1439DCu;
label_1439dc:
    // 0x1439dc: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x1439dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x1439e0: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x1439e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x1439e4: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x1439e4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1439e8: 0x1675024  and         $t2, $t3, $a3
    ctx->pc = 0x1439e8u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x1439ec: 0x1540ffdd  bnez        $t2, . + 4 + (-0x23 << 2)
    ctx->pc = 0x1439ECu;
    {
        const bool branch_taken_0x1439ec = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x1439F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1439ECu;
            // 0x1439f0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1439ec) {
            ctx->pc = 0x143964u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143964;
        }
    }
    ctx->pc = 0x1439F4u;
    // 0x1439f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1439F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1439FCu;
    // 0x1439fc: 0x0  nop
    ctx->pc = 0x1439fcu;
    // NOP
    // 0x143a00: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143a00u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143a04: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143a04u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143a08: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143a08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143a0c: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143a0cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143a10: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143a10u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143a14: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143a14u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143a18: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x143a18u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143a1c: 0x240b0001  addiu       $t3, $zero, 0x1
    ctx->pc = 0x143a1cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x143a20: 0xcc040  sll         $t8, $t4, 1
    ctx->pc = 0x143a20u;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x143a24: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143a24u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
label_143a28:
    // 0x143a28: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143a28u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143a2c: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143a2cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143a30: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143a30u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143a34: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143a34u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143a38: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x143a38u;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143a3c: 0x356b8000  ori         $t3, $t3, 0x8000
    ctx->pc = 0x143a3cu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)32768);
    // 0x143a40: 0x10e00016  beqz        $a3, . + 4 + (0x16 << 2)
    ctx->pc = 0x143A40u;
    {
        const bool branch_taken_0x143a40 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x143A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143A40u;
            // 0x143a44: 0x70087e88  pextlb      $t7, $zero, $t0 (Delay Slot)
        SET_GPR_VEC(ctx, 15, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143a40) {
            ctx->pc = 0x143A9Cu;
            goto label_143a9c;
        }
    }
    ctx->pc = 0x143A48u;
label_143a48:
    // 0x143a48: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143a48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143a4c: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x143a4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x143a50: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143a50u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143a54: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143a54u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143a58: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143a58u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143a5c: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x143a5cu;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143a60: 0x70085688  pextlb      $t2, $zero, $t0
    ctx->pc = 0x143a60u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x143a64: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143a64u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143a68: 0x714f4908  paddh       $t1, $t2, $t7
    ctx->pc = 0x143a68u;
    SET_GPR_VEC(ctx, 9, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15)));
    // 0x143a6c: 0x71407ca9  por         $t7, $t2, $zero
    ctx->pc = 0x143a6cu;
    SET_GPR_VEC(ctx, 15, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143a70: 0x71395108  paddh       $t2, $t1, $t9
    ctx->pc = 0x143a70u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 25)));
    // 0x143a74: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x143a74u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143a78: 0x79c80000  lq          $t0, 0x0($t6)
    ctx->pc = 0x143a78u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x143a7c: 0x71485108  paddh       $t2, $t2, $t0
    ctx->pc = 0x143a7cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 8)));
    // 0x143a80: 0x71404988  pcgth       $t1, $t2, $zero
    ctx->pc = 0x143a80u;
    SET_GPR_VEC(ctx, 9, PS2_PCGTH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143a84: 0x70094bf6  psrlh       $t1, $t1, 15
    ctx->pc = 0x143a84u;
    SET_GPR_VEC(ctx, 9, _mm_srli_epi16(GPR_VEC(ctx, 9), 15));
    // 0x143a88: 0x71495108  paddh       $t2, $t2, $t1
    ctx->pc = 0x143a88u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 9)));
    // 0x143a8c: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x143a8cu;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143a90: 0x7dca0000  sq          $t2, 0x0($t6)
    ctx->pc = 0x143a90u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 10));
    // 0x143a94: 0x1ce0ffec  bgtz        $a3, . + 4 + (-0x14 << 2)
    ctx->pc = 0x143A94u;
    {
        const bool branch_taken_0x143a94 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143A94u;
            // 0x143a98: 0x1d87021  addu        $t6, $t6, $t8 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143a94) {
            ctx->pc = 0x143A48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143a48;
        }
    }
    ctx->pc = 0x143A9Cu;
label_143a9c:
    // 0x143a9c: 0x700b53f7  psrah       $t2, $t3, 15
    ctx->pc = 0x143a9cu;
    SET_GPR_VEC(ctx, 10, _mm_srai_epi16(GPR_VEC(ctx, 11), 15));
    // 0x143aa0: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x143aa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x143aa4: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143aa4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143aa8: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x143aa8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x143aac: 0x1475024  and         $t2, $t2, $a3
    ctx->pc = 0x143aacu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & GPR_U64(ctx, 7));
    // 0x143ab0: 0x1540ffe5  bnez        $t2, . + 4 + (-0x1B << 2)
    ctx->pc = 0x143AB0u;
    {
        const bool branch_taken_0x143ab0 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143AB0u;
            // 0x143ab4: 0x316b7fff  andi        $t3, $t3, 0x7FFF (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)32767);
        ctx->in_delay_slot = false;
        if (branch_taken_0x143ab0) {
            ctx->pc = 0x143A48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143a48;
        }
    }
    ctx->pc = 0x143AB8u;
    // 0x143ab8: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143ab8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143abc: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143abcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143ac0: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143ac0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143ac4: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x143ac4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x143ac8: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x143ac8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x143acc: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x143accu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x143ad0: 0x316a0001  andi        $t2, $t3, 0x1
    ctx->pc = 0x143ad0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)1);
    // 0x143ad4: 0x1540ffd4  bnez        $t2, . + 4 + (-0x2C << 2)
    ctx->pc = 0x143AD4u;
    {
        const bool branch_taken_0x143ad4 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143AD4u;
            // 0x143ad8: 0x316bfffe  andi        $t3, $t3, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x143ad4) {
            ctx->pc = 0x143A28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143a28;
        }
    }
    ctx->pc = 0x143ADCu;
    // 0x143adc: 0x3e00008  jr          $ra
    ctx->pc = 0x143ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x143AE4u;
    // 0x143ae4: 0x0  nop
    ctx->pc = 0x143ae4u;
    // NOP
    // 0x143ae8: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143ae8u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143aec: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143aecu;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143af0: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143af0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143af4: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143af4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143af8: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143af8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143afc: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143afcu;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143b00: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143b00u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143b04: 0x24180001  addiu       $t8, $zero, 0x1
    ctx->pc = 0x143b04u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x143b08: 0x8c890010  lw          $t1, 0x10($a0)
    ctx->pc = 0x143b08u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143b0c: 0x94040  sll         $t0, $t1, 1
    ctx->pc = 0x143b0cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x143b10: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x143b10u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_143b14:
    // 0x143b14: 0x78aa0000  lq          $t2, 0x0($a1)
    ctx->pc = 0x143b14u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143b18: 0x78cf0000  lq          $t7, 0x0($a2)
    ctx->pc = 0x143b18u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143b1c: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143b1cu;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143b20: 0x71ea16e8  qfsrv       $v0, $t7, $t2
    ctx->pc = 0x143b20u;
    SET_GPR_VEC(ctx, 2, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143b24: 0x714f1ee8  qfsrv       $v1, $t2, $t7
    ctx->pc = 0x143b24u;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15), ctx->sa & 0x7F));
    // 0x143b28: 0x70025688  pextlb      $t2, $zero, $v0
    ctx->pc = 0x143b28u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143b2c: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143b2cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143b30: 0x70027ea8  pextub      $t7, $zero, $v0
    ctx->pc = 0x143b30u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143b34: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143b34u;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143b38: 0x70621ee8  qfsrv       $v1, $v1, $v0
    ctx->pc = 0x143b38u;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 3), GPR_VEC(ctx, 2), ctx->sa & 0x7F));
    // 0x143b3c: 0x70031688  pextlb      $v0, $zero, $v1
    ctx->pc = 0x143b3cu;
    SET_GPR_VEC(ctx, 2, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x143b40: 0x70031ea8  pextub      $v1, $zero, $v1
    ctx->pc = 0x143b40u;
    SET_GPR_VEC(ctx, 3, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x143b44: 0x71425108  paddh       $t2, $t2, $v0
    ctx->pc = 0x143b44u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 2)));
    // 0x143b48: 0x71e37908  paddh       $t7, $t7, $v1
    ctx->pc = 0x143b48u;
    SET_GPR_VEC(ctx, 15, PS2_PADDH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 3)));
    // 0x143b4c: 0x71591108  paddh       $v0, $t2, $t9
    ctx->pc = 0x143b4cu;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x143b50: 0x71f91908  paddh       $v1, $t7, $t9
    ctx->pc = 0x143b50u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x143b54: 0x70021076  psrlh       $v0, $v0, 1
    ctx->pc = 0x143b54u;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 2), 1));
    // 0x143b58: 0x70031876  psrlh       $v1, $v1, 1
    ctx->pc = 0x143b58u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 3), 1));
    // 0x143b5c: 0x79ca0000  lq          $t2, 0x0($t6)
    ctx->pc = 0x143b5cu;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x143b60: 0x79cf0010  lq          $t7, 0x10($t6)
    ctx->pc = 0x143b60u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 14), 16)));
    // 0x143b64: 0x704a1108  paddh       $v0, $v0, $t2
    ctx->pc = 0x143b64u;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 10)));
    // 0x143b68: 0x706f1908  paddh       $v1, $v1, $t7
    ctx->pc = 0x143b68u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 15)));
    // 0x143b6c: 0x70595108  paddh       $t2, $v0, $t9
    ctx->pc = 0x143b6cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x143b70: 0x700a1076  psrlh       $v0, $t2, 1
    ctx->pc = 0x143b70u;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143b74: 0x70605188  pcgth       $t2, $v1, $zero
    ctx->pc = 0x143b74u;
    SET_GPR_VEC(ctx, 10, PS2_PCGTH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 0)));
    // 0x143b78: 0x700a53f6  psrlh       $t2, $t2, 15
    ctx->pc = 0x143b78u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 15));
    // 0x143b7c: 0x706a5108  paddh       $t2, $v1, $t2
    ctx->pc = 0x143b7cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 10)));
    // 0x143b80: 0x700a1876  psrlh       $v1, $t2, 1
    ctx->pc = 0x143b80u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143b84: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x143b84u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x143b88: 0x7dc30010  sq          $v1, 0x10($t6)
    ctx->pc = 0x143b88u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 3));
    // 0x143b8c: 0xa92821  addu        $a1, $a1, $t1
    ctx->pc = 0x143b8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x143b90: 0xc93021  addu        $a2, $a2, $t1
    ctx->pc = 0x143b90u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0x143b94: 0x1ce0ffdf  bgtz        $a3, . + 4 + (-0x21 << 2)
    ctx->pc = 0x143B94u;
    {
        const bool branch_taken_0x143b94 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143B94u;
            // 0x143b98: 0x1c87021  addu        $t6, $t6, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143b94) {
            ctx->pc = 0x143B14u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143b14;
        }
    }
    ctx->pc = 0x143B9Cu;
    // 0x143b9c: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x143b9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x143ba0: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x143ba0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x143ba4: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143ba4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143ba8: 0x1676024  and         $t4, $t3, $a3
    ctx->pc = 0x143ba8u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x143bac: 0x1580ffd9  bnez        $t4, . + 4 + (-0x27 << 2)
    ctx->pc = 0x143BACu;
    {
        const bool branch_taken_0x143bac = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x143BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143BACu;
            // 0x143bb0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143bac) {
            ctx->pc = 0x143B14u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143b14;
        }
    }
    ctx->pc = 0x143BB4u;
    // 0x143bb4: 0x3e00008  jr          $ra
    ctx->pc = 0x143BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x143BBCu;
    // 0x143bbc: 0x0  nop
    ctx->pc = 0x143bbcu;
    // NOP
    // 0x143bc0: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143bc0u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143bc4: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143bc4u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143bc8: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143bc8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143bcc: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143bccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143bd0: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143bd0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143bd4: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143bd4u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143bd8: 0x24180001  addiu       $t8, $zero, 0x1
    ctx->pc = 0x143bd8u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x143bdc: 0x240cffff  addiu       $t4, $zero, -0x1
    ctx->pc = 0x143bdcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x143be0: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x143be0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143be4: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x143be4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
label_143be8:
    // 0x143be8: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143be8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143bec: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x143becu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_143bf0:
    // 0x143bf0: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143bf0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143bf4: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143bf4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143bf8: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143bf8u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143bfc: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143bfcu;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143c00: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x143c00u;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143c04: 0x70084e88  pextlb      $t1, $zero, $t0
    ctx->pc = 0x143c04u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x143c08: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143c08u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143c0c: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x143c0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x143c10: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x143c10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x143c14: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143c14u;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143c18: 0x700856e8  qfsrv       $t2, $zero, $t0
    ctx->pc = 0x143c18u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143c1c: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143c1cu;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143c20: 0x71285108  paddh       $t2, $t1, $t0
    ctx->pc = 0x143c20u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143c24: 0x71595108  paddh       $t2, $t2, $t9
    ctx->pc = 0x143c24u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x143c28: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x143c28u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143c2c: 0x79c80000  lq          $t0, 0x0($t6)
    ctx->pc = 0x143c2cu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x143c30: 0x71485108  paddh       $t2, $t2, $t0
    ctx->pc = 0x143c30u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 8)));
    // 0x143c34: 0x71404988  pcgth       $t1, $t2, $zero
    ctx->pc = 0x143c34u;
    SET_GPR_VEC(ctx, 9, PS2_PCGTH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143c38: 0x70094bf6  psrlh       $t1, $t1, 15
    ctx->pc = 0x143c38u;
    SET_GPR_VEC(ctx, 9, _mm_srli_epi16(GPR_VEC(ctx, 9), 15));
    // 0x143c3c: 0x71495108  paddh       $t2, $t2, $t1
    ctx->pc = 0x143c3cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 9)));
    // 0x143c40: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x143c40u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143c44: 0x7dca0000  sq          $t2, 0x0($t6)
    ctx->pc = 0x143c44u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 10));
    // 0x143c48: 0x1ce0ffe9  bgtz        $a3, . + 4 + (-0x17 << 2)
    ctx->pc = 0x143C48u;
    {
        const bool branch_taken_0x143c48 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143C4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143C48u;
            // 0x143c4c: 0x1c27021  addu        $t6, $t6, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143c48) {
            ctx->pc = 0x143BF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143bf0;
        }
    }
    ctx->pc = 0x143C50u;
    // 0x143c50: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x143c50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x143c54: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x143c54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x143c58: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143c58u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143c5c: 0x1675024  and         $t2, $t3, $a3
    ctx->pc = 0x143c5cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x143c60: 0x1540ffe3  bnez        $t2, . + 4 + (-0x1D << 2)
    ctx->pc = 0x143C60u;
    {
        const bool branch_taken_0x143c60 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143C60u;
            // 0x143c64: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143c60) {
            ctx->pc = 0x143BF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143bf0;
        }
    }
    ctx->pc = 0x143C68u;
    // 0x143c68: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143c68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143c6c: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143c6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143c70: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143c70u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143c74: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x143c74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x143c78: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x143c78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x143c7c: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x143c7cu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x143c80: 0x1580ffd9  bnez        $t4, . + 4 + (-0x27 << 2)
    ctx->pc = 0x143C80u;
    {
        const bool branch_taken_0x143c80 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x143C84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143C80u;
            // 0x143c84: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143c80) {
            ctx->pc = 0x143BE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143be8;
        }
    }
    ctx->pc = 0x143C88u;
    // 0x143c88: 0x3e00008  jr          $ra
    ctx->pc = 0x143C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x143C90u;
    // 0x143c90: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143c90u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143c94: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143c94u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143c98: 0x7019c874  psllh       $t9, $t9, 1
    ctx->pc = 0x143c98u;
    SET_GPR_VEC(ctx, 25, _mm_slli_epi16(GPR_VEC(ctx, 25), 1));
    // 0x143c9c: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143c9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143ca0: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143ca0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143ca4: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143ca4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143ca8: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143ca8u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143cac: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143cacu;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143cb0: 0x8c980010  lw          $t8, 0x10($a0)
    ctx->pc = 0x143cb0u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143cb4: 0x240c0001  addiu       $t4, $zero, 0x1
    ctx->pc = 0x143cb4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x143cb8: 0x78a80000  lq          $t0, 0x0($a1)
    ctx->pc = 0x143cb8u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143cbc: 0x78c90000  lq          $t1, 0x0($a2)
    ctx->pc = 0x143cbcu;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143cc0: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143cc0u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143cc4: 0x712856e8  qfsrv       $t2, $t1, $t0
    ctx->pc = 0x143cc4u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143cc8: 0x71097ee8  qfsrv       $t7, $t0, $t1
    ctx->pc = 0x143cc8u;
    SET_GPR_VEC(ctx, 15, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 9), ctx->sa & 0x7F));
    // 0x143ccc: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143cccu;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143cd0: 0x700a4ea8  pextub      $t1, $zero, $t2
    ctx->pc = 0x143cd0u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143cd4: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x143cd4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x143cd8: 0x5980000  mtsab       $t4, 0x0
    ctx->pc = 0x143cd8u;
    ctx->sa = ((GPR_U32(ctx, 12) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143cdc: 0x71ea7ee8  qfsrv       $t7, $t7, $t2
    ctx->pc = 0x143cdcu;
    SET_GPR_VEC(ctx, 15, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143ce0: 0x700f5688  pextlb      $t2, $zero, $t7
    ctx->pc = 0x143ce0u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 15)));
    // 0x143ce4: 0x700f7ea8  pextub      $t7, $zero, $t7
    ctx->pc = 0x143ce4u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 15)));
    // 0x143ce8: 0x710a4108  paddh       $t0, $t0, $t2
    ctx->pc = 0x143ce8u;
    SET_GPR_VEC(ctx, 8, PS2_PADDH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 10)));
    // 0x143cec: 0x10e00028  beqz        $a3, . + 4 + (0x28 << 2)
    ctx->pc = 0x143CECu;
    {
        const bool branch_taken_0x143cec = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x143CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143CECu;
            // 0x143cf0: 0x712f4908  paddh       $t1, $t1, $t7 (Delay Slot)
        SET_GPR_VEC(ctx, 9, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 15)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143cec) {
            ctx->pc = 0x143D90u;
            goto label_143d90;
        }
    }
    ctx->pc = 0x143CF4u;
label_143cf4:
    // 0x143cf4: 0xb82821  addu        $a1, $a1, $t8
    ctx->pc = 0x143cf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 24)));
    // 0x143cf8: 0xd83021  addu        $a2, $a2, $t8
    ctx->pc = 0x143cf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 24)));
    // 0x143cfc: 0x78aa0000  lq          $t2, 0x0($a1)
    ctx->pc = 0x143cfcu;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143d00: 0x78cf0000  lq          $t7, 0x0($a2)
    ctx->pc = 0x143d00u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143d04: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143d04u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143d08: 0x71ea16e8  qfsrv       $v0, $t7, $t2
    ctx->pc = 0x143d08u;
    SET_GPR_VEC(ctx, 2, PS2_QFSRV(GPR_VEC(ctx, 15), GPR_VEC(ctx, 10), ctx->sa & 0x7F));
    // 0x143d0c: 0x714f1ee8  qfsrv       $v1, $t2, $t7
    ctx->pc = 0x143d0cu;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15), ctx->sa & 0x7F));
    // 0x143d10: 0x70025688  pextlb      $t2, $zero, $v0
    ctx->pc = 0x143d10u;
    SET_GPR_VEC(ctx, 10, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143d14: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143d14u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143d18: 0x70027ea8  pextub      $t7, $zero, $v0
    ctx->pc = 0x143d18u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x143d1c: 0x5980000  mtsab       $t4, 0x0
    ctx->pc = 0x143d1cu;
    ctx->sa = ((GPR_U32(ctx, 12) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143d20: 0x70621ee8  qfsrv       $v1, $v1, $v0
    ctx->pc = 0x143d20u;
    SET_GPR_VEC(ctx, 3, PS2_QFSRV(GPR_VEC(ctx, 3), GPR_VEC(ctx, 2), ctx->sa & 0x7F));
    // 0x143d24: 0x70031688  pextlb      $v0, $zero, $v1
    ctx->pc = 0x143d24u;
    SET_GPR_VEC(ctx, 2, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x143d28: 0x70031ea8  pextub      $v1, $zero, $v1
    ctx->pc = 0x143d28u;
    SET_GPR_VEC(ctx, 3, PS2_PEXTUB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 3)));
    // 0x143d2c: 0x71425108  paddh       $t2, $t2, $v0
    ctx->pc = 0x143d2cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 2)));
    // 0x143d30: 0x71e37908  paddh       $t7, $t7, $v1
    ctx->pc = 0x143d30u;
    SET_GPR_VEC(ctx, 15, PS2_PADDH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 3)));
    // 0x143d34: 0x710a1108  paddh       $v0, $t0, $t2
    ctx->pc = 0x143d34u;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 10)));
    // 0x143d38: 0x712f1908  paddh       $v1, $t1, $t7
    ctx->pc = 0x143d38u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 15)));
    // 0x143d3c: 0x714044a9  por         $t0, $t2, $zero
    ctx->pc = 0x143d3cu;
    SET_GPR_VEC(ctx, 8, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143d40: 0x71e04ca9  por         $t1, $t7, $zero
    ctx->pc = 0x143d40u;
    SET_GPR_VEC(ctx, 9, PS2_POR(GPR_VEC(ctx, 15), GPR_VEC(ctx, 0)));
    // 0x143d44: 0x70591108  paddh       $v0, $v0, $t9
    ctx->pc = 0x143d44u;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x143d48: 0x70791908  paddh       $v1, $v1, $t9
    ctx->pc = 0x143d48u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 25)));
    // 0x143d4c: 0x700210b6  psrlh       $v0, $v0, 2
    ctx->pc = 0x143d4cu;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 2), 2));
    // 0x143d50: 0x700318b6  psrlh       $v1, $v1, 2
    ctx->pc = 0x143d50u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 3), 2));
    // 0x143d54: 0x79ca0000  lq          $t2, 0x0($t6)
    ctx->pc = 0x143d54u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x143d58: 0x79cf0010  lq          $t7, 0x10($t6)
    ctx->pc = 0x143d58u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 14), 16)));
    // 0x143d5c: 0x704a1108  paddh       $v0, $v0, $t2
    ctx->pc = 0x143d5cu;
    SET_GPR_VEC(ctx, 2, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 10)));
    // 0x143d60: 0x706f1908  paddh       $v1, $v1, $t7
    ctx->pc = 0x143d60u;
    SET_GPR_VEC(ctx, 3, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 15)));
    // 0x143d64: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143d64u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143d68: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143d68u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143d6c: 0x70595108  paddh       $t2, $v0, $t9
    ctx->pc = 0x143d6cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 2), GPR_VEC(ctx, 25)));
    // 0x143d70: 0x700a1076  psrlh       $v0, $t2, 1
    ctx->pc = 0x143d70u;
    SET_GPR_VEC(ctx, 2, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143d74: 0x70795108  paddh       $t2, $v1, $t9
    ctx->pc = 0x143d74u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 3), GPR_VEC(ctx, 25)));
    // 0x143d78: 0x700a1876  psrlh       $v1, $t2, 1
    ctx->pc = 0x143d78u;
    SET_GPR_VEC(ctx, 3, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143d7c: 0x7dc20000  sq          $v0, 0x0($t6)
    ctx->pc = 0x143d7cu;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 2));
    // 0x143d80: 0x185040  sll         $t2, $t8, 1
    ctx->pc = 0x143d80u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 24), 1));
    // 0x143d84: 0x7dc30010  sq          $v1, 0x10($t6)
    ctx->pc = 0x143d84u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 16), GPR_VEC(ctx, 3));
    // 0x143d88: 0x1ce0ffda  bgtz        $a3, . + 4 + (-0x26 << 2)
    ctx->pc = 0x143D88u;
    {
        const bool branch_taken_0x143d88 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143D88u;
            // 0x143d8c: 0x1ca7021  addu        $t6, $t6, $t2 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143d88) {
            ctx->pc = 0x143CF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143cf4;
        }
    }
    ctx->pc = 0x143D90u;
label_143d90:
    // 0x143d90: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x143d90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x143d94: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x143d94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x143d98: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143d98u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143d9c: 0x1675024  and         $t2, $t3, $a3
    ctx->pc = 0x143d9cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & GPR_U64(ctx, 7));
    // 0x143da0: 0x1540ffd4  bnez        $t2, . + 4 + (-0x2C << 2)
    ctx->pc = 0x143DA0u;
    {
        const bool branch_taken_0x143da0 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143DA0u;
            // 0x143da4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143da0) {
            ctx->pc = 0x143CF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143cf4;
        }
    }
    ctx->pc = 0x143DA8u;
    // 0x143da8: 0x3e00008  jr          $ra
    ctx->pc = 0x143DA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x143DB0u;
    // 0x143db0: 0x7000cce9  pnor        $t9, $zero, $zero
    ctx->pc = 0x143db0u;
    SET_GPR_VEC(ctx, 25, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x143db4: 0x7019cbf6  psrlh       $t9, $t9, 15
    ctx->pc = 0x143db4u;
    SET_GPR_VEC(ctx, 25, _mm_srli_epi16(GPR_VEC(ctx, 25), 15));
    // 0x143db8: 0x7019c874  psllh       $t9, $t9, 1
    ctx->pc = 0x143db8u;
    SET_GPR_VEC(ctx, 25, _mm_slli_epi16(GPR_VEC(ctx, 25), 1));
    // 0x143dbc: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143dbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143dc0: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143dc0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143dc4: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143dc4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143dc8: 0x8c8d0004  lw          $t5, 0x4($a0)
    ctx->pc = 0x143dc8u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x143dcc: 0x8c8c0010  lw          $t4, 0x10($a0)
    ctx->pc = 0x143dccu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x143dd0: 0x24180001  addiu       $t8, $zero, 0x1
    ctx->pc = 0x143dd0u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x143dd4: 0x240b0001  addiu       $t3, $zero, 0x1
    ctx->pc = 0x143dd4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_143dd8:
    // 0x143dd8: 0x8c870008  lw          $a3, 0x8($a0)
    ctx->pc = 0x143dd8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x143ddc: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143ddcu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143de0: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143de0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143de4: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143de4u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143de8: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143de8u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143dec: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x143decu;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143df0: 0x70084e88  pextlb      $t1, $zero, $t0
    ctx->pc = 0x143df0u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x143df4: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143df4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143df8: 0x356b8000  ori         $t3, $t3, 0x8000
    ctx->pc = 0x143df8u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)32768);
    // 0x143dfc: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143dfcu;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143e00: 0x700856e8  qfsrv       $t2, $zero, $t0
    ctx->pc = 0x143e00u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143e04: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143e04u;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143e08: 0x10e0001c  beqz        $a3, . + 4 + (0x1C << 2)
    ctx->pc = 0x143E08u;
    {
        const bool branch_taken_0x143e08 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x143E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143E08u;
            // 0x143e0c: 0x71287908  paddh       $t7, $t1, $t0 (Delay Slot)
        SET_GPR_VEC(ctx, 15, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143e08) {
            ctx->pc = 0x143E7Cu;
            goto label_143e7c;
        }
    }
    ctx->pc = 0x143E10u;
label_143e10:
    // 0x143e10: 0xcc3021  addu        $a2, $a2, $t4
    ctx->pc = 0x143e10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x143e14: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x143e14u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143e18: 0xdcc90000  ld          $t1, 0x0($a2)
    ctx->pc = 0x143e18u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143e1c: 0x71284389  pcpyld      $t0, $t1, $t0
    ctx->pc = 0x143e1cu;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143e20: 0x5b80000  mtsab       $t5, 0x0
    ctx->pc = 0x143e20u;
    ctx->sa = ((GPR_U32(ctx, 13) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143e24: 0x710846e8  qfsrv       $t0, $t0, $t0
    ctx->pc = 0x143e24u;
    SET_GPR_VEC(ctx, 8, PS2_QFSRV(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143e28: 0x70084e88  pextlb      $t1, $zero, $t0
    ctx->pc = 0x143e28u;
    SET_GPR_VEC(ctx, 9, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8)));
    // 0x143e2c: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x143e2cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x143e30: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x143e30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x143e34: 0x7180000  mtsab       $t8, 0x0
    ctx->pc = 0x143e34u;
    ctx->sa = ((GPR_U32(ctx, 24) ^ (uint32_t)0) & 0xF) << 3;
    // 0x143e38: 0x700856e8  qfsrv       $t2, $zero, $t0
    ctx->pc = 0x143e38u;
    SET_GPR_VEC(ctx, 10, PS2_QFSRV(GPR_VEC(ctx, 0), GPR_VEC(ctx, 8), ctx->sa & 0x7F));
    // 0x143e3c: 0x700a4688  pextlb      $t0, $zero, $t2
    ctx->pc = 0x143e3cu;
    SET_GPR_VEC(ctx, 8, PS2_PEXTLB(GPR_VEC(ctx, 0), GPR_VEC(ctx, 10)));
    // 0x143e40: 0x71285108  paddh       $t2, $t1, $t0
    ctx->pc = 0x143e40u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143e44: 0x714f4908  paddh       $t1, $t2, $t7
    ctx->pc = 0x143e44u;
    SET_GPR_VEC(ctx, 9, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 15)));
    // 0x143e48: 0x71407ca9  por         $t7, $t2, $zero
    ctx->pc = 0x143e48u;
    SET_GPR_VEC(ctx, 15, PS2_POR(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143e4c: 0x71395108  paddh       $t2, $t1, $t9
    ctx->pc = 0x143e4cu;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 25)));
    // 0x143e50: 0x700a50b6  psrlh       $t2, $t2, 2
    ctx->pc = 0x143e50u;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 2));
    // 0x143e54: 0x79c80000  lq          $t0, 0x0($t6)
    ctx->pc = 0x143e54u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x143e58: 0x71485108  paddh       $t2, $t2, $t0
    ctx->pc = 0x143e58u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 8)));
    // 0x143e5c: 0x71404988  pcgth       $t1, $t2, $zero
    ctx->pc = 0x143e5cu;
    SET_GPR_VEC(ctx, 9, PS2_PCGTH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 0)));
    // 0x143e60: 0x70094bf6  psrlh       $t1, $t1, 15
    ctx->pc = 0x143e60u;
    SET_GPR_VEC(ctx, 9, _mm_srli_epi16(GPR_VEC(ctx, 9), 15));
    // 0x143e64: 0x71495108  paddh       $t2, $t2, $t1
    ctx->pc = 0x143e64u;
    SET_GPR_VEC(ctx, 10, PS2_PADDH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 9)));
    // 0x143e68: 0xc4040  sll         $t0, $t4, 1
    ctx->pc = 0x143e68u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x143e6c: 0x700a5076  psrlh       $t2, $t2, 1
    ctx->pc = 0x143e6cu;
    SET_GPR_VEC(ctx, 10, _mm_srli_epi16(GPR_VEC(ctx, 10), 1));
    // 0x143e70: 0x7dca0000  sq          $t2, 0x0($t6)
    ctx->pc = 0x143e70u;
    WRITE128(ADD32(GPR_U32(ctx, 14), 0), GPR_VEC(ctx, 10));
    // 0x143e74: 0x1ce0ffe6  bgtz        $a3, . + 4 + (-0x1A << 2)
    ctx->pc = 0x143E74u;
    {
        const bool branch_taken_0x143e74 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x143E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143E74u;
            // 0x143e78: 0x1c87021  addu        $t6, $t6, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143e74) {
            ctx->pc = 0x143E10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143e10;
        }
    }
    ctx->pc = 0x143E7Cu;
label_143e7c:
    // 0x143e7c: 0x700b53f7  psrah       $t2, $t3, 15
    ctx->pc = 0x143e7cu;
    SET_GPR_VEC(ctx, 10, _mm_srai_epi16(GPR_VEC(ctx, 11), 15));
    // 0x143e80: 0x24a50140  addiu       $a1, $a1, 0x140
    ctx->pc = 0x143e80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 320));
    // 0x143e84: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x143e84u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x143e88: 0x24c60140  addiu       $a2, $a2, 0x140
    ctx->pc = 0x143e88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 320));
    // 0x143e8c: 0x1475024  and         $t2, $t2, $a3
    ctx->pc = 0x143e8cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & GPR_U64(ctx, 7));
    // 0x143e90: 0x1540ffdf  bnez        $t2, . + 4 + (-0x21 << 2)
    ctx->pc = 0x143E90u;
    {
        const bool branch_taken_0x143e90 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143E90u;
            // 0x143e94: 0x316b7fff  andi        $t3, $t3, 0x7FFF (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)32767);
        ctx->in_delay_slot = false;
        if (branch_taken_0x143e90) {
            ctx->pc = 0x143E10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143e10;
        }
    }
    ctx->pc = 0x143E98u;
    // 0x143e98: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x143e98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x143e9c: 0x8c860018  lw          $a2, 0x18($a0)
    ctx->pc = 0x143e9cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x143ea0: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x143ea0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x143ea4: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x143ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x143ea8: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x143ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x143eac: 0x25ce0080  addiu       $t6, $t6, 0x80
    ctx->pc = 0x143eacu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 128));
    // 0x143eb0: 0x316a0001  andi        $t2, $t3, 0x1
    ctx->pc = 0x143eb0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)1);
    // 0x143eb4: 0x1540ffc8  bnez        $t2, . + 4 + (-0x38 << 2)
    ctx->pc = 0x143EB4u;
    {
        const bool branch_taken_0x143eb4 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x143EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143EB4u;
            // 0x143eb8: 0x316bfffe  andi        $t3, $t3, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x143eb4) {
            ctx->pc = 0x143DD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143dd8;
        }
    }
    ctx->pc = 0x143EBCu;
    // 0x143ebc: 0x3e00008  jr          $ra
    ctx->pc = 0x143EBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x143EC4u;
    // 0x143ec4: 0x0  nop
    ctx->pc = 0x143ec4u;
    // NOP
label_143ec8:
    // 0x143ec8: 0x240c0018  addiu       $t4, $zero, 0x18
    ctx->pc = 0x143ec8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x143ecc: 0x3c0a0014  lui         $t2, 0x14
    ctx->pc = 0x143eccu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)20 << 16));
    // 0x143ed0: 0x254a3f70  addiu       $t2, $t2, 0x3F70
    ctx->pc = 0x143ed0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 16240));
    // 0x143ed4: 0x794b0000  lq          $t3, 0x0($t2)
    ctx->pc = 0x143ed4u;
    SET_GPR_VEC(ctx, 11, READ128(ADD32(GPR_U32(ctx, 10), 0)));
label_143ed8:
    // 0x143ed8: 0x78a80000  lq          $t0, 0x0($a1)
    ctx->pc = 0x143ed8u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143edc: 0x218cffff  addi        $t4, $t4, -0x1
    ctx->pc = 0x143edcu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 12), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 12, (int32_t)tmp); }
    // 0x143ee0: 0x78cd0000  lq          $t5, 0x0($a2)
    ctx->pc = 0x143ee0u;
    SET_GPR_VEC(ctx, 13, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x143ee4: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x143ee4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x143ee8: 0x78a90010  lq          $t1, 0x10($a1)
    ctx->pc = 0x143ee8u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x143eec: 0x710d4108  paddh       $t0, $t0, $t5
    ctx->pc = 0x143eecu;
    SET_GPR_VEC(ctx, 8, PS2_PADDH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 13)));
    // 0x143ef0: 0x78c20010  lq          $v0, 0x10($a2)
    ctx->pc = 0x143ef0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x143ef4: 0x710b41e8  pminh       $t0, $t0, $t3
    ctx->pc = 0x143ef4u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 11)));
    // 0x143ef8: 0x71224908  paddh       $t1, $t1, $v0
    ctx->pc = 0x143ef8u;
    SET_GPR_VEC(ctx, 9, PS2_PADDH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 2)));
    // 0x143efc: 0x710041c8  pmaxh       $t0, $t0, $zero
    ctx->pc = 0x143efcu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 0)));
    // 0x143f00: 0x712b49e8  pminh       $t1, $t1, $t3
    ctx->pc = 0x143f00u;
    SET_GPR_VEC(ctx, 9, PS2_PMINH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 11)));
    // 0x143f04: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x143f04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x143f08: 0x712049c8  pmaxh       $t1, $t1, $zero
    ctx->pc = 0x143f08u;
    SET_GPR_VEC(ctx, 9, PS2_PMAXH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 0)));
    // 0x143f0c: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x143f0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x143f10: 0x712856c8  ppacb       $t2, $t1, $t0
    ctx->pc = 0x143f10u;
    SET_GPR_VEC(ctx, 10, PS2_PPACB(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143f14: 0x1580fff0  bnez        $t4, . + 4 + (-0x10 << 2)
    ctx->pc = 0x143F14u;
    {
        const bool branch_taken_0x143f14 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x143F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143F14u;
            // 0x143f18: 0x7c8afff0  sq          $t2, -0x10($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 4294967280), GPR_VEC(ctx, 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143f14) {
            ctx->pc = 0x143ED8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143ed8;
        }
    }
    ctx->pc = 0x143F1Cu;
    // 0x143f1c: 0x3e00008  jr          $ra
    ctx->pc = 0x143F1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x143F24u;
    // 0x143f24: 0x0  nop
    ctx->pc = 0x143f24u;
    // NOP
label_143f28:
    // 0x143f28: 0x240c0018  addiu       $t4, $zero, 0x18
    ctx->pc = 0x143f28u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x143f2c: 0x3c0a0014  lui         $t2, 0x14
    ctx->pc = 0x143f2cu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)20 << 16));
    // 0x143f30: 0x254a3f70  addiu       $t2, $t2, 0x3F70
    ctx->pc = 0x143f30u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 16240));
    // 0x143f34: 0x794b0000  lq          $t3, 0x0($t2)
    ctx->pc = 0x143f34u;
    SET_GPR_VEC(ctx, 11, READ128(ADD32(GPR_U32(ctx, 10), 0)));
label_143f38:
    // 0x143f38: 0x78a80000  lq          $t0, 0x0($a1)
    ctx->pc = 0x143f38u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x143f3c: 0x218cffff  addi        $t4, $t4, -0x1
    ctx->pc = 0x143f3cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 12), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 12, (int32_t)tmp); }
    // 0x143f40: 0x710b41e8  pminh       $t0, $t0, $t3
    ctx->pc = 0x143f40u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 11)));
    // 0x143f44: 0x78a90010  lq          $t1, 0x10($a1)
    ctx->pc = 0x143f44u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x143f48: 0x710041c8  pmaxh       $t0, $t0, $zero
    ctx->pc = 0x143f48u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 0)));
    // 0x143f4c: 0x712b49e8  pminh       $t1, $t1, $t3
    ctx->pc = 0x143f4cu;
    SET_GPR_VEC(ctx, 9, PS2_PMINH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 11)));
    // 0x143f50: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x143f50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x143f54: 0x712049c8  pmaxh       $t1, $t1, $zero
    ctx->pc = 0x143f54u;
    SET_GPR_VEC(ctx, 9, PS2_PMAXH(GPR_VEC(ctx, 9), GPR_VEC(ctx, 0)));
    // 0x143f58: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x143f58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x143f5c: 0x712856c8  ppacb       $t2, $t1, $t0
    ctx->pc = 0x143f5cu;
    SET_GPR_VEC(ctx, 10, PS2_PPACB(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x143f60: 0x1580fff5  bnez        $t4, . + 4 + (-0xB << 2)
    ctx->pc = 0x143F60u;
    {
        const bool branch_taken_0x143f60 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x143F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143F60u;
            // 0x143f64: 0x7c8afff0  sq          $t2, -0x10($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 4294967280), GPR_VEC(ctx, 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x143f60) {
            ctx->pc = 0x143F38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_143f38;
        }
    }
    ctx->pc = 0x143F68u;
    // 0x143f68: 0x0  nop
    ctx->pc = 0x143f68u;
    // NOP
    // 0x143f6c: 0x0  nop
    ctx->pc = 0x143f6cu;
    // NOP
    // 0x143f70: 0xff00ff  .word       0x00FF00FF                   # dsra32      $zero, $ra, 3 # 00E00000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x143f70u;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 31) >> (32 + 3));
    // 0x143f74: 0xff00ff  .word       0x00FF00FF                   # dsra32      $zero, $ra, 3 # 00E00000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x143f74u;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 31) >> (32 + 3));
    // 0x143f78: 0xff00ff  .word       0x00FF00FF                   # dsra32      $zero, $ra, 3 # 00E00000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x143f78u;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 31) >> (32 + 3));
    // 0x143f7c: 0xff00ff  .word       0x00FF00FF                   # dsra32      $zero, $ra, 3 # 00E00000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x143f7cu;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 31) >> (32 + 3));
    // 0x143f80: 0x3e00008  jr          $ra
    ctx->pc = 0x143F80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x143030u: goto label_143030;
            case 0x143068u: goto label_143068;
            case 0x14307Cu: goto label_14307c;
            case 0x14309Cu: goto label_14309c;
            case 0x1430ACu: goto label_1430ac;
            case 0x1430B8u: goto label_1430b8;
            case 0x1430BCu: goto label_1430bc;
            case 0x1430F0u: goto label_1430f0;
            case 0x143150u: goto label_143150;
            case 0x143194u: goto label_143194;
            case 0x1431FCu: goto label_1431fc;
            case 0x143270u: goto label_143270;
            case 0x143278u: goto label_143278;
            case 0x14332Cu: goto label_14332c;
            case 0x14337Cu: goto label_14337c;
            case 0x1433C8u: goto label_1433c8;
            case 0x1433E8u: goto label_1433e8;
            case 0x143424u: goto label_143424;
            case 0x14349Cu: goto label_14349c;
            case 0x143548u: goto label_143548;
            case 0x143550u: goto label_143550;
            case 0x14363Cu: goto label_14363c;
            case 0x1436B0u: goto label_1436b0;
            case 0x1436F8u: goto label_1436f8;
            case 0x143730u: goto label_143730;
            case 0x143784u: goto label_143784;
            case 0x1437F4u: goto label_1437f4;
            case 0x143890u: goto label_143890;
            case 0x143898u: goto label_143898;
            case 0x143964u: goto label_143964;
            case 0x1439DCu: goto label_1439dc;
            case 0x143A28u: goto label_143a28;
            case 0x143A48u: goto label_143a48;
            case 0x143A9Cu: goto label_143a9c;
            case 0x143B14u: goto label_143b14;
            case 0x143BE8u: goto label_143be8;
            case 0x143BF0u: goto label_143bf0;
            case 0x143CF4u: goto label_143cf4;
            case 0x143D90u: goto label_143d90;
            case 0x143DD8u: goto label_143dd8;
            case 0x143E10u: goto label_143e10;
            case 0x143E7Cu: goto label_143e7c;
            case 0x143EC8u: goto label_143ec8;
            case 0x143ED8u: goto label_143ed8;
            case 0x143F28u: goto label_143f28;
            case 0x143F38u: goto label_143f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x143F88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
