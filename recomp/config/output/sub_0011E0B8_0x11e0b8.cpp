#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E0B8
// Address: 0x11e0b8 - 0x11e170
void sub_0011E0B8_0x11e0b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E0B8_0x11e0b8");
#endif

    switch (ctx->pc) {
        case 0x11e10cu: goto label_11e10c;
        case 0x11e11cu: goto label_11e11c;
        case 0x11e12cu: goto label_11e12c;
        case 0x11e134u: goto label_11e134;
        case 0x11e13cu: goto label_11e13c;
        case 0x11e154u: goto label_11e154;
        default: break;
    }

    ctx->pc = 0x11e0b8u;

    // 0x11e0b8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11e0b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11e0bc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11e0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11e0c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11e0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e0c4: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x11e0c4u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x11e0c8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11e0c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11e0cc: 0x2650b3e8  addiu       $s0, $s2, -0x4C18
    ctx->pc = 0x11e0ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294947816));
    // 0x11e0d0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11e0d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11e0d4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x11e0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11e0d8: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E0D8u;
    {
        const bool branch_taken_0x11e0d8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11e0d8) {
            ctx->pc = 0x11E0ECu;
            goto label_11e0ec;
        }
    }
    ctx->pc = 0x11E0E0u;
    // 0x11e0e0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e0e4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x11E0E4u;
    {
        const bool branch_taken_0x11e0e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E0E4u;
            // 0x11e0e8: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e0e4) {
            ctx->pc = 0x11E158u;
            goto label_11e158;
        }
    }
    ctx->pc = 0x11E0ECu;
label_11e0ec:
    // 0x11e0ec: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x11e0ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11e0f0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E0F0u;
    {
        const bool branch_taken_0x11e0f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e0f0) {
            ctx->pc = 0x11E104u;
            goto label_11e104;
        }
    }
    ctx->pc = 0x11E0F8u;
    // 0x11e0f8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e0fc: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x11E0FCu;
    {
        const bool branch_taken_0x11e0fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E0FCu;
            // 0x11e100: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e0fc) {
            ctx->pc = 0x11E158u;
            goto label_11e158;
        }
    }
    ctx->pc = 0x11E104u;
label_11e104:
    // 0x11e104: 0xc047598  jal         func_11D660
    ctx->pc = 0x11E104u;
    SET_GPR_U32(ctx, 31, 0x11E10Cu);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E10Cu; }
        if (ctx->pc != 0x11E10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E10Cu; }
        if (ctx->pc != 0x11E10Cu) { return; }
    }
    ctx->pc = 0x11E10Cu;
label_11e10c:
    // 0x11e10c: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x11e10cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11e110: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11e110u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e114: 0xc0450c8  jal         func_114320
    ctx->pc = 0x11E114u;
    SET_GPR_U32(ctx, 31, 0x11E11Cu);
    ctx->pc = 0x11E118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E114u;
            // 0x11e118: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114320u;
    if (runtime->hasFunction(0x114320u)) {
        auto targetFn = runtime->lookupFunction(0x114320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E11Cu; }
        if (ctx->pc != 0x11E11Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E11Cu; }
        if (ctx->pc != 0x11E11Cu) { return; }
    }
    ctx->pc = 0x11E11Cu;
label_11e11c:
    // 0x11e11c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11E11Cu;
    {
        const bool branch_taken_0x11e11c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11E120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E11Cu;
            // 0x11e120: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e11c) {
            ctx->pc = 0x11E140u;
            goto label_11e140;
        }
    }
    ctx->pc = 0x11E124u;
    // 0x11e124: 0xc045440  jal         func_115100
    ctx->pc = 0x11E124u;
    SET_GPR_U32(ctx, 31, 0x11E12Cu);
    ctx->pc = 0x11E128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E124u;
            // 0x11e128: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115100u;
    if (runtime->hasFunction(0x115100u)) {
        auto targetFn = runtime->lookupFunction(0x115100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E12Cu; }
        if (ctx->pc != 0x11E12Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E12Cu; }
        if (ctx->pc != 0x11E12Cu) { return; }
    }
    ctx->pc = 0x11E12Cu;
label_11e12c:
    // 0x11e12c: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E12Cu;
    SET_GPR_U32(ctx, 31, 0x11E134u);
    ctx->pc = 0x11E130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E12Cu;
            // 0x11e130: 0x24040c00  addiu       $a0, $zero, 0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E134u; }
        if (ctx->pc != 0x11E134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E134u; }
        if (ctx->pc != 0x11E134u) { return; }
    }
    ctx->pc = 0x11E134u;
label_11e134:
    // 0x11e134: 0xc0477cc  jal         func_11DF30
    ctx->pc = 0x11E134u;
    SET_GPR_U32(ctx, 31, 0x11E13Cu);
    ctx->pc = 0x11E138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E134u;
            // 0x11e138: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF30u;
    if (runtime->hasFunction(0x11DF30u)) {
        auto targetFn = runtime->lookupFunction(0x11DF30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E13Cu; }
        if (ctx->pc != 0x11E13Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF30_0x11df30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E13Cu; }
        if (ctx->pc != 0x11E13Cu) { return; }
    }
    ctx->pc = 0x11E13Cu;
label_11e13c:
    // 0x11e13c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11e13cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_11e140:
    // 0x11e140: 0xfe40b3e8  sd          $zero, -0x4C18($s2)
    ctx->pc = 0x11e140u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 4294947816), GPR_U64(ctx, 0));
    // 0x11e144: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11E144u;
    {
        const bool branch_taken_0x11e144 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E144u;
            // 0x11e148: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e144) {
            ctx->pc = 0x11E154u;
            goto label_11e154;
        }
    }
    ctx->pc = 0x11E14Cu;
    // 0x11e14c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11E14Cu;
    SET_GPR_U32(ctx, 31, 0x11E154u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E154u; }
        if (ctx->pc != 0x11E154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E154u; }
        if (ctx->pc != 0x11E154u) { return; }
    }
    ctx->pc = 0x11E154u;
label_11e154:
    // 0x11e154: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11e154u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11e158:
    // 0x11e158: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11e158u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e15c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e15cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e160: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e160u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e164: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e164u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e168: 0x3e00008  jr          $ra
    ctx->pc = 0x11E168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E168u;
            // 0x11e16c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E0ECu: goto label_11e0ec;
            case 0x11E104u: goto label_11e104;
            case 0x11E10Cu: goto label_11e10c;
            case 0x11E11Cu: goto label_11e11c;
            case 0x11E12Cu: goto label_11e12c;
            case 0x11E134u: goto label_11e134;
            case 0x11E13Cu: goto label_11e13c;
            case 0x11E140u: goto label_11e140;
            case 0x11E154u: goto label_11e154;
            case 0x11E158u: goto label_11e158;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E170u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
