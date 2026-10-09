#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4020
// Address: 0x1d4020 - 0x1d4124
void sub_001D4020_0x1d4020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4020_0x1d4020");
#endif

    switch (ctx->pc) {
        case 0x1d4074u: goto label_1d4074;
        case 0x1d4098u: goto label_1d4098;
        case 0x1d40acu: goto label_1d40ac;
        case 0x1d40e0u: goto label_1d40e0;
        case 0x1d40fcu: goto label_1d40fc;
        case 0x1d4108u: goto label_1d4108;
        default: break;
    }

    ctx->pc = 0x1d4020u;

    // 0x1d4020: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d4020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d4024: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1d4024u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1d4028: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d402c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d402cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4030: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4030u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4034: 0x8c30443c  lw          $s0, 0x443C($at)
    ctx->pc = 0x1d4034u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17468)));
    // 0x1d4038: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4038u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d403c: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d403cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4040: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D4040u;
    {
        const bool branch_taken_0x1d4040 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4040u;
            // 0x1d4044: 0x246343c0  addiu       $v1, $v1, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4040) {
            ctx->pc = 0x1D40BCu;
            goto label_1d40bc;
        }
    }
    ctx->pc = 0x1D4048u;
    // 0x1d4048: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4048u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d404c: 0x902243fd  lbu         $v0, 0x43FD($at)
    ctx->pc = 0x1d404cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17405)));
    // 0x1d4050: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D4050u;
    {
        const bool branch_taken_0x1d4050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4050) {
            ctx->pc = 0x1D407Cu;
            goto label_1d407c;
        }
    }
    ctx->pc = 0x1D4058u;
    // 0x1d4058: 0x9467001a  lhu         $a3, 0x1A($v1)
    ctx->pc = 0x1d4058u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d405c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d405cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4060: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d4060u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d4064: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d4064u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4068: 0x24a56738  addiu       $a1, $a1, 0x6738
    ctx->pc = 0x1d4068u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26424));
    // 0x1d406c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D406Cu;
    SET_GPR_U32(ctx, 31, 0x1D4074u);
    ctx->pc = 0x1D4070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D406Cu;
            // 0x1d4070: 0x24c66750  addiu       $a2, $a2, 0x6750 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4074u; }
        if (ctx->pc != 0x1D4074u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4074u; }
        if (ctx->pc != 0x1D4074u) { return; }
    }
    ctx->pc = 0x1D4074u;
label_1d4074:
    // 0x1d4074: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D4074u;
    {
        const bool branch_taken_0x1d4074 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4074u;
            // 0x1d4078: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4074) {
            ctx->pc = 0x1D409Cu;
            goto label_1d409c;
        }
    }
    ctx->pc = 0x1D407Cu;
label_1d407c:
    // 0x1d407c: 0x9467001a  lhu         $a3, 0x1A($v1)
    ctx->pc = 0x1d407cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d4080: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4080u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4084: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d4084u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d4088: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d4088u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d408c: 0x24a56768  addiu       $a1, $a1, 0x6768
    ctx->pc = 0x1d408cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26472));
    // 0x1d4090: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4090u;
    SET_GPR_U32(ctx, 31, 0x1D4098u);
    ctx->pc = 0x1D4094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4090u;
            // 0x1d4094: 0x24c66750  addiu       $a2, $a2, 0x6750 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4098u; }
        if (ctx->pc != 0x1D4098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4098u; }
        if (ctx->pc != 0x1D4098u) { return; }
    }
    ctx->pc = 0x1D4098u;
label_1d4098:
    // 0x1d4098: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d4098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
label_1d409c:
    // 0x1d409c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d409cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d40a0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d40a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d40a4: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D40A4u;
    SET_GPR_U32(ctx, 31, 0x1D40ACu);
    ctx->pc = 0x1D40A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D40A4u;
            // 0x1d40a8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40ACu; }
        if (ctx->pc != 0x1D40ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40ACu; }
        if (ctx->pc != 0x1D40ACu) { return; }
    }
    ctx->pc = 0x1D40ACu;
