#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B82E0
// Address: 0x1b82e0 - 0x1b8360
void sub_001B82E0_0x1b82e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B82E0_0x1b82e0");
#endif

    switch (ctx->pc) {
        case 0x1b8348u: goto label_1b8348;
        case 0x1b8350u: goto label_1b8350;
        default: break;
    }

    ctx->pc = 0x1b82e0u;

    // 0x1b82e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b82e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b82e4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b82e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b82e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b82e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b82ec: 0x902243ca  lbu         $v0, 0x43CA($at)
    ctx->pc = 0x1b82ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17354)));
    // 0x1b82f0: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B82F0u;
    {
        const bool branch_taken_0x1b82f0 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1B82F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B82F0u;
            // 0x1b82f4: 0x21842  srl         $v1, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b82f0) {
            ctx->pc = 0x1B8304u;
            goto label_1b8304;
        }
    }
    ctx->pc = 0x1B82F8u;
    // 0x1b82f8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b82f8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b82fc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B82FCu;
    {
        const bool branch_taken_0x1b82fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B82FCu;
            // 0x1b8300: 0x468000a0  cvt.s.w     $f2, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b82fc) {
            ctx->pc = 0x1B831Cu;
            goto label_1b831c;
        }
    }
    ctx->pc = 0x1B8304u;
label_1b8304:
    // 0x1b8304: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1b8304u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1b8308: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1b8308u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1b830c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1b830cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b8310: 0x0  nop
    ctx->pc = 0x1b8310u;
    // NOP
    // 0x1b8314: 0x468000a0  cvt.s.w     $f2, $f0
    ctx->pc = 0x1b8314u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1b8318: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1b8318u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1b831c:
    // 0x1b831c: 0x3c0340e0  lui         $v1, 0x40E0
    ctx->pc = 0x1b831cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16608 << 16));
    // 0x1b8320: 0x3c024380  lui         $v0, 0x4380
    ctx->pc = 0x1b8320u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17280 << 16));
    // 0x1b8324: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1b8324u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b8328: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b8328u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b832c: 0x0  nop
    ctx->pc = 0x1b832cu;
    // NOP
    // 0x1b8330: 0x46011043  div.s       $f1, $f2, $f1
    ctx->pc = 0x1b8330u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[1];
    // 0x1b8334: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1b8334u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1b8338: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b8338u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b833c: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x1b833cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1b8340: 0xc06b3ac  jal         func_1ACEB0
    ctx->pc = 0x1B8340u;
    SET_GPR_U32(ctx, 31, 0x1B8348u);
    ctx->pc = 0x1B8344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8340u;
            // 0x1b8344: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACEB0u;
    if (runtime->hasFunction(0x1ACEB0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACEB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8348u; }
        if (ctx->pc != 0x1B8348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACEB0_0x1aceb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8348u; }
        if (ctx->pc != 0x1B8348u) { return; }
    }
    ctx->pc = 0x1B8348u;
label_1b8348:
    // 0x1b8348: 0xc06e654  jal         func_1B9950
    ctx->pc = 0x1B8348u;
    SET_GPR_U32(ctx, 31, 0x1B8350u);
    ctx->pc = 0x1B9950u;
    if (runtime->hasFunction(0x1B9950u)) {
        auto targetFn = runtime->lookupFunction(0x1B9950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8350u; }
        if (ctx->pc != 0x1B8350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B9950_0x1b9950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8350u; }
        if (ctx->pc != 0x1B8350u) { return; }
    }
    ctx->pc = 0x1B8350u;
label_1b8350:
    // 0x1b8350: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b8350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8354: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8354u;
            // 0x1b8358: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8304u: goto label_1b8304;
            case 0x1B831Cu: goto label_1b831c;
            case 0x1B8348u: goto label_1b8348;
            case 0x1B8350u: goto label_1b8350;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B835Cu;
    // 0x1b835c: 0x0  nop
    ctx->pc = 0x1b835cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
