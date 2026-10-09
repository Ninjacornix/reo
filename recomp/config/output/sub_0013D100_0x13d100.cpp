#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D100
// Address: 0x13d100 - 0x13d190
void sub_0013D100_0x13d100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D100_0x13d100");
#endif

    switch (ctx->pc) {
        case 0x13d120u: goto label_13d120;
        case 0x13d14cu: goto label_13d14c;
        default: break;
    }

    ctx->pc = 0x13d100u;

    // 0x13d100: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d100u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d104: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x13d104u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d108: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13d108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13d10c: 0x14c00006  bnez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D10Cu;
    {
        const bool branch_taken_0x13d10c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D10Cu;
            // 0x13d110: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d10c) {
            ctx->pc = 0x13D128u;
            goto label_13d128;
        }
    }
    ctx->pc = 0x13D114u;
    // 0x13d114: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d114u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d118: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D118u;
    SET_GPR_U32(ctx, 31, 0x13D120u);
    ctx->pc = 0x13D11Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D118u;
            // 0x13d11c: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D120u; }
        if (ctx->pc != 0x13D120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D120u; }
        if (ctx->pc != 0x13D120u) { return; }
    }
    ctx->pc = 0x13D120u;
label_13d120:
    // 0x13d120: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x13D120u;
    {
        const bool branch_taken_0x13d120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D120u;
            // 0x13d124: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d120) {
            ctx->pc = 0x13D184u;
            goto label_13d184;
        }
    }
    ctx->pc = 0x13D128u;
label_13d128:
    // 0x13d128: 0x4600006  bltz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D128u;
    {
        const bool branch_taken_0x13d128 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x13D12Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D128u;
            // 0x13d12c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d128) {
            ctx->pc = 0x13D144u;
            goto label_13d144;
        }
    }
    ctx->pc = 0x13D130u;
    // 0x13d130: 0x8cc20024  lw          $v0, 0x24($a2)
    ctx->pc = 0x13d130u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 36)));
    // 0x13d134: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x13d134u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13d138: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D138u;
    {
        const bool branch_taken_0x13d138 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13d138) {
            ctx->pc = 0x13D13Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D138u;
            // 0x13d13c: 0x8cc50020  lw          $a1, 0x20($a2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D158u;
            goto label_13d158;
        }
    }
    ctx->pc = 0x13D140u;
    // 0x13d140: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d140u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_13d144:
    // 0x13d144: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D144u;
    SET_GPR_U32(ctx, 31, 0x13D14Cu);
    ctx->pc = 0x13D148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D144u;
            // 0x13d148: 0x2484d3b8  addiu       $a0, $a0, -0x2C48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D14Cu; }
        if (ctx->pc != 0x13D14Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D14Cu; }
        if (ctx->pc != 0x13D14Cu) { return; }
    }
    ctx->pc = 0x13D14Cu;
label_13d14c:
    // 0x13d14c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x13D14Cu;
    {
        const bool branch_taken_0x13d14c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D14Cu;
            // 0x13d150: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d14c) {
            ctx->pc = 0x13D184u;
            goto label_13d184;
        }
    }
    ctx->pc = 0x13D154u;
    // 0x13d154: 0x0  nop
    ctx->pc = 0x13d154u;
    // NOP
label_13d158:
    // 0x13d158: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x13d158u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x13d15c: 0x24a4000f  addiu       $a0, $a1, 0xF
    ctx->pc = 0x13d15cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x13d160: 0x28a30000  slti        $v1, $a1, 0x0
    ctx->pc = 0x13d160u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13d164: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x13d164u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d168: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x13d168u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x13d16c: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x13d16cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x13d170: 0x22100  sll         $a0, $v0, 4
    ctx->pc = 0x13d170u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x13d174: 0xa41023  subu        $v0, $a1, $a0
    ctx->pc = 0x13d174u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13d178: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x13d178u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x13d17c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x13d17cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x13d180: 0x8c620038  lw          $v0, 0x38($v1)
    ctx->pc = 0x13d180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
label_13d184:
    // 0x13d184: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d184u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d188: 0x3e00008  jr          $ra
    ctx->pc = 0x13D188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D18Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D188u;
            // 0x13d18c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D120u: goto label_13d120;
            case 0x13D128u: goto label_13d128;
            case 0x13D144u: goto label_13d144;
            case 0x13D14Cu: goto label_13d14c;
            case 0x13D158u: goto label_13d158;
            case 0x13D184u: goto label_13d184;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D190u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
