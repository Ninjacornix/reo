#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5F70
// Address: 0x1f5f70 - 0x1f6350
void sub_001F5F70_0x1f5f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5F70_0x1f5f70");
#endif

    switch (ctx->pc) {
        case 0x1f5fb4u: goto label_1f5fb4;
        case 0x1f5ff8u: goto label_1f5ff8;
        case 0x1f6010u: goto label_1f6010;
        case 0x1f601cu: goto label_1f601c;
        case 0x1f6024u: goto label_1f6024;
        case 0x1f6034u: goto label_1f6034;
        case 0x1f6070u: goto label_1f6070;
        case 0x1f6078u: goto label_1f6078;
        case 0x1f6118u: goto label_1f6118;
        case 0x1f6148u: goto label_1f6148;
        case 0x1f615cu: goto label_1f615c;
        case 0x1f619cu: goto label_1f619c;
        case 0x1f61b4u: goto label_1f61b4;
        case 0x1f61dcu: goto label_1f61dc;
        case 0x1f6234u: goto label_1f6234;
        case 0x1f6264u: goto label_1f6264;
        case 0x1f62b0u: goto label_1f62b0;
        case 0x1f62c8u: goto label_1f62c8;
        case 0x1f62d8u: goto label_1f62d8;
        case 0x1f6324u: goto label_1f6324;
        case 0x1f633cu: goto label_1f633c;
        default: break;
    }

    ctx->pc = 0x1f5f70u;

    // 0x1f5f70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f5f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f5f74: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5f74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5f78: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f5f78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f5f7c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f5f7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5f80: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f5f80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5f84: 0x10400043  beqz        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1F5F84u;
    {
        const bool branch_taken_0x1f5f84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F84u;
            // 0x1f5f88: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5f84) {
            ctx->pc = 0x1F6094u;
            goto label_1f6094;
        }
    }
    ctx->pc = 0x1F5F8Cu;
    // 0x1f5f8c: 0xae00006c  sw          $zero, 0x6C($s0)
    ctx->pc = 0x1f5f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 108), GPR_U32(ctx, 0));
    // 0x1f5f90: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f5f90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f5f94: 0x8c2257c8  lw          $v0, 0x57C8($at)
    ctx->pc = 0x1f5f94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22472)));
    // 0x1f5f98: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1F5F98u;
    {
        const bool branch_taken_0x1f5f98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f5f98) {
            ctx->pc = 0x1F5FC4u;
            goto label_1f5fc4;
        }
    }
    ctx->pc = 0x1F5FA0u;
    // 0x1f5fa0: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f5fa0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f5fa4: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f5fa4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f5fa8: 0x2484ead0  addiu       $a0, $a0, -0x1530
    ctx->pc = 0x1f5fa8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961872));
    // 0x1f5fac: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F5FACu;
    SET_GPR_U32(ctx, 31, 0x1F5FB4u);
    ctx->pc = 0x1F5FB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5FACu;
            // 0x1f5fb0: 0x24a59b20  addiu       $a1, $a1, -0x64E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5FB4u; }
        if (ctx->pc != 0x1F5FB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5FB4u; }
        if (ctx->pc != 0x1F5FB4u) { return; }
    }
    ctx->pc = 0x1F5FB4u;
label_1f5fb4:
    // 0x1f5fb4: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f5fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f5fb8: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f5fb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f5fbc: 0x2442ead0  addiu       $v0, $v0, -0x1530
    ctx->pc = 0x1f5fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294961872));
    // 0x1f5fc0: 0xac2257c8  sw          $v0, 0x57C8($at)
    ctx->pc = 0x1f5fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 22472), GPR_U32(ctx, 2));
label_1f5fc4:
    // 0x1f5fc4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f5fc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f5fc8: 0x8c2257c0  lw          $v0, 0x57C0($at)
    ctx->pc = 0x1f5fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22464)));
    // 0x1f5fcc: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F5FCCu;
    {
        const bool branch_taken_0x1f5fcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f5fcc) {
            ctx->pc = 0x1F5FE4u;
            goto label_1f5fe4;
        }
    }
    ctx->pc = 0x1F5FD4u;
    // 0x1f5fd4: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f5fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f5fd8: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f5fd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f5fdc: 0x2442dad0  addiu       $v0, $v0, -0x2530
    ctx->pc = 0x1f5fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957776));
    // 0x1f5fe0: 0xac2257c0  sw          $v0, 0x57C0($at)
    ctx->pc = 0x1f5fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 22464), GPR_U32(ctx, 2));
