#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165FC8
// Address: 0x165fc8 - 0x166128
void sub_00165FC8_0x165fc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165FC8_0x165fc8");
#endif

    switch (ctx->pc) {
        case 0x165fecu: goto label_165fec;
        case 0x165ffcu: goto label_165ffc;
        case 0x1660b0u: goto label_1660b0;
        case 0x1660ecu: goto label_1660ec;
        case 0x1660f8u: goto label_1660f8;
        default: break;
    }

    ctx->pc = 0x165fc8u;

    // 0x165fc8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x165fc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x165fcc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x165fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x165fd0: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x165fd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165fd4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x165fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x165fd8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x165fd8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165fdc: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x165fdcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x165fe0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x165fe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x165fe4: 0xc05db7a  jal         func_176DE8
    ctx->pc = 0x165FE4u;
    SET_GPR_U32(ctx, 31, 0x165FECu);
    ctx->pc = 0x165FE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165FE4u;
            // 0x165fe8: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176DE8u;
    if (runtime->hasFunction(0x176DE8u)) {
        auto targetFn = runtime->lookupFunction(0x176DE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165FECu; }
        if (ctx->pc != 0x165FECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176DE8_0x176de8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165FECu; }
        if (ctx->pc != 0x165FECu) { return; }
    }
    ctx->pc = 0x165FECu;
label_165fec:
    // 0x165fec: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x165fecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165ff0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165ff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165ff4: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x165FF4u;
    SET_GPR_U32(ctx, 31, 0x165FFCu);
    ctx->pc = 0x165FF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165FF4u;
            // 0x165ff8: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165FFCu; }
        if (ctx->pc != 0x165FFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165FFCu; }
        if (ctx->pc != 0x165FFCu) { return; }
    }
    ctx->pc = 0x165FFCu;
label_165ffc:
    // 0x165ffc: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x165ffcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x166000: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x166000u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166004: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x166004u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x166008: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x166008u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16600c: 0x3e00008  jr          $ra
    ctx->pc = 0x16600Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16600Cu;
            // 0x166010: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165FECu: goto label_165fec;
            case 0x165FFCu: goto label_165ffc;
            case 0x1660B0u: goto label_1660b0;
            case 0x1660ECu: goto label_1660ec;
            case 0x1660F8u: goto label_1660f8;
            case 0x166110u: goto label_166110;
            case 0x166114u: goto label_166114;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166014u;
    // 0x166014: 0x0  nop
    ctx->pc = 0x166014u;
    // NOP
    // 0x166018: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16601c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16601cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166020: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166024: 0x34a50c03  ori         $a1, $a1, 0xC03
    ctx->pc = 0x166024u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3075);
    // 0x166028: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16602c: 0x805a704  j           func_169C10
    ctx->pc = 0x16602Cu;
    ctx->pc = 0x166030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16602Cu;
            // 0x166030: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166034u;
    // 0x166034: 0x0  nop
    ctx->pc = 0x166034u;
    // NOP
    // 0x166038: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166038u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16603c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16603cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166040: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166044: 0x34a50c03  ori         $a1, $a1, 0xC03
    ctx->pc = 0x166044u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3075);
    // 0x166048: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16604c: 0x805a704  j           func_169C10
    ctx->pc = 0x16604Cu;
    ctx->pc = 0x166050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16604Cu;
            // 0x166050: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166054u;
    // 0x166054: 0x0  nop
    ctx->pc = 0x166054u;
    // NOP
    // 0x166058: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166058u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16605c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16605cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166060: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166060u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166064: 0x34a50c03  ori         $a1, $a1, 0xC03
    ctx->pc = 0x166064u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3075);
    // 0x166068: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166068u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16606c: 0x805a704  j           func_169C10
    ctx->pc = 0x16606Cu;
    ctx->pc = 0x166070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16606Cu;
            // 0x166070: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166074u;
    // 0x166074: 0x0  nop
    ctx->pc = 0x166074u;
    // NOP
    // 0x166078: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16607c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16607cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166080: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166080u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166084: 0x34a50c03  ori         $a1, $a1, 0xC03
    ctx->pc = 0x166084u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3075);
    // 0x166088: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166088u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16608c: 0x805a704  j           func_169C10
    ctx->pc = 0x16608Cu;
    ctx->pc = 0x166090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16608Cu;
            // 0x166090: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166094u;
    // 0x166094: 0x0  nop
    ctx->pc = 0x166094u;
    // NOP
    // 0x166098: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166098u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16609c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16609cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1660a0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1660a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1660a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1660a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1660a8: 0xc05984a  jal         func_166128
    ctx->pc = 0x1660A8u;
    SET_GPR_U32(ctx, 31, 0x1660B0u);
    ctx->pc = 0x1660ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1660A8u;
            // 0x1660ac: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166128u;
    if (runtime->hasFunction(0x166128u)) {
        auto targetFn = runtime->lookupFunction(0x166128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660B0u; }
        if (ctx->pc != 0x1660B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166128_0x166128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660B0u; }
        if (ctx->pc != 0x1660B0u) { return; }
    }
    ctx->pc = 0x1660B0u;
