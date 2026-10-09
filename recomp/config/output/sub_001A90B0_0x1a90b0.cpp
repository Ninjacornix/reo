#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A90B0
// Address: 0x1a90b0 - 0x1a9180
void sub_001A90B0_0x1a90b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A90B0_0x1a90b0");
#endif

    switch (ctx->pc) {
        case 0x1a90c0u: goto label_1a90c0;
        case 0x1a90fcu: goto label_1a90fc;
        case 0x1a9114u: goto label_1a9114;
        case 0x1a9124u: goto label_1a9124;
        case 0x1a9144u: goto label_1a9144;
        case 0x1a915cu: goto label_1a915c;
        case 0x1a916cu: goto label_1a916c;
        default: break;
    }

    ctx->pc = 0x1a90b0u;

    // 0x1a90b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a90b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a90b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a90b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a90b8: 0xc06b1c4  jal         func_1AC710
    ctx->pc = 0x1A90B8u;
    SET_GPR_U32(ctx, 31, 0x1A90C0u);
    ctx->pc = 0x1A90BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A90B8u;
            // 0x1a90bc: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC710u;
    if (runtime->hasFunction(0x1AC710u)) {
        auto targetFn = runtime->lookupFunction(0x1AC710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A90C0u; }
        if (ctx->pc != 0x1A90C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC710_0x1ac710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A90C0u; }
        if (ctx->pc != 0x1A90C0u) { return; }
    }
    ctx->pc = 0x1A90C0u;
label_1a90c0:
    // 0x1a90c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a90c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a90c4: 0x8c23fa0c  lw          $v1, -0x5F4($at)
    ctx->pc = 0x1a90c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965772)));
    // 0x1a90c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a90c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a90cc: 0x8c22fa04  lw          $v0, -0x5FC($at)
    ctx->pc = 0x1a90ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965764)));
    // 0x1a90d0: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1a90d0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a90d4: 0x14200019  bnez        $at, . + 4 + (0x19 << 2)
    ctx->pc = 0x1A90D4u;
    {
        const bool branch_taken_0x1a90d4 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A90D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A90D4u;
            // 0x1a90d8: 0x3c011200  lui         $at, 0x1200 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a90d4) {
            ctx->pc = 0x1A913Cu;
            goto label_1a913c;
        }
    }
    ctx->pc = 0x1A90DCu;
    // 0x1a90dc: 0xdc221000  ld          $v0, 0x1000($at)
    ctx->pc = 0x1a90dcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4096)));
    // 0x1a90e0: 0x2137a  dsrl        $v0, $v0, 13
    ctx->pc = 0x1a90e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 13);
    // 0x1a90e4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a90e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a90e8: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1a90e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1a90ec: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1a90ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a90f0: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1a90f0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1a90f4: 0xc06a41c  jal         func_1A9070
    ctx->pc = 0x1A90F4u;
    SET_GPR_U32(ctx, 31, 0x1A90FCu);
    ctx->pc = 0x1A90F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A90F4u;
            // 0x1a90f8: 0xac22f9fc  sw          $v0, -0x604($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965756), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9070u;
    if (runtime->hasFunction(0x1A9070u)) {
        auto targetFn = runtime->lookupFunction(0x1A9070u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A90FCu; }
        if (ctx->pc != 0x1A90FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9070_0x1a9070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A90FCu; }
        if (ctx->pc != 0x1A90FCu) { return; }
    }
    ctx->pc = 0x1A90FCu;
label_1a90fc:
    // 0x1a90fc: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a90fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a9100: 0x8c220ec0  lw          $v0, 0xEC0($at)
    ctx->pc = 0x1a9100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 3776)));
    // 0x1a9104: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A9104u;
    {
        const bool branch_taken_0x1a9104 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9104u;
            // 0x1a9108: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9104) {
            ctx->pc = 0x1A911Cu;
            goto label_1a911c;
        }
    }
    ctx->pc = 0x1A910Cu;
    // 0x1a910c: 0xc057e94  jal         func_15FA50
    ctx->pc = 0x1A910Cu;
    SET_GPR_U32(ctx, 31, 0x1A9114u);
    ctx->pc = 0x15FA50u;
    if (runtime->hasFunction(0x15FA50u)) {
        auto targetFn = runtime->lookupFunction(0x15FA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9114u; }
        if (ctx->pc != 0x1A9114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FA50_0x15fa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9114u; }
        if (ctx->pc != 0x1A9114u) { return; }
    }
    ctx->pc = 0x1A9114u;
