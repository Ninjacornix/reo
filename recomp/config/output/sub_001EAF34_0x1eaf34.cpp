#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EAF34
// Address: 0x1eaf34 - 0x1eb064
void sub_001EAF34_0x1eaf34(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EAF34_0x1eaf34");
#endif

    switch (ctx->pc) {
        case 0x1eaf70u: goto label_1eaf70;
        case 0x1eafb8u: goto label_1eafb8;
        default: break;
    }

    ctx->pc = 0x1eaf34u;

    // 0x1eaf34: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1eaf34u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1eaf38: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1eaf38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1eaf3c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1eaf3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1eaf40: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1eaf40u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eaf44: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1eaf44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1eaf48: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1eaf48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1eaf4c: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1eaf4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1eaf50: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eaf50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eaf54: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eaf54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eaf58: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1eaf58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1eaf5c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1eaf5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eaf60: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eaf60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eaf64: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eaf64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eaf68: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x1eaf68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1eaf6c: 0xa7c20018  sh          $v0, 0x18($fp)
    ctx->pc = 0x1eaf6cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 24), (uint16_t)GPR_U32(ctx, 2));
label_1eaf70:
    // 0x1eaf70: 0x87c20018  lh          $v0, 0x18($fp)
    ctx->pc = 0x1eaf70u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eaf74: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1eaf74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1eaf78: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EAF78u;
    {
        const bool branch_taken_0x1eaf78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eaf78) {
            ctx->pc = 0x1EAF88u;
            goto label_1eaf88;
        }
    }
    ctx->pc = 0x1EAF80u;
    // 0x1eaf80: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1EAF80u;
    {
        const bool branch_taken_0x1eaf80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eaf80) {
            ctx->pc = 0x1EAFF4u;
            goto label_1eaff4;
        }
    }
    ctx->pc = 0x1EAF88u;
label_1eaf88:
    // 0x1eaf88: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eaf88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eaf8c: 0x87c20018  lh          $v0, 0x18($fp)
    ctx->pc = 0x1eaf8cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eaf90: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1eaf90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eaf94: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eaf94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eaf98: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eaf98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaf9c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eaf9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eafa0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eafa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eafa4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1eafa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1eafa8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1eafa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eafac: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1eafacu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eafb0: 0xc07ab3e  jal         func_1EACF8
    ctx->pc = 0x1EAFB0u;
    SET_GPR_U32(ctx, 31, 0x1EAFB8u);
    ctx->pc = 0x1EACF8u;
    if (runtime->hasFunction(0x1EACF8u)) {
        auto targetFn = runtime->lookupFunction(0x1EACF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAFB8u; }
        if (ctx->pc != 0x1EAFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EACF8_0x1eacf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAFB8u; }
        if (ctx->pc != 0x1EAFB8u) { return; }
    }
    ctx->pc = 0x1EAFB8u;
label_1eafb8:
    // 0x1eafb8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1eafb8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eafbc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eafbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eafc0: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x1eafc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x1eafc4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eafc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eafc8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eafc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eafcc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1eafccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1eafd0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eafd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eafd4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1eafd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1eafd8: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1eafd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eafdc: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eafdcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eafe0: 0x97c20018  lhu         $v0, 0x18($fp)
    ctx->pc = 0x1eafe0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eafe4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1eafe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1eafe8: 0xa7c20018  sh          $v0, 0x18($fp)
    ctx->pc = 0x1eafe8u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 24), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eafec: 0x1000ffe0  b           . + 4 + (-0x20 << 2)
    ctx->pc = 0x1EAFECu;
    {
        const bool branch_taken_0x1eafec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eafec) {
            ctx->pc = 0x1EAF70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaf70;
        }
    }
    ctx->pc = 0x1EAFF4u;
label_1eaff4:
    // 0x1eaff4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eaff4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaff8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1eaff8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1eaffc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eaffcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eb000: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1eb000u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1eb004: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1eb004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb008: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eb008u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eb00c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb00cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb010: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eb010u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eb014: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1eb014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1eb018: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eb018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eb01c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eb01cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eb020: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb024: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eb024u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb028: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eb028u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb02c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eb02cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eb030: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1eb030u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1eb034: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1eb034u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb038: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eb038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb03c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eb03cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb040: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1eb040u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb044: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eb044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eb048: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eb048u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb04c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eb04cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb050: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1eb050u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1eb054: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1eb054u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1eb058: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1eb058u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1eb05c: 0x3e00008  jr          $ra
    ctx->pc = 0x1EB05Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EAF70u: goto label_1eaf70;
            case 0x1EAF88u: goto label_1eaf88;
            case 0x1EAFB8u: goto label_1eafb8;
            case 0x1EAFF4u: goto label_1eaff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EB064u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
