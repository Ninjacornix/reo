#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001608B0
// Address: 0x1608b0 - 0x160904
void sub_001608B0_0x1608b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001608B0_0x1608b0");
#endif

    ctx->pc = 0x1608b0u;

    // 0x1608b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1608b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1608b4: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1608b4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1608b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1608b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1608bc: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x1608bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1608c0: 0x8c670134  lw          $a3, 0x134($v1)
    ctx->pc = 0x1608c0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 308)));
    // 0x1608c4: 0x24453fff  addiu       $a1, $v0, 0x3FFF
    ctx->pc = 0x1608c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 16383));
    // 0x1608c8: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1608c8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1608cc: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x1608ccu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x1608d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1608d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1608d4: 0x21383  sra         $v0, $v0, 14
    ctx->pc = 0x1608d4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 14));
    // 0x1608d8: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x1608d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1608dc: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x1608dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1608e0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1608e0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1608e4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1608e4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1608e8: 0x460c0002  mul.s       $f0, $f0, $f12
    ctx->pc = 0x1608e8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[12]);
    // 0x1608ec: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1608ecu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1608f0: 0x44050800  mfc1        $a1, $f1
    ctx->pc = 0x1608f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1608f4: 0xe5102a  slt         $v0, $a3, $a1
    ctx->pc = 0x1608f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1608f8: 0xe2280b  movn        $a1, $a3, $v0
    ctx->pc = 0x1608f8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x1608fc: 0x8057fc6  j           func_15FF18
    ctx->pc = 0x1608FCu;
    ctx->pc = 0x160900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1608FCu;
            // 0x160900: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FF18u;
    if (runtime->hasFunction(0x15FF18u)) {
        auto targetFn = runtime->lookupFunction(0x15FF18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015FF18_0x15ff18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160904u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
