#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112038
// Address: 0x112038 - 0x112178
void sub_00112038_0x112038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112038_0x112038");
#endif

    switch (ctx->pc) {
        case 0x112058u: goto label_112058;
        case 0x112068u: goto label_112068;
        case 0x112130u: goto label_112130;
        case 0x112168u: goto label_112168;
        default: break;
    }

    ctx->pc = 0x112038u;

    // 0x112038: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x112038u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x11203c: 0xffa40040  sd          $a0, 0x40($sp)
    ctx->pc = 0x11203cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 4));
    // 0x112040: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x112040u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x112044: 0xffa50048  sd          $a1, 0x48($sp)
    ctx->pc = 0x112044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 5));
    // 0x112048: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x112048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x11204c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x11204cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x112050: 0xc044674  jal         func_1119D0
    ctx->pc = 0x112050u;
    SET_GPR_U32(ctx, 31, 0x112058u);
    ctx->pc = 0x112054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112050u;
            // 0x112054: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112058u; }
        if (ctx->pc != 0x112058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112058u; }
        if (ctx->pc != 0x112058u) { return; }
    }
    ctx->pc = 0x112058u;
label_112058:
    // 0x112058: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x112058u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x11205c: 0x27a40048  addiu       $a0, $sp, 0x48
    ctx->pc = 0x11205cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x112060: 0xc044674  jal         func_1119D0
    ctx->pc = 0x112060u;
    SET_GPR_U32(ctx, 31, 0x112068u);
    ctx->pc = 0x112064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112060u;
            // 0x112064: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112068u; }
        if (ctx->pc != 0x112068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112068u; }
        if (ctx->pc != 0x112068u) { return; }
    }
    ctx->pc = 0x112068u;
label_112068:
    // 0x112068: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x112068u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11206c: 0x3a0402d  daddu       $t0, $sp, $zero
    ctx->pc = 0x11206cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112070: 0x2cc20002  sltiu       $v0, $a2, 0x2
    ctx->pc = 0x112070u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x112074: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x112074u;
    {
        const bool branch_taken_0x112074 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x112078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112074u;
            // 0x112078: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112074) {
            ctx->pc = 0x112160u;
            goto label_112160;
        }
    }
    ctx->pc = 0x11207Cu;
    // 0x11207c: 0x8fa50020  lw          $a1, 0x20($sp)
    ctx->pc = 0x11207cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x112080: 0x2ca20002  sltiu       $v0, $a1, 0x2
    ctx->pc = 0x112080u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x112084: 0x14400036  bnez        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x112084u;
    {
        const bool branch_taken_0x112084 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x112088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112084u;
            // 0x112088: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112084) {
            ctx->pc = 0x112160u;
            goto label_112160;
        }
    }
    ctx->pc = 0x11208Cu;
    // 0x11208c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x11208cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x112090: 0x38c40004  xori        $a0, $a2, 0x4
    ctx->pc = 0x112090u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) ^ (uint64_t)(uint16_t)4);
    // 0x112094: 0x8fa30024  lw          $v1, 0x24($sp)
    ctx->pc = 0x112094u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x112098: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x112098u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x11209c: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11209Cu;
    {
        const bool branch_taken_0x11209c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1120A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11209Cu;
            // 0x1120a0: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11209c) {
            ctx->pc = 0x1120B0u;
            goto label_1120b0;
        }
    }
    ctx->pc = 0x1120A4u;
    // 0x1120a4: 0x38c20002  xori        $v0, $a2, 0x2
    ctx->pc = 0x1120a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ (uint64_t)(uint16_t)2);
    // 0x1120a8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1120A8u;
    {
        const bool branch_taken_0x1120a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1120ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1120A8u;
            // 0x1120ac: 0x38a20004  xori        $v0, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1120a8) {
            ctx->pc = 0x1120C8u;
            goto label_1120c8;
        }
    }
    ctx->pc = 0x1120B0u;
label_1120b0:
    // 0x1120b0: 0x54c5002b  bnel        $a2, $a1, . + 4 + (0x2B << 2)
    ctx->pc = 0x1120B0u;
    {
        const bool branch_taken_0x1120b0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 5));
        if (branch_taken_0x1120b0) {
            ctx->pc = 0x1120B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1120B0u;
            // 0x1120b4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x112160u;
            goto label_112160;
        }
    }
    ctx->pc = 0x1120B8u;
    // 0x1120b8: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1120b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1120bc: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1120BCu;
    {
        const bool branch_taken_0x1120bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1120C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1120BCu;
            // 0x1120c0: 0x244485a0  addiu       $a0, $v0, -0x7A60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1120bc) {
            ctx->pc = 0x112160u;
            goto label_112160;
        }
    }
    ctx->pc = 0x1120C4u;
    // 0x1120c4: 0x0  nop
    ctx->pc = 0x1120c4u;
    // NOP
