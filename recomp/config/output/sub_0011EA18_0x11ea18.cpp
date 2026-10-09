#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EA18
// Address: 0x11ea18 - 0x11eac8
void sub_0011EA18_0x11ea18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EA18_0x11ea18");
#endif

    switch (ctx->pc) {
        case 0x11ea88u: goto label_11ea88;
        case 0x11ea98u: goto label_11ea98;
        case 0x11eaa8u: goto label_11eaa8;
        default: break;
    }

    ctx->pc = 0x11ea18u;

label_11ea18:
    // 0x11ea18: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11ea18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11ea1c: 0x2443b3e8  addiu       $v1, $v0, -0x4C18
    ctx->pc = 0x11ea1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11ea20: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x11ea20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x11ea24: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11EA24u;
    {
        const bool branch_taken_0x11ea24 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11ea24) {
            ctx->pc = 0x11EA38u;
            goto label_11ea38;
        }
    }
    ctx->pc = 0x11EA2Cu;
    // 0x11ea2c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11ea2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11ea30: 0x3e00008  jr          $ra
    ctx->pc = 0x11EA30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EA30u;
            // 0x11ea34: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EA18u: goto label_11ea18;
            case 0x11EA38u: goto label_11ea38;
            case 0x11EA48u: goto label_11ea48;
            case 0x11EA60u: goto label_11ea60;
            case 0x11EA88u: goto label_11ea88;
            case 0x11EA98u: goto label_11ea98;
            case 0x11EAA8u: goto label_11eaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EA38u;
label_11ea38:
    // 0x11ea38: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EA38u;
    {
        const bool branch_taken_0x11ea38 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x11ea38) {
            ctx->pc = 0x11EA48u;
            goto label_11ea48;
        }
    }
    ctx->pc = 0x11EA40u;
    // 0x11ea40: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x11ea40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x11ea44: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x11ea44u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_11ea48:
    // 0x11ea48: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EA48u;
    {
        const bool branch_taken_0x11ea48 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x11ea48) {
            ctx->pc = 0x11EA60u;
            goto label_11ea60;
        }
    }
    ctx->pc = 0x11EA50u;
    // 0x11ea50: 0x8c630010  lw          $v1, 0x10($v1)
    ctx->pc = 0x11ea50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x11ea54: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x11ea54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x11ea58: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x11ea58u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x11ea5c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x11ea5cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_11ea60:
    // 0x11ea60: 0x3e00008  jr          $ra
    ctx->pc = 0x11EA60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EA64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EA60u;
            // 0x11ea64: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EA18u: goto label_11ea18;
            case 0x11EA38u: goto label_11ea38;
            case 0x11EA48u: goto label_11ea48;
            case 0x11EA60u: goto label_11ea60;
            case 0x11EA88u: goto label_11ea88;
            case 0x11EA98u: goto label_11ea98;
            case 0x11EAA8u: goto label_11eaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EA68u;
    // 0x11ea68: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11ea68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11ea6c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ea6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ea70: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11ea70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ea74: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11ea74u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ea78: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11ea78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11ea7c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11ea7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11ea80: 0xc047598  jal         func_11D660
    ctx->pc = 0x11EA80u;
    SET_GPR_U32(ctx, 31, 0x11EA88u);
    ctx->pc = 0x11EA84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EA80u;
            // 0x11ea84: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EA88u; }
        if (ctx->pc != 0x11EA88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EA88u; }
        if (ctx->pc != 0x11EA88u) { return; }
    }
    ctx->pc = 0x11EA88u;
label_11ea88:
    // 0x11ea88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11ea88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ea8c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11ea8cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ea90: 0xc047a86  jal         func_11EA18
    ctx->pc = 0x11EA90u;
    SET_GPR_U32(ctx, 31, 0x11EA98u);
    ctx->pc = 0x11EA94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EA90u;
            // 0x11ea94: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EA18u;
    goto label_11ea18;
    ctx->pc = 0x11EA98u;
label_11ea98:
    // 0x11ea98: 0x12400003  beqz        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EA98u;
    {
        const bool branch_taken_0x11ea98 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EA9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EA98u;
            // 0x11ea9c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ea98) {
            ctx->pc = 0x11EAA8u;
            goto label_11eaa8;
        }
    }
    ctx->pc = 0x11EAA0u;
    // 0x11eaa0: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11EAA0u;
    SET_GPR_U32(ctx, 31, 0x11EAA8u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EAA8u; }
        if (ctx->pc != 0x11EAA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EAA8u; }
        if (ctx->pc != 0x11EAA8u) { return; }
    }
    ctx->pc = 0x11EAA8u;
label_11eaa8:
    // 0x11eaa8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11eaa8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11eaac: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11eaacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11eab0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11eab0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11eab4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11eab4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11eab8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11eab8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11eabc: 0x3e00008  jr          $ra
    ctx->pc = 0x11EABCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EAC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EABCu;
            // 0x11eac0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EA18u: goto label_11ea18;
            case 0x11EA38u: goto label_11ea38;
            case 0x11EA48u: goto label_11ea48;
            case 0x11EA60u: goto label_11ea60;
            case 0x11EA88u: goto label_11ea88;
            case 0x11EA98u: goto label_11ea98;
            case 0x11EAA8u: goto label_11eaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EAC4u;
    // 0x11eac4: 0x0  nop
    ctx->pc = 0x11eac4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
