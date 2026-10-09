#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011B010
// Address: 0x11b010 - 0x11b248
void sub_0011B010_0x11b010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011B010_0x11b010");
#endif

    switch (ctx->pc) {
        case 0x11b048u: goto label_11b048;
        case 0x11b054u: goto label_11b054;
        case 0x11b06cu: goto label_11b06c;
        case 0x11b090u: goto label_11b090;
        case 0x11b0d0u: goto label_11b0d0;
        case 0x11b0fcu: goto label_11b0fc;
        case 0x11b138u: goto label_11b138;
        case 0x11b174u: goto label_11b174;
        case 0x11b1b0u: goto label_11b1b0;
        case 0x11b1c0u: goto label_11b1c0;
        case 0x11b1c8u: goto label_11b1c8;
        case 0x11b1dcu: goto label_11b1dc;
        case 0x11b1ecu: goto label_11b1ec;
        case 0x11b204u: goto label_11b204;
        case 0x11b214u: goto label_11b214;
        case 0x11b21cu: goto label_11b21c;
        default: break;
    }

    ctx->pc = 0x11b010u;

    // 0x11b010: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x11b010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x11b014: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11b014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11b018: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11b018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11b01c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11b01cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b020: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11b020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11b024: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11b024u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b028: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11b028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11b02c: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11b02cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11b030: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11b030u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11b034: 0x26b1ca40  addiu       $s1, $s5, -0x35C0
    ctx->pc = 0x11b034u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), 4294953536));
    // 0x11b038: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x11b038u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x11b03c: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11b03cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11b040: 0xc04607e  jal         func_1181F8
    ctx->pc = 0x11B040u;
    SET_GPR_U32(ctx, 31, 0x11B048u);
    ctx->pc = 0x11B044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B040u;
            // 0x11b044: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1181F8u;
    if (runtime->hasFunction(0x1181F8u)) {
        auto targetFn = runtime->lookupFunction(0x1181F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B048u; }
        if (ctx->pc != 0x11B048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001181F8_0x1181f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B048u; }
        if (ctx->pc != 0x11B048u) { return; }
    }
    ctx->pc = 0x11B048u;
label_11b048:
    // 0x11b048: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11b048u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b04c: 0xc04619c  jal         func_118670
    ctx->pc = 0x11B04Cu;
    SET_GPR_U32(ctx, 31, 0x11B054u);
    ctx->pc = 0x11B050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B04Cu;
            // 0x11b050: 0x24040016  addiu       $a0, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B054u; }
        if (ctx->pc != 0x11B054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B054u; }
        if (ctx->pc != 0x11B054u) { return; }
    }
    ctx->pc = 0x11B054u;
label_11b054:
    // 0x11b054: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11b054u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11b058: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11b058u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11b05c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B05Cu;
    {
        const bool branch_taken_0x11b05c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b05c) {
            ctx->pc = 0x11B074u;
            goto label_11b074;
        }
    }
    ctx->pc = 0x11B064u;
    // 0x11b064: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B064u;
    SET_GPR_U32(ctx, 31, 0x11B06Cu);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B06Cu; }
        if (ctx->pc != 0x11B06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B06Cu; }
        if (ctx->pc != 0x11B06Cu) { return; }
    }
    ctx->pc = 0x11B06Cu;
label_11b06c:
    // 0x11b06c: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x11B06Cu;
    {
        const bool branch_taken_0x11b06c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B06Cu;
            // 0x11b070: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b06c) {
            ctx->pc = 0x11B220u;
            goto label_11b220;
        }
    }
    ctx->pc = 0x11B074u;
label_11b074:
    // 0x11b074: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11B074u;
    {
        const bool branch_taken_0x11b074 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11b074) {
            ctx->pc = 0x11B088u;
            goto label_11b088;
        }
    }
    ctx->pc = 0x11B07Cu;
    // 0x11b07c: 0x8e130004  lw          $s3, 0x4($s0)
    ctx->pc = 0x11b07cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11b080: 0x16600005  bnez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B080u;
    {
        const bool branch_taken_0x11b080 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x11B084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B080u;
            // 0x11b084: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b080) {
            ctx->pc = 0x11B098u;
            goto label_11b098;
        }
    }
    ctx->pc = 0x11B088u;
label_11b088:
    // 0x11b088: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B088u;
    SET_GPR_U32(ctx, 31, 0x11B090u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B090u; }
        if (ctx->pc != 0x11B090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B090u; }
        if (ctx->pc != 0x11B090u) { return; }
    }
    ctx->pc = 0x11B090u;
label_11b090:
    // 0x11b090: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x11B090u;
    {
        const bool branch_taken_0x11b090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B090u;
            // 0x11b094: 0x2402fff7  addiu       $v0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b090) {
            ctx->pc = 0x11B220u;
            goto label_11b220;
        }
    }
    ctx->pc = 0x11B098u;
