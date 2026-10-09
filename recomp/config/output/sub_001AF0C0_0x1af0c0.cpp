#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF0C0
// Address: 0x1af0c0 - 0x1af1e0
void sub_001AF0C0_0x1af0c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF0C0_0x1af0c0");
#endif

    switch (ctx->pc) {
        case 0x1af0ecu: goto label_1af0ec;
        case 0x1af100u: goto label_1af100;
        case 0x1af10cu: goto label_1af10c;
        case 0x1af118u: goto label_1af118;
        case 0x1af124u: goto label_1af124;
        case 0x1af134u: goto label_1af134;
        case 0x1af140u: goto label_1af140;
        case 0x1af14cu: goto label_1af14c;
        case 0x1af158u: goto label_1af158;
        case 0x1af164u: goto label_1af164;
        case 0x1af170u: goto label_1af170;
        case 0x1af17cu: goto label_1af17c;
        case 0x1af188u: goto label_1af188;
        case 0x1af1c0u: goto label_1af1c0;
        case 0x1af1ccu: goto label_1af1cc;
        default: break;
    }

    ctx->pc = 0x1af0c0u;

    // 0x1af0c0: 0x24022710  addiu       $v0, $zero, 0x2710
    ctx->pc = 0x1af0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10000));
    // 0x1af0c4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1af0c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1af0c8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1af0c8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1af0cc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1af0ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1af0d0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1af0d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1af0d4: 0x3c0343fa  lui         $v1, 0x43FA
    ctx->pc = 0x1af0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17402 << 16));
    // 0x1af0d8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1af0d8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1af0dc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1af0dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af0e0: 0xafa3002c  sw          $v1, 0x2C($sp)
    ctx->pc = 0x1af0e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 3));
    // 0x1af0e4: 0xc06bddc  jal         func_1AF770
    ctx->pc = 0x1AF0E4u;
    SET_GPR_U32(ctx, 31, 0x1AF0ECu);
    ctx->pc = 0x1AF0E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF0E4u;
            // 0x1af0e8: 0xe7a00028  swc1        $f0, 0x28($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF770u;
    if (runtime->hasFunction(0x1AF770u)) {
        auto targetFn = runtime->lookupFunction(0x1AF770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF0ECu; }
        if (ctx->pc != 0x1AF0ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF770_0x1af770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF0ECu; }
        if (ctx->pc != 0x1AF0ECu) { return; }
    }
    ctx->pc = 0x1AF0ECu;
label_1af0ec:
    // 0x1af0ec: 0x16000026  bnez        $s0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1AF0ECu;
    {
        const bool branch_taken_0x1af0ec = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1af0ec) {
            ctx->pc = 0x1AF188u;
            goto label_1af188;
        }
    }
    ctx->pc = 0x1AF0F4u;
    // 0x1af0f4: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x1af0f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1af0f8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF0F8u;
    SET_GPR_U32(ctx, 31, 0x1AF100u);
    ctx->pc = 0x1AF0FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF0F8u;
            // 0x1af0fc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF100u; }
        if (ctx->pc != 0x1AF100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF100u; }
        if (ctx->pc != 0x1AF100u) { return; }
    }
    ctx->pc = 0x1AF100u;
label_1af100:
    // 0x1af100: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1af100u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1af104: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF104u;
    SET_GPR_U32(ctx, 31, 0x1AF10Cu);
    ctx->pc = 0x1AF108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF104u;
            // 0x1af108: 0x24050200  addiu       $a1, $zero, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF10Cu; }
        if (ctx->pc != 0x1AF10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF10Cu; }
        if (ctx->pc != 0x1AF10Cu) { return; }
    }
    ctx->pc = 0x1AF10Cu;
label_1af10c:
    // 0x1af10c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1af10cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1af110: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF110u;
    SET_GPR_U32(ctx, 31, 0x1AF118u);
    ctx->pc = 0x1AF114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF110u;
            // 0x1af114: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF118u; }
        if (ctx->pc != 0x1AF118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF118u; }
        if (ctx->pc != 0x1AF118u) { return; }
    }
    ctx->pc = 0x1AF118u;
label_1af118:
    // 0x1af118: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1af118u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1af11c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF11Cu;
    SET_GPR_U32(ctx, 31, 0x1AF124u);
    ctx->pc = 0x1AF120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF11Cu;
            // 0x1af120: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF124u; }
        if (ctx->pc != 0x1AF124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF124u; }
        if (ctx->pc != 0x1AF124u) { return; }
    }
    ctx->pc = 0x1AF124u;
label_1af124:
    // 0x1af124: 0x3c0280ff  lui         $v0, 0x80FF
    ctx->pc = 0x1af124u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33023 << 16));
    // 0x1af128: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x1af128u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1af12c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF12Cu;
    SET_GPR_U32(ctx, 31, 0x1AF134u);
    ctx->pc = 0x1AF130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF12Cu;
            // 0x1af130: 0x3445ffff  ori         $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF134u; }
        if (ctx->pc != 0x1AF134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF134u; }
        if (ctx->pc != 0x1AF134u) { return; }
    }
    ctx->pc = 0x1AF134u;
label_1af134:
    // 0x1af134: 0x8fa5002c  lw          $a1, 0x2C($sp)
    ctx->pc = 0x1af134u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1af138: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF138u;
    SET_GPR_U32(ctx, 31, 0x1AF140u);
    ctx->pc = 0x1AF13Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF138u;
            // 0x1af13c: 0x24040010  addiu       $a0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF140u; }
        if (ctx->pc != 0x1AF140u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF140u; }
        if (ctx->pc != 0x1AF140u) { return; }
    }
    ctx->pc = 0x1AF140u;
