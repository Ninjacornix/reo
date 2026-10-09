#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013FBF8
// Address: 0x13fbf8 - 0x13fd58
void sub_0013FBF8_0x13fbf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013FBF8_0x13fbf8");
#endif

    switch (ctx->pc) {
        case 0x13fc34u: goto label_13fc34;
        case 0x13fc88u: goto label_13fc88;
        case 0x13fcc8u: goto label_13fcc8;
        case 0x13fd28u: goto label_13fd28;
        default: break;
    }

    ctx->pc = 0x13fbf8u;

    // 0x13fbf8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13fbf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13fbfc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fbfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fc00: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13fc00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fc04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fc04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13fc08: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13fc08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fc0c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13fc0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13fc10: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13fc10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13fc14: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fc14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc18: 0x18400049  blez        $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x13FC18u;
    {
        const bool branch_taken_0x13fc18 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13FC1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC18u;
            // 0x13fc1c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fc18) {
            ctx->pc = 0x13FD40u;
            goto label_13fd40;
        }
    }
    ctx->pc = 0x13FC20u;
    // 0x13fc20: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13fc20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fc24: 0x50400047  beql        $v0, $zero, . + 4 + (0x47 << 2)
    ctx->pc = 0x13FC24u;
    {
        const bool branch_taken_0x13fc24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fc24) {
            ctx->pc = 0x13FC28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC24u;
            // 0x13fc28: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FD44u;
            goto label_13fd44;
        }
    }
    ctx->pc = 0x13FC2Cu;
    // 0x13fc2c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FC2Cu;
    SET_GPR_U32(ctx, 31, 0x13FC34u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC34u; }
        if (ctx->pc != 0x13FC34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC34u; }
        if (ctx->pc != 0x13FC34u) { return; }
    }
    ctx->pc = 0x13FC34u;
label_13fc34:
    // 0x13fc34: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13fc34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13fc38: 0x16420029  bne         $s2, $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x13FC38u;
    {
        const bool branch_taken_0x13fc38 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13fc38) {
            ctx->pc = 0x13FCE0u;
            goto label_13fce0;
        }
    }
    ctx->pc = 0x13FC40u;
    // 0x13fc40: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x13fc40u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fc44: 0x8e09001c  lw          $t1, 0x1C($s0)
    ctx->pc = 0x13fc44u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fc48: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x13fc48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fc4c: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x13fc4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc50: 0xa93823  subu        $a3, $a1, $t1
    ctx->pc = 0x13fc50u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x13fc54: 0x8e060024  lw          $a2, 0x24($s0)
    ctx->pc = 0x13fc54u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13fc58: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13fc58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13fc5c: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x13fc5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13fc60: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x13FC60u;
    {
        const bool branch_taken_0x13fc60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FC64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC60u;
            // 0x13fc64: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fc60) {
            ctx->pc = 0x13FC90u;
            goto label_13fc90;
        }
    }
    ctx->pc = 0x13FC68u;
    // 0x13fc68: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fc68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc6c: 0xc73023  subu        $a2, $a2, $a3
    ctx->pc = 0x13fc6cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x13fc70: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13fc70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fc74: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x13fc74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13fc78: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x13fc78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x13fc7c: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x13fc7cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x13fc80: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x13FC80u;
    SET_GPR_U32(ctx, 31, 0x13FC88u);
    ctx->pc = 0x13FC84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC80u;
            // 0x13fc84: 0x1242021  addu        $a0, $t1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC88u; }
        if (ctx->pc != 0x13FC88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC88u; }
        if (ctx->pc != 0x13FC88u) { return; }
    }
    ctx->pc = 0x13FC88u;
label_13fc88:
    // 0x13fc88: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x13fc88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fc8c: 0x8e09001c  lw          $t1, 0x1C($s0)
    ctx->pc = 0x13fc8cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
