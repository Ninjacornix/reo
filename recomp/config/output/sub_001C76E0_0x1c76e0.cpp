#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C76E0
// Address: 0x1c76e0 - 0x1c7a80
void sub_001C76E0_0x1c76e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C76E0_0x1c76e0");
#endif

    switch (ctx->pc) {
        case 0x1c7714u: goto label_1c7714;
        case 0x1c7734u: goto label_1c7734;
        case 0x1c774cu: goto label_1c774c;
        case 0x1c77c4u: goto label_1c77c4;
        case 0x1c77d8u: goto label_1c77d8;
        case 0x1c77e8u: goto label_1c77e8;
        case 0x1c7840u: goto label_1c7840;
        case 0x1c7848u: goto label_1c7848;
        case 0x1c787cu: goto label_1c787c;
        case 0x1c788cu: goto label_1c788c;
        case 0x1c7910u: goto label_1c7910;
        case 0x1c7940u: goto label_1c7940;
        case 0x1c7948u: goto label_1c7948;
        case 0x1c795cu: goto label_1c795c;
        case 0x1c796cu: goto label_1c796c;
        case 0x1c79a4u: goto label_1c79a4;
        case 0x1c79b8u: goto label_1c79b8;
        case 0x1c7a30u: goto label_1c7a30;
        case 0x1c7a48u: goto label_1c7a48;
        default: break;
    }

    ctx->pc = 0x1c76e0u;

    // 0x1c76e0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1c76e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1c76e4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c76e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c76e8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c76e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c76ec: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1c76ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1c76f0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c76f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c76f4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c76f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c76f8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c76f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c76fc: 0x90245056  lbu         $a0, 0x5056($at)
    ctx->pc = 0x1c76fcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20566)));
    // 0x1c7700: 0x3c100033  lui         $s0, 0x33
    ctx->pc = 0x1c7700u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)51 << 16));
    // 0x1c7704: 0x108300d6  beq         $a0, $v1, . + 4 + (0xD6 << 2)
    ctx->pc = 0x1C7704u;
    {
        const bool branch_taken_0x1c7704 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C7708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7704u;
            // 0x1c7708: 0x26105030  addiu       $s0, $s0, 0x5030 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 20528));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7704) {
            ctx->pc = 0x1C7A60u;
            goto label_1c7a60;
        }
    }
    ctx->pc = 0x1C770Cu;
    // 0x1c770c: 0xc071f2c  jal         func_1C7CB0
    ctx->pc = 0x1C770Cu;
    SET_GPR_U32(ctx, 31, 0x1C7714u);
    ctx->pc = 0x1C7710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C770Cu;
            // 0x1c7710: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CB0u;
    if (runtime->hasFunction(0x1C7CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7714u; }
        if (ctx->pc != 0x1C7714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CB0_0x1c7cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7714u; }
        if (ctx->pc != 0x1C7714u) { return; }
    }
    ctx->pc = 0x1C7714u;
label_1c7714:
    // 0x1c7714: 0x104000a0  beqz        $v0, . + 4 + (0xA0 << 2)
    ctx->pc = 0x1C7714u;
    {
        const bool branch_taken_0x1c7714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7714) {
            ctx->pc = 0x1C7998u;
            goto label_1c7998;
        }
    }
    ctx->pc = 0x1C771Cu;
    // 0x1c771c: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1c771cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1c7720: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x1c7720u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1c7724: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1c7724u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c7728: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1c7728u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1c772c: 0xc073050  jal         func_1CC140
    ctx->pc = 0x1C772Cu;
    SET_GPR_U32(ctx, 31, 0x1C7734u);
    ctx->pc = 0x1C7730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C772Cu;
            // 0x1c7730: 0x622021  addu        $a0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC140u;
    if (runtime->hasFunction(0x1CC140u)) {
        auto targetFn = runtime->lookupFunction(0x1CC140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7734u; }
        if (ctx->pc != 0x1C7734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC140_0x1cc140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7734u; }
        if (ctx->pc != 0x1C7734u) { return; }
    }
    ctx->pc = 0x1C7734u;