label_1d40ac:
    // 0x1d40ac: 0x1c400019  bgtz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1D40ACu;
    {
        const bool branch_taken_0x1d40ac = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d40ac) {
            ctx->pc = 0x1D4114u;
            goto label_1d4114;
        }
    }
    ctx->pc = 0x1D40B4u;
    // 0x1d40b4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1D40B4u;
    {
        const bool branch_taken_0x1d40b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D40B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D40B4u;
            // 0x1d40b8: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d40b4) {
            ctx->pc = 0x1D4114u;
            goto label_1d4114;
        }
    }
    ctx->pc = 0x1D40BCu;
label_1d40bc:
    // 0x1d40bc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d40bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d40c0: 0x902243fd  lbu         $v0, 0x43FD($at)
    ctx->pc = 0x1d40c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17405)));
    // 0x1d40c4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D40C4u;
    {
        const bool branch_taken_0x1d40c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d40c4) {
            ctx->pc = 0x1D40E8u;
            goto label_1d40e8;
        }
    }
    ctx->pc = 0x1D40CCu;
    // 0x1d40cc: 0x9466001a  lhu         $a2, 0x1A($v1)
    ctx->pc = 0x1d40ccu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d40d0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d40d0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d40d4: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d40d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d40d8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D40D8u;
    SET_GPR_U32(ctx, 31, 0x1D40E0u);
    ctx->pc = 0x1D40DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D40D8u;
            // 0x1d40dc: 0x24a56778  addiu       $a1, $a1, 0x6778 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26488));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40E0u; }
        if (ctx->pc != 0x1D40E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40E0u; }
        if (ctx->pc != 0x1D40E0u) { return; }
    }
    ctx->pc = 0x1D40E0u;
label_1d40e0:
    // 0x1d40e0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D40E0u;
    {
        const bool branch_taken_0x1d40e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D40E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D40E0u;
            // 0x1d40e4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d40e0) {
            ctx->pc = 0x1D4100u;
            goto label_1d4100;
        }
    }
    ctx->pc = 0x1D40E8u;
label_1d40e8:
    // 0x1d40e8: 0x9466001a  lhu         $a2, 0x1A($v1)
    ctx->pc = 0x1d40e8u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d40ec: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d40ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d40f0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d40f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d40f4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D40F4u;
    SET_GPR_U32(ctx, 31, 0x1D40FCu);
    ctx->pc = 0x1D40F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D40F4u;
            // 0x1d40f8: 0x24a56788  addiu       $a1, $a1, 0x6788 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40FCu; }
        if (ctx->pc != 0x1D40FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40FCu; }
        if (ctx->pc != 0x1D40FCu) { return; }
    }
    ctx->pc = 0x1D40FCu;
label_1d40fc:
    // 0x1d40fc: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d40fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
label_1d4100:
    // 0x1d4100: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D4100u;
    SET_GPR_U32(ctx, 31, 0x1D4108u);
    ctx->pc = 0x1D4104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4100u;
            // 0x1d4104: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4108u; }
        if (ctx->pc != 0x1D4108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4108u; }
        if (ctx->pc != 0x1D4108u) { return; }
    }
    ctx->pc = 0x1D4108u;
label_1d4108:
    // 0x1d4108: 0x1c400002  bgtz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D4108u;
    {
        const bool branch_taken_0x1d4108 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d4108) {
            ctx->pc = 0x1D4114u;
            goto label_1d4114;
        }
    }
    ctx->pc = 0x1D4110u;
    // 0x1d4110: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1d4110u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_1d4114:
    // 0x1d4114: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4118: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4118u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d411c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D411Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D411Cu;
            // 0x1d4120: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4074u: goto label_1d4074;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D4098u: goto label_1d4098;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40ACu: goto label_1d40ac;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E0u: goto label_1d40e0;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D40FCu: goto label_1d40fc;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4108u: goto label_1d4108;
            case 0x1D4114u: goto label_1d4114;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4124u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
