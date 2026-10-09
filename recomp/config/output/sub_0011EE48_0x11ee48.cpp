#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EE48
// Address: 0x11ee48 - 0x11ef08
void sub_0011EE48_0x11ee48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EE48_0x11ee48");
#endif

    switch (ctx->pc) {
        case 0x11ee90u: goto label_11ee90;
        case 0x11eed0u: goto label_11eed0;
        case 0x11eedcu: goto label_11eedc;
        case 0x11eeecu: goto label_11eeec;
        default: break;
    }

    ctx->pc = 0x11ee48u;

label_11ee48:
    // 0x11ee48: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11ee48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11ee4c: 0x41282  srl         $v0, $a0, 10
    ctx->pc = 0x11ee4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 10));
    // 0x11ee50: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ee50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ee54: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ee54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11ee58: 0x28980  sll         $s1, $v0, 6
    ctx->pc = 0x11ee58u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x11ee5c: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EE5Cu;
    {
        const bool branch_taken_0x11ee5c = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11EE60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE5Cu;
            // 0x11ee60: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ee5c) {
            ctx->pc = 0x11EE74u;
            goto label_11ee74;
        }
    }
    ctx->pc = 0x11EE64u;
    // 0x11ee64: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x11ee64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x11ee68: 0x308203ff  andi        $v0, $a0, 0x3FF
    ctx->pc = 0x11ee68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1023);
    // 0x11ee6c: 0x50430003  beql        $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EE6Cu;
    {
        const bool branch_taken_0x11ee6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x11ee6c) {
            ctx->pc = 0x11EE70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE6Cu;
            // 0x11ee70: 0x8e22000c  lw          $v0, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11EE7Cu;
            goto label_11ee7c;
        }
    }
    ctx->pc = 0x11EE74u;
label_11ee74:
    // 0x11ee74: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x11EE74u;
    {
        const bool branch_taken_0x11ee74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EE78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE74u;
            // 0x11ee78: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ee74) {
            ctx->pc = 0x11EEA0u;
            goto label_11eea0;
        }
    }
    ctx->pc = 0x11EE7Cu;
label_11ee7c:
    // 0x11ee7c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11ee7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x11ee80: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11EE80u;
    {
        const bool branch_taken_0x11ee80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EE84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE80u;
            // 0x11ee84: 0xde300018  ld          $s0, 0x18($s1) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 17), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ee80) {
            ctx->pc = 0x11EE9Cu;
            goto label_11ee9c;
        }
    }
    ctx->pc = 0x11EE88u;
    // 0x11ee88: 0xc0479e8  jal         func_11E7A0
    ctx->pc = 0x11EE88u;
    SET_GPR_U32(ctx, 31, 0x11EE90u);
    ctx->pc = 0x11E7A0u;
    if (runtime->hasFunction(0x11E7A0u)) {
        auto targetFn = runtime->lookupFunction(0x11E7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE90u; }
        if (ctx->pc != 0x11EE90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E7A0_0x11e7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE90u; }
        if (ctx->pc != 0x11EE90u) { return; }
    }
    ctx->pc = 0x11EE90u;
label_11ee90:
    // 0x11ee90: 0xde230010  ld          $v1, 0x10($s1)
    ctx->pc = 0x11ee90u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x11ee94: 0x43102f  dsubu       $v0, $v0, $v1
    ctx->pc = 0x11ee94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x11ee98: 0x202802d  daddu       $s0, $s0, $v0
    ctx->pc = 0x11ee98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_11ee9c:
    // 0x11ee9c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ee9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_11eea0:
    // 0x11eea0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11eea0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11eea4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11eea4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11eea8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11eea8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11eeac: 0x3e00008  jr          $ra
    ctx->pc = 0x11EEACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EEB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EEACu;
            // 0x11eeb0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EE48u: goto label_11ee48;
            case 0x11EE74u: goto label_11ee74;
            case 0x11EE7Cu: goto label_11ee7c;
            case 0x11EE90u: goto label_11ee90;
            case 0x11EE9Cu: goto label_11ee9c;
            case 0x11EEA0u: goto label_11eea0;
            case 0x11EED0u: goto label_11eed0;
            case 0x11EEDCu: goto label_11eedc;
            case 0x11EEECu: goto label_11eeec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EEB4u;
    // 0x11eeb4: 0x0  nop
    ctx->pc = 0x11eeb4u;
    // NOP
    // 0x11eeb8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11eeb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11eebc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11eebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11eec0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11eec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11eec4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11eec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11eec8: 0xc047598  jal         func_11D660
    ctx->pc = 0x11EEC8u;
    SET_GPR_U32(ctx, 31, 0x11EED0u);
    ctx->pc = 0x11EECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EEC8u;
            // 0x11eecc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EED0u; }
        if (ctx->pc != 0x11EED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EED0u; }
        if (ctx->pc != 0x11EED0u) { return; }
    }
    ctx->pc = 0x11EED0u;
label_11eed0:
    // 0x11eed0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11eed0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11eed4: 0xc047b92  jal         func_11EE48
    ctx->pc = 0x11EED4u;
    SET_GPR_U32(ctx, 31, 0x11EEDCu);
    ctx->pc = 0x11EED8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EED4u;
            // 0x11eed8: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EE48u;
    goto label_11ee48;
    ctx->pc = 0x11EEDCu;
label_11eedc:
    // 0x11eedc: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EEDCu;
    {
        const bool branch_taken_0x11eedc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EEDCu;
            // 0x11eee0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eedc) {
            ctx->pc = 0x11EEECu;
            goto label_11eeec;
        }
    }
    ctx->pc = 0x11EEE4u;
    // 0x11eee4: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11EEE4u;
    SET_GPR_U32(ctx, 31, 0x11EEECu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EEECu; }
        if (ctx->pc != 0x11EEECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EEECu; }
        if (ctx->pc != 0x11EEECu) { return; }
    }
    ctx->pc = 0x11EEECu;
label_11eeec:
    // 0x11eeec: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11eeecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11eef0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11eef0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11eef4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11eef4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11eef8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11eef8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11eefc: 0x3e00008  jr          $ra
    ctx->pc = 0x11EEFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EEFCu;
            // 0x11ef00: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EE48u: goto label_11ee48;
            case 0x11EE74u: goto label_11ee74;
            case 0x11EE7Cu: goto label_11ee7c;
            case 0x11EE90u: goto label_11ee90;
            case 0x11EE9Cu: goto label_11ee9c;
            case 0x11EEA0u: goto label_11eea0;
            case 0x11EED0u: goto label_11eed0;
            case 0x11EEDCu: goto label_11eedc;
            case 0x11EEECu: goto label_11eeec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EF04u;
    // 0x11ef04: 0x0  nop
    ctx->pc = 0x11ef04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
