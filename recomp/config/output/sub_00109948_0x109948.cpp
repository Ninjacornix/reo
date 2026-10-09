#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00109948
// Address: 0x109948 - 0x1099b0
void sub_00109948_0x109948(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00109948_0x109948");
#endif

    switch (ctx->pc) {
        case 0x10997cu: goto label_10997c;
        default: break;
    }

    ctx->pc = 0x109948u;

    // 0x109948: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x109948u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10994c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10994cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x109950: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x109950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x109954: 0x3c055851  lui         $a1, 0x5851
    ctx->pc = 0x109954u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22609 << 16));
    // 0x109958: 0x34a5f42d  ori         $a1, $a1, 0xF42D
    ctx->pc = 0x109958u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)62509);
    // 0x10995c: 0x52c38  dsll        $a1, $a1, 16
    ctx->pc = 0x10995cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 16);
    // 0x109960: 0x34a54c95  ori         $a1, $a1, 0x4C95
    ctx->pc = 0x109960u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)19605);
    // 0x109964: 0x52c38  dsll        $a1, $a1, 16
    ctx->pc = 0x109964u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 16);
    // 0x109968: 0x34a57f2d  ori         $a1, $a1, 0x7F2D
    ctx->pc = 0x109968u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)32557);
    // 0x10996c: 0x8c5097f0  lw          $s0, -0x6810($v0)
    ctx->pc = 0x10996cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x109970: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x109970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x109974: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x109974u;
    SET_GPR_U32(ctx, 31, 0x10997Cu);
    ctx->pc = 0x109978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109974u;
            // 0x109978: 0xde0400a8  ld          $a0, 0xA8($s0) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 168)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10997Cu; }
        if (ctx->pc != 0x10997Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10997Cu; }
        if (ctx->pc != 0x10997Cu) { return; }
    }
    ctx->pc = 0x10997Cu;
label_10997c:
    // 0x10997c: 0x3c047fff  lui         $a0, 0x7FFF
    ctx->pc = 0x10997cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32767 << 16));
    // 0x109980: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x109980u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x109984: 0x64430001  daddiu      $v1, $v0, 0x1
    ctx->pc = 0x109984u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x109988: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x109988u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10998c: 0x3103e  dsrl32      $v0, $v1, 0
    ctx->pc = 0x10998cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x109990: 0xfe0300a8  sd          $v1, 0xA8($s0)
    ctx->pc = 0x109990u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 168), GPR_U64(ctx, 3));
    // 0x109994: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x109994u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x109998: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x109998u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10999c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10999cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1099a0: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1099a0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1099a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1099A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1099A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1099A4u;
            // 0x1099a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10997Cu: goto label_10997c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1099ACu;
    // 0x1099ac: 0x0  nop
    ctx->pc = 0x1099acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
