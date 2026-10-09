#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142B98
// Address: 0x142b98 - 0x142fb8
void sub_00142B98_0x142b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142B98_0x142b98");
#endif

    ctx->pc = 0x142b98u;

    // 0x142b98: 0x80c02d  daddu       $t8, $a0, $zero
    ctx->pc = 0x142b98u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142b9c: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x142b9cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x142ba0: 0x270206d4  addiu       $v0, $t8, 0x6D4
    ctx->pc = 0x142ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 24), 1748));
    // 0x142ba4: 0xffbe00a0  sd          $fp, 0xA0($sp)
    ctx->pc = 0x142ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x142ba8: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x142ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x142bac: 0x24030140  addiu       $v1, $zero, 0x140
    ctx->pc = 0x142bacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x142bb0: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x142bb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x142bb4: 0xa0f02d  daddu       $fp, $a1, $zero
    ctx->pc = 0x142bb4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142bb8: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x142bb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x142bbc: 0x120702d  daddu       $t6, $t1, $zero
    ctx->pc = 0x142bbcu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142bc0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x142bc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x142bc4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x142bc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142bc8: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x142bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x142bcc: 0x100802d  daddu       $s0, $t0, $zero
    ctx->pc = 0x142bccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142bd0: 0xffb70090  sd          $s7, 0x90($sp)
    ctx->pc = 0x142bd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x142bd4: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x142bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x142bd8: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x142bd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x142bdc: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x142bdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x142be0: 0x8fa50014  lw          $a1, 0x14($sp)
    ctx->pc = 0x142be0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x142be4: 0x8f040834  lw          $a0, 0x834($t8)
    ctx->pc = 0x142be4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 24), 2100)));
    // 0x142be8: 0x8fb600b0  lw          $s6, 0xB0($sp)
    ctx->pc = 0x142be8u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x142bec: 0xafa40008  sw          $a0, 0x8($sp)
    ctx->pc = 0x142becu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
    // 0x142bf0: 0x2404001c  addiu       $a0, $zero, 0x1C
    ctx->pc = 0x142bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x142bf4: 0x8fad00c0  lw          $t5, 0xC0($sp)
    ctx->pc = 0x142bf4u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x142bf8: 0x8f020828  lw          $v0, 0x828($t8)
    ctx->pc = 0x142bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 24), 2088)));
    // 0x142bfc: 0xafaa0004  sw          $t2, 0x4($sp)
    ctx->pc = 0x142bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 10));
    // 0x142c00: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x142c00u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x142c04: 0xafa70000  sw          $a3, 0x0($sp)
    ctx->pc = 0x142c04u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 7));
    // 0x142c08: 0x8fa70004  lw          $a3, 0x4($sp)
    ctx->pc = 0x142c08u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x142c0c: 0x165043  sra         $t2, $s6, 1
    ctx->pc = 0x142c0cu;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 22), 1));
    // 0x142c10: 0x8fb200b8  lw          $s2, 0xB8($sp)
    ctx->pc = 0x142c10u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x142c14: 0x1474021  addu        $t0, $t2, $a3
    ctx->pc = 0x142c14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 7)));
    // 0x142c18: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x142c18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x142c1c: 0x8c770000  lw          $s7, 0x0($v1)
    ctx->pc = 0x142c1cu;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x142c20: 0x244205a8  addiu       $v0, $v0, 0x5A8
    ctx->pc = 0x142c20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1448));
    // 0x142c24: 0x3021021  addu        $v0, $t8, $v0
    ctx->pc = 0x142c24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 2)));
    // 0x142c28: 0x2e42018  mult        $a0, $s7, $a0
    ctx->pc = 0x142c28u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x142c2c: 0x248300b8  addiu       $v1, $a0, 0xB8
    ctx->pc = 0x142c2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 184));
    // 0x142c30: 0x24840048  addiu       $a0, $a0, 0x48
    ctx->pc = 0x142c30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 72));
    // 0x142c34: 0x437821  addu        $t7, $v0, $v1
    ctx->pc = 0x142c34u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142c38: 0x11a00005  beqz        $t5, . + 4 + (0x5 << 2)
    ctx->pc = 0x142C38u;
    {
        const bool branch_taken_0x142c38 = (GPR_U64(ctx, 13) == GPR_U64(ctx, 0));
        ctx->pc = 0x142C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142C38u;
            // 0x142c3c: 0x446021  addu        $t4, $v0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142c38) {
            ctx->pc = 0x142C50u;
            goto label_142c50;
        }
    }
    ctx->pc = 0x142C40u;
    // 0x142c40: 0x121043  sra         $v0, $s2, 1
    ctx->pc = 0x142c40u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 18), 1));
    // 0x142c44: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x142c44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x142c48: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x142C48u;
    {
        const bool branch_taken_0x142c48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142C4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142C48u;
            // 0x142c4c: 0x21040  sll         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142c48) {
            ctx->pc = 0x142C58u;
            goto label_142c58;
        }
    }
    ctx->pc = 0x142C50u;
