#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D1D0
// Address: 0x15d1d0 - 0x15d470
void sub_0015D1D0_0x15d1d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D1D0_0x15d1d0");
#endif

    switch (ctx->pc) {
        case 0x15d1ecu: goto label_15d1ec;
        case 0x15d1f8u: goto label_15d1f8;
        case 0x15d20cu: goto label_15d20c;
        case 0x15d220u: goto label_15d220;
        case 0x15d234u: goto label_15d234;
        case 0x15d250u: goto label_15d250;
        case 0x15d26cu: goto label_15d26c;
        case 0x15d280u: goto label_15d280;
        case 0x15d288u: goto label_15d288;
        case 0x15d290u: goto label_15d290;
        case 0x15d298u: goto label_15d298;
        case 0x15d2a8u: goto label_15d2a8;
        case 0x15d2b8u: goto label_15d2b8;
        case 0x15d314u: goto label_15d314;
        case 0x15d334u: goto label_15d334;
        case 0x15d34cu: goto label_15d34c;
        case 0x15d360u: goto label_15d360;
        case 0x15d3c8u: goto label_15d3c8;
        case 0x15d404u: goto label_15d404;
        case 0x15d40cu: goto label_15d40c;
        default: break;
    }

    ctx->pc = 0x15d1d0u;

    // 0x15d1d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15d1d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15d1d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d1d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d1d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15d1d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d1dc: 0x1200003a  beqz        $s0, . + 4 + (0x3A << 2)
    ctx->pc = 0x15D1DCu;
    {
        const bool branch_taken_0x15d1dc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D1DCu;
            // 0x15d1e0: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d1dc) {
            ctx->pc = 0x15D2C8u;
            goto label_15d2c8;
        }
    }
    ctx->pc = 0x15D1E4u;
    // 0x15d1e4: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15D1E4u;
    SET_GPR_U32(ctx, 31, 0x15D1ECu);
    ctx->pc = 0x15F2F0u;
    if (runtime->hasFunction(0x15F2F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D1ECu; }
        if (ctx->pc != 0x15D1ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F2F0_0x15f2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D1ECu; }
        if (ctx->pc != 0x15D1ECu) { return; }
    }
    ctx->pc = 0x15D1ECu;
label_15d1ec:
    // 0x15d1ec: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x15d1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x15d1f0: 0xc058652  jal         func_161948
    ctx->pc = 0x15D1F0u;
    SET_GPR_U32(ctx, 31, 0x15D1F8u);
    ctx->pc = 0x15D1F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D1F0u;
            // 0x15d1f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161948u;
    if (runtime->hasFunction(0x161948u)) {
        auto targetFn = runtime->lookupFunction(0x161948u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D1F8u; }
        if (ctx->pc != 0x15D1F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161948_0x161948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D1F8u; }
        if (ctx->pc != 0x15D1F8u) { return; }
    }
    ctx->pc = 0x15D1F8u;
label_15d1f8:
    // 0x15d1f8: 0x8e0400a8  lw          $a0, 0xA8($s0)
    ctx->pc = 0x15d1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 168)));
    // 0x15d1fc: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x15D1FCu;
    {
        const bool branch_taken_0x15d1fc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d1fc) {
            ctx->pc = 0x15D200u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D1FCu;
            // 0x15d200: 0x8e04004c  lw          $a0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D210u;
            goto label_15d210;
        }
    }
    ctx->pc = 0x15D204u;
    // 0x15d204: 0xc0582de  jal         func_160B78
    ctx->pc = 0x15D204u;
    SET_GPR_U32(ctx, 31, 0x15D20Cu);
    ctx->pc = 0x160B78u;
    if (runtime->hasFunction(0x160B78u)) {
        auto targetFn = runtime->lookupFunction(0x160B78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D20Cu; }
        if (ctx->pc != 0x15D20Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B78_0x160b78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D20Cu; }
        if (ctx->pc != 0x15D20Cu) { return; }
    }
    ctx->pc = 0x15D20Cu;
label_15d20c:
    // 0x15d20c: 0x8e04004c  lw          $a0, 0x4C($s0)
    ctx->pc = 0x15d20cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
