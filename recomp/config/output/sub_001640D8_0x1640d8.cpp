#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001640D8
// Address: 0x1640d8 - 0x164270
void sub_001640D8_0x1640d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001640D8_0x1640d8");
#endif

    switch (ctx->pc) {
        case 0x164114u: goto label_164114;
        case 0x164134u: goto label_164134;
        case 0x164144u: goto label_164144;
        case 0x16419cu: goto label_16419c;
        case 0x1641b8u: goto label_1641b8;
        case 0x1641ccu: goto label_1641cc;
        case 0x1641d4u: goto label_1641d4;
        case 0x1641e0u: goto label_1641e0;
        case 0x164200u: goto label_164200;
        case 0x16420cu: goto label_16420c;
        case 0x164214u: goto label_164214;
        case 0x164248u: goto label_164248;
        default: break;
    }

    ctx->pc = 0x1640d8u;

    // 0x1640d8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1640d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1640dc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1640dcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1640e0: 0x8c45de54  lw          $a1, -0x21AC($v0)
    ctx->pc = 0x1640e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958676)));
    // 0x1640e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1640e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1640e8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1640e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1640ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1640ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1640f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1640f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1640f4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1640f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1640f8: 0x14a30019  bne         $a1, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1640F8u;
    {
        const bool branch_taken_0x1640f8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x1640FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1640F8u;
            // 0x1640fc: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1640f8) {
            ctx->pc = 0x164160u;
            goto label_164160;
        }
    }
    ctx->pc = 0x164100u;
    // 0x164100: 0x16200007  bnez        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x164100u;
    {
        const bool branch_taken_0x164100 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x164100) {
            ctx->pc = 0x164120u;
            goto label_164120;
        }
    }
    ctx->pc = 0x164108u;
    // 0x164108: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x164108u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16410c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16410Cu;
    SET_GPR_U32(ctx, 31, 0x164114u);
    ctx->pc = 0x164110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16410Cu;
            // 0x164110: 0x24840548  addiu       $a0, $a0, 0x548 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164114u; }
        if (ctx->pc != 0x164114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164114u; }
        if (ctx->pc != 0x164114u) { return; }
    }
    ctx->pc = 0x164114u;
label_164114:
    // 0x164114: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x164114u;
    {
        const bool branch_taken_0x164114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x164118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164114u;
            // 0x164118: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164114) {
            ctx->pc = 0x164160u;
            goto label_164160;
        }
    }
    ctx->pc = 0x16411Cu;
    // 0x16411c: 0x0  nop
    ctx->pc = 0x16411cu;
    // NOP
label_164120:
    // 0x164120: 0x8e300004  lw          $s0, 0x4($s1)
    ctx->pc = 0x164120u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x164124: 0x1605000e  bne         $s0, $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x164124u;
    {
        const bool branch_taken_0x164124 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 5));
        ctx->pc = 0x164128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164124u;
            // 0x164128: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164124) {
            ctx->pc = 0x164160u;
            goto label_164160;
        }
    }
    ctx->pc = 0x16412Cu;
    // 0x16412c: 0xc0590b0  jal         func_1642C0
    ctx->pc = 0x16412Cu;
    SET_GPR_U32(ctx, 31, 0x164134u);
    ctx->pc = 0x1642C0u;
    if (runtime->hasFunction(0x1642C0u)) {
        auto targetFn = runtime->lookupFunction(0x1642C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164134u; }
        if (ctx->pc != 0x164134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642C0_0x1642c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164134u; }
        if (ctx->pc != 0x164134u) { return; }
    }
    ctx->pc = 0x164134u;
label_164134:
    // 0x164134: 0x5050000a  beql        $v0, $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x164134u;
    {
        const bool branch_taken_0x164134 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        if (branch_taken_0x164134) {
            ctx->pc = 0x164138u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164134u;
            // 0x164138: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164160u;
            goto label_164160;
        }
    }
    ctx->pc = 0x16413Cu;
    // 0x16413c: 0xc0590da  jal         func_164368
    ctx->pc = 0x16413Cu;
    SET_GPR_U32(ctx, 31, 0x164144u);
    ctx->pc = 0x164368u;
    if (runtime->hasFunction(0x164368u)) {
        auto targetFn = runtime->lookupFunction(0x164368u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164144u; }
        if (ctx->pc != 0x164144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164368_0x164368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164144u; }
        if (ctx->pc != 0x164144u) { return; }
    }
    ctx->pc = 0x164144u;
