#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014FBD8
// Address: 0x14fbd8 - 0x14fe84
void sub_0014FBD8_0x14fbd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014FBD8_0x14fbd8");
#endif

    switch (ctx->pc) {
        case 0x14fc18u: goto label_14fc18;
        case 0x14fc28u: goto label_14fc28;
        case 0x14fc34u: goto label_14fc34;
        case 0x14fc50u: goto label_14fc50;
        case 0x14fc60u: goto label_14fc60;
        case 0x14fc6cu: goto label_14fc6c;
        case 0x14fc80u: goto label_14fc80;
        case 0x14fc8cu: goto label_14fc8c;
        case 0x14fc94u: goto label_14fc94;
        case 0x14fcb4u: goto label_14fcb4;
        case 0x14fcc0u: goto label_14fcc0;
        case 0x14fcc8u: goto label_14fcc8;
        case 0x14fcdcu: goto label_14fcdc;
        case 0x14fce8u: goto label_14fce8;
        case 0x14fcf0u: goto label_14fcf0;
        case 0x14fd08u: goto label_14fd08;
        case 0x14fd38u: goto label_14fd38;
        case 0x14fd58u: goto label_14fd58;
        case 0x14fd68u: goto label_14fd68;
        case 0x14fd78u: goto label_14fd78;
        case 0x14fd80u: goto label_14fd80;
        case 0x14fdb8u: goto label_14fdb8;
        case 0x14fde8u: goto label_14fde8;
        case 0x14fe0cu: goto label_14fe0c;
        case 0x14fe1cu: goto label_14fe1c;
        case 0x14fe2cu: goto label_14fe2c;
        case 0x14fe34u: goto label_14fe34;
        default: break;
    }

    ctx->pc = 0x14fbd8u;

    // 0x14fbd8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x14fbd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x14fbdc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x14fbdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x14fbe0: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14fbe0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fbe4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x14fbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x14fbe8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x14fbe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x14fbec: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x14fbecu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fbf0: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x14fbf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x14fbf4: 0x26b61000  addiu       $s6, $s5, 0x1000
    ctx->pc = 0x14fbf4u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 21), 4096));
    // 0x14fbf8: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x14fbf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x14fbfc: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x14fbfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x14fc00: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x14fc00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14fc04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x14fc04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x14fc08: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x14fc08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x14fc0c: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x14fc0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x14fc10: 0xc052490  jal         func_149240
    ctx->pc = 0x14FC10u;
    SET_GPR_U32(ctx, 31, 0x14FC18u);
    ctx->pc = 0x14FC14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC10u;
            // 0x14fc14: 0x26b70800  addiu       $s7, $s5, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 21), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149240u;
    if (runtime->hasFunction(0x149240u)) {
        auto targetFn = runtime->lookupFunction(0x149240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC18u; }
        if (ctx->pc != 0x14FC18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149240_0x149240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC18u; }
        if (ctx->pc != 0x14FC18u) { return; }
    }
    ctx->pc = 0x14FC18u;
label_14fc18:
    // 0x14fc18: 0x3414ff80  ori         $s4, $zero, 0xFF80
    ctx->pc = 0x14fc18u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x14fc1c: 0x14a3bc  dsll32      $s4, $s4, 14
    ctx->pc = 0x14fc1cu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) << (32 + 14));
    // 0x14fc20: 0x40f02d  daddu       $fp, $v0, $zero
    ctx->pc = 0x14fc20u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc24: 0x0  nop
    ctx->pc = 0x14fc24u;
    // NOP
label_14fc28:
    // 0x14fc28: 0x2664ff80  addiu       $a0, $s3, -0x80
    ctx->pc = 0x14fc28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967168));
    // 0x14fc2c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FC2Cu;
    SET_GPR_U32(ctx, 31, 0x14FC34u);
    ctx->pc = 0x14FC30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC2Cu;
            // 0x14fc30: 0x1388c0  sll         $s1, $s3, 3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC34u; }
        if (ctx->pc != 0x14FC34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC34u; }
        if (ctx->pc != 0x14FC34u) { return; }
    }
    ctx->pc = 0x14FC34u;