label_15d210:
    // 0x15d210: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x15D210u;
    {
        const bool branch_taken_0x15d210 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d210) {
            ctx->pc = 0x15D214u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D210u;
            // 0x15d214: 0x8e040044  lw          $a0, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D224u;
            goto label_15d224;
        }
    }
    ctx->pc = 0x15D218u;
    // 0x15d218: 0xc04f32e  jal         func_13CCB8
    ctx->pc = 0x15D218u;
    SET_GPR_U32(ctx, 31, 0x15D220u);
    ctx->pc = 0x13CCB8u;
    if (runtime->hasFunction(0x13CCB8u)) {
        auto targetFn = runtime->lookupFunction(0x13CCB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D220u; }
        if (ctx->pc != 0x15D220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CCB8_0x13ccb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D220u; }
        if (ctx->pc != 0x15D220u) { return; }
    }
    ctx->pc = 0x15D220u;
label_15d220:
    // 0x15d220: 0x8e040044  lw          $a0, 0x44($s0)
    ctx->pc = 0x15d220u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
label_15d224:
    // 0x15d224: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x15D224u;
    {
        const bool branch_taken_0x15d224 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d224) {
            ctx->pc = 0x15D228u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D224u;
            // 0x15d228: 0x8e04012c  lw          $a0, 0x12C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D238u;
            goto label_15d238;
        }
    }
    ctx->pc = 0x15D22Cu;
    // 0x15d22c: 0xc059176  jal         func_1645D8
    ctx->pc = 0x15D22Cu;
    SET_GPR_U32(ctx, 31, 0x15D234u);
    ctx->pc = 0x1645D8u;
    if (runtime->hasFunction(0x1645D8u)) {
        auto targetFn = runtime->lookupFunction(0x1645D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D234u; }
        if (ctx->pc != 0x15D234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001645D8_0x1645d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D234u; }
        if (ctx->pc != 0x15D234u) { return; }
    }
    ctx->pc = 0x15D234u;
label_15d234:
    // 0x15d234: 0x8e04012c  lw          $a0, 0x12C($s0)
    ctx->pc = 0x15d234u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
label_15d238:
    // 0x15d238: 0x50800006  beql        $a0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D238u;
    {
        const bool branch_taken_0x15d238 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d238) {
            ctx->pc = 0x15D23Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D238u;
            // 0x15d23c: 0x8e04014c  lw          $a0, 0x14C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 332)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D254u;
            goto label_15d254;
        }
    }
    ctx->pc = 0x15D240u;
    // 0x15d240: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x15d240u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15d244: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x15d244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x15d248: 0x40f809  jalr        $v0
    ctx->pc = 0x15D248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15D250u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15D250u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D1ECu: goto label_15d1ec;
            case 0x15D1F8u: goto label_15d1f8;
            case 0x15D20Cu: goto label_15d20c;
            case 0x15D210u: goto label_15d210;
            case 0x15D220u: goto label_15d220;
            case 0x15D224u: goto label_15d224;
            case 0x15D234u: goto label_15d234;
            case 0x15D238u: goto label_15d238;
            case 0x15D250u: goto label_15d250;
            case 0x15D254u: goto label_15d254;
            case 0x15D26Cu: goto label_15d26c;
            case 0x15D270u: goto label_15d270;
            case 0x15D280u: goto label_15d280;
            case 0x15D288u: goto label_15d288;
            case 0x15D290u: goto label_15d290;
            case 0x15D298u: goto label_15d298;
            case 0x15D2A8u: goto label_15d2a8;
            case 0x15D2B8u: goto label_15d2b8;
            case 0x15D2C8u: goto label_15d2c8;
            case 0x15D308u: goto label_15d308;
            case 0x15D314u: goto label_15d314;
            case 0x15D320u: goto label_15d320;
            case 0x15D334u: goto label_15d334;
            case 0x15D340u: goto label_15d340;
            case 0x15D34Cu: goto label_15d34c;
            case 0x15D360u: goto label_15d360;
            case 0x15D374u: goto label_15d374;
            case 0x15D3C0u: goto label_15d3c0;
            case 0x15D3C8u: goto label_15d3c8;
            case 0x15D404u: goto label_15d404;
            case 0x15D40Cu: goto label_15d40c;
            case 0x15D450u: goto label_15d450;
            case 0x15D454u: goto label_15d454;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15D250u; }
            if (ctx->pc != 0x15D250u) { return; }
        }
        }
    }
    ctx->pc = 0x15D250u;
