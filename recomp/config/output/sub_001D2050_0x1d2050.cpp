#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2050
// Address: 0x1d2050 - 0x1d2168
void sub_001D2050_0x1d2050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2050_0x1d2050");
#endif

    switch (ctx->pc) {
        case 0x1d2088u: goto label_1d2088;
        case 0x1d209cu: goto label_1d209c;
        case 0x1d20acu: goto label_1d20ac;
        case 0x1d20b0u: goto label_1d20b0;
        case 0x1d20d0u: goto label_1d20d0;
        case 0x1d2110u: goto label_1d2110;
        case 0x1d2120u: goto label_1d2120;
        case 0x1d213cu: goto label_1d213c;
        case 0x1d2150u: goto label_1d2150;
        default: break;
    }

    ctx->pc = 0x1d2050u;

    // 0x1d2050: 0x27bdfec0  addiu       $sp, $sp, -0x140
    ctx->pc = 0x1d2050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x1d2054: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d2054u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d2058: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d2058u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d205c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d205cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2060: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d2060u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d2064: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1d2064u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1d2068: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d2068u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d206c: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d206cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2070: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d2070u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d2074: 0x24a56520  addiu       $a1, $a1, 0x6520
    ctx->pc = 0x1d2074u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25888));
    // 0x1d2078: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d2078u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d207c: 0x24122600  addiu       $s2, $zero, 0x2600
    ctx->pc = 0x1d207cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 9728));
    // 0x1d2080: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D2080u;
    SET_GPR_U32(ctx, 31, 0x1D2088u);
    ctx->pc = 0x1D2084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2080u;
            // 0x1d2084: 0x2028821  addu        $s1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2088u; }
        if (ctx->pc != 0x1D2088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2088u; }
        if (ctx->pc != 0x1D2088u) { return; }
    }
    ctx->pc = 0x1D2088u;
label_1d2088:
    // 0x1d2088: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d2088u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d208c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d208cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2090: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d2090u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2094: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D2094u;
    SET_GPR_U32(ctx, 31, 0x1D209Cu);
    ctx->pc = 0x1D2098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2094u;
            // 0x1d2098: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D209Cu; }
        if (ctx->pc != 0x1D209Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D209Cu; }
        if (ctx->pc != 0x1D209Cu) { return; }
    }
    ctx->pc = 0x1D209Cu;
label_1d209c:
    // 0x1d209c: 0x1040002c  beqz        $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1D209Cu;
    {
        const bool branch_taken_0x1d209c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D20A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D209Cu;
            // 0x1d20a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d209c) {
            ctx->pc = 0x1D2150u;
            goto label_1d2150;
        }
    }
    ctx->pc = 0x1D20A4u;
    // 0x1d20a4: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1D20A4u;
    SET_GPR_U32(ctx, 31, 0x1D20ACu);
    ctx->pc = 0x1D20A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D20A4u;
            // 0x1d20a8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D20ACu; }
        if (ctx->pc != 0x1D20ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D20ACu; }
        if (ctx->pc != 0x1D20ACu) { return; }
    }
    ctx->pc = 0x1D20ACu;
label_1d20ac:
    // 0x1d20ac: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d20acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d20b0:
    // 0x1d20b0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d20b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d20b4: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1d20b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d20b8: 0x24426700  addiu       $v0, $v0, 0x6700
    ctx->pc = 0x1d20b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26368));
    // 0x1d20bc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1d20bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d20c0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d20c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d20c4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1d20c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d20c8: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D20C8u;
    SET_GPR_U32(ctx, 31, 0x1D20D0u);
    ctx->pc = 0x1D20CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D20C8u;
            // 0x1d20cc: 0x2222821  addu        $a1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D20D0u; }
        if (ctx->pc != 0x1D20D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D20D0u; }
        if (ctx->pc != 0x1D20D0u) { return; }
    }
    ctx->pc = 0x1D20D0u;
