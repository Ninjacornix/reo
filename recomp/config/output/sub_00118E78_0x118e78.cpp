#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00118E78
// Address: 0x118e78 - 0x1190b0
void sub_00118E78_0x118e78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00118E78_0x118e78");
#endif

    switch (ctx->pc) {
        case 0x118eb0u: goto label_118eb0;
        case 0x118ebcu: goto label_118ebc;
        case 0x118ed4u: goto label_118ed4;
        case 0x118ef8u: goto label_118ef8;
        case 0x118f38u: goto label_118f38;
        case 0x118f64u: goto label_118f64;
        case 0x118fa0u: goto label_118fa0;
        case 0x118fdcu: goto label_118fdc;
        case 0x119018u: goto label_119018;
        case 0x119028u: goto label_119028;
        case 0x119030u: goto label_119030;
        case 0x119044u: goto label_119044;
        case 0x119054u: goto label_119054;
        case 0x11906cu: goto label_11906c;
        case 0x11907cu: goto label_11907c;
        case 0x119084u: goto label_119084;
        default: break;
    }

    ctx->pc = 0x118e78u;

    // 0x118e78: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x118e78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x118e7c: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x118e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x118e80: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x118e80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x118e84: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x118e84u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118e88: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x118e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x118e8c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x118e8cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118e90: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x118e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x118e94: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x118e94u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x118e98: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x118e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x118e9c: 0x26b1ca40  addiu       $s1, $s5, -0x35C0
    ctx->pc = 0x118e9cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), 4294953536));
    // 0x118ea0: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x118ea0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x118ea4: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x118ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x118ea8: 0xc04607e  jal         func_1181F8
    ctx->pc = 0x118EA8u;
    SET_GPR_U32(ctx, 31, 0x118EB0u);
    ctx->pc = 0x118EACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118EA8u;
            // 0x118eac: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1181F8u;
    if (runtime->hasFunction(0x1181F8u)) {
        auto targetFn = runtime->lookupFunction(0x1181F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118EB0u; }
        if (ctx->pc != 0x118EB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001181F8_0x1181f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118EB0u; }
        if (ctx->pc != 0x118EB0u) { return; }
    }
    ctx->pc = 0x118EB0u;
label_118eb0:
    // 0x118eb0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x118eb0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118eb4: 0xc04619c  jal         func_118670
    ctx->pc = 0x118EB4u;
    SET_GPR_U32(ctx, 31, 0x118EBCu);
    ctx->pc = 0x118EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118EB4u;
            // 0x118eb8: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118EBCu; }
        if (ctx->pc != 0x118EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118EBCu; }
        if (ctx->pc != 0x118EBCu) { return; }
    }
    ctx->pc = 0x118EBCu;
label_118ebc:
    // 0x118ebc: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x118ebcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x118ec0: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x118ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x118ec4: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x118EC4u;
    {
        const bool branch_taken_0x118ec4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x118ec4) {
            ctx->pc = 0x118EDCu;
            goto label_118edc;
        }
    }
    ctx->pc = 0x118ECCu;
    // 0x118ecc: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118ECCu;
    SET_GPR_U32(ctx, 31, 0x118ED4u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118ED4u; }
        if (ctx->pc != 0x118ED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118ED4u; }
        if (ctx->pc != 0x118ED4u) { return; }
    }
    ctx->pc = 0x118ED4u;
label_118ed4:
    // 0x118ed4: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x118ED4u;
    {
        const bool branch_taken_0x118ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118ED4u;
            // 0x118ed8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118ed4) {
            ctx->pc = 0x119088u;
            goto label_119088;
        }
    }
    ctx->pc = 0x118EDCu;
label_118edc:
    // 0x118edc: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x118EDCu;
    {
        const bool branch_taken_0x118edc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x118edc) {
            ctx->pc = 0x118EF0u;
            goto label_118ef0;
        }
    }
    ctx->pc = 0x118EE4u;
    // 0x118ee4: 0x8e130004  lw          $s3, 0x4($s0)
    ctx->pc = 0x118ee4u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x118ee8: 0x16600005  bnez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x118EE8u;
    {
        const bool branch_taken_0x118ee8 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x118EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118EE8u;
            // 0x118eec: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118ee8) {
            ctx->pc = 0x118F00u;
            goto label_118f00;
        }
    }
    ctx->pc = 0x118EF0u;
label_118ef0:
    // 0x118ef0: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118EF0u;
    SET_GPR_U32(ctx, 31, 0x118EF8u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118EF8u; }
        if (ctx->pc != 0x118EF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118EF8u; }
        if (ctx->pc != 0x118EF8u) { return; }
    }
    ctx->pc = 0x118EF8u;
