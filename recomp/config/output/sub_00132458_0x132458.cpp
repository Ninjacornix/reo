#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132458
// Address: 0x132458 - 0x1324a8
void sub_00132458_0x132458(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132458_0x132458");
#endif

    switch (ctx->pc) {
        case 0x13246cu: goto label_13246c;
        default: break;
    }

    ctx->pc = 0x132458u;

    // 0x132458: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x132458u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13245c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13245cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132460: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x132460u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x132464: 0xc04c858  jal         func_132160
    ctx->pc = 0x132464u;
    SET_GPR_U32(ctx, 31, 0x13246Cu);
    ctx->pc = 0x132468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132464u;
            // 0x132468: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132160u;
    if (runtime->hasFunction(0x132160u)) {
        auto targetFn = runtime->lookupFunction(0x132160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13246Cu; }
        if (ctx->pc != 0x13246Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132160_0x132160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13246Cu; }
        if (ctx->pc != 0x13246Cu) { return; }
    }
    ctx->pc = 0x13246Cu;
label_13246c:
    // 0x13246c: 0xc7a10000  lwc1        $f1, 0x0($sp)
    ctx->pc = 0x13246cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x132470: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x132470u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x132474: 0x3c0142c8  lui         $at, 0x42C8
    ctx->pc = 0x132474u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17096 << 16));
    // 0x132478: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x132478u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x13247c: 0xc7a20004  lwc1        $f2, 0x4($sp)
    ctx->pc = 0x13247cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x132480: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x132480u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x132484: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x132484u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132488: 0x0  nop
    ctx->pc = 0x132488u;
    // NOP
    // 0x13248c: 0x0  nop
    ctx->pc = 0x13248cu;
    // NOP
    // 0x132490: 0x46020843  div.s       $f1, $f1, $f2
    ctx->pc = 0x132490u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[2];
    // 0x132494: 0x46000842  mul.s       $f1, $f1, $f0
    ctx->pc = 0x132494u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x132498: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x132498u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x13249c: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x13249cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1324a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1324A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1324A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1324A0u;
            // 0x1324a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13246Cu: goto label_13246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1324A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
