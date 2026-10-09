#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BA48
// Address: 0x16ba48 - 0x16baec
void sub_0016BA48_0x16ba48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BA48_0x16ba48");
#endif

    switch (ctx->pc) {
        case 0x16ba68u: goto label_16ba68;
        case 0x16ba8cu: goto label_16ba8c;
        case 0x16ba94u: goto label_16ba94;
        case 0x16baa8u: goto label_16baa8;
        default: break;
    }

    ctx->pc = 0x16ba48u;

    // 0x16ba48: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16ba48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16ba4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16ba4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16ba50: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16ba50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16ba54: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16ba54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16ba58: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16ba58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16ba5c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16ba5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16ba60: 0xc05aee6  jal         func_16BB98
    ctx->pc = 0x16BA60u;
    SET_GPR_U32(ctx, 31, 0x16BA68u);
    ctx->pc = 0x16BA64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BA60u;
            // 0x16ba64: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BB98u;
    if (runtime->hasFunction(0x16BB98u)) {
        auto targetFn = runtime->lookupFunction(0x16BB98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BA68u; }
        if (ctx->pc != 0x16BA68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BB98_0x16bb98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BA68u; }
        if (ctx->pc != 0x16BA68u) { return; }
    }
    ctx->pc = 0x16BA68u;
label_16ba68:
    // 0x16ba68: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16ba68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ba6c: 0x52000019  beql        $s0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x16BA6Cu;
    {
        const bool branch_taken_0x16ba6c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x16ba6c) {
            ctx->pc = 0x16BA70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16BA6Cu;
            // 0x16ba70: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16BAD4u;
            goto label_16bad4;
        }
    }
    ctx->pc = 0x16BA74u;
    // 0x16ba74: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x16ba74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16ba78: 0x10600015  beqz        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x16BA78u;
    {
        const bool branch_taken_0x16ba78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BA78u;
            // 0x16ba7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ba78) {
            ctx->pc = 0x16BAD0u;
            goto label_16bad0;
        }
    }
    ctx->pc = 0x16BA80u;
    // 0x16ba80: 0x8e321aec  lw          $s2, 0x1AEC($s1)
    ctx->pc = 0x16ba80u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 6892)));
    // 0x16ba84: 0xc05a49e  jal         func_169278
    ctx->pc = 0x16BA84u;
    SET_GPR_U32(ctx, 31, 0x16BA8Cu);
    ctx->pc = 0x16BA88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BA84u;
            // 0x16ba88: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169278u;
    if (runtime->hasFunction(0x169278u)) {
        auto targetFn = runtime->lookupFunction(0x169278u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BA8Cu; }
        if (ctx->pc != 0x16BA8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169278_0x169278(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BA8Cu; }
        if (ctx->pc != 0x16BA8Cu) { return; }
    }
    ctx->pc = 0x16BA8Cu;
label_16ba8c:
    // 0x16ba8c: 0xc05aebc  jal         func_16BAF0
    ctx->pc = 0x16BA8Cu;
    SET_GPR_U32(ctx, 31, 0x16BA94u);
    ctx->pc = 0x16BA90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BA8Cu;
            // 0x16ba90: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BAF0u;
    if (runtime->hasFunction(0x16BAF0u)) {
        auto targetFn = runtime->lookupFunction(0x16BAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BA94u; }
        if (ctx->pc != 0x16BA94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BAF0_0x16baf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BA94u; }
        if (ctx->pc != 0x16BA94u) { return; }
    }
    ctx->pc = 0x16BA94u;
label_16ba94:
    // 0x16ba94: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16ba94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ba98: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16ba98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ba9c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16ba9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16baa0: 0xc05aebe  jal         func_16BAF8
    ctx->pc = 0x16BAA0u;
    SET_GPR_U32(ctx, 31, 0x16BAA8u);
    ctx->pc = 0x16BAA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BAA0u;
            // 0x16baa4: 0x26330cc0  addiu       $s3, $s1, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 3264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BAF8u;
    if (runtime->hasFunction(0x16BAF8u)) {
        auto targetFn = runtime->lookupFunction(0x16BAF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BAA8u; }
        if (ctx->pc != 0x16BAA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BAF8_0x16baf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BAA8u; }
        if (ctx->pc != 0x16BAA8u) { return; }
    }
    ctx->pc = 0x16BAA8u;
label_16baa8:
    // 0x16baa8: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x16BAA8u;
    {
        const bool branch_taken_0x16baa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16baa8) {
            ctx->pc = 0x16BAACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16BAA8u;
            // 0x16baac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16BAD4u;
            goto label_16bad4;
        }
    }
    ctx->pc = 0x16BAB0u;
    // 0x16bab0: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x16bab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16bab4: 0xae430020  sw          $v1, 0x20($s2)
    ctx->pc = 0x16bab4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 3));
    // 0x16bab8: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x16bab8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x16babc: 0xae440024  sw          $a0, 0x24($s2)
    ctx->pc = 0x16babcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 4));
    // 0x16bac0: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x16bac0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x16bac4: 0xae630114  sw          $v1, 0x114($s3)
    ctx->pc = 0x16bac4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 276), GPR_U32(ctx, 3));
    // 0x16bac8: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x16bac8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x16bacc: 0xae44000c  sw          $a0, 0xC($s2)
    ctx->pc = 0x16baccu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 4));
label_16bad0:
    // 0x16bad0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bad0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16bad4:
    // 0x16bad4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16bad4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bad8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16bad8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16badc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16badcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bae0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16bae0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16bae4: 0x3e00008  jr          $ra
    ctx->pc = 0x16BAE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BAE4u;
            // 0x16bae8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BA68u: goto label_16ba68;
            case 0x16BA8Cu: goto label_16ba8c;
            case 0x16BA94u: goto label_16ba94;
            case 0x16BAA8u: goto label_16baa8;
            case 0x16BAD0u: goto label_16bad0;
            case 0x16BAD4u: goto label_16bad4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BAECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