label_14fc34:
    // 0x14fc34: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fc34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fc38: 0xdc25e2d8  ld          $a1, -0x1D28($at)
    ctx->pc = 0x14fc38u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959832)));
    // 0x14fc3c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x14fc3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc40: 0x2378021  addu        $s0, $s1, $s7
    ctx->pc = 0x14fc40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 23)));
    // 0x14fc44: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fc44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc48: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FC48u;
    SET_GPR_U32(ctx, 31, 0x14FC50u);
    ctx->pc = 0x14FC4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC48u;
            // 0x14fc4c: 0x2368821  addu        $s1, $s1, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC50u; }
        if (ctx->pc != 0x14FC50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC50u; }
        if (ctx->pc != 0x14FC50u) { return; }
    }
    ctx->pc = 0x14FC50u;
label_14fc50:
    // 0x14fc50: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fc50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc54: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x14fc54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc58: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FC58u;
    SET_GPR_U32(ctx, 31, 0x14FC60u);
    ctx->pc = 0x14FC5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC58u;
            // 0x14fc5c: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC60u; }
        if (ctx->pc != 0x14FC60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC60u; }
        if (ctx->pc != 0x14FC60u) { return; }
    }
    ctx->pc = 0x14FC60u;
label_14fc60:
    // 0x14fc60: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x14fc60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc64: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FC64u;
    SET_GPR_U32(ctx, 31, 0x14FC6Cu);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC6Cu; }
        if (ctx->pc != 0x14FC6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC6Cu; }
        if (ctx->pc != 0x14FC6Cu) { return; }
    }
    ctx->pc = 0x14FC6Cu;
label_14fc6c:
    // 0x14fc6c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fc6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc70: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fc70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fc74: 0xdc25e2e0  ld          $a1, -0x1D20($at)
    ctx->pc = 0x14fc74u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959840)));
    // 0x14fc78: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FC78u;
    SET_GPR_U32(ctx, 31, 0x14FC80u);
    ctx->pc = 0x14FC7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC78u;
            // 0x14fc7c: 0xa6020004  sh          $v0, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC80u; }
        if (ctx->pc != 0x14FC80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC80u; }
        if (ctx->pc != 0x14FC80u) { return; }
    }
    ctx->pc = 0x14FC80u;
label_14fc80:
    // 0x14fc80: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fc80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc84: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FC84u;
    SET_GPR_U32(ctx, 31, 0x14FC8Cu);
    ctx->pc = 0x14FC88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC84u;
            // 0x14fc88: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC8Cu; }
        if (ctx->pc != 0x14FC8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC8Cu; }
        if (ctx->pc != 0x14FC8Cu) { return; }
    }
    ctx->pc = 0x14FC8Cu;
label_14fc8c:
    // 0x14fc8c: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FC8Cu;
    SET_GPR_U32(ctx, 31, 0x14FC94u);
    ctx->pc = 0x14FC90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC8Cu;
            // 0x14fc90: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC94u; }
        if (ctx->pc != 0x14FC94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC94u; }
        if (ctx->pc != 0x14FC94u) { return; }
    }
    ctx->pc = 0x14FC94u;
label_14fc94:
    // 0x14fc94: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x14fc94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fc98: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x14fc98u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fc9c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fc9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fca0: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x14fca0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fca4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fca4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fca8: 0xdc25e2e8  ld          $a1, -0x1D18($at)
    ctx->pc = 0x14fca8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959848)));
    // 0x14fcac: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FCACu;
    SET_GPR_U32(ctx, 31, 0x14FCB4u);
    ctx->pc = 0x14FCB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCACu;
            // 0x14fcb0: 0xa6200004  sh          $zero, 0x4($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCB4u; }
        if (ctx->pc != 0x14FCB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCB4u; }
        if (ctx->pc != 0x14FCB4u) { return; }
    }
    ctx->pc = 0x14FCB4u;
