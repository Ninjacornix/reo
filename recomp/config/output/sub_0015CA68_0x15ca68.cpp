#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015CA68
// Address: 0x15ca68 - 0x15cbc8
void sub_0015CA68_0x15ca68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015CA68_0x15ca68");
#endif

    switch (ctx->pc) {
        case 0x15caa0u: goto label_15caa0;
        case 0x15cab0u: goto label_15cab0;
        case 0x15cac0u: goto label_15cac0;
        case 0x15cad0u: goto label_15cad0;
        case 0x15cae8u: goto label_15cae8;
        case 0x15caf8u: goto label_15caf8;
        case 0x15cb04u: goto label_15cb04;
        case 0x15cb14u: goto label_15cb14;
        case 0x15cb24u: goto label_15cb24;
        case 0x15cb3cu: goto label_15cb3c;
        case 0x15cb4cu: goto label_15cb4c;
        case 0x15cb5cu: goto label_15cb5c;
        case 0x15cb6cu: goto label_15cb6c;
        case 0x15cb7cu: goto label_15cb7c;
        case 0x15cb8cu: goto label_15cb8c;
        case 0x15cb9cu: goto label_15cb9c;
        default: break;
    }

    ctx->pc = 0x15ca68u;

    // 0x15ca68: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15ca68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15ca6c: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x15ca6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x15ca70: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ca70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ca74: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x15ca74u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ca78: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15ca78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ca7c: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x15ca7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ca80: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15ca80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15ca84: 0x2118018  mult        $s0, $s0, $s1
    ctx->pc = 0x15ca84u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x15ca88: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15ca88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15ca8c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15ca8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ca90: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15ca90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15ca94: 0x8c920040  lw          $s2, 0x40($a0)
    ctx->pc = 0x15ca94u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15ca98: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CA98u;
    SET_GPR_U32(ctx, 31, 0x15CAA0u);
    ctx->pc = 0x15CA9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CA98u;
            // 0x15ca9c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAA0u; }
        if (ctx->pc != 0x15CAA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAA0u; }
        if (ctx->pc != 0x15CAA0u) { return; }
    }
    ctx->pc = 0x15CAA0u;
label_15caa0:
    // 0x15caa0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15caa0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15caa4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15caa4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15caa8: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CAA8u;
    SET_GPR_U32(ctx, 31, 0x15CAB0u);
    ctx->pc = 0x15CAACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CAA8u;
            // 0x15caac: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAB0u; }
        if (ctx->pc != 0x15CAB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAB0u; }
        if (ctx->pc != 0x15CAB0u) { return; }
    }
    ctx->pc = 0x15CAB0u;
label_15cab0:
    // 0x15cab0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cab4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15cab4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cab8: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CAB8u;
    SET_GPR_U32(ctx, 31, 0x15CAC0u);
    ctx->pc = 0x15CABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CAB8u;
            // 0x15cabc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAC0u; }
        if (ctx->pc != 0x15CAC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAC0u; }
        if (ctx->pc != 0x15CAC0u) { return; }
    }
    ctx->pc = 0x15CAC0u;
label_15cac0:
    // 0x15cac0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cac0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cac4: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x15cac4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x15cac8: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CAC8u;
    SET_GPR_U32(ctx, 31, 0x15CAD0u);
    ctx->pc = 0x15CACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CAC8u;
            // 0x15cacc: 0x24050017  addiu       $a1, $zero, 0x17 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAD0u; }
        if (ctx->pc != 0x15CAD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAD0u; }
        if (ctx->pc != 0x15CAD0u) { return; }
    }
    ctx->pc = 0x15CAD0u;
label_15cad0:
    // 0x15cad0: 0x102140  sll         $a0, $s0, 5
    ctx->pc = 0x15cad0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 5));
    // 0x15cad4: 0x902023  subu        $a0, $a0, $s0
    ctx->pc = 0x15cad4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x15cad8: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x15cad8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x15cadc: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x15cadcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x15cae0: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x15CAE0u;
    SET_GPR_U32(ctx, 31, 0x15CAE8u);
    ctx->pc = 0x15CAE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CAE0u;
            // 0x15cae4: 0x420c0  sll         $a0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAE8u; }
        if (ctx->pc != 0x15CAE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAE8u; }
        if (ctx->pc != 0x15CAE8u) { return; }
    }
    ctx->pc = 0x15CAE8u;
label_15cae8:
    // 0x15cae8: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x15cae8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x15caec: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x15caecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x15caf0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x15CAF0u;
    SET_GPR_U32(ctx, 31, 0x15CAF8u);
    ctx->pc = 0x15CAF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CAF0u;
            // 0x15caf4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAF8u; }
        if (ctx->pc != 0x15CAF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CAF8u; }
        if (ctx->pc != 0x15CAF8u) { return; }
    }
    ctx->pc = 0x15CAF8u;
label_15caf8:
    // 0x15caf8: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x15caf8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cafc: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x15CAFCu;
    SET_GPR_U32(ctx, 31, 0x15CB04u);
    ctx->pc = 0x15CB00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CAFCu;
            // 0x15cb00: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB04u; }
        if (ctx->pc != 0x15CB04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB04u; }
        if (ctx->pc != 0x15CB04u) { return; }
    }
    ctx->pc = 0x15CB04u;
