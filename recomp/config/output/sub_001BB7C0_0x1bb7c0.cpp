#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB7C0
// Address: 0x1bb7c0 - 0x1bb8b0
void sub_001BB7C0_0x1bb7c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB7C0_0x1bb7c0");
#endif

    switch (ctx->pc) {
        case 0x1bb7e0u: goto label_1bb7e0;
        case 0x1bb854u: goto label_1bb854;
        case 0x1bb87cu: goto label_1bb87c;
        case 0x1bb888u: goto label_1bb888;
        case 0x1bb894u: goto label_1bb894;
        default: break;
    }

    ctx->pc = 0x1bb7c0u;

    // 0x1bb7c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bb7c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bb7c4: 0x24040058  addiu       $a0, $zero, 0x58
    ctx->pc = 0x1bb7c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
    // 0x1bb7c8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1bb7c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1bb7cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bb7ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bb7d0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bb7d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bb7d4: 0x3c100031  lui         $s0, 0x31
    ctx->pc = 0x1bb7d4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49 << 16));
    // 0x1bb7d8: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1BB7D8u;
    SET_GPR_U32(ctx, 31, 0x1BB7E0u);
    ctx->pc = 0x1BB7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB7D8u;
            // 0x1bb7dc: 0x26106650  addiu       $s0, $s0, 0x6650 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 26192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB7E0u; }
        if (ctx->pc != 0x1BB7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB7E0u; }
        if (ctx->pc != 0x1BB7E0u) { return; }
    }
    ctx->pc = 0x1BB7E0u;
label_1bb7e0:
    // 0x1bb7e0: 0x1440002c  bnez        $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1BB7E0u;
    {
        const bool branch_taken_0x1bb7e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB7E0u;
            // 0x1bb7e4: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb7e0) {
            ctx->pc = 0x1BB894u;
            goto label_1bb894;
        }
    }
    ctx->pc = 0x1BB7E8u;
    // 0x1bb7e8: 0x8c236654  lw          $v1, 0x6654($at)
    ctx->pc = 0x1bb7e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26196)));
    // 0x1bb7ec: 0x10600029  beqz        $v1, . + 4 + (0x29 << 2)
    ctx->pc = 0x1BB7ECu;
    {
        const bool branch_taken_0x1bb7ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb7ec) {
            ctx->pc = 0x1BB894u;
            goto label_1bb894;
        }
    }
    ctx->pc = 0x1BB7F4u;
    // 0x1bb7f4: 0xc601000c  lwc1        $f1, 0xC($s0)
    ctx->pc = 0x1bb7f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1bb7f8: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x1bb7f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x1bb7fc: 0x44831000  mtc1        $v1, $f2
    ctx->pc = 0x1bb7fcu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1bb800: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1bb800u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1bb804: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1bb804u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb808: 0x0  nop
    ctx->pc = 0x1bb808u;
    // NOP
    // 0x1bb80c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x1bb80cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x1bb810: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1bb810u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1bb814: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB814u;
    {
        const bool branch_taken_0x1bb814 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1bb814) {
            ctx->pc = 0x1BB82Cu;
            goto label_1bb82c;
        }
    }
    ctx->pc = 0x1BB81Cu;
    // 0x1bb81c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1bb81cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1bb820: 0x44110800  mfc1        $s1, $f1
    ctx->pc = 0x1bb820u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 17, bits); }
    // 0x1bb824: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BB824u;
    {
        const bool branch_taken_0x1bb824 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb824) {
            ctx->pc = 0x1BB844u;
            goto label_1bb844;
        }
    }
    ctx->pc = 0x1BB82Cu;
label_1bb82c:
    // 0x1bb82c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1bb82cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1bb830: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1bb830u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1bb834: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1bb834u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1bb838: 0x44110800  mfc1        $s1, $f1
    ctx->pc = 0x1bb838u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 17, bits); }
    // 0x1bb83c: 0x0  nop
    ctx->pc = 0x1bb83cu;
    // NOP
    // 0x1bb840: 0x2238825  or          $s1, $s1, $v1
    ctx->pc = 0x1bb840u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
label_1bb844:
    // 0x1bb844: 0x12200013  beqz        $s1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1BB844u;
    {
        const bool branch_taken_0x1bb844 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB844u;
            // 0x1bb848: 0x2404006c  addiu       $a0, $zero, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb844) {
            ctx->pc = 0x1BB894u;
            goto label_1bb894;
        }
    }
    ctx->pc = 0x1BB84Cu;
    // 0x1bb84c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BB84Cu;
    SET_GPR_U32(ctx, 31, 0x1BB854u);
    ctx->pc = 0x1BB850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB84Cu;
            // 0x1bb850: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB854u; }
        if (ctx->pc != 0x1BB854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB854u; }
        if (ctx->pc != 0x1BB854u) { return; }
    }
    ctx->pc = 0x1BB854u;
label_1bb854:
    // 0x1bb854: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x1bb854u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1bb858: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1bb858u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1bb85c: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x1bb85cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1bb860: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1bb860u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1bb864: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1bb864u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1bb868: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1bb868u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1bb86c: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1bb86cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1bb870: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1bb870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1bb874: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1BB874u;
    SET_GPR_U32(ctx, 31, 0x1BB87Cu);
    ctx->pc = 0x1BB878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB874u;
            // 0x1bb878: 0xae02001c  sw          $v0, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB87Cu; }
        if (ctx->pc != 0x1BB87Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB87Cu; }
        if (ctx->pc != 0x1BB87Cu) { return; }
    }
    ctx->pc = 0x1BB87Cu;
label_1bb87c:
    // 0x1bb87c: 0x2404005e  addiu       $a0, $zero, 0x5E
    ctx->pc = 0x1bb87cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x1bb880: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BB880u;
    SET_GPR_U32(ctx, 31, 0x1BB888u);
    ctx->pc = 0x1BB884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB880u;
            // 0x1bb884: 0x24050032  addiu       $a1, $zero, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB888u; }
        if (ctx->pc != 0x1BB888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB888u; }
        if (ctx->pc != 0x1BB888u) { return; }
    }
    ctx->pc = 0x1BB888u;
label_1bb888:
    // 0x1bb888: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb888u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb88c: 0xc06aed8  jal         func_1ABB60
    ctx->pc = 0x1BB88Cu;
    SET_GPR_U32(ctx, 31, 0x1BB894u);
    ctx->pc = 0x1BB890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB88Cu;
            // 0x1bb890: 0x24846664  addiu       $a0, $a0, 0x6664 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26212));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ABB60u;
    if (runtime->hasFunction(0x1ABB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ABB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB894u; }
        if (ctx->pc != 0x1BB894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ABB60_0x1abb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB894u; }
        if (ctx->pc != 0x1BB894u) { return; }
    }
    ctx->pc = 0x1BB894u;
label_1bb894:
    // 0x1bb894: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1bb894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bb898: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bb898u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bb89c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bb89cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb8a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB8A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB8A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB8A0u;
            // 0x1bb8a4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB7E0u: goto label_1bb7e0;
            case 0x1BB82Cu: goto label_1bb82c;
            case 0x1BB844u: goto label_1bb844;
            case 0x1BB854u: goto label_1bb854;
            case 0x1BB87Cu: goto label_1bb87c;
            case 0x1BB888u: goto label_1bb888;
            case 0x1BB894u: goto label_1bb894;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB8A8u;
    // 0x1bb8a8: 0x0  nop
    ctx->pc = 0x1bb8a8u;
    // NOP
    // 0x1bb8ac: 0x0  nop
    ctx->pc = 0x1bb8acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