label_11b098:
    // 0x11b098: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x11b098u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11b09c: 0x2442df40  addiu       $v0, $v0, -0x20C0
    ctx->pc = 0x11b09cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958912));
    // 0x11b0a0: 0xfe320010  sd          $s2, 0x10($s1)
    ctx->pc = 0x11b0a0u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 16), GPR_U64(ctx, 18));
    // 0x11b0a4: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x11b0a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x11b0a8: 0xae23000c  sw          $v1, 0xC($s1)
    ctx->pc = 0x11b0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
    // 0x11b0ac: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x11b0acu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x11b0b0: 0xae340018  sw          $s4, 0x18($s1)
    ctx->pc = 0x11b0b0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 20));
    // 0x11b0b4: 0xae22001c  sw          $v0, 0x1C($s1)
    ctx->pc = 0x11b0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 2));
    // 0x11b0b8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x11b0b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11b0bc: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11b0bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11b0c0: 0xafa50014  sw          $a1, 0x14($sp)
    ctx->pc = 0x11b0c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    // 0x11b0c4: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11b0c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11b0c8: 0xc045188  jal         func_114620
    ctx->pc = 0x11B0C8u;
    SET_GPR_U32(ctx, 31, 0x11B0D0u);
    ctx->pc = 0x11B0CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B0C8u;
            // 0x11b0cc: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B0D0u; }
        if (ctx->pc != 0x11B0D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B0D0u; }
        if (ctx->pc != 0x11B0D0u) { return; }
    }
    ctx->pc = 0x11B0D0u;
label_11b0d0:
    // 0x11b0d0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11b0d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b0d4: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x11b0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x11b0d8: 0x27a20030  addiu       $v0, $sp, 0x30
    ctx->pc = 0x11b0d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b0dc: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x11b0dcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x11b0e0: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x11b0e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x11b0e4: 0x32628000  andi        $v0, $s3, 0x8000
    ctx->pc = 0x11b0e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)32768);
    // 0x11b0e8: 0x10400024  beqz        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x11B0E8u;
    {
        const bool branch_taken_0x11b0e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B0E8u;
            // 0x11b0ec: 0xaeb2ca40  sw          $s2, -0x35C0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 4294953536), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b0e8) {
            ctx->pc = 0x11B17Cu;
            goto label_11b17c;
        }
    }
    ctx->pc = 0x11B0F0u;
    // 0x11b0f0: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x11b0f0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x11b0f4: 0xc045198  jal         func_114660
    ctx->pc = 0x11B0F4u;
    SET_GPR_U32(ctx, 31, 0x11B0FCu);
    ctx->pc = 0x11B0F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B0F4u;
            // 0x11b0f8: 0x8e849dec  lw          $a0, -0x6214($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B0FCu; }
        if (ctx->pc != 0x11B0FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B0FCu; }
        if (ctx->pc != 0x11B0FCu) { return; }
    }
    ctx->pc = 0x11B0FCu;
label_11b0fc:
    // 0x11b0fc: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x11b0fcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x11b100: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b100u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b104: 0x8ce39d58  lw          $v1, -0x62A8($a3)
    ctx->pc = 0x11b104u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4294942040)));
    // 0x11b108: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11b108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11b10c: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11B10Cu;
    {
        const bool branch_taken_0x11b10c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x11B110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B10Cu;
            // 0x11b110: 0x3c160026  lui         $s6, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b10c) {
            ctx->pc = 0x11B130u;
            goto label_11b130;
        }
    }
    ctx->pc = 0x11B114u;
    // 0x11b114: 0x8ea3ca40  lw          $v1, -0x35C0($s5)
    ctx->pc = 0x11b114u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294953536)));
    // 0x11b118: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11b118u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11b11c: 0x31023  negu        $v0, $v1
    ctx->pc = 0x11b11cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x11b120: 0xace39d58  sw          $v1, -0x62A8($a3)
    ctx->pc = 0x11b120u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294942040), GPR_U32(ctx, 3));
    // 0x11b124: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11B124u;
    {
        const bool branch_taken_0x11b124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B124u;
            // 0x11b128: 0xaea2ca40  sw          $v0, -0x35C0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 4294953536), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b124) {
            ctx->pc = 0x11B16Cu;
            goto label_11b16c;
        }
    }
    ctx->pc = 0x11B12Cu;
    // 0x11b12c: 0x0  nop
    ctx->pc = 0x11b12cu;
    // NOP