label_15cb04:
    // 0x15cb04: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15cb04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cb08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb0c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x15CB0Cu;
    SET_GPR_U32(ctx, 31, 0x15CB14u);
    ctx->pc = 0x15CB10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB0Cu;
            // 0x15cb10: 0x200882d  daddu       $s1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB14u; }
        if (ctx->pc != 0x15CB14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB14u; }
        if (ctx->pc != 0x15CB14u) { return; }
    }
    ctx->pc = 0x15CB14u;
label_15cb14:
    // 0x15cb14: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x15cb14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb18: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15cb18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb1c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x15CB1Cu;
    SET_GPR_U32(ctx, 31, 0x15CB24u);
    ctx->pc = 0x15CB20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB1Cu;
            // 0x15cb20: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB24u; }
        if (ctx->pc != 0x15CB24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB24u; }
        if (ctx->pc != 0x15CB24u) { return; }
    }
    ctx->pc = 0x15CB24u;
label_15cb24:
    // 0x15cb24: 0x2405002d  addiu       $a1, $zero, 0x2D
    ctx->pc = 0x15cb24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x15cb28: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x15cb28u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x15cb2c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb30: 0x202880b  movn        $s1, $s0, $v0
    ctx->pc = 0x15cb30u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 16));
    // 0x15cb34: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CB34u;
    SET_GPR_U32(ctx, 31, 0x15CB3Cu);
    ctx->pc = 0x15CB38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB34u;
            // 0x15cb38: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB3Cu; }
        if (ctx->pc != 0x15CB3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB3Cu; }
        if (ctx->pc != 0x15CB3Cu) { return; }
    }
    ctx->pc = 0x15CB3Cu;
label_15cb3c:
    // 0x15cb3c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb40: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15cb40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb44: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CB44u;
    SET_GPR_U32(ctx, 31, 0x15CB4Cu);
    ctx->pc = 0x15CB48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB44u;
            // 0x15cb48: 0x2405002c  addiu       $a1, $zero, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB4Cu; }
        if (ctx->pc != 0x15CB4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB4Cu; }
        if (ctx->pc != 0x15CB4Cu) { return; }
    }
    ctx->pc = 0x15CB4Cu;
label_15cb4c:
    // 0x15cb4c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb50: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15cb50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb54: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CB54u;
    SET_GPR_U32(ctx, 31, 0x15CB5Cu);
    ctx->pc = 0x15CB58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB54u;
            // 0x15cb58: 0x2405002a  addiu       $a1, $zero, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB5Cu; }
        if (ctx->pc != 0x15CB5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB5Cu; }
        if (ctx->pc != 0x15CB5Cu) { return; }
    }
    ctx->pc = 0x15CB5Cu;
label_15cb5c:
    // 0x15cb5c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb60: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x15cb60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x15cb64: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CB64u;
    SET_GPR_U32(ctx, 31, 0x15CB6Cu);
    ctx->pc = 0x15CB68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB64u;
            // 0x15cb68: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB6Cu; }
        if (ctx->pc != 0x15CB6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB6Cu; }
        if (ctx->pc != 0x15CB6Cu) { return; }
    }
    ctx->pc = 0x15CB6Cu;
label_15cb6c:
    // 0x15cb6c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb70: 0x24050033  addiu       $a1, $zero, 0x33
    ctx->pc = 0x15cb70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 51));
    // 0x15cb74: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CB74u;
    SET_GPR_U32(ctx, 31, 0x15CB7Cu);
    ctx->pc = 0x15CB78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB74u;
            // 0x15cb78: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB7Cu; }
        if (ctx->pc != 0x15CB7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB7Cu; }
        if (ctx->pc != 0x15CB7Cu) { return; }
    }
    ctx->pc = 0x15CB7Cu;
label_15cb7c:
    // 0x15cb7c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb80: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x15cb80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x15cb84: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CB84u;
    SET_GPR_U32(ctx, 31, 0x15CB8Cu);
    ctx->pc = 0x15CB88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB84u;
            // 0x15cb88: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB8Cu; }
        if (ctx->pc != 0x15CB8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB8Cu; }
        if (ctx->pc != 0x15CB8Cu) { return; }
    }
    ctx->pc = 0x15CB8Cu;
label_15cb8c:
    // 0x15cb8c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cb90: 0x2405001c  addiu       $a1, $zero, 0x1C
    ctx->pc = 0x15cb90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x15cb94: 0xc05d4ce  jal         func_175338
    ctx->pc = 0x15CB94u;
    SET_GPR_U32(ctx, 31, 0x15CB9Cu);
    ctx->pc = 0x15CB98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CB94u;
            // 0x15cb98: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB9Cu; }
        if (ctx->pc != 0x15CB9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175338_0x175338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CB9Cu; }
        if (ctx->pc != 0x15CB9Cu) { return; }
    }
    ctx->pc = 0x15CB9Cu;
label_15cb9c:
    // 0x15cb9c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15cb9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cba0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15cba0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15cba4: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x15cba4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x15cba8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15cba8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15cbac: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15cbacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cbb0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15cbb0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15cbb4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15cbb4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15cbb8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15cbb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15cbbc: 0x805afb2  j           func_16BEC8
    ctx->pc = 0x15CBBCu;
    ctx->pc = 0x15CBC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CBBCu;
            // 0x15cbc0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BEC8u;
    if (runtime->hasFunction(0x16BEC8u)) {
        auto targetFn = runtime->lookupFunction(0x16BEC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016BEC8_0x16bec8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15CBC4u;
    // 0x15cbc4: 0x0  nop
    ctx->pc = 0x15cbc4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
