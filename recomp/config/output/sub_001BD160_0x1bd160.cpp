#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD160
// Address: 0x1bd160 - 0x1bd2e0
void sub_001BD160_0x1bd160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD160_0x1bd160");
#endif

    switch (ctx->pc) {
        case 0x1bd170u: goto label_1bd170;
        case 0x1bd178u: goto label_1bd178;
        case 0x1bd184u: goto label_1bd184;
        case 0x1bd1acu: goto label_1bd1ac;
        case 0x1bd1d0u: goto label_1bd1d0;
        case 0x1bd1f0u: goto label_1bd1f0;
        case 0x1bd21cu: goto label_1bd21c;
        case 0x1bd23cu: goto label_1bd23c;
        case 0x1bd24cu: goto label_1bd24c;
        case 0x1bd26cu: goto label_1bd26c;
        case 0x1bd274u: goto label_1bd274;
        case 0x1bd294u: goto label_1bd294;
        case 0x1bd29cu: goto label_1bd29c;
        case 0x1bd2bcu: goto label_1bd2bc;
        case 0x1bd2c4u: goto label_1bd2c4;
        default: break;
    }

    ctx->pc = 0x1bd160u;

    // 0x1bd160: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bd160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bd164: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bd164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bd168: 0xc045198  jal         func_114660
    ctx->pc = 0x1BD168u;
    SET_GPR_U32(ctx, 31, 0x1BD170u);
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD170u; }
        if (ctx->pc != 0x1BD170u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD170u; }
        if (ctx->pc != 0x1BD170u) { return; }
    }
    ctx->pc = 0x1BD170u;
label_1bd170:
    // 0x1bd170: 0xc0dea90  jal         func_37AA40
    ctx->pc = 0x1BD170u;
    SET_GPR_U32(ctx, 31, 0x1BD178u);
    ctx->pc = 0x37AA40u;
    {
        auto targetFn = runtime->lookupFunction(0x37AA40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD178u; }
        if (ctx->pc != 0x1BD178u) { return; }
    }
    ctx->pc = 0x1BD178u;
label_1bd178:
    // 0x1bd178: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd178u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd17c: 0xc0470f8  jal         func_11C3E0
    ctx->pc = 0x1BD17Cu;
    SET_GPR_U32(ctx, 31, 0x1BD184u);
    ctx->pc = 0x1BD180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD17Cu;
            // 0x1bd180: 0x24840408  addiu       $a0, $a0, 0x408 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1032));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C3E0u;
    if (runtime->hasFunction(0x11C3E0u)) {
        auto targetFn = runtime->lookupFunction(0x11C3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD184u; }
        if (ctx->pc != 0x1BD184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C3E0_0x11c3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD184u; }
        if (ctx->pc != 0x1BD184u) { return; }
    }
    ctx->pc = 0x1BD184u;
label_1bd184:
    // 0x1bd184: 0x4400031  bltz        $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x1BD184u;
    {
        const bool branch_taken_0x1bd184 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd184) {
            ctx->pc = 0x1BD24Cu;
            goto label_1bd24c;
        }
    }
    ctx->pc = 0x1BD18Cu;
    // 0x1bd18c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd18cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd190: 0x24054807  addiu       $a1, $zero, 0x4807
    ctx->pc = 0x1bd190u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18439));
    // 0x1bd194: 0x24840410  addiu       $a0, $a0, 0x410
    ctx->pc = 0x1bd194u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1040));
    // 0x1bd198: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd198u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd19c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd19cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1a0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd1a0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1a4: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD1A4u;
    SET_GPR_U32(ctx, 31, 0x1BD1ACu);
    ctx->pc = 0x1BD1A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD1A4u;
            // 0x1bd1a8: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD1ACu; }
        if (ctx->pc != 0x1BD1ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD1ACu; }
        if (ctx->pc != 0x1BD1ACu) { return; }
    }
    ctx->pc = 0x1BD1ACu;