label_1f5fe4:
    // 0x1f5fe4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f5fe4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f5fe8: 0x8c2257c8  lw          $v0, 0x57C8($at)
    ctx->pc = 0x1f5fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22472)));
    // 0x1f5fec: 0xae020070  sw          $v0, 0x70($s0)
    ctx->pc = 0x1f5fecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 112), GPR_U32(ctx, 2));
    // 0x1f5ff0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F5FF0u;
    SET_GPR_U32(ctx, 31, 0x1F5FF8u);
    ctx->pc = 0x1F5FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5FF0u;
            // 0x1f5ff4: 0x8e040070  lw          $a0, 0x70($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5FF8u; }
        if (ctx->pc != 0x1F5FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5FF8u; }
        if (ctx->pc != 0x1F5FF8u) { return; }
    }
    ctx->pc = 0x1F5FF8u;
label_1f5ff8:
    // 0x1f5ff8: 0xae020074  sw          $v0, 0x74($s0)
    ctx->pc = 0x1f5ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 2));
    // 0x1f5ffc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f5ffcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6000: 0x24050011  addiu       $a1, $zero, 0x11
    ctx->pc = 0x1f6000u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1f6004: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1f6004u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f6008: 0xc07d284  jal         func_1F4A10
    ctx->pc = 0x1F6008u;
    SET_GPR_U32(ctx, 31, 0x1F6010u);
    ctx->pc = 0x1F600Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6008u;
            // 0x1f600c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4A10u;
    if (runtime->hasFunction(0x1F4A10u)) {
        auto targetFn = runtime->lookupFunction(0x1F4A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6010u; }
        if (ctx->pc != 0x1F6010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4A10_0x1f4a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6010u; }
        if (ctx->pc != 0x1F6010u) { return; }
    }
    ctx->pc = 0x1F6010u;
label_1f6010:
    // 0x1f6010: 0x8e05006c  lw          $a1, 0x6C($s0)
    ctx->pc = 0x1f6010u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 108)));
    // 0x1f6014: 0xc07d308  jal         func_1F4C20
    ctx->pc = 0x1F6014u;
    SET_GPR_U32(ctx, 31, 0x1F601Cu);
    ctx->pc = 0x1F6018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6014u;
            // 0x1f6018: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4C20u;
    if (runtime->hasFunction(0x1F4C20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F601Cu; }
        if (ctx->pc != 0x1F601Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4C20_0x1f4c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F601Cu; }
        if (ctx->pc != 0x1F601Cu) { return; }
    }
    ctx->pc = 0x1F601Cu;
label_1f601c:
    // 0x1f601c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F601Cu;
    SET_GPR_U32(ctx, 31, 0x1F6024u);
    ctx->pc = 0x1F6020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F601Cu;
            // 0x1f6020: 0x8e040070  lw          $a0, 0x70($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6024u; }
        if (ctx->pc != 0x1F6024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6024u; }
        if (ctx->pc != 0x1F6024u) { return; }
    }
    ctx->pc = 0x1F6024u;
label_1f6024:
    // 0x1f6024: 0x8e050070  lw          $a1, 0x70($s0)
    ctx->pc = 0x1f6024u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x1f6028: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f6028u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f602c: 0xc07d330  jal         func_1F4CC0
    ctx->pc = 0x1F602Cu;
    SET_GPR_U32(ctx, 31, 0x1F6034u);
    ctx->pc = 0x1F6030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F602Cu;
            // 0x1f6030: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4CC0u;
    if (runtime->hasFunction(0x1F4CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6034u; }
        if (ctx->pc != 0x1F6034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4CC0_0x1f4cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6034u; }
        if (ctx->pc != 0x1F6034u) { return; }
    }
    ctx->pc = 0x1F6034u;
