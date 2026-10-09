#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8350
// Address: 0x1c8350 - 0x1c8418
void sub_001C8350_0x1c8350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8350_0x1c8350");
#endif

    switch (ctx->pc) {
        case 0x1c8364u: goto label_1c8364;
        case 0x1c836cu: goto label_1c836c;
        case 0x1c8374u: goto label_1c8374;
        case 0x1c837cu: goto label_1c837c;
        case 0x1c839cu: goto label_1c839c;
        case 0x1c83d4u: goto label_1c83d4;
        case 0x1c83f8u: goto label_1c83f8;
        case 0x1c8400u: goto label_1c8400;
        default: break;
    }

    ctx->pc = 0x1c8350u;

    // 0x1c8350: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8354: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c8354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c8358: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c8358u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c835c: 0xc072214  jal         func_1C8850
    ctx->pc = 0x1C835Cu;
    SET_GPR_U32(ctx, 31, 0x1C8364u);
    ctx->pc = 0x1C8360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C835Cu;
            // 0x1c8360: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8850u;
    if (runtime->hasFunction(0x1C8850u)) {
        auto targetFn = runtime->lookupFunction(0x1C8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8364u; }
        if (ctx->pc != 0x1C8364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8364u; }
        if (ctx->pc != 0x1C8364u) { return; }
    }
    ctx->pc = 0x1C8364u;
label_1c8364:
    // 0x1c8364: 0xc072214  jal         func_1C8850
    ctx->pc = 0x1C8364u;
    SET_GPR_U32(ctx, 31, 0x1C836Cu);
    ctx->pc = 0x1C8368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8364u;
            // 0x1c8368: 0xe600006c  swc1        $f0, 0x6C($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 108), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8850u;
    if (runtime->hasFunction(0x1C8850u)) {
        auto targetFn = runtime->lookupFunction(0x1C8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C836Cu; }
        if (ctx->pc != 0x1C836Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C836Cu; }
        if (ctx->pc != 0x1C836Cu) { return; }
    }
    ctx->pc = 0x1C836Cu;
label_1c836c:
    // 0x1c836c: 0xc072214  jal         func_1C8850
    ctx->pc = 0x1C836Cu;
    SET_GPR_U32(ctx, 31, 0x1C8374u);
    ctx->pc = 0x1C8370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C836Cu;
            // 0x1c8370: 0xe6000070  swc1        $f0, 0x70($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 112), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8850u;
    if (runtime->hasFunction(0x1C8850u)) {
        auto targetFn = runtime->lookupFunction(0x1C8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8374u; }
        if (ctx->pc != 0x1C8374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8374u; }
        if (ctx->pc != 0x1C8374u) { return; }
    }
    ctx->pc = 0x1C8374u;
label_1c8374:
    // 0x1c8374: 0xc0722d4  jal         func_1C8B50
    ctx->pc = 0x1C8374u;
    SET_GPR_U32(ctx, 31, 0x1C837Cu);
    ctx->pc = 0x1C8378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8374u;
            // 0x1c8378: 0xe6000074  swc1        $f0, 0x74($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 116), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8B50u;
    if (runtime->hasFunction(0x1C8B50u)) {
        auto targetFn = runtime->lookupFunction(0x1C8B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C837Cu; }
        if (ctx->pc != 0x1C837Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8B50_0x1c8b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C837Cu; }
        if (ctx->pc != 0x1C837Cu) { return; }
    }
    ctx->pc = 0x1C837Cu;
label_1c837c:
    // 0x1c837c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c837cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8380: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1c8380u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8384: 0x8022c6c0  lb          $v0, -0x3940($at)
    ctx->pc = 0x1c8384u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952640)));
    // 0x1c8388: 0xae020048  sw          $v0, 0x48($s0)
    ctx->pc = 0x1c8388u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 2));
    // 0x1c838c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c838cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8390: 0x8022c6c1  lb          $v0, -0x393F($at)
    ctx->pc = 0x1c8390u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952641)));
    // 0x1c8394: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C8394u;
    {
        const bool branch_taken_0x1c8394 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8394u;
            // 0x1c8398: 0xae020040  sw          $v0, 0x40($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8394) {
            ctx->pc = 0x1C83A8u;
            goto label_1c83a8;
        }
    }
    ctx->pc = 0x1C839Cu;