label_15d250:
    // 0x15d250: 0x8e04014c  lw          $a0, 0x14C($s0)
    ctx->pc = 0x15d250u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 332)));
label_15d254:
    // 0x15d254: 0x50800006  beql        $a0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D254u;
    {
        const bool branch_taken_0x15d254 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d254) {
            ctx->pc = 0x15D258u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D254u;
            // 0x15d258: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D270u;
            goto label_15d270;
        }
    }
    ctx->pc = 0x15D25Cu;
    // 0x15d25c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x15d25cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15d260: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x15d260u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x15d264: 0x40f809  jalr        $v0
    ctx->pc = 0x15D264u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15D26Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15D26Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D1ECu: goto label_15d1ec;
            case 0x15D1F8u: goto label_15d1f8;
            case 0x15D20Cu: goto label_15d20c;
            case 0x15D210u: goto label_15d210;
            case 0x15D220u: goto label_15d220;
            case 0x15D224u: goto label_15d224;
            case 0x15D234u: goto label_15d234;
            case 0x15D238u: goto label_15d238;
            case 0x15D250u: goto label_15d250;
            case 0x15D254u: goto label_15d254;
            case 0x15D26Cu: goto label_15d26c;
            case 0x15D270u: goto label_15d270;
            case 0x15D280u: goto label_15d280;
            case 0x15D288u: goto label_15d288;
            case 0x15D290u: goto label_15d290;
            case 0x15D298u: goto label_15d298;
            case 0x15D2A8u: goto label_15d2a8;
            case 0x15D2B8u: goto label_15d2b8;
            case 0x15D2C8u: goto label_15d2c8;
            case 0x15D308u: goto label_15d308;
            case 0x15D314u: goto label_15d314;
            case 0x15D320u: goto label_15d320;
            case 0x15D334u: goto label_15d334;
            case 0x15D340u: goto label_15d340;
            case 0x15D34Cu: goto label_15d34c;
            case 0x15D360u: goto label_15d360;
            case 0x15D374u: goto label_15d374;
            case 0x15D3C0u: goto label_15d3c0;
            case 0x15D3C8u: goto label_15d3c8;
            case 0x15D404u: goto label_15d404;
            case 0x15D40Cu: goto label_15d40c;
            case 0x15D450u: goto label_15d450;
            case 0x15D454u: goto label_15d454;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15D26Cu; }
            if (ctx->pc != 0x15D26Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15D26Cu;
label_15d26c:
    // 0x15d26c: 0x8e040040  lw          $a0, 0x40($s0)
    ctx->pc = 0x15d26cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
label_15d270:
    // 0x15d270: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15D270u;
    {
        const bool branch_taken_0x15d270 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d270) {
            ctx->pc = 0x15D280u;
            goto label_15d280;
        }
    }
    ctx->pc = 0x15D278u;
    // 0x15d278: 0xc057288  jal         func_15CA20
    ctx->pc = 0x15D278u;
    SET_GPR_U32(ctx, 31, 0x15D280u);
    ctx->pc = 0x15CA20u;
    if (runtime->hasFunction(0x15CA20u)) {
        auto targetFn = runtime->lookupFunction(0x15CA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D280u; }
        if (ctx->pc != 0x15D280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015CA20_0x15ca20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D280u; }
        if (ctx->pc != 0x15D280u) { return; }
    }
    ctx->pc = 0x15D280u;