label_142c50:
    // 0x142c50: 0x121043  sra         $v0, $s2, 1
    ctx->pc = 0x142c50u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 18), 1));
    // 0x142c54: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x142c54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
label_142c58:
    // 0x142c58: 0x4b1021  addu        $v0, $v0, $t3
    ctx->pc = 0x142c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x142c5c: 0x433021  addu        $a2, $v0, $v1
    ctx->pc = 0x142c5cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142c60: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x142c60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x142c64: 0x8a103  sra         $s4, $t0, 4
    ctx->pc = 0x142c64u;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 8), 4));
    // 0x142c68: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x142c68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142c6c: 0x141900  sll         $v1, $s4, 4
    ctx->pc = 0x142c6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 4));
    // 0x142c70: 0x2852818  mult        $a1, $s4, $a1
    ctx->pc = 0x142c70u;
    { int64_t result = (int64_t)GPR_S32(ctx, 20) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x142c74: 0x6a903  sra         $s5, $a2, 4
    ctx->pc = 0x142c74u;
    SET_GPR_S32(ctx, 21, SRA32(GPR_S32(ctx, 6), 4));
    // 0x142c78: 0x8fa70008  lw          $a3, 0x8($sp)
    ctx->pc = 0x142c78u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x142c7c: 0x502021  addu        $a0, $v0, $s0
    ctx->pc = 0x142c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x142c80: 0x1031823  subu        $v1, $t0, $v1
    ctx->pc = 0x142c80u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x142c84: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x142c84u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x142c88: 0xad830004  sw          $v1, 0x4($t4)
    ctx->pc = 0x142c88u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 4), GPR_U32(ctx, 3));
    // 0x142c8c: 0xe42021  addu        $a0, $a3, $a0
    ctx->pc = 0x142c8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x142c90: 0xb52821  addu        $a1, $a1, $s5
    ctx->pc = 0x142c90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 21)));
    // 0x142c94: 0x151100  sll         $v0, $s5, 4
    ctx->pc = 0x142c94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 21), 4));
    // 0x142c98: 0xafa50010  sw          $a1, 0x10($sp)
    ctx->pc = 0x142c98u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x142c9c: 0xc23023  subu        $a2, $a2, $v0
    ctx->pc = 0x142c9cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x142ca0: 0xad840000  sw          $a0, 0x0($t4)
    ctx->pc = 0x142ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 0), GPR_U32(ctx, 4));
    // 0x142ca4: 0x32590001  andi        $t9, $s2, 0x1
    ctx->pc = 0x142ca4u;
    SET_GPR_U64(ctx, 25, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)1);
    // 0x142ca8: 0x1320000f  beqz        $t9, . + 4 + (0xF << 2)
    ctx->pc = 0x142CA8u;
    {
        const bool branch_taken_0x142ca8 = (GPR_U64(ctx, 25) == GPR_U64(ctx, 0));
        ctx->pc = 0x142CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142CA8u;
            // 0x142cac: 0x32d30001  andi        $s3, $s6, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x142ca8) {
            ctx->pc = 0x142CE8u;
            goto label_142ce8;
        }
    }
    ctx->pc = 0x142CB0u;
    // 0x142cb0: 0x1ae1004  sllv        $v0, $t6, $t5
    ctx->pc = 0x142cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 14), GPR_U32(ctx, 13) & 0x1F));
    // 0x142cb4: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x142cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x142cb8: 0x28420010  slti        $v0, $v0, 0x10
    ctx->pc = 0x142cb8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x142cbc: 0x54400017  bnel        $v0, $zero, . + 4 + (0x17 << 2)
    ctx->pc = 0x142CBCu;
    {
        const bool branch_taken_0x142cbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x142cbc) {
            ctx->pc = 0x142CC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142CBCu;
            // 0x142cc0: 0xad8e0008  sw          $t6, 0x8($t4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 12), 8), GPR_U32(ctx, 14));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142D1Cu;
            goto label_142d1c;
        }
    }
    ctx->pc = 0x142CC4u;
    // 0x142cc4: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x142cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x142cc8: 0x1a61807  srav        $v1, $a2, $t5
    ctx->pc = 0x142cc8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), GPR_U32(ctx, 13) & 0x1F));
    // 0x142ccc: 0x1a21007  srav        $v0, $v0, $t5
    ctx->pc = 0x142cccu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 13) & 0x1F));
    // 0x142cd0: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x142cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142cd4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x142cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x142cd8: 0x1c21823  subu        $v1, $t6, $v0
    ctx->pc = 0x142cd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 14), GPR_U32(ctx, 2)));
    // 0x142cdc: 0xad820008  sw          $v0, 0x8($t4)
    ctx->pc = 0x142cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 12), 8), GPR_U32(ctx, 2));
    // 0x142ce0: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x142CE0u;
    {
        const bool branch_taken_0x142ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142CE0u;
            // 0x142ce4: 0xad83000c  sw          $v1, 0xC($t4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 12), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142ce0) {
            ctx->pc = 0x142D20u;
            goto label_142d20;
        }
    }
    ctx->pc = 0x142CE8u;
