#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D108
// Address: 0x15d108 - 0x15d1d0
void sub_0015D108_0x15d108(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D108_0x15d108");
#endif

    switch (ctx->pc) {
        case 0x15d130u: goto label_15d130;
        case 0x15d140u: goto label_15d140;
        case 0x15d15cu: goto label_15d15c;
        case 0x15d170u: goto label_15d170;
        case 0x15d188u: goto label_15d188;
        case 0x15d190u: goto label_15d190;
        default: break;
    }

    ctx->pc = 0x15d108u;

    // 0x15d108: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15d108u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15d10c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d10cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d110: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15d110u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d114: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15d114u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15d118: 0x2611000c  addiu       $s1, $s0, 0xC
    ctx->pc = 0x15d118u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x15d11c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15d11cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15d120: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15d120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15d124: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x15d124u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x15d128: 0xc0582d6  jal         func_160B58
    ctx->pc = 0x15D128u;
    SET_GPR_U32(ctx, 31, 0x15D130u);
    ctx->pc = 0x15D12Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D128u;
            // 0x15d12c: 0x8e25000c  lw          $a1, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B58u;
    if (runtime->hasFunction(0x160B58u)) {
        auto targetFn = runtime->lookupFunction(0x160B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D130u; }
        if (ctx->pc != 0x15D130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B58_0x160b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D130u; }
        if (ctx->pc != 0x15D130u) { return; }
    }
    ctx->pc = 0x15D130u;
label_15d130:
    // 0x15d130: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d130u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d134: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x15d134u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d138: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15D138u;
    SET_GPR_U32(ctx, 31, 0x15D140u);
    ctx->pc = 0x15D13Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D138u;
            // 0x15d13c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D140u; }
        if (ctx->pc != 0x15D140u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D140u; }
        if (ctx->pc != 0x15D140u) { return; }
    }
    ctx->pc = 0x15D140u;
label_15d140:
    // 0x15d140: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d140u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d144: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x15D144u;
    {
        const bool branch_taken_0x15d144 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D144u;
            // 0x15d148: 0x2484eb08  addiu       $a0, $a0, -0x14F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961928));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d144) {
            ctx->pc = 0x15D180u;
            goto label_15d180;
        }
    }
    ctx->pc = 0x15D14Cu;
    // 0x15d14c: 0xae0200ac  sw          $v0, 0xAC($s0)
    ctx->pc = 0x15d14cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 172), GPR_U32(ctx, 2));
    // 0x15d150: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15d150u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d154: 0xc058630  jal         func_1618C0
    ctx->pc = 0x15D154u;
    SET_GPR_U32(ctx, 31, 0x15D15Cu);
    ctx->pc = 0x15D158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D154u;
            // 0x15d158: 0xae1200b0  sw          $s2, 0xB0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 176), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1618C0u;
    if (runtime->hasFunction(0x1618C0u)) {
        auto targetFn = runtime->lookupFunction(0x1618C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D15Cu; }
        if (ctx->pc != 0x15D15Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001618C0_0x1618c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D15Cu; }
        if (ctx->pc != 0x15D15Cu) { return; }
    }
    ctx->pc = 0x15D15Cu;
label_15d15c:
    // 0x15d15c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15d15cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15d160: 0x14430011  bne         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x15D160u;
    {
        const bool branch_taken_0x15d160 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x15D164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D160u;
            // 0x15d164: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d160) {
            ctx->pc = 0x15D1A8u;
            goto label_15d1a8;
        }
    }
    ctx->pc = 0x15D168u;
    // 0x15d168: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15D168u;
    SET_GPR_U32(ctx, 31, 0x15D170u);
    ctx->pc = 0x15D16Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D168u;
            // 0x15d16c: 0x3c050002  lui         $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)2 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D170u; }
        if (ctx->pc != 0x15D170u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D170u; }
        if (ctx->pc != 0x15D170u) { return; }
    }
    ctx->pc = 0x15D170u;
label_15d170:
    // 0x15d170: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d170u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d174: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x15d174u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d178: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15D178u;
    {
        const bool branch_taken_0x15d178 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D17Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D178u;
            // 0x15d17c: 0x2484eb30  addiu       $a0, $a0, -0x14D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d178) {
            ctx->pc = 0x15D198u;
            goto label_15d198;
        }
    }
    ctx->pc = 0x15D180u;
label_15d180:
    // 0x15d180: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D180u;
    SET_GPR_U32(ctx, 31, 0x15D188u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D188u; }
        if (ctx->pc != 0x15D188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D188u; }
        if (ctx->pc != 0x15D188u) { return; }
    }
    ctx->pc = 0x15D188u;
label_15d188:
    // 0x15d188: 0xc0575d0  jal         func_15D740
    ctx->pc = 0x15D188u;
    SET_GPR_U32(ctx, 31, 0x15D190u);
    ctx->pc = 0x15D18Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D188u;
            // 0x15d18c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D740u;
    if (runtime->hasFunction(0x15D740u)) {
        auto targetFn = runtime->lookupFunction(0x15D740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D190u; }
        if (ctx->pc != 0x15D190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D740_0x15d740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D190u; }
        if (ctx->pc != 0x15D190u) { return; }
    }
    ctx->pc = 0x15D190u;
label_15d190:
    // 0x15d190: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x15D190u;
    {
        const bool branch_taken_0x15d190 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D190u;
            // 0x15d194: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d190) {
            ctx->pc = 0x15D1B4u;
            goto label_15d1b4;
        }
    }
    ctx->pc = 0x15D198u;
label_15d198:
    // 0x15d198: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x15d198u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x15d19c: 0xae0300ec  sw          $v1, 0xEC($s0)
    ctx->pc = 0x15d19cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 236), GPR_U32(ctx, 3));
    // 0x15d1a0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15D1A0u;
    {
        const bool branch_taken_0x15d1a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D1A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D1A0u;
            // 0x15d1a4: 0xae0200f0  sw          $v0, 0xF0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 240), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d1a0) {
            ctx->pc = 0x15D1B0u;
            goto label_15d1b0;
        }
    }
    ctx->pc = 0x15D1A8u;
label_15d1a8:
    // 0x15d1a8: 0xae0000f0  sw          $zero, 0xF0($s0)
    ctx->pc = 0x15d1a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 240), GPR_U32(ctx, 0));
    // 0x15d1ac: 0xae0000ec  sw          $zero, 0xEC($s0)
    ctx->pc = 0x15d1acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 236), GPR_U32(ctx, 0));
label_15d1b0:
    // 0x15d1b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15d1b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15d1b4:
    // 0x15d1b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d1b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d1b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15d1b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d1bc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15d1bcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d1c0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15d1c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15d1c4: 0x3e00008  jr          $ra
    ctx->pc = 0x15D1C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D1C4u;
            // 0x15d1c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D130u: goto label_15d130;
            case 0x15D140u: goto label_15d140;
            case 0x15D15Cu: goto label_15d15c;
            case 0x15D170u: goto label_15d170;
            case 0x15D180u: goto label_15d180;
            case 0x15D188u: goto label_15d188;
            case 0x15D190u: goto label_15d190;
            case 0x15D198u: goto label_15d198;
            case 0x15D1A8u: goto label_15d1a8;
            case 0x15D1B0u: goto label_15d1b0;
            case 0x15D1B4u: goto label_15d1b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D1CCu;
    // 0x15d1cc: 0x0  nop
    ctx->pc = 0x15d1ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
