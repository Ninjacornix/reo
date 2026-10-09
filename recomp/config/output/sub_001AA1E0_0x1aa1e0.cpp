#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AA1E0
// Address: 0x1aa1e0 - 0x1aa3d0
void sub_001AA1E0_0x1aa1e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AA1E0_0x1aa1e0");
#endif

    switch (ctx->pc) {
        case 0x1aa228u: goto label_1aa228;
        case 0x1aa278u: goto label_1aa278;
        case 0x1aa2a0u: goto label_1aa2a0;
        case 0x1aa2b4u: goto label_1aa2b4;
        case 0x1aa2dcu: goto label_1aa2dc;
        case 0x1aa2f8u: goto label_1aa2f8;
        case 0x1aa304u: goto label_1aa304;
        case 0x1aa310u: goto label_1aa310;
        case 0x1aa31cu: goto label_1aa31c;
        case 0x1aa338u: goto label_1aa338;
        case 0x1aa354u: goto label_1aa354;
        case 0x1aa360u: goto label_1aa360;
        case 0x1aa37cu: goto label_1aa37c;
        default: break;
    }

    ctx->pc = 0x1aa1e0u;

    // 0x1aa1e0: 0x27bdfee0  addiu       $sp, $sp, -0x120
    ctx->pc = 0x1aa1e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x1aa1e4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa1e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa1e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1aa1e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1aa1ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aa1ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aa1f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1aa1f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa1f4: 0x8c2416a0  lw          $a0, 0x16A0($at)
    ctx->pc = 0x1aa1f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa1f8: 0x10800070  beqz        $a0, . + 4 + (0x70 << 2)
    ctx->pc = 0x1AA1F8u;
    {
        const bool branch_taken_0x1aa1f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa1f8) {
            ctx->pc = 0x1AA3BCu;
            goto label_1aa3bc;
        }
    }
    ctx->pc = 0x1AA200u;
    // 0x1aa200: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1aa200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1aa204: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AA204u;
    {
        const bool branch_taken_0x1aa204 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA204u;
            // 0x1aa208: 0x24850008  addiu       $a1, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa204) {
            ctx->pc = 0x1AA218u;
            goto label_1aa218;
        }
    }
    ctx->pc = 0x1AA20Cu;
    // 0x1aa20c: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x1aa20cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1aa210: 0x1070006a  beq         $v1, $s0, . + 4 + (0x6A << 2)
    ctx->pc = 0x1AA210u;
    {
        const bool branch_taken_0x1aa210 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 16));
        if (branch_taken_0x1aa210) {
            ctx->pc = 0x1AA3BCu;
            goto label_1aa3bc;
        }
    }
    ctx->pc = 0x1AA218u;
label_1aa218:
    // 0x1aa218: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa218u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa21c: 0x8c22444c  lw          $v0, 0x444C($at)
    ctx->pc = 0x1aa21cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17484)));
    // 0x1aa220: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AA220u;
    {
        const bool branch_taken_0x1aa220 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aa220) {
            ctx->pc = 0x1AA244u;
            goto label_1aa244;
        }
    }
    ctx->pc = 0x1AA228u;
label_1aa228:
    // 0x1aa228: 0x0  nop
    ctx->pc = 0x1aa228u;
    // NOP
    // 0x1aa22c: 0x0  nop
    ctx->pc = 0x1aa22cu;
    // NOP
    // 0x1aa230: 0x0  nop
    ctx->pc = 0x1aa230u;
    // NOP
    // 0x1aa234: 0x0  nop
    ctx->pc = 0x1aa234u;
    // NOP
    // 0x1aa238: 0x0  nop
    ctx->pc = 0x1aa238u;
    // NOP
    // 0x1aa23c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AA23Cu;
    {
        const bool branch_taken_0x1aa23c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa23c) {
            ctx->pc = 0x1AA228u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa228;
        }
    }
    ctx->pc = 0x1AA244u;
