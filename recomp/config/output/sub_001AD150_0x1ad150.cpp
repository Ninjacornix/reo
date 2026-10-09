#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD150
// Address: 0x1ad150 - 0x1ad220
void sub_001AD150_0x1ad150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD150_0x1ad150");
#endif

    switch (ctx->pc) {
        case 0x1ad180u: goto label_1ad180;
        case 0x1ad190u: goto label_1ad190;
        case 0x1ad1a8u: goto label_1ad1a8;
        case 0x1ad1b0u: goto label_1ad1b0;
        case 0x1ad1b8u: goto label_1ad1b8;
        case 0x1ad1c4u: goto label_1ad1c4;
        case 0x1ad1d4u: goto label_1ad1d4;
        case 0x1ad1dcu: goto label_1ad1dc;
        case 0x1ad1ecu: goto label_1ad1ec;
        case 0x1ad1fcu: goto label_1ad1fc;
        default: break;
    }

    ctx->pc = 0x1ad150u;

    // 0x1ad150: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1ad150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1ad154: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ad154u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ad158: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1ad158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1ad15c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ad15cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ad160: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ad160u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ad164: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1ad164u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad168: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ad168u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ad16c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1ad16cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad170: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1ad170u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad174: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1ad174u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ad178: 0xc06a030  jal         func_1A80C0
    ctx->pc = 0x1AD178u;
    SET_GPR_U32(ctx, 31, 0x1AD180u);
    ctx->pc = 0x1AD17Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD178u;
            // 0x1ad17c: 0x3444000c  ori         $a0, $v0, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A80C0u;
    if (runtime->hasFunction(0x1A80C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A80C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD180u; }
        if (ctx->pc != 0x1AD180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A80C0_0x1a80c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD180u; }
        if (ctx->pc != 0x1AD180u) { return; }
    }
    ctx->pc = 0x1AD180u;
label_1ad180:
    // 0x1ad180: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1ad180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad184: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1ad184u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad188: 0xc06b488  jal         func_1AD220
    ctx->pc = 0x1AD188u;
    SET_GPR_U32(ctx, 31, 0x1AD190u);
    ctx->pc = 0x1AD18Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD188u;
            // 0x1ad18c: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD220u;
    if (runtime->hasFunction(0x1AD220u)) {
        auto targetFn = runtime->lookupFunction(0x1AD220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD190u; }
        if (ctx->pc != 0x1AD190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD220_0x1ad220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD190u; }
        if (ctx->pc != 0x1AD190u) { return; }
    }
    ctx->pc = 0x1AD190u;
label_1ad190:
    // 0x1ad190: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD190u;
    {
        const bool branch_taken_0x1ad190 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1AD194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD190u;
            // 0x1ad194: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad190) {
            ctx->pc = 0x1AD1A0u;
            goto label_1ad1a0;
        }
    }
    ctx->pc = 0x1AD198u;
    // 0x1ad198: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1AD198u;
    {
        const bool branch_taken_0x1ad198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD198u;
            // 0x1ad19c: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad198) {
            ctx->pc = 0x1AD204u;
            goto label_1ad204;
        }
    }
    ctx->pc = 0x1AD1A0u;
label_1ad1a0:
    // 0x1ad1a0: 0xc06ade4  jal         func_1AB790
    ctx->pc = 0x1AD1A0u;
    SET_GPR_U32(ctx, 31, 0x1AD1A8u);
    ctx->pc = 0x1AB790u;
    if (runtime->hasFunction(0x1AB790u)) {
        auto targetFn = runtime->lookupFunction(0x1AB790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1A8u; }
        if (ctx->pc != 0x1AD1A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB790_0x1ab790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1A8u; }
        if (ctx->pc != 0x1AD1A8u) { return; }
    }
    ctx->pc = 0x1AD1A8u;
label_1ad1a8:
    // 0x1ad1a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AD1A8u;
    {
        const bool branch_taken_0x1ad1a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD1ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD1A8u;
            // 0x1ad1ac: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad1a8) {
            ctx->pc = 0x1AD1BCu;
            goto label_1ad1bc;
        }
    }
    ctx->pc = 0x1AD1B0u;
label_1ad1b0:
    // 0x1ad1b0: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1AD1B0u;
    SET_GPR_U32(ctx, 31, 0x1AD1B8u);
    ctx->pc = 0x1AD1B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD1B0u;
            // 0x1ad1b4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1B8u; }
        if (ctx->pc != 0x1AD1B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1B8u; }
        if (ctx->pc != 0x1AD1B8u) { return; }
    }
    ctx->pc = 0x1AD1B8u;
