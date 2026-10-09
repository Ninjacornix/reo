#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6A40
// Address: 0x1c6a40 - 0x1c6c90
void sub_001C6A40_0x1c6a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6A40_0x1c6a40");
#endif

    switch (ctx->pc) {
        case 0x1c6a50u: goto label_1c6a50;
        case 0x1c6a90u: goto label_1c6a90;
        case 0x1c6ab4u: goto label_1c6ab4;
        case 0x1c6abcu: goto label_1c6abc;
        case 0x1c6b68u: goto label_1c6b68;
        case 0x1c6c3cu: goto label_1c6c3c;
        default: break;
    }

    ctx->pc = 0x1c6a40u;

    // 0x1c6a40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6a44: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6a48: 0xc072214  jal         func_1C8850
    ctx->pc = 0x1C6A48u;
    SET_GPR_U32(ctx, 31, 0x1C6A50u);
    ctx->pc = 0x1C8850u;
    if (runtime->hasFunction(0x1C8850u)) {
        auto targetFn = runtime->lookupFunction(0x1C8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6A50u; }
        if (ctx->pc != 0x1C6A50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6A50u; }
        if (ctx->pc != 0x1C6A50u) { return; }
    }
    ctx->pc = 0x1C6A50u;
label_1c6a50:
    // 0x1c6a50: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6a50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6a54: 0xe420506c  swc1        $f0, 0x506C($at)
    ctx->pc = 0x1c6a54u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20588), bits); }
    // 0x1c6a58: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6a58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6a5c: 0xc4225068  lwc1        $f2, 0x5068($at)
    ctx->pc = 0x1c6a5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20584)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1c6a60: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6a60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6a64: 0xc4215060  lwc1        $f1, 0x5060($at)
    ctx->pc = 0x1c6a64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20576)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c6a68: 0x46020081  sub.s       $f2, $f0, $f2
    ctx->pc = 0x1c6a68u;
    ctx->f[2] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x1c6a6c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6a6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6a70: 0xe4205068  swc1        $f0, 0x5068($at)
    ctx->pc = 0x1c6a70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20584), bits); }
    // 0x1c6a74: 0x46001006  mov.s       $f0, $f2
    ctx->pc = 0x1c6a74u;
    ctx->f[0] = FPU_MOV_S(ctx->f[2]);
    // 0x1c6a78: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6a78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6a7c: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1c6a7cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1c6a80: 0xe4225064  swc1        $f2, 0x5064($at)
    ctx->pc = 0x1c6a80u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20580), bits); }
    // 0x1c6a84: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6a84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6a88: 0xc071db8  jal         func_1C76E0
    ctx->pc = 0x1C6A88u;
    SET_GPR_U32(ctx, 31, 0x1C6A90u);
    ctx->pc = 0x1C6A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6A88u;
            // 0x1c6a8c: 0xe4205060  swc1        $f0, 0x5060($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20576), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C76E0u;
    if (runtime->hasFunction(0x1C76E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C76E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6A90u; }
        if (ctx->pc != 0x1C6A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C76E0_0x1c76e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6A90u; }
        if (ctx->pc != 0x1C6A90u) { return; }
    }
    ctx->pc = 0x1C6A90u;
label_1c6a90:
    // 0x1c6a90: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6a94: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c6a94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c6a98: 0x90235056  lbu         $v1, 0x5056($at)
    ctx->pc = 0x1c6a98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20566)));
    // 0x1c6a9c: 0x24425f70  addiu       $v0, $v0, 0x5F70
    ctx->pc = 0x1c6a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24432));
    // 0x1c6aa0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c6aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c6aa4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c6aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c6aa8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c6aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c6aac: 0x40f809  jalr        $v0
    ctx->pc = 0x1C6AACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1C6AB4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1C6AB4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6A50u: goto label_1c6a50;
            case 0x1C6A90u: goto label_1c6a90;
            case 0x1C6AB4u: goto label_1c6ab4;
            case 0x1C6ABCu: goto label_1c6abc;
            case 0x1C6B24u: goto label_1c6b24;
            case 0x1C6B68u: goto label_1c6b68;
            case 0x1C6B9Cu: goto label_1c6b9c;
            case 0x1C6C3Cu: goto label_1c6c3c;
            case 0x1C6C48u: goto label_1c6c48;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1C6AB4u; }
            if (ctx->pc != 0x1C6AB4u) { return; }
        }
        }
    }
    ctx->pc = 0x1C6AB4u;
label_1c6ab4:
    // 0x1c6ab4: 0xc071d44  jal         func_1C7510
    ctx->pc = 0x1C6AB4u;
    SET_GPR_U32(ctx, 31, 0x1C6ABCu);
    ctx->pc = 0x1C7510u;
    if (runtime->hasFunction(0x1C7510u)) {
        auto targetFn = runtime->lookupFunction(0x1C7510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6ABCu; }
        if (ctx->pc != 0x1C6ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7510_0x1c7510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6ABCu; }
        if (ctx->pc != 0x1C6ABCu) { return; }
    }
    ctx->pc = 0x1C6ABCu;