label_1aa244:
    // 0x1aa244: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1aa244u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1aa248: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aa248u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aa24c: 0x8c24444c  lw          $a0, 0x444C($at)
    ctx->pc = 0x1aa24cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17484)));
    // 0x1aa250: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1aa250u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1aa254: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa254u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa258: 0x24846000  addiu       $a0, $a0, 0x6000
    ctx->pc = 0x1aa258u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24576));
    // 0x1aa25c: 0x8c2316a0  lw          $v1, 0x16A0($at)
    ctx->pc = 0x1aa25cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa260: 0x16020007  bne         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AA260u;
    {
        const bool branch_taken_0x1aa260 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AA264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA260u;
            // 0x1aa264: 0xac64000c  sw          $a0, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa260) {
            ctx->pc = 0x1AA280u;
            goto label_1aa280;
        }
    }
    ctx->pc = 0x1AA268u;
    // 0x1aa268: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa268u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa26c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1aa26cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1aa270: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1AA270u;
    SET_GPR_U32(ctx, 31, 0x1AA278u);
    ctx->pc = 0x1AA274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA270u;
            // 0x1aa274: 0x24a5cfb0  addiu       $a1, $a1, -0x3050 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA278u; }
        if (ctx->pc != 0x1AA278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA278u; }
        if (ctx->pc != 0x1AA278u) { return; }
    }
    ctx->pc = 0x1AA278u;
label_1aa278:
    // 0x1aa278: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1AA278u;
    {
        const bool branch_taken_0x1aa278 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa278) {
            ctx->pc = 0x1AA2A0u;
            goto label_1aa2a0;
        }
    }
    ctx->pc = 0x1AA280u;
label_1aa280:
    // 0x1aa280: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa280u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa284: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aa284u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aa288: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1aa288u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1aa28c: 0x24a5cfc0  addiu       $a1, $a1, -0x3040
    ctx->pc = 0x1aa28cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954944));
    // 0x1aa290: 0x24c6cfd8  addiu       $a2, $a2, -0x3028
    ctx->pc = 0x1aa290u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294954968));
    // 0x1aa294: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1aa294u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa298: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA298u;
    SET_GPR_U32(ctx, 31, 0x1AA2A0u);
    ctx->pc = 0x1AA29Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA298u;
            // 0x1aa29c: 0x200402d  daddu       $t0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2A0u; }
        if (ctx->pc != 0x1AA2A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2A0u; }
        if (ctx->pc != 0x1AA2A0u) { return; }
    }
    ctx->pc = 0x1AA2A0u;
label_1aa2a0:
    // 0x1aa2a0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa2a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa2a4: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1aa2a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1aa2a8: 0x8c2516a0  lw          $a1, 0x16A0($at)
    ctx->pc = 0x1aa2a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa2ac: 0xc06a758  jal         func_1A9D60
    ctx->pc = 0x1AA2ACu;
    SET_GPR_U32(ctx, 31, 0x1AA2B4u);
    ctx->pc = 0x1AA2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA2ACu;
            // 0x1aa2b0: 0x24066000  addiu       $a2, $zero, 0x6000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9D60u;
    if (runtime->hasFunction(0x1A9D60u)) {
        auto targetFn = runtime->lookupFunction(0x1A9D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2B4u; }
        if (ctx->pc != 0x1AA2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9D60_0x1a9d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2B4u; }
        if (ctx->pc != 0x1AA2B4u) { return; }
    }
    ctx->pc = 0x1AA2B4u;
label_1aa2b4:
    // 0x1aa2b4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa2b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa2b8: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1aa2b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1aa2bc: 0x8c2316a0  lw          $v1, 0x16A0($at)
    ctx->pc = 0x1aa2bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa2c0: 0x16020008  bne         $s0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AA2C0u;
    {
        const bool branch_taken_0x1aa2c0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AA2C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA2C0u;
            // 0x1aa2c4: 0xac70001c  sw          $s0, 0x1C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa2c0) {
            ctx->pc = 0x1AA2E4u;
            goto label_1aa2e4;
        }
    }
    ctx->pc = 0x1AA2C8u;
    // 0x1aa2c8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa2c8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa2cc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1aa2ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa2d0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1aa2d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1aa2d4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA2D4u;
    SET_GPR_U32(ctx, 31, 0x1AA2DCu);
    ctx->pc = 0x1AA2D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA2D4u;
            // 0x1aa2d8: 0x24a5cfe8  addiu       $a1, $a1, -0x3018 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954984));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2DCu; }
        if (ctx->pc != 0x1AA2DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2DCu; }
        if (ctx->pc != 0x1AA2DCu) { return; }
    }
    ctx->pc = 0x1AA2DCu;
