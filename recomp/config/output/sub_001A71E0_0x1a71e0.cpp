#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A71E0
// Address: 0x1a71e0 - 0x1a7310
void sub_001A71E0_0x1a71e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A71E0_0x1a71e0");
#endif

    switch (ctx->pc) {
        case 0x1a7208u: goto label_1a7208;
        case 0x1a7218u: goto label_1a7218;
        case 0x1a722cu: goto label_1a722c;
        case 0x1a7240u: goto label_1a7240;
        case 0x1a7250u: goto label_1a7250;
        case 0x1a727cu: goto label_1a727c;
        case 0x1a7290u: goto label_1a7290;
        case 0x1a72b4u: goto label_1a72b4;
        case 0x1a72c8u: goto label_1a72c8;
        case 0x1a72f4u: goto label_1a72f4;
        default: break;
    }

    ctx->pc = 0x1a71e0u;

    // 0x1a71e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a71e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a71e4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a71e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a71e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a71e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a71ec: 0x8c220a58  lw          $v0, 0xA58($at)
    ctx->pc = 0x1a71ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2648)));
    // 0x1a71f0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A71F0u;
    {
        const bool branch_taken_0x1a71f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A71F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A71F0u;
            // 0x1a71f4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a71f0) {
            ctx->pc = 0x1A7200u;
            goto label_1a7200;
        }
    }
    ctx->pc = 0x1A71F8u;
    // 0x1a71f8: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1A71F8u;
    {
        const bool branch_taken_0x1a71f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A71FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A71F8u;
            // 0x1a71fc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a71f8) {
            ctx->pc = 0x1A72FCu;
            goto label_1a72fc;
        }
    }
    ctx->pc = 0x1A7200u;
label_1a7200:
    // 0x1a7200: 0xc069c48  jal         func_1A7120
    ctx->pc = 0x1A7200u;
    SET_GPR_U32(ctx, 31, 0x1A7208u);
    ctx->pc = 0x1A7120u;
    if (runtime->hasFunction(0x1A7120u)) {
        auto targetFn = runtime->lookupFunction(0x1A7120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7208u; }
        if (ctx->pc != 0x1A7208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7120_0x1a7120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7208u; }
        if (ctx->pc != 0x1A7208u) { return; }
    }
    ctx->pc = 0x1A7208u;
label_1a7208:
    // 0x1a7208: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a7208u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a720c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a720cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7210: 0xc069c5c  jal         func_1A7170
    ctx->pc = 0x1A7210u;
    SET_GPR_U32(ctx, 31, 0x1A7218u);
    ctx->pc = 0x1A7214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7210u;
            // 0x1a7214: 0x24840c30  addiu       $a0, $a0, 0xC30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7170u;
    if (runtime->hasFunction(0x1A7170u)) {
        auto targetFn = runtime->lookupFunction(0x1A7170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7218u; }
        if (ctx->pc != 0x1A7218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7170_0x1a7170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7218u; }
        if (ctx->pc != 0x1A7218u) { return; }
    }
    ctx->pc = 0x1A7218u;
label_1a7218:
    // 0x1a7218: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7218u;
    {
        const bool branch_taken_0x1a7218 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A721Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7218u;
            // 0x1a721c: 0x3c04002b  lui         $a0, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7218) {
            ctx->pc = 0x1A7234u;
            goto label_1a7234;
        }
    }
    ctx->pc = 0x1A7220u;
    // 0x1a7220: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7220u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7224: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7224u;
    SET_GPR_U32(ctx, 31, 0x1A722Cu);
    ctx->pc = 0x1A7228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7224u;
            // 0x1a7228: 0x24841fa0  addiu       $a0, $a0, 0x1FA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A722Cu; }
        if (ctx->pc != 0x1A722Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A722Cu; }
        if (ctx->pc != 0x1A722Cu) { return; }
    }
    ctx->pc = 0x1A722Cu;
label_1a722c:
    // 0x1a722c: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1A722Cu;
    {
        const bool branch_taken_0x1a722c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A722Cu;
            // 0x1a7230: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a722c) {
            ctx->pc = 0x1A72F8u;
            goto label_1a72f8;
        }
    }
    ctx->pc = 0x1A7234u;