label_1c6abc:
    // 0x1c6abc: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6abcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6ac0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x1c6ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x1c6ac4: 0xc4225078  lwc1        $f2, 0x5078($at)
    ctx->pc = 0x1c6ac4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20600)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1c6ac8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1c6ac8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1c6acc: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6accu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6ad0: 0xc4215064  lwc1        $f1, 0x5064($at)
    ctx->pc = 0x1c6ad0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20580)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c6ad4: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1c6ad4u;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1c6ad8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6ad8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6adc: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1c6adcu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c6ae0: 0x45010010  bc1t        . + 4 + (0x10 << 2)
    ctx->pc = 0x1C6AE0u;
    {
        const bool branch_taken_0x1c6ae0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1C6AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6AE0u;
            // 0x1c6ae4: 0xe4215078  swc1        $f1, 0x5078($at) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20600), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6ae0) {
            ctx->pc = 0x1C6B24u;
            goto label_1c6b24;
        }
    }
    ctx->pc = 0x1C6AE8u;
    // 0x1c6ae8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6ae8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6aec: 0x9423508e  lhu         $v1, 0x508E($at)
    ctx->pc = 0x1c6aecu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20622)));
    // 0x1c6af0: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1c6af0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1c6af4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6af4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6af8: 0x94225096  lhu         $v0, 0x5096($at)
    ctx->pc = 0x1c6af8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20630)));
    // 0x1c6afc: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6afcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b00: 0xe4205078  swc1        $f0, 0x5078($at)
    ctx->pc = 0x1c6b00u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20600), bits); }
    // 0x1c6b04: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b08: 0xa423508c  sh          $v1, 0x508C($at)
    ctx->pc = 0x1c6b08u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 20620), (uint16_t)GPR_U32(ctx, 3));
    // 0x1c6b0c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b10: 0xa4225094  sh          $v0, 0x5094($at)
    ctx->pc = 0x1c6b10u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 20628), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c6b14: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b18: 0xa420508e  sh          $zero, 0x508E($at)
    ctx->pc = 0x1c6b18u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 20622), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c6b1c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b20: 0xa4205096  sh          $zero, 0x5096($at)
    ctx->pc = 0x1c6b20u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 20630), (uint16_t)GPR_U32(ctx, 0));
label_1c6b24:
    // 0x1c6b24: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b28: 0xc4225074  lwc1        $f2, 0x5074($at)
    ctx->pc = 0x1c6b28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20596)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1c6b2c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b30: 0xc4215064  lwc1        $f1, 0x5064($at)
    ctx->pc = 0x1c6b30u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20580)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c6b34: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c6b34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c6b38: 0xc4205f68  lwc1        $f0, 0x5F68($at)
    ctx->pc = 0x1c6b38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 24424)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c6b3c: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1c6b3cu;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1c6b40: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1c6b40u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c6b44: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b48: 0x45010014  bc1t        . + 4 + (0x14 << 2)
    ctx->pc = 0x1C6B48u;
    {
        const bool branch_taken_0x1c6b48 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1C6B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6B48u;
            // 0x1c6b4c: 0xe4215074  swc1        $f1, 0x5074($at) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20596), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6b48) {
            ctx->pc = 0x1C6B9Cu;
            goto label_1c6b9c;
        }
    }
    ctx->pc = 0x1C6B50u;
    // 0x1c6b50: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b54: 0x90255056  lbu         $a1, 0x5056($at)
    ctx->pc = 0x1c6b54u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20566)));
    // 0x1c6b58: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b5c: 0x90265057  lbu         $a2, 0x5057($at)
    ctx->pc = 0x1c6b5cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20567)));
    // 0x1c6b60: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C6B60u;
    SET_GPR_U32(ctx, 31, 0x1C6B68u);
    ctx->pc = 0x1C6B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6B60u;
            // 0x1c6b64: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6B68u; }
        if (ctx->pc != 0x1C6B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6B68u; }
        if (ctx->pc != 0x1C6B68u) { return; }
    }
    ctx->pc = 0x1C6B68u;
label_1c6b68:
    // 0x1c6b68: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b6c: 0x24020012  addiu       $v0, $zero, 0x12
    ctx->pc = 0x1c6b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1c6b70: 0x942351b8  lhu         $v1, 0x51B8($at)
    ctx->pc = 0x1c6b70u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c6b74: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b78: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c6b78u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
    // 0x1c6b7c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c6b7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c6b80: 0x8c225f58  lw          $v0, 0x5F58($at)
    ctx->pc = 0x1c6b80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c6b84: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1c6b84u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c6b88: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C6B88u;
    {
        const bool branch_taken_0x1c6b88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c6b88) {
            ctx->pc = 0x1C6B9Cu;
            goto label_1c6b9c;
        }
    }
    ctx->pc = 0x1C6B90u;
    // 0x1c6b90: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1c6b90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c6b94: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6b98: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c6b98u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