label_1c7734:
    // 0x1c7734: 0x4410014  bgez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1C7734u;
    {
        const bool branch_taken_0x1c7734 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1c7734) {
            ctx->pc = 0x1C7788u;
            goto label_1c7788;
        }
    }
    ctx->pc = 0x1C773Cu;
    // 0x1c773c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1c773cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c7740: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c7740u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7744: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C7744u;
    SET_GPR_U32(ctx, 31, 0x1C774Cu);
    ctx->pc = 0x1C7748u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7744u;
            // 0x1c7748: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C774Cu; }
        if (ctx->pc != 0x1C774Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C774Cu; }
        if (ctx->pc != 0x1C774Cu) { return; }
    }
    ctx->pc = 0x1C774Cu;
label_1c774c:
    // 0x1c774c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c774cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7750: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c7750u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c7754: 0x942451b8  lhu         $a0, 0x51B8($at)
    ctx->pc = 0x1c7754u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c7758: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7758u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c775c: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c775cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c7760: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c7760u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c7764: 0x8c235f58  lw          $v1, 0x5F58($at)
    ctx->pc = 0x1c7764u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c7768: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1c7768u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c776c: 0x146000bc  bnez        $v1, . + 4 + (0xBC << 2)
    ctx->pc = 0x1C776Cu;
    {
        const bool branch_taken_0x1c776c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c776c) {
            ctx->pc = 0x1C7A60u;
            goto label_1c7a60;
        }
    }
    ctx->pc = 0x1C7774u;
    // 0x1c7774: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1c7774u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c7778: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7778u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c777c: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c777cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c7780: 0x100000b8  b           . + 4 + (0xB8 << 2)
    ctx->pc = 0x1C7780u;
    {
        const bool branch_taken_0x1c7780 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7780u;
            // 0x1c7784: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7780) {
            ctx->pc = 0x1C7A64u;
            goto label_1c7a64;
        }
    }
    ctx->pc = 0x1C7788u;
label_1c7788:
    // 0x1c7788: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1c7788u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c778c: 0x3c030033  lui         $v1, 0x33
    ctx->pc = 0x1c778cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)51 << 16));
    // 0x1c7790: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7790u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7794: 0x246350a4  addiu       $v1, $v1, 0x50A4
    ctx->pc = 0x1c7794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20644));
    // 0x1c7798: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1c7798u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1c779c: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x1c779cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x1c77a0: 0xc420506c  lwc1        $f0, 0x506C($at)
    ctx->pc = 0x1c77a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20588)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c77a4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c77a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c77a8: 0x90245054  lbu         $a0, 0x5054($at)
    ctx->pc = 0x1c77a8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20564)));
    // 0x1c77ac: 0x41100  sll         $v0, $a0, 4
    ctx->pc = 0x1c77acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1c77b0: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1c77b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1c77b4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1c77b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1c77b8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1c77b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c77bc: 0x10000076  b           . + 4 + (0x76 << 2)
    ctx->pc = 0x1C77BCu;
    {
        const bool branch_taken_0x1c77bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C77C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C77BCu;
            // 0x1c77c0: 0xe4400000  swc1        $f0, 0x0($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c77bc) {
            ctx->pc = 0x1C7998u;
            goto label_1c7998;
        }
    }
    ctx->pc = 0x1C77C4u;
