#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1778
// Address: 0x1c1778 - 0x1c17dc
void sub_001C1778_0x1c1778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1778_0x1c1778");
#endif

    switch (ctx->pc) {
        case 0x1c1788u: goto label_1c1788;
        case 0x1c17a0u: goto label_1c17a0;
        case 0x1c17c8u: goto label_1c17c8;
        default: break;
    }

    ctx->pc = 0x1c1778u;

    // 0x1c1778: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1778u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c177c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c177cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c1780: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C1780u;
    SET_GPR_U32(ctx, 31, 0x1C1788u);
    ctx->pc = 0x1C15E8u;
    if (runtime->hasFunction(0x1C15E8u)) {
        auto targetFn = runtime->lookupFunction(0x1C15E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1788u; }
        if (ctx->pc != 0x1C1788u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C15E8_0x1c15e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1788u; }
        if (ctx->pc != 0x1C1788u) { return; }
    }
    ctx->pc = 0x1C1788u;
label_1c1788:
    // 0x1c1788: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1788u;
    {
        const bool branch_taken_0x1c1788 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C178Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1788u;
            // 0x1c178c: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1788) {
            ctx->pc = 0x1C1798u;
            goto label_1c1798;
        }
    }
    ctx->pc = 0x1C1790u;
    // 0x1c1790: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C1790u;
    {
        const bool branch_taken_0x1c1790 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1790u;
            // 0x1c1794: 0x904252d3  lbu         $v0, 0x52D3($v0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 21203)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1790) {
            ctx->pc = 0x1C17D0u;
            goto label_1c17d0;
        }
    }
    ctx->pc = 0x1C1798u;
label_1c1798:
    // 0x1c1798: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1798u;
    SET_GPR_U32(ctx, 31, 0x1C17A0u);
    ctx->pc = 0x1C179Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1798u;
            // 0x1c179c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C17A0u; }
        if (ctx->pc != 0x1C17A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C17A0u; }
        if (ctx->pc != 0x1C17A0u) { return; }
    }
    ctx->pc = 0x1C17A0u;
label_1c17a0:
    // 0x1c17a0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1c17a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c17a4: 0x21342  srl         $v0, $v0, 13
    ctx->pc = 0x1c17a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 13));
    // 0x1c17a8: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x1c17a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x1c17ac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C17ACu;
    {
        const bool branch_taken_0x1c17ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C17B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C17ACu;
            // 0x1c17b0: 0x37a40004  ori         $a0, $sp, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c17ac) {
            ctx->pc = 0x1C17BCu;
            goto label_1c17bc;
        }
    }
    ctx->pc = 0x1C17B4u;
    // 0x1c17b4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C17B4u;
    {
        const bool branch_taken_0x1c17b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C17B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C17B4u;
            // 0x1c17b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c17b4) {
            ctx->pc = 0x1C17D0u;
            goto label_1c17d0;
        }
    }
    ctx->pc = 0x1C17BCu;
label_1c17bc:
    // 0x1c17bc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c17bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c17c0: 0xc04524c  jal         func_114930
    ctx->pc = 0x1C17C0u;
    SET_GPR_U32(ctx, 31, 0x1C17C8u);
    ctx->pc = 0x1C17C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C17C0u;
            // 0x1c17c4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114930u;
    if (runtime->hasFunction(0x114930u)) {
        auto targetFn = runtime->lookupFunction(0x114930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C17C8u; }
        if (ctx->pc != 0x1C17C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114930_0x114930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C17C8u; }
        if (ctx->pc != 0x1C17C8u) { return; }
    }
    ctx->pc = 0x1C17C8u;
label_1c17c8:
    // 0x1c17c8: 0x93a30004  lbu         $v1, 0x4($sp)
    ctx->pc = 0x1c17c8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1c17cc: 0x31182  srl         $v0, $v1, 6
    ctx->pc = 0x1c17ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 6));
label_1c17d0:
    // 0x1c17d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c17d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c17d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C17D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C17D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C17D4u;
            // 0x1c17d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1788u: goto label_1c1788;
            case 0x1C1798u: goto label_1c1798;
            case 0x1C17A0u: goto label_1c17a0;
            case 0x1C17BCu: goto label_1c17bc;
            case 0x1C17C8u: goto label_1c17c8;
            case 0x1C17D0u: goto label_1c17d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C17DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