label_1a9114:
    // 0x1a9114: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9114u;
    {
        const bool branch_taken_0x1a9114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9114) {
            ctx->pc = 0x1A9124u;
            goto label_1a9124;
        }
    }
    ctx->pc = 0x1A911Cu;
label_1a911c:
    // 0x1a911c: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1A911Cu;
    SET_GPR_U32(ctx, 31, 0x1A9124u);
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9124u; }
        if (ctx->pc != 0x1A9124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9124u; }
        if (ctx->pc != 0x1A9124u) { return; }
    }
    ctx->pc = 0x1A9124u;
label_1a9124:
    // 0x1a9124: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a9124u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a9128: 0x8c23fa10  lw          $v1, -0x5F0($at)
    ctx->pc = 0x1a9128u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965776)));
    // 0x1a912c: 0x1460fff3  bnez        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A912Cu;
    {
        const bool branch_taken_0x1a912c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a912c) {
            ctx->pc = 0x1A90FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a90fc;
        }
    }
    ctx->pc = 0x1A9134u;
    // 0x1a9134: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1A9134u;
    {
        const bool branch_taken_0x1a9134 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9134u;
            // 0x1a9138: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9134) {
            ctx->pc = 0x1A9170u;
            goto label_1a9170;
        }
    }
    ctx->pc = 0x1A913Cu;
label_1a913c:
    // 0x1a913c: 0xc06a41c  jal         func_1A9070
    ctx->pc = 0x1A913Cu;
    SET_GPR_U32(ctx, 31, 0x1A9144u);
    ctx->pc = 0x1A9070u;
    if (runtime->hasFunction(0x1A9070u)) {
        auto targetFn = runtime->lookupFunction(0x1A9070u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9144u; }
        if (ctx->pc != 0x1A9144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9070_0x1a9070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9144u; }
        if (ctx->pc != 0x1A9144u) { return; }
    }
    ctx->pc = 0x1A9144u;
label_1a9144:
    // 0x1a9144: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9144u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a9148: 0x8c220ec0  lw          $v0, 0xEC0($at)
    ctx->pc = 0x1a9148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 3776)));
    // 0x1a914c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A914Cu;
    {
        const bool branch_taken_0x1a914c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A914Cu;
            // 0x1a9150: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a914c) {
            ctx->pc = 0x1A9164u;
            goto label_1a9164;
        }
    }
    ctx->pc = 0x1A9154u;
    // 0x1a9154: 0xc057e94  jal         func_15FA50
    ctx->pc = 0x1A9154u;
    SET_GPR_U32(ctx, 31, 0x1A915Cu);
    ctx->pc = 0x15FA50u;
    if (runtime->hasFunction(0x15FA50u)) {
        auto targetFn = runtime->lookupFunction(0x15FA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A915Cu; }
        if (ctx->pc != 0x1A915Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FA50_0x15fa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A915Cu; }
        if (ctx->pc != 0x1A915Cu) { return; }
    }
    ctx->pc = 0x1A915Cu;
label_1a915c:
    // 0x1a915c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A915Cu;
    {
        const bool branch_taken_0x1a915c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a915c) {
            ctx->pc = 0x1A916Cu;
            goto label_1a916c;
        }
    }
    ctx->pc = 0x1A9164u;
label_1a9164:
    // 0x1a9164: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1A9164u;
    SET_GPR_U32(ctx, 31, 0x1A916Cu);
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A916Cu; }
        if (ctx->pc != 0x1A916Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A916Cu; }
        if (ctx->pc != 0x1A916Cu) { return; }
    }
    ctx->pc = 0x1A916Cu;
label_1a916c:
    // 0x1a916c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a916cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a9170:
    // 0x1a9170: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9170u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9170u;
            // 0x1a9174: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A90C0u: goto label_1a90c0;
            case 0x1A90FCu: goto label_1a90fc;
            case 0x1A9114u: goto label_1a9114;
            case 0x1A911Cu: goto label_1a911c;
            case 0x1A9124u: goto label_1a9124;
            case 0x1A913Cu: goto label_1a913c;
            case 0x1A9144u: goto label_1a9144;
            case 0x1A915Cu: goto label_1a915c;
            case 0x1A9164u: goto label_1a9164;
            case 0x1A916Cu: goto label_1a916c;
            case 0x1A9170u: goto label_1a9170;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9178u;
    // 0x1a9178: 0x0  nop
    ctx->pc = 0x1a9178u;
    // NOP
    // 0x1a917c: 0x0  nop
    ctx->pc = 0x1a917cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