label_142ce8:
    // 0x142ce8: 0x1ae1004  sllv        $v0, $t6, $t5
    ctx->pc = 0x142ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 14), GPR_U32(ctx, 13) & 0x1F));
    // 0x142cec: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x142cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x142cf0: 0x28420011  slti        $v0, $v0, 0x11
    ctx->pc = 0x142cf0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x142cf4: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x142CF4u;
    {
        const bool branch_taken_0x142cf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x142cf4) {
            ctx->pc = 0x142CF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142CF4u;
            // 0x142cf8: 0xad8e0008  sw          $t6, 0x8($t4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 12), 8), GPR_U32(ctx, 14));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142D1Cu;
            goto label_142d1c;
        }
    }
    ctx->pc = 0x142CFCu;
    // 0x142cfc: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x142cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x142d00: 0x1a61807  srav        $v1, $a2, $t5
    ctx->pc = 0x142d00u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), GPR_U32(ctx, 13) & 0x1F));
    // 0x142d04: 0x1a21007  srav        $v0, $v0, $t5
    ctx->pc = 0x142d04u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 13) & 0x1F));
    // 0x142d08: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x142d08u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142d0c: 0x1c22023  subu        $a0, $t6, $v0
    ctx->pc = 0x142d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 14), GPR_U32(ctx, 2)));
    // 0x142d10: 0xad820008  sw          $v0, 0x8($t4)
    ctx->pc = 0x142d10u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 8), GPR_U32(ctx, 2));
    // 0x142d14: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x142D14u;
    {
        const bool branch_taken_0x142d14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142D14u;
            // 0x142d18: 0xad84000c  sw          $a0, 0xC($t4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 12), 12), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142d14) {
            ctx->pc = 0x142D20u;
            goto label_142d20;
        }
    }
    ctx->pc = 0x142D1Cu;
