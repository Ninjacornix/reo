#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198AF0
// Address: 0x198af0 - 0x198b30
void sub_00198AF0_0x198af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198AF0_0x198af0");
#endif

    ctx->pc = 0x198af0u;

    // 0x198af0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198af0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198af4: 0xc420fd60  lwc1        $f0, -0x2A0($at)
    ctx->pc = 0x198af4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x198af8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x198af8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x198afc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198afcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198b00: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x198b00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x198b04: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x198B04u;
    {
        const bool branch_taken_0x198b04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x198B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198B04u;
            // 0x198b08: 0x46006301  sub.s       $f12, $f12, $f0 (Delay Slot)
        ctx->f[12] = FPU_SUB_S(ctx->f[12], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198b04) {
            ctx->pc = 0x198B1Cu;
            goto label_198b1c;
        }
    }
    ctx->pc = 0x198B0Cu;
    // 0x198b0c: 0x3c023f00  lui         $v0, 0x3F00
    ctx->pc = 0x198b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16128 << 16));
    // 0x198b10: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x198b10u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x198b14: 0x0  nop
    ctx->pc = 0x198b14u;
    // NOP
    // 0x198b18: 0x46006302  mul.s       $f12, $f12, $f0
    ctx->pc = 0x198b18u;
    ctx->f[12] = FPU_MUL_S(ctx->f[12], ctx->f[0]);
label_198b1c:
    // 0x198b1c: 0x3e00008  jr          $ra
    ctx->pc = 0x198B1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198B1Cu;
            // 0x198b20: 0x46006006  mov.s       $f0, $f12 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x198B1Cu: goto label_198b1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x198B24u;
    // 0x198b24: 0x0  nop
    ctx->pc = 0x198b24u;
    // NOP
    // 0x198b28: 0x0  nop
    ctx->pc = 0x198b28u;
    // NOP
    // 0x198b2c: 0x0  nop
    ctx->pc = 0x198b2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