label_11b130:
    // 0x11b130: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11b130u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11b134: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x11b134u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_11b138:
    // 0x11b138: 0x28c20020  slti        $v0, $a2, 0x20
    ctx->pc = 0x11b138u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x11b13c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x11B13Cu;
    {
        const bool branch_taken_0x11b13c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B13Cu;
            // 0x11b140: 0x61080  sll         $v0, $a2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b13c) {
            ctx->pc = 0x11B16Cu;
            goto label_11b16c;
        }
    }
    ctx->pc = 0x11B144u;
    // 0x11b144: 0x24e39d58  addiu       $v1, $a3, -0x62A8
    ctx->pc = 0x11b144u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294942040));
    // 0x11b148: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x11b148u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x11b14c: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x11b14cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11b150: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x11b150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11b154: 0x1444fff8  bne         $v0, $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B154u;
    {
        const bool branch_taken_0x11b154 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x11B158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B154u;
            // 0x11b158: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b154) {
            ctx->pc = 0x11B138u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b138;
        }
    }
    ctx->pc = 0x11B15Cu;
    // 0x11b15c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x11b15cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11b160: 0x21823  negu        $v1, $v0
    ctx->pc = 0x11b160u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x11b164: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x11b164u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x11b168: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x11b168u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_11b16c:
    // 0x11b16c: 0xc045190  jal         func_114640
    ctx->pc = 0x11B16Cu;
    SET_GPR_U32(ctx, 31, 0x11B174u);
    ctx->pc = 0x11B170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B16Cu;
            // 0x11b170: 0x8e849dec  lw          $a0, -0x6214($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B174u; }
        if (ctx->pc != 0x11B174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B174u; }
        if (ctx->pc != 0x11B174u) { return; }
    }
    ctx->pc = 0x11B174u;
label_11b174:
    // 0x11b174: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x11B174u;
    {
        const bool branch_taken_0x11b174 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B174u;
            // 0x11b178: 0x2610d680  addiu       $s0, $s0, -0x2980 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294956672));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b174) {
            ctx->pc = 0x11B188u;
            goto label_11b188;
        }
    }
    ctx->pc = 0x11B17Cu;
label_11b17c:
    // 0x11b17c: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11b17cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11b180: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11b180u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11b184: 0x2610d680  addiu       $s0, $s0, -0x2980
    ctx->pc = 0x11b184u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294956672));
label_11b188:
    // 0x11b188: 0x26c4e140  addiu       $a0, $s6, -0x1EC0
    ctx->pc = 0x11b188u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294959424));
    // 0x11b18c: 0x26a7ca40  addiu       $a3, $s5, -0x35C0
    ctx->pc = 0x11b18cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), 4294953536));
    // 0x11b190: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b190u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b194: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x11b194u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x11b198: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b198u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b19c: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x11b19cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11b1a0: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11b1a0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b1a4: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b1a4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b1a8: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B1A8u;
    SET_GPR_U32(ctx, 31, 0x11B1B0u);
    ctx->pc = 0x11B1ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1A8u;
            // 0x11b1ac: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1B0u; }
        if (ctx->pc != 0x11B1B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1B0u; }
        if (ctx->pc != 0x11B1B0u) { return; }
    }
    ctx->pc = 0x11B1B0u;
label_11b1b0:
    // 0x11b1b0: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B1B0u;
    {
        const bool branch_taken_0x11b1b0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1B0u;
            // 0x11b1b4: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b1b0) {
            ctx->pc = 0x11B1D0u;
            goto label_11b1d0;
        }
    }
    ctx->pc = 0x11B1B8u;
    // 0x11b1b8: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B1B8u;
    SET_GPR_U32(ctx, 31, 0x11B1C0u);
    ctx->pc = 0x11B1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1B8u;
            // 0x11b1bc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1C0u; }
        if (ctx->pc != 0x11B1C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1C0u; }
        if (ctx->pc != 0x11B1C0u) { return; }
    }
    ctx->pc = 0x11B1C0u;
label_11b1c0:
    // 0x11b1c0: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B1C0u;
    SET_GPR_U32(ctx, 31, 0x11B1C8u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1C8u; }
        if (ctx->pc != 0x11B1C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1C8u; }
        if (ctx->pc != 0x11B1C8u) { return; }
    }
    ctx->pc = 0x11B1C8u;
label_11b1c8:
    // 0x11b1c8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x11B1C8u;
    {
        const bool branch_taken_0x11b1c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B1CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1C8u;
            // 0x11b1cc: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b1c8) {
            ctx->pc = 0x11B220u;
            goto label_11b220;
        }
    }
    ctx->pc = 0x11B1D0u;
label_11b1d0:
    // 0x11b1d0: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x11b1d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x11b1d4: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B1D4u;
    SET_GPR_U32(ctx, 31, 0x11B1DCu);
    ctx->pc = 0x11B1D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1D4u;
            // 0x11b1d8: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1DCu; }
        if (ctx->pc != 0x11B1DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1DCu; }
        if (ctx->pc != 0x11B1DCu) { return; }
    }
    ctx->pc = 0x11B1DCu;
