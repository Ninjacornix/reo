#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170CA0
// Address: 0x170ca0 - 0x170d90
void sub_00170CA0_0x170ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170CA0_0x170ca0");
#endif

    switch (ctx->pc) {
        case 0x170cd8u: goto label_170cd8;
        default: break;
    }

    ctx->pc = 0x170ca0u;

    // 0x170ca0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x170ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x170ca4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x170ca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170ca8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170ca8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170cac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x170cacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170cb0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x170cb0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170cb4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x170cb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x170cb8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x170cb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170cbc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x170cbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x170cc0: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x170cc0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170cc4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x170cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x170cc8: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x170cc8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170ccc: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x170cccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x170cd0: 0xc045198  jal         func_114660
    ctx->pc = 0x170CD0u;
    SET_GPR_U32(ctx, 31, 0x170CD8u);
    ctx->pc = 0x170CD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170CD0u;
            // 0x170cd4: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170CD8u; }
        if (ctx->pc != 0x170CD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170CD8u; }
        if (ctx->pc != 0x170CD8u) { return; }
    }
    ctx->pc = 0x170CD8u;
label_170cd8:
    // 0x170cd8: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x170cd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x170cdc: 0x8e050010  lw          $a1, 0x10($s0)
    ctx->pc = 0x170cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x170ce0: 0x8e060014  lw          $a2, 0x14($s0)
    ctx->pc = 0x170ce0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x170ce4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x170ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x170ce8: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x170ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x170cec: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x170cecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x170cf0: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x170cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x170cf4: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x170cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x170cf8: 0x50800001  beql        $a0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x170CF8u;
    {
        const bool branch_taken_0x170cf8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x170cf8) {
            ctx->pc = 0x170CFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170CF8u;
            // 0x170cfc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x170D00u;
            goto label_170d00;
        }
    }
    ctx->pc = 0x170D00u;
label_170d00:
    // 0x170d00: 0x64001a  div         $zero, $v1, $a0
    ctx->pc = 0x170d00u;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x170d04: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x170d04u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x170d08: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x170d08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x170d0c: 0x2442f000  addiu       $v0, $v0, -0x1000
    ctx->pc = 0x170d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963200));
    // 0x170d10: 0x462823  subu        $a1, $v0, $a2
    ctx->pc = 0x170d10u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x170d14: 0x3810  mfhi        $a3
    ctx->pc = 0x170d14u;
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x170d18: 0x872023  subu        $a0, $a0, $a3
    ctx->pc = 0x170d18u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x170d1c: 0x85102a  slt         $v0, $a0, $a1
    ctx->pc = 0x170d1cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x170d20: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x170D20u;
    {
        const bool branch_taken_0x170d20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x170d20) {
            ctx->pc = 0x170D24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170D20u;
            // 0x170d24: 0xae240000  sw          $a0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170D48u;
            goto label_170d48;
        }
    }
    ctx->pc = 0x170D28u;
    // 0x170d28: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x170d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x170d2c: 0xae250000  sw          $a1, 0x0($s1)
    ctx->pc = 0x170d2cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 5));
    // 0x170d30: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x170d30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x170d34: 0xae800000  sw          $zero, 0x0($s4)
    ctx->pc = 0x170d34u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x170d38: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x170d38u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x170d3c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x170D3Cu;
    {
        const bool branch_taken_0x170d3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x170D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170D3Cu;
            // 0x170d40: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170d3c) {
            ctx->pc = 0x170D68u;
            goto label_170d68;
        }
    }
    ctx->pc = 0x170D44u;
    // 0x170d44: 0x0  nop
    ctx->pc = 0x170d44u;
    // NOP
label_170d48:
    // 0x170d48: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x170d48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x170d4c: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x170d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x170d50: 0x871821  addu        $v1, $a0, $a3
    ctx->pc = 0x170d50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x170d54: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x170d54u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x170d58: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x170d58u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x170d5c: 0xa21023  subu        $v0, $a1, $v0
    ctx->pc = 0x170d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x170d60: 0xae640000  sw          $a0, 0x0($s3)
    ctx->pc = 0x170d60u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
    // 0x170d64: 0xae820000  sw          $v0, 0x0($s4)
    ctx->pc = 0x170d64u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
label_170d68:
    // 0x170d68: 0x8e040040  lw          $a0, 0x40($s0)
    ctx->pc = 0x170d68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x170d6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170d6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x170d70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170d70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170d74: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x170d74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170d78: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x170d78u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170d7c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x170d7cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x170d80: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x170d80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x170d84: 0x8045190  j           func_114640
    ctx->pc = 0x170D84u;
    ctx->pc = 0x170D88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170D84u;
            // 0x170d88: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x170D8Cu;
    // 0x170d8c: 0x0  nop
    ctx->pc = 0x170d8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