label_15d280:
    // 0x15d280: 0xc058cdc  jal         func_163370
    ctx->pc = 0x15D280u;
    SET_GPR_U32(ctx, 31, 0x15D288u);
    ctx->pc = 0x15D284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D280u;
            // 0x15d284: 0x260401ec  addiu       $a0, $s0, 0x1EC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 492));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163370u;
    if (runtime->hasFunction(0x163370u)) {
        auto targetFn = runtime->lookupFunction(0x163370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D288u; }
        if (ctx->pc != 0x15D288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163370_0x163370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D288u; }
        if (ctx->pc != 0x15D288u) { return; }
    }
    ctx->pc = 0x15D288u;
label_15d288:
    // 0x15d288: 0xc0575d0  jal         func_15D740
    ctx->pc = 0x15D288u;
    SET_GPR_U32(ctx, 31, 0x15D290u);
    ctx->pc = 0x15D28Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D288u;
            // 0x15d28c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D740u;
    if (runtime->hasFunction(0x15D740u)) {
        auto targetFn = runtime->lookupFunction(0x15D740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D290u; }
        if (ctx->pc != 0x15D290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D740_0x15d740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D290u; }
        if (ctx->pc != 0x15D290u) { return; }
    }
    ctx->pc = 0x15D290u;
label_15d290:
    // 0x15d290: 0xc0575f0  jal         func_15D7C0
    ctx->pc = 0x15D290u;
    SET_GPR_U32(ctx, 31, 0x15D298u);
    ctx->pc = 0x15D294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D290u;
            // 0x15d294: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D7C0u;
    if (runtime->hasFunction(0x15D7C0u)) {
        auto targetFn = runtime->lookupFunction(0x15D7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D298u; }
        if (ctx->pc != 0x15D298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D7C0_0x15d7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D298u; }
        if (ctx->pc != 0x15D298u) { return; }
    }
    ctx->pc = 0x15D298u;
label_15d298:
    // 0x15d298: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15D298u;
    {
        const bool branch_taken_0x15d298 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D29Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D298u;
            // 0x15d29c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d298) {
            ctx->pc = 0x15D2A8u;
            goto label_15d2a8;
        }
    }
    ctx->pc = 0x15D2A0u;
    // 0x15d2a0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D2A0u;
    SET_GPR_U32(ctx, 31, 0x15D2A8u);
    ctx->pc = 0x15D2A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D2A0u;
            // 0x15d2a4: 0x2484eb58  addiu       $a0, $a0, -0x14A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962008));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D2A8u; }
        if (ctx->pc != 0x15D2A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D2A8u; }
        if (ctx->pc != 0x15D2A8u) { return; }
    }
    ctx->pc = 0x15D2A8u;
label_15d2a8:
    // 0x15d2a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d2a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d2ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15d2acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d2b0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x15D2B0u;
    SET_GPR_U32(ctx, 31, 0x15D2B8u);
    ctx->pc = 0x15D2B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D2B0u;
            // 0x15d2b4: 0x24060210  addiu       $a2, $zero, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D2B8u; }
        if (ctx->pc != 0x15D2B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D2B8u; }
        if (ctx->pc != 0x15D2B8u) { return; }
    }
    ctx->pc = 0x15D2B8u;
