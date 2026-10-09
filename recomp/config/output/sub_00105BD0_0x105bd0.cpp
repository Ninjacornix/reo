#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00105BD0
// Address: 0x105bd0 - 0x105d40
void sub_00105BD0_0x105bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00105BD0_0x105bd0");
#endif

    switch (ctx->pc) {
        case 0x105c00u: goto label_105c00;
        case 0x105c4cu: goto label_105c4c;
        case 0x105c78u: goto label_105c78;
        case 0x105c98u: goto label_105c98;
        case 0x105ce0u: goto label_105ce0;
        case 0x105d18u: goto label_105d18;
        default: break;
    }

    ctx->pc = 0x105bd0u;

    // 0x105bd0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x105bd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x105bd4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x105bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x105bd8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x105bd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105bdc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x105bdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x105be0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x105be0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105be4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x105be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x105be8: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x105be8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x105bec: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x105becu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x105bf0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x105bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x105bf4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x105bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x105bf8: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x105BF8u;
    SET_GPR_U32(ctx, 31, 0x105C00u);
    ctx->pc = 0x105BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105BF8u;
            // 0x105bfc: 0x10803e  dsrl32      $s0, $s0, 0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C00u; }
        if (ctx->pc != 0x105C00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C00u; }
        if (ctx->pc != 0x105C00u) { return; }
    }
    ctx->pc = 0x105C00u;
label_105c00:
    // 0x105c00: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x105c00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x105c04: 0x2406fffc  addiu       $a2, $zero, -0x4
    ctx->pc = 0x105c04u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x105c08: 0x24549800  addiu       $s4, $v0, -0x6800
    ctx->pc = 0x105c08u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 4294940672));
    // 0x105c0c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x105c0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c10: 0x8e830008  lw          $v1, 0x8($s4)
    ctx->pc = 0x105c10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105c14: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x105c14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x105c18: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x105c18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x105c1c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x105c1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x105c20: 0x2903e  dsrl32      $s2, $v0, 0
    ctx->pc = 0x105c20u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x105c24: 0x250802f  dsubu       $s0, $s2, $s0
    ctx->pc = 0x105c24u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) - GPR_U64(ctx, 16));
    // 0x105c28: 0x66100fef  daddiu      $s0, $s0, 0xFEF
    ctx->pc = 0x105c28u;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)4079);
    // 0x105c2c: 0x10833a  dsrl        $s0, $s0, 12
    ctx->pc = 0x105c2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> 12);
    // 0x105c30: 0x6610ffff  daddiu      $s0, $s0, -0x1
    ctx->pc = 0x105c30u;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)4294967295);
    // 0x105c34: 0x108338  dsll        $s0, $s0, 12
    ctx->pc = 0x105c34u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << 12);
    // 0x105c38: 0x2a021000  slti        $v0, $s0, 0x1000
    ctx->pc = 0x105c38u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4096) ? 1 : 0);
    // 0x105c3c: 0x14400026  bnez        $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x105C3Cu;
    {
        const bool branch_taken_0x105c3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x105C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105C3Cu;
            // 0x105c40: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105c3c) {
            ctx->pc = 0x105CD8u;
            goto label_105cd8;
        }
    }
    ctx->pc = 0x105C44u;
    // 0x105c44: 0xc042896  jal         func_10A258
    ctx->pc = 0x105C44u;
    SET_GPR_U32(ctx, 31, 0x105C4Cu);
    ctx->pc = 0x105C48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105C44u;
            // 0x105c48: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A258u;
    if (runtime->hasFunction(0x10A258u)) {
        auto targetFn = runtime->lookupFunction(0x10A258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C4Cu; }
        if (ctx->pc != 0x105C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A258_0x10a258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C4Cu; }
        if (ctx->pc != 0x105C4Cu) { return; }
    }
    ctx->pc = 0x105C4Cu;
label_105c4c:
    // 0x105c4c: 0x8e830008  lw          $v1, 0x8($s4)
    ctx->pc = 0x105c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105c50: 0x12283c  dsll32      $a1, $s2, 0
    ctx->pc = 0x105c50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) << (32 + 0));
    // 0x105c54: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x105c54u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x105c58: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x105c58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x105c5c: 0x1443001e  bne         $v0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x105C5Cu;
    {
        const bool branch_taken_0x105c5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x105C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105C5Cu;
            // 0x105c60: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105c5c) {
            ctx->pc = 0x105CD8u;
            goto label_105cd8;
        }
    }
    ctx->pc = 0x105C64u;
    // 0x105c64: 0x10983c  dsll32      $s3, $s0, 0
    ctx->pc = 0x105c64u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 16) << (32 + 0));
    // 0x105c68: 0x13983f  dsra32      $s3, $s3, 0
    ctx->pc = 0x105c68u;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x105c6c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x105c6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c70: 0xc042896  jal         func_10A258
    ctx->pc = 0x105C70u;
    SET_GPR_U32(ctx, 31, 0x105C78u);
    ctx->pc = 0x105C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105C70u;
            // 0x105c74: 0x132823  negu        $a1, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A258u;
    if (runtime->hasFunction(0x10A258u)) {
        auto targetFn = runtime->lookupFunction(0x10A258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C78u; }
        if (ctx->pc != 0x105C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A258_0x10a258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C78u; }
        if (ctx->pc != 0x105C78u) { return; }
    }
    ctx->pc = 0x105C78u;