label_142d1c:
    // 0x142d1c: 0xad80000c  sw          $zero, 0xC($t4)
    ctx->pc = 0x142d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 12), 12), GPR_U32(ctx, 0));
label_142d20:
    // 0x142d20: 0x8f050828  lw          $a1, 0x828($t8)
    ctx->pc = 0x142d20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 24), 2088)));
    // 0x142d24: 0x24020140  addiu       $v0, $zero, 0x140
    ctx->pc = 0x142d24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x142d28: 0x24070600  addiu       $a3, $zero, 0x600
    ctx->pc = 0x142d28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x142d2c: 0x132040  sll         $a0, $s3, 1
    ctx->pc = 0x142d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x142d30: 0xa21818  mult        $v1, $a1, $v0
    ctx->pc = 0x142d30u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x142d34: 0x2e73818  mult        $a3, $s7, $a3
    ctx->pc = 0x142d34u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x142d38: 0x8fa200c8  lw          $v0, 0xC8($sp)
    ctx->pc = 0x142d38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x142d3c: 0x64900  sll         $t1, $a2, 4
    ctx->pc = 0x142d3cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x142d40: 0x252a0300  addiu       $t2, $t1, 0x300
    ctx->pc = 0x142d40u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 9), 768));
    // 0x142d44: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x142d44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x142d48: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x142d48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x142d4c: 0x1a63004  sllv        $a2, $a2, $t5
    ctx->pc = 0x142d4cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 13) & 0x1F));
    // 0x142d50: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x142d50u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x142d54: 0x782821  addu        $a1, $v1, $t8
    ctx->pc = 0x142d54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 24)));
    // 0x142d58: 0x1217c2  srl         $v0, $s2, 31
    ctx->pc = 0x142d58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x142d5c: 0x161fc2  srl         $v1, $s6, 31
    ctx->pc = 0x142d5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 22), 31));
    // 0x142d60: 0x8ca805a8  lw          $t0, 0x5A8($a1)
    ctx->pc = 0x142d60u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 1448)));
    // 0x142d64: 0x2c31821  addu        $v1, $s6, $v1
    ctx->pc = 0x142d64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
    // 0x142d68: 0x2422821  addu        $a1, $s2, $v0
    ctx->pc = 0x142d68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x142d6c: 0x39843  sra         $s3, $v1, 1
    ctx->pc = 0x142d6cu;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 3), 1));
    // 0x142d70: 0x1079021  addu        $s2, $t0, $a3
    ctx->pc = 0x142d70u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x142d74: 0x31883  sra         $v1, $v1, 2
    ctx->pc = 0x142d74u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 2));
    // 0x142d78: 0x8fa70018  lw          $a3, 0x18($sp)
    ctx->pc = 0x142d78u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x142d7c: 0x2494821  addu        $t1, $s2, $t1
    ctx->pc = 0x142d7cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 9)));
    // 0x142d80: 0x24a5021  addu        $t2, $s2, $t2
    ctx->pc = 0x142d80u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 10)));
    // 0x142d84: 0x5b043  sra         $s6, $a1, 1
    ctx->pc = 0x142d84u;
    SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 5), 1));
    // 0x142d88: 0xe42025  or          $a0, $a3, $a0
    ctx->pc = 0x142d88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
    // 0x142d8c: 0x992025  or          $a0, $a0, $t9
    ctx->pc = 0x142d8cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 25));
    // 0x142d90: 0x103843  sra         $a3, $s0, 1
    ctx->pc = 0x142d90u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 16), 1));
    // 0x142d94: 0xafa4000c  sw          $a0, 0xC($sp)
    ctx->pc = 0x142d94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 4));
    // 0x142d98: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x142d98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x142d9c: 0xad890014  sw          $t1, 0x14($t4)
    ctx->pc = 0x142d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 12), 20), GPR_U32(ctx, 9));
    // 0x142da0: 0x41043  sra         $v0, $a0, 1
    ctx->pc = 0x142da0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 4), 1));
    // 0x142da4: 0xad860010  sw          $a2, 0x10($t4)
    ctx->pc = 0x142da4u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 16), GPR_U32(ctx, 6));
    // 0x142da8: 0x624021  addu        $t0, $v1, $v0
    ctx->pc = 0x142da8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x142dac: 0xad8a0018  sw          $t2, 0x18($t4)
    ctx->pc = 0x142dacu;
    WRITE32(ADD32(GPR_U32(ctx, 12), 24), GPR_U32(ctx, 10));
    // 0x142db0: 0x11a00008  beqz        $t5, . + 4 + (0x8 << 2)
    ctx->pc = 0x142DB0u;
    {
        const bool branch_taken_0x142db0 = (GPR_U64(ctx, 13) == GPR_U64(ctx, 0));
        ctx->pc = 0x142DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142DB0u;
            // 0x142db4: 0xe4843  sra         $t1, $t6, 1 (Delay Slot)
        SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 14), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142db0) {
            ctx->pc = 0x142DD4u;
            goto label_142dd4;
        }
    }
    ctx->pc = 0x142DB8u;
    // 0x142db8: 0x51083  sra         $v0, $a1, 2
    ctx->pc = 0x142db8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 5), 2));
    // 0x142dbc: 0xb2043  sra         $a0, $t3, 1
    ctx->pc = 0x142dbcu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 11), 1));
    // 0x142dc0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x142dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x142dc4: 0xf11821  addu        $v1, $a3, $s1
    ctx->pc = 0x142dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 17)));
    // 0x142dc8: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x142dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x142dcc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x142DCCu;
    {
        const bool branch_taken_0x142dcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142DCCu;
            // 0x142dd0: 0x433021  addu        $a2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142dcc) {
            ctx->pc = 0x142DE8u;
            goto label_142de8;
        }
    }
    ctx->pc = 0x142DD4u;
