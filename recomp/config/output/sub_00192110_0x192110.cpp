#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192110
// Address: 0x192110 - 0x192164
void sub_00192110_0x192110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192110_0x192110");
#endif

    switch (ctx->pc) {
        case 0x192138u: goto label_192138;
        case 0x192154u: goto label_192154;
        default: break;
    }

    ctx->pc = 0x192110u;

    // 0x192110: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x192110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x192114: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x192114u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x192118: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x192118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x19211c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x19211cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x192120: 0x46006506  mov.s       $f20, $f12
    ctx->pc = 0x192120u;
    ctx->f[20] = FPU_MOV_S(ctx->f[12]);
    // 0x192124: 0x4600a007  neg.s       $f0, $f20
    ctx->pc = 0x192124u;
    ctx->f[0] = FPU_NEG_S(ctx->f[20]);
    // 0x192128: 0x46140042  mul.s       $f1, $f0, $f20
    ctx->pc = 0x192128u;
    ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[20]);
    // 0x19212c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x19212cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x192130: 0xc064888  jal         func_192220
    ctx->pc = 0x192130u;
    SET_GPR_U32(ctx, 31, 0x192138u);
    ctx->pc = 0x192134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192130u;
            // 0x192134: 0x46010300  add.s       $f12, $f0, $f1 (Delay Slot)
        ctx->f[12] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x192220u;
    if (runtime->hasFunction(0x192220u)) {
        auto targetFn = runtime->lookupFunction(0x192220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192138u; }
        if (ctx->pc != 0x192138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192220_0x192220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192138u; }
        if (ctx->pc != 0x192138u) { return; }
    }
    ctx->pc = 0x192138u;
label_192138:
    // 0x192138: 0x0  nop
    ctx->pc = 0x192138u;
    // NOP
    // 0x19213c: 0x0  nop
    ctx->pc = 0x19213cu;
    // NOP
    // 0x192140: 0x4600a303  div.s       $f12, $f20, $f0
    ctx->pc = 0x192140u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[20] / ctx->f[0];
    // 0x192144: 0x0  nop
    ctx->pc = 0x192144u;
    // NOP
    // 0x192148: 0x0  nop
    ctx->pc = 0x192148u;
    // NOP
    // 0x19214c: 0xc06485c  jal         func_192170
    ctx->pc = 0x19214Cu;
    SET_GPR_U32(ctx, 31, 0x192154u);
    ctx->pc = 0x192170u;
    if (runtime->hasFunction(0x192170u)) {
        auto targetFn = runtime->lookupFunction(0x192170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192154u; }
        if (ctx->pc != 0x192154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192170_0x192170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192154u; }
        if (ctx->pc != 0x192154u) { return; }
    }
    ctx->pc = 0x192154u;
label_192154:
    // 0x192154: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x192154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192158: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x192158u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x19215c: 0x3e00008  jr          $ra
    ctx->pc = 0x19215Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19215Cu;
            // 0x192160: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192138u: goto label_192138;
            case 0x192154u: goto label_192154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192164u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