label_1120c8:
    // 0x1120c8: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1120C8u;
    {
        const bool branch_taken_0x1120c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1120c8) {
            ctx->pc = 0x1120CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1120C8u;
            // 0x1120cc: 0x38a20002  xori        $v0, $a1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1120E0u;
            goto label_1120e0;
        }
    }
    ctx->pc = 0x1120D0u;
    // 0x1120d0: 0xffa00010  sd          $zero, 0x10($sp)
    ctx->pc = 0x1120d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 0));
    // 0x1120d4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1120d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1120d8: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1120D8u;
    {
        const bool branch_taken_0x1120d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1120DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1120D8u;
            // 0x1120dc: 0xafa00008  sw          $zero, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1120d8) {
            ctx->pc = 0x112160u;
            goto label_112160;
        }
    }
    ctx->pc = 0x1120E0u;
label_1120e0:
    // 0x1120e0: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1120E0u;
    {
        const bool branch_taken_0x1120e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1120e0) {
            ctx->pc = 0x1120E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1120E0u;
            // 0x1120e4: 0x8fa30008  lw          $v1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1120F8u;
            goto label_1120f8;
        }
    }
    ctx->pc = 0x1120E8u;
    // 0x1120e8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1120e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1120ec: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1120ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1120f0: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1120F0u;
    {
        const bool branch_taken_0x1120f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1120F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1120F0u;
            // 0x1120f4: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1120f0) {
            ctx->pc = 0x112160u;
            goto label_112160;
        }
    }
    ctx->pc = 0x1120F8u;
label_1120f8:
    // 0x1120f8: 0x8fa20028  lw          $v0, 0x28($sp)
    ctx->pc = 0x1120f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1120fc: 0xdfa40010  ld          $a0, 0x10($sp)
    ctx->pc = 0x1120fcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112100: 0xdfa60030  ld          $a2, 0x30($sp)
    ctx->pc = 0x112100u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x112104: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x112104u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x112108: 0x86282b  sltu        $a1, $a0, $a2
    ctx->pc = 0x112108u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x11210c: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x11210Cu;
    {
        const bool branch_taken_0x11210c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x112110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11210Cu;
            // 0x112110: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11210c) {
            ctx->pc = 0x112124u;
            goto label_112124;
        }
    }
    ctx->pc = 0x112114u;
    // 0x112114: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x112114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x112118: 0x42078  dsll        $a0, $a0, 1
    ctx->pc = 0x112118u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 1);
    // 0x11211c: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x11211cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x112120: 0x86282b  sltu        $a1, $a0, $a2
    ctx->pc = 0x112120u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
label_112124:
    // 0x112124: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x112124u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x112128: 0x31b7c  dsll32      $v1, $v1, 13
    ctx->pc = 0x112128u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 13));
    // 0x11212c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11212cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_112130:
    // 0x112130: 0x14a00005  bnez        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x112130u;
    {
        const bool branch_taken_0x112130 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x112134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112130u;
            // 0x112134: 0x41078  dsll        $v0, $a0, 1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << 1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x112130) {
            ctx->pc = 0x112148u;
            goto label_112148;
        }
    }
    ctx->pc = 0x112138u;
    // 0x112138: 0x86202f  dsubu       $a0, $a0, $a2
    ctx->pc = 0x112138u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) - GPR_U64(ctx, 6));
    // 0x11213c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x11213cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x112140: 0x41078  dsll        $v0, $a0, 1
    ctx->pc = 0x112140u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << 1);
    // 0x112144: 0x0  nop
    ctx->pc = 0x112144u;
    // NOP
label_112148:
    // 0x112148: 0x3187a  dsrl        $v1, $v1, 1
    ctx->pc = 0x112148u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> 1);
    // 0x11214c: 0x46282b  sltu        $a1, $v0, $a2
    ctx->pc = 0x11214cu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x112150: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x112150u;
    {
        const bool branch_taken_0x112150 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x112154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112150u;
            // 0x112154: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112150) {
            ctx->pc = 0x112130u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_112130;
        }
    }
    ctx->pc = 0x112158u;
    // 0x112158: 0xfd070010  sd          $a3, 0x10($t0)
    ctx->pc = 0x112158u;
    WRITE64(ADD32(GPR_U32(ctx, 8), 16), GPR_U64(ctx, 7));
    // 0x11215c: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x11215cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_112160:
    // 0x112160: 0xc04463e  jal         func_1118F8
    ctx->pc = 0x112160u;
    SET_GPR_U32(ctx, 31, 0x112168u);
    ctx->pc = 0x1118F8u;
    if (runtime->hasFunction(0x1118F8u)) {
        auto targetFn = runtime->lookupFunction(0x1118F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112168u; }
        if (ctx->pc != 0x112168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118F8_0x1118f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112168u; }
        if (ctx->pc != 0x112168u) { return; }
    }
    ctx->pc = 0x112168u;
label_112168:
    // 0x112168: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x112168u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11216c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x11216cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x112170: 0x3e00008  jr          $ra
    ctx->pc = 0x112170u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112170u;
            // 0x112174: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112058u: goto label_112058;
            case 0x112068u: goto label_112068;
            case 0x1120B0u: goto label_1120b0;
            case 0x1120C8u: goto label_1120c8;
            case 0x1120E0u: goto label_1120e0;
            case 0x1120F8u: goto label_1120f8;
            case 0x112124u: goto label_112124;
            case 0x112130u: goto label_112130;
            case 0x112148u: goto label_112148;
            case 0x112160u: goto label_112160;
            case 0x112168u: goto label_112168;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112178u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
