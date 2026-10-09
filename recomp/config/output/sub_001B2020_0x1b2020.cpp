#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2020
// Address: 0x1b2020 - 0x1b20e0
void sub_001B2020_0x1b2020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2020_0x1b2020");
#endif

    switch (ctx->pc) {
        case 0x1b2050u: goto label_1b2050;
        case 0x1b2064u: goto label_1b2064;
        case 0x1b2080u: goto label_1b2080;
        case 0x1b209cu: goto label_1b209c;
        case 0x1b20b8u: goto label_1b20b8;
        default: break;
    }

    ctx->pc = 0x1b2020u;

    // 0x1b2020: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b2020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b2024: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2024u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2028: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b2028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b202c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b202cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b2030: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b2030u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b2034: 0x8023adf8  lb          $v1, -0x5208($at)
    ctx->pc = 0x1b2034u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946296)));
    // 0x1b2038: 0x10600023  beqz        $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1B2038u;
    {
        const bool branch_taken_0x1b2038 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B203Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2038u;
            // 0x1b203c: 0x3c010039  lui         $at, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2038) {
            ctx->pc = 0x1B20C8u;
            goto label_1b20c8;
        }
    }
    ctx->pc = 0x1B2040u;
    // 0x1b2040: 0x8c30edd4  lw          $s0, -0x122C($at)
    ctx->pc = 0x1b2040u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962644)));
    // 0x1b2044: 0x1200000b  beqz        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x1B2044u;
    {
        const bool branch_taken_0x1b2044 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2044) {
            ctx->pc = 0x1B2074u;
            goto label_1b2074;
        }
    }
    ctx->pc = 0x1B204Cu;
    // 0x1b204c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b204cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b2050:
    // 0x1b2050: 0x96021170  lhu         $v0, 0x1170($s0)
    ctx->pc = 0x1b2050u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4464)));
    // 0x1b2054: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B2054u;
    {
        const bool branch_taken_0x1b2054 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2054u;
            // 0x1b2058: 0x3044ffff  andi        $a0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2054) {
            ctx->pc = 0x1B2064u;
            goto label_1b2064;
        }
    }
    ctx->pc = 0x1B205Cu;
    // 0x1b205c: 0xc064968  jal         func_1925A0
    ctx->pc = 0x1B205Cu;
    SET_GPR_U32(ctx, 31, 0x1B2064u);
    ctx->pc = 0x1925A0u;
    if (runtime->hasFunction(0x1925A0u)) {
        auto targetFn = runtime->lookupFunction(0x1925A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2064u; }
        if (ctx->pc != 0x1B2064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001925A0_0x1925a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2064u; }
        if (ctx->pc != 0x1B2064u) { return; }
    }
    ctx->pc = 0x1B2064u;
label_1b2064:
    // 0x1b2064: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b2064u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b2068: 0x2a220010  slti        $v0, $s1, 0x10
    ctx->pc = 0x1b2068u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b206c: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B206Cu;
    {
        const bool branch_taken_0x1b206c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B206Cu;
            // 0x1b2070: 0x261011a0  addiu       $s0, $s0, 0x11A0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4512));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b206c) {
            ctx->pc = 0x1B2050u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2050;
        }
    }
    ctx->pc = 0x1B2074u;
label_1b2074:
    // 0x1b2074: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2074u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2078: 0xc06c6ec  jal         func_1B1BB0
    ctx->pc = 0x1B2078u;
    SET_GPR_U32(ctx, 31, 0x1B2080u);
    ctx->pc = 0x1B207Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2078u;
            // 0x1b207c: 0x2484c814  addiu       $a0, $a0, -0x37EC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952980));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BB0u;
    if (runtime->hasFunction(0x1B1BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2080u; }
        if (ctx->pc != 0x1B2080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BB0_0x1b1bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2080u; }
        if (ctx->pc != 0x1B2080u) { return; }
    }
    ctx->pc = 0x1B2080u;
label_1b2080:
    // 0x1b2080: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2080u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2084: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2084u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2088: 0xa020c810  sb          $zero, -0x37F0($at)
    ctx->pc = 0x1b2088u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952976), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b208c: 0x2484bb84  addiu       $a0, $a0, -0x447C
    ctx->pc = 0x1b208cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949764));
    // 0x1b2090: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2090u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2094: 0xc06c6ec  jal         func_1B1BB0
    ctx->pc = 0x1B2094u;
    SET_GPR_U32(ctx, 31, 0x1B209Cu);
    ctx->pc = 0x1B2098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2094u;
            // 0x1b2098: 0xa020c811  sb          $zero, -0x37EF($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294952977), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BB0u;
    if (runtime->hasFunction(0x1B1BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B209Cu; }
        if (ctx->pc != 0x1B209Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BB0_0x1b1bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B209Cu; }
        if (ctx->pc != 0x1B209Cu) { return; }
    }
    ctx->pc = 0x1B209Cu;
label_1b209c:
    // 0x1b209c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b209cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b20a0: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b20a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b20a4: 0xa020bb80  sb          $zero, -0x4480($at)
    ctx->pc = 0x1b20a4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294949760), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b20a8: 0x2484aef4  addiu       $a0, $a0, -0x510C
    ctx->pc = 0x1b20a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946548));
    // 0x1b20ac: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b20acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b20b0: 0xc06c6ec  jal         func_1B1BB0
    ctx->pc = 0x1B20B0u;
    SET_GPR_U32(ctx, 31, 0x1B20B8u);
    ctx->pc = 0x1B20B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B20B0u;
            // 0x1b20b4: 0xa020bb81  sb          $zero, -0x447F($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294949761), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BB0u;
    if (runtime->hasFunction(0x1B1BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B20B8u; }
        if (ctx->pc != 0x1B20B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BB0_0x1b1bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B20B8u; }
        if (ctx->pc != 0x1B20B8u) { return; }
    }
    ctx->pc = 0x1B20B8u;
label_1b20b8:
    // 0x1b20b8: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b20b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b20bc: 0xa020aef0  sb          $zero, -0x5110($at)
    ctx->pc = 0x1b20bcu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946544), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b20c0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b20c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b20c4: 0xa020aef1  sb          $zero, -0x510F($at)
    ctx->pc = 0x1b20c4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946545), (uint8_t)GPR_U32(ctx, 0));
label_1b20c8:
    // 0x1b20c8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b20c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b20cc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b20ccu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b20d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b20d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b20d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B20D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B20D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B20D4u;
            // 0x1b20d8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2050u: goto label_1b2050;
            case 0x1B2064u: goto label_1b2064;
            case 0x1B2074u: goto label_1b2074;
            case 0x1B2080u: goto label_1b2080;
            case 0x1B209Cu: goto label_1b209c;
            case 0x1B20B8u: goto label_1b20b8;
            case 0x1B20C8u: goto label_1b20c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B20DCu;
    // 0x1b20dc: 0x0  nop
    ctx->pc = 0x1b20dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
