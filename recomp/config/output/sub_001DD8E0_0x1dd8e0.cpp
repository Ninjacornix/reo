#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DD8E0
// Address: 0x1dd8e0 - 0x1dd960
void sub_001DD8E0_0x1dd8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DD8E0_0x1dd8e0");
#endif

    ctx->pc = 0x1dd8e0u;

    // 0x1dd8e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dd8e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dd8e4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dd8e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dd8e8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dd8e8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd8ec: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dd8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dd8f0: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dd8f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd8f4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd8f8: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1dd8f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd8fc: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dd8fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dd900: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dd900u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dd904: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd908: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1dd908u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd90c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dd90cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dd910: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dd910u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dd914: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dd914u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dd918: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd91c: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1dd91cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd920: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dd920u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dd924: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dd924u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dd928: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1dd928u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dd92c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dd92cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dd930: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd934: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1dd934u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd938: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dd938u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dd93c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dd93cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dd940: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dd940u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dd944: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dd944u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dd948: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1dd948u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1dd94c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dd94cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd950: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dd950u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dd954: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1dd954u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1dd958: 0x3e00008  jr          $ra
    ctx->pc = 0x1DD958u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DD960u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