label_1aa2dc:
    // 0x1aa2dc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1AA2DCu;
    {
        const bool branch_taken_0x1aa2dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AA2E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA2DCu;
            // 0x1aa2e0: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa2dc) {
            ctx->pc = 0x1AA2FCu;
            goto label_1aa2fc;
        }
    }
    ctx->pc = 0x1AA2E4u;
label_1aa2e4:
    // 0x1aa2e4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aa2e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aa2e8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1aa2e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa2ec: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1aa2ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1aa2f0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AA2F0u;
    SET_GPR_U32(ctx, 31, 0x1AA2F8u);
    ctx->pc = 0x1AA2F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA2F0u;
            // 0x1aa2f4: 0x24a5cff8  addiu       $a1, $a1, -0x3008 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2F8u; }
        if (ctx->pc != 0x1AA2F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA2F8u; }
        if (ctx->pc != 0x1AA2F8u) { return; }
    }
    ctx->pc = 0x1AA2F8u;
label_1aa2f8:
    // 0x1aa2f8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1aa2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
label_1aa2fc:
    // 0x1aa2fc: 0xc06a678  jal         func_1A99E0
    ctx->pc = 0x1AA2FCu;
    SET_GPR_U32(ctx, 31, 0x1AA304u);
    ctx->pc = 0x1A99E0u;
    if (runtime->hasFunction(0x1A99E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A99E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA304u; }
        if (ctx->pc != 0x1AA304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A99E0_0x1a99e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA304u; }
        if (ctx->pc != 0x1AA304u) { return; }
    }
    ctx->pc = 0x1AA304u;
label_1aa304:
    // 0x1aa304: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1aa304u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa308: 0x600002c  bltz        $s0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1AA308u;
    {
        const bool branch_taken_0x1aa308 = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x1aa308) {
            ctx->pc = 0x1AA3BCu;
            goto label_1aa3bc;
        }
    }
    ctx->pc = 0x1AA310u;
label_1aa310:
    // 0x1aa310: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x1aa310u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1aa314: 0xc04a490  jal         func_129240
    ctx->pc = 0x1AA314u;
    SET_GPR_U32(ctx, 31, 0x1AA31Cu);
    ctx->pc = 0x1AA318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA314u;
            // 0x1aa318: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129240u;
    if (runtime->hasFunction(0x129240u)) {
        auto targetFn = runtime->lookupFunction(0x129240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA31Cu; }
        if (ctx->pc != 0x1AA31Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129240_0x129240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA31Cu; }
        if (ctx->pc != 0x1AA31Cu) { return; }
    }
    ctx->pc = 0x1AA31Cu;
label_1aa31c:
    // 0x1aa31c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa31cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa320: 0xac2216a8  sw          $v0, 0x16A8($at)
    ctx->pc = 0x1aa320u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 5800), GPR_U32(ctx, 2));
    // 0x1aa324: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AA324u;
    {
        const bool branch_taken_0x1aa324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa324) {
            ctx->pc = 0x1AA310u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa310;
        }
    }
    ctx->pc = 0x1AA32Cu;
    // 0x1aa32c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa32cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa330: 0xc04a702  jal         func_129C08
    ctx->pc = 0x1AA330u;
    SET_GPR_U32(ctx, 31, 0x1AA338u);
    ctx->pc = 0x1AA334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA330u;
            // 0x1aa334: 0x8c2416a8  lw          $a0, 0x16A8($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5800)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129C08u;
    if (runtime->hasFunction(0x129C08u)) {
        auto targetFn = runtime->lookupFunction(0x129C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA338u; }
        if (ctx->pc != 0x1AA338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129C08_0x129c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA338u; }
        if (ctx->pc != 0x1AA338u) { return; }
    }
    ctx->pc = 0x1AA338u;
label_1aa338:
    // 0x1aa338: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1aa338u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aa33c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa33cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa340: 0x8c2216a0  lw          $v0, 0x16A0($at)
    ctx->pc = 0x1aa340u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa344: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa344u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa348: 0x8c2416a8  lw          $a0, 0x16A8($at)
    ctx->pc = 0x1aa348u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5800)));
    // 0x1aa34c: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x1AA34Cu;
    SET_GPR_U32(ctx, 31, 0x1AA354u);
    ctx->pc = 0x1AA350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA34Cu;
            // 0x1aa350: 0x8c46000c  lw          $a2, 0xC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA354u; }
        if (ctx->pc != 0x1AA354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA354u; }
        if (ctx->pc != 0x1AA354u) { return; }
    }
    ctx->pc = 0x1AA354u;