label_15d2b8:
    // 0x15d2b8: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x15d2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x15d2bc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15d2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15d2c0: 0x2442dce8  addiu       $v0, $v0, -0x2318
    ctx->pc = 0x15d2c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958312));
    // 0x15d2c4: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x15d2c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_15d2c8:
    // 0x15d2c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d2c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d2cc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d2ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d2d0: 0x3e00008  jr          $ra
    ctx->pc = 0x15D2D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D2D0u;
            // 0x15d2d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D1ECu: goto label_15d1ec;
            case 0x15D1F8u: goto label_15d1f8;
            case 0x15D20Cu: goto label_15d20c;
            case 0x15D210u: goto label_15d210;
            case 0x15D220u: goto label_15d220;
            case 0x15D224u: goto label_15d224;
            case 0x15D234u: goto label_15d234;
            case 0x15D238u: goto label_15d238;
            case 0x15D250u: goto label_15d250;
            case 0x15D254u: goto label_15d254;
            case 0x15D26Cu: goto label_15d26c;
            case 0x15D270u: goto label_15d270;
            case 0x15D280u: goto label_15d280;
            case 0x15D288u: goto label_15d288;
            case 0x15D290u: goto label_15d290;
            case 0x15D298u: goto label_15d298;
            case 0x15D2A8u: goto label_15d2a8;
            case 0x15D2B8u: goto label_15d2b8;
            case 0x15D2C8u: goto label_15d2c8;
            case 0x15D308u: goto label_15d308;
            case 0x15D314u: goto label_15d314;
            case 0x15D320u: goto label_15d320;
            case 0x15D334u: goto label_15d334;
            case 0x15D340u: goto label_15d340;
            case 0x15D34Cu: goto label_15d34c;
            case 0x15D360u: goto label_15d360;
            case 0x15D374u: goto label_15d374;
            case 0x15D3C0u: goto label_15d3c0;
            case 0x15D3C8u: goto label_15d3c8;
            case 0x15D404u: goto label_15d404;
            case 0x15D40Cu: goto label_15d40c;
            case 0x15D450u: goto label_15d450;
            case 0x15D454u: goto label_15d454;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D2D8u;
    // 0x15d2d8: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x15d2d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x15d2dc: 0xffb10068  sd          $s1, 0x68($sp)
    ctx->pc = 0x15d2dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 17));
    // 0x15d2e0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15d2e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d2e4: 0xffb00060  sd          $s0, 0x60($sp)
    ctx->pc = 0x15d2e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 16));
    // 0x15d2e8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15d2e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d2ec: 0xffb20070  sd          $s2, 0x70($sp)
    ctx->pc = 0x15d2ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 18));
    // 0x15d2f0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x15d2f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d2f4: 0xffb30078  sd          $s3, 0x78($sp)
    ctx->pc = 0x15d2f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 19));
    // 0x15d2f8: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x15D2F8u;
    {
        const bool branch_taken_0x15d2f8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D2FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D2F8u;
            // 0x15d2fc: 0xffbf0080  sd          $ra, 0x80($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d2f8) {
            ctx->pc = 0x15D308u;
            goto label_15d308;
        }
    }
    ctx->pc = 0x15D300u;
    // 0x15d300: 0x16400007  bnez        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x15D300u;
    {
        const bool branch_taken_0x15d300 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x15d300) {
            ctx->pc = 0x15D320u;
            goto label_15d320;
        }
    }
    ctx->pc = 0x15D308u;
label_15d308:
    // 0x15d308: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d308u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d30c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D30Cu;
    SET_GPR_U32(ctx, 31, 0x15D314u);
    ctx->pc = 0x15D310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D30Cu;
            // 0x15d310: 0x2484eb70  addiu       $a0, $a0, -0x1490 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962032));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D314u; }
        if (ctx->pc != 0x15D314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D314u; }
        if (ctx->pc != 0x15D314u) { return; }
    }
    ctx->pc = 0x15D314u;
label_15d314:
    // 0x15d314: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x15D314u;
    {
        const bool branch_taken_0x15d314 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D314u;
            // 0x15d318: 0xdfb00060  ld          $s0, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d314) {
            ctx->pc = 0x15D454u;
            goto label_15d454;
        }
    }
    ctx->pc = 0x15D31Cu;
    // 0x15d31c: 0x0  nop
    ctx->pc = 0x15d31cu;
    // NOP
label_15d320:
    // 0x15d320: 0x5e000007  bgtzl       $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15D320u;
    {
        const bool branch_taken_0x15d320 = (GPR_S64(ctx, 16) > 0);
        if (branch_taken_0x15d320) {
            ctx->pc = 0x15D324u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D320u;
            // 0x15d324: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D340u;
            goto label_15d340;
        }
    }
    ctx->pc = 0x15D328u;
    // 0x15d328: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d328u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d32c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D32Cu;
    SET_GPR_U32(ctx, 31, 0x15D334u);
    ctx->pc = 0x15D330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D32Cu;
            // 0x15d330: 0x2484eb98  addiu       $a0, $a0, -0x1468 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D334u; }
        if (ctx->pc != 0x15D334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D334u; }
        if (ctx->pc != 0x15D334u) { return; }
    }
    ctx->pc = 0x15D334u;