label_1a7234:
    // 0x1a7234: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1a7234u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a7238: 0xc069c5c  jal         func_1A7170
    ctx->pc = 0x1A7238u;
    SET_GPR_U32(ctx, 31, 0x1A7240u);
    ctx->pc = 0x1A723Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7238u;
            // 0x1a723c: 0x24840c00  addiu       $a0, $a0, 0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7170u;
    if (runtime->hasFunction(0x1A7170u)) {
        auto targetFn = runtime->lookupFunction(0x1A7170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7240u; }
        if (ctx->pc != 0x1A7240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7170_0x1a7170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7240u; }
        if (ctx->pc != 0x1A7240u) { return; }
    }
    ctx->pc = 0x1A7240u;
label_1a7240:
    // 0x1a7240: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A7240u;
    {
        const bool branch_taken_0x1a7240 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A7244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7240u;
            // 0x1a7244: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7240) {
            ctx->pc = 0x1A7258u;
            goto label_1a7258;
        }
    }
    ctx->pc = 0x1A7248u;
    // 0x1a7248: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7248u;
    SET_GPR_U32(ctx, 31, 0x1A7250u);
    ctx->pc = 0x1A724Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7248u;
            // 0x1a724c: 0x24841fe0  addiu       $a0, $a0, 0x1FE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7250u; }
        if (ctx->pc != 0x1A7250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7250u; }
        if (ctx->pc != 0x1A7250u) { return; }
    }
    ctx->pc = 0x1A7250u;
label_1a7250:
    // 0x1a7250: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1A7250u;
    {
        const bool branch_taken_0x1a7250 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7250u;
            // 0x1a7254: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7250) {
            ctx->pc = 0x1A72F8u;
            goto label_1a72f8;
        }
    }
    ctx->pc = 0x1A7258u;
label_1a7258:
    // 0x1a7258: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a7258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a725c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a725cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a7260: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x1a7260u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1a7264: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x1a7264u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x1a7268: 0x8c221180  lw          $v0, 0x1180($at)
    ctx->pc = 0x1a7268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4480)));
    // 0x1a726c: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1A726Cu;
    {
        const bool branch_taken_0x1a726c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A7270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A726Cu;
            // 0x1a7270: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a726c) {
            ctx->pc = 0x1A729Cu;
            goto label_1a729c;
        }
    }
    ctx->pc = 0x1A7274u;
    // 0x1a7274: 0xc045188  jal         func_114620
    ctx->pc = 0x1A7274u;
    SET_GPR_U32(ctx, 31, 0x1A727Cu);
    ctx->pc = 0x1A7278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7274u;
            // 0x1a7278: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A727Cu; }
        if (ctx->pc != 0x1A727Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A727Cu; }
        if (ctx->pc != 0x1A727Cu) { return; }
    }
    ctx->pc = 0x1A727Cu;
label_1a727c:
    // 0x1a727c: 0x1c400006  bgtz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A727Cu;
    {
        const bool branch_taken_0x1a727c = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1A7280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A727Cu;
            // 0x1a7280: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a727c) {
            ctx->pc = 0x1A7298u;
            goto label_1a7298;
        }
    }
    ctx->pc = 0x1A7284u;
    // 0x1a7284: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7284u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7288: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7288u;
    SET_GPR_U32(ctx, 31, 0x1A7290u);
    ctx->pc = 0x1A728Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7288u;
            // 0x1a728c: 0x24842020  addiu       $a0, $a0, 0x2020 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7290u; }
        if (ctx->pc != 0x1A7290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7290u; }
        if (ctx->pc != 0x1A7290u) { return; }
    }
    ctx->pc = 0x1A7290u;
label_1a7290:
    // 0x1a7290: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1A7290u;
    {
        const bool branch_taken_0x1a7290 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7290u;
            // 0x1a7294: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7290) {
            ctx->pc = 0x1A72F8u;
            goto label_1a72f8;
        }
    }
    ctx->pc = 0x1A7298u;
label_1a7298:
    // 0x1a7298: 0xac221180  sw          $v0, 0x1180($at)
    ctx->pc = 0x1a7298u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4480), GPR_U32(ctx, 2));
