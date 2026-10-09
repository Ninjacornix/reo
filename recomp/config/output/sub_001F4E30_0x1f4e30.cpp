#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4E30
// Address: 0x1f4e30 - 0x1f4fa4
void sub_001F4E30_0x1f4e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4E30_0x1f4e30");
#endif

    switch (ctx->pc) {
        case 0x1f4e44u: goto label_1f4e44;
        case 0x1f4e5cu: goto label_1f4e5c;
        case 0x1f4e68u: goto label_1f4e68;
        case 0x1f4e7cu: goto label_1f4e7c;
        case 0x1f4e8cu: goto label_1f4e8c;
        case 0x1f4e9cu: goto label_1f4e9c;
        case 0x1f4ea8u: goto label_1f4ea8;
        case 0x1f4ebcu: goto label_1f4ebc;
        case 0x1f4eccu: goto label_1f4ecc;
        case 0x1f4edcu: goto label_1f4edc;
        case 0x1f4eecu: goto label_1f4eec;
        case 0x1f4efcu: goto label_1f4efc;
        case 0x1f4f38u: goto label_1f4f38;
        case 0x1f4f40u: goto label_1f4f40;
        default: break;
    }

    ctx->pc = 0x1f4e30u;

    // 0x1f4e30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f4e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f4e34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f4e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f4e38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f4e38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f4e3c: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F4E3Cu;
    SET_GPR_U32(ctx, 31, 0x1F4E44u);
    ctx->pc = 0x1F4E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E3Cu;
            // 0x1f4e40: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E44u; }
        if (ctx->pc != 0x1F4E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E44u; }
        if (ctx->pc != 0x1F4E44u) { return; }
    }
    ctx->pc = 0x1F4E44u;
label_1f4e44:
    // 0x1f4e44: 0xa6020040  sh          $v0, 0x40($s0)
    ctx->pc = 0x1f4e44u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 64), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f4e48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f4e48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4e4c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f4e4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4e50: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f4e50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f4e54: 0xc07d284  jal         func_1F4A10
    ctx->pc = 0x1F4E54u;
    SET_GPR_U32(ctx, 31, 0x1F4E5Cu);
    ctx->pc = 0x1F4E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E54u;
            // 0x1f4e58: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4A10u;
    if (runtime->hasFunction(0x1F4A10u)) {
        auto targetFn = runtime->lookupFunction(0x1F4A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E5Cu; }
        if (ctx->pc != 0x1F4E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4A10_0x1f4a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E5Cu; }
        if (ctx->pc != 0x1F4E5Cu) { return; }
    }
    ctx->pc = 0x1F4E5Cu;
label_1f4e5c:
    // 0x1f4e5c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4e5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4e60: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F4E60u;
    SET_GPR_U32(ctx, 31, 0x1F4E68u);
    ctx->pc = 0x1F4E64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E60u;
            // 0x1f4e64: 0x8c24eba0  lw          $a0, -0x1460($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962080)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E68u; }
        if (ctx->pc != 0x1F4E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E68u; }
        if (ctx->pc != 0x1F4E68u) { return; }
    }
    ctx->pc = 0x1F4E68u;
label_1f4e68:
    // 0x1f4e68: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4e68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4e6c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f4e6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4e70: 0x8c25eba0  lw          $a1, -0x1460($at)
    ctx->pc = 0x1f4e70u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962080)));
    // 0x1f4e74: 0xc07d330  jal         func_1F4CC0
    ctx->pc = 0x1F4E74u;
    SET_GPR_U32(ctx, 31, 0x1F4E7Cu);
    ctx->pc = 0x1F4E78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E74u;
            // 0x1f4e78: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4CC0u;
    if (runtime->hasFunction(0x1F4CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E7Cu; }
        if (ctx->pc != 0x1F4E7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4CC0_0x1f4cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E7Cu; }
        if (ctx->pc != 0x1F4E7Cu) { return; }
    }
    ctx->pc = 0x1F4E7Cu;
label_1f4e7c:
    // 0x1f4e7c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4e7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4e80: 0x9025eba4  lbu         $a1, -0x145C($at)
    ctx->pc = 0x1f4e80u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962084)));
    // 0x1f4e84: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F4E84u;
    SET_GPR_U32(ctx, 31, 0x1F4E8Cu);
    ctx->pc = 0x1F4E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E84u;
            // 0x1f4e88: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E8Cu; }
        if (ctx->pc != 0x1F4E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E8Cu; }
        if (ctx->pc != 0x1F4E8Cu) { return; }
    }
    ctx->pc = 0x1F4E8Cu;
label_1f4e8c:
    // 0x1f4e8c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4e8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4e90: 0x9025eba5  lbu         $a1, -0x145B($at)
    ctx->pc = 0x1f4e90u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962085)));
    // 0x1f4e94: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F4E94u;
    SET_GPR_U32(ctx, 31, 0x1F4E9Cu);
    ctx->pc = 0x1F4E98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E94u;
            // 0x1f4e98: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E9Cu; }
        if (ctx->pc != 0x1F4E9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E9Cu; }
        if (ctx->pc != 0x1F4E9Cu) { return; }
    }
    ctx->pc = 0x1F4E9Cu;