label_15d334:
    // 0x15d334: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x15D334u;
    {
        const bool branch_taken_0x15d334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D334u;
            // 0x15d338: 0xdfb00060  ld          $s0, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d334) {
            ctx->pc = 0x15D454u;
            goto label_15d454;
        }
    }
    ctx->pc = 0x15D33Cu;
    // 0x15d33c: 0x0  nop
    ctx->pc = 0x15d33cu;
    // NOP
label_15d340:
    // 0x15d340: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15d340u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d344: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x15D344u;
    SET_GPR_U32(ctx, 31, 0x15D34Cu);
    ctx->pc = 0x15D348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D344u;
            // 0x15d348: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D34Cu; }
        if (ctx->pc != 0x15D34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D34Cu; }
        if (ctx->pc != 0x15D34Cu) { return; }
    }
    ctx->pc = 0x15D34Cu;
label_15d34c:
    // 0x15d34c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15d34cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d350: 0x27b30020  addiu       $s3, $sp, 0x20
    ctx->pc = 0x15d350u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x15d354: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15d354u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d358: 0xc05a07a  jal         func_1681E8
    ctx->pc = 0x15D358u;
    SET_GPR_U32(ctx, 31, 0x15D360u);
    ctx->pc = 0x15D35Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D358u;
            // 0x15d35c: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1681E8u;
    if (runtime->hasFunction(0x1681E8u)) {
        auto targetFn = runtime->lookupFunction(0x1681E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D360u; }
        if (ctx->pc != 0x15D360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001681E8_0x1681e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D360u; }
        if (ctx->pc != 0x15D360u) { return; }
    }
    ctx->pc = 0x15D360u;
label_15d360:
    // 0x15d360: 0x83a20020  lb          $v0, 0x20($sp)
    ctx->pc = 0x15d360u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15d364: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15D364u;
    {
        const bool branch_taken_0x15d364 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D364u;
            // 0x15d368: 0x83a20021  lb          $v0, 0x21($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 33)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d364) {
            ctx->pc = 0x15D374u;
            goto label_15d374;
        }
    }
    ctx->pc = 0x15D36Cu;
    // 0x15d36c: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x15D36Cu;
    {
        const bool branch_taken_0x15d36c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15d36c) {
            ctx->pc = 0x15D3C0u;
            goto label_15d3c0;
        }
    }
    ctx->pc = 0x15D374u;
label_15d374:
    // 0x15d374: 0x6ba20007  ldl         $v0, 0x7($sp)
    ctx->pc = 0x15d374u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x15d378: 0x6fa20000  ldr         $v0, 0x0($sp)
    ctx->pc = 0x15d378u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x15d37c: 0x6ba3000f  ldl         $v1, 0xF($sp)
    ctx->pc = 0x15d37cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x15d380: 0x6fa30008  ldr         $v1, 0x8($sp)
    ctx->pc = 0x15d380u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x15d384: 0x6ba40017  ldl         $a0, 0x17($sp)
    ctx->pc = 0x15d384u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x15d388: 0x6fa40010  ldr         $a0, 0x10($sp)
    ctx->pc = 0x15d388u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x15d38c: 0x6ba5001f  ldl         $a1, 0x1F($sp)
    ctx->pc = 0x15d38cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x15d390: 0x6fa50018  ldr         $a1, 0x18($sp)
    ctx->pc = 0x15d390u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x15d394: 0xb2420007  sdl         $v0, 0x7($s2)
    ctx->pc = 0x15d394u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d398: 0xb6420000  sdr         $v0, 0x0($s2)
    ctx->pc = 0x15d398u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d39c: 0xb243000f  sdl         $v1, 0xF($s2)
    ctx->pc = 0x15d39cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d3a0: 0xb6430008  sdr         $v1, 0x8($s2)
    ctx->pc = 0x15d3a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d3a4: 0xb2440017  sdl         $a0, 0x17($s2)
    ctx->pc = 0x15d3a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d3a8: 0xb6440010  sdr         $a0, 0x10($s2)
    ctx->pc = 0x15d3a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d3ac: 0xb245001f  sdl         $a1, 0x1F($s2)
    ctx->pc = 0x15d3acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d3b0: 0xb6450018  sdr         $a1, 0x18($s2)
    ctx->pc = 0x15d3b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d3b4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x15D3B4u;
    {
        const bool branch_taken_0x15d3b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D3B4u;
            // 0x15d3b8: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d3b4) {
            ctx->pc = 0x15D450u;
            goto label_15d450;
        }
    }
    ctx->pc = 0x15D3BCu;
    // 0x15d3bc: 0x0  nop
    ctx->pc = 0x15d3bcu;
    // NOP
