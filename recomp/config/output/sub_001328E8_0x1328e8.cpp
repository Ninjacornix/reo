#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001328E8
// Address: 0x1328e8 - 0x132974
void sub_001328E8_0x1328e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001328E8_0x1328e8");
#endif

    ctx->pc = 0x1328e8u;

    // 0x1328e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1328e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1328ec: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1328ecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1328f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1328f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1328f4: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1328F4u;
    {
        const bool branch_taken_0x1328f4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1328F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1328F4u;
            // 0x1328f8: 0xa0402d  daddu       $t0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1328f4) {
            ctx->pc = 0x132910u;
            goto label_132910;
        }
    }
    ctx->pc = 0x1328FCu;
    // 0x1328fc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1328fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132900: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132904: 0x2484b208  addiu       $a0, $a0, -0x4DF8
    ctx->pc = 0x132904u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947336));
    // 0x132908: 0x804a034  j           func_1280D0
    ctx->pc = 0x132908u;
    ctx->pc = 0x13290Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132908u;
            // 0x13290c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132910u;
label_132910:
    // 0x132910: 0x44860000  mtc1        $a2, $f0
    ctx->pc = 0x132910u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x132914: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x132914u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x132918: 0x84e5003c  lh          $a1, 0x3C($a3)
    ctx->pc = 0x132918u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x13291c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13291cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132920: 0x46006002  mul.s       $f0, $f12, $f0
    ctx->pc = 0x132920u;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[0]);
    // 0x132924: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x132924u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x132928: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x132928u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x13292c: 0x2464001f  addiu       $a0, $v1, 0x1F
    ctx->pc = 0x13292cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 31));
    // 0x132930: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x132930u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x132934: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x132934u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x132938: 0x31943  sra         $v1, $v1, 5
    ctx->pc = 0x132938u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 5));
    // 0x13293c: 0x681818  mult        $v1, $v1, $t0
    ctx->pc = 0x13293cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x132940: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x132940u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x132944: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x132944u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x132948: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x132948u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x13294c: 0x244407ff  addiu       $a0, $v0, 0x7FF
    ctx->pc = 0x13294cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x132950: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x132950u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132954: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x132954u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x132958: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x132958u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x13295c: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x13295cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x132960: 0x65102a  slt         $v0, $v1, $a1
    ctx->pc = 0x132960u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x132964: 0x62280b  movn        $a1, $v1, $v0
    ctx->pc = 0x132964u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 3));
    // 0x132968: 0xa4e5003e  sh          $a1, 0x3E($a3)
    ctx->pc = 0x132968u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 62), (uint16_t)GPR_U32(ctx, 5));
    // 0x13296c: 0x3e00008  jr          $ra
    ctx->pc = 0x13296Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13296Cu;
            // 0x132970: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132910u: goto label_132910;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132974u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