label_142dd4:
    // 0x142dd4: 0x51083  sra         $v0, $a1, 2
    ctx->pc = 0x142dd4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 5), 2));
    // 0x142dd8: 0xb1843  sra         $v1, $t3, 1
    ctx->pc = 0x142dd8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 11), 1));
    // 0x142ddc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x142ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142de0: 0xf12021  addu        $a0, $a3, $s1
    ctx->pc = 0x142de0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 17)));
    // 0x142de4: 0x443021  addu        $a2, $v0, $a0
    ctx->pc = 0x142de4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_142de8:
    // 0x142de8: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x142de8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142dec: 0x650c3  sra         $t2, $a2, 3
    ctx->pc = 0x142decu;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 6), 3));
    // 0x142df0: 0x8fac0008  lw          $t4, 0x8($sp)
    ctx->pc = 0x142df0u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x142df4: 0xa20c0  sll         $a0, $t2, 3
    ctx->pc = 0x142df4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x142df8: 0xa71021  addu        $v0, $a1, $a3
    ctx->pc = 0x142df8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x142dfc: 0x32730001  andi        $s3, $s3, 0x1
    ctx->pc = 0x142dfcu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)1);
    // 0x142e00: 0x838c3  sra         $a3, $t0, 3
    ctx->pc = 0x142e00u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 8), 3));
    // 0x142e04: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x142e04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x142e08: 0x24420200  addiu       $v0, $v0, 0x200
    ctx->pc = 0x142e08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 512));
    // 0x142e0c: 0x718c0  sll         $v1, $a3, 3
    ctx->pc = 0x142e0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x142e10: 0x1031823  subu        $v1, $t0, $v1
    ctx->pc = 0x142e10u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x142e14: 0x1821021  addu        $v0, $t4, $v0
    ctx->pc = 0x142e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 2)));
    // 0x142e18: 0xc43023  subu        $a2, $a2, $a0
    ctx->pc = 0x142e18u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x142e1c: 0x32d90001  andi        $t9, $s6, 0x1
    ctx->pc = 0x142e1cu;
    SET_GPR_U64(ctx, 25, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)1);
    // 0x142e20: 0xade30004  sw          $v1, 0x4($t7)
    ctx->pc = 0x142e20u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 4), GPR_U32(ctx, 3));
    // 0x142e24: 0x1320000f  beqz        $t9, . + 4 + (0xF << 2)
    ctx->pc = 0x142E24u;
    {
        const bool branch_taken_0x142e24 = (GPR_U64(ctx, 25) == GPR_U64(ctx, 0));
        ctx->pc = 0x142E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142E24u;
            // 0x142e28: 0xade20000  sw          $v0, 0x0($t7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 15), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142e24) {
            ctx->pc = 0x142E64u;
            goto label_142e64;
        }
    }
    ctx->pc = 0x142E2Cu;
    // 0x142e2c: 0x1a91004  sllv        $v0, $t1, $t5
    ctx->pc = 0x142e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 13) & 0x1F));
    // 0x142e30: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x142e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x142e34: 0x28420008  slti        $v0, $v0, 0x8
    ctx->pc = 0x142e34u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x142e38: 0x54400017  bnel        $v0, $zero, . + 4 + (0x17 << 2)
    ctx->pc = 0x142E38u;
    {
        const bool branch_taken_0x142e38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x142e38) {
            ctx->pc = 0x142E3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142E38u;
            // 0x142e3c: 0xade90008  sw          $t1, 0x8($t7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 15), 8), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142E98u;
            goto label_142e98;
        }
    }
    ctx->pc = 0x142E40u;
    // 0x142e40: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x142e40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142e44: 0x1a61807  srav        $v1, $a2, $t5
    ctx->pc = 0x142e44u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), GPR_U32(ctx, 13) & 0x1F));
    // 0x142e48: 0x1a21007  srav        $v0, $v0, $t5
    ctx->pc = 0x142e48u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 13) & 0x1F));
    // 0x142e4c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x142e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142e50: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x142e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x142e54: 0x1221823  subu        $v1, $t1, $v0
    ctx->pc = 0x142e54u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x142e58: 0xade20008  sw          $v0, 0x8($t7)
    ctx->pc = 0x142e58u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 8), GPR_U32(ctx, 2));
    // 0x142e5c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x142E5Cu;
    {
        const bool branch_taken_0x142e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142E5Cu;
            // 0x142e60: 0xade3000c  sw          $v1, 0xC($t7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 15), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142e5c) {
            ctx->pc = 0x142E9Cu;
            goto label_142e9c;
        }
    }
    ctx->pc = 0x142E64u;