label_14fcb4:
    // 0x14fcb4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fcb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fcb8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FCB8u;
    SET_GPR_U32(ctx, 31, 0x14FCC0u);
    ctx->pc = 0x14FCBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCB8u;
            // 0x14fcbc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC0u; }
        if (ctx->pc != 0x14FCC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC0u; }
        if (ctx->pc != 0x14FCC0u) { return; }
    }
    ctx->pc = 0x14FCC0u;
label_14fcc0:
    // 0x14fcc0: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FCC0u;
    SET_GPR_U32(ctx, 31, 0x14FCC8u);
    ctx->pc = 0x14FCC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCC0u;
            // 0x14fcc4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC8u; }
        if (ctx->pc != 0x14FCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC8u; }
        if (ctx->pc != 0x14FCC8u) { return; }
    }
    ctx->pc = 0x14FCC8u;
label_14fcc8:
    // 0x14fcc8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fcc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fccc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fcccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fcd0: 0xdc25e2f0  ld          $a1, -0x1D10($at)
    ctx->pc = 0x14fcd0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959856)));
    // 0x14fcd4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FCD4u;
    SET_GPR_U32(ctx, 31, 0x14FCDCu);
    ctx->pc = 0x14FCD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCD4u;
            // 0x14fcd8: 0xa6220002  sh          $v0, 0x2($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCDCu; }
        if (ctx->pc != 0x14FCDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCDCu; }
        if (ctx->pc != 0x14FCDCu) { return; }
    }
    ctx->pc = 0x14FCDCu;
label_14fcdc:
    // 0x14fcdc: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fcdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fce0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FCE0u;
    SET_GPR_U32(ctx, 31, 0x14FCE8u);
    ctx->pc = 0x14FCE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCE0u;
            // 0x14fce4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCE8u; }
        if (ctx->pc != 0x14FCE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCE8u; }
        if (ctx->pc != 0x14FCE8u) { return; }
    }
    ctx->pc = 0x14FCE8u;
label_14fce8:
    // 0x14fce8: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FCE8u;
    SET_GPR_U32(ctx, 31, 0x14FCF0u);
    ctx->pc = 0x14FCECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCE8u;
            // 0x14fcec: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCF0u; }
        if (ctx->pc != 0x14FCF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCF0u; }
        if (ctx->pc != 0x14FCF0u) { return; }
    }
    ctx->pc = 0x14FCF0u;
label_14fcf0:
    // 0x14fcf0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x14fcf0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fcf4: 0x2a630100  slti        $v1, $s3, 0x100
    ctx->pc = 0x14fcf4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x14fcf8: 0x1460ffcb  bnez        $v1, . + 4 + (-0x35 << 2)
    ctx->pc = 0x14FCF8u;
    {
        const bool branch_taken_0x14fcf8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x14FCFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCF8u;
            // 0x14fcfc: 0xa6220000  sh          $v0, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fcf8) {
            ctx->pc = 0x14FC28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fc28;
        }
    }
    ctx->pc = 0x14FD00u;
    // 0x14fd00: 0x2a0102d  daddu       $v0, $s5, $zero
    ctx->pc = 0x14fd00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fd04: 0x2413000f  addiu       $s3, $zero, 0xF
    ctx->pc = 0x14fd04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_14fd08:
    // 0x14fd08: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fd08u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fd0c: 0xa4400004  sh          $zero, 0x4($v0)
    ctx->pc = 0x14fd0cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd10: 0xa4400002  sh          $zero, 0x2($v0)
    ctx->pc = 0x14fd10u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd14: 0xa4400000  sh          $zero, 0x0($v0)
    ctx->pc = 0x14fd14u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd18: 0xa4400006  sh          $zero, 0x6($v0)
    ctx->pc = 0x14fd18u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd1c: 0x661fffa  bgez        $s3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14FD1Cu;
    {
        const bool branch_taken_0x14fd1c = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD1Cu;
            // 0x14fd20: 0x24420008  addiu       $v0, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fd1c) {
            ctx->pc = 0x14FD08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fd08;
        }
    }
    ctx->pc = 0x14FD24u;
    // 0x14fd24: 0x1ea140  sll         $s4, $fp, 5
    ctx->pc = 0x14fd24u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 30), 5));
    // 0x14fd28: 0x24120070  addiu       $s2, $zero, 0x70
    ctx->pc = 0x14fd28u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 112));
    // 0x14fd2c: 0x26b00080  addiu       $s0, $s5, 0x80
    ctx->pc = 0x14fd2cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 128));
    // 0x14fd30: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x14fd30u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fd34: 0x2413006f  addiu       $s3, $zero, 0x6F
    ctx->pc = 0x14fd34u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 111));
