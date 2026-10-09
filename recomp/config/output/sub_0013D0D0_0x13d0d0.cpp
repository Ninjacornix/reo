#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D0D0
// Address: 0x13d0d0 - 0x13d358
void sub_0013D0D0_0x13d0d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D0D0_0x13d0d0");
#endif

    switch (ctx->pc) {
        case 0x13d0e8u: goto label_13d0e8;
        case 0x13d120u: goto label_13d120;
        case 0x13d14cu: goto label_13d14c;
        case 0x13d1a8u: goto label_13d1a8;
        case 0x13d1c8u: goto label_13d1c8;
        case 0x13d204u: goto label_13d204;
        case 0x13d240u: goto label_13d240;
        case 0x13d260u: goto label_13d260;
        case 0x13d29cu: goto label_13d29c;
        case 0x13d2d8u: goto label_13d2d8;
        case 0x13d2f8u: goto label_13d2f8;
        case 0x13d334u: goto label_13d334;
        default: break;
    }

    ctx->pc = 0x13d0d0u;

    // 0x13d0d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d0d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d0d4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D0D4u;
    {
        const bool branch_taken_0x13d0d4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0D4u;
            // 0x13d0d8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d0d4) {
            ctx->pc = 0x13D0F0u;
            goto label_13d0f0;
        }
    }
    ctx->pc = 0x13D0DCu;
    // 0x13d0dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d0dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d0e0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D0E0u;
    SET_GPR_U32(ctx, 31, 0x13D0E8u);
    ctx->pc = 0x13D0E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0E0u;
            // 0x13d0e4: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D0E8u; }
        if (ctx->pc != 0x13D0E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D0E8u; }
        if (ctx->pc != 0x13D0E8u) { return; }
    }
    ctx->pc = 0x13D0E8u;
label_13d0e8:
    // 0x13d0e8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13D0E8u;
    {
        const bool branch_taken_0x13d0e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0E8u;
            // 0x13d0ec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d0e8) {
            ctx->pc = 0x13D0F4u;
            goto label_13d0f4;
        }
    }
    ctx->pc = 0x13D0F0u;
label_13d0f0:
    // 0x13d0f0: 0x8c820024  lw          $v0, 0x24($a0)
    ctx->pc = 0x13d0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