label_1c77c4:
    // 0x1c77c4: 0x6410018  bgez        $s2, . + 4 + (0x18 << 2)
    ctx->pc = 0x1C77C4u;
    {
        const bool branch_taken_0x1c77c4 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x1C77C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C77C4u;
            // 0x1c77c8: 0x2a430002  slti        $v1, $s2, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c77c4) {
            ctx->pc = 0x1C7828u;
            goto label_1c7828;
        }
    }
    ctx->pc = 0x1C77CCu;
    // 0x1c77cc: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c77ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c77d0: 0xc071f00  jal         func_1C7C00
    ctx->pc = 0x1C77D0u;
    SET_GPR_U32(ctx, 31, 0x1C77D8u);
    ctx->pc = 0x1C77D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C77D0u;
            // 0x1c77d4: 0x24845030  addiu       $a0, $a0, 0x5030 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C00u;
    if (runtime->hasFunction(0x1C7C00u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C77D8u; }
        if (ctx->pc != 0x1C77D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C00_0x1c7c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C77D8u; }
        if (ctx->pc != 0x1C77D8u) { return; }
    }
    ctx->pc = 0x1C77D8u;
label_1c77d8:
    // 0x1c77d8: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1c77d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c77dc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c77dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c77e0: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C77E0u;
    SET_GPR_U32(ctx, 31, 0x1C77E8u);
    ctx->pc = 0x1C77E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C77E0u;
            // 0x1c77e4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C77E8u; }
        if (ctx->pc != 0x1C77E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C77E8u; }
        if (ctx->pc != 0x1C77E8u) { return; }
    }
    ctx->pc = 0x1C77E8u;
label_1c77e8:
    // 0x1c77e8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c77e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c77ec: 0x24030015  addiu       $v1, $zero, 0x15
    ctx->pc = 0x1c77ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1c77f0: 0x942451b8  lhu         $a0, 0x51B8($at)
    ctx->pc = 0x1c77f0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c77f4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c77f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c77f8: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c77f8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c77fc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c77fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c7800: 0x8c235f58  lw          $v1, 0x5F58($at)
    ctx->pc = 0x1c7800u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c7804: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1c7804u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c7808: 0x14600095  bnez        $v1, . + 4 + (0x95 << 2)
    ctx->pc = 0x1C7808u;
    {
        const bool branch_taken_0x1c7808 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c7808) {
            ctx->pc = 0x1C7A60u;
            goto label_1c7a60;
        }
    }
    ctx->pc = 0x1C7810u;
    // 0x1c7810: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1c7810u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c7814: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7814u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7818: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c7818u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c781c: 0x10000090  b           . + 4 + (0x90 << 2)
    ctx->pc = 0x1C781Cu;
    {
        const bool branch_taken_0x1c781c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c781c) {
            ctx->pc = 0x1C7A60u;
            goto label_1c7a60;
        }
    }
    ctx->pc = 0x1C7824u;
    // 0x1c7824: 0x2a430002  slti        $v1, $s2, 0x2
    ctx->pc = 0x1c7824u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)2) ? 1 : 0);
label_1c7828:
    // 0x1c7828: 0x14600061  bnez        $v1, . + 4 + (0x61 << 2)
    ctx->pc = 0x1C7828u;
    {
        const bool branch_taken_0x1c7828 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C782Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7828u;
            // 0x1c782c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7828) {
            ctx->pc = 0x1C79B0u;
            goto label_1c79b0;
        }
    }
    ctx->pc = 0x1C7830u;
    // 0x1c7830: 0x3c050033  lui         $a1, 0x33
    ctx->pc = 0x1c7830u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)51 << 16));
    // 0x1c7834: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1c7834u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1c7838: 0xc071f1c  jal         func_1C7C70
    ctx->pc = 0x1C7838u;
    SET_GPR_U32(ctx, 31, 0x1C7840u);
    ctx->pc = 0x1C783Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7838u;
            // 0x1c783c: 0x24a55030  addiu       $a1, $a1, 0x5030 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C70u;
    if (runtime->hasFunction(0x1C7C70u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7840u; }
        if (ctx->pc != 0x1C7840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C70_0x1c7c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7840u; }
        if (ctx->pc != 0x1C7840u) { return; }
    }
    ctx->pc = 0x1C7840u;