label_14fd38:
    // 0x14fd38: 0x232001a  div         $zero, $s1, $s2
    ctx->pc = 0x14fd38u;
    { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x14fd3c: 0x26310100  addiu       $s1, $s1, 0x100
    ctx->pc = 0x14fd3cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 256));
    // 0x14fd40: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x14FD40u;
    {
        const bool branch_taken_0x14fd40 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x14fd40) {
            ctx->pc = 0x14FD44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD40u;
            // 0x14fd44: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x14FD48u;
            goto label_14fd48;
        }
    }
    ctx->pc = 0x14FD48u;
label_14fd48:
    // 0x14fd48: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fd48u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fd4c: 0x2012  mflo        $a0
    ctx->pc = 0x14fd4cu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x14fd50: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FD50u;
    SET_GPR_U32(ctx, 31, 0x14FD58u);
    ctx->pc = 0x14FD54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD50u;
            // 0x14fd54: 0x2484fff0  addiu       $a0, $a0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD58u; }
        if (ctx->pc != 0x14FD58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD58u; }
        if (ctx->pc != 0x14FD58u) { return; }
    }
    ctx->pc = 0x14FD58u;
label_14fd58:
    // 0x14fd58: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fd58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fd5c: 0xdc25e2f8  ld          $a1, -0x1D08($at)
    ctx->pc = 0x14fd5cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959864)));
    // 0x14fd60: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FD60u;
    SET_GPR_U32(ctx, 31, 0x14FD68u);
    ctx->pc = 0x14FD64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD60u;
            // 0x14fd64: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD68u; }
        if (ctx->pc != 0x14FD68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD68u; }
        if (ctx->pc != 0x14FD68u) { return; }
    }
    ctx->pc = 0x14FD68u;
label_14fd68:
    // 0x14fd68: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x14fd68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x14fd6c: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x14fd6cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x14fd70: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FD70u;
    SET_GPR_U32(ctx, 31, 0x14FD78u);
    ctx->pc = 0x14FD74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD70u;
            // 0x14fd74: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD78u; }
        if (ctx->pc != 0x14FD78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD78u; }
        if (ctx->pc != 0x14FD78u) { return; }
    }
    ctx->pc = 0x14FD78u;
label_14fd78:
    // 0x14fd78: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FD78u;
    SET_GPR_U32(ctx, 31, 0x14FD80u);
    ctx->pc = 0x14FD7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD78u;
            // 0x14fd7c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD80u; }
        if (ctx->pc != 0x14FD80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD80u; }
        if (ctx->pc != 0x14FD80u) { return; }
    }
    ctx->pc = 0x14FD80u;