label_13d0f4:
    // 0x13d0f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d0f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d0f8: 0x3e00008  jr          $ra
    ctx->pc = 0x13D0F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0F8u;
            // 0x13d0fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D0E8u: goto label_13d0e8;
            case 0x13D0F0u: goto label_13d0f0;
            case 0x13D0F4u: goto label_13d0f4;
            case 0x13D120u: goto label_13d120;
            case 0x13D128u: goto label_13d128;
            case 0x13D144u: goto label_13d144;
            case 0x13D14Cu: goto label_13d14c;
            case 0x13D158u: goto label_13d158;
            case 0x13D184u: goto label_13d184;
            case 0x13D1A8u: goto label_13d1a8;
            case 0x13D1B0u: goto label_13d1b0;
            case 0x13D1C8u: goto label_13d1c8;
            case 0x13D1ECu: goto label_13d1ec;
            case 0x13D204u: goto label_13d204;
            case 0x13D210u: goto label_13d210;
            case 0x13D218u: goto label_13d218;
            case 0x13D240u: goto label_13d240;
            case 0x13D248u: goto label_13d248;
            case 0x13D260u: goto label_13d260;
            case 0x13D284u: goto label_13d284;
            case 0x13D29Cu: goto label_13d29c;
            case 0x13D2A8u: goto label_13d2a8;
            case 0x13D2B0u: goto label_13d2b0;
            case 0x13D2D8u: goto label_13d2d8;
            case 0x13D2E0u: goto label_13d2e0;
            case 0x13D2F8u: goto label_13d2f8;
            case 0x13D31Cu: goto label_13d31c;
            case 0x13D334u: goto label_13d334;
            case 0x13D340u: goto label_13d340;
            case 0x13D348u: goto label_13d348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D100u;
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
            case 0x13D0E8u: goto label_13d0e8;
            case 0x13D0F0u: goto label_13d0f0;
            case 0x13D0F4u: goto label_13d0f4;
            case 0x13D120u: goto label_13d120;
            case 0x13D128u: goto label_13d128;
            case 0x13D144u: goto label_13d144;
            case 0x13D14Cu: goto label_13d14c;
            case 0x13D158u: goto label_13d158;
            case 0x13D184u: goto label_13d184;
            case 0x13D1A8u: goto label_13d1a8;
            case 0x13D1B0u: goto label_13d1b0;
            case 0x13D1C8u: goto label_13d1c8;
            case 0x13D1ECu: goto label_13d1ec;
            case 0x13D204u: goto label_13d204;
            case 0x13D210u: goto label_13d210;
            case 0x13D218u: goto label_13d218;
            case 0x13D240u: goto label_13d240;
            case 0x13D248u: goto label_13d248;
            case 0x13D260u: goto label_13d260;
            case 0x13D284u: goto label_13d284;
            case 0x13D29Cu: goto label_13d29c;
            case 0x13D2A8u: goto label_13d2a8;
            case 0x13D2B0u: goto label_13d2b0;
            case 0x13D2D8u: goto label_13d2d8;
            case 0x13D2E0u: goto label_13d2e0;
            case 0x13D2F8u: goto label_13d2f8;
            case 0x13D31Cu: goto label_13d31c;
            case 0x13D334u: goto label_13d334;
            case 0x13D340u: goto label_13d340;
            case 0x13D348u: goto label_13d348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D190u;
    // 0x13d190: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d190u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d194: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D194u;
    {
        const bool branch_taken_0x13d194 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D194u;
            // 0x13d198: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d194) {
            ctx->pc = 0x13D1B0u;
            goto label_13d1b0;
        }
    }
    ctx->pc = 0x13D19Cu;
    // 0x13d19c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d19cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d1a0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D1A0u;
    SET_GPR_U32(ctx, 31, 0x13D1A8u);
    ctx->pc = 0x13D1A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1A0u;
            // 0x13d1a4: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D1A8u; }
        if (ctx->pc != 0x13D1A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D1A8u; }
        if (ctx->pc != 0x13D1A8u) { return; }
    }
    ctx->pc = 0x13D1A8u;
label_13d1a8:
    // 0x13d1a8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x13D1A8u;
    {
        const bool branch_taken_0x13d1a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D1ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1A8u;
            // 0x13d1ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d1a8) {
            ctx->pc = 0x13D218u;
            goto label_13d218;
        }
    }
    ctx->pc = 0x13D1B0u;
label_13d1b0:
    // 0x13d1b0: 0x24860038  addiu       $a2, $a0, 0x38
    ctx->pc = 0x13d1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x13d1b4: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d1b8: 0x1045000c  beq         $v0, $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x13D1B8u;
    {
        const bool branch_taken_0x13d1b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13D1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1B8u;
            // 0x13d1bc: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d1b8) {
            ctx->pc = 0x13D1ECu;
            goto label_13d1ec;
        }
    }
    ctx->pc = 0x13D1C0u;
    // 0x13d1c0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13d1c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13d1c4: 0x0  nop
    ctx->pc = 0x13d1c4u;
    // NOP
