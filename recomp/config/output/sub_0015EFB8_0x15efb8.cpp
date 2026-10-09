#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EFB8
// Address: 0x15efb8 - 0x15f0a8
void sub_0015EFB8_0x15efb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EFB8_0x15efb8");
#endif

    switch (ctx->pc) {
        case 0x15efd4u: goto label_15efd4;
        case 0x15efe8u: goto label_15efe8;
        case 0x15f010u: goto label_15f010;
        case 0x15f018u: goto label_15f018;
        case 0x15f020u: goto label_15f020;
        case 0x15f028u: goto label_15f028;
        case 0x15f050u: goto label_15f050;
        case 0x15f058u: goto label_15f058;
        case 0x15f060u: goto label_15f060;
        case 0x15f06cu: goto label_15f06c;
        case 0x15f078u: goto label_15f078;
        case 0x15f080u: goto label_15f080;
        default: break;
    }

    ctx->pc = 0x15efb8u;

    // 0x15efb8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15efb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15efbc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15efbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15efc0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15efc0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15efc4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15efc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15efc8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15efc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15efcc: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15EFCCu;
    SET_GPR_U32(ctx, 31, 0x15EFD4u);
    ctx->pc = 0x15EFD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EFCCu;
            // 0x15efd0: 0x261101ec  addiu       $s1, $s0, 0x1EC (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 492));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EFD4u; }
        if (ctx->pc != 0x15EFD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EFD4u; }
        if (ctx->pc != 0x15EFD4u) { return; }
    }
    ctx->pc = 0x15EFD4u;
label_15efd4:
    // 0x15efd4: 0x8e020040  lw          $v0, 0x40($s0)
    ctx->pc = 0x15efd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x15efd8: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x15EFD8u;
    {
        const bool branch_taken_0x15efd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EFD8u;
            // 0x15efdc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15efd8) {
            ctx->pc = 0x15F050u;
            goto label_15f050;
        }
    }
    ctx->pc = 0x15EFE0u;
    // 0x15efe0: 0xc0572f2  jal         func_15CBC8
    ctx->pc = 0x15EFE0u;
    SET_GPR_U32(ctx, 31, 0x15EFE8u);
    ctx->pc = 0x15CBC8u;
    if (runtime->hasFunction(0x15CBC8u)) {
        auto targetFn = runtime->lookupFunction(0x15CBC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EFE8u; }
        if (ctx->pc != 0x15EFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015CBC8_0x15cbc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EFE8u; }
        if (ctx->pc != 0x15EFE8u) { return; }
    }
    ctx->pc = 0x15EFE8u;
label_15efe8:
    // 0x15efe8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15EFE8u;
    {
        const bool branch_taken_0x15efe8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EFECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EFE8u;
            // 0x15efec: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15efe8) {
            ctx->pc = 0x15F008u;
            goto label_15f008;
        }
    }
    ctx->pc = 0x15EFF0u;
    // 0x15eff0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15eff0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15eff4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15eff4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15eff8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15eff8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15effc: 0x2484f060  addiu       $a0, $a0, -0xFA0
    ctx->pc = 0x15effcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963296));
    // 0x15f000: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F000u;
    ctx->pc = 0x15F004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F000u;
            // 0x15f004: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F008u;
label_15f008:
    // 0x15f008: 0xc058cb0  jal         func_1632C0
    ctx->pc = 0x15F008u;
    SET_GPR_U32(ctx, 31, 0x15F010u);
    ctx->pc = 0x15F00Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F008u;
            // 0x15f00c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1632C0u;
    if (runtime->hasFunction(0x1632C0u)) {
        auto targetFn = runtime->lookupFunction(0x1632C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F010u; }
        if (ctx->pc != 0x15F010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001632C0_0x1632c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F010u; }
        if (ctx->pc != 0x15F010u) { return; }
    }
    ctx->pc = 0x15F010u;
label_15f010:
    // 0x15f010: 0xc057808  jal         func_15E020
    ctx->pc = 0x15F010u;
    SET_GPR_U32(ctx, 31, 0x15F018u);
    ctx->pc = 0x15F014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F010u;
            // 0x15f014: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E020u;
    if (runtime->hasFunction(0x15E020u)) {
        auto targetFn = runtime->lookupFunction(0x15E020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F018u; }
        if (ctx->pc != 0x15F018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E020_0x15e020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F018u; }
        if (ctx->pc != 0x15F018u) { return; }
    }
    ctx->pc = 0x15F018u;
label_15f018:
    // 0x15f018: 0xc05867e  jal         func_1619F8
    ctx->pc = 0x15F018u;
    SET_GPR_U32(ctx, 31, 0x15F020u);
    ctx->pc = 0x15F01Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F018u;
            // 0x15f01c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1619F8u;
    if (runtime->hasFunction(0x1619F8u)) {
        auto targetFn = runtime->lookupFunction(0x1619F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F020u; }
        if (ctx->pc != 0x15F020u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001619F8_0x1619f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F020u; }
        if (ctx->pc != 0x15F020u) { return; }
    }
    ctx->pc = 0x15F020u;
label_15f020:
    // 0x15f020: 0xc05865e  jal         func_161978
    ctx->pc = 0x15F020u;
    SET_GPR_U32(ctx, 31, 0x15F028u);
    ctx->pc = 0x15F024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F020u;
            // 0x15f024: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161978u;
    if (runtime->hasFunction(0x161978u)) {
        auto targetFn = runtime->lookupFunction(0x161978u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F028u; }
        if (ctx->pc != 0x15F028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161978_0x161978(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F028u; }
        if (ctx->pc != 0x15F028u) { return; }
    }
    ctx->pc = 0x15F028u;
label_15f028:
    // 0x15f028: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f028u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f02c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15F02Cu;
    {
        const bool branch_taken_0x15f02c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F02Cu;
            // 0x15f030: 0x2484f090  addiu       $a0, $a0, -0xF70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f02c) {
            ctx->pc = 0x15F048u;
            goto label_15f048;
        }
    }
    ctx->pc = 0x15F034u;
    // 0x15f034: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f034u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f038: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f038u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f03c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f03cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f040: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F040u;
    ctx->pc = 0x15F044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F040u;
            // 0x15f044: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F048u;
