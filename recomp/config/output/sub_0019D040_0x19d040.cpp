#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D040
// Address: 0x19d040 - 0x19d120
void sub_0019D040_0x19d040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D040_0x19d040");
#endif

    switch (ctx->pc) {
        case 0x19d07cu: goto label_19d07c;
        default: break;
    }

    ctx->pc = 0x19d040u;

    // 0x19d040: 0x8c820030  lw          $v0, 0x30($a0)
    ctx->pc = 0x19d040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x19d044: 0xa2082b  sltu        $at, $a1, $v0
    ctx->pc = 0x19d044u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x19d048: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D048u;
    {
        const bool branch_taken_0x19d048 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x19d048) {
            ctx->pc = 0x19D058u;
            goto label_19d058;
        }
    }
    ctx->pc = 0x19D050u;
    // 0x19d050: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x19D050u;
    {
        const bool branch_taken_0x19d050 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D050u;
            // 0x19d054: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d050) {
            ctx->pc = 0x19D114u;
            goto label_19d114;
        }
    }
    ctx->pc = 0x19D058u;
label_19d058:
    // 0x19d058: 0x848c001a  lh          $t4, 0x1A($a0)
    ctx->pc = 0x19d058u;
    SET_GPR_S32(ctx, 12, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x19d05c: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x19d05cu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d060: 0x848b001c  lh          $t3, 0x1C($a0)
    ctx->pc = 0x19d060u;
    SET_GPR_S32(ctx, 11, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x19d064: 0x24070014  addiu       $a3, $zero, 0x14
    ctx->pc = 0x19d064u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x19d068: 0x84820014  lh          $v0, 0x14($a0)
    ctx->pc = 0x19d068u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x19d06c: 0x24080013  addiu       $t0, $zero, 0x13
    ctx->pc = 0x19d06cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x19d070: 0x24090002  addiu       $t1, $zero, 0x2
    ctx->pc = 0x19d070u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19d074: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x19D074u;
    {
        const bool branch_taken_0x19d074 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D074u;
            // 0x19d078: 0x240a0001  addiu       $t2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d074) {
            ctx->pc = 0x19D108u;
            goto label_19d108;
        }
    }
    ctx->pc = 0x19D07Cu;
label_19d07c:
    // 0x19d07c: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x19d07cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x19d080: 0x10600016  beqz        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x19D080u;
    {
        const bool branch_taken_0x19d080 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x19d080) {
            ctx->pc = 0x19D0DCu;
            goto label_19d0dc;
        }
    }
    ctx->pc = 0x19D088u;
    // 0x19d088: 0x106a0011  beq         $v1, $t2, . + 4 + (0x11 << 2)
    ctx->pc = 0x19D088u;
    {
        const bool branch_taken_0x19d088 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 10));
        if (branch_taken_0x19d088) {
            ctx->pc = 0x19D0D0u;
            goto label_19d0d0;
        }
    }
    ctx->pc = 0x19D090u;
    // 0x19d090: 0x1069000c  beq         $v1, $t1, . + 4 + (0xC << 2)
    ctx->pc = 0x19D090u;
    {
        const bool branch_taken_0x19d090 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 9));
        if (branch_taken_0x19d090) {
            ctx->pc = 0x19D0C4u;
            goto label_19d0c4;
        }
    }
    ctx->pc = 0x19D098u;
    // 0x19d098: 0x10680008  beq         $v1, $t0, . + 4 + (0x8 << 2)
    ctx->pc = 0x19D098u;
    {
        const bool branch_taken_0x19d098 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        if (branch_taken_0x19d098) {
            ctx->pc = 0x19D0BCu;
            goto label_19d0bc;
        }
    }
    ctx->pc = 0x19D0A0u;
    // 0x19d0a0: 0x10670003  beq         $v1, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D0A0u;
    {
        const bool branch_taken_0x19d0a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 7));
        if (branch_taken_0x19d0a0) {
            ctx->pc = 0x19D0B0u;
            goto label_19d0b0;
        }
    }
    ctx->pc = 0x19D0A8u;
    // 0x19d0a8: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x19D0A8u;
    {
        const bool branch_taken_0x19d0a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D0ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D0A8u;
            // 0x19d0ac: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d0a8) {
            ctx->pc = 0x19D114u;
            goto label_19d114;
        }
    }
    ctx->pc = 0x19D0B0u;
