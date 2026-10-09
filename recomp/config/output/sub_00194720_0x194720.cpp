#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00194720
// Address: 0x194720 - 0x194a50
void sub_00194720_0x194720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00194720_0x194720");
#endif

    switch (ctx->pc) {
        case 0x194760u: goto label_194760;
        case 0x1947b4u: goto label_1947b4;
        case 0x1947dcu: goto label_1947dc;
        case 0x1947ecu: goto label_1947ec;
        case 0x19488cu: goto label_19488c;
        case 0x1948b4u: goto label_1948b4;
        case 0x1948c4u: goto label_1948c4;
        case 0x194964u: goto label_194964;
        case 0x19498cu: goto label_19498c;
        case 0x19499cu: goto label_19499c;
        case 0x194a34u: goto label_194a34;
        default: break;
    }

    ctx->pc = 0x194720u;

    // 0x194720: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x194720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x194724: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194724u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194728: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x194728u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19472c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19472cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x194730: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x194730u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x194734: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194734u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194738: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194738u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x19473c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19473Cu;
    {
        const bool branch_taken_0x19473c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x194740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19473Cu;
            // 0x194740: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19473c) {
            ctx->pc = 0x19474Cu;
            goto label_19474c;
        }
    }
    ctx->pc = 0x194744u;
    // 0x194744: 0x100000bc  b           . + 4 + (0xBC << 2)
    ctx->pc = 0x194744u;
    {
        const bool branch_taken_0x194744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194744u;
            // 0x194748: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194744) {
            ctx->pc = 0x194A38u;
            goto label_194a38;
        }
    }
    ctx->pc = 0x19474Cu;
label_19474c:
    // 0x19474c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x19474cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x194750: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x194750u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194754: 0x2484ff30  addiu       $a0, $a0, -0xD0
    ctx->pc = 0x194754u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967088));
    // 0x194758: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194758u;
    SET_GPR_U32(ctx, 31, 0x194760u);
    ctx->pc = 0x19475Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194758u;
            // 0x19475c: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194760u; }
        if (ctx->pc != 0x194760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194760u; }
        if (ctx->pc != 0x194760u) { return; }
    }
    ctx->pc = 0x194760u;
label_194760:
    // 0x194760: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194760u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194764: 0x34028080  ori         $v0, $zero, 0x8080
    ctx->pc = 0x194764u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32896);
    // 0x194768: 0x9427fee8  lhu         $a3, -0x118($at)
    ctx->pc = 0x194768u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294967016)));
    // 0x19476c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x19476cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x194770: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194770u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194774: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x194774u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x194778: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x194778u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x19477c: 0x34428080  ori         $v0, $v0, 0x8080
    ctx->pc = 0x19477cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
    // 0x194780: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x194780u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x194784: 0x24848680  addiu       $a0, $a0, -0x7980
    ctx->pc = 0x194784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936192));
    // 0x194788: 0x2625000c  addiu       $a1, $s1, 0xC
    ctx->pc = 0x194788u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x19478c: 0x2626000e  addiu       $a2, $s1, 0xE
    ctx->pc = 0x19478cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 14));
    // 0x194790: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194790u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194794: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x194794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x194798: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x194798u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x19479c: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x19479cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1947a0: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1947a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1947a4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1947a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1947a8: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x1947a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1947ac: 0xc06628c  jal         func_198A30
    ctx->pc = 0x1947ACu;
    SET_GPR_U32(ctx, 31, 0x1947B4u);
    ctx->pc = 0x1947B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1947ACu;
            // 0x1947b0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A30u;
    if (runtime->hasFunction(0x198A30u)) {
        auto targetFn = runtime->lookupFunction(0x198A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947B4u; }
        if (ctx->pc != 0x1947B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A30_0x198a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947B4u; }
        if (ctx->pc != 0x1947B4u) { return; }
    }
    ctx->pc = 0x1947B4u;
label_1947b4:
    // 0x1947b4: 0x8622000e  lh          $v0, 0xE($s1)
    ctx->pc = 0x1947b4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 14)));
    // 0x1947b8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1947b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1947bc: 0x8623000c  lh          $v1, 0xC($s1)
    ctx->pc = 0x1947bcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1947c0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1947c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1947c4: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1947c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1947c8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1947c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1947cc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1947ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1947d0: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1947d0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1947d4: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1947D4u;
    SET_GPR_U32(ctx, 31, 0x1947DCu);
    ctx->pc = 0x1947D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1947D4u;
            // 0x1947d8: 0x86240000  lh          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947DCu; }
        if (ctx->pc != 0x1947DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947DCu; }
        if (ctx->pc != 0x1947DCu) { return; }
    }
    ctx->pc = 0x1947DCu;
label_1947dc:
    // 0x1947dc: 0x86240002  lh          $a0, 0x2($s1)
    ctx->pc = 0x1947dcu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1947e0: 0x2943c  dsll32      $s2, $v0, 16
    ctx->pc = 0x1947e0u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1947e4: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1947E4u;
    SET_GPR_U32(ctx, 31, 0x1947ECu);
    ctx->pc = 0x1947E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1947E4u;
            // 0x1947e8: 0x12943f  dsra32      $s2, $s2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 18, GPR_S64(ctx, 18) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947ECu; }
        if (ctx->pc != 0x1947ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947ECu; }
        if (ctx->pc != 0x1947ECu) { return; }
    }
    ctx->pc = 0x1947ECu;