label_1f6034:
    // 0x1f6034: 0x9603002c  lhu         $v1, 0x2C($s0)
    ctx->pc = 0x1f6034u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f6038: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1f6038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f603c: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1f603cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1f6040: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x1f6040u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1f6044: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f6044u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f6048: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1f6048u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1f604c: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1f604cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1f6050: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f6050u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f6054: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x1f6054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f6058: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f6058u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f605c: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1f605cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f6060: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f6060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f6064: 0x2343c  dsll32      $a2, $v0, 16
    ctx->pc = 0x1f6064u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f6068: 0xc075aa4  jal         func_1D6A90
    ctx->pc = 0x1F6068u;
    SET_GPR_U32(ctx, 31, 0x1F6070u);
    ctx->pc = 0x1F606Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6068u;
            // 0x1f606c: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A90u;
    if (runtime->hasFunction(0x1D6A90u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6070u; }
        if (ctx->pc != 0x1F6070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A90_0x1d6a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6070u; }
        if (ctx->pc != 0x1F6070u) { return; }
    }
    ctx->pc = 0x1F6070u;
label_1f6070:
    // 0x1f6070: 0xc07d16c  jal         func_1F45B0
    ctx->pc = 0x1F6070u;
    SET_GPR_U32(ctx, 31, 0x1F6078u);
    ctx->pc = 0x1F6074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6070u;
            // 0x1f6074: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45B0u;
    if (runtime->hasFunction(0x1F45B0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6078u; }
        if (ctx->pc != 0x1F6078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45B0_0x1f45b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6078u; }
        if (ctx->pc != 0x1F6078u) { return; }
    }
    ctx->pc = 0x1F6078u;
label_1f6078:
    // 0x1f6078: 0x2841ffff  slti        $at, $v0, -0x1
    ctx->pc = 0x1f6078u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1f607c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F607Cu;
    {
        const bool branch_taken_0x1f607c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f607c) {
            ctx->pc = 0x1F608Cu;
            goto label_1f608c;
        }
    }
    ctx->pc = 0x1F6084u;
    // 0x1f6084: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F6084u;
    {
        const bool branch_taken_0x1f6084 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6084u;
            // 0x1f6088: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6084) {
            ctx->pc = 0x1F609Cu;
            goto label_1f609c;
        }
    }
    ctx->pc = 0x1F608Cu;
