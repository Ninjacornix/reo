#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AEF00
// Address: 0x1aef00 - 0x1af040
void sub_001AEF00_0x1aef00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AEF00_0x1aef00");
#endif

    switch (ctx->pc) {
        case 0x1aef20u: goto label_1aef20;
        case 0x1aef84u: goto label_1aef84;
        case 0x1aefc0u: goto label_1aefc0;
        case 0x1aeffcu: goto label_1aeffc;
        default: break;
    }

    ctx->pc = 0x1aef00u;

    // 0x1aef00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1aef00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1aef04: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1aef04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1aef08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1aef08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1aef0c: 0x2484fb60  addiu       $a0, $a0, -0x4A0
    ctx->pc = 0x1aef0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966112));
    // 0x1aef10: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1aef10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aef14: 0x24064234  addiu       $a2, $zero, 0x4234
    ctx->pc = 0x1aef14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16948));
    // 0x1aef18: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AEF18u;
    SET_GPR_U32(ctx, 31, 0x1AEF20u);
    ctx->pc = 0x1AEF1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEF18u;
            // 0x1aef1c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEF20u; }
        if (ctx->pc != 0x1AEF20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEF20u; }
        if (ctx->pc != 0x1AEF20u) { return; }
    }
    ctx->pc = 0x1AEF20u;
label_1aef20:
    // 0x1aef20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aef20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aef24: 0x3c070032  lui         $a3, 0x32
    ctx->pc = 0x1aef24u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)50 << 16));
    // 0x1aef28: 0x8c283bd8  lw          $t0, 0x3BD8($at)
    ctx->pc = 0x1aef28u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 15320)));
    // 0x1aef2c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1aef2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1aef30: 0x24090001  addiu       $t1, $zero, 0x1
    ctx->pc = 0x1aef30u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aef34: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1aef34u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aef38: 0x24e7fb60  addiu       $a3, $a3, -0x4A0
    ctx->pc = 0x1aef38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294966112));
    // 0x1aef3c: 0x248442d0  addiu       $a0, $a0, 0x42D0
    ctx->pc = 0x1aef3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17104));
    // 0x1aef40: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1aef40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1aef44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aef44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aef48: 0x35080001  ori         $t0, $t0, 0x1
    ctx->pc = 0x1aef48u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)1);
    // 0x1aef4c: 0xa029fb7c  sb          $t1, -0x484($at)
    ctx->pc = 0x1aef4cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294966140), (uint8_t)GPR_U32(ctx, 9));
    // 0x1aef50: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aef50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aef54: 0x8c261ef4  lw          $a2, 0x1EF4($at)
    ctx->pc = 0x1aef54u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 7924)));
    // 0x1aef58: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aef58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aef5c: 0x34c60001  ori         $a2, $a2, 0x1
    ctx->pc = 0x1aef5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1);
    // 0x1aef60: 0x9025fb83  lbu         $a1, -0x47D($at)
    ctx->pc = 0x1aef60u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294966147)));
    // 0x1aef64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aef64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aef68: 0x34a50003  ori         $a1, $a1, 0x3
    ctx->pc = 0x1aef68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3);
    // 0x1aef6c: 0xac283bd8  sw          $t0, 0x3BD8($at)
    ctx->pc = 0x1aef6cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 15320), GPR_U32(ctx, 8));
    // 0x1aef70: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aef70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aef74: 0xac261ef4  sw          $a2, 0x1EF4($at)
    ctx->pc = 0x1aef74u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 7924), GPR_U32(ctx, 6));
    // 0x1aef78: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aef78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aef7c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1AEF7Cu;
    {
        const bool branch_taken_0x1aef7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AEF80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEF7Cu;
            // 0x1aef80: 0xa025fb83  sb          $a1, -0x47D($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294966147), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aef7c) {
            ctx->pc = 0x1AEFA4u;
            goto label_1aefa4;
        }
    }
    ctx->pc = 0x1AEF84u;
label_1aef84:
    // 0x1aef84: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1aef84u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1aef88: 0x52943  sra         $a1, $a1, 5
    ctx->pc = 0x1aef88u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 5));
    // 0x1aef8c: 0xc94004  sllv        $t0, $t1, $a2
    ctx->pc = 0x1aef8cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 6) & 0x1F));
    // 0x1aef90: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1aef90u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1aef94: 0xe53021  addu        $a2, $a3, $a1
    ctx->pc = 0x1aef94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x1aef98: 0x8cc54094  lw          $a1, 0x4094($a2)
    ctx->pc = 0x1aef98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16532)));
    // 0x1aef9c: 0xa82825  or          $a1, $a1, $t0
    ctx->pc = 0x1aef9cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 8));
    // 0x1aefa0: 0xacc54094  sw          $a1, 0x4094($a2)
    ctx->pc = 0x1aefa0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16532), GPR_U32(ctx, 5));