label_118ef8:
    // 0x118ef8: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x118EF8u;
    {
        const bool branch_taken_0x118ef8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118EF8u;
            // 0x118efc: 0x2402fff7  addiu       $v0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118ef8) {
            ctx->pc = 0x119088u;
            goto label_119088;
        }
    }
    ctx->pc = 0x118F00u;
label_118f00:
    // 0x118f00: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x118f00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x118f04: 0x2442df40  addiu       $v0, $v0, -0x20C0
    ctx->pc = 0x118f04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958912));
    // 0x118f08: 0xae320010  sw          $s2, 0x10($s1)
    ctx->pc = 0x118f08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 18));
    // 0x118f0c: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x118f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x118f10: 0xae23000c  sw          $v1, 0xC($s1)
    ctx->pc = 0x118f10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
    // 0x118f14: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x118f14u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x118f18: 0xae340014  sw          $s4, 0x14($s1)
    ctx->pc = 0x118f18u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 20));
    // 0x118f1c: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x118f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x118f20: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x118f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x118f24: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x118f24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x118f28: 0xafa50014  sw          $a1, 0x14($sp)
    ctx->pc = 0x118f28u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    // 0x118f2c: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x118f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x118f30: 0xc045188  jal         func_114620
    ctx->pc = 0x118F30u;
    SET_GPR_U32(ctx, 31, 0x118F38u);
    ctx->pc = 0x118F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118F30u;
            // 0x118f34: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118F38u; }
        if (ctx->pc != 0x118F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118F38u; }
        if (ctx->pc != 0x118F38u) { return; }
    }
    ctx->pc = 0x118F38u;
label_118f38:
    // 0x118f38: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x118f38u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118f3c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x118f3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x118f40: 0x27a20030  addiu       $v0, $sp, 0x30
    ctx->pc = 0x118f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x118f44: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x118f44u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x118f48: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x118f48u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x118f4c: 0x32628000  andi        $v0, $s3, 0x8000
    ctx->pc = 0x118f4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)32768);
    // 0x118f50: 0x10400024  beqz        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x118F50u;
    {
        const bool branch_taken_0x118f50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x118F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118F50u;
            // 0x118f54: 0xaeb2ca40  sw          $s2, -0x35C0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 4294953536), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118f50) {
            ctx->pc = 0x118FE4u;
            goto label_118fe4;
        }
    }
    ctx->pc = 0x118F58u;
    // 0x118f58: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x118f58u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x118f5c: 0xc045198  jal         func_114660
    ctx->pc = 0x118F5Cu;
    SET_GPR_U32(ctx, 31, 0x118F64u);
    ctx->pc = 0x118F60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118F5Cu;
            // 0x118f60: 0x8e849dec  lw          $a0, -0x6214($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118F64u; }
        if (ctx->pc != 0x118F64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118F64u; }
        if (ctx->pc != 0x118F64u) { return; }
    }
    ctx->pc = 0x118F64u;
label_118f64:
    // 0x118f64: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x118f64u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x118f68: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x118f68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118f6c: 0x8ce39d58  lw          $v1, -0x62A8($a3)
    ctx->pc = 0x118f6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4294942040)));
    // 0x118f70: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x118f70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x118f74: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x118F74u;
    {
        const bool branch_taken_0x118f74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x118F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118F74u;
            // 0x118f78: 0x3c160026  lui         $s6, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118f74) {
            ctx->pc = 0x118F98u;
            goto label_118f98;
        }
    }
    ctx->pc = 0x118F7Cu;
    // 0x118f7c: 0x8ea3ca40  lw          $v1, -0x35C0($s5)
    ctx->pc = 0x118f7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294953536)));
    // 0x118f80: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x118f80u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x118f84: 0x31023  negu        $v0, $v1
    ctx->pc = 0x118f84u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x118f88: 0xace39d58  sw          $v1, -0x62A8($a3)
    ctx->pc = 0x118f88u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294942040), GPR_U32(ctx, 3));
    // 0x118f8c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x118F8Cu;
    {
        const bool branch_taken_0x118f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118F8Cu;
            // 0x118f90: 0xaea2ca40  sw          $v0, -0x35C0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 4294953536), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118f8c) {
            ctx->pc = 0x118FD4u;
            goto label_118fd4;
        }
    }
    ctx->pc = 0x118F94u;
    // 0x118f94: 0x0  nop
    ctx->pc = 0x118f94u;
    // NOP