label_1f608c:
    // 0x1f608c: 0x2402000d  addiu       $v0, $zero, 0xD
    ctx->pc = 0x1f608cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1f6090: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f6090u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f6094:
    // 0x1f6094: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6094u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6098: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f6098u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f609c:
    // 0x1f609c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f609cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f60a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F60A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F60A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F60A0u;
            // 0x1f60a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F5FB4u: goto label_1f5fb4;
            case 0x1F5FC4u: goto label_1f5fc4;
            case 0x1F5FE4u: goto label_1f5fe4;
            case 0x1F5FF8u: goto label_1f5ff8;
            case 0x1F6010u: goto label_1f6010;
            case 0x1F601Cu: goto label_1f601c;
            case 0x1F6024u: goto label_1f6024;
            case 0x1F6034u: goto label_1f6034;
            case 0x1F6070u: goto label_1f6070;
            case 0x1F6078u: goto label_1f6078;
            case 0x1F608Cu: goto label_1f608c;
            case 0x1F6094u: goto label_1f6094;
            case 0x1F609Cu: goto label_1f609c;
            case 0x1F6110u: goto label_1f6110;
            case 0x1F6118u: goto label_1f6118;
            case 0x1F6140u: goto label_1f6140;
            case 0x1F6148u: goto label_1f6148;
            case 0x1F615Cu: goto label_1f615c;
            case 0x1F618Cu: goto label_1f618c;
            case 0x1F619Cu: goto label_1f619c;
            case 0x1F61ACu: goto label_1f61ac;
            case 0x1F61B4u: goto label_1f61b4;
            case 0x1F61D0u: goto label_1f61d0;
            case 0x1F61DCu: goto label_1f61dc;
            case 0x1F61F4u: goto label_1f61f4;
            case 0x1F61FCu: goto label_1f61fc;
            case 0x1F6200u: goto label_1f6200;
            case 0x1F6234u: goto label_1f6234;
            case 0x1F6248u: goto label_1f6248;
            case 0x1F6254u: goto label_1f6254;
            case 0x1F6264u: goto label_1f6264;
            case 0x1F6294u: goto label_1f6294;
            case 0x1F62B0u: goto label_1f62b0;
            case 0x1F62B8u: goto label_1f62b8;
            case 0x1F62C8u: goto label_1f62c8;
            case 0x1F62CCu: goto label_1f62cc;
            case 0x1F62D8u: goto label_1f62d8;
            case 0x1F6308u: goto label_1f6308;
            case 0x1F6324u: goto label_1f6324;
            case 0x1F632Cu: goto label_1f632c;
            case 0x1F633Cu: goto label_1f633c;
            case 0x1F6340u: goto label_1f6340;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F60A8u;
    // 0x1f60a8: 0x0  nop
    ctx->pc = 0x1f60a8u;
    // NOP
    // 0x1f60ac: 0x0  nop
    ctx->pc = 0x1f60acu;
    // NOP
    // 0x1f60b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f60b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f60b4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f60b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f60b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f60b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f60bc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f60bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f60c0: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f60c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f60c4: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x1f60c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f60c8: 0x1040004c  beqz        $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x1F60C8u;
    {
        const bool branch_taken_0x1f60c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F60CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F60C8u;
            // 0x1f60cc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f60c8) {
            ctx->pc = 0x1F61FCu;
            goto label_1f61fc;
        }
    }
    ctx->pc = 0x1F60D0u;
    // 0x1f60d0: 0x80630006  lb          $v1, 0x6($v1)
    ctx->pc = 0x1f60d0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 6)));
    // 0x1f60d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f60d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f60d8: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F60D8u;
    {
        const bool branch_taken_0x1f60d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F60DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F60D8u;
            // 0x1f60dc: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f60d8) {
            ctx->pc = 0x1F6110u;
            goto label_1f6110;
        }
    }
    ctx->pc = 0x1F60E0u;
    // 0x1f60e0: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f60e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f60e4: 0xae02008c  sw          $v0, 0x8C($s0)
    ctx->pc = 0x1f60e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 2));
    // 0x1f60e8: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f60e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f60ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f60ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f60f0: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f60f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f60f4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f60f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f60f8: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f60f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f60fc: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f60fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6100: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6100u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6104: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6104u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6108: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1F6108u;
    {
        const bool branch_taken_0x1f6108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F610Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6108u;
            // 0x1f610c: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6108) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F6110u;
label_1f6110:
    // 0x1f6110: 0xc07d1f8  jal         func_1F47E0
    ctx->pc = 0x1F6110u;
    SET_GPR_U32(ctx, 31, 0x1F6118u);
    ctx->pc = 0x1F47E0u;
    if (runtime->hasFunction(0x1F47E0u)) {
        auto targetFn = runtime->lookupFunction(0x1F47E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6118u; }
        if (ctx->pc != 0x1F6118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F47E0_0x1f47e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6118u; }
        if (ctx->pc != 0x1F6118u) { return; }
    }
    ctx->pc = 0x1F6118u;
label_1f6118:
    // 0x1f6118: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f6118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f611c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F611Cu;
    {
        const bool branch_taken_0x1f611c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F6120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F611Cu;
            // 0x1f6120: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f611c) {
            ctx->pc = 0x1F6140u;
            goto label_1f6140;
        }
    }
    ctx->pc = 0x1F6124u;
    // 0x1f6124: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f6124u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f6128: 0x24030012  addiu       $v1, $zero, 0x12
    ctx->pc = 0x1f6128u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1f612c: 0x8c2457c0  lw          $a0, 0x57C0($at)
    ctx->pc = 0x1f612cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22464)));
    // 0x1f6130: 0x2402ffc2  addiu       $v0, $zero, -0x3E
    ctx->pc = 0x1f6130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967234));
    // 0x1f6134: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1f6134u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6138: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1F6138u;
    {
        const bool branch_taken_0x1f6138 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F613Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6138u;
            // 0x1f613c: 0xa2030001  sb          $v1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6138) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F6140u;
label_1f6140:
    // 0x1f6140: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F6140u;
    SET_GPR_U32(ctx, 31, 0x1F6148u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6148u; }
        if (ctx->pc != 0x1F6148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6148u; }
        if (ctx->pc != 0x1F6148u) { return; }
    }
    ctx->pc = 0x1F6148u;
label_1f6148:
    // 0x1f6148: 0xae020078  sw          $v0, 0x78($s0)
    ctx->pc = 0x1f6148u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 120), GPR_U32(ctx, 2));
    // 0x1f614c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f614cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6150: 0x8e060074  lw          $a2, 0x74($s0)
    ctx->pc = 0x1f6150u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
    // 0x1f6154: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F6154u;
    SET_GPR_U32(ctx, 31, 0x1F615Cu);
    ctx->pc = 0x1F6158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6154u;
            // 0x1f6158: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F615Cu; }
        if (ctx->pc != 0x1F615Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F615Cu; }
        if (ctx->pc != 0x1F615Cu) { return; }
    }
    ctx->pc = 0x1F615Cu;