label_1aefa4:
    // 0x1aefa4: 0xa2840  sll         $a1, $t2, 1
    ctx->pc = 0x1aefa4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
    // 0x1aefa8: 0x852821  addu        $a1, $a0, $a1
    ctx->pc = 0x1aefa8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1aefac: 0x84a50000  lh          $a1, 0x0($a1)
    ctx->pc = 0x1aefacu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1aefb0: 0x14a3fff4  bne         $a1, $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1AEFB0u;
    {
        const bool branch_taken_0x1aefb0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x1AEFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEFB0u;
            // 0x1aefb4: 0x30a6001f  andi        $a2, $a1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aefb0) {
            ctx->pc = 0x1AEF84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aef84;
        }
    }
    ctx->pc = 0x1AEFB8u;
    // 0x1aefb8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1AEFB8u;
    {
        const bool branch_taken_0x1aefb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AEFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEFB8u;
            // 0x1aefbc: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aefb8) {
            ctx->pc = 0x1AF000u;
            goto label_1af000;
        }
    }
    ctx->pc = 0x1AEFC0u;
label_1aefc0:
    // 0x1aefc0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1aefc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1aefc4: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1aefc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1aefc8: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1aefc8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1aefcc: 0x452821  addu        $a1, $v0, $a1
    ctx->pc = 0x1aefccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1aefd0: 0x2484fb60  addiu       $a0, $a0, -0x4A0
    ctx->pc = 0x1aefd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966112));
    // 0x1aefd4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1aefd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1aefd8: 0x244242b0  addiu       $v0, $v0, 0x42B0
    ctx->pc = 0x1aefd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17072));
    // 0x1aefdc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1aefdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1aefe0: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1aefe0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1aefe4: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1aefe4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1aefe8: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1aefe8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1aefec: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aefecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aeff0: 0x2464009c  addiu       $a0, $v1, 0x9C
    ctx->pc = 0x1aeff0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 156));
    // 0x1aeff4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AEFF4u;
    SET_GPR_U32(ctx, 31, 0x1AEFFCu);
    ctx->pc = 0x1AEFF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEFF4u;
            // 0x1aeff8: 0x24a5fec8  addiu       $a1, $a1, -0x138 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966984));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEFFCu; }
        if (ctx->pc != 0x1AEFFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEFFCu; }
        if (ctx->pc != 0x1AEFFCu) { return; }
    }
    ctx->pc = 0x1AEFFCu;
label_1aeffc:
    // 0x1aeffc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1aeffcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1af000:
    // 0x1af000: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1af000u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1af004: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1af004u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1af008: 0x24844268  addiu       $a0, $a0, 0x4268
    ctx->pc = 0x1af008u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17000));
    // 0x1af00c: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x1af00cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1af010: 0x90840000  lbu         $a0, 0x0($a0)
    ctx->pc = 0x1af010u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af014: 0x1483ffea  bne         $a0, $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1AF014u;
    {
        const bool branch_taken_0x1af014 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1AF018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF014u;
            // 0x1af018: 0x308500ff  andi        $a1, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af014) {
            ctx->pc = 0x1AEFC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aefc0;
        }
    }
    ctx->pc = 0x1AF01Cu;
    // 0x1af01c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af01cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af020: 0xa030fb80  sb          $s0, -0x480($at)
    ctx->pc = 0x1af020u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294966144), (uint8_t)GPR_U32(ctx, 16));
    // 0x1af024: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1af024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1af028: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1af028u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af02c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF02Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF02Cu;
            // 0x1af030: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AEF20u: goto label_1aef20;
            case 0x1AEF84u: goto label_1aef84;
            case 0x1AEFA4u: goto label_1aefa4;
            case 0x1AEFC0u: goto label_1aefc0;
            case 0x1AEFFCu: goto label_1aeffc;
            case 0x1AF000u: goto label_1af000;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF034u;
    // 0x1af034: 0x0  nop
    ctx->pc = 0x1af034u;
    // NOP
    // 0x1af038: 0x0  nop
    ctx->pc = 0x1af038u;
    // NOP
    // 0x1af03c: 0x0  nop
    ctx->pc = 0x1af03cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