label_1bd1ac:
    // 0x1bd1ac: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd1acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd1b0: 0xac2244f8  sw          $v0, 0x44F8($at)
    ctx->pc = 0x1bd1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17656), GPR_U32(ctx, 2));
    // 0x1bd1b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd1b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd1b8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1bd1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1bd1bc: 0x8c2344f8  lw          $v1, 0x44F8($at)
    ctx->pc = 0x1bd1bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17656)));
    // 0x1bd1c0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD1C0u;
    {
        const bool branch_taken_0x1bd1c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1bd1c0) {
            ctx->pc = 0x1BD1D0u;
            goto label_1bd1d0;
        }
    }
    ctx->pc = 0x1BD1C8u;
    // 0x1bd1c8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1BD1C8u;
    {
        const bool branch_taken_0x1bd1c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD1CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD1C8u;
            // 0x1bd1cc: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd1c8) {
            ctx->pc = 0x1BD200u;
            goto label_1bd200;
        }
    }
    ctx->pc = 0x1BD1D0u;
label_1bd1d0:
    // 0x1bd1d0: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd1d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd1d4: 0x24054402  addiu       $a1, $zero, 0x4402
    ctx->pc = 0x1bd1d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17410));
    // 0x1bd1d8: 0x24840418  addiu       $a0, $a0, 0x418
    ctx->pc = 0x1bd1d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1048));
    // 0x1bd1dc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd1dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1e0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd1e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1e4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd1e4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1e8: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD1E8u;
    SET_GPR_U32(ctx, 31, 0x1BD1F0u);
    ctx->pc = 0x1BD1ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD1E8u;
            // 0x1bd1ec: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD1F0u; }
        if (ctx->pc != 0x1BD1F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD1F0u; }
        if (ctx->pc != 0x1BD1F0u) { return; }
    }
    ctx->pc = 0x1BD1F0u;
label_1bd1f0:
    // 0x1bd1f0: 0x440fff7  bltz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1BD1F0u;
    {
        const bool branch_taken_0x1bd1f0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd1f0) {
            ctx->pc = 0x1BD1D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd1d0;
        }
    }
    ctx->pc = 0x1BD1F8u;
    // 0x1bd1f8: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1BD1F8u;
    {
        const bool branch_taken_0x1bd1f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd1f8) {
            ctx->pc = 0x1BD274u;
            goto label_1bd274;
        }
    }
    ctx->pc = 0x1BD200u;
label_1bd200:
    // 0x1bd200: 0x24055003  addiu       $a1, $zero, 0x5003
    ctx->pc = 0x1bd200u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20483));
    // 0x1bd204: 0x24840420  addiu       $a0, $a0, 0x420
    ctx->pc = 0x1bd204u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1056));
    // 0x1bd208: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd208u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd20c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd20cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd210: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd210u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd214: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD214u;
    SET_GPR_U32(ctx, 31, 0x1BD21Cu);
    ctx->pc = 0x1BD218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD214u;
            // 0x1bd218: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD21Cu; }
        if (ctx->pc != 0x1BD21Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD21Cu; }
        if (ctx->pc != 0x1BD21Cu) { return; }
    }
    ctx->pc = 0x1BD21Cu;
label_1bd21c:
    // 0x1bd21c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd21cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd220: 0x24054806  addiu       $a1, $zero, 0x4806
    ctx->pc = 0x1bd220u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18438));
    // 0x1bd224: 0x24840410  addiu       $a0, $a0, 0x410
    ctx->pc = 0x1bd224u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1040));
    // 0x1bd228: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd228u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd22c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd22cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd230: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd230u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd234: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD234u;
    SET_GPR_U32(ctx, 31, 0x1BD23Cu);
    ctx->pc = 0x1BD238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD234u;
            // 0x1bd238: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD23Cu; }
        if (ctx->pc != 0x1BD23Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD23Cu; }
        if (ctx->pc != 0x1BD23Cu) { return; }
    }
    ctx->pc = 0x1BD23Cu;
label_1bd23c:
    // 0x1bd23c: 0x440fff7  bltz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1BD23Cu;
    {
        const bool branch_taken_0x1bd23c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd23c) {
            ctx->pc = 0x1BD21Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd21c;
        }
    }
    ctx->pc = 0x1BD244u;
    // 0x1bd244: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1BD244u;
    {
        const bool branch_taken_0x1bd244 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd244) {
            ctx->pc = 0x1BD274u;
            goto label_1bd274;
        }
    }
    ctx->pc = 0x1BD24Cu;