label_14fd80:
    // 0x14fd80: 0xa6140006  sh          $s4, 0x6($s0)
    ctx->pc = 0x14fd80u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 20));
    // 0x14fd84: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x14fd84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x14fd88: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x14fd88u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x14fd8c: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x14fd8cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fd90: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x14fd90u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fd94: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x14fd94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fd98: 0x661ffe7  bgez        $s3, . + 4 + (-0x19 << 2)
    ctx->pc = 0x14FD98u;
    {
        const bool branch_taken_0x14fd98 = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD98u;
            // 0x14fd9c: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fd98) {
            ctx->pc = 0x14FD38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fd38;
        }
    }
    ctx->pc = 0x14FDA0u;
    // 0x14fda0: 0x1ea180  sll         $s4, $fp, 6
    ctx->pc = 0x14fda0u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 30), 6));
    // 0x14fda4: 0x2402458d  addiu       $v0, $zero, 0x458D
    ctx->pc = 0x14fda4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17805));
    // 0x14fda8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x14fda8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fdac: 0x26a30400  addiu       $v1, $s5, 0x400
    ctx->pc = 0x14fdacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1024));
    // 0x14fdb0: 0x2413000f  addiu       $s3, $zero, 0xF
    ctx->pc = 0x14fdb0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x14fdb4: 0x0  nop
    ctx->pc = 0x14fdb4u;
    // NOP
label_14fdb8:
    // 0x14fdb8: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fdb8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fdbc: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x14fdbcu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fdc0: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x14fdc0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fdc4: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x14fdc4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fdc8: 0xa4640006  sh          $a0, 0x6($v1)
    ctx->pc = 0x14fdc8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 6), (uint16_t)GPR_U32(ctx, 4));
    // 0x14fdcc: 0x661fffa  bgez        $s3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14FDCCu;
    {
        const bool branch_taken_0x14fdcc = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FDCCu;
            // 0x14fdd0: 0x24630008  addiu       $v1, $v1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fdcc) {
            ctx->pc = 0x14FDB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fdb8;
        }
    }
    ctx->pc = 0x14FDD4u;
    // 0x14fdd4: 0x26b00480  addiu       $s0, $s5, 0x480
    ctx->pc = 0x14fdd4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 1152));
    // 0x14fdd8: 0x241500ff  addiu       $s5, $zero, 0xFF
    ctx->pc = 0x14fdd8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x14fddc: 0x24120070  addiu       $s2, $zero, 0x70
    ctx->pc = 0x14fddcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 112));
    // 0x14fde0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x14fde0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fde4: 0x2413006f  addiu       $s3, $zero, 0x6F
    ctx->pc = 0x14fde4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 111));
label_14fde8:
    // 0x14fde8: 0x232001a  div         $zero, $s1, $s2
    ctx->pc = 0x14fde8u;
    { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x14fdec: 0x26310100  addiu       $s1, $s1, 0x100
    ctx->pc = 0x14fdecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 256));
    // 0x14fdf0: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x14FDF0u;
    {
        const bool branch_taken_0x14fdf0 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x14fdf0) {
            ctx->pc = 0x14FDF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14FDF0u;
            // 0x14fdf4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x14FDF8u;
            goto label_14fdf8;
        }
    }
    ctx->pc = 0x14FDF8u;
label_14fdf8:
    // 0x14fdf8: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fdf8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fdfc: 0x2012  mflo        $a0
    ctx->pc = 0x14fdfcu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x14fe00: 0x2a42023  subu        $a0, $s5, $a0
    ctx->pc = 0x14fe00u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 4)));
    // 0x14fe04: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FE04u;
    SET_GPR_U32(ctx, 31, 0x14FE0Cu);
    ctx->pc = 0x14FE08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE04u;
            // 0x14fe08: 0x2484fff0  addiu       $a0, $a0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE0Cu; }
        if (ctx->pc != 0x14FE0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE0Cu; }
        if (ctx->pc != 0x14FE0Cu) { return; }
    }
    ctx->pc = 0x14FE0Cu;
label_14fe0c:
    // 0x14fe0c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fe0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fe10: 0xdc25e300  ld          $a1, -0x1D00($at)
    ctx->pc = 0x14fe10u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959872)));
    // 0x14fe14: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FE14u;
    SET_GPR_U32(ctx, 31, 0x14FE1Cu);
    ctx->pc = 0x14FE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE14u;
            // 0x14fe18: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE1Cu; }
        if (ctx->pc != 0x14FE1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE1Cu; }
        if (ctx->pc != 0x14FE1Cu) { return; }
    }
    ctx->pc = 0x14FE1Cu;