label_13fc90:
    // 0x13fc90: 0x8e280004  lw          $t0, 0x4($s1)
    ctx->pc = 0x13fc90u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc94: 0xa91823  subu        $v1, $a1, $t1
    ctx->pc = 0x13fc94u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x13fc98: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13fc98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fc9c: 0x683821  addu        $a3, $v1, $t0
    ctx->pc = 0x13fc9cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x13fca0: 0x87102a  slt         $v0, $a0, $a3
    ctx->pc = 0x13fca0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x13fca4: 0x5040000a  beql        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x13FCA4u;
    {
        const bool branch_taken_0x13fca4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fca4) {
            ctx->pc = 0x13FCA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCA4u;
            // 0x13fca8: 0x8e020034  lw          $v0, 0x34($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FCD0u;
            goto label_13fcd0;
        }
    }
    ctx->pc = 0x13FCACu;
    // 0x13fcac: 0xe43023  subu        $a2, $a3, $a0
    ctx->pc = 0x13fcacu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x13fcb0: 0x120202d  daddu       $a0, $t1, $zero
    ctx->pc = 0x13fcb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fcb4: 0x106102a  slt         $v0, $t0, $a2
    ctx->pc = 0x13fcb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13fcb8: 0x102300b  movn        $a2, $t0, $v0
    ctx->pc = 0x13fcb8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 8));
    // 0x13fcbc: 0xe62823  subu        $a1, $a3, $a2
    ctx->pc = 0x13fcbcu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x13fcc0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x13FCC0u;
    SET_GPR_U32(ctx, 31, 0x13FCC8u);
    ctx->pc = 0x13FCC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCC0u;
            // 0x13fcc4: 0x852821  addu        $a1, $a0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FCC8u; }
        if (ctx->pc != 0x13FCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FCC8u; }
        if (ctx->pc != 0x13FCC8u) { return; }
    }
    ctx->pc = 0x13FCC8u;
label_13fcc8:
    // 0x13fcc8: 0x8e280004  lw          $t0, 0x4($s1)
    ctx->pc = 0x13fcc8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fccc: 0x8e020034  lw          $v0, 0x34($s0)
    ctx->pc = 0x13fcccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
label_13fcd0:
    // 0x13fcd0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x13fcd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x13fcd4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x13FCD4u;
    {
        const bool branch_taken_0x13fcd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FCD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCD4u;
            // 0x13fcd8: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fcd4) {
            ctx->pc = 0x13FD28u;
            goto label_13fd28;
        }
    }
    ctx->pc = 0x13FCDCu;
    // 0x13fcdc: 0x0  nop
    ctx->pc = 0x13fcdcu;
    // NOP
label_13fce0:
    // 0x13fce0: 0x5640000b  bnel        $s2, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x13FCE0u;
    {
        const bool branch_taken_0x13fce0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x13fce0) {
            ctx->pc = 0x13FCE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCE0u;
            // 0x13fce4: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FD10u;
            goto label_13fd10;
        }
    }
    ctx->pc = 0x13FCE8u;
    // 0x13fce8: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fce8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fcec: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x13fcecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13fcf0: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x13fcf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x13fcf4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13fcf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fcf8: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x13fcf8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x13fcfc: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fcfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fd00: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x13fd00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x13fd04: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13FD04u;
    {
        const bool branch_taken_0x13fd04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FD08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD04u;
            // 0x13fd08: 0xae04002c  sw          $a0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd04) {
            ctx->pc = 0x13FD28u;
            goto label_13fd28;
        }
    }
    ctx->pc = 0x13FD0Cu;
    // 0x13fd0c: 0x0  nop
    ctx->pc = 0x13fd0cu;
    // NOP
label_13fd10:
    // 0x13fd10: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13fd10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13fd14: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FD14u;
    {
        const bool branch_taken_0x13fd14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FD18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD14u;
            // 0x13fd18: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd14) {
            ctx->pc = 0x13FD28u;
            goto label_13fd28;
        }
    }
    ctx->pc = 0x13FD1Cu;
    // 0x13fd1c: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fd1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fd20: 0x40f809  jalr        $v0
    ctx->pc = 0x13FD20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FD28u);
        ctx->pc = 0x13FD24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD20u;
            // 0x13fd24: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FD28u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FD28u; }
            if (ctx->pc != 0x13FD28u) { return; }
        }
        }
    }
    ctx->pc = 0x13FD28u;
label_13fd28:
    // 0x13fd28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fd28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fd2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fd2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fd30: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fd30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fd34: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13fd34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fd38: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13FD38u;
    ctx->pc = 0x13FD3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD38u;
            // 0x13fd3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13FD40u;
label_13fd40:
    // 0x13fd40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fd40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13fd44:
    // 0x13fd44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fd44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fd48: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fd48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fd4c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13fd4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fd50: 0x3e00008  jr          $ra
    ctx->pc = 0x13FD50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FD54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD50u;
            // 0x13fd54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FD58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