label_11b1dc:
    // 0x11b1dc: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B1DCu;
    {
        const bool branch_taken_0x11b1dc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x11B1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1DCu;
            // 0x11b1e0: 0x32628000  andi        $v0, $s3, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b1dc) {
            ctx->pc = 0x11B1F4u;
            goto label_11b1f4;
        }
    }
    ctx->pc = 0x11B1E4u;
    // 0x11b1e4: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B1E4u;
    SET_GPR_U32(ctx, 31, 0x11B1ECu);
    ctx->pc = 0x11B1E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1E4u;
            // 0x11b1e8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1ECu; }
        if (ctx->pc != 0x11B1ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B1ECu; }
        if (ctx->pc != 0x11B1ECu) { return; }
    }
    ctx->pc = 0x11B1ECu;
label_11b1ec:
    // 0x11b1ec: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x11B1ECu;
    {
        const bool branch_taken_0x11b1ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1ECu;
            // 0x11b1f0: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b1ec) {
            ctx->pc = 0x11B220u;
            goto label_11b220;
        }
    }
    ctx->pc = 0x11B1F4u;
label_11b1f4:
    // 0x11b1f4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B1F4u;
    {
        const bool branch_taken_0x11b1f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11b1f4) {
            ctx->pc = 0x11B20Cu;
            goto label_11b20c;
        }
    }
    ctx->pc = 0x11B1FCu;
    // 0x11b1fc: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B1FCu;
    SET_GPR_U32(ctx, 31, 0x11B204u);
    ctx->pc = 0x11B200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B1FCu;
            // 0x11b200: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B204u; }
        if (ctx->pc != 0x11B204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B204u; }
        if (ctx->pc != 0x11B204u) { return; }
    }
    ctx->pc = 0x11B204u;
label_11b204:
    // 0x11b204: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B204u;
    {
        const bool branch_taken_0x11b204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B204u;
            // 0x11b208: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b204) {
            ctx->pc = 0x11B220u;
            goto label_11b220;
        }
    }
    ctx->pc = 0x11B20Cu;
label_11b20c:
    // 0x11b20c: 0xc045198  jal         func_114660
    ctx->pc = 0x11B20Cu;
    SET_GPR_U32(ctx, 31, 0x11B214u);
    ctx->pc = 0x11B210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B20Cu;
            // 0x11b210: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B214u; }
        if (ctx->pc != 0x11B214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B214u; }
        if (ctx->pc != 0x11B214u) { return; }
    }
    ctx->pc = 0x11B214u;
label_11b214:
    // 0x11b214: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B214u;
    SET_GPR_U32(ctx, 31, 0x11B21Cu);
    ctx->pc = 0x11B218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B214u;
            // 0x11b218: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B21Cu; }
        if (ctx->pc != 0x11B21Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B21Cu; }
        if (ctx->pc != 0x11B21Cu) { return; }
    }
    ctx->pc = 0x11B21Cu;
label_11b21c:
    // 0x11b21c: 0xdfa20030  ld          $v0, 0x30($sp)
    ctx->pc = 0x11b21cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_11b220:
    // 0x11b220: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x11b220u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11b224: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11b224u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11b228: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11b228u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11b22c: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11b22cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11b230: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11b230u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11b234: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11b234u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11b238: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11b238u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11b23c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11b23cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11b240: 0x3e00008  jr          $ra
    ctx->pc = 0x11B240u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B240u;
            // 0x11b244: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B048u: goto label_11b048;
            case 0x11B054u: goto label_11b054;
            case 0x11B06Cu: goto label_11b06c;
            case 0x11B074u: goto label_11b074;
            case 0x11B088u: goto label_11b088;
            case 0x11B090u: goto label_11b090;
            case 0x11B098u: goto label_11b098;
            case 0x11B0D0u: goto label_11b0d0;
            case 0x11B0FCu: goto label_11b0fc;
            case 0x11B130u: goto label_11b130;
            case 0x11B138u: goto label_11b138;
            case 0x11B16Cu: goto label_11b16c;
            case 0x11B174u: goto label_11b174;
            case 0x11B17Cu: goto label_11b17c;
            case 0x11B188u: goto label_11b188;
            case 0x11B1B0u: goto label_11b1b0;
            case 0x11B1C0u: goto label_11b1c0;
            case 0x11B1C8u: goto label_11b1c8;
            case 0x11B1D0u: goto label_11b1d0;
            case 0x11B1DCu: goto label_11b1dc;
            case 0x11B1ECu: goto label_11b1ec;
            case 0x11B1F4u: goto label_11b1f4;
            case 0x11B204u: goto label_11b204;
            case 0x11B20Cu: goto label_11b20c;
            case 0x11B214u: goto label_11b214;
            case 0x11B21Cu: goto label_11b21c;
            case 0x11B220u: goto label_11b220;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B248u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