label_1660b0:
    // 0x1660b0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1660b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1660b4: 0x50c00017  beql        $a2, $zero, . + 4 + (0x17 << 2)
    ctx->pc = 0x1660B4u;
    {
        const bool branch_taken_0x1660b4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1660b4) {
            ctx->pc = 0x1660B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1660B4u;
            // 0x1660b8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x166114u;
            goto label_166114;
        }
    }
    ctx->pc = 0x1660BCu;
    // 0x1660bc: 0x8e101b74  lw          $s0, 0x1B74($s0)
    ctx->pc = 0x1660bcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7028)));
    // 0x1660c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1660c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1660c4: 0x8e030034  lw          $v1, 0x34($s0)
    ctx->pc = 0x1660c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1660c8: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1660C8u;
    {
        const bool branch_taken_0x1660c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1660CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1660C8u;
            // 0x1660cc: 0x8e110000  lw          $s1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1660c8) {
            ctx->pc = 0x166110u;
            goto label_166110;
        }
    }
    ctx->pc = 0x1660D0u;
    // 0x1660d0: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1660d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1660d4: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1660D4u;
    {
        const bool branch_taken_0x1660d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1660D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1660D4u;
            // 0x1660d8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1660d4) {
            ctx->pc = 0x166110u;
            goto label_166110;
        }
    }
    ctx->pc = 0x1660DCu;
    // 0x1660dc: 0x8cc70014  lw          $a3, 0x14($a2)
    ctx->pc = 0x1660dcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x1660e0: 0x8cc5000c  lw          $a1, 0xC($a2)
    ctx->pc = 0x1660e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x1660e4: 0xc04a916  jal         func_12A458
    ctx->pc = 0x1660E4u;
    SET_GPR_U32(ctx, 31, 0x1660ECu);
    ctx->pc = 0x1660E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1660E4u;
            // 0x1660e8: 0x8cc60010  lw          $a2, 0x10($a2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A458u;
    if (runtime->hasFunction(0x12A458u)) {
        auto targetFn = runtime->lookupFunction(0x12A458u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660ECu; }
        if (ctx->pc != 0x1660ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A458_0x12a458(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660ECu; }
        if (ctx->pc != 0x1660ECu) { return; }
    }
    ctx->pc = 0x1660ECu;
label_1660ec:
    // 0x1660ec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1660ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1660f0: 0xc04cc50  jal         func_133140
    ctx->pc = 0x1660F0u;
    SET_GPR_U32(ctx, 31, 0x1660F8u);
    ctx->pc = 0x1660F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1660F0u;
            // 0x1660f4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133140u;
    if (runtime->hasFunction(0x133140u)) {
        auto targetFn = runtime->lookupFunction(0x133140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660F8u; }
        if (ctx->pc != 0x1660F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133140_0x133140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1660F8u; }
        if (ctx->pc != 0x1660F8u) { return; }
    }
    ctx->pc = 0x1660F8u;
label_1660f8:
    // 0x1660f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1660f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1660fc: 0x3c030016  lui         $v1, 0x16
    ctx->pc = 0x1660fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)22 << 16));
    // 0x166100: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x166100u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x166104: 0x246351c0  addiu       $v1, $v1, 0x51C0
    ctx->pc = 0x166104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20928));
    // 0x166108: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166108u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16610c: 0xae03003c  sw          $v1, 0x3C($s0)
    ctx->pc = 0x16610cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 3));
label_166110:
    // 0x166110: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166110u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_166114:
    // 0x166114: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166114u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166118: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166118u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16611c: 0x3e00008  jr          $ra
    ctx->pc = 0x16611Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16611Cu;
            // 0x166120: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165FECu: goto label_165fec;
            case 0x165FFCu: goto label_165ffc;
            case 0x1660B0u: goto label_1660b0;
            case 0x1660ECu: goto label_1660ec;
            case 0x1660F8u: goto label_1660f8;
            case 0x166110u: goto label_166110;
            case 0x166114u: goto label_166114;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166124u;
    // 0x166124: 0x0  nop
    ctx->pc = 0x166124u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