label_1d20d0:
    // 0x1d20d0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d20d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d20d4: 0x2a020004  slti        $v0, $s0, 0x4
    ctx->pc = 0x1d20d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d20d8: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1D20D8u;
    {
        const bool branch_taken_0x1d20d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D20DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D20D8u;
            // 0x1d20dc: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d20d8) {
            ctx->pc = 0x1D20B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d20b0;
        }
    }
    ctx->pc = 0x1D20E0u;
    // 0x1d20e0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d20e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d20e4: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d20e4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d20e8: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D20E8u;
    {
        const bool branch_taken_0x1d20e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D20ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D20E8u;
            // 0x1d20ec: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d20e8) {
            ctx->pc = 0x1D2128u;
            goto label_1d2128;
        }
    }
    ctx->pc = 0x1D20F0u;
    // 0x1d20f0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d20f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d20f4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d20f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d20f8: 0x942743da  lhu         $a3, 0x43DA($at)
    ctx->pc = 0x1d20f8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d20fc: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d20fcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d2100: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d2100u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2104: 0x24a56548  addiu       $a1, $a1, 0x6548
    ctx->pc = 0x1d2104u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25928));
    // 0x1d2108: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D2108u;
    SET_GPR_U32(ctx, 31, 0x1D2110u);
    ctx->pc = 0x1D210Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2108u;
            // 0x1d210c: 0x24c66560  addiu       $a2, $a2, 0x6560 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 25952));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2110u; }
        if (ctx->pc != 0x1D2110u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2110u; }
        if (ctx->pc != 0x1D2110u) { return; }
    }
    ctx->pc = 0x1D2110u;
label_1d2110:
    // 0x1d2110: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d2110u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2114: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d2114u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2118: 0xc073364  jal         func_1CCD90
    ctx->pc = 0x1D2118u;
    SET_GPR_U32(ctx, 31, 0x1D2120u);
    ctx->pc = 0x1D211Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2118u;
            // 0x1d211c: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCD90u;
    if (runtime->hasFunction(0x1CCD90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2120u; }
        if (ctx->pc != 0x1D2120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCD90_0x1ccd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2120u; }
        if (ctx->pc != 0x1D2120u) { return; }
    }
    ctx->pc = 0x1D2120u;
label_1d2120:
    // 0x1d2120: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D2120u;
    {
        const bool branch_taken_0x1d2120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2120u;
            // 0x1d2124: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2120) {
            ctx->pc = 0x1D2154u;
            goto label_1d2154;
        }
    }
    ctx->pc = 0x1D2128u;
label_1d2128:
    // 0x1d2128: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d2128u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d212c: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d212cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d2130: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d2130u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2134: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D2134u;
    SET_GPR_U32(ctx, 31, 0x1D213Cu);
    ctx->pc = 0x1D2138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2134u;
            // 0x1d2138: 0x24a56580  addiu       $a1, $a1, 0x6580 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25984));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D213Cu; }
        if (ctx->pc != 0x1D213Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D213Cu; }
        if (ctx->pc != 0x1D213Cu) { return; }
    }
    ctx->pc = 0x1D213Cu;
label_1d213c:
    // 0x1d213c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d213cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d2140: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d2140u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2144: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d2144u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2148: 0xc073364  jal         func_1CCD90
    ctx->pc = 0x1D2148u;
    SET_GPR_U32(ctx, 31, 0x1D2150u);
    ctx->pc = 0x1D214Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2148u;
            // 0x1d214c: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCD90u;
    if (runtime->hasFunction(0x1CCD90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2150u; }
        if (ctx->pc != 0x1D2150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCD90_0x1ccd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2150u; }
        if (ctx->pc != 0x1D2150u) { return; }
    }
    ctx->pc = 0x1D2150u;
label_1d2150:
    // 0x1d2150: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d2150u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1d2154:
    // 0x1d2154: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d2154u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2158: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d2158u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d215c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d215cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2160: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2160u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2160u;
            // 0x1d2164: 0x27bd0140  addiu       $sp, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2088u: goto label_1d2088;
            case 0x1D209Cu: goto label_1d209c;
            case 0x1D20ACu: goto label_1d20ac;
            case 0x1D20B0u: goto label_1d20b0;
            case 0x1D20D0u: goto label_1d20d0;
            case 0x1D2110u: goto label_1d2110;
            case 0x1D2120u: goto label_1d2120;
            case 0x1D2128u: goto label_1d2128;
            case 0x1D213Cu: goto label_1d213c;
            case 0x1D2150u: goto label_1d2150;
            case 0x1D2154u: goto label_1d2154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2168u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