label_1c6b9c:
    // 0x1c6b9c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6b9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6ba0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6ba0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6ba4: 0x90225056  lbu         $v0, 0x5056($at)
    ctx->pc = 0x1c6ba4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20566)));
    // 0x1c6ba8: 0x38420007  xori        $v0, $v0, 0x7
    ctx->pc = 0x1c6ba8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)7);
    // 0x1c6bac: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1c6bacu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1c6bb0: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1c6bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1c6bb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6BB4u;
            // 0x1c6bb8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6A50u: goto label_1c6a50;
            case 0x1C6A90u: goto label_1c6a90;
            case 0x1C6AB4u: goto label_1c6ab4;
            case 0x1C6ABCu: goto label_1c6abc;
            case 0x1C6B24u: goto label_1c6b24;
            case 0x1C6B68u: goto label_1c6b68;
            case 0x1C6B9Cu: goto label_1c6b9c;
            case 0x1C6C3Cu: goto label_1c6c3c;
            case 0x1C6C48u: goto label_1c6c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6BBCu;
    // 0x1c6bbc: 0x0  nop
    ctx->pc = 0x1c6bbcu;
    // NOP
    // 0x1c6bc0: 0x8071ea0  j           func_1C7A80
    ctx->pc = 0x1C6BC0u;
    ctx->pc = 0x1C6BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6BC0u;
            // 0x1c6bc4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7A80u;
    if (runtime->hasFunction(0x1C7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7A80_0x1c7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6BC8u;
    // 0x1c6bc8: 0x0  nop
    ctx->pc = 0x1c6bc8u;
    // NOP
    // 0x1c6bcc: 0x0  nop
    ctx->pc = 0x1c6bccu;
    // NOP
    // 0x1c6bd0: 0x8071ea0  j           func_1C7A80
    ctx->pc = 0x1C6BD0u;
    ctx->pc = 0x1C6BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6BD0u;
            // 0x1c6bd4: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7A80u;
    if (runtime->hasFunction(0x1C7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7A80_0x1c7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6BD8u;
    // 0x1c6bd8: 0x0  nop
    ctx->pc = 0x1c6bd8u;
    // NOP
    // 0x1c6bdc: 0x0  nop
    ctx->pc = 0x1c6bdcu;
    // NOP
    // 0x1c6be0: 0x8071ea0  j           func_1C7A80
    ctx->pc = 0x1C6BE0u;
    ctx->pc = 0x1C6BE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6BE0u;
            // 0x1c6be4: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7A80u;
    if (runtime->hasFunction(0x1C7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7A80_0x1c7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6BE8u;
    // 0x1c6be8: 0x0  nop
    ctx->pc = 0x1c6be8u;
    // NOP
    // 0x1c6bec: 0x0  nop
    ctx->pc = 0x1c6becu;
    // NOP
    // 0x1c6bf0: 0x8071ea0  j           func_1C7A80
    ctx->pc = 0x1C6BF0u;
    ctx->pc = 0x1C6BF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6BF0u;
            // 0x1c6bf4: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7A80u;
    if (runtime->hasFunction(0x1C7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7A80_0x1c7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6BF8u;
    // 0x1c6bf8: 0x0  nop
    ctx->pc = 0x1c6bf8u;
    // NOP
    // 0x1c6bfc: 0x0  nop
    ctx->pc = 0x1c6bfcu;
    // NOP
    // 0x1c6c00: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6c00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6c04: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1c6c04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c6c08: 0x8071ea0  j           func_1C7A80
    ctx->pc = 0x1C6C08u;
    ctx->pc = 0x1C6C0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6C08u;
            // 0x1c6c0c: 0xa02051a1  sb          $zero, 0x51A1($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 20897), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7A80u;
    if (runtime->hasFunction(0x1C7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7A80_0x1c7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6C10u;
    // 0x1c6c10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6c10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6c14: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6c14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6c18: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6c1c: 0xc4215074  lwc1        $f1, 0x5074($at)
    ctx->pc = 0x1c6c1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20596)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c6c20: 0x3c010025  lui         $at, 0x25
    ctx->pc = 0x1c6c20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)37 << 16));
    // 0x1c6c24: 0xc4202d70  lwc1        $f0, 0x2D70($at)
    ctx->pc = 0x1c6c24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 11632)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c6c28: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1c6c28u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c6c2c: 0x45010006  bc1t        . + 4 + (0x6 << 2)
    ctx->pc = 0x1C6C2Cu;
    {
        const bool branch_taken_0x1c6c2c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1c6c2c) {
            ctx->pc = 0x1C6C48u;
            goto label_1c6c48;
        }
    }
    ctx->pc = 0x1C6C34u;
    // 0x1c6c34: 0xc071b9c  jal         func_1C6E70
    ctx->pc = 0x1C6C34u;
    SET_GPR_U32(ctx, 31, 0x1C6C3Cu);
    ctx->pc = 0x1C6E70u;
    if (runtime->hasFunction(0x1C6E70u)) {
        auto targetFn = runtime->lookupFunction(0x1C6E70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6C3Cu; }
        if (ctx->pc != 0x1C6C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C6E70_0x1c6e70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6C3Cu; }
        if (ctx->pc != 0x1C6C3Cu) { return; }
    }
    ctx->pc = 0x1C6C3Cu;
label_1c6c3c:
    // 0x1c6c3c: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C6C3Cu;
    {
        const bool branch_taken_0x1c6c3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6C3Cu;
            // 0x1c6c40: 0x3c010033  lui         $at, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6c3c) {
            ctx->pc = 0x1C6C48u;
            goto label_1c6c48;
        }
    }
    ctx->pc = 0x1C6C44u;
    // 0x1c6c44: 0xac205074  sw          $zero, 0x5074($at)
    ctx->pc = 0x1c6c44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20596), GPR_U32(ctx, 0));
label_1c6c48:
    // 0x1c6c48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6c48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6c4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6C4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6C4Cu;
            // 0x1c6c50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6A50u: goto label_1c6a50;
            case 0x1C6A90u: goto label_1c6a90;
            case 0x1C6AB4u: goto label_1c6ab4;
            case 0x1C6ABCu: goto label_1c6abc;
            case 0x1C6B24u: goto label_1c6b24;
            case 0x1C6B68u: goto label_1c6b68;
            case 0x1C6B9Cu: goto label_1c6b9c;
            case 0x1C6C3Cu: goto label_1c6c3c;
            case 0x1C6C48u: goto label_1c6c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6C54u;
    // 0x1c6c54: 0x0  nop
    ctx->pc = 0x1c6c54u;
    // NOP
    // 0x1c6c58: 0x0  nop
    ctx->pc = 0x1c6c58u;
    // NOP
    // 0x1c6c5c: 0x0  nop
    ctx->pc = 0x1c6c5cu;
    // NOP
    // 0x1c6c60: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6A50u: goto label_1c6a50;
            case 0x1C6A90u: goto label_1c6a90;
            case 0x1C6AB4u: goto label_1c6ab4;
            case 0x1C6ABCu: goto label_1c6abc;
            case 0x1C6B24u: goto label_1c6b24;
            case 0x1C6B68u: goto label_1c6b68;
            case 0x1C6B9Cu: goto label_1c6b9c;
            case 0x1C6C3Cu: goto label_1c6c3c;
            case 0x1C6C48u: goto label_1c6c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6C68u;
    // 0x1c6c68: 0x0  nop
    ctx->pc = 0x1c6c68u;
    // NOP
    // 0x1c6c6c: 0x0  nop
    ctx->pc = 0x1c6c6cu;
    // NOP
    // 0x1c6c70: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6C70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6A50u: goto label_1c6a50;
            case 0x1C6A90u: goto label_1c6a90;
            case 0x1C6AB4u: goto label_1c6ab4;
            case 0x1C6ABCu: goto label_1c6abc;
            case 0x1C6B24u: goto label_1c6b24;
            case 0x1C6B68u: goto label_1c6b68;
            case 0x1C6B9Cu: goto label_1c6b9c;
            case 0x1C6C3Cu: goto label_1c6c3c;
            case 0x1C6C48u: goto label_1c6c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6C78u;
    // 0x1c6c78: 0x0  nop
    ctx->pc = 0x1c6c78u;
    // NOP
    // 0x1c6c7c: 0x0  nop
    ctx->pc = 0x1c6c7cu;
    // NOP
    // 0x1c6c80: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6C80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6A50u: goto label_1c6a50;
            case 0x1C6A90u: goto label_1c6a90;
            case 0x1C6AB4u: goto label_1c6ab4;
            case 0x1C6ABCu: goto label_1c6abc;
            case 0x1C6B24u: goto label_1c6b24;
            case 0x1C6B68u: goto label_1c6b68;
            case 0x1C6B9Cu: goto label_1c6b9c;
            case 0x1C6C3Cu: goto label_1c6c3c;
            case 0x1C6C48u: goto label_1c6c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6C88u;
    // 0x1c6c88: 0x0  nop
    ctx->pc = 0x1c6c88u;
    // NOP
    // 0x1c6c8c: 0x0  nop
    ctx->pc = 0x1c6c8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