label_13d1c8:
    // 0x13d1c8: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x13d1c8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13d1cc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D1CCu;
    {
        const bool branch_taken_0x13d1cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1CCu;
            // 0x13d1d0: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d1cc) {
            ctx->pc = 0x13D1ECu;
            goto label_13d1ec;
        }
    }
    ctx->pc = 0x13D1D4u;
    // 0x13d1d4: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d1d8: 0x0  nop
    ctx->pc = 0x13d1d8u;
    // NOP
    // 0x13d1dc: 0x0  nop
    ctx->pc = 0x13d1dcu;
    // NOP
    // 0x13d1e0: 0x0  nop
    ctx->pc = 0x13d1e0u;
    // NOP
    // 0x13d1e4: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13D1E4u;
    {
        const bool branch_taken_0x13d1e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x13d1e4) {
            ctx->pc = 0x13D1E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1E4u;
            // 0x13d1e8: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D1C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d1c8;
        }
    }
    ctx->pc = 0x13D1ECu;
label_13d1ec:
    // 0x13d1ec: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13d1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13d1f0: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D1F0u;
    {
        const bool branch_taken_0x13d1f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d1f0) {
            ctx->pc = 0x13D1F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1F0u;
            // 0x13d1f4: 0x31940  sll         $v1, $v1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D210u;
            goto label_13d210;
        }
    }
    ctx->pc = 0x13D1F8u;
    // 0x13d1f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d1fc: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D1FCu;
    SET_GPR_U32(ctx, 31, 0x13D204u);
    ctx->pc = 0x13D200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1FCu;
            // 0x13d200: 0x2484d3d8  addiu       $a0, $a0, -0x2C28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D204u; }
        if (ctx->pc != 0x13D204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D204u; }
        if (ctx->pc != 0x13D204u) { return; }
    }
    ctx->pc = 0x13D204u;
label_13d204:
    // 0x13d204: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13D204u;
    {
        const bool branch_taken_0x13d204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D204u;
            // 0x13d208: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d204) {
            ctx->pc = 0x13D218u;
            goto label_13d218;
        }
    }
    ctx->pc = 0x13D20Cu;
    // 0x13d20c: 0x0  nop
    ctx->pc = 0x13d20cu;
    // NOP
label_13d210:
    // 0x13d210: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x13d210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x13d214: 0x8c62003c  lw          $v0, 0x3C($v1)
    ctx->pc = 0x13d214u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 60)));
label_13d218:
    // 0x13d218: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d218u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d21c: 0x3e00008  jr          $ra
    ctx->pc = 0x13D21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D21Cu;
            // 0x13d220: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D0E8u: goto label_13d0e8;
            case 0x13D0F0u: goto label_13d0f0;
            case 0x13D0F4u: goto label_13d0f4;
            case 0x13D120u: goto label_13d120;
            case 0x13D128u: goto label_13d128;
            case 0x13D144u: goto label_13d144;
            case 0x13D14Cu: goto label_13d14c;
            case 0x13D158u: goto label_13d158;
            case 0x13D184u: goto label_13d184;
            case 0x13D1A8u: goto label_13d1a8;
            case 0x13D1B0u: goto label_13d1b0;
            case 0x13D1C8u: goto label_13d1c8;
            case 0x13D1ECu: goto label_13d1ec;
            case 0x13D204u: goto label_13d204;
            case 0x13D210u: goto label_13d210;
            case 0x13D218u: goto label_13d218;
            case 0x13D240u: goto label_13d240;
            case 0x13D248u: goto label_13d248;
            case 0x13D260u: goto label_13d260;
            case 0x13D284u: goto label_13d284;
            case 0x13D29Cu: goto label_13d29c;
            case 0x13D2A8u: goto label_13d2a8;
            case 0x13D2B0u: goto label_13d2b0;
            case 0x13D2D8u: goto label_13d2d8;
            case 0x13D2E0u: goto label_13d2e0;
            case 0x13D2F8u: goto label_13d2f8;
            case 0x13D31Cu: goto label_13d31c;
            case 0x13D334u: goto label_13d334;
            case 0x13D340u: goto label_13d340;
            case 0x13D348u: goto label_13d348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D224u;
    // 0x13d224: 0x0  nop
    ctx->pc = 0x13d224u;
    // NOP
    // 0x13d228: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d22c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D22Cu;
    {
        const bool branch_taken_0x13d22c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D22Cu;
            // 0x13d230: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d22c) {
            ctx->pc = 0x13D248u;
            goto label_13d248;
        }
    }
    ctx->pc = 0x13D234u;
    // 0x13d234: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d234u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d238: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D238u;
    SET_GPR_U32(ctx, 31, 0x13D240u);
    ctx->pc = 0x13D23Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D238u;
            // 0x13d23c: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D240u; }
        if (ctx->pc != 0x13D240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D240u; }
        if (ctx->pc != 0x13D240u) { return; }
    }
    ctx->pc = 0x13D240u;