label_15d3c0:
    // 0x15d3c0: 0xc05751c  jal         func_15D470
    ctx->pc = 0x15D3C0u;
    SET_GPR_U32(ctx, 31, 0x15D3C8u);
    ctx->pc = 0x15D3C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D3C0u;
            // 0x15d3c4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D470u;
    if (runtime->hasFunction(0x15D470u)) {
        auto targetFn = runtime->lookupFunction(0x15D470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D3C8u; }
        if (ctx->pc != 0x15D3C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D470_0x15d470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D3C8u; }
        if (ctx->pc != 0x15D3C8u) { return; }
    }
    ctx->pc = 0x15D3C8u;
label_15d3c8:
    // 0x15d3c8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15d3c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d3cc: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x15d3ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15d3d0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15d3d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d3d4: 0x8faa0034  lw          $t2, 0x34($sp)
    ctx->pc = 0x15d3d4u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x15d3d8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x15d3d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d3dc: 0x8fa70040  lw          $a3, 0x40($sp)
    ctx->pc = 0x15d3dcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15d3e0: 0x8fa8004c  lw          $t0, 0x4C($sp)
    ctx->pc = 0x15d3e0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x15d3e4: 0x83a90048  lb          $t1, 0x48($sp)
    ctx->pc = 0x15d3e4u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15d3e8: 0xafa3000c  sw          $v1, 0xC($sp)
    ctx->pc = 0x15d3e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
    // 0x15d3ec: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x15d3ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x15d3f0: 0xafaa0008  sw          $t2, 0x8($sp)
    ctx->pc = 0x15d3f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 10));
    // 0x15d3f4: 0xafa70010  sw          $a3, 0x10($sp)
    ctx->pc = 0x15d3f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 7));
    // 0x15d3f8: 0xafa80014  sw          $t0, 0x14($sp)
    ctx->pc = 0x15d3f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 8));
    // 0x15d3fc: 0xc057968  jal         func_15E5A0
    ctx->pc = 0x15D3FCu;
    SET_GPR_U32(ctx, 31, 0x15D404u);
    ctx->pc = 0x15D400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D3FCu;
            // 0x15d400: 0xafa90018  sw          $t1, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E5A0u;
    if (runtime->hasFunction(0x15E5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15E5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D404u; }
        if (ctx->pc != 0x15D404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E5A0_0x15e5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D404u; }
        if (ctx->pc != 0x15D404u) { return; }
    }
    ctx->pc = 0x15D404u;
label_15d404:
    // 0x15d404: 0xc057530  jal         func_15D4C0
    ctx->pc = 0x15D404u;
    SET_GPR_U32(ctx, 31, 0x15D40Cu);
    ctx->pc = 0x15D408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D404u;
            // 0x15d408: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D4C0u;
    if (runtime->hasFunction(0x15D4C0u)) {
        auto targetFn = runtime->lookupFunction(0x15D4C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D40Cu; }
        if (ctx->pc != 0x15D40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D4C0_0x15d4c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D40Cu; }
        if (ctx->pc != 0x15D40Cu) { return; }
    }
    ctx->pc = 0x15D40Cu;