label_1f4e9c:
    // 0x1f4e9c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4e9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4ea0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F4EA0u;
    SET_GPR_U32(ctx, 31, 0x1F4EA8u);
    ctx->pc = 0x1F4EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4EA0u;
            // 0x1f4ea4: 0x8c24eba8  lw          $a0, -0x1458($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962088)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EA8u; }
        if (ctx->pc != 0x1F4EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EA8u; }
        if (ctx->pc != 0x1F4EA8u) { return; }
    }
    ctx->pc = 0x1F4EA8u;
label_1f4ea8:
    // 0x1f4ea8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4ea8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4eac: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f4eacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4eb0: 0x8c25eba8  lw          $a1, -0x1458($at)
    ctx->pc = 0x1f4eb0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962088)));
    // 0x1f4eb4: 0xc07d330  jal         func_1F4CC0
    ctx->pc = 0x1F4EB4u;
    SET_GPR_U32(ctx, 31, 0x1F4EBCu);
    ctx->pc = 0x1F4EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4EB4u;
            // 0x1f4eb8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4CC0u;
    if (runtime->hasFunction(0x1F4CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EBCu; }
        if (ctx->pc != 0x1F4EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4CC0_0x1f4cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EBCu; }
        if (ctx->pc != 0x1F4EBCu) { return; }
    }
    ctx->pc = 0x1F4EBCu;
label_1f4ebc:
    // 0x1f4ebc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4ebcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4ec0: 0x9025ebac  lbu         $a1, -0x1454($at)
    ctx->pc = 0x1f4ec0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962092)));
    // 0x1f4ec4: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F4EC4u;
    SET_GPR_U32(ctx, 31, 0x1F4ECCu);
    ctx->pc = 0x1F4EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4EC4u;
            // 0x1f4ec8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4ECCu; }
        if (ctx->pc != 0x1F4ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4ECCu; }
        if (ctx->pc != 0x1F4ECCu) { return; }
    }
    ctx->pc = 0x1F4ECCu;
label_1f4ecc:
    // 0x1f4ecc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4eccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4ed0: 0x9025ebad  lbu         $a1, -0x1453($at)
    ctx->pc = 0x1f4ed0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962093)));
    // 0x1f4ed4: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F4ED4u;
    SET_GPR_U32(ctx, 31, 0x1F4EDCu);
    ctx->pc = 0x1F4ED8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4ED4u;
            // 0x1f4ed8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EDCu; }
        if (ctx->pc != 0x1F4EDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EDCu; }
        if (ctx->pc != 0x1F4EDCu) { return; }
    }
    ctx->pc = 0x1F4EDCu;
label_1f4edc:
    // 0x1f4edc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4edcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4ee0: 0x9025ebae  lbu         $a1, -0x1452($at)
    ctx->pc = 0x1f4ee0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962094)));
    // 0x1f4ee4: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F4EE4u;
    SET_GPR_U32(ctx, 31, 0x1F4EECu);
    ctx->pc = 0x1F4EE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4EE4u;
            // 0x1f4ee8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EECu; }
        if (ctx->pc != 0x1F4EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EECu; }
        if (ctx->pc != 0x1F4EECu) { return; }
    }
    ctx->pc = 0x1F4EECu;
label_1f4eec:
    // 0x1f4eec: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4eecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4ef0: 0x9025ebaf  lbu         $a1, -0x1451($at)
    ctx->pc = 0x1f4ef0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962095)));
    // 0x1f4ef4: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F4EF4u;
    SET_GPR_U32(ctx, 31, 0x1F4EFCu);
    ctx->pc = 0x1F4EF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4EF4u;
            // 0x1f4ef8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EFCu; }
        if (ctx->pc != 0x1F4EFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4EFCu; }
        if (ctx->pc != 0x1F4EFCu) { return; }
    }
    ctx->pc = 0x1F4EFCu;
label_1f4efc:
    // 0x1f4efc: 0x9603002c  lhu         $v1, 0x2C($s0)
    ctx->pc = 0x1f4efcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f4f00: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1f4f00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f4f04: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1f4f04u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1f4f08: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x1f4f08u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1f4f0c: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f4f0cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f4f10: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1f4f10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1f4f14: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1f4f14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1f4f18: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f4f18u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f4f1c: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x1f4f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f4f20: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f4f20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f4f24: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1f4f24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f4f28: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f4f28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f4f2c: 0x2343c  dsll32      $a2, $v0, 16
    ctx->pc = 0x1f4f2cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f4f30: 0xc075aa4  jal         func_1D6A90
    ctx->pc = 0x1F4F30u;
    SET_GPR_U32(ctx, 31, 0x1F4F38u);
    ctx->pc = 0x1F4F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F30u;
            // 0x1f4f34: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A90u;
    if (runtime->hasFunction(0x1D6A90u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4F38u; }
        if (ctx->pc != 0x1F4F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A90_0x1d6a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4F38u; }
        if (ctx->pc != 0x1F4F38u) { return; }
    }
    ctx->pc = 0x1F4F38u;
