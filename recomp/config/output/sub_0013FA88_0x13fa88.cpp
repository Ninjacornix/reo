#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013FA88
// Address: 0x13fa88 - 0x13fbf4
void sub_0013FA88_0x13fa88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013FA88_0x13fa88");
#endif

    switch (ctx->pc) {
        case 0x13fab4u: goto label_13fab4;
        case 0x13fbd8u: goto label_13fbd8;
        default: break;
    }

    ctx->pc = 0x13fa88u;

    // 0x13fa88: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13fa88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13fa8c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13fa8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13fa90: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13fa90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fa94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fa94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fa98: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13fa98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fa9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fa9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13faa0: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x13faa0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13faa4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13faa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13faa8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13faa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13faac: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FAACu;
    SET_GPR_U32(ctx, 31, 0x13FAB4u);
    ctx->pc = 0x13FAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FAACu;
            // 0x13fab0: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FAB4u; }
        if (ctx->pc != 0x13FAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FAB4u; }
        if (ctx->pc != 0x13FAB4u) { return; }
    }
    ctx->pc = 0x13FAB4u;
label_13fab4:
    // 0x13fab4: 0x16400020  bnez        $s2, . + 4 + (0x20 << 2)
    ctx->pc = 0x13FAB4u;
    {
        const bool branch_taken_0x13fab4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13FAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FAB4u;
            // 0x13fab8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fab4) {
            ctx->pc = 0x13FB38u;
            goto label_13fb38;
        }
    }
    ctx->pc = 0x13FABCu;
    // 0x13fabc: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x13fabcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13fac0: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fac0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fac4: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x13fac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13fac8: 0x8e050010  lw          $a1, 0x10($s0)
    ctx->pc = 0x13fac8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13facc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x13faccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fad0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13fad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13fad4: 0x8e06001c  lw          $a2, 0x1C($s0)
    ctx->pc = 0x13fad4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fad8: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x13fad8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13fadc: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x13fadcu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x13fae0: 0x53202a  slt         $a0, $v0, $s3
    ctx->pc = 0x13fae0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x13fae4: 0x264100a  movz        $v0, $s3, $a0
    ctx->pc = 0x13fae4u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 19));
    // 0x13fae8: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x13fae8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x13faec: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x13faecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13faf0: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x13faf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13faf4: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x13faf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13faf8: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x13faf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x13fafc: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x13fafcu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fb00: 0xae260000  sw          $a2, 0x0($s1)
    ctx->pc = 0x13fb00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 6));
    // 0x13fb04: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FB04u;
    {
        const bool branch_taken_0x13fb04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fb04) {
            ctx->pc = 0x13FB08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB04u;
            // 0x13fb08: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FB0Cu;
            goto label_13fb0c;
        }
    }
    ctx->pc = 0x13FB0Cu;
label_13fb0c:
    // 0x13fb0c: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x13fb0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13fb10: 0x8e030028  lw          $v1, 0x28($s0)
    ctx->pc = 0x13fb10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13fb14: 0x2810  mfhi        $a1
    ctx->pc = 0x13fb14u;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x13fb18: 0xae050014  sw          $a1, 0x14($s0)
    ctx->pc = 0x13fb18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 5));
    // 0x13fb1c: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fb1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fb20: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13fb20u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fb24: 0xae040010  sw          $a0, 0x10($s0)
    ctx->pc = 0x13fb24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 4));
    // 0x13fb28: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fb28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fb2c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13fb2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13fb30: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x13FB30u;
    {
        const bool branch_taken_0x13fb30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB30u;
            // 0x13fb34: 0xae030028  sw          $v1, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fb30) {
            ctx->pc = 0x13FBD8u;
            goto label_13fbd8;
        }
    }
    ctx->pc = 0x13FB38u;
label_13fb38:
    // 0x13fb38: 0x56420021  bnel        $s2, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x13FB38u;
    {
        const bool branch_taken_0x13fb38 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13fb38) {
            ctx->pc = 0x13FB3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB38u;
            // 0x13fb3c: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FBC0u;
            goto label_13fbc0;
        }
    }
    ctx->pc = 0x13FB40u;
    // 0x13fb40: 0x8e030018  lw          $v1, 0x18($s0)
    ctx->pc = 0x13fb40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13fb44: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fb44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fb48: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x13fb48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13fb4c: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x13fb4cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fb50: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x13fb50u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fb54: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13fb54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13fb58: 0x8e06001c  lw          $a2, 0x1C($s0)
    ctx->pc = 0x13fb58u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fb5c: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x13fb5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13fb60: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x13fb60u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x13fb64: 0x53202a  slt         $a0, $v0, $s3
    ctx->pc = 0x13fb64u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x13fb68: 0x264100a  movz        $v0, $s3, $a0
    ctx->pc = 0x13fb68u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 19));
    // 0x13fb6c: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x13fb6cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x13fb70: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x13fb70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13fb74: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x13fb74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fb78: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x13fb78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fb7c: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x13fb7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x13fb80: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x13fb80u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fb84: 0xae260000  sw          $a2, 0x0($s1)
    ctx->pc = 0x13fb84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 6));
    // 0x13fb88: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FB88u;
    {
        const bool branch_taken_0x13fb88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fb88) {
            ctx->pc = 0x13FB8Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB88u;
            // 0x13fb8c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FB90u;
            goto label_13fb90;
        }
    }
    ctx->pc = 0x13FB90u;
label_13fb90:
    // 0x13fb90: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x13fb90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fb94: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x13fb94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x13fb98: 0x2810  mfhi        $a1
    ctx->pc = 0x13fb98u;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x13fb9c: 0xae050018  sw          $a1, 0x18($s0)
    ctx->pc = 0x13fb9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 5));
    // 0x13fba0: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fba4: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13fba4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fba8: 0xae04000c  sw          $a0, 0xC($s0)
    ctx->pc = 0x13fba8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 4));
    // 0x13fbac: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fbacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fbb0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13fbb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13fbb4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13FBB4u;
    {
        const bool branch_taken_0x13fbb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FBB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBB4u;
            // 0x13fbb8: 0xae030030  sw          $v1, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fbb4) {
            ctx->pc = 0x13FBD8u;
            goto label_13fbd8;
        }
    }
    ctx->pc = 0x13FBBCu;
    // 0x13fbbc: 0x0  nop
    ctx->pc = 0x13fbbcu;
    // NOP
label_13fbc0:
    // 0x13fbc0: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13fbc0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13fbc4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FBC4u;
    {
        const bool branch_taken_0x13fbc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FBC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBC4u;
            // 0x13fbc8: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fbc4) {
            ctx->pc = 0x13FBD8u;
            goto label_13fbd8;
        }
    }
    ctx->pc = 0x13FBCCu;
    // 0x13fbcc: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fbccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fbd0: 0x40f809  jalr        $v0
    ctx->pc = 0x13FBD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FBD8u);
        ctx->pc = 0x13FBD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBD0u;
            // 0x13fbd4: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FBD8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FBD8u; }
            if (ctx->pc != 0x13FBD8u) { return; }
        }
        }
    }
    ctx->pc = 0x13FBD8u;
label_13fbd8:
    // 0x13fbd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fbd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fbdc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fbdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fbe0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fbe0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fbe4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13fbe4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fbe8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13fbe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13fbec: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13FBECu;
    ctx->pc = 0x13FBF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBECu;
            // 0x13fbf0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13FBF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