label_142e64:
    // 0x142e64: 0x1a91004  sllv        $v0, $t1, $t5
    ctx->pc = 0x142e64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 13) & 0x1F));
    // 0x142e68: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x142e68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x142e6c: 0x28420009  slti        $v0, $v0, 0x9
    ctx->pc = 0x142e6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x142e70: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x142E70u;
    {
        const bool branch_taken_0x142e70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x142e70) {
            ctx->pc = 0x142E74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142E70u;
            // 0x142e74: 0xade90008  sw          $t1, 0x8($t7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 15), 8), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142E98u;
            goto label_142e98;
        }
    }
    ctx->pc = 0x142E78u;
    // 0x142e78: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x142e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142e7c: 0x1a61807  srav        $v1, $a2, $t5
    ctx->pc = 0x142e7cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), GPR_U32(ctx, 13) & 0x1F));
    // 0x142e80: 0x1a21007  srav        $v0, $v0, $t5
    ctx->pc = 0x142e80u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 13) & 0x1F));
    // 0x142e84: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x142e84u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142e88: 0x1222023  subu        $a0, $t1, $v0
    ctx->pc = 0x142e88u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x142e8c: 0xade20008  sw          $v0, 0x8($t7)
    ctx->pc = 0x142e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 15), 8), GPR_U32(ctx, 2));
    // 0x142e90: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x142E90u;
    {
        const bool branch_taken_0x142e90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142E90u;
            // 0x142e94: 0xade4000c  sw          $a0, 0xC($t7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 15), 12), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142e90) {
            ctx->pc = 0x142E9Cu;
            goto label_142e9c;
        }
    }
    ctx->pc = 0x142E98u;