label_1947ec:
    // 0x1947ec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1947ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1947f0: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1947f0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1947f4: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1947f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1947f8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1947f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1947fc: 0x12243c  dsll32      $a0, $s2, 16
    ctx->pc = 0x1947fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) << (32 + 16));
    // 0x194800: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x194800u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194804: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x194804u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x194808: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194808u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19480c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19480cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194810: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x194810u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194814: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194818: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194818u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x19481c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19481cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194820: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x194820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x194824: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194824u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194828: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194828u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19482c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x19482cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194830: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194830u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194834: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194834u;
    {
        const bool branch_taken_0x194834 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194834u;
            // 0x194838: 0x623025  or          $a2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194834) {
            ctx->pc = 0x19484Cu;
            goto label_19484c;
        }
    }
    ctx->pc = 0x19483Cu;
    // 0x19483c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19483cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194840: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194840u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194844: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194844u;
    {
        const bool branch_taken_0x194844 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194844u;
            // 0x194848: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194844) {
            ctx->pc = 0x194868u;
            goto label_194868;
        }
    }
    ctx->pc = 0x19484Cu;
label_19484c:
    // 0x19484c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x19484cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194850: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194850u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194854: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194854u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194858: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194858u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x19485c: 0x0  nop
    ctx->pc = 0x19485cu;
    // NOP
    // 0x194860: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194860u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194864: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194864u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194868:
    // 0x194868: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194868u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19486c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x19486cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194870: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x194870u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x194874: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194874u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194878: 0x26250010  addiu       $a1, $s1, 0x10
    ctx->pc = 0x194878u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x19487c: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x19487cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x194880: 0x26260012  addiu       $a2, $s1, 0x12
    ctx->pc = 0x194880u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 18));
    // 0x194884: 0xc06628c  jal         func_198A30
    ctx->pc = 0x194884u;
    SET_GPR_U32(ctx, 31, 0x19488Cu);
    ctx->pc = 0x194888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194884u;
            // 0x194888: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A30u;
    if (runtime->hasFunction(0x198A30u)) {
        auto targetFn = runtime->lookupFunction(0x198A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19488Cu; }
        if (ctx->pc != 0x19488Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A30_0x198a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19488Cu; }
        if (ctx->pc != 0x19488Cu) { return; }
    }
    ctx->pc = 0x19488Cu;
label_19488c:
    // 0x19488c: 0x86220012  lh          $v0, 0x12($s1)
    ctx->pc = 0x19488cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 18)));
    // 0x194890: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194890u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194894: 0x86230010  lh          $v1, 0x10($s1)
    ctx->pc = 0x194894u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x194898: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194898u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19489c: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x19489cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1948a0: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1948a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1948a4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1948a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1948a8: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x1948a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x1948ac: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1948ACu;
    SET_GPR_U32(ctx, 31, 0x1948B4u);
    ctx->pc = 0x1948B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1948ACu;
            // 0x1948b0: 0x86240004  lh          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948B4u; }
        if (ctx->pc != 0x1948B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948B4u; }
        if (ctx->pc != 0x1948B4u) { return; }
    }
    ctx->pc = 0x1948B4u;
label_1948b4:
    // 0x1948b4: 0x86240006  lh          $a0, 0x6($s1)
    ctx->pc = 0x1948b4u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 6)));
    // 0x1948b8: 0x2943c  dsll32      $s2, $v0, 16
    ctx->pc = 0x1948b8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1948bc: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1948BCu;
    SET_GPR_U32(ctx, 31, 0x1948C4u);
    ctx->pc = 0x1948C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1948BCu;
            // 0x1948c0: 0x12943f  dsra32      $s2, $s2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 18, GPR_S64(ctx, 18) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948C4u; }
        if (ctx->pc != 0x1948C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948C4u; }
        if (ctx->pc != 0x1948C4u) { return; }
    }
    ctx->pc = 0x1948C4u;
label_1948c4:
    // 0x1948c4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1948c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1948c8: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1948c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1948cc: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1948ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1948d0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1948d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1948d4: 0x12243c  dsll32      $a0, $s2, 16
    ctx->pc = 0x1948d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) << (32 + 16));
    // 0x1948d8: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1948d8u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1948dc: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1948dcu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1948e0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1948e0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1948e4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1948e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1948e8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1948e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1948ec: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1948ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1948f0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1948f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1948f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1948f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1948f8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1948f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1948fc: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1948fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194900: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194900u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194904: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194904u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194908: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194908u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x19490c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x19490Cu;
    {
        const bool branch_taken_0x19490c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19490Cu;
            // 0x194910: 0x623025  or          $a2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19490c) {
            ctx->pc = 0x194924u;
            goto label_194924;
        }
    }
    ctx->pc = 0x194914u;
    // 0x194914: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194914u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194918: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194918u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x19491c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19491Cu;
    {
        const bool branch_taken_0x19491c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19491Cu;
            // 0x194920: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19491c) {
            ctx->pc = 0x194940u;
            goto label_194940;
        }
    }
    ctx->pc = 0x194924u;
