#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DDEF8
// Address: 0x1ddef8 - 0x1ddfd4
void sub_001DDEF8_0x1ddef8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DDEF8_0x1ddef8");
#endif

    ctx->pc = 0x1ddef8u;

    // 0x1ddef8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ddef8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ddefc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1ddefcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1ddf00: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ddf00u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddf04: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1ddf04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1ddf08: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddf08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf0c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddf0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf10: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1ddf10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddf14: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddf14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddf18: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddf18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddf1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddf1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf20: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1ddf20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddf24: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddf24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddf28: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddf28u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddf2c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddf2cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddf30: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddf30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf34: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1ddf34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddf38: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddf38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddf3c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddf3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddf40: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ddf40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ddf44: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddf44u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddf48: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddf48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf4c: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1ddf4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddf50: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddf50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddf54: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddf54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddf58: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddf58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddf5c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddf5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddf60: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1ddf60u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1ddf64: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddf64u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf68: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddf68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf6c: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1ddf6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddf70: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddf70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddf74: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddf74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddf78: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddf78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf7c: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1ddf7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddf80: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddf80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddf84: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddf84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddf88: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddf88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddf8c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddf8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddf90: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1ddf90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddf94: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddf94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddf98: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddf98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddf9c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ddf9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ddfa0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddfa0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddfa4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddfa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddfa8: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1ddfa8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddfac: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddfacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddfb0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddfb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddfb4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddfb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddfb8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddfb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddfbc: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1ddfbcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1ddfc0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1ddfc0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddfc4: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1ddfc4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ddfc8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1ddfc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1ddfcc: 0x3e00008  jr          $ra
    ctx->pc = 0x1DDFCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DDFD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
