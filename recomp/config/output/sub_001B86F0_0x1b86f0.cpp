#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B86F0
// Address: 0x1b86f0 - 0x1b8780
void sub_001B86F0_0x1b86f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B86F0_0x1b86f0");
#endif

    switch (ctx->pc) {
        case 0x1b8734u: goto label_1b8734;
        case 0x1b8738u: goto label_1b8738;
        case 0x1b8758u: goto label_1b8758;
        default: break;
    }

    ctx->pc = 0x1b86f0u;

    // 0x1b86f0: 0x44841000  mtc1        $a0, $f2
    ctx->pc = 0x1b86f0u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1b86f4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b86f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b86f8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b86f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b86fc: 0x3c0240e0  lui         $v0, 0x40E0
    ctx->pc = 0x1b86fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16608 << 16));
    // 0x1b8700: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1b8700u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1b8704: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1b8704u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1b8708: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1b8708u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b870c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1b870cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1b8710: 0x46011503  div.s       $f20, $f2, $f1
    ctx->pc = 0x1b8710u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[20] = std::bit_cast<float>(__maxf); } else ctx->f[20] = ctx->f[2] / ctx->f[1];
    // 0x1b8714: 0x3c024380  lui         $v0, 0x4380
    ctx->pc = 0x1b8714u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17280 << 16));
    // 0x1b8718: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b8718u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b871c: 0x0  nop
    ctx->pc = 0x1b871cu;
    // NOP
    // 0x1b8720: 0x46140002  mul.s       $f0, $f0, $f20
    ctx->pc = 0x1b8720u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[20]);
    // 0x1b8724: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b8724u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b8728: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x1b8728u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1b872c: 0xc06b3ac  jal         func_1ACEB0
    ctx->pc = 0x1B872Cu;
    SET_GPR_U32(ctx, 31, 0x1B8734u);
    ctx->pc = 0x1B8730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B872Cu;
            // 0x1b8730: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACEB0u;
    if (runtime->hasFunction(0x1ACEB0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACEB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8734u; }
        if (ctx->pc != 0x1B8734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACEB0_0x1aceb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8734u; }
        if (ctx->pc != 0x1B8734u) { return; }
    }
    ctx->pc = 0x1B8734u;
label_1b8734:
    // 0x1b8734: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1b8734u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b8738:
    // 0x1b8738: 0x3c0242fe  lui         $v0, 0x42FE
    ctx->pc = 0x1b8738u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17150 << 16));
    // 0x1b873c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b873cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b8740: 0x0  nop
    ctx->pc = 0x1b8740u;
    // NOP
    // 0x1b8744: 0x46140002  mul.s       $f0, $f0, $f20
    ctx->pc = 0x1b8744u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[20]);
    // 0x1b8748: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b8748u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b874c: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x1b874cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1b8750: 0xc06b830  jal         func_1AE0C0
    ctx->pc = 0x1B8750u;
    SET_GPR_U32(ctx, 31, 0x1B8758u);
    ctx->pc = 0x1B8754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8750u;
            // 0x1b8754: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE0C0u;
    if (runtime->hasFunction(0x1AE0C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE0C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8758u; }
        if (ctx->pc != 0x1B8758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE0C0_0x1ae0c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8758u; }
        if (ctx->pc != 0x1B8758u) { return; }
    }
    ctx->pc = 0x1B8758u;
label_1b8758:
    // 0x1b8758: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b8758u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b875c: 0x2a030003  slti        $v1, $s0, 0x3
    ctx->pc = 0x1b875cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1b8760: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x1B8760u;
    {
        const bool branch_taken_0x1b8760 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b8760) {
            ctx->pc = 0x1B8738u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b8738;
        }
    }
    ctx->pc = 0x1B8768u;
    // 0x1b8768: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b8768u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b876c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1b876cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1b8770: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1b8770u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b8774: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8774u;
            // 0x1b8778: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8734u: goto label_1b8734;
            case 0x1B8738u: goto label_1b8738;
            case 0x1B8758u: goto label_1b8758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B877Cu;
    // 0x1b877c: 0x0  nop
    ctx->pc = 0x1b877cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
