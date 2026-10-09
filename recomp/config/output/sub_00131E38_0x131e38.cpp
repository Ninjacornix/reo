#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131E38
// Address: 0x131e38 - 0x131ef8
void sub_00131E38_0x131e38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131E38_0x131e38");
#endif

    switch (ctx->pc) {
        case 0x131e8cu: goto label_131e8c;
        case 0x131e98u: goto label_131e98;
        case 0x131eacu: goto label_131eac;
        case 0x131ec4u: goto label_131ec4;
        case 0x131ee0u: goto label_131ee0;
        default: break;
    }

    ctx->pc = 0x131e38u;

    // 0x131e38: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x131e38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x131e3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131e40: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131e40u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131e44: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131e48: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x131E48u;
    {
        const bool branch_taken_0x131e48 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x131E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131E48u;
            // 0x131e4c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131e48) {
            ctx->pc = 0x131E70u;
            goto label_131e70;
        }
    }
    ctx->pc = 0x131E50u;
    // 0x131e50: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x131e50u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x131e54: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131e54u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131e58: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131e58u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131e5c: 0x2484af20  addiu       $a0, $a0, -0x50E0
    ctx->pc = 0x131e5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946592));
    // 0x131e60: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x131e60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131e64: 0x804a034  j           func_1280D0
    ctx->pc = 0x131E64u;
    ctx->pc = 0x131E68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131E64u;
            // 0x131e68: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131E6Cu;
    // 0x131e6c: 0x0  nop
    ctx->pc = 0x131e6cu;
    // NOP
label_131e70:
    // 0x131e70: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x131e70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x131e74: 0x2451b798  addiu       $s1, $v0, -0x4868
    ctx->pc = 0x131e74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948760));
    // 0x131e78: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x131e78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x131e7c: 0x50600007  beql        $v1, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x131E7Cu;
    {
        const bool branch_taken_0x131e7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x131e7c) {
            ctx->pc = 0x131E80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131E7Cu;
            // 0x131e80: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131E9Cu;
            goto label_131e9c;
        }
    }
    ctx->pc = 0x131E84u;
    // 0x131e84: 0xc04b32c  jal         func_12CCB0
    ctx->pc = 0x131E84u;
    SET_GPR_U32(ctx, 31, 0x131E8Cu);
    ctx->pc = 0x131E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131E84u;
            // 0x131e88: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CCB0u;
    if (runtime->hasFunction(0x12CCB0u)) {
        auto targetFn = runtime->lookupFunction(0x12CCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131E8Cu; }
        if (ctx->pc != 0x131E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CCB0_0x12ccb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131E8Cu; }
        if (ctx->pc != 0x131E8Cu) { return; }
    }
    ctx->pc = 0x131E8Cu;
label_131e8c:
    // 0x131e8c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x131e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x131e90: 0x40f809  jalr        $v0
    ctx->pc = 0x131E90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131E98u);
        ctx->pc = 0x131E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131E90u;
            // 0x131e94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x131E98u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131E70u: goto label_131e70;
            case 0x131E8Cu: goto label_131e8c;
            case 0x131E98u: goto label_131e98;
            case 0x131E9Cu: goto label_131e9c;
            case 0x131EACu: goto label_131eac;
            case 0x131EB0u: goto label_131eb0;
            case 0x131EC4u: goto label_131ec4;
            case 0x131EE0u: goto label_131ee0;
            case 0x131EE4u: goto label_131ee4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131E98u; }
            if (ctx->pc != 0x131E98u) { return; }
        }
        }
    }
    ctx->pc = 0x131E98u;
label_131e98:
    // 0x131e98: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x131e98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_131e9c:
    // 0x131e9c: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x131E9Cu;
    {
        const bool branch_taken_0x131e9c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x131e9c) {
            ctx->pc = 0x131EA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131E9Cu;
            // 0x131ea0: 0x82030002  lb          $v1, 0x2($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131EB0u;
            goto label_131eb0;
        }
    }
    ctx->pc = 0x131EA4u;
    // 0x131ea4: 0xc04c148  jal         func_130520
    ctx->pc = 0x131EA4u;
    SET_GPR_U32(ctx, 31, 0x131EACu);
    ctx->pc = 0x130520u;
    if (runtime->hasFunction(0x130520u)) {
        auto targetFn = runtime->lookupFunction(0x130520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131EACu; }
        if (ctx->pc != 0x131EACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130520_0x130520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131EACu; }
        if (ctx->pc != 0x131EACu) { return; }
    }
    ctx->pc = 0x131EACu;
label_131eac:
    // 0x131eac: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x131eacu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
label_131eb0:
    // 0x131eb0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x131eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x131eb4: 0x5462000b  bnel        $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x131EB4u;
    {
        const bool branch_taken_0x131eb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x131eb4) {
            ctx->pc = 0x131EB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131EB4u;
            // 0x131eb8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131EE4u;
            goto label_131ee4;
        }
    }
    ctx->pc = 0x131EBCu;
    // 0x131ebc: 0xc04f3de  jal         func_13CF78
    ctx->pc = 0x131EBCu;
    SET_GPR_U32(ctx, 31, 0x131EC4u);
    ctx->pc = 0x131EC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131EBCu;
            // 0x131ec0: 0x8e040094  lw          $a0, 0x94($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131EC4u; }
        if (ctx->pc != 0x131EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF78_0x13cf78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131EC4u; }
        if (ctx->pc != 0x131EC4u) { return; }
    }
    ctx->pc = 0x131EC4u;
label_131ec4:
    // 0x131ec4: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x131ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x131ec8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x131EC8u;
    {
        const bool branch_taken_0x131ec8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131EC8u;
            // 0x131ecc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131ec8) {
            ctx->pc = 0x131EE0u;
            goto label_131ee0;
        }
    }
    ctx->pc = 0x131ED0u;
    // 0x131ed0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x131ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x131ed4: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x131ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x131ed8: 0x60f809  jalr        $v1
    ctx->pc = 0x131ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x131EE0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x131EE0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131E70u: goto label_131e70;
            case 0x131E8Cu: goto label_131e8c;
            case 0x131E98u: goto label_131e98;
            case 0x131E9Cu: goto label_131e9c;
            case 0x131EACu: goto label_131eac;
            case 0x131EB0u: goto label_131eb0;
            case 0x131EC4u: goto label_131ec4;
            case 0x131EE0u: goto label_131ee0;
            case 0x131EE4u: goto label_131ee4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131EE0u; }
            if (ctx->pc != 0x131EE0u) { return; }
        }
        }
    }
    ctx->pc = 0x131EE0u;
label_131ee0:
    // 0x131ee0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x131ee0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_131ee4:
    // 0x131ee4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131ee4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131ee8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131ee8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131eec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x131eecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131ef0: 0x804c766  j           func_131D98
    ctx->pc = 0x131EF0u;
    ctx->pc = 0x131EF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131EF0u;
            // 0x131ef4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131D98u;
    if (runtime->hasFunction(0x131D98u)) {
        auto targetFn = runtime->lookupFunction(0x131D98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00131D98_0x131d98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131EF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
