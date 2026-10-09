#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E1A0
// Address: 0x11e1a0 - 0x11e2b0
void sub_0011E1A0_0x11e1a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E1A0_0x11e1a0");
#endif

    switch (ctx->pc) {
        case 0x11e1b4u: goto label_11e1b4;
        case 0x11e1e0u: goto label_11e1e0;
        case 0x11e1fcu: goto label_11e1fc;
        case 0x11e204u: goto label_11e204;
        case 0x11e20cu: goto label_11e20c;
        case 0x11e21cu: goto label_11e21c;
        case 0x11e244u: goto label_11e244;
        case 0x11e270u: goto label_11e270;
        case 0x11e288u: goto label_11e288;
        case 0x11e298u: goto label_11e298;
        default: break;
    }

    ctx->pc = 0x11e1a0u;

    // 0x11e1a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11e1a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11e1a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11e1a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e1a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11e1a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11e1ac: 0xc047598  jal         func_11D660
    ctx->pc = 0x11E1ACu;
    SET_GPR_U32(ctx, 31, 0x11E1B4u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E1B4u; }
        if (ctx->pc != 0x11E1B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E1B4u; }
        if (ctx->pc != 0x11E1B4u) { return; }
    }
    ctx->pc = 0x11E1B4u;
label_11e1b4:
    // 0x11e1b4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11e1b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e1b8: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11e1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11e1bc: 0x34421010  ori         $v0, $v0, 0x1010
    ctx->pc = 0x11e1bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4112);
    // 0x11e1c0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x11e1c0u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e1c4: 0x30430080  andi        $v1, $v0, 0x80
    ctx->pc = 0x11e1c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x11e1c8: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11E1C8u;
    {
        const bool branch_taken_0x11e1c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e1c8) {
            ctx->pc = 0x11E1E8u;
            goto label_11e1e8;
        }
    }
    ctx->pc = 0x11E1D0u;
    // 0x11e1d0: 0x12000013  beqz        $s0, . + 4 + (0x13 << 2)
    ctx->pc = 0x11E1D0u;
    {
        const bool branch_taken_0x11e1d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E1D0u;
            // 0x11e1d4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e1d0) {
            ctx->pc = 0x11E220u;
            goto label_11e220;
        }
    }
    ctx->pc = 0x11E1D8u;
    // 0x11e1d8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11E1D8u;
    SET_GPR_U32(ctx, 31, 0x11E1E0u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E1E0u; }
        if (ctx->pc != 0x11E1E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E1E0u; }
        if (ctx->pc != 0x11E1E0u) { return; }
    }
    ctx->pc = 0x11E1E0u;
label_11e1e0:
    // 0x11e1e0: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11E1E0u;
    {
        const bool branch_taken_0x11e1e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E1E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E1E0u;
            // 0x11e1e4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e1e0) {
            ctx->pc = 0x11E220u;
            goto label_11e220;
        }
    }
    ctx->pc = 0x11E1E8u;
label_11e1e8:
    // 0x11e1e8: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e1e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e1ec: 0x3484f3ff  ori         $a0, $a0, 0xF3FF
    ctx->pc = 0x11e1ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)62463);
    // 0x11e1f0: 0x442024  and         $a0, $v0, $a0
    ctx->pc = 0x11e1f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x11e1f4: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E1F4u;
    SET_GPR_U32(ctx, 31, 0x11E1FCu);
    ctx->pc = 0x11E1F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E1F4u;
            // 0x11e1f8: 0x34840080  ori         $a0, $a0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E1FCu; }
        if (ctx->pc != 0x11E1FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E1FCu; }
        if (ctx->pc != 0x11E1FCu) { return; }
    }
    ctx->pc = 0x11E1FCu;
label_11e1fc:
    // 0x11e1fc: 0xc0479e8  jal         func_11E7A0
    ctx->pc = 0x11E1FCu;
    SET_GPR_U32(ctx, 31, 0x11E204u);
    ctx->pc = 0x11E7A0u;
    if (runtime->hasFunction(0x11E7A0u)) {
        auto targetFn = runtime->lookupFunction(0x11E7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E204u; }
        if (ctx->pc != 0x11E204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E7A0_0x11e7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E204u; }
        if (ctx->pc != 0x11E204u) { return; }
    }
    ctx->pc = 0x11E204u;
label_11e204:
    // 0x11e204: 0xc0478ac  jal         func_11E2B0
    ctx->pc = 0x11E204u;
    SET_GPR_U32(ctx, 31, 0x11E20Cu);
    ctx->pc = 0x11E208u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E204u;
            // 0x11e208: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E2B0u;
    if (runtime->hasFunction(0x11E2B0u)) {
        auto targetFn = runtime->lookupFunction(0x11E2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E20Cu; }
        if (ctx->pc != 0x11E20Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E2B0_0x11e2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E20Cu; }
        if (ctx->pc != 0x11E20Cu) { return; }
    }
    ctx->pc = 0x11E20Cu;
label_11e20c:
    // 0x11e20c: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E20Cu;
    {
        const bool branch_taken_0x11e20c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E20Cu;
            // 0x11e210: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e20c) {
            ctx->pc = 0x11E220u;
            goto label_11e220;
        }
    }
    ctx->pc = 0x11E214u;
    // 0x11e214: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11E214u;
    SET_GPR_U32(ctx, 31, 0x11E21Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E21Cu; }
        if (ctx->pc != 0x11E21Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E21Cu; }
        if (ctx->pc != 0x11E21Cu) { return; }
    }
    ctx->pc = 0x11E21Cu;
