#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001690F0
// Address: 0x1690f0 - 0x169168
void sub_001690F0_0x1690f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001690F0_0x1690f0");
#endif

    switch (ctx->pc) {
        case 0x169130u: goto label_169130;
        case 0x16913cu: goto label_16913c;
        case 0x169144u: goto label_169144;
        case 0x16914cu: goto label_16914c;
        default: break;
    }

    ctx->pc = 0x1690f0u;

    // 0x1690f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1690f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1690f4: 0x28c70801  slti        $a3, $a2, 0x801
    ctx->pc = 0x1690f4u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)2049) ? 1 : 0);
    // 0x1690f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1690f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1690fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1690fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169100: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x169100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x169104: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x169104u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169108: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16910c: 0x26510078  addiu       $s1, $s2, 0x78
    ctx->pc = 0x16910cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 120));
    // 0x169110: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x169110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x169114: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x169114u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x169118: 0x1460000d  bnez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x169118u;
    {
        const bool branch_taken_0x169118 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16911Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169118u;
            // 0x16911c: 0x2644010c  addiu       $a0, $s2, 0x10C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 268));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169118) {
            ctx->pc = 0x169150u;
            goto label_169150;
        }
    }
    ctx->pc = 0x169120u;
    // 0x169120: 0x24100800  addiu       $s0, $zero, 0x800
    ctx->pc = 0x169120u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x169124: 0xc7800b  movn        $s0, $a2, $a3
    ctx->pc = 0x169124u;
    if (GPR_U64(ctx, 7) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 6));
    // 0x169128: 0xc055798  jal         func_155E60
    ctx->pc = 0x169128u;
    SET_GPR_U32(ctx, 31, 0x169130u);
    ctx->pc = 0x16912Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169128u;
            // 0x16912c: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169130u; }
        if (ctx->pc != 0x169130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169130u; }
        if (ctx->pc != 0x169130u) { return; }
    }
    ctx->pc = 0x169130u;
label_169130:
    // 0x169130: 0xae300090  sw          $s0, 0x90($s1)
    ctx->pc = 0x169130u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 16));
    // 0x169134: 0xc05a4cc  jal         func_169330
    ctx->pc = 0x169134u;
    SET_GPR_U32(ctx, 31, 0x16913Cu);
    ctx->pc = 0x169138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169134u;
            // 0x169138: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169330u;
    if (runtime->hasFunction(0x169330u)) {
        auto targetFn = runtime->lookupFunction(0x169330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16913Cu; }
        if (ctx->pc != 0x16913Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169330_0x169330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16913Cu; }
        if (ctx->pc != 0x16913Cu) { return; }
    }
    ctx->pc = 0x16913Cu;
label_16913c:
    // 0x16913c: 0xc05a654  jal         func_169950
    ctx->pc = 0x16913Cu;
    SET_GPR_U32(ctx, 31, 0x169144u);
    ctx->pc = 0x169140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16913Cu;
            // 0x169140: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169950u;
    if (runtime->hasFunction(0x169950u)) {
        auto targetFn = runtime->lookupFunction(0x169950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169144u; }
        if (ctx->pc != 0x169144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169950_0x169950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169144u; }
        if (ctx->pc != 0x169144u) { return; }
    }
    ctx->pc = 0x169144u;
label_169144:
    // 0x169144: 0xc05a45a  jal         func_169168
    ctx->pc = 0x169144u;
    SET_GPR_U32(ctx, 31, 0x16914Cu);
    ctx->pc = 0x169148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169144u;
            // 0x169148: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169168u;
    if (runtime->hasFunction(0x169168u)) {
        auto targetFn = runtime->lookupFunction(0x169168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16914Cu; }
        if (ctx->pc != 0x16914Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169168_0x169168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16914Cu; }
        if (ctx->pc != 0x16914Cu) { return; }
    }
    ctx->pc = 0x16914Cu;
label_16914c:
    // 0x16914c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16914cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_169150:
    // 0x169150: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169150u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169154: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169154u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169158: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x169158u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16915c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16915cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x169160: 0x3e00008  jr          $ra
    ctx->pc = 0x169160u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169160u;
            // 0x169164: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169130u: goto label_169130;
            case 0x16913Cu: goto label_16913c;
            case 0x169144u: goto label_169144;
            case 0x16914Cu: goto label_16914c;
            case 0x169150u: goto label_169150;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169168u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