label_1f615c:
    // 0x1f615c: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F615Cu;
    {
        const bool branch_taken_0x1f615c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F615Cu;
            // 0x1f6160: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f615c) {
            ctx->pc = 0x1F618Cu;
            goto label_1f618c;
        }
    }
    ctx->pc = 0x1F6164u;
    // 0x1f6164: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6168: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6168u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f616c: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f616cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6170: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6170u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6174: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6174u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6178: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6178u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f617c: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f617cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6180: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6180u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6184: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6184u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6188: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1f6188u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f618c:
    // 0x1f618c: 0x8e050070  lw          $a1, 0x70($s0)
    ctx->pc = 0x1f618cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x1f6190: 0x8e060074  lw          $a2, 0x74($s0)
    ctx->pc = 0x1f6190u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
    // 0x1f6194: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1F6194u;
    SET_GPR_U32(ctx, 31, 0x1F619Cu);
    ctx->pc = 0x1F6198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6194u;
            // 0x1f6198: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F619Cu; }
        if (ctx->pc != 0x1F619Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F619Cu; }
        if (ctx->pc != 0x1F619Cu) { return; }
    }
    ctx->pc = 0x1F619Cu;
label_1f619c:
    // 0x1f619c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F619Cu;
    {
        const bool branch_taken_0x1f619c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F619Cu;
            // 0x1f61a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f619c) {
            ctx->pc = 0x1F61ACu;
            goto label_1f61ac;
        }
    }
    ctx->pc = 0x1F61A4u;
    // 0x1f61a4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1F61A4u;
    {
        const bool branch_taken_0x1f61a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61A4u;
            // 0x1f61a8: 0x2402ffc3  addiu       $v0, $zero, -0x3D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967235));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f61a4) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F61ACu;
label_1f61ac:
    // 0x1f61ac: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F61ACu;
    SET_GPR_U32(ctx, 31, 0x1F61B4u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61B4u; }
        if (ctx->pc != 0x1F61B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61B4u; }
        if (ctx->pc != 0x1F61B4u) { return; }
    }
    ctx->pc = 0x1F61B4u;
label_1f61b4:
    // 0x1f61b4: 0xae02007c  sw          $v0, 0x7C($s0)
    ctx->pc = 0x1f61b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 124), GPR_U32(ctx, 2));
    // 0x1f61b8: 0x8e02007c  lw          $v0, 0x7C($s0)
    ctx->pc = 0x1f61b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x1f61bc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F61BCu;
    {
        const bool branch_taken_0x1f61bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f61bc) {
            ctx->pc = 0x1F61D0u;
            goto label_1f61d0;
        }
    }
    ctx->pc = 0x1F61C4u;
    // 0x1f61c4: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f61c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f61c8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1F61C8u;
    {
        const bool branch_taken_0x1f61c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61C8u;
            // 0x1f61cc: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f61c8) {
            ctx->pc = 0x1F61F4u;
            goto label_1f61f4;
        }
    }
    ctx->pc = 0x1F61D0u;
label_1f61d0:
    // 0x1f61d0: 0xae000084  sw          $zero, 0x84($s0)
    ctx->pc = 0x1f61d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 0));
    // 0x1f61d4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F61D4u;
    SET_GPR_U32(ctx, 31, 0x1F61DCu);
    ctx->pc = 0x1F61D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61D4u;
            // 0x1f61d8: 0x8e040070  lw          $a0, 0x70($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61DCu; }
        if (ctx->pc != 0x1F61DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61DCu; }
        if (ctx->pc != 0x1F61DCu) { return; }
    }
    ctx->pc = 0x1F61DCu;