label_1bd24c:
    // 0x1bd24c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd24cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd250: 0x24054402  addiu       $a1, $zero, 0x4402
    ctx->pc = 0x1bd250u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17410));
    // 0x1bd254: 0x24840418  addiu       $a0, $a0, 0x418
    ctx->pc = 0x1bd254u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1048));
    // 0x1bd258: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd258u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd25c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd25cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd260: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd260u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd264: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD264u;
    SET_GPR_U32(ctx, 31, 0x1BD26Cu);
    ctx->pc = 0x1BD268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD264u;
            // 0x1bd268: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD26Cu; }
        if (ctx->pc != 0x1BD26Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD26Cu; }
        if (ctx->pc != 0x1BD26Cu) { return; }
    }
    ctx->pc = 0x1BD26Cu;
label_1bd26c:
    // 0x1bd26c: 0x440fff7  bltz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1BD26Cu;
    {
        const bool branch_taken_0x1bd26c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd26c) {
            ctx->pc = 0x1BD24Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd24c;
        }
    }
    ctx->pc = 0x1BD274u;
label_1bd274:
    // 0x1bd274: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd274u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd278: 0x24054328  addiu       $a1, $zero, 0x4328
    ctx->pc = 0x1bd278u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17192));
    // 0x1bd27c: 0x24840428  addiu       $a0, $a0, 0x428
    ctx->pc = 0x1bd27cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1064));
    // 0x1bd280: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd280u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd284: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd284u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd288: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd288u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd28c: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD28Cu;
    SET_GPR_U32(ctx, 31, 0x1BD294u);
    ctx->pc = 0x1BD290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD28Cu;
            // 0x1bd290: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD294u; }
        if (ctx->pc != 0x1BD294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD294u; }
        if (ctx->pc != 0x1BD294u) { return; }
    }
    ctx->pc = 0x1BD294u;
label_1bd294:
    // 0x1bd294: 0x440fff7  bltz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1BD294u;
    {
        const bool branch_taken_0x1bd294 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd294) {
            ctx->pc = 0x1BD274u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd274;
        }
    }
    ctx->pc = 0x1BD29Cu;
label_1bd29c:
    // 0x1bd29c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd29cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd2a0: 0x24054323  addiu       $a1, $zero, 0x4323
    ctx->pc = 0x1bd2a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17187));
    // 0x1bd2a4: 0x24840428  addiu       $a0, $a0, 0x428
    ctx->pc = 0x1bd2a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1064));
    // 0x1bd2a8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd2a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd2ac: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd2acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd2b0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd2b0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd2b4: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD2B4u;
    SET_GPR_U32(ctx, 31, 0x1BD2BCu);
    ctx->pc = 0x1BD2B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD2B4u;
            // 0x1bd2b8: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD2BCu; }
        if (ctx->pc != 0x1BD2BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD2BCu; }
        if (ctx->pc != 0x1BD2BCu) { return; }
    }
    ctx->pc = 0x1BD2BCu;
label_1bd2bc:
    // 0x1bd2bc: 0x440fff7  bltz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1BD2BCu;
    {
        const bool branch_taken_0x1bd2bc = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd2bc) {
            ctx->pc = 0x1BD29Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd29c;
        }
    }
    ctx->pc = 0x1BD2C4u;
label_1bd2c4:
    // 0x1bd2c4: 0x0  nop
    ctx->pc = 0x1bd2c4u;
    // NOP
    // 0x1bd2c8: 0x0  nop
    ctx->pc = 0x1bd2c8u;
    // NOP
    // 0x1bd2cc: 0x0  nop
    ctx->pc = 0x1bd2ccu;
    // NOP
    // 0x1bd2d0: 0x0  nop
    ctx->pc = 0x1bd2d0u;
    // NOP
    // 0x1bd2d4: 0x0  nop
    ctx->pc = 0x1bd2d4u;
    // NOP
    // 0x1bd2d8: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1BD2D8u;
    {
        const bool branch_taken_0x1bd2d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd2d8) {
            ctx->pc = 0x1BD2C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd2c4;
        }
    }
    ctx->pc = 0x1BD2E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