label_19d0b0:
    // 0x19d0b0: 0x18b1818  mult        $v1, $t4, $t3
    ctx->pc = 0x19d0b0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 11); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19d0b4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x19D0B4u;
    {
        const bool branch_taken_0x19d0b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D0B4u;
            // 0x19d0b8: 0x31843  sra         $v1, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d0b4) {
            ctx->pc = 0x19D0E4u;
            goto label_19d0e4;
        }
    }
    ctx->pc = 0x19D0BCu;
label_19d0bc:
    // 0x19d0bc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x19D0BCu;
    {
        const bool branch_taken_0x19d0bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D0BCu;
            // 0x19d0c0: 0x18b1818  mult        $v1, $t4, $t3 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 11); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d0bc) {
            ctx->pc = 0x19D0E4u;
            goto label_19d0e4;
        }
    }
    ctx->pc = 0x19D0C4u;
label_19d0c4:
    // 0x19d0c4: 0x18b1818  mult        $v1, $t4, $t3
    ctx->pc = 0x19d0c4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 11); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19d0c8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x19D0C8u;
    {
        const bool branch_taken_0x19d0c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D0CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D0C8u;
            // 0x19d0cc: 0x31840  sll         $v1, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d0c8) {
            ctx->pc = 0x19D0E4u;
            goto label_19d0e4;
        }
    }
    ctx->pc = 0x19D0D0u;
label_19d0d0:
    // 0x19d0d0: 0x18b1818  mult        $v1, $t4, $t3
    ctx->pc = 0x19d0d0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 11); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19d0d4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x19D0D4u;
    {
        const bool branch_taken_0x19d0d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D0D4u;
            // 0x19d0d8: 0x31880  sll         $v1, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d0d4) {
            ctx->pc = 0x19D0E4u;
            goto label_19d0e4;
        }
    }
    ctx->pc = 0x19D0DCu;
label_19d0dc:
    // 0x19d0dc: 0x18b1818  mult        $v1, $t4, $t3
    ctx->pc = 0x19d0dcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 11); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19d0e0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x19d0e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_19d0e4:
    // 0x19d0e4: 0x246600ff  addiu       $a2, $v1, 0xFF
    ctx->pc = 0x19d0e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 255));
    // 0x19d0e8: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D0E8u;
    {
        const bool branch_taken_0x19d0e8 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x19D0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D0E8u;
            // 0x19d0ec: 0x61a03  sra         $v1, $a2, 8 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d0e8) {
            ctx->pc = 0x19D0F8u;
            goto label_19d0f8;
        }
    }
    ctx->pc = 0x19D0F0u;
    // 0x19d0f0: 0x24c300ff  addiu       $v1, $a2, 0xFF
    ctx->pc = 0x19d0f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 255));
    // 0x19d0f4: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x19d0f4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
label_19d0f8:
    // 0x19d0f8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x19d0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x19d0fc: 0xc6043  sra         $t4, $t4, 1
    ctx->pc = 0x19d0fcu;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 12), 1));
    // 0x19d100: 0xb5843  sra         $t3, $t3, 1
    ctx->pc = 0x19d100u;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 1));
    // 0x19d104: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x19d104u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
label_19d108:
    // 0x19d108: 0x1a5182a  slt         $v1, $t5, $a1
    ctx->pc = 0x19d108u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x19d10c: 0x1460ffdb  bnez        $v1, . + 4 + (-0x25 << 2)
    ctx->pc = 0x19D10Cu;
    {
        const bool branch_taken_0x19d10c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19d10c) {
            ctx->pc = 0x19D07Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19d07c;
        }
    }
    ctx->pc = 0x19D114u;
label_19d114:
    // 0x19d114: 0x3e00008  jr          $ra
    ctx->pc = 0x19D114u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D058u: goto label_19d058;
            case 0x19D07Cu: goto label_19d07c;
            case 0x19D0B0u: goto label_19d0b0;
            case 0x19D0BCu: goto label_19d0bc;
            case 0x19D0C4u: goto label_19d0c4;
            case 0x19D0D0u: goto label_19d0d0;
            case 0x19D0DCu: goto label_19d0dc;
            case 0x19D0E4u: goto label_19d0e4;
            case 0x19D0F8u: goto label_19d0f8;
            case 0x19D108u: goto label_19d108;
            case 0x19D114u: goto label_19d114;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D11Cu;
    // 0x19d11c: 0x0  nop
    ctx->pc = 0x19d11cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
