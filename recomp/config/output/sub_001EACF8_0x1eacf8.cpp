#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EACF8
// Address: 0x1eacf8 - 0x1eae08
void sub_001EACF8_0x1eacf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EACF8_0x1eacf8");
#endif

    ctx->pc = 0x1eacf8u;

    // 0x1eacf8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1eacf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1eacfc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1eacfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1ead00: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ead00u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ead04: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1ead04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1ead08: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1ead08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1ead0c: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1ead0cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ead10: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ead10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ead14: 0xa7c2000e  sh          $v0, 0xE($fp)
    ctx->pc = 0x1ead14u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ead18: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1ead18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ead1c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ead1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ead20: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1ead20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1ead24: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1ead24u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ead28: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ead28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ead2c: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1ead2cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ead30: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1ead30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ead34: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ead34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ead38: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1ead38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1ead3c: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1ead3cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ead40: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ead40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ead44: 0xa7c2000a  sh          $v0, 0xA($fp)
    ctx->pc = 0x1ead44u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ead48: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1ead48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ead4c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ead4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ead50: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1ead50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1ead54: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1ead54u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ead58: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ead58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ead5c: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1ead5cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ead60: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1ead60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ead64: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1ead64u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1ead68: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ead68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ead6c: 0x24430040  addiu       $v1, $v0, 0x40
    ctx->pc = 0x1ead6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x1ead70: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x1ead70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1ead74: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1ead74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ead78: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1ead78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ead7c: 0x97c2000a  lhu         $v0, 0xA($fp)
    ctx->pc = 0x1ead7cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 10)));
    // 0x1ead80: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ead80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ead84: 0x24430440  addiu       $v1, $v0, 0x440
    ctx->pc = 0x1ead84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1088));
    // 0x1ead88: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x1ead88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1ead8c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ead8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ead90: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1ead90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1ead94: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1ead94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ead98: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ead98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ead9c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1ead9cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eada0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1eada0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eada4: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1eada4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eada8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1eada8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eadac: 0x24430840  addiu       $v1, $v0, 0x840
    ctx->pc = 0x1eadacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 2112));
    // 0x1eadb0: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x1eadb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1eadb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1eadb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1eadb8: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eadb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eadbc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eadbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eadc0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eadc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eadc4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eadc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eadc8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1eadc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eadcc: 0x97c2000e  lhu         $v0, 0xE($fp)
    ctx->pc = 0x1eadccu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1eadd0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1eadd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eadd4: 0x24430c40  addiu       $v1, $v0, 0xC40
    ctx->pc = 0x1eadd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 3136));
    // 0x1eadd8: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x1eadd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1eaddc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1eaddcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1eade0: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eade0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eade4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eade4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eade8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eade8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eadec: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eadecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eadf0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eadf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eadf4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eadf4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eadf8: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1eadf8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1eadfc: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1eadfcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1eae00: 0x3e00008  jr          $ra
    ctx->pc = 0x1EAE00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1EAE08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