label_1f4f38:
    // 0x1f4f38: 0xc07d16c  jal         func_1F45B0
    ctx->pc = 0x1F4F38u;
    SET_GPR_U32(ctx, 31, 0x1F4F40u);
    ctx->pc = 0x1F4F3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F38u;
            // 0x1f4f3c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45B0u;
    if (runtime->hasFunction(0x1F45B0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4F40u; }
        if (ctx->pc != 0x1F4F40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45B0_0x1f45b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4F40u; }
        if (ctx->pc != 0x1F4F40u) { return; }
    }
    ctx->pc = 0x1F4F40u;
label_1f4f40:
    // 0x1f4f40: 0x2841ffff  slti        $at, $v0, -0x1
    ctx->pc = 0x1f4f40u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1f4f44: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4F44u;
    {
        const bool branch_taken_0x1f4f44 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4F48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F44u;
            // 0x1f4f48: 0x3c010036  lui         $at, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4f44) {
            ctx->pc = 0x1F4F54u;
            goto label_1f4f54;
        }
    }
    ctx->pc = 0x1F4F4Cu;
    // 0x1f4f4c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1F4F4Cu;
    {
        const bool branch_taken_0x1f4f4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F4Cu;
            // 0x1f4f50: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4f4c) {
            ctx->pc = 0x1F4F98u;
            goto label_1f4f98;
        }
    }
    ctx->pc = 0x1F4F54u;
label_1f4f54:
    // 0x1f4f54: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1f4f54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f4f58: 0x8c23eaf0  lw          $v1, -0x1510($at)
    ctx->pc = 0x1f4f58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f4f5c: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F4F5Cu;
    {
        const bool branch_taken_0x1f4f5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F4F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F5Cu;
            // 0x1f4f60: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4f5c) {
            ctx->pc = 0x1F4F8Cu;
            goto label_1f4f8c;
        }
    }
    ctx->pc = 0x1F4F64u;
    // 0x1f4f64: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f4f64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f4f68: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F4F68u;
    {
        const bool branch_taken_0x1f4f68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1f4f68) {
            ctx->pc = 0x1F4F88u;
            goto label_1f4f88;
        }
    }
    ctx->pc = 0x1F4F70u;
    // 0x1f4f70: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4F70u;
    {
        const bool branch_taken_0x1f4f70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F70u;
            // 0x1f4f74: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4f70) {
            ctx->pc = 0x1F4F80u;
            goto label_1f4f80;
        }
    }
    ctx->pc = 0x1F4F78u;
    // 0x1f4f78: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F4F78u;
    {
        const bool branch_taken_0x1f4f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F78u;
            // 0x1f4f7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4f78) {
            ctx->pc = 0x1F4F94u;
            goto label_1f4f94;
        }
    }
    ctx->pc = 0x1F4F80u;
label_1f4f80:
    // 0x1f4f80: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4F80u;
    {
        const bool branch_taken_0x1f4f80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F80u;
            // 0x1f4f84: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4f80) {
            ctx->pc = 0x1F4F90u;
            goto label_1f4f90;
        }
    }
    ctx->pc = 0x1F4F88u;
label_1f4f88:
    // 0x1f4f88: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f4f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1f4f8c:
    // 0x1f4f8c: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f4f8cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f4f90:
    // 0x1f4f90: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f4f90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f4f94:
    // 0x1f4f94: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f4f94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f4f98:
    // 0x1f4f98: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4f98u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4f9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4F9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4F9Cu;
            // 0x1f4fa0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4E44u: goto label_1f4e44;
            case 0x1F4E5Cu: goto label_1f4e5c;
            case 0x1F4E68u: goto label_1f4e68;
            case 0x1F4E7Cu: goto label_1f4e7c;
            case 0x1F4E8Cu: goto label_1f4e8c;
            case 0x1F4E9Cu: goto label_1f4e9c;
            case 0x1F4EA8u: goto label_1f4ea8;
            case 0x1F4EBCu: goto label_1f4ebc;
            case 0x1F4ECCu: goto label_1f4ecc;
            case 0x1F4EDCu: goto label_1f4edc;
            case 0x1F4EECu: goto label_1f4eec;
            case 0x1F4EFCu: goto label_1f4efc;
            case 0x1F4F38u: goto label_1f4f38;
            case 0x1F4F40u: goto label_1f4f40;
            case 0x1F4F54u: goto label_1f4f54;
            case 0x1F4F80u: goto label_1f4f80;
            case 0x1F4F88u: goto label_1f4f88;
            case 0x1F4F8Cu: goto label_1f4f8c;
            case 0x1F4F90u: goto label_1f4f90;
            case 0x1F4F94u: goto label_1f4f94;
            case 0x1F4F98u: goto label_1f4f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4FA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