label_105c78:
    // 0x105c78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x105c78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c7c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x105c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x105c80: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x105c80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x105c84: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x105c84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c88: 0x14460017  bne         $v0, $a2, . + 4 + (0x17 << 2)
    ctx->pc = 0x105C88u;
    {
        const bool branch_taken_0x105c88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        ctx->pc = 0x105C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105C88u;
            // 0x105c8c: 0x24679c30  addiu       $a3, $v1, -0x63D0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941744));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105c88) {
            ctx->pc = 0x105CE8u;
            goto label_105ce8;
        }
    }
    ctx->pc = 0x105C90u;
    // 0x105c90: 0xc042896  jal         func_10A258
    ctx->pc = 0x105C90u;
    SET_GPR_U32(ctx, 31, 0x105C98u);
    ctx->pc = 0x10A258u;
    if (runtime->hasFunction(0x10A258u)) {
        auto targetFn = runtime->lookupFunction(0x10A258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C98u; }
        if (ctx->pc != 0x105C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A258_0x10a258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C98u; }
        if (ctx->pc != 0x105C98u) { return; }
    }
    ctx->pc = 0x105C98u;
label_105c98:
    // 0x105c98: 0x8e860008  lw          $a2, 0x8($s4)
    ctx->pc = 0x105c98u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105c9c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x105c9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105ca0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x105ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x105ca4: 0xe69023  subu        $s2, $a3, $a2
    ctx->pc = 0x105ca4u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x105ca8: 0x2421025  or          $v0, $s2, $v0
    ctx->pc = 0x105ca8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x105cac: 0x2a430010  slti        $v1, $s2, 0x10
    ctx->pc = 0x105cacu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x105cb0: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x105cb0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x105cb4: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x105cb4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x105cb8: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x105CB8u;
    {
        const bool branch_taken_0x105cb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x105CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105CB8u;
            // 0x105cbc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105cb8) {
            ctx->pc = 0x105CD8u;
            goto label_105cd8;
        }
    }
    ctx->pc = 0x105CC0u;
    // 0x105cc0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x105cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x105cc4: 0x8c439c18  lw          $v1, -0x63E8($v0)
    ctx->pc = 0x105cc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294941720)));
    // 0x105cc8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x105cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x105ccc: 0xe31823  subu        $v1, $a3, $v1
    ctx->pc = 0x105cccu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x105cd0: 0xac439c30  sw          $v1, -0x63D0($v0)
    ctx->pc = 0x105cd0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294941744), GPR_U32(ctx, 3));
    // 0x105cd4: 0xacc50004  sw          $a1, 0x4($a2)
    ctx->pc = 0x105cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
label_105cd8:
    // 0x105cd8: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x105CD8u;
    SET_GPR_U32(ctx, 31, 0x105CE0u);
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105CE0u; }
        if (ctx->pc != 0x105CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105CE0u; }
        if (ctx->pc != 0x105CE0u) { return; }
    }
    ctx->pc = 0x105CE0u;
label_105ce0:
    // 0x105ce0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x105CE0u;
    {
        const bool branch_taken_0x105ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105CE0u;
            // 0x105ce4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105ce0) {
            ctx->pc = 0x105D1Cu;
            goto label_105d1c;
        }
    }
    ctx->pc = 0x105CE8u;
label_105ce8:
    // 0x105ce8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x105ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x105cec: 0x250182f  dsubu       $v1, $s2, $s0
    ctx->pc = 0x105cecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) - GPR_U64(ctx, 16));
    // 0x105cf0: 0x8e850008  lw          $a1, 0x8($s4)
    ctx->pc = 0x105cf0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105cf4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x105cf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x105cf8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x105cf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x105cfc: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x105cfcu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x105d00: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x105d00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105d04: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x105d04u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x105d08: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x105d08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x105d0c: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x105d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x105d10: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x105D10u;
    SET_GPR_U32(ctx, 31, 0x105D18u);
    ctx->pc = 0x105D14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105D10u;
            // 0x105d14: 0xace20000  sw          $v0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105D18u; }
        if (ctx->pc != 0x105D18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105D18u; }
        if (ctx->pc != 0x105D18u) { return; }
    }
    ctx->pc = 0x105D18u;
label_105d18:
    // 0x105d18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x105d18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_105d1c:
    // 0x105d1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x105d1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x105d20: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x105d20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x105d24: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x105d24u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x105d28: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x105d28u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x105d2c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x105d2cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x105d30: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x105d30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x105d34: 0x3e00008  jr          $ra
    ctx->pc = 0x105D34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105D34u;
            // 0x105d38: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105C00u: goto label_105c00;
            case 0x105C4Cu: goto label_105c4c;
            case 0x105C78u: goto label_105c78;
            case 0x105C98u: goto label_105c98;
            case 0x105CD8u: goto label_105cd8;
            case 0x105CE0u: goto label_105ce0;
            case 0x105CE8u: goto label_105ce8;
            case 0x105D18u: goto label_105d18;
            case 0x105D1Cu: goto label_105d1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x105D3Cu;
    // 0x105d3c: 0x0  nop
    ctx->pc = 0x105d3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