label_15f048:
    // 0x15f048: 0xc058676  jal         func_1619D8
    ctx->pc = 0x15F048u;
    SET_GPR_U32(ctx, 31, 0x15F050u);
    ctx->pc = 0x15F04Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F048u;
            // 0x15f04c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1619D8u;
    if (runtime->hasFunction(0x1619D8u)) {
        auto targetFn = runtime->lookupFunction(0x1619D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F050u; }
        if (ctx->pc != 0x15F050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001619D8_0x1619d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F050u; }
        if (ctx->pc != 0x15F050u) { return; }
    }
    ctx->pc = 0x15F050u;
label_15f050:
    // 0x15f050: 0xc057c2a  jal         func_15F0A8
    ctx->pc = 0x15F050u;
    SET_GPR_U32(ctx, 31, 0x15F058u);
    ctx->pc = 0x15F054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F050u;
            // 0x15f054: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F0A8u;
    if (runtime->hasFunction(0x15F0A8u)) {
        auto targetFn = runtime->lookupFunction(0x15F0A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F058u; }
        if (ctx->pc != 0x15F058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F0A8_0x15f0a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F058u; }
        if (ctx->pc != 0x15F058u) { return; }
    }
    ctx->pc = 0x15F058u;
label_15f058:
    // 0x15f058: 0xc057b92  jal         func_15EE48
    ctx->pc = 0x15F058u;
    SET_GPR_U32(ctx, 31, 0x15F060u);
    ctx->pc = 0x15F05Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F058u;
            // 0x15f05c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EE48u;
    if (runtime->hasFunction(0x15EE48u)) {
        auto targetFn = runtime->lookupFunction(0x15EE48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F060u; }
        if (ctx->pc != 0x15F060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EE48_0x15ee48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F060u; }
        if (ctx->pc != 0x15F060u) { return; }
    }
    ctx->pc = 0x15F060u;
label_15f060:
    // 0x15f060: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f060u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f064: 0xc057cfc  jal         func_15F3F0
    ctx->pc = 0x15F064u;
    SET_GPR_U32(ctx, 31, 0x15F06Cu);
    ctx->pc = 0x15F068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F064u;
            // 0x15f068: 0x82050072  lb          $a1, 0x72($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 114)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F3F0u;
    if (runtime->hasFunction(0x15F3F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F3F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F06Cu; }
        if (ctx->pc != 0x15F06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F3F0_0x15f3f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F06Cu; }
        if (ctx->pc != 0x15F06Cu) { return; }
    }
    ctx->pc = 0x15F06Cu;
label_15f06c:
    // 0x15f06c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15f06cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f070: 0xc058c1e  jal         func_163078
    ctx->pc = 0x15F070u;
    SET_GPR_U32(ctx, 31, 0x15F078u);
    ctx->pc = 0x15F074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F070u;
            // 0x15f074: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163078u;
    if (runtime->hasFunction(0x163078u)) {
        auto targetFn = runtime->lookupFunction(0x163078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F078u; }
        if (ctx->pc != 0x15F078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163078_0x163078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F078u; }
        if (ctx->pc != 0x15F078u) { return; }
    }
    ctx->pc = 0x15F078u;
label_15f078:
    // 0x15f078: 0xc058bbc  jal         func_162EF0
    ctx->pc = 0x15F078u;
    SET_GPR_U32(ctx, 31, 0x15F080u);
    ctx->pc = 0x15F07Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F078u;
            // 0x15f07c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162EF0u;
    if (runtime->hasFunction(0x162EF0u)) {
        auto targetFn = runtime->lookupFunction(0x162EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F080u; }
        if (ctx->pc != 0x15F080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162EF0_0x162ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F080u; }
        if (ctx->pc != 0x15F080u) { return; }
    }
    ctx->pc = 0x15F080u;
label_15f080:
    // 0x15f080: 0xae000084  sw          $zero, 0x84($s0)
    ctx->pc = 0x15f080u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 0));
    // 0x15f084: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15f084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f088: 0xa2000071  sb          $zero, 0x71($s0)
    ctx->pc = 0x15f088u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 113), (uint8_t)GPR_U32(ctx, 0));
    // 0x15f08c: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x15f08cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x15f090: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f090u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f094: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f094u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f098: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f098u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f09c: 0x3e00008  jr          $ra
    ctx->pc = 0x15F09Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F0A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F09Cu;
            // 0x15f0a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EFD4u: goto label_15efd4;
            case 0x15EFE8u: goto label_15efe8;
            case 0x15F008u: goto label_15f008;
            case 0x15F010u: goto label_15f010;
            case 0x15F018u: goto label_15f018;
            case 0x15F020u: goto label_15f020;
            case 0x15F028u: goto label_15f028;
            case 0x15F048u: goto label_15f048;
            case 0x15F050u: goto label_15f050;
            case 0x15F058u: goto label_15f058;
            case 0x15F060u: goto label_15f060;
            case 0x15F06Cu: goto label_15f06c;
            case 0x15F078u: goto label_15f078;
            case 0x15F080u: goto label_15f080;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F0A4u;
    // 0x15f0a4: 0x0  nop
    ctx->pc = 0x15f0a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