label_164144:
    // 0x164144: 0x1050fff3  beq         $v0, $s0, . + 4 + (-0xD << 2)
    ctx->pc = 0x164144u;
    {
        const bool branch_taken_0x164144 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x164148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164144u;
            // 0x164148: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164144) {
            ctx->pc = 0x164114u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_164114;
        }
    }
    ctx->pc = 0x16414Cu;
    // 0x16414c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16414cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164150: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x164150u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164154: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x164154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164158: 0x805905e  j           func_164178
    ctx->pc = 0x164158u;
    ctx->pc = 0x16415Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164158u;
            // 0x16415c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164178u;
    goto label_164178;
    ctx->pc = 0x164160u;
label_164160:
    // 0x164160: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x164160u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164164: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x164164u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164168: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x164168u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16416c: 0x3e00008  jr          $ra
    ctx->pc = 0x16416Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16416Cu;
            // 0x164170: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164114u: goto label_164114;
            case 0x164120u: goto label_164120;
            case 0x164134u: goto label_164134;
            case 0x164144u: goto label_164144;
            case 0x164160u: goto label_164160;
            case 0x164178u: goto label_164178;
            case 0x16419Cu: goto label_16419c;
            case 0x1641B8u: goto label_1641b8;
            case 0x1641C0u: goto label_1641c0;
            case 0x1641CCu: goto label_1641cc;
            case 0x1641D4u: goto label_1641d4;
            case 0x1641E0u: goto label_1641e0;
            case 0x1641F8u: goto label_1641f8;
            case 0x164200u: goto label_164200;
            case 0x164204u: goto label_164204;
            case 0x16420Cu: goto label_16420c;
            case 0x164214u: goto label_164214;
            case 0x16421Cu: goto label_16421c;
            case 0x164248u: goto label_164248;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164174u;
    // 0x164174: 0x0  nop
    ctx->pc = 0x164174u;
    // NOP
label_164178:
    // 0x164178: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x164178u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16417c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16417cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x164180: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x164180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164184: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x164184u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164188: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x164188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16418c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16418cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x164190: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x164190u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x164194: 0xc0590ae  jal         func_1642B8
    ctx->pc = 0x164194u;
    SET_GPR_U32(ctx, 31, 0x16419Cu);
    ctx->pc = 0x164198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164194u;
            // 0x164198: 0x8e120040  lw          $s2, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1642B8u;
    if (runtime->hasFunction(0x1642B8u)) {
        auto targetFn = runtime->lookupFunction(0x1642B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16419Cu; }
        if (ctx->pc != 0x16419Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642B8_0x1642b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16419Cu; }
        if (ctx->pc != 0x16419Cu) { return; }
    }
    ctx->pc = 0x16419Cu;
label_16419c:
    // 0x16419c: 0x8e110004  lw          $s1, 0x4($s0)
    ctx->pc = 0x16419cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1641a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1641a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1641a4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1641a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1641a8: 0x12220005  beq         $s1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1641A8u;
    {
        const bool branch_taken_0x1641a8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x1641ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1641A8u;
            // 0x1641ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1641a8) {
            ctx->pc = 0x1641C0u;
            goto label_1641c0;
        }
    }
    ctx->pc = 0x1641B0u;
    // 0x1641b0: 0xc0590ae  jal         func_1642B8
    ctx->pc = 0x1641B0u;
    SET_GPR_U32(ctx, 31, 0x1641B8u);
    ctx->pc = 0x1641B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1641B0u;
            // 0x1641b4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1642B8u;
    if (runtime->hasFunction(0x1642B8u)) {
        auto targetFn = runtime->lookupFunction(0x1642B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641B8u; }
        if (ctx->pc != 0x1641B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642B8_0x1642b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641B8u; }
        if (ctx->pc != 0x1641B8u) { return; }
    }
    ctx->pc = 0x1641B8u;