label_1a729c:
    // 0x1a729c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a729cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a72a0: 0x8c221188  lw          $v0, 0x1188($at)
    ctx->pc = 0x1a72a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4488)));
    // 0x1a72a4: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1A72A4u;
    {
        const bool branch_taken_0x1a72a4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1a72a4) {
            ctx->pc = 0x1A72D4u;
            goto label_1a72d4;
        }
    }
    ctx->pc = 0x1A72ACu;
    // 0x1a72ac: 0xc045188  jal         func_114620
    ctx->pc = 0x1A72ACu;
    SET_GPR_U32(ctx, 31, 0x1A72B4u);
    ctx->pc = 0x1A72B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A72ACu;
            // 0x1a72b0: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A72B4u; }
        if (ctx->pc != 0x1A72B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A72B4u; }
        if (ctx->pc != 0x1A72B4u) { return; }
    }
    ctx->pc = 0x1A72B4u;
label_1a72b4:
    // 0x1a72b4: 0x1c400006  bgtz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A72B4u;
    {
        const bool branch_taken_0x1a72b4 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1A72B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A72B4u;
            // 0x1a72b8: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a72b4) {
            ctx->pc = 0x1A72D0u;
            goto label_1a72d0;
        }
    }
    ctx->pc = 0x1A72BCu;
    // 0x1a72bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a72bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a72c0: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A72C0u;
    SET_GPR_U32(ctx, 31, 0x1A72C8u);
    ctx->pc = 0x1A72C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A72C0u;
            // 0x1a72c4: 0x24842050  addiu       $a0, $a0, 0x2050 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A72C8u; }
        if (ctx->pc != 0x1A72C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A72C8u; }
        if (ctx->pc != 0x1A72C8u) { return; }
    }
    ctx->pc = 0x1A72C8u;
label_1a72c8:
    // 0x1a72c8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A72C8u;
    {
        const bool branch_taken_0x1a72c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A72CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A72C8u;
            // 0x1a72cc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a72c8) {
            ctx->pc = 0x1A72F8u;
            goto label_1a72f8;
        }
    }
    ctx->pc = 0x1A72D0u;
label_1a72d0:
    // 0x1a72d0: 0xac221188  sw          $v0, 0x1188($at)
    ctx->pc = 0x1a72d0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4488), GPR_U32(ctx, 2));
label_1a72d4:
    // 0x1a72d4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a72d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a72d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a72d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a72dc: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a72dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a72e0: 0x24842080  addiu       $a0, $a0, 0x2080
    ctx->pc = 0x1a72e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8320));
    // 0x1a72e4: 0xac220a58  sw          $v0, 0xA58($at)
    ctx->pc = 0x1a72e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2648), GPR_U32(ctx, 2));
    // 0x1a72e8: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1a72e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a72ec: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A72ECu;
    SET_GPR_U32(ctx, 31, 0x1A72F4u);
    ctx->pc = 0x1A72F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A72ECu;
            // 0x1a72f0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A72F4u; }
        if (ctx->pc != 0x1A72F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A72F4u; }
        if (ctx->pc != 0x1A72F4u) { return; }
    }
    ctx->pc = 0x1A72F4u;
label_1a72f4:
    // 0x1a72f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a72f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a72f8:
    // 0x1a72f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a72f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a72fc:
    // 0x1a72fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A72FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A72FCu;
            // 0x1a7300: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7200u: goto label_1a7200;
            case 0x1A7208u: goto label_1a7208;
            case 0x1A7218u: goto label_1a7218;
            case 0x1A722Cu: goto label_1a722c;
            case 0x1A7234u: goto label_1a7234;
            case 0x1A7240u: goto label_1a7240;
            case 0x1A7250u: goto label_1a7250;
            case 0x1A7258u: goto label_1a7258;
            case 0x1A727Cu: goto label_1a727c;
            case 0x1A7290u: goto label_1a7290;
            case 0x1A7298u: goto label_1a7298;
            case 0x1A729Cu: goto label_1a729c;
            case 0x1A72B4u: goto label_1a72b4;
            case 0x1A72C8u: goto label_1a72c8;
            case 0x1A72D0u: goto label_1a72d0;
            case 0x1A72D4u: goto label_1a72d4;
            case 0x1A72F4u: goto label_1a72f4;
            case 0x1A72F8u: goto label_1a72f8;
            case 0x1A72FCu: goto label_1a72fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7304u;
    // 0x1a7304: 0x0  nop
    ctx->pc = 0x1a7304u;
    // NOP
    // 0x1a7308: 0x0  nop
    ctx->pc = 0x1a7308u;
    // NOP
    // 0x1a730c: 0x0  nop
    ctx->pc = 0x1a730cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