label_11e21c:
    // 0x11e21c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11e21cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11e220:
    // 0x11e220: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11e220u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e224: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e224u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e228: 0x3e00008  jr          $ra
    ctx->pc = 0x11E228u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E22Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E228u;
            // 0x11e22c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E1B4u: goto label_11e1b4;
            case 0x11E1E0u: goto label_11e1e0;
            case 0x11E1E8u: goto label_11e1e8;
            case 0x11E1FCu: goto label_11e1fc;
            case 0x11E204u: goto label_11e204;
            case 0x11E20Cu: goto label_11e20c;
            case 0x11E21Cu: goto label_11e21c;
            case 0x11E220u: goto label_11e220;
            case 0x11E244u: goto label_11e244;
            case 0x11E270u: goto label_11e270;
            case 0x11E278u: goto label_11e278;
            case 0x11E288u: goto label_11e288;
            case 0x11E298u: goto label_11e298;
            case 0x11E29Cu: goto label_11e29c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E230u;
    // 0x11e230: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11e230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11e234: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11e234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e238: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11e238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11e23c: 0xc047598  jal         func_11D660
    ctx->pc = 0x11E23Cu;
    SET_GPR_U32(ctx, 31, 0x11E244u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E244u; }
        if (ctx->pc != 0x11E244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E244u; }
        if (ctx->pc != 0x11E244u) { return; }
    }
    ctx->pc = 0x11E244u;
label_11e244:
    // 0x11e244: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11e244u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e248: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11e248u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11e24c: 0x34421010  ori         $v0, $v0, 0x1010
    ctx->pc = 0x11e24cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4112);
    // 0x11e250: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x11e250u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e254: 0x30430080  andi        $v1, $v0, 0x80
    ctx->pc = 0x11e254u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x11e258: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11E258u;
    {
        const bool branch_taken_0x11e258 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11e258) {
            ctx->pc = 0x11E278u;
            goto label_11e278;
        }
    }
    ctx->pc = 0x11E260u;
    // 0x11e260: 0x1200000e  beqz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x11E260u;
    {
        const bool branch_taken_0x11e260 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E260u;
            // 0x11e264: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e260) {
            ctx->pc = 0x11E29Cu;
            goto label_11e29c;
        }
    }
    ctx->pc = 0x11E268u;
    // 0x11e268: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11E268u;
    SET_GPR_U32(ctx, 31, 0x11E270u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E270u; }
        if (ctx->pc != 0x11E270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E270u; }
        if (ctx->pc != 0x11E270u) { return; }
    }
    ctx->pc = 0x11E270u;
label_11e270:
    // 0x11e270: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x11E270u;
    {
        const bool branch_taken_0x11e270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E270u;
            // 0x11e274: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e270) {
            ctx->pc = 0x11E29Cu;
            goto label_11e29c;
        }
    }
    ctx->pc = 0x11E278u;
label_11e278:
    // 0x11e278: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e278u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e27c: 0x3484f37f  ori         $a0, $a0, 0xF37F
    ctx->pc = 0x11e27cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)62335);
    // 0x11e280: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E280u;
    SET_GPR_U32(ctx, 31, 0x11E288u);
    ctx->pc = 0x11E284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E280u;
            // 0x11e284: 0x442024  and         $a0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E288u; }
        if (ctx->pc != 0x11E288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E288u; }
        if (ctx->pc != 0x11E288u) { return; }
    }
    ctx->pc = 0x11E288u;
label_11e288:
    // 0x11e288: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E288u;
    {
        const bool branch_taken_0x11e288 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E28Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E288u;
            // 0x11e28c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e288) {
            ctx->pc = 0x11E29Cu;
            goto label_11e29c;
        }
    }
    ctx->pc = 0x11E290u;
    // 0x11e290: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11E290u;
    SET_GPR_U32(ctx, 31, 0x11E298u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E298u; }
        if (ctx->pc != 0x11E298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E298u; }
        if (ctx->pc != 0x11E298u) { return; }
    }
    ctx->pc = 0x11E298u;
label_11e298:
    // 0x11e298: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11e298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11e29c:
    // 0x11e29c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11e29cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e2a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e2a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e2a4: 0x3e00008  jr          $ra
    ctx->pc = 0x11E2A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E2A4u;
            // 0x11e2a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E1B4u: goto label_11e1b4;
            case 0x11E1E0u: goto label_11e1e0;
            case 0x11E1E8u: goto label_11e1e8;
            case 0x11E1FCu: goto label_11e1fc;
            case 0x11E204u: goto label_11e204;
            case 0x11E20Cu: goto label_11e20c;
            case 0x11E21Cu: goto label_11e21c;
            case 0x11E220u: goto label_11e220;
            case 0x11E244u: goto label_11e244;
            case 0x11E270u: goto label_11e270;
            case 0x11E278u: goto label_11e278;
            case 0x11E288u: goto label_11e288;
            case 0x11E298u: goto label_11e298;
            case 0x11E29Cu: goto label_11e29c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E2ACu;
    // 0x11e2ac: 0x0  nop
    ctx->pc = 0x11e2acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