label_1c7840:
    // 0x1c7840: 0xc071f5c  jal         func_1C7D70
    ctx->pc = 0x1C7840u;
    SET_GPR_U32(ctx, 31, 0x1C7848u);
    ctx->pc = 0x1C7844u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7840u;
            // 0x1c7844: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D70u;
    if (runtime->hasFunction(0x1C7D70u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7848u; }
        if (ctx->pc != 0x1C7848u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D70_0x1c7d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7848u; }
        if (ctx->pc != 0x1C7848u) { return; }
    }
    ctx->pc = 0x1C7848u;
label_1c7848:
    // 0x1c7848: 0x3045ffff  andi        $a1, $v0, 0xFFFF
    ctx->pc = 0x1c7848u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1c784c: 0x51b03  sra         $v1, $a1, 12
    ctx->pc = 0x1c784cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 5), 12));
    // 0x1c7850: 0x3064000f  andi        $a0, $v1, 0xF
    ctx->pc = 0x1c7850u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x1c7854: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C7854u;
    {
        const bool branch_taken_0x1c7854 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1C7858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7854u;
            // 0x1c7858: 0x30b10fff  andi        $s1, $a1, 0xFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4095);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7854) {
            ctx->pc = 0x1C7870u;
            goto label_1c7870;
        }
    }
    ctx->pc = 0x1C785Cu;
    // 0x1c785c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c785cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7860: 0x90235055  lbu         $v1, 0x5055($at)
    ctx->pc = 0x1c7860u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20565)));
    // 0x1c7864: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1c7864u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c7868: 0x14600018  bnez        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1C7868u;
    {
        const bool branch_taken_0x1c7868 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C786Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7868u;
            // 0x1c786c: 0x3223ffff  andi        $v1, $s1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7868) {
            ctx->pc = 0x1C78CCu;
            goto label_1c78cc;
        }
    }
    ctx->pc = 0x1C7870u;
label_1c7870:
    // 0x1c7870: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7870u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7874: 0xc071f00  jal         func_1C7C00
    ctx->pc = 0x1C7874u;
    SET_GPR_U32(ctx, 31, 0x1C787Cu);
    ctx->pc = 0x1C7878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7874u;
            // 0x1c7878: 0x24845030  addiu       $a0, $a0, 0x5030 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C00u;
    if (runtime->hasFunction(0x1C7C00u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C787Cu; }
        if (ctx->pc != 0x1C787Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C00_0x1c7c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C787Cu; }
        if (ctx->pc != 0x1C787Cu) { return; }
    }
    ctx->pc = 0x1C787Cu;
label_1c787c:
    // 0x1c787c: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1c787cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c7880: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c7880u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7884: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C7884u;
    SET_GPR_U32(ctx, 31, 0x1C788Cu);
    ctx->pc = 0x1C7888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7884u;
            // 0x1c7888: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C788Cu; }
        if (ctx->pc != 0x1C788Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C788Cu; }
        if (ctx->pc != 0x1C788Cu) { return; }
    }
    ctx->pc = 0x1C788Cu;
label_1c788c:
    // 0x1c788c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c788cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7890: 0x24030015  addiu       $v1, $zero, 0x15
    ctx->pc = 0x1c7890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1c7894: 0x942451b8  lhu         $a0, 0x51B8($at)
    ctx->pc = 0x1c7894u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c7898: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7898u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c789c: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c789cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c78a0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c78a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c78a4: 0x8c235f58  lw          $v1, 0x5F58($at)
    ctx->pc = 0x1c78a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c78a8: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1c78a8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c78ac: 0x1460006c  bnez        $v1, . + 4 + (0x6C << 2)
    ctx->pc = 0x1C78ACu;
    {
        const bool branch_taken_0x1c78ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c78ac) {
            ctx->pc = 0x1C7A60u;
            goto label_1c7a60;
        }
    }
    ctx->pc = 0x1C78B4u;
    // 0x1c78b4: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1c78b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c78b8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c78b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c78bc: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c78bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c78c0: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x1C78C0u;
    {
        const bool branch_taken_0x1c78c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c78c0) {
            ctx->pc = 0x1C7A60u;
            goto label_1c7a60;
        }
    }
    ctx->pc = 0x1C78C8u;
    // 0x1c78c8: 0x3223ffff  andi        $v1, $s1, 0xFFFF
    ctx->pc = 0x1c78c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