label_1c839c:
    // 0x1c839c: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1c839cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1c83a0: 0xac43004c  sw          $v1, 0x4C($v0)
    ctx->pc = 0x1c83a0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 3));
    // 0x1c83a4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c83a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_1c83a8:
    // 0x1c83a8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c83a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c83ac: 0x8022c6c0  lb          $v0, -0x3940($at)
    ctx->pc = 0x1c83acu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952640)));
    // 0x1c83b0: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1c83b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c83b4: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1C83B4u;
    {
        const bool branch_taken_0x1c83b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C83B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C83B4u;
            // 0x1c83b8: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c83b4) {
            ctx->pc = 0x1C839Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c839c;
        }
    }
    ctx->pc = 0x1C83BCu;
    // 0x1c83bc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c83bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c83c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c83c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c83c4: 0x8023c6c1  lb          $v1, -0x393F($at)
    ctx->pc = 0x1c83c4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952641)));
    // 0x1c83c8: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x1c83c8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1c83cc: 0xc072214  jal         func_1C8850
    ctx->pc = 0x1C83CCu;
    SET_GPR_U32(ctx, 31, 0x1C83D4u);
    ctx->pc = 0x1C83D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C83CCu;
            // 0x1c83d0: 0xa2020044  sb          $v0, 0x44($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 68), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8850u;
    if (runtime->hasFunction(0x1C8850u)) {
        auto targetFn = runtime->lookupFunction(0x1C8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C83D4u; }
        if (ctx->pc != 0x1C83D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C83D4u; }
        if (ctx->pc != 0x1C83D4u) { return; }
    }
    ctx->pc = 0x1C83D4u;
label_1c83d4:
    // 0x1c83d4: 0xe600006c  swc1        $f0, 0x6C($s0)
    ctx->pc = 0x1c83d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 108), bits); }
    // 0x1c83d8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c83d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c83dc: 0xae000070  sw          $zero, 0x70($s0)
    ctx->pc = 0x1c83dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 112), GPR_U32(ctx, 0));
    // 0x1c83e0: 0x8025c6c1  lb          $a1, -0x393F($at)
    ctx->pc = 0x1c83e0u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952641)));
    // 0x1c83e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c83e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c83e8: 0x8026c6c0  lb          $a2, -0x3940($at)
    ctx->pc = 0x1c83e8u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952640)));
    // 0x1c83ec: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c83ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c83f0: 0xc0719f8  jal         func_1C67E0
    ctx->pc = 0x1C83F0u;
    SET_GPR_U32(ctx, 31, 0x1C83F8u);
    ctx->pc = 0x1C83F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C83F0u;
            // 0x1c83f4: 0x8c24b694  lw          $a0, -0x496C($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948500)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C67E0u;
    if (runtime->hasFunction(0x1C67E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C67E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C83F8u; }
        if (ctx->pc != 0x1C83F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C67E0_0x1c67e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C83F8u; }
        if (ctx->pc != 0x1C83F8u) { return; }
    }
    ctx->pc = 0x1C83F8u;
label_1c83f8:
    // 0x1c83f8: 0xc0719f0  jal         func_1C67C0
    ctx->pc = 0x1C83F8u;
    SET_GPR_U32(ctx, 31, 0x1C8400u);
    ctx->pc = 0x1C67C0u;
    if (runtime->hasFunction(0x1C67C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C67C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8400u; }
        if (ctx->pc != 0x1C8400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C67C0_0x1c67c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8400u; }
        if (ctx->pc != 0x1C8400u) { return; }
    }
    ctx->pc = 0x1C8400u;
label_1c8400:
    // 0x1c8400: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c8400u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c8404: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1c8404u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1c8408: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c8408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c840c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c840cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8410: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8410u;
            // 0x1c8414: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8364u: goto label_1c8364;
            case 0x1C836Cu: goto label_1c836c;
            case 0x1C8374u: goto label_1c8374;
            case 0x1C837Cu: goto label_1c837c;
            case 0x1C839Cu: goto label_1c839c;
            case 0x1C83A8u: goto label_1c83a8;
            case 0x1C83D4u: goto label_1c83d4;
            case 0x1C83F8u: goto label_1c83f8;
            case 0x1C8400u: goto label_1c8400;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8418u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