label_118f98:
    // 0x118f98: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x118f98u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x118f9c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x118f9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_118fa0:
    // 0x118fa0: 0x28c20020  slti        $v0, $a2, 0x20
    ctx->pc = 0x118fa0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x118fa4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x118FA4u;
    {
        const bool branch_taken_0x118fa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x118FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118FA4u;
            // 0x118fa8: 0x61080  sll         $v0, $a2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118fa4) {
            ctx->pc = 0x118FD4u;
            goto label_118fd4;
        }
    }
    ctx->pc = 0x118FACu;
    // 0x118fac: 0x24e39d58  addiu       $v1, $a3, -0x62A8
    ctx->pc = 0x118facu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294942040));
    // 0x118fb0: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x118fb0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x118fb4: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x118fb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x118fb8: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x118fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x118fbc: 0x1444fff8  bne         $v0, $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x118FBCu;
    {
        const bool branch_taken_0x118fbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x118FC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118FBCu;
            // 0x118fc0: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118fbc) {
            ctx->pc = 0x118FA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118fa0;
        }
    }
    ctx->pc = 0x118FC4u;
    // 0x118fc4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x118fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x118fc8: 0x21823  negu        $v1, $v0
    ctx->pc = 0x118fc8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x118fcc: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x118fccu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x118fd0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x118fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_118fd4:
    // 0x118fd4: 0xc045190  jal         func_114640
    ctx->pc = 0x118FD4u;
    SET_GPR_U32(ctx, 31, 0x118FDCu);
    ctx->pc = 0x118FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118FD4u;
            // 0x118fd8: 0x8e849dec  lw          $a0, -0x6214($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118FDCu; }
        if (ctx->pc != 0x118FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118FDCu; }
        if (ctx->pc != 0x118FDCu) { return; }
    }
    ctx->pc = 0x118FDCu;
label_118fdc:
    // 0x118fdc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x118FDCu;
    {
        const bool branch_taken_0x118fdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118FDCu;
            // 0x118fe0: 0x2610d680  addiu       $s0, $s0, -0x2980 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294956672));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118fdc) {
            ctx->pc = 0x118FF0u;
            goto label_118ff0;
        }
    }
    ctx->pc = 0x118FE4u;
label_118fe4:
    // 0x118fe4: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x118fe4u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x118fe8: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x118fe8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x118fec: 0x2610d680  addiu       $s0, $s0, -0x2980
    ctx->pc = 0x118fecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294956672));
label_118ff0:
    // 0x118ff0: 0x26c4e140  addiu       $a0, $s6, -0x1EC0
    ctx->pc = 0x118ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294959424));
    // 0x118ff4: 0x26a7ca40  addiu       $a3, $s5, -0x35C0
    ctx->pc = 0x118ff4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), 4294953536));
    // 0x118ff8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x118ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x118ffc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x118ffcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119000: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x119000u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119004: 0x2408001c  addiu       $t0, $zero, 0x1C
    ctx->pc = 0x119004u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x119008: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x119008u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11900c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11900cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119010: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x119010u;
    SET_GPR_U32(ctx, 31, 0x119018u);
    ctx->pc = 0x119014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119010u;
            // 0x119014: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119018u; }
        if (ctx->pc != 0x119018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119018u; }
        if (ctx->pc != 0x119018u) { return; }
    }
    ctx->pc = 0x119018u;
label_119018:
    // 0x119018: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x119018u;
    {
        const bool branch_taken_0x119018 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11901Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119018u;
            // 0x11901c: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119018) {
            ctx->pc = 0x119038u;
            goto label_119038;
        }
    }
    ctx->pc = 0x119020u;
    // 0x119020: 0xc04518c  jal         func_114630
    ctx->pc = 0x119020u;
    SET_GPR_U32(ctx, 31, 0x119028u);
    ctx->pc = 0x119024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119020u;
            // 0x119024: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119028u; }
        if (ctx->pc != 0x119028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119028u; }
        if (ctx->pc != 0x119028u) { return; }
    }
    ctx->pc = 0x119028u;
label_119028:
    // 0x119028: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119028u;
    SET_GPR_U32(ctx, 31, 0x119030u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119030u; }
        if (ctx->pc != 0x119030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119030u; }
        if (ctx->pc != 0x119030u) { return; }
    }
    ctx->pc = 0x119030u;
label_119030:
    // 0x119030: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x119030u;
    {
        const bool branch_taken_0x119030 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119030u;
            // 0x119034: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119030) {
            ctx->pc = 0x119088u;
            goto label_119088;
        }
    }
    ctx->pc = 0x119038u;