label_1c78cc:
    // 0x1c78cc: 0x24700002  addiu       $s0, $v1, 0x2
    ctx->pc = 0x1c78ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1c78d0: 0x250182a  slt         $v1, $s2, $s0
    ctx->pc = 0x1c78d0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1c78d4: 0x14600035  bnez        $v1, . + 4 + (0x35 << 2)
    ctx->pc = 0x1C78D4u;
    {
        const bool branch_taken_0x1c78d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c78d4) {
            ctx->pc = 0x1C79ACu;
            goto label_1c79ac;
        }
    }
    ctx->pc = 0x1C78DCu;
    // 0x1c78dc: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x1c78dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1c78e0: 0x3c020033  lui         $v0, 0x33
    ctx->pc = 0x1c78e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51 << 16));
    // 0x1c78e4: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1c78e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1c78e8: 0x24425050  addiu       $v0, $v0, 0x5050
    ctx->pc = 0x1c78e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20560));
    // 0x1c78ec: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c78ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c78f0: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1c78f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c78f4: 0x9062004c  lbu         $v0, 0x4C($v1)
    ctx->pc = 0x1c78f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 76)));
    // 0x1c78f8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C78F8u;
    {
        const bool branch_taken_0x1c78f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c78f8) {
            ctx->pc = 0x1C7918u;
            goto label_1c7918;
        }
    }
    ctx->pc = 0x1C7900u;
    // 0x1c7900: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7900u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7904: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1c7904u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7908: 0xc071f60  jal         func_1C7D80
    ctx->pc = 0x1C7908u;
    SET_GPR_U32(ctx, 31, 0x1C7910u);
    ctx->pc = 0x1C790Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7908u;
            // 0x1c790c: 0x24845030  addiu       $a0, $a0, 0x5030 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D80u;
    if (runtime->hasFunction(0x1C7D80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7910u; }
        if (ctx->pc != 0x1C7910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D80_0x1c7d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7910u; }
        if (ctx->pc != 0x1C7910u) { return; }
    }
    ctx->pc = 0x1C7910u;
label_1c7910:
    // 0x1c7910: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1C7910u;
    {
        const bool branch_taken_0x1c7910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7910) {
            ctx->pc = 0x1C7998u;
            goto label_1c7998;
        }
    }
    ctx->pc = 0x1C7918u;
label_1c7918:
    // 0x1c7918: 0x8c620050  lw          $v0, 0x50($v1)
    ctx->pc = 0x1c7918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 80)));
    // 0x1c791c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c791cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7920: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c7920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c7924: 0xac620050  sw          $v0, 0x50($v1)
    ctx->pc = 0x1c7924u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 80), GPR_U32(ctx, 2));
    // 0x1c7928: 0xc420506c  lwc1        $f0, 0x506C($at)
    ctx->pc = 0x1c7928u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20588)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c792c: 0x1220000b  beqz        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x1C792Cu;
    {
        const bool branch_taken_0x1c792c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C792Cu;
            // 0x1c7930: 0xe4600054  swc1        $f0, 0x54($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 84), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c792c) {
            ctx->pc = 0x1C795Cu;
            goto label_1c795c;
        }
    }
    ctx->pc = 0x1C7934u;
    // 0x1c7934: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7934u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7938: 0xc071f54  jal         func_1C7D50
    ctx->pc = 0x1C7938u;
    SET_GPR_U32(ctx, 31, 0x1C7940u);
    ctx->pc = 0x1C793Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7938u;
            // 0x1c793c: 0x24842f90  addiu       $a0, $a0, 0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D50u;
    if (runtime->hasFunction(0x1C7D50u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7940u; }
        if (ctx->pc != 0x1C7940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D50_0x1c7d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7940u; }
        if (ctx->pc != 0x1C7940u) { return; }
    }
    ctx->pc = 0x1C7940u;
