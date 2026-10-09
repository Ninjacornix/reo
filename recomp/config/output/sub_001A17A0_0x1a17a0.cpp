#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A17A0
// Address: 0x1a17a0 - 0x1a1820
void sub_001A17A0_0x1a17a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A17A0_0x1a17a0");
#endif

    ctx->pc = 0x1a17a0u;

    // 0x1a17a0: 0x8c860008  lw          $a2, 0x8($a0)
    ctx->pc = 0x1a17a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a17a4: 0x51900  sll         $v1, $a1, 4
    ctx->pc = 0x1a17a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1a17a8: 0x3405ffff  ori         $a1, $zero, 0xFFFF
    ctx->pc = 0x1a17a8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a17ac: 0xc33821  addu        $a3, $a2, $v1
    ctx->pc = 0x1a17acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1a17b0: 0x94e3000c  lhu         $v1, 0xC($a3)
    ctx->pc = 0x1a17b0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x1a17b4: 0x10650006  beq         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A17B4u;
    {
        const bool branch_taken_0x1a17b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a17b4) {
            ctx->pc = 0x1A17D0u;
            goto label_1a17d0;
        }
    }
    ctx->pc = 0x1A17BCu;
    // 0x1a17bc: 0x94e5000e  lhu         $a1, 0xE($a3)
    ctx->pc = 0x1a17bcu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 14)));
    // 0x1a17c0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a17c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a17c4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x1a17c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1a17c8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A17C8u;
    {
        const bool branch_taken_0x1a17c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A17CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A17C8u;
            // 0x1a17cc: 0xa465000e  sh          $a1, 0xE($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 14), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a17c8) {
            ctx->pc = 0x1A17ECu;
            goto label_1a17ec;
        }
    }
    ctx->pc = 0x1A17D0u;
label_1a17d0:
    // 0x1a17d0: 0x94e3000e  lhu         $v1, 0xE($a3)
    ctx->pc = 0x1a17d0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 14)));
    // 0x1a17d4: 0xac830024  sw          $v1, 0x24($a0)
    ctx->pc = 0x1a17d4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 3));
    // 0x1a17d8: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x1a17d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1a17dc: 0x14650003  bne         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A17DCu;
    {
        const bool branch_taken_0x1a17dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a17dc) {
            ctx->pc = 0x1A17ECu;
            goto label_1a17ec;
        }
    }
    ctx->pc = 0x1A17E4u;
    // 0x1a17e4: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1a17e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1a17e8: 0xac830010  sw          $v1, 0x10($a0)
    ctx->pc = 0x1a17e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
label_1a17ec:
    // 0x1a17ec: 0x94e5000e  lhu         $a1, 0xE($a3)
    ctx->pc = 0x1a17ecu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 14)));
    // 0x1a17f0: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1a17f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a17f4: 0x10a30006  beq         $a1, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A17F4u;
    {
        const bool branch_taken_0x1a17f4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a17f4) {
            ctx->pc = 0x1A1810u;
            goto label_1a1810;
        }
    }
    ctx->pc = 0x1A17FCu;
    // 0x1a17fc: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1a17fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1800: 0x52900  sll         $a1, $a1, 4
    ctx->pc = 0x1a1800u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1a1804: 0x94e6000c  lhu         $a2, 0xC($a3)
    ctx->pc = 0x1a1804u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x1a1808: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a1808u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a180c: 0xa466000c  sh          $a2, 0xC($v1)
    ctx->pc = 0x1a180cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 12), (uint16_t)GPR_U32(ctx, 6));
label_1a1810:
    // 0x1a1810: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A17D0u: goto label_1a17d0;
            case 0x1A17ECu: goto label_1a17ec;
            case 0x1A1810u: goto label_1a1810;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1818u;
    // 0x1a1818: 0x0  nop
    ctx->pc = 0x1a1818u;
    // NOP
    // 0x1a181c: 0x0  nop
    ctx->pc = 0x1a181cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