label_119038:
    // 0x119038: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x119038u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x11903c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11903Cu;
    SET_GPR_U32(ctx, 31, 0x119044u);
    ctx->pc = 0x119040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11903Cu;
            // 0x119040: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119044u; }
        if (ctx->pc != 0x119044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119044u; }
        if (ctx->pc != 0x119044u) { return; }
    }
    ctx->pc = 0x119044u;
label_119044:
    // 0x119044: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x119044u;
    {
        const bool branch_taken_0x119044 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x119048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119044u;
            // 0x119048: 0x32628000  andi        $v0, $s3, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
        if (branch_taken_0x119044) {
            ctx->pc = 0x11905Cu;
            goto label_11905c;
        }
    }
    ctx->pc = 0x11904Cu;
    // 0x11904c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11904Cu;
    SET_GPR_U32(ctx, 31, 0x119054u);
    ctx->pc = 0x119050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11904Cu;
            // 0x119050: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119054u; }
        if (ctx->pc != 0x119054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119054u; }
        if (ctx->pc != 0x119054u) { return; }
    }
    ctx->pc = 0x119054u;
label_119054:
    // 0x119054: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x119054u;
    {
        const bool branch_taken_0x119054 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119054u;
            // 0x119058: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119054) {
            ctx->pc = 0x119088u;
            goto label_119088;
        }
    }
    ctx->pc = 0x11905Cu;
label_11905c:
    // 0x11905c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11905Cu;
    {
        const bool branch_taken_0x11905c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11905c) {
            ctx->pc = 0x119074u;
            goto label_119074;
        }
    }
    ctx->pc = 0x119064u;
    // 0x119064: 0xc04518c  jal         func_114630
    ctx->pc = 0x119064u;
    SET_GPR_U32(ctx, 31, 0x11906Cu);
    ctx->pc = 0x119068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119064u;
            // 0x119068: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11906Cu; }
        if (ctx->pc != 0x11906Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11906Cu; }
        if (ctx->pc != 0x11906Cu) { return; }
    }
    ctx->pc = 0x11906Cu;
label_11906c:
    // 0x11906c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11906Cu;
    {
        const bool branch_taken_0x11906c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11906Cu;
            // 0x119070: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11906c) {
            ctx->pc = 0x119088u;
            goto label_119088;
        }
    }
    ctx->pc = 0x119074u;
label_119074:
    // 0x119074: 0xc045198  jal         func_114660
    ctx->pc = 0x119074u;
    SET_GPR_U32(ctx, 31, 0x11907Cu);
    ctx->pc = 0x119078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119074u;
            // 0x119078: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11907Cu; }
        if (ctx->pc != 0x11907Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11907Cu; }
        if (ctx->pc != 0x11907Cu) { return; }
    }
    ctx->pc = 0x11907Cu;
label_11907c:
    // 0x11907c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11907Cu;
    SET_GPR_U32(ctx, 31, 0x119084u);
    ctx->pc = 0x119080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11907Cu;
            // 0x119080: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119084u; }
        if (ctx->pc != 0x119084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119084u; }
        if (ctx->pc != 0x119084u) { return; }
    }
    ctx->pc = 0x119084u;
label_119084:
    // 0x119084: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x119084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_119088:
    // 0x119088: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x119088u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11908c: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11908cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x119090: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x119090u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x119094: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x119094u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x119098: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x119098u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11909c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11909cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1190a0: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x1190a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1190a4: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x1190a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1190a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1190A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1190ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1190A8u;
            // 0x1190ac: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118EB0u: goto label_118eb0;
            case 0x118EBCu: goto label_118ebc;
            case 0x118ED4u: goto label_118ed4;
            case 0x118EDCu: goto label_118edc;
            case 0x118EF0u: goto label_118ef0;
            case 0x118EF8u: goto label_118ef8;
            case 0x118F00u: goto label_118f00;
            case 0x118F38u: goto label_118f38;
            case 0x118F64u: goto label_118f64;
            case 0x118F98u: goto label_118f98;
            case 0x118FA0u: goto label_118fa0;
            case 0x118FD4u: goto label_118fd4;
            case 0x118FDCu: goto label_118fdc;
            case 0x118FE4u: goto label_118fe4;
            case 0x118FF0u: goto label_118ff0;
            case 0x119018u: goto label_119018;
            case 0x119028u: goto label_119028;
            case 0x119030u: goto label_119030;
            case 0x119038u: goto label_119038;
            case 0x119044u: goto label_119044;
            case 0x119054u: goto label_119054;
            case 0x11905Cu: goto label_11905c;
            case 0x11906Cu: goto label_11906c;
            case 0x119074u: goto label_119074;
            case 0x11907Cu: goto label_11907c;
            case 0x119084u: goto label_119084;
            case 0x119088u: goto label_119088;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1190B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