label_1c7940:
    // 0x1c7940: 0xc071f30  jal         func_1C7CC0
    ctx->pc = 0x1C7940u;
    SET_GPR_U32(ctx, 31, 0x1C7948u);
    ctx->pc = 0x1C7944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7940u;
            // 0x1c7944: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CC0u;
    if (runtime->hasFunction(0x1C7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7948u; }
        if (ctx->pc != 0x1C7948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CC0_0x1c7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7948u; }
        if (ctx->pc != 0x1C7948u) { return; }
    }
    ctx->pc = 0x1C7948u;
label_1c7948:
    // 0x1c7948: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7948u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c794c: 0x3226ffff  andi        $a2, $s1, 0xFFFF
    ctx->pc = 0x1c794cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x1c7950: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c7950u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7954: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C7954u;
    SET_GPR_U32(ctx, 31, 0x1C795Cu);
    ctx->pc = 0x1C7958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7954u;
            // 0x1c7958: 0x24842f90  addiu       $a0, $a0, 0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C795Cu; }
        if (ctx->pc != 0x1C795Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C795Cu; }
        if (ctx->pc != 0x1C795Cu) { return; }
    }
    ctx->pc = 0x1C795Cu;
label_1c795c:
    // 0x1c795c: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c795cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7960: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1c7960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7964: 0xc071f60  jal         func_1C7D80
    ctx->pc = 0x1C7964u;
    SET_GPR_U32(ctx, 31, 0x1C796Cu);
    ctx->pc = 0x1C7968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7964u;
            // 0x1c7968: 0x24845030  addiu       $a0, $a0, 0x5030 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D80u;
    if (runtime->hasFunction(0x1C7D80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C796Cu; }
        if (ctx->pc != 0x1C796Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D80_0x1c7d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C796Cu; }
        if (ctx->pc != 0x1C796Cu) { return; }
    }
    ctx->pc = 0x1C796Cu;
label_1c796c:
    // 0x1c796c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c796cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7970: 0x3203ffff  andi        $v1, $s0, 0xFFFF
    ctx->pc = 0x1c7970u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1c7974: 0x8c245090  lw          $a0, 0x5090($at)
    ctx->pc = 0x1c7974u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20624)));
    // 0x1c7978: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7978u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c797c: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x1c797cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1c7980: 0x94225096  lhu         $v0, 0x5096($at)
    ctx->pc = 0x1c7980u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20630)));
    // 0x1c7984: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7984u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7988: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c7988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c798c: 0xac245090  sw          $a0, 0x5090($at)
    ctx->pc = 0x1c798cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20624), GPR_U32(ctx, 4));
    // 0x1c7990: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7990u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7994: 0xa4225096  sh          $v0, 0x5096($at)
    ctx->pc = 0x1c7994u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 20630), (uint16_t)GPR_U32(ctx, 2));
label_1c7998:
    // 0x1c7998: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7998u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c799c: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1C799Cu;
    SET_GPR_U32(ctx, 31, 0x1C79A4u);
    ctx->pc = 0x1C79A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C799Cu;
            // 0x1c79a0: 0x24845030  addiu       $a0, $a0, 0x5030 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C79A4u; }
        if (ctx->pc != 0x1C79A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C79A4u; }
        if (ctx->pc != 0x1C79A4u) { return; }
    }
    ctx->pc = 0x1C79A4u;
label_1c79a4:
    // 0x1c79a4: 0x1440ff87  bnez        $v0, . + 4 + (-0x79 << 2)
    ctx->pc = 0x1C79A4u;
    {
        const bool branch_taken_0x1c79a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C79A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C79A4u;
            // 0x1c79a8: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c79a4) {
            ctx->pc = 0x1C77C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c77c4;
        }
    }
    ctx->pc = 0x1C79ACu;