label_1641b8:
    // 0x1641b8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1641B8u;
    {
        const bool branch_taken_0x1641b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1641BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1641B8u;
            // 0x1641bc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1641b8) {
            ctx->pc = 0x16421Cu;
            goto label_16421c;
        }
    }
    ctx->pc = 0x1641C0u;
label_1641c0:
    // 0x1641c0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1641c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1641c4: 0xc0590b2  jal         func_1642C8
    ctx->pc = 0x1641C4u;
    SET_GPR_U32(ctx, 31, 0x1641CCu);
    ctx->pc = 0x1641C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1641C4u;
            // 0x1641c8: 0xac50ef60  sw          $s0, -0x10A0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963040), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1642C8u;
    if (runtime->hasFunction(0x1642C8u)) {
        auto targetFn = runtime->lookupFunction(0x1642C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641CCu; }
        if (ctx->pc != 0x1641CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642C8_0x1642c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641CCu; }
        if (ctx->pc != 0x1641CCu) { return; }
    }
    ctx->pc = 0x1641CCu;
label_1641cc:
    // 0x1641cc: 0xc05c94c  jal         func_172530
    ctx->pc = 0x1641CCu;
    SET_GPR_U32(ctx, 31, 0x1641D4u);
    ctx->pc = 0x1641D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1641CCu;
            // 0x1641d0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172530u;
    if (runtime->hasFunction(0x172530u)) {
        auto targetFn = runtime->lookupFunction(0x172530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641D4u; }
        if (ctx->pc != 0x1641D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172530_0x172530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641D4u; }
        if (ctx->pc != 0x1641D4u) { return; }
    }
    ctx->pc = 0x1641D4u;
label_1641d4:
    // 0x1641d4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1641d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1641d8: 0xc0590b2  jal         func_1642C8
    ctx->pc = 0x1641D8u;
    SET_GPR_U32(ctx, 31, 0x1641E0u);
    ctx->pc = 0x1641DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1641D8u;
            // 0x1641dc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1642C8u;
    if (runtime->hasFunction(0x1642C8u)) {
        auto targetFn = runtime->lookupFunction(0x1642C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641E0u; }
        if (ctx->pc != 0x1641E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642C8_0x1642c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1641E0u; }
        if (ctx->pc != 0x1641E0u) { return; }
    }
    ctx->pc = 0x1641E0u;
label_1641e0:
    // 0x1641e0: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1641e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1641e4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1641E4u;
    {
        const bool branch_taken_0x1641e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1641E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1641E4u;
            // 0x1641e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1641e4) {
            ctx->pc = 0x1641F8u;
            goto label_1641f8;
        }
    }
    ctx->pc = 0x1641ECu;
    // 0x1641ec: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1641ECu;
    {
        const bool branch_taken_0x1641ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1641F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1641ECu;
            // 0x1641f0: 0xae000068  sw          $zero, 0x68($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1641ec) {
            ctx->pc = 0x164204u;
            goto label_164204;
        }
    }
    ctx->pc = 0x1641F4u;
    // 0x1641f4: 0x0  nop
    ctx->pc = 0x1641f4u;
    // NOP
label_1641f8:
    // 0x1641f8: 0xc058f1e  jal         func_163C78
    ctx->pc = 0x1641F8u;
    SET_GPR_U32(ctx, 31, 0x164200u);
    ctx->pc = 0x1641FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1641F8u;
            // 0x1641fc: 0xae110068  sw          $s1, 0x68($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163C78u;
    if (runtime->hasFunction(0x163C78u)) {
        auto targetFn = runtime->lookupFunction(0x163C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164200u; }
        if (ctx->pc != 0x164200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163C78_0x163c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164200u; }
        if (ctx->pc != 0x164200u) { return; }
    }
    ctx->pc = 0x164200u;
label_164200:
    // 0x164200: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x164200u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_164204:
    // 0x164204: 0xc0590ae  jal         func_1642B8
    ctx->pc = 0x164204u;
    SET_GPR_U32(ctx, 31, 0x16420Cu);
    ctx->pc = 0x164208u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164204u;
            // 0x164208: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1642B8u;
    if (runtime->hasFunction(0x1642B8u)) {
        auto targetFn = runtime->lookupFunction(0x1642B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16420Cu; }
        if (ctx->pc != 0x16420Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642B8_0x1642b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16420Cu; }
        if (ctx->pc != 0x16420Cu) { return; }
    }
    ctx->pc = 0x16420Cu;
