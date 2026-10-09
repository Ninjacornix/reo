#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E628
// Address: 0x17e628 - 0x17e6a0
void sub_0017E628_0x17e628(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E628_0x17e628");
#endif

    switch (ctx->pc) {
        case 0x17e670u: goto label_17e670;
        case 0x17e68cu: goto label_17e68c;
        default: break;
    }

    ctx->pc = 0x17e628u;

    // 0x17e628: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17e628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17e62c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17e62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17e630: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e630u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e634: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E634u;
    {
        const bool branch_taken_0x17e634 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E634u;
            // 0x17e638: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e634) {
            ctx->pc = 0x17E644u;
            goto label_17e644;
        }
    }
    ctx->pc = 0x17E63Cu;
    // 0x17e63c: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E63Cu;
    {
        const bool branch_taken_0x17e63c = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17E640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E63Cu;
            // 0x17e640: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e63c) {
            ctx->pc = 0x17E650u;
            goto label_17e650;
        }
    }
    ctx->pc = 0x17E644u;
label_17e644:
    // 0x17e644: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x17E644u;
    {
        const bool branch_taken_0x17e644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E644u;
            // 0x17e648: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e644) {
            ctx->pc = 0x17E690u;
            goto label_17e690;
        }
    }
    ctx->pc = 0x17E64Cu;
    // 0x17e64c: 0x0  nop
    ctx->pc = 0x17e64cu;
    // NOP
label_17e650:
    // 0x17e650: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17e650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e654: 0x24a51570  addiu       $a1, $a1, 0x1570
    ctx->pc = 0x17e654u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5488));
    // 0x17e658: 0x82020010  lb          $v0, 0x10($s0)
    ctx->pc = 0x17e658u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17e65c: 0x82030011  lb          $v1, 0x11($s0)
    ctx->pc = 0x17e65cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 17)));
    // 0x17e660: 0xa3a20000  sb          $v0, 0x0($sp)
    ctx->pc = 0x17e660u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x17e664: 0xa3a30001  sb          $v1, 0x1($sp)
    ctx->pc = 0x17e664u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x17e668: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E668u;
    SET_GPR_U32(ctx, 31, 0x17E670u);
    ctx->pc = 0x17E66Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E668u;
            // 0x17e66c: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E670u; }
        if (ctx->pc != 0x17E670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E670u; }
        if (ctx->pc != 0x17E670u) { return; }
    }
    ctx->pc = 0x17E670u;
label_17e670:
    // 0x17e670: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17e670u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17e674: 0x26040014  addiu       $a0, $s0, 0x14
    ctx->pc = 0x17e674u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17e678: 0x24a51560  addiu       $a1, $a1, 0x1560
    ctx->pc = 0x17e678u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5472));
    // 0x17e67c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E67Cu;
    {
        const bool branch_taken_0x17e67c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E67Cu;
            // 0x17e680: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e67c) {
            ctx->pc = 0x17E690u;
            goto label_17e690;
        }
    }
    ctx->pc = 0x17E684u;
    // 0x17e684: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E684u;
    SET_GPR_U32(ctx, 31, 0x17E68Cu);
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E68Cu; }
        if (ctx->pc != 0x17E68Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E68Cu; }
        if (ctx->pc != 0x17E68Cu) { return; }
    }
    ctx->pc = 0x17E68Cu;
label_17e68c:
    // 0x17e68c: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x17e68cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_17e690:
    // 0x17e690: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17e690u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e694: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17e694u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e698: 0x3e00008  jr          $ra
    ctx->pc = 0x17E698u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E698u;
            // 0x17e69c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E644u: goto label_17e644;
            case 0x17E650u: goto label_17e650;
            case 0x17E670u: goto label_17e670;
            case 0x17E68Cu: goto label_17e68c;
            case 0x17E690u: goto label_17e690;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E6A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