label_1ad1b8:
    // 0x1ad1b8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1ad1b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1ad1bc:
    // 0x1ad1bc: 0xc069fd4  jal         func_1A7F50
    ctx->pc = 0x1AD1BCu;
    SET_GPR_U32(ctx, 31, 0x1AD1C4u);
    ctx->pc = 0x1A7F50u;
    if (runtime->hasFunction(0x1A7F50u)) {
        auto targetFn = runtime->lookupFunction(0x1A7F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1C4u; }
        if (ctx->pc != 0x1AD1C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7F50_0x1a7f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1C4u; }
        if (ctx->pc != 0x1AD1C4u) { return; }
    }
    ctx->pc = 0x1AD1C4u;
label_1ad1c4:
    // 0x1ad1c4: 0x1c40fffa  bgtz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AD1C4u;
    {
        const bool branch_taken_0x1ad1c4 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1ad1c4) {
            ctx->pc = 0x1AD1B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ad1b0;
        }
    }
    ctx->pc = 0x1AD1CCu;
    // 0x1ad1cc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AD1CCu;
    {
        const bool branch_taken_0x1ad1cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD1CCu;
            // 0x1ad1d0: 0x3c028000  lui         $v0, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad1cc) {
            ctx->pc = 0x1AD1E0u;
            goto label_1ad1e0;
        }
    }
    ctx->pc = 0x1AD1D4u;
label_1ad1d4:
    // 0x1ad1d4: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1AD1D4u;
    SET_GPR_U32(ctx, 31, 0x1AD1DCu);
    ctx->pc = 0x1AD1D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD1D4u;
            // 0x1ad1d8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1DCu; }
        if (ctx->pc != 0x1AD1DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1DCu; }
        if (ctx->pc != 0x1AD1DCu) { return; }
    }
    ctx->pc = 0x1AD1DCu;
label_1ad1dc:
    // 0x1ad1dc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ad1dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
label_1ad1e0:
    // 0x1ad1e0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1ad1e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ad1e4: 0xc06a030  jal         func_1A80C0
    ctx->pc = 0x1AD1E4u;
    SET_GPR_U32(ctx, 31, 0x1AD1ECu);
    ctx->pc = 0x1AD1E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD1E4u;
            // 0x1ad1e8: 0x3444000c  ori         $a0, $v0, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A80C0u;
    if (runtime->hasFunction(0x1A80C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A80C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1ECu; }
        if (ctx->pc != 0x1AD1ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A80C0_0x1a80c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1ECu; }
        if (ctx->pc != 0x1AD1ECu) { return; }
    }
    ctx->pc = 0x1AD1ECu;
label_1ad1ec:
    // 0x1ad1ec: 0x1c40fff9  bgtz        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AD1ECu;
    {
        const bool branch_taken_0x1ad1ec = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1ad1ec) {
            ctx->pc = 0x1AD1D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ad1d4;
        }
    }
    ctx->pc = 0x1AD1F4u;
    // 0x1ad1f4: 0xc06adfc  jal         func_1AB7F0
    ctx->pc = 0x1AD1F4u;
    SET_GPR_U32(ctx, 31, 0x1AD1FCu);
    ctx->pc = 0x1AB7F0u;
    if (runtime->hasFunction(0x1AB7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1FCu; }
        if (ctx->pc != 0x1AD1FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD1FCu; }
        if (ctx->pc != 0x1AD1FCu) { return; }
    }
    ctx->pc = 0x1AD1FCu;
label_1ad1fc:
    // 0x1ad1fc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1ad1fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad200: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1ad200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1ad204:
    // 0x1ad204: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ad204u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ad208: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ad208u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ad20c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ad20cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad210: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD210u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD210u;
            // 0x1ad214: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD180u: goto label_1ad180;
            case 0x1AD190u: goto label_1ad190;
            case 0x1AD1A0u: goto label_1ad1a0;
            case 0x1AD1A8u: goto label_1ad1a8;
            case 0x1AD1B0u: goto label_1ad1b0;
            case 0x1AD1B8u: goto label_1ad1b8;
            case 0x1AD1BCu: goto label_1ad1bc;
            case 0x1AD1C4u: goto label_1ad1c4;
            case 0x1AD1D4u: goto label_1ad1d4;
            case 0x1AD1DCu: goto label_1ad1dc;
            case 0x1AD1E0u: goto label_1ad1e0;
            case 0x1AD1ECu: goto label_1ad1ec;
            case 0x1AD1FCu: goto label_1ad1fc;
            case 0x1AD204u: goto label_1ad204;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD218u;
    // 0x1ad218: 0x0  nop
    ctx->pc = 0x1ad218u;
    // NOP
    // 0x1ad21c: 0x0  nop
    ctx->pc = 0x1ad21cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