label_14fe1c:
    // 0x14fe1c: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x14fe1cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x14fe20: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x14fe20u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x14fe24: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FE24u;
    SET_GPR_U32(ctx, 31, 0x14FE2Cu);
    ctx->pc = 0x14FE28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE24u;
            // 0x14fe28: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE2Cu; }
        if (ctx->pc != 0x14FE2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE2Cu; }
        if (ctx->pc != 0x14FE2Cu) { return; }
    }
    ctx->pc = 0x14FE2Cu;
label_14fe2c:
    // 0x14fe2c: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FE2Cu;
    SET_GPR_U32(ctx, 31, 0x14FE34u);
    ctx->pc = 0x14FE30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE2Cu;
            // 0x14fe30: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE34u; }
        if (ctx->pc != 0x14FE34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE34u; }
        if (ctx->pc != 0x14FE34u) { return; }
    }
    ctx->pc = 0x14FE34u;
label_14fe34:
    // 0x14fe34: 0xa6140006  sh          $s4, 0x6($s0)
    ctx->pc = 0x14fe34u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 20));
    // 0x14fe38: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x14fe38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x14fe3c: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x14fe3cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x14fe40: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x14fe40u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fe44: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x14fe44u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fe48: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x14fe48u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fe4c: 0x661ffe6  bgez        $s3, . + 4 + (-0x1A << 2)
    ctx->pc = 0x14FE4Cu;
    {
        const bool branch_taken_0x14fe4c = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE4Cu;
            // 0x14fe50: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fe4c) {
            ctx->pc = 0x14FDE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fde8;
        }
    }
    ctx->pc = 0x14FE54u;
    // 0x14fe54: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14fe54u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14fe58: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x14fe58u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14fe5c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x14fe5cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14fe60: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x14fe60u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x14fe64: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x14fe64u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14fe68: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x14fe68u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x14fe6c: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x14fe6cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14fe70: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x14fe70u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x14fe74: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x14fe74u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14fe78: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x14fe78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x14fe7c: 0x3e00008  jr          $ra
    ctx->pc = 0x14FE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14FE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE7Cu;
            // 0x14fe80: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14FC18u: goto label_14fc18;
            case 0x14FC28u: goto label_14fc28;
            case 0x14FC34u: goto label_14fc34;
            case 0x14FC50u: goto label_14fc50;
            case 0x14FC60u: goto label_14fc60;
            case 0x14FC6Cu: goto label_14fc6c;
            case 0x14FC80u: goto label_14fc80;
            case 0x14FC8Cu: goto label_14fc8c;
            case 0x14FC94u: goto label_14fc94;
            case 0x14FCB4u: goto label_14fcb4;
            case 0x14FCC0u: goto label_14fcc0;
            case 0x14FCC8u: goto label_14fcc8;
            case 0x14FCDCu: goto label_14fcdc;
            case 0x14FCE8u: goto label_14fce8;
            case 0x14FCF0u: goto label_14fcf0;
            case 0x14FD08u: goto label_14fd08;
            case 0x14FD38u: goto label_14fd38;
            case 0x14FD48u: goto label_14fd48;
            case 0x14FD58u: goto label_14fd58;
            case 0x14FD68u: goto label_14fd68;
            case 0x14FD78u: goto label_14fd78;
            case 0x14FD80u: goto label_14fd80;
            case 0x14FDB8u: goto label_14fdb8;
            case 0x14FDE8u: goto label_14fde8;
            case 0x14FDF8u: goto label_14fdf8;
            case 0x14FE0Cu: goto label_14fe0c;
            case 0x14FE1Cu: goto label_14fe1c;
            case 0x14FE2Cu: goto label_14fe2c;
            case 0x14FE34u: goto label_14fe34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FE84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