label_1af140:
    // 0x1af140: 0x8fa50028  lw          $a1, 0x28($sp)
    ctx->pc = 0x1af140u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1af144: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF144u;
    SET_GPR_U32(ctx, 31, 0x1AF14Cu);
    ctx->pc = 0x1AF148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF144u;
            // 0x1af148: 0x24040011  addiu       $a0, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF14Cu; }
        if (ctx->pc != 0x1AF14Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF14Cu; }
        if (ctx->pc != 0x1AF14Cu) { return; }
    }
    ctx->pc = 0x1AF14Cu;
label_1af14c:
    // 0x1af14c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1af14cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1af150: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF150u;
    SET_GPR_U32(ctx, 31, 0x1AF158u);
    ctx->pc = 0x1AF154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF150u;
            // 0x1af154: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF158u; }
        if (ctx->pc != 0x1AF158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF158u; }
        if (ctx->pc != 0x1AF158u) { return; }
    }
    ctx->pc = 0x1AF158u;
label_1af158:
    // 0x1af158: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1af158u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1af15c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF15Cu;
    SET_GPR_U32(ctx, 31, 0x1AF164u);
    ctx->pc = 0x1AF160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF15Cu;
            // 0x1af160: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF164u; }
        if (ctx->pc != 0x1AF164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF164u; }
        if (ctx->pc != 0x1AF164u) { return; }
    }
    ctx->pc = 0x1AF164u;
label_1af164:
    // 0x1af164: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1af164u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1af168: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF168u;
    SET_GPR_U32(ctx, 31, 0x1AF170u);
    ctx->pc = 0x1AF16Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF168u;
            // 0x1af16c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF170u; }
        if (ctx->pc != 0x1AF170u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF170u; }
        if (ctx->pc != 0x1AF170u) { return; }
    }
    ctx->pc = 0x1AF170u;
label_1af170:
    // 0x1af170: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1af170u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1af174: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF174u;
    SET_GPR_U32(ctx, 31, 0x1AF17Cu);
    ctx->pc = 0x1AF178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF174u;
            // 0x1af178: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF17Cu; }
        if (ctx->pc != 0x1AF17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF17Cu; }
        if (ctx->pc != 0x1AF17Cu) { return; }
    }
    ctx->pc = 0x1AF17Cu;
label_1af17c:
    // 0x1af17c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1af17cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af180: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF180u;
    SET_GPR_U32(ctx, 31, 0x1AF188u);
    ctx->pc = 0x1AF184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF180u;
            // 0x1af184: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF188u; }
        if (ctx->pc != 0x1AF188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF188u; }
        if (ctx->pc != 0x1AF188u) { return; }
    }
    ctx->pc = 0x1AF188u;
label_1af188:
    // 0x1af188: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af188u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af18c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1af18cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1af190: 0xa0204402  sb          $zero, 0x4402($at)
    ctx->pc = 0x1af190u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17410), (uint8_t)GPR_U32(ctx, 0));
    // 0x1af194: 0x2404005e  addiu       $a0, $zero, 0x5E
    ctx->pc = 0x1af194u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x1af198: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af198u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af19c: 0x24050032  addiu       $a1, $zero, 0x32
    ctx->pc = 0x1af19cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x1af1a0: 0xa0224400  sb          $v0, 0x4400($at)
    ctx->pc = 0x1af1a0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17408), (uint8_t)GPR_U32(ctx, 2));
    // 0x1af1a4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1af1a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1af1a8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af1a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af1ac: 0xa0224401  sb          $v0, 0x4401($at)
    ctx->pc = 0x1af1acu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17409), (uint8_t)GPR_U32(ctx, 2));
    // 0x1af1b0: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1af1b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1af1b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af1b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af1b8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF1B8u;
    SET_GPR_U32(ctx, 31, 0x1AF1C0u);
    ctx->pc = 0x1AF1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF1B8u;
            // 0x1af1bc: 0xa0224403  sb          $v0, 0x4403($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17411), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF1C0u; }
        if (ctx->pc != 0x1AF1C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF1C0u; }
        if (ctx->pc != 0x1AF1C0u) { return; }
    }
    ctx->pc = 0x1AF1C0u;
label_1af1c0:
    // 0x1af1c0: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x1af1c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1af1c4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF1C4u;
    SET_GPR_U32(ctx, 31, 0x1AF1CCu);
    ctx->pc = 0x1AF1C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF1C4u;
            // 0x1af1c8: 0x3c050001  lui         $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF1CCu; }
        if (ctx->pc != 0x1AF1CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF1CCu; }
        if (ctx->pc != 0x1AF1CCu) { return; }
    }
    ctx->pc = 0x1AF1CCu;
label_1af1cc:
    // 0x1af1cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1af1ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1af1d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1af1d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af1d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF1D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF1D4u;
            // 0x1af1d8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF0ECu: goto label_1af0ec;
            case 0x1AF100u: goto label_1af100;
            case 0x1AF10Cu: goto label_1af10c;
            case 0x1AF118u: goto label_1af118;
            case 0x1AF124u: goto label_1af124;
            case 0x1AF134u: goto label_1af134;
            case 0x1AF140u: goto label_1af140;
            case 0x1AF14Cu: goto label_1af14c;
            case 0x1AF158u: goto label_1af158;
            case 0x1AF164u: goto label_1af164;
            case 0x1AF170u: goto label_1af170;
            case 0x1AF17Cu: goto label_1af17c;
            case 0x1AF188u: goto label_1af188;
            case 0x1AF1C0u: goto label_1af1c0;
            case 0x1AF1CCu: goto label_1af1cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF1DCu;
    // 0x1af1dc: 0x0  nop
    ctx->pc = 0x1af1dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