label_1f61dc:
    // 0x1f61dc: 0x2443000c  addiu       $v1, $v0, 0xC
    ctx->pc = 0x1f61dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1f61e0: 0x240202fe  addiu       $v0, $zero, 0x2FE
    ctx->pc = 0x1f61e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 766));
    // 0x1f61e4: 0x431823  subu        $v1, $v0, $v1
    ctx->pc = 0x1f61e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f61e8: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1f61e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1f61ec: 0xa6030080  sh          $v1, 0x80($s0)
    ctx->pc = 0x1f61ecu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 128), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f61f0: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f61f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f61f4:
    // 0x1f61f4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F61F4u;
    {
        const bool branch_taken_0x1f61f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61F4u;
            // 0x1f61f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f61f4) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F61FCu;
label_1f61fc:
    // 0x1f61fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f61fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f6200:
    // 0x1f6200: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f6200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f6204: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6204u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6208: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6208u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F620Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6208u;
            // 0x1f620c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F5FB4u: goto label_1f5fb4;
            case 0x1F5FC4u: goto label_1f5fc4;
            case 0x1F5FE4u: goto label_1f5fe4;
            case 0x1F5FF8u: goto label_1f5ff8;
            case 0x1F6010u: goto label_1f6010;
            case 0x1F601Cu: goto label_1f601c;
            case 0x1F6024u: goto label_1f6024;
            case 0x1F6034u: goto label_1f6034;
            case 0x1F6070u: goto label_1f6070;
            case 0x1F6078u: goto label_1f6078;
            case 0x1F608Cu: goto label_1f608c;
            case 0x1F6094u: goto label_1f6094;
            case 0x1F609Cu: goto label_1f609c;
            case 0x1F6110u: goto label_1f6110;
            case 0x1F6118u: goto label_1f6118;
            case 0x1F6140u: goto label_1f6140;
            case 0x1F6148u: goto label_1f6148;
            case 0x1F615Cu: goto label_1f615c;
            case 0x1F618Cu: goto label_1f618c;
            case 0x1F619Cu: goto label_1f619c;
            case 0x1F61ACu: goto label_1f61ac;
            case 0x1F61B4u: goto label_1f61b4;
            case 0x1F61D0u: goto label_1f61d0;
            case 0x1F61DCu: goto label_1f61dc;
            case 0x1F61F4u: goto label_1f61f4;
            case 0x1F61FCu: goto label_1f61fc;
            case 0x1F6200u: goto label_1f6200;
            case 0x1F6234u: goto label_1f6234;
            case 0x1F6248u: goto label_1f6248;
            case 0x1F6254u: goto label_1f6254;
            case 0x1F6264u: goto label_1f6264;
            case 0x1F6294u: goto label_1f6294;
            case 0x1F62B0u: goto label_1f62b0;
            case 0x1F62B8u: goto label_1f62b8;
            case 0x1F62C8u: goto label_1f62c8;
            case 0x1F62CCu: goto label_1f62cc;
            case 0x1F62D8u: goto label_1f62d8;
            case 0x1F6308u: goto label_1f6308;
            case 0x1F6324u: goto label_1f6324;
            case 0x1F632Cu: goto label_1f632c;
            case 0x1F633Cu: goto label_1f633c;
            case 0x1F6340u: goto label_1f6340;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6210u;
    // 0x1f6210: 0x27bdfbe0  addiu       $sp, $sp, -0x420
    ctx->pc = 0x1f6210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966240));
    // 0x1f6214: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6214u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6218: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f621c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f621cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6220: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f6220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f6224: 0x10400045  beqz        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1F6224u;
    {
        const bool branch_taken_0x1f6224 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6224u;
            // 0x1f6228: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6224) {
            ctx->pc = 0x1F633Cu;
            goto label_1f633c;
        }
    }
    ctx->pc = 0x1F622Cu;
    // 0x1f622c: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F622Cu;
    SET_GPR_U32(ctx, 31, 0x1F6234u);
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6234u; }
        if (ctx->pc != 0x1F6234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6234u; }
        if (ctx->pc != 0x1F6234u) { return; }
    }
    ctx->pc = 0x1F6234u;
label_1f6234:
    // 0x1f6234: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f6234u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f6238: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6238u;
    {
        const bool branch_taken_0x1f6238 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F623Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6238u;
            // 0x1f623c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6238) {
            ctx->pc = 0x1F6248u;
            goto label_1f6248;
        }
    }
    ctx->pc = 0x1F6240u;
    // 0x1f6240: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F6240u;
    {
        const bool branch_taken_0x1f6240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6240u;
            // 0x1f6244: 0xac22c7f8  sw          $v0, -0x3808($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294952952), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6240) {
            ctx->pc = 0x1F6254u;
            goto label_1f6254;
        }
    }
    ctx->pc = 0x1F6248u;
label_1f6248:
    // 0x1f6248: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1f6248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1f624c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f624cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f6250: 0xac22c7f8  sw          $v0, -0x3808($at)
    ctx->pc = 0x1f6250u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952952), GPR_U32(ctx, 2));