label_1c79ac:
    // 0x1c79ac: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1c79acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c79b0:
    // 0x1c79b0: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1C79B0u;
    {
        const bool branch_taken_0x1c79b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c79b0) {
            ctx->pc = 0x1C7A4Cu;
            goto label_1c7a4c;
        }
    }
    ctx->pc = 0x1C79B8u;
label_1c79b8:
    // 0x1c79b8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c79b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c79bc: 0x90235054  lbu         $v1, 0x5054($at)
    ctx->pc = 0x1c79bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20564)));
    // 0x1c79c0: 0x12030021  beq         $s0, $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x1C79C0u;
    {
        const bool branch_taken_0x1c79c0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c79c0) {
            ctx->pc = 0x1C7A48u;
            goto label_1c7a48;
        }
    }
    ctx->pc = 0x1C79C8u;
    // 0x1c79c8: 0x101900  sll         $v1, $s0, 4
    ctx->pc = 0x1c79c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x1c79cc: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c79ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c79d0: 0x702823  subu        $a1, $v1, $s0
    ctx->pc = 0x1c79d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1c79d4: 0x24845050  addiu       $a0, $a0, 0x5050
    ctx->pc = 0x1c79d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20560));
    // 0x1c79d8: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1c79d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1c79dc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c79dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c79e0: 0x853021  addu        $a2, $a0, $a1
    ctx->pc = 0x1c79e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1c79e4: 0x90c4004c  lbu         $a0, 0x4C($a2)
    ctx->pc = 0x1c79e4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 76)));
    // 0x1c79e8: 0x14830017  bne         $a0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1C79E8u;
    {
        const bool branch_taken_0x1c79e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1C79ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C79E8u;
            // 0x1c79ec: 0x24c5004c  addiu       $a1, $a2, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 76));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c79e8) {
            ctx->pc = 0x1C7A48u;
            goto label_1c7a48;
        }
    }
    ctx->pc = 0x1C79F0u;
    // 0x1c79f0: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c79f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c79f4: 0xc421506c  lwc1        $f1, 0x506C($at)
    ctx->pc = 0x1c79f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20588)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c79f8: 0xc4c20054  lwc1        $f2, 0x54($a2)
    ctx->pc = 0x1c79f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 84)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1c79fc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c79fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c7a00: 0xc4205f50  lwc1        $f0, 0x5F50($at)
    ctx->pc = 0x1c7a00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 24400)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c7a04: 0x46020841  sub.s       $f1, $f1, $f2
    ctx->pc = 0x1c7a04u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[2]);
    // 0x1c7a08: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1c7a08u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c7a0c: 0x4501000e  bc1t        . + 4 + (0xE << 2)
    ctx->pc = 0x1C7A0Cu;
    {
        const bool branch_taken_0x1c7a0c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1c7a0c) {
            ctx->pc = 0x1C7A48u;
            goto label_1c7a48;
        }
    }
    ctx->pc = 0x1C7A14u;
    // 0x1c7a14: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1c7a14u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c7a18: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a1c: 0x9022505f  lbu         $v0, 0x505F($at)
    ctx->pc = 0x1c7a1cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20575)));
    // 0x1c7a20: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c7a20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c7a24: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a28: 0xc071c7c  jal         func_1C71F0
    ctx->pc = 0x1C7A28u;
    SET_GPR_U32(ctx, 31, 0x1C7A30u);
    ctx->pc = 0x1C7A2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7A28u;
            // 0x1c7a2c: 0xa022505f  sb          $v0, 0x505F($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 20575), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C71F0u;
    if (runtime->hasFunction(0x1C71F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C71F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7A30u; }
        if (ctx->pc != 0x1C7A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C71F0_0x1c71f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7A30u; }
        if (ctx->pc != 0x1C7A30u) { return; }
    }
    ctx->pc = 0x1C7A30u;