label_1aa354:
    // 0x1aa354: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa358: 0xc04a752  jal         func_129D48
    ctx->pc = 0x1AA358u;
    SET_GPR_U32(ctx, 31, 0x1AA360u);
    ctx->pc = 0x1AA35Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA358u;
            // 0x1aa35c: 0x8c2416a8  lw          $a0, 0x16A8($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5800)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA360u; }
        if (ctx->pc != 0x1AA360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA360u; }
        if (ctx->pc != 0x1AA360u) { return; }
    }
    ctx->pc = 0x1AA360u;
label_1aa360:
    // 0x1aa360: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1aa360u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1aa364: 0x0  nop
    ctx->pc = 0x1aa364u;
    // NOP
    // 0x1aa368: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AA368u;
    {
        const bool branch_taken_0x1aa368 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1aa368) {
            ctx->pc = 0x1AA354u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa354;
        }
    }
    ctx->pc = 0x1AA370u;
    // 0x1aa370: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa370u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa374: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1AA374u;
    SET_GPR_U32(ctx, 31, 0x1AA37Cu);
    ctx->pc = 0x1AA378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA374u;
            // 0x1aa378: 0x8c2416a8  lw          $a0, 0x16A8($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5800)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA37Cu; }
        if (ctx->pc != 0x1AA37Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA37Cu; }
        if (ctx->pc != 0x1AA37Cu) { return; }
    }
    ctx->pc = 0x1AA37Cu;
label_1aa37c:
    // 0x1aa37c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa37cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa380: 0xac2016a8  sw          $zero, 0x16A8($at)
    ctx->pc = 0x1aa380u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 5800), GPR_U32(ctx, 0));
    // 0x1aa384: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa388: 0x8c2416a0  lw          $a0, 0x16A0($at)
    ctx->pc = 0x1aa388u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa38c: 0x8c85000c  lw          $a1, 0xC($a0)
    ctx->pc = 0x1aa38cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1aa390: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa390u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa394: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1aa394u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1aa398: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x1aa398u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x1aa39c: 0x8c2316a0  lw          $v1, 0x16A0($at)
    ctx->pc = 0x1aa39cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa3a0: 0x8ca40004  lw          $a0, 0x4($a1)
    ctx->pc = 0x1aa3a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1aa3a4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa3a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa3a8: 0xac640014  sw          $a0, 0x14($v1)
    ctx->pc = 0x1aa3a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 4));
    // 0x1aa3ac: 0x8c2416a0  lw          $a0, 0x16A0($at)
    ctx->pc = 0x1aa3acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1aa3b0: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x1aa3b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1aa3b4: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1aa3b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1aa3b8: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x1aa3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
label_1aa3bc:
    // 0x1aa3bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1aa3bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aa3c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aa3c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aa3c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA3C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AA3C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA3C4u;
            // 0x1aa3c8: 0x27bd0120  addiu       $sp, $sp, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 288));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AA218u: goto label_1aa218;
            case 0x1AA228u: goto label_1aa228;
            case 0x1AA244u: goto label_1aa244;
            case 0x1AA278u: goto label_1aa278;
            case 0x1AA280u: goto label_1aa280;
            case 0x1AA2A0u: goto label_1aa2a0;
            case 0x1AA2B4u: goto label_1aa2b4;
            case 0x1AA2DCu: goto label_1aa2dc;
            case 0x1AA2E4u: goto label_1aa2e4;
            case 0x1AA2F8u: goto label_1aa2f8;
            case 0x1AA2FCu: goto label_1aa2fc;
            case 0x1AA304u: goto label_1aa304;
            case 0x1AA310u: goto label_1aa310;
            case 0x1AA31Cu: goto label_1aa31c;
            case 0x1AA338u: goto label_1aa338;
            case 0x1AA354u: goto label_1aa354;
            case 0x1AA360u: goto label_1aa360;
            case 0x1AA37Cu: goto label_1aa37c;
            case 0x1AA3BCu: goto label_1aa3bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AA3CCu;
    // 0x1aa3cc: 0x0  nop
    ctx->pc = 0x1aa3ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