label_1f6254:
    // 0x1f6254: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f6254u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6258: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f6258u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f625c: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F625Cu;
    SET_GPR_U32(ctx, 31, 0x1F6264u);
    ctx->pc = 0x1F6260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F625Cu;
            // 0x1f6260: 0x240600ff  addiu       $a2, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6264u; }
        if (ctx->pc != 0x1F6264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6264u; }
        if (ctx->pc != 0x1F6264u) { return; }
    }
    ctx->pc = 0x1F6264u;
label_1f6264:
    // 0x1f6264: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F6264u;
    {
        const bool branch_taken_0x1f6264 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6264u;
            // 0x1f6268: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6264) {
            ctx->pc = 0x1F6294u;
            goto label_1f6294;
        }
    }
    ctx->pc = 0x1F626Cu;
    // 0x1f626c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f626cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6270: 0xae04008c  sw          $a0, 0x8C($s0)
    ctx->pc = 0x1f6270u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 4));
    // 0x1f6274: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f6274u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6278: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6278u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f627c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f627cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6280: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6280u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6284: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6284u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6288: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6288u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f628c: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f628cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6290: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1f6290u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6294:
    // 0x1f6294: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F6294u;
    {
        const bool branch_taken_0x1f6294 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6294u;
            // 0x1f6298: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6294) {
            ctx->pc = 0x1F62B8u;
            goto label_1f62b8;
        }
    }
    ctx->pc = 0x1F629Cu;
    // 0x1f629c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f629cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f62a0: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f62a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f62a4: 0x2484c6f0  addiu       $a0, $a0, -0x3910
    ctx->pc = 0x1f62a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952688));
    // 0x1f62a8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1F62A8u;
    SET_GPR_U32(ctx, 31, 0x1F62B0u);
    ctx->pc = 0x1F62ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62A8u;
            // 0x1f62ac: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62B0u; }
        if (ctx->pc != 0x1F62B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62B0u; }
        if (ctx->pc != 0x1F62B0u) { return; }
    }
    ctx->pc = 0x1F62B0u;
label_1f62b0:
    // 0x1f62b0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F62B0u;
    {
        const bool branch_taken_0x1f62b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F62B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62B0u;
            // 0x1f62b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f62b0) {
            ctx->pc = 0x1F62CCu;
            goto label_1f62cc;
        }
    }
    ctx->pc = 0x1F62B8u;
label_1f62b8:
    // 0x1f62b8: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f62b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f62bc: 0x2484c6f0  addiu       $a0, $a0, -0x3910
    ctx->pc = 0x1f62bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952688));
    // 0x1f62c0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F62C0u;
    SET_GPR_U32(ctx, 31, 0x1F62C8u);
    ctx->pc = 0x1F62C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62C0u;
            // 0x1f62c4: 0x24a59b40  addiu       $a1, $a1, -0x64C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62C8u; }
        if (ctx->pc != 0x1F62C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62C8u; }
        if (ctx->pc != 0x1F62C8u) { return; }
    }
    ctx->pc = 0x1F62C8u;
label_1f62c8:
    // 0x1f62c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f62c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1f62cc:
    // 0x1f62cc: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f62ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f62d0: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F62D0u;
    SET_GPR_U32(ctx, 31, 0x1F62D8u);
    ctx->pc = 0x1F62D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62D0u;
            // 0x1f62d4: 0x240600ff  addiu       $a2, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62D8u; }
        if (ctx->pc != 0x1F62D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62D8u; }
        if (ctx->pc != 0x1F62D8u) { return; }
    }
    ctx->pc = 0x1F62D8u;