label_15d40c:
    // 0x15d40c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x15d40cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x15d410: 0x6ba20007  ldl         $v0, 0x7($sp)
    ctx->pc = 0x15d410u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x15d414: 0x6fa20000  ldr         $v0, 0x0($sp)
    ctx->pc = 0x15d414u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x15d418: 0x6ba3000f  ldl         $v1, 0xF($sp)
    ctx->pc = 0x15d418u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x15d41c: 0x6fa30008  ldr         $v1, 0x8($sp)
    ctx->pc = 0x15d41cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x15d420: 0x6ba40017  ldl         $a0, 0x17($sp)
    ctx->pc = 0x15d420u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x15d424: 0x6fa40010  ldr         $a0, 0x10($sp)
    ctx->pc = 0x15d424u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x15d428: 0x6ba5001f  ldl         $a1, 0x1F($sp)
    ctx->pc = 0x15d428u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x15d42c: 0x6fa50018  ldr         $a1, 0x18($sp)
    ctx->pc = 0x15d42cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x15d430: 0xb2420007  sdl         $v0, 0x7($s2)
    ctx->pc = 0x15d430u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d434: 0xb6420000  sdr         $v0, 0x0($s2)
    ctx->pc = 0x15d434u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d438: 0xb243000f  sdl         $v1, 0xF($s2)
    ctx->pc = 0x15d438u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d43c: 0xb6430008  sdr         $v1, 0x8($s2)
    ctx->pc = 0x15d43cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d440: 0xb2440017  sdl         $a0, 0x17($s2)
    ctx->pc = 0x15d440u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d444: 0xb6440010  sdr         $a0, 0x10($s2)
    ctx->pc = 0x15d444u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d448: 0xb245001f  sdl         $a1, 0x1F($s2)
    ctx->pc = 0x15d448u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15d44c: 0xb6450018  sdr         $a1, 0x18($s2)
    ctx->pc = 0x15d44cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_15d450:
    // 0x15d450: 0xdfb00060  ld          $s0, 0x60($sp)
    ctx->pc = 0x15d450u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_15d454:
    // 0x15d454: 0xdfb10068  ld          $s1, 0x68($sp)
    ctx->pc = 0x15d454u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x15d458: 0xdfb20070  ld          $s2, 0x70($sp)
    ctx->pc = 0x15d458u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x15d45c: 0xdfb30078  ld          $s3, 0x78($sp)
    ctx->pc = 0x15d45cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x15d460: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x15d460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x15d464: 0x3e00008  jr          $ra
    ctx->pc = 0x15D464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D464u;
            // 0x15d468: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D1ECu: goto label_15d1ec;
            case 0x15D1F8u: goto label_15d1f8;
            case 0x15D20Cu: goto label_15d20c;
            case 0x15D210u: goto label_15d210;
            case 0x15D220u: goto label_15d220;
            case 0x15D224u: goto label_15d224;
            case 0x15D234u: goto label_15d234;
            case 0x15D238u: goto label_15d238;
            case 0x15D250u: goto label_15d250;
            case 0x15D254u: goto label_15d254;
            case 0x15D26Cu: goto label_15d26c;
            case 0x15D270u: goto label_15d270;
            case 0x15D280u: goto label_15d280;
            case 0x15D288u: goto label_15d288;
            case 0x15D290u: goto label_15d290;
            case 0x15D298u: goto label_15d298;
            case 0x15D2A8u: goto label_15d2a8;
            case 0x15D2B8u: goto label_15d2b8;
            case 0x15D2C8u: goto label_15d2c8;
            case 0x15D308u: goto label_15d308;
            case 0x15D314u: goto label_15d314;
            case 0x15D320u: goto label_15d320;
            case 0x15D334u: goto label_15d334;
            case 0x15D340u: goto label_15d340;
            case 0x15D34Cu: goto label_15d34c;
            case 0x15D360u: goto label_15d360;
            case 0x15D374u: goto label_15d374;
            case 0x15D3C0u: goto label_15d3c0;
            case 0x15D3C8u: goto label_15d3c8;
            case 0x15D404u: goto label_15d404;
            case 0x15D40Cu: goto label_15d40c;
            case 0x15D450u: goto label_15d450;
            case 0x15D454u: goto label_15d454;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D46Cu;
    // 0x15d46c: 0x0  nop
    ctx->pc = 0x15d46cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