label_1c7a30:
    // 0x1c7a30: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a34: 0xa022505e  sb          $v0, 0x505E($at)
    ctx->pc = 0x1c7a34u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 20574), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c7a38: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a3c: 0x9025505e  lbu         $a1, 0x505E($at)
    ctx->pc = 0x1c7a3cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20574)));
    // 0x1c7a40: 0xc071ec4  jal         func_1C7B10
    ctx->pc = 0x1C7A40u;
    SET_GPR_U32(ctx, 31, 0x1C7A48u);
    ctx->pc = 0x1C7A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7A40u;
            // 0x1c7a44: 0x320400ff  andi        $a0, $s0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7B10u;
    if (runtime->hasFunction(0x1C7B10u)) {
        auto targetFn = runtime->lookupFunction(0x1C7B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7A48u; }
        if (ctx->pc != 0x1C7A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7B10_0x1c7b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7A48u; }
        if (ctx->pc != 0x1C7A48u) { return; }
    }
    ctx->pc = 0x1C7A48u;
label_1c7a48:
    // 0x1c7a48: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1c7a48u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1c7a4c:
    // 0x1c7a4c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a50: 0x90235055  lbu         $v1, 0x5055($at)
    ctx->pc = 0x1c7a50u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20565)));
    // 0x1c7a54: 0x203182a  slt         $v1, $s0, $v1
    ctx->pc = 0x1c7a54u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c7a58: 0x1460ffd7  bnez        $v1, . + 4 + (-0x29 << 2)
    ctx->pc = 0x1C7A58u;
    {
        const bool branch_taken_0x1c7a58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c7a58) {
            ctx->pc = 0x1C79B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c79b8;
        }
    }
    ctx->pc = 0x1C7A60u;
label_1c7a60:
    // 0x1c7a60: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c7a60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1c7a64:
    // 0x1c7a64: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c7a64u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c7a68: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c7a68u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c7a6c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c7a6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c7a70: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7A70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7A70u;
            // 0x1c7a74: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7714u: goto label_1c7714;
            case 0x1C7734u: goto label_1c7734;
            case 0x1C774Cu: goto label_1c774c;
            case 0x1C7788u: goto label_1c7788;
            case 0x1C77C4u: goto label_1c77c4;
            case 0x1C77D8u: goto label_1c77d8;
            case 0x1C77E8u: goto label_1c77e8;
            case 0x1C7828u: goto label_1c7828;
            case 0x1C7840u: goto label_1c7840;
            case 0x1C7848u: goto label_1c7848;
            case 0x1C7870u: goto label_1c7870;
            case 0x1C787Cu: goto label_1c787c;
            case 0x1C788Cu: goto label_1c788c;
            case 0x1C78CCu: goto label_1c78cc;
            case 0x1C7910u: goto label_1c7910;
            case 0x1C7918u: goto label_1c7918;
            case 0x1C7940u: goto label_1c7940;
            case 0x1C7948u: goto label_1c7948;
            case 0x1C795Cu: goto label_1c795c;
            case 0x1C796Cu: goto label_1c796c;
            case 0x1C7998u: goto label_1c7998;
            case 0x1C79A4u: goto label_1c79a4;
            case 0x1C79ACu: goto label_1c79ac;
            case 0x1C79B0u: goto label_1c79b0;
            case 0x1C79B8u: goto label_1c79b8;
            case 0x1C7A30u: goto label_1c7a30;
            case 0x1C7A48u: goto label_1c7a48;
            case 0x1C7A4Cu: goto label_1c7a4c;
            case 0x1C7A60u: goto label_1c7a60;
            case 0x1C7A64u: goto label_1c7a64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7A78u;
    // 0x1c7a78: 0x0  nop
    ctx->pc = 0x1c7a78u;
    // NOP
    // 0x1c7a7c: 0x0  nop
    ctx->pc = 0x1c7a7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
