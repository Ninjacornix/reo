#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191220
// Address: 0x191220 - 0x191278
void sub_00191220_0x191220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191220_0x191220");
#endif

    switch (ctx->pc) {
        case 0x191258u: goto label_191258;
        case 0x191268u: goto label_191268;
        default: break;
    }

    ctx->pc = 0x191220u;

    // 0x191220: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x191220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x191224: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x191224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x191228: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191228u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19122c: 0xc4800030  lwc1        $f0, 0x30($a0)
    ctx->pc = 0x19122cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191230: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x191230u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191234: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191234u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191238: 0xe7a00020  swc1        $f0, 0x20($sp)
    ctx->pc = 0x191238u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x19123c: 0xc4800034  lwc1        $f0, 0x34($a0)
    ctx->pc = 0x19123cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191240: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191240u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191244: 0xe7a00024  swc1        $f0, 0x24($sp)
    ctx->pc = 0x191244u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 36), bits); }
    // 0x191248: 0xc4800038  lwc1        $f0, 0x38($a0)
    ctx->pc = 0x191248u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19124c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19124cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191250: 0xc064474  jal         func_1911D0
    ctx->pc = 0x191250u;
    SET_GPR_U32(ctx, 31, 0x191258u);
    ctx->pc = 0x191254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191250u;
            // 0x191254: 0xe7a00028  swc1        $f0, 0x28($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1911D0u;
    if (runtime->hasFunction(0x1911D0u)) {
        auto targetFn = runtime->lookupFunction(0x1911D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191258u; }
        if (ctx->pc != 0x191258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001911D0_0x1911d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191258u; }
        if (ctx->pc != 0x191258u) { return; }
    }
    ctx->pc = 0x191258u;
label_191258:
    // 0x191258: 0x26040030  addiu       $a0, $s0, 0x30
    ctx->pc = 0x191258u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x19125c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x19125cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191260: 0xc064674  jal         func_1919D0
    ctx->pc = 0x191260u;
    SET_GPR_U32(ctx, 31, 0x191268u);
    ctx->pc = 0x191264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191260u;
            // 0x191264: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1919D0u;
    if (runtime->hasFunction(0x1919D0u)) {
        auto targetFn = runtime->lookupFunction(0x1919D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191268u; }
        if (ctx->pc != 0x191268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001919D0_0x1919d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191268u; }
        if (ctx->pc != 0x191268u) { return; }
    }
    ctx->pc = 0x191268u;
label_191268:
    // 0x191268: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x191268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19126c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19126cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191270: 0x3e00008  jr          $ra
    ctx->pc = 0x191270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191270u;
            // 0x191274: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191258u: goto label_191258;
            case 0x191268u: goto label_191268;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191278u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