label_13d240:
    // 0x13d240: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x13D240u;
    {
        const bool branch_taken_0x13d240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D240u;
            // 0x13d244: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d240) {
            ctx->pc = 0x13D2B0u;
            goto label_13d2b0;
        }
    }
    ctx->pc = 0x13D248u;
label_13d248:
    // 0x13d248: 0x24860038  addiu       $a2, $a0, 0x38
    ctx->pc = 0x13d248u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x13d24c: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d24cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d250: 0x1045000c  beq         $v0, $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x13D250u;
    {
        const bool branch_taken_0x13d250 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13D254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D250u;
            // 0x13d254: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d250) {
            ctx->pc = 0x13D284u;
            goto label_13d284;
        }
    }
    ctx->pc = 0x13D258u;
    // 0x13d258: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13d258u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13d25c: 0x0  nop
    ctx->pc = 0x13d25cu;
    // NOP
label_13d260:
    // 0x13d260: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x13d260u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13d264: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D264u;
    {
        const bool branch_taken_0x13d264 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D264u;
            // 0x13d268: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d264) {
            ctx->pc = 0x13D284u;
            goto label_13d284;
        }
    }
    ctx->pc = 0x13D26Cu;
    // 0x13d26c: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d26cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d270: 0x0  nop
    ctx->pc = 0x13d270u;
    // NOP
    // 0x13d274: 0x0  nop
    ctx->pc = 0x13d274u;
    // NOP
    // 0x13d278: 0x0  nop
    ctx->pc = 0x13d278u;
    // NOP
    // 0x13d27c: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13D27Cu;
    {
        const bool branch_taken_0x13d27c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x13d27c) {
            ctx->pc = 0x13D280u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D27Cu;
            // 0x13d280: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d260;
        }
    }
    ctx->pc = 0x13D284u;
label_13d284:
    // 0x13d284: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13d284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13d288: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D288u;
    {
        const bool branch_taken_0x13d288 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d288) {
            ctx->pc = 0x13D28Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D288u;
            // 0x13d28c: 0x31940  sll         $v1, $v1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D2A8u;
            goto label_13d2a8;
        }
    }
    ctx->pc = 0x13D290u;
    // 0x13d290: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d290u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d294: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D294u;
    SET_GPR_U32(ctx, 31, 0x13D29Cu);
    ctx->pc = 0x13D298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D294u;
            // 0x13d298: 0x2484d3d8  addiu       $a0, $a0, -0x2C28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D29Cu; }
        if (ctx->pc != 0x13D29Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D29Cu; }
        if (ctx->pc != 0x13D29Cu) { return; }
    }
    ctx->pc = 0x13D29Cu;
label_13d29c:
    // 0x13d29c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13D29Cu;
    {
        const bool branch_taken_0x13d29c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D29Cu;
            // 0x13d2a0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d29c) {
            ctx->pc = 0x13D2B0u;
            goto label_13d2b0;
        }
    }
    ctx->pc = 0x13D2A4u;
    // 0x13d2a4: 0x0  nop
    ctx->pc = 0x13d2a4u;
    // NOP
label_13d2a8:
    // 0x13d2a8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x13d2a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x13d2ac: 0x8c620050  lw          $v0, 0x50($v1)
    ctx->pc = 0x13d2acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 80)));