label_142e98:
    // 0x142e98: 0xade0000c  sw          $zero, 0xC($t7)
    ctx->pc = 0x142e98u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 12), GPR_U32(ctx, 0));
label_142e9c:
    // 0x142e9c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x142e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142ea0: 0xf42023  subu        $a0, $a3, $s4
    ctx->pc = 0x142ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 20)));
    // 0x142ea4: 0x1a21004  sllv        $v0, $v0, $t5
    ctx->pc = 0x142ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 13) & 0x1F));
    // 0x142ea8: 0x1551823  subu        $v1, $t2, $s5
    ctx->pc = 0x142ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 10), GPR_U32(ctx, 21)));
    // 0x142eac: 0xade20010  sw          $v0, 0x10($t7)
    ctx->pc = 0x142eacu;
    WRITE32(ADD32(GPR_U32(ctx, 15), 16), GPR_U32(ctx, 2));
    // 0x142eb0: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x142eb0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x142eb4: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x142eb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x142eb8: 0x24050140  addiu       $a1, $zero, 0x140
    ctx->pc = 0x142eb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x142ebc: 0x8fa7000c  lw          $a3, 0xC($sp)
    ctx->pc = 0x142ebcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x142ec0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x142ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x142ec4: 0x8f080828  lw          $t0, 0x828($t8)
    ctx->pc = 0x142ec4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 24), 2088)));
    // 0x142ec8: 0x240a0180  addiu       $t2, $zero, 0x180
    ctx->pc = 0x142ec8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    // 0x142ecc: 0x8fac0010  lw          $t4, 0x10($sp)
    ctx->pc = 0x142eccu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x142ed0: 0x2442a6b8  addiu       $v0, $v0, -0x5948
    ctx->pc = 0x142ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944440));
    // 0x142ed4: 0x1054018  mult        $t0, $t0, $a1
    ctx->pc = 0x142ed4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x142ed8: 0x71880  sll         $v1, $a3, 2
    ctx->pc = 0x142ed8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x142edc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x142edcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x142ee0: 0x8a2818  mult        $a1, $a0, $t2
    ctx->pc = 0x142ee0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x142ee4: 0x18a6818  mult        $t5, $t4, $t2
    ctx->pc = 0x142ee4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 13, (int32_t)result); }
    // 0x142ee8: 0x8fcb0010  lw          $t3, 0x10($fp)
    ctx->pc = 0x142ee8u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x142eec: 0x8c6c0000  lw          $t4, 0x0($v1)
    ctx->pc = 0x142eecu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x142ef0: 0x173880  sll         $a3, $s7, 2
    ctx->pc = 0x142ef0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 23), 2));
    // 0x142ef4: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x142ef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x142ef8: 0xe83821  addu        $a3, $a3, $t0
    ctx->pc = 0x142ef8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x142efc: 0xb22021  addu        $a0, $a1, $s2
    ctx->pc = 0x142efcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 18)));
    // 0x142f00: 0x131040  sll         $v0, $s3, 1
    ctx->pc = 0x142f00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x142f04: 0x6b5821  addu        $t3, $v1, $t3
    ctx->pc = 0x142f04u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x142f08: 0x8fa50018  lw          $a1, 0x18($sp)
    ctx->pc = 0x142f08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x142f0c: 0x3071821  addu        $v1, $t8, $a3
    ctx->pc = 0x142f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 7)));
    // 0x142f10: 0x630c0  sll         $a2, $a2, 3
    ctx->pc = 0x142f10u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x142f14: 0xac6c05d0  sw          $t4, 0x5D0($v1)
    ctx->pc = 0x142f14u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1488), GPR_U32(ctx, 12));
    // 0x142f18: 0xa21025  or          $v0, $a1, $v0
    ctx->pc = 0x142f18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x142f1c: 0x8fac0014  lw          $t4, 0x14($sp)
    ctx->pc = 0x142f1cu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x142f20: 0x24c30400  addiu       $v1, $a2, 0x400
    ctx->pc = 0x142f20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 1024));
    // 0x142f24: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x142f24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x142f28: 0x591025  or          $v0, $v0, $t9
    ctx->pc = 0x142f28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 25));
    // 0x142f2c: 0x1884021  addu        $t0, $t4, $t0
    ctx->pc = 0x142f2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 8)));
    // 0x142f30: 0x24c60100  addiu       $a2, $a2, 0x100
    ctx->pc = 0x142f30u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 256));
    // 0x142f34: 0x16a6018  mult        $t4, $t3, $t2
    ctx->pc = 0x142f34u;
    { int64_t result = (int64_t)GPR_S32(ctx, 11) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 12, (int32_t)result); }
    // 0x142f38: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x142f38u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x142f3c: 0x8fc90000  lw          $t1, 0x0($fp)
    ctx->pc = 0x142f3cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x142f40: 0x862021  addu        $a0, $a0, $a2
    ctx->pc = 0x142f40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x142f44: 0x24a5a6d8  addiu       $a1, $a1, -0x5928
    ctx->pc = 0x142f44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294944472));
    // 0x142f48: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x142f48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x142f4c: 0xade40014  sw          $a0, 0x14($t7)
    ctx->pc = 0x142f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 15), 20), GPR_U32(ctx, 4));
    // 0x142f50: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x142f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x142f54: 0xade30018  sw          $v1, 0x18($t7)
    ctx->pc = 0x142f54u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 24), GPR_U32(ctx, 3));
    // 0x142f58: 0x3072021  addu        $a0, $t8, $a3
    ctx->pc = 0x142f58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 7)));
    // 0x142f5c: 0x1895821  addu        $t3, $t4, $t1
    ctx->pc = 0x142f5cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 9)));
    // 0x142f60: 0x8d050000  lw          $a1, 0x0($t0)
    ctx->pc = 0x142f60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x142f64: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x142f64u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142f68: 0x12d4821  addu        $t1, $t1, $t5
    ctx->pc = 0x142f68u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 13)));
    // 0x142f6c: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x142f6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x142f70: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x142f70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x142f74: 0xac8905b0  sw          $t1, 0x5B0($a0)
    ctx->pc = 0x142f74u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 1456), GPR_U32(ctx, 9));
    // 0x142f78: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x142f78u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142f7c: 0xdfbe00a0  ld          $fp, 0xA0($sp)
    ctx->pc = 0x142f7cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x142f80: 0xdfb70090  ld          $s7, 0x90($sp)
    ctx->pc = 0x142f80u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x142f84: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x142f84u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x142f88: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x142f88u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x142f8c: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x142f8cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x142f90: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x142f90u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x142f94: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x142f94u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x142f98: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x142f98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x142f9c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x142f9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x142fa0: 0xac6605e0  sw          $a2, 0x5E0($v1)
    ctx->pc = 0x142fa0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1504), GPR_U32(ctx, 6));
    // 0x142fa4: 0xaceb05c0  sw          $t3, 0x5C0($a3)
    ctx->pc = 0x142fa4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 1472), GPR_U32(ctx, 11));
    // 0x142fa8: 0xad050000  sw          $a1, 0x0($t0)
    ctx->pc = 0x142fa8u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 5));
    // 0x142fac: 0x3e00008  jr          $ra
    ctx->pc = 0x142FACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x142FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142FACu;
            // 0x142fb0: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x142C50u: goto label_142c50;
            case 0x142C58u: goto label_142c58;
            case 0x142CE8u: goto label_142ce8;
            case 0x142D1Cu: goto label_142d1c;
            case 0x142D20u: goto label_142d20;
            case 0x142DD4u: goto label_142dd4;
            case 0x142DE8u: goto label_142de8;
            case 0x142E64u: goto label_142e64;
            case 0x142E98u: goto label_142e98;
            case 0x142E9Cu: goto label_142e9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x142FB4u;
    // 0x142fb4: 0x0  nop
    ctx->pc = 0x142fb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