label_16420c:
    // 0x16420c: 0xc05c928  jal         func_1724A0
    ctx->pc = 0x16420Cu;
    SET_GPR_U32(ctx, 31, 0x164214u);
    ctx->pc = 0x164210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16420Cu;
            // 0x164210: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1724A0u;
    if (runtime->hasFunction(0x1724A0u)) {
        auto targetFn = runtime->lookupFunction(0x1724A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164214u; }
        if (ctx->pc != 0x164214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001724A0_0x1724a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164214u; }
        if (ctx->pc != 0x164214u) { return; }
    }
    ctx->pc = 0x164214u;
label_164214:
    // 0x164214: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x164214u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x164218: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x164218u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_16421c:
    // 0x16421c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16421cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164220: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x164220u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164224: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x164224u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164228: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x164228u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16422c: 0x3e00008  jr          $ra
    ctx->pc = 0x16422Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16422Cu;
            // 0x164230: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164114u: goto label_164114;
            case 0x164120u: goto label_164120;
            case 0x164134u: goto label_164134;
            case 0x164144u: goto label_164144;
            case 0x164160u: goto label_164160;
            case 0x164178u: goto label_164178;
            case 0x16419Cu: goto label_16419c;
            case 0x1641B8u: goto label_1641b8;
            case 0x1641C0u: goto label_1641c0;
            case 0x1641CCu: goto label_1641cc;
            case 0x1641D4u: goto label_1641d4;
            case 0x1641E0u: goto label_1641e0;
            case 0x1641F8u: goto label_1641f8;
            case 0x164200u: goto label_164200;
            case 0x164204u: goto label_164204;
            case 0x16420Cu: goto label_16420c;
            case 0x164214u: goto label_164214;
            case 0x16421Cu: goto label_16421c;
            case 0x164248u: goto label_164248;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164234u;
    // 0x164234: 0x0  nop
    ctx->pc = 0x164234u;
    // NOP
    // 0x164238: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164238u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16423c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16423cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164240: 0xc058fb8  jal         func_163EE0
    ctx->pc = 0x164240u;
    SET_GPR_U32(ctx, 31, 0x164248u);
    ctx->pc = 0x163EE0u;
    if (runtime->hasFunction(0x163EE0u)) {
        auto targetFn = runtime->lookupFunction(0x163EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164248u; }
        if (ctx->pc != 0x164248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163EE0_0x163ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164248u; }
        if (ctx->pc != 0x164248u) { return; }
    }
    ctx->pc = 0x164248u;
label_164248:
    // 0x164248: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16424c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16424cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164250: 0x3e00008  jr          $ra
    ctx->pc = 0x164250u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164250u;
            // 0x164254: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164114u: goto label_164114;
            case 0x164120u: goto label_164120;
            case 0x164134u: goto label_164134;
            case 0x164144u: goto label_164144;
            case 0x164160u: goto label_164160;
            case 0x164178u: goto label_164178;
            case 0x16419Cu: goto label_16419c;
            case 0x1641B8u: goto label_1641b8;
            case 0x1641C0u: goto label_1641c0;
            case 0x1641CCu: goto label_1641cc;
            case 0x1641D4u: goto label_1641d4;
            case 0x1641E0u: goto label_1641e0;
            case 0x1641F8u: goto label_1641f8;
            case 0x164200u: goto label_164200;
            case 0x164204u: goto label_164204;
            case 0x16420Cu: goto label_16420c;
            case 0x164214u: goto label_164214;
            case 0x16421Cu: goto label_16421c;
            case 0x164248u: goto label_164248;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164258u;
    // 0x164258: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164258u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16425c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x16425cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164260: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164264: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164264u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164268: 0x805900e  j           func_164038
    ctx->pc = 0x164268u;
    ctx->pc = 0x16426Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164268u;
            // 0x16426c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164038u;
    if (runtime->hasFunction(0x164038u)) {
        auto targetFn = runtime->lookupFunction(0x164038u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00164038_0x164038(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164270u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