label_1f62d8:
    // 0x1f62d8: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F62D8u;
    {
        const bool branch_taken_0x1f62d8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F62DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62D8u;
            // 0x1f62dc: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f62d8) {
            ctx->pc = 0x1F6308u;
            goto label_1f6308;
        }
    }
    ctx->pc = 0x1F62E0u;
    // 0x1f62e0: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f62e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f62e4: 0xae04008c  sw          $a0, 0x8C($s0)
    ctx->pc = 0x1f62e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 4));
    // 0x1f62e8: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f62e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f62ec: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f62ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f62f0: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f62f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f62f4: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f62f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f62f8: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f62f8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f62fc: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f62fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6300: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6300u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6304: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1f6304u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6308:
    // 0x1f6308: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F6308u;
    {
        const bool branch_taken_0x1f6308 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F630Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6308u;
            // 0x1f630c: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6308) {
            ctx->pc = 0x1F632Cu;
            goto label_1f632c;
        }
    }
    ctx->pc = 0x1F6310u;
    // 0x1f6310: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f6310u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f6314: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f6314u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f6318: 0x2484cc60  addiu       $a0, $a0, -0x33A0
    ctx->pc = 0x1f6318u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954080));
    // 0x1f631c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1F631Cu;
    SET_GPR_U32(ctx, 31, 0x1F6324u);
    ctx->pc = 0x1F6320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F631Cu;
            // 0x1f6320: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6324u; }
        if (ctx->pc != 0x1F6324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6324u; }
        if (ctx->pc != 0x1F6324u) { return; }
    }
    ctx->pc = 0x1F6324u;
label_1f6324:
    // 0x1f6324: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F6324u;
    {
        const bool branch_taken_0x1f6324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6324u;
            // 0x1f6328: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6324) {
            ctx->pc = 0x1F6340u;
            goto label_1f6340;
        }
    }
    ctx->pc = 0x1F632Cu;
label_1f632c:
    // 0x1f632c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f632cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f6330: 0x2484cc60  addiu       $a0, $a0, -0x33A0
    ctx->pc = 0x1f6330u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954080));
    // 0x1f6334: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F6334u;
    SET_GPR_U32(ctx, 31, 0x1F633Cu);
    ctx->pc = 0x1F6338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6334u;
            // 0x1f6338: 0x24a59b80  addiu       $a1, $a1, -0x6480 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F633Cu; }
        if (ctx->pc != 0x1F633Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F633Cu; }
        if (ctx->pc != 0x1F633Cu) { return; }
    }
    ctx->pc = 0x1F633Cu;
label_1f633c:
    // 0x1f633c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f633cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f6340:
    // 0x1f6340: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6340u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6344: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6344u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6348: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6348u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F634Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6348u;
            // 0x1f634c: 0x27bd0420  addiu       $sp, $sp, 0x420 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1056));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F5FB4u: goto label_1f5fb4;
            case 0x1F5FC4u: goto label_1f5fc4;
            case 0x1F5FE4u: goto label_1f5fe4;
            case 0x1F5FF8u: goto label_1f5ff8;
            case 0x1F6010u: goto label_1f6010;
            case 0x1F601Cu: goto label_1f601c;
            case 0x1F6024u: goto label_1f6024;
            case 0x1F6034u: goto label_1f6034;
            case 0x1F6070u: goto label_1f6070;
            case 0x1F6078u: goto label_1f6078;
            case 0x1F608Cu: goto label_1f608c;
            case 0x1F6094u: goto label_1f6094;
            case 0x1F609Cu: goto label_1f609c;
            case 0x1F6110u: goto label_1f6110;
            case 0x1F6118u: goto label_1f6118;
            case 0x1F6140u: goto label_1f6140;
            case 0x1F6148u: goto label_1f6148;
            case 0x1F615Cu: goto label_1f615c;
            case 0x1F618Cu: goto label_1f618c;
            case 0x1F619Cu: goto label_1f619c;
            case 0x1F61ACu: goto label_1f61ac;
            case 0x1F61B4u: goto label_1f61b4;
            case 0x1F61D0u: goto label_1f61d0;
            case 0x1F61DCu: goto label_1f61dc;
            case 0x1F61F4u: goto label_1f61f4;
            case 0x1F61FCu: goto label_1f61fc;
            case 0x1F6200u: goto label_1f6200;
            case 0x1F6234u: goto label_1f6234;
            case 0x1F6248u: goto label_1f6248;
            case 0x1F6254u: goto label_1f6254;
            case 0x1F6264u: goto label_1f6264;
            case 0x1F6294u: goto label_1f6294;
            case 0x1F62B0u: goto label_1f62b0;
            case 0x1F62B8u: goto label_1f62b8;
            case 0x1F62C8u: goto label_1f62c8;
            case 0x1F62CCu: goto label_1f62cc;
            case 0x1F62D8u: goto label_1f62d8;
            case 0x1F6308u: goto label_1f6308;
            case 0x1F6324u: goto label_1f6324;
            case 0x1F632Cu: goto label_1f632c;
            case 0x1F633Cu: goto label_1f633c;
            case 0x1F6340u: goto label_1f6340;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6350u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