label_194924:
    // 0x194924: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194924u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194928: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194928u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x19492c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19492cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194930: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194930u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194934: 0x0  nop
    ctx->pc = 0x194934u;
    // NOP
    // 0x194938: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194938u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19493c: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x19493cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194940:
    // 0x194940: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194940u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194944: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194944u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194948: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x194948u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19494c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19494cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194950: 0x26250014  addiu       $a1, $s1, 0x14
    ctx->pc = 0x194950u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x194954: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x194954u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x194958: 0x26260016  addiu       $a2, $s1, 0x16
    ctx->pc = 0x194958u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 22));
    // 0x19495c: 0xc06628c  jal         func_198A30
    ctx->pc = 0x19495Cu;
    SET_GPR_U32(ctx, 31, 0x194964u);
    ctx->pc = 0x194960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19495Cu;
            // 0x194960: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A30u;
    if (runtime->hasFunction(0x198A30u)) {
        auto targetFn = runtime->lookupFunction(0x198A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194964u; }
        if (ctx->pc != 0x194964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A30_0x198a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194964u; }
        if (ctx->pc != 0x194964u) { return; }
    }
    ctx->pc = 0x194964u;
label_194964:
    // 0x194964: 0x86220016  lh          $v0, 0x16($s1)
    ctx->pc = 0x194964u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 22)));
    // 0x194968: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194968u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19496c: 0x86230014  lh          $v1, 0x14($s1)
    ctx->pc = 0x19496cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x194970: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194970u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194974: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194974u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194978: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194978u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19497c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x19497cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194980: 0xfc220050  sd          $v0, 0x50($at)
    ctx->pc = 0x194980u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 80), GPR_U64(ctx, 2));
    // 0x194984: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194984u;
    SET_GPR_U32(ctx, 31, 0x19498Cu);
    ctx->pc = 0x194988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194984u;
            // 0x194988: 0x86240008  lh          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19498Cu; }
        if (ctx->pc != 0x19498Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19498Cu; }
        if (ctx->pc != 0x19498Cu) { return; }
    }
    ctx->pc = 0x19498Cu;
label_19498c:
    // 0x19498c: 0x8624000a  lh          $a0, 0xA($s1)
    ctx->pc = 0x19498cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x194990: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x194990u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194994: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194994u;
    SET_GPR_U32(ctx, 31, 0x19499Cu);
    ctx->pc = 0x194998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194994u;
            // 0x194998: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19499Cu; }
        if (ctx->pc != 0x19499Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19499Cu; }
        if (ctx->pc != 0x19499Cu) { return; }
    }
    ctx->pc = 0x19499Cu;
label_19499c:
    // 0x19499c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19499cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1949a0: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1949a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1949a4: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1949a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1949a8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1949a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1949ac: 0x10243c  dsll32      $a0, $s0, 16
    ctx->pc = 0x1949acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1949b0: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1949b0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1949b4: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1949b4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1949b8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1949b8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1949bc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1949bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1949c0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1949c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1949c4: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1949c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1949c8: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1949c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1949cc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1949ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1949d0: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1949d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1949d4: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1949d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1949d8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1949d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1949dc: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1949dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1949e0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1949e0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1949e4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1949E4u;
    {
        const bool branch_taken_0x1949e4 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1949E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1949E4u;
            // 0x1949e8: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1949e4) {
            ctx->pc = 0x1949FCu;
            goto label_1949fc;
        }
    }
    ctx->pc = 0x1949ECu;
    // 0x1949ec: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1949ecu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1949f0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1949f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1949f4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1949F4u;
    {
        const bool branch_taken_0x1949f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1949F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1949F4u;
            // 0x1949f8: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1949f4) {
            ctx->pc = 0x194A18u;
            goto label_194a18;
        }
    }
    ctx->pc = 0x1949FCu;
label_1949fc:
    // 0x1949fc: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1949fcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194a00: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194a00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194a04: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194a04u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194a08: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194a08u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194a0c: 0x0  nop
    ctx->pc = 0x194a0cu;
    // NOP
    // 0x194a10: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194a10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194a14: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194a18:
    // 0x194a18: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194a18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194a1c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194a20: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194a20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194a24: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194a28: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x194a28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194a2c: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194A2Cu;
    SET_GPR_U32(ctx, 31, 0x194A34u);
    ctx->pc = 0x194A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194A2Cu;
            // 0x194a30: 0xfc220058  sd          $v0, 0x58($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 88), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A34u; }
        if (ctx->pc != 0x194A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A34u; }
        if (ctx->pc != 0x194A34u) { return; }
    }
    ctx->pc = 0x194A34u;
label_194a34:
    // 0x194a34: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194a34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194a38:
    // 0x194a38: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x194a38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x194a3c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x194a3cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194a40: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x194a40u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194a44: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x194a44u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194a48: 0x3e00008  jr          $ra
    ctx->pc = 0x194A48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194A48u;
            // 0x194a4c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194A50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
