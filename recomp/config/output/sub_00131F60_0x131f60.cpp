#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131F60
// Address: 0x131f60 - 0x132028
void sub_00131F60_0x131f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131F60_0x131f60");
#endif

    switch (ctx->pc) {
        case 0x131fa0u: goto label_131fa0;
        case 0x131fbcu: goto label_131fbc;
        case 0x131fc8u: goto label_131fc8;
        case 0x131fd4u: goto label_131fd4;
        default: break;
    }

    ctx->pc = 0x131f60u;

    // 0x131f60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x131f60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x131f64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131f68: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131f68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131f6c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131f6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131f70: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x131f70u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131f74: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x131f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x131f78: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x131f78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131f7c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x131f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x131f80: 0x92020001  lbu         $v0, 0x1($s0)
    ctx->pc = 0x131f80u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x131f84: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x131f84u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x131f88: 0x2442fffd  addiu       $v0, $v0, -0x3
    ctx->pc = 0x131f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967293));
    // 0x131f8c: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x131f8cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x131f90: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x131F90u;
    {
        const bool branch_taken_0x131f90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131F90u;
            // 0x131f94: 0x31e03  sra         $v1, $v1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131f90) {
            ctx->pc = 0x131FA8u;
            goto label_131fa8;
        }
    }
    ctx->pc = 0x131F98u;
    // 0x131f98: 0xc04b1c6  jal         func_12C718
    ctx->pc = 0x131F98u;
    SET_GPR_U32(ctx, 31, 0x131FA0u);
    ctx->pc = 0x131F9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131F98u;
            // 0x131f9c: 0x8e04000c  lw          $a0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C718u;
    if (runtime->hasFunction(0x12C718u)) {
        auto targetFn = runtime->lookupFunction(0x12C718u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FA0u; }
        if (ctx->pc != 0x131FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C718_0x12c718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FA0u; }
        if (ctx->pc != 0x131FA0u) { return; }
    }
    ctx->pc = 0x131FA0u;
label_131fa0:
    // 0x131fa0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x131FA0u;
    {
        const bool branch_taken_0x131fa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x131FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131FA0u;
            // 0x131fa4: 0x8e030088  lw          $v1, 0x88($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 136)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131fa0) {
            ctx->pc = 0x132004u;
            goto label_132004;
        }
    }
    ctx->pc = 0x131FA8u;
label_131fa8:
    // 0x131fa8: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x131fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x131fac: 0x54620012  bnel        $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x131FACu;
    {
        const bool branch_taken_0x131fac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x131fac) {
            ctx->pc = 0x131FB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131FACu;
            // 0x131fb0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131FF8u;
            goto label_131ff8;
        }
    }
    ctx->pc = 0x131FB4u;
    // 0x131fb4: 0xc04b602  jal         func_12D808
    ctx->pc = 0x131FB4u;
    SET_GPR_U32(ctx, 31, 0x131FBCu);
    ctx->pc = 0x131FB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131FB4u;
            // 0x131fb8: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D808u;
    if (runtime->hasFunction(0x12D808u)) {
        auto targetFn = runtime->lookupFunction(0x12D808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FBCu; }
        if (ctx->pc != 0x131FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D808_0x12d808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FBCu; }
        if (ctx->pc != 0x131FBCu) { return; }
    }
    ctx->pc = 0x131FBCu;
label_131fbc:
    // 0x131fbc: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x131fbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x131fc0: 0xc04b5e4  jal         func_12D790
    ctx->pc = 0x131FC0u;
    SET_GPR_U32(ctx, 31, 0x131FC8u);
    ctx->pc = 0x131FC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131FC0u;
            // 0x131fc4: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D790u;
    if (runtime->hasFunction(0x12D790u)) {
        auto targetFn = runtime->lookupFunction(0x12D790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FC8u; }
        if (ctx->pc != 0x131FC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D790_0x12d790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FC8u; }
        if (ctx->pc != 0x131FC8u) { return; }
    }
    ctx->pc = 0x131FC8u;
label_131fc8:
    // 0x131fc8: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x131fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x131fcc: 0xc04b5f0  jal         func_12D7C0
    ctx->pc = 0x131FCCu;
    SET_GPR_U32(ctx, 31, 0x131FD4u);
    ctx->pc = 0x131FD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131FCCu;
            // 0x131fd0: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7C0u;
    if (runtime->hasFunction(0x12D7C0u)) {
        auto targetFn = runtime->lookupFunction(0x12D7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FD4u; }
        if (ctx->pc != 0x131FD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7C0_0x12d7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FD4u; }
        if (ctx->pc != 0x131FD4u) { return; }
    }
    ctx->pc = 0x131FD4u;
label_131fd4:
    // 0x131fd4: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x131fd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x131fd8: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x131fd8u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x131fdc: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x131FDCu;
    {
        const bool branch_taken_0x131fdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x131fdc) {
            ctx->pc = 0x131FE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131FDCu;
            // 0x131fe0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x131FE4u;
            goto label_131fe4;
        }
    }
    ctx->pc = 0x131FE4u;
label_131fe4:
    // 0x131fe4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x131fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x131fe8: 0x1812  mflo        $v1
    ctx->pc = 0x131fe8u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x131fec: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x131fecu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x131ff0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x131FF0u;
    {
        const bool branch_taken_0x131ff0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x131FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131FF0u;
            // 0x131ff4: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131ff0) {
            ctx->pc = 0x132000u;
            goto label_132000;
        }
    }
    ctx->pc = 0x131FF8u;
label_131ff8:
    // 0x131ff8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x131ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x131ffc: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x131ffcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_132000:
    // 0x132000: 0x8e030088  lw          $v1, 0x88($s0)
    ctx->pc = 0x132000u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 136)));
label_132004:
    // 0x132004: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x132004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x132008: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132008u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13200c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13200cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x132010: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x132010u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132014: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x132014u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x132018: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x132018u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13201c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13201cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132020: 0x3e00008  jr          $ra
    ctx->pc = 0x132020u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132020u;
            // 0x132024: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131FA0u: goto label_131fa0;
            case 0x131FA8u: goto label_131fa8;
            case 0x131FBCu: goto label_131fbc;
            case 0x131FC8u: goto label_131fc8;
            case 0x131FD4u: goto label_131fd4;
            case 0x131FE4u: goto label_131fe4;
            case 0x131FF8u: goto label_131ff8;
            case 0x132000u: goto label_132000;
            case 0x132004u: goto label_132004;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132028u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
