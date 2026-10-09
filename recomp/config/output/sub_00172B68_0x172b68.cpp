#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172B68
// Address: 0x172b68 - 0x172bd8
void sub_00172B68_0x172b68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172B68_0x172b68");
#endif

    switch (ctx->pc) {
        case 0x172b7cu: goto label_172b7c;
        case 0x172b8cu: goto label_172b8c;
        default: break;
    }

    ctx->pc = 0x172b68u;

    // 0x172b68: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172b68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172b6c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172b70: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x172b70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x172b74: 0xc05cc4c  jal         func_173130
    ctx->pc = 0x172B74u;
    SET_GPR_U32(ctx, 31, 0x172B7Cu);
    ctx->pc = 0x172B78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172B74u;
            // 0x172b78: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173130u;
    if (runtime->hasFunction(0x173130u)) {
        auto targetFn = runtime->lookupFunction(0x173130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B7Cu; }
        if (ctx->pc != 0x172B7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173130_0x173130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B7Cu; }
        if (ctx->pc != 0x172B7Cu) { return; }
    }
    ctx->pc = 0x172B7Cu;
label_172b7c:
    // 0x172b7c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x172B7Cu;
    {
        const bool branch_taken_0x172b7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B7Cu;
            // 0x172b80: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b7c) {
            ctx->pc = 0x172B94u;
            goto label_172b94;
        }
    }
    ctx->pc = 0x172B84u;
    // 0x172b84: 0xc05cb12  jal         func_172C48
    ctx->pc = 0x172B84u;
    SET_GPR_U32(ctx, 31, 0x172B8Cu);
    ctx->pc = 0x172C48u;
    if (runtime->hasFunction(0x172C48u)) {
        auto targetFn = runtime->lookupFunction(0x172C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B8Cu; }
        if (ctx->pc != 0x172B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172C48_0x172c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B8Cu; }
        if (ctx->pc != 0x172B8Cu) { return; }
    }
    ctx->pc = 0x172B8Cu;
label_172b8c:
    // 0x172b8c: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x172B8Cu;
    {
        const bool branch_taken_0x172b8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172b8c) {
            ctx->pc = 0x172B90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172B8Cu;
            // 0x172b90: 0x8e05004c  lw          $a1, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172BA0u;
            goto label_172ba0;
        }
    }
    ctx->pc = 0x172B94u;
label_172b94:
    // 0x172b94: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x172B94u;
    {
        const bool branch_taken_0x172b94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B94u;
            // 0x172b98: 0x8e020048  lw          $v0, 0x48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b94) {
            ctx->pc = 0x172BC8u;
            goto label_172bc8;
        }
    }
    ctx->pc = 0x172B9Cu;
    // 0x172b9c: 0x0  nop
    ctx->pc = 0x172b9cu;
    // NOP
label_172ba0:
    // 0x172ba0: 0x8e040048  lw          $a0, 0x48($s0)
    ctx->pc = 0x172ba0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x172ba4: 0x28a20002  slti        $v0, $a1, 0x2
    ctx->pc = 0x172ba4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x172ba8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x172BA8u;
    {
        const bool branch_taken_0x172ba8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172BA8u;
            // 0x172bac: 0x28a30005  slti        $v1, $a1, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x172ba8) {
            ctx->pc = 0x172BC4u;
            goto label_172bc4;
        }
    }
    ctx->pc = 0x172BB0u;
    // 0x172bb0: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x172BB0u;
    {
        const bool branch_taken_0x172bb0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x172BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172BB0u;
            // 0x172bb4: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172bb0) {
            ctx->pc = 0x172BC8u;
            goto label_172bc8;
        }
    }
    ctx->pc = 0x172BB8u;
    // 0x172bb8: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x172bb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x172bbc: 0xa31026  xor         $v0, $a1, $v1
    ctx->pc = 0x172bbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 3));
    // 0x172bc0: 0x62200a  movz        $a0, $v1, $v0
    ctx->pc = 0x172bc0u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_172bc4:
    // 0x172bc4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x172bc4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_172bc8:
    // 0x172bc8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172bc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172bcc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x172bccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172bd0: 0x3e00008  jr          $ra
    ctx->pc = 0x172BD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172BD0u;
            // 0x172bd4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172B7Cu: goto label_172b7c;
            case 0x172B8Cu: goto label_172b8c;
            case 0x172B94u: goto label_172b94;
            case 0x172BA0u: goto label_172ba0;
            case 0x172BC4u: goto label_172bc4;
            case 0x172BC8u: goto label_172bc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172BD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
