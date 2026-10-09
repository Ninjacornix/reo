#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166FE8
// Address: 0x166fe8 - 0x1670c8
void sub_00166FE8_0x166fe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166FE8_0x166fe8");
#endif

    switch (ctx->pc) {
        case 0x167070u: goto label_167070;
        case 0x167084u: goto label_167084;
        case 0x1670acu: goto label_1670ac;
        default: break;
    }

    ctx->pc = 0x166fe8u;

    // 0x166fe8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166fe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x166fec: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x166fecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x166ff0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166ff0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166ff4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166ff4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166ff8: 0x8059c00  j           func_167000
    ctx->pc = 0x166FF8u;
    ctx->pc = 0x166FFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166FF8u;
            // 0x166ffc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167000u;
    goto label_167000;
    ctx->pc = 0x167000u;
label_167000:
    // 0x167000: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167000u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167004: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x167004u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x167008: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167008u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16700c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16700cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x167010: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167010u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167014: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x167014u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167018: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167018u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16701c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x16701cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x167020: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x167020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x167024: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167024u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167028: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x167028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16702c: 0x24841140  addiu       $a0, $a0, 0x1140
    ctx->pc = 0x16702cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x167030: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x167030u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x167034: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x167034u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167038: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x167038u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x16703c: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x16703cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167040: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x167040u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x167044: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x167044u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x167048: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x167048u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x16704c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x16704cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x167050: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x167050u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x167054: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x167054u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x167058: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x167058u;
    {
        const bool branch_taken_0x167058 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16705Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167058u;
            // 0x16705c: 0x8c910014  lw          $s1, 0x14($a0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167058) {
            ctx->pc = 0x1670ACu;
            goto label_1670ac;
        }
    }
    ctx->pc = 0x167060u;
    // 0x167060: 0x52200013  beql        $s1, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x167060u;
    {
        const bool branch_taken_0x167060 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x167060) {
            ctx->pc = 0x167064u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167060u;
            // 0x167064: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1670B0u;
            goto label_1670b0;
        }
    }
    ctx->pc = 0x167068u;
    // 0x167068: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167068u;
    SET_GPR_U32(ctx, 31, 0x167070u);
    ctx->pc = 0x16706Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167068u;
            // 0x16706c: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167070u; }
        if (ctx->pc != 0x167070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167070u; }
        if (ctx->pc != 0x167070u) { return; }
    }
    ctx->pc = 0x167070u;
label_167070:
    // 0x167070: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x167070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167074: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x167074u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167078: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x167078u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16707c: 0xc059cb8  jal         func_1672E0
    ctx->pc = 0x16707Cu;
    SET_GPR_U32(ctx, 31, 0x167084u);
    ctx->pc = 0x167080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16707Cu;
            // 0x167080: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1672E0u;
    if (runtime->hasFunction(0x1672E0u)) {
        auto targetFn = runtime->lookupFunction(0x1672E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167084u; }
        if (ctx->pc != 0x167084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001672E0_0x1672e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167084u; }
        if (ctx->pc != 0x167084u) { return; }
    }
    ctx->pc = 0x167084u;
label_167084:
    // 0x167084: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x167084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x167088: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x167088u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x16708c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x16708cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167090: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x167090u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x167094: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x167094u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x167098: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x167098u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x16709c: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x16709cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1670a0: 0xae050004  sw          $a1, 0x4($s0)
    ctx->pc = 0x1670a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 5));
    // 0x1670a4: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1670A4u;
    SET_GPR_U32(ctx, 31, 0x1670ACu);
    ctx->pc = 0x1670A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1670A4u;
            // 0x1670a8: 0xae060008  sw          $a2, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1670ACu; }
        if (ctx->pc != 0x1670ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1670ACu; }
        if (ctx->pc != 0x1670ACu) { return; }
    }
    ctx->pc = 0x1670ACu;
label_1670ac:
    // 0x1670ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1670acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1670b0:
    // 0x1670b0: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x1670b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1670b4: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x1670b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1670b8: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1670b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1670bc: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1670bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1670c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1670C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1670C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1670C0u;
            // 0x1670c4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167000u: goto label_167000;
            case 0x167070u: goto label_167070;
            case 0x167084u: goto label_167084;
            case 0x1670ACu: goto label_1670ac;
            case 0x1670B0u: goto label_1670b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1670C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