label_13d2b0:
    // 0x13d2b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d2b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d2b4: 0x3e00008  jr          $ra
    ctx->pc = 0x13D2B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2B4u;
            // 0x13d2b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D0E8u: goto label_13d0e8;
            case 0x13D0F0u: goto label_13d0f0;
            case 0x13D0F4u: goto label_13d0f4;
            case 0x13D120u: goto label_13d120;
            case 0x13D128u: goto label_13d128;
            case 0x13D144u: goto label_13d144;
            case 0x13D14Cu: goto label_13d14c;
            case 0x13D158u: goto label_13d158;
            case 0x13D184u: goto label_13d184;
            case 0x13D1A8u: goto label_13d1a8;
            case 0x13D1B0u: goto label_13d1b0;
            case 0x13D1C8u: goto label_13d1c8;
            case 0x13D1ECu: goto label_13d1ec;
            case 0x13D204u: goto label_13d204;
            case 0x13D210u: goto label_13d210;
            case 0x13D218u: goto label_13d218;
            case 0x13D240u: goto label_13d240;
            case 0x13D248u: goto label_13d248;
            case 0x13D260u: goto label_13d260;
            case 0x13D284u: goto label_13d284;
            case 0x13D29Cu: goto label_13d29c;
            case 0x13D2A8u: goto label_13d2a8;
            case 0x13D2B0u: goto label_13d2b0;
            case 0x13D2D8u: goto label_13d2d8;
            case 0x13D2E0u: goto label_13d2e0;
            case 0x13D2F8u: goto label_13d2f8;
            case 0x13D31Cu: goto label_13d31c;
            case 0x13D334u: goto label_13d334;
            case 0x13D340u: goto label_13d340;
            case 0x13D348u: goto label_13d348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D2BCu;
    // 0x13d2bc: 0x0  nop
    ctx->pc = 0x13d2bcu;
    // NOP
    // 0x13d2c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d2c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d2c4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D2C4u;
    {
        const bool branch_taken_0x13d2c4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2C4u;
            // 0x13d2c8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2c4) {
            ctx->pc = 0x13D2E0u;
            goto label_13d2e0;
        }
    }
    ctx->pc = 0x13D2CCu;
    // 0x13d2cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d2d0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D2D0u;
    SET_GPR_U32(ctx, 31, 0x13D2D8u);
    ctx->pc = 0x13D2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2D0u;
            // 0x13d2d4: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D2D8u; }
        if (ctx->pc != 0x13D2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D2D8u; }
        if (ctx->pc != 0x13D2D8u) { return; }
    }
    ctx->pc = 0x13D2D8u;
label_13d2d8:
    // 0x13d2d8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x13D2D8u;
    {
        const bool branch_taken_0x13d2d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2D8u;
            // 0x13d2dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2d8) {
            ctx->pc = 0x13D348u;
            goto label_13d348;
        }
    }
    ctx->pc = 0x13D2E0u;
label_13d2e0:
    // 0x13d2e0: 0x24860038  addiu       $a2, $a0, 0x38
    ctx->pc = 0x13d2e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x13d2e4: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d2e8: 0x1045000c  beq         $v0, $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x13D2E8u;
    {
        const bool branch_taken_0x13d2e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13D2ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2E8u;
            // 0x13d2ec: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2e8) {
            ctx->pc = 0x13D31Cu;
            goto label_13d31c;
        }
    }
    ctx->pc = 0x13D2F0u;
    // 0x13d2f0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13d2f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13d2f4: 0x0  nop
    ctx->pc = 0x13d2f4u;
    // NOP
