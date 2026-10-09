#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001696B0
// Address: 0x1696b0 - 0x169748
void sub_001696B0_0x1696b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001696B0_0x1696b0");
#endif

    switch (ctx->pc) {
        case 0x1696e0u: goto label_1696e0;
        case 0x1696f8u: goto label_1696f8;
        case 0x169710u: goto label_169710;
        case 0x169728u: goto label_169728;
        default: break;
    }

    ctx->pc = 0x1696b0u;

    // 0x1696b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1696b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1696b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1696b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1696b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1696b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1696bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1696bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1696c0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1696c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1696c4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1696c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1696c8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1696c8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1696cc: 0x12000017  beqz        $s0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1696CCu;
    {
        const bool branch_taken_0x1696cc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1696D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1696CCu;
            // 0x1696d0: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1696cc) {
            ctx->pc = 0x16972Cu;
            goto label_16972c;
        }
    }
    ctx->pc = 0x1696D4u;
    // 0x1696d4: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x1696d4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x1696d8: 0xc05a646  jal         func_169918
    ctx->pc = 0x1696D8u;
    SET_GPR_U32(ctx, 31, 0x1696E0u);
    ctx->pc = 0x1696DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1696D8u;
            // 0x1696dc: 0x24c69db0  addiu       $a2, $a2, -0x6250 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294942128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1696E0u; }
        if (ctx->pc != 0x1696E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1696E0u; }
        if (ctx->pc != 0x1696E0u) { return; }
    }
    ctx->pc = 0x1696E0u;
label_1696e0:
    // 0x1696e0: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x1696e0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x1696e4: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1696e4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1696e8: 0x24c69e18  addiu       $a2, $a2, -0x61E8
    ctx->pc = 0x1696e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294942232));
    // 0x1696ec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1696ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1696f0: 0xc05a646  jal         func_169918
    ctx->pc = 0x1696F0u;
    SET_GPR_U32(ctx, 31, 0x1696F8u);
    ctx->pc = 0x1696F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1696F0u;
            // 0x1696f4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1696F8u; }
        if (ctx->pc != 0x1696F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1696F8u; }
        if (ctx->pc != 0x1696F8u) { return; }
    }
    ctx->pc = 0x1696F8u;
label_1696f8:
    // 0x1696f8: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x1696f8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x1696fc: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x1696fcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x169700: 0x24c69e98  addiu       $a2, $a2, -0x6168
    ctx->pc = 0x169700u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294942360));
    // 0x169704: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169704u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169708: 0xc05a646  jal         func_169918
    ctx->pc = 0x169708u;
    SET_GPR_U32(ctx, 31, 0x169710u);
    ctx->pc = 0x16970Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169708u;
            // 0x16970c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169710u; }
        if (ctx->pc != 0x169710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169710u; }
        if (ctx->pc != 0x169710u) { return; }
    }
    ctx->pc = 0x169710u;
label_169710:
    // 0x169710: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x169710u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x169714: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x169714u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x169718: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169718u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16971c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x16971cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169720: 0xc05a646  jal         func_169918
    ctx->pc = 0x169720u;
    SET_GPR_U32(ctx, 31, 0x169728u);
    ctx->pc = 0x169724u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169720u;
            // 0x169724: 0x24c69f00  addiu       $a2, $a2, -0x6100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294942464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169728u; }
        if (ctx->pc != 0x169728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169728u; }
        if (ctx->pc != 0x169728u) { return; }
    }
    ctx->pc = 0x169728u;
label_169728:
    // 0x169728: 0xae42000c  sw          $v0, 0xC($s2)
    ctx->pc = 0x169728u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 2));
label_16972c:
    // 0x16972c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16972cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169730: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169730u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169734: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x169734u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169738: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x169738u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16973c: 0x3e00008  jr          $ra
    ctx->pc = 0x16973Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16973Cu;
            // 0x169740: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1696E0u: goto label_1696e0;
            case 0x1696F8u: goto label_1696f8;
            case 0x169710u: goto label_169710;
            case 0x169728u: goto label_169728;
            case 0x16972Cu: goto label_16972c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169744u;
    // 0x169744: 0x0  nop
    ctx->pc = 0x169744u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