label_13d2f8:
    // 0x13d2f8: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x13d2f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13d2fc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D2FCu;
    {
        const bool branch_taken_0x13d2fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2FCu;
            // 0x13d300: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2fc) {
            ctx->pc = 0x13D31Cu;
            goto label_13d31c;
        }
    }
    ctx->pc = 0x13D304u;
    // 0x13d304: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d308: 0x0  nop
    ctx->pc = 0x13d308u;
    // NOP
    // 0x13d30c: 0x0  nop
    ctx->pc = 0x13d30cu;
    // NOP
    // 0x13d310: 0x0  nop
    ctx->pc = 0x13d310u;
    // NOP
    // 0x13d314: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13D314u;
    {
        const bool branch_taken_0x13d314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x13d314) {
            ctx->pc = 0x13D318u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D314u;
            // 0x13d318: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D2F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d2f8;
        }
    }
    ctx->pc = 0x13D31Cu;
label_13d31c:
    // 0x13d31c: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13d31cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13d320: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D320u;
    {
        const bool branch_taken_0x13d320 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d320) {
            ctx->pc = 0x13D324u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D320u;
            // 0x13d324: 0x31940  sll         $v1, $v1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D340u;
            goto label_13d340;
        }
    }
    ctx->pc = 0x13D328u;
    // 0x13d328: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d328u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d32c: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D32Cu;
    SET_GPR_U32(ctx, 31, 0x13D334u);
    ctx->pc = 0x13D330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D32Cu;
            // 0x13d330: 0x2484d3d8  addiu       $a0, $a0, -0x2C28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D334u; }
        if (ctx->pc != 0x13D334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D334u; }
        if (ctx->pc != 0x13D334u) { return; }
    }
    ctx->pc = 0x13D334u;
label_13d334:
    // 0x13d334: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13D334u;
    {
        const bool branch_taken_0x13d334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D334u;
            // 0x13d338: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d334) {
            ctx->pc = 0x13D348u;
            goto label_13d348;
        }
    }
    ctx->pc = 0x13D33Cu;
    // 0x13d33c: 0x0  nop
    ctx->pc = 0x13d33cu;
    // NOP
label_13d340:
    // 0x13d340: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x13d340u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x13d344: 0x8c620054  lw          $v0, 0x54($v1)
    ctx->pc = 0x13d344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 84)));
label_13d348:
    // 0x13d348: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d348u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d34c: 0x3e00008  jr          $ra
    ctx->pc = 0x13D34Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D34Cu;
            // 0x13d350: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D0E8u: goto label_13d0e8;
            case 0x13D0F0u: goto label_13d0f0;
            case 0x13D0F4u: goto label_13d0f4;
            case 0x13D120u: goto label_13d120;
            case 0x13D128u: goto label_13d128;
            case 0x13D144u: goto label_13d144;
            case 0x13D14Cu: goto label_13d14c;
            case 0x13D158u: goto label_13d158;
            case 0x13D184u: goto label_13d184;
            case 0x13D1A8u: goto label_13d1a8;
            case 0x13D1B0u: goto label_13d1b0;
            case 0x13D1C8u: goto label_13d1c8;
            case 0x13D1ECu: goto label_13d1ec;
            case 0x13D204u: goto label_13d204;
            case 0x13D210u: goto label_13d210;
            case 0x13D218u: goto label_13d218;
            case 0x13D240u: goto label_13d240;
            case 0x13D248u: goto label_13d248;
            case 0x13D260u: goto label_13d260;
            case 0x13D284u: goto label_13d284;
            case 0x13D29Cu: goto label_13d29c;
            case 0x13D2A8u: goto label_13d2a8;
            case 0x13D2B0u: goto label_13d2b0;
            case 0x13D2D8u: goto label_13d2d8;
            case 0x13D2E0u: goto label_13d2e0;
            case 0x13D2F8u: goto label_13d2f8;
            case 0x13D31Cu: goto label_13d31c;
            case 0x13D334u: goto label_13d334;
            case 0x13D340u: goto label_13d340;
            case 0x13D348u: goto label_13d348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D354u;
    // 0x13d354: 0x0  nop
    ctx->pc = 0x13d354u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
